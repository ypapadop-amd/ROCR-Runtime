/*
 * =============================================================================
 *   ROC Runtime Conformance Release License
 * =============================================================================
 * The University of Illinois/NCSA
 * Open Source License (NCSA)
 *
 * Copyright (c) 2017, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Developed by:
 *
 *                 AMD Research and AMD ROC Software Development
 *
 *                 Advanced Micro Devices, Inc.
 *
 *                 www.amd.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal with the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimers.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimers in
 *    the documentation and/or other materials provided with the distribution.
 *  - Neither the names of <Name of Development Group, Name of Institution>,
 *    nor the names of its contributors may be used to endorse or promote
 *    products derived from this Software without specific prior written
 *    permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS WITH THE SOFTWARE.
 *
 */

#include <assert.h>
#include <stdint.h>
#include <getopt.h>

#include <iostream>
#include <string>

#include "suites/test_common/test_base.h"
#include "suites/test_common/test_common.h"


static const struct option long_options[] = {
  {"iterations", required_argument, nullptr, 'i'},
  {"verbose", required_argument, nullptr, 'v'},
  {"monitor_verbose", required_argument, nullptr, 'm'},

  {nullptr, 0, nullptr, 0}
};
static const char* short_options = "i:v:m:r";

static void PrintHelp(void) {
  std::cout <<
     "Optional RocRTst Arguments:\n"
     "--iterations, -i <number of iterations to execute>; override default, "
         "which varies for each test\n"
     "--rocrtst_help, -r print this help message\n"
     "--verbosity, -v <verbosity level>\n"
     "  Verbosity levels:\n"
     "   0    -- minimal; just summary information\n"
     "   1    -- intermediate; show intermediate values such as intermediate "
                  "perf. data\n"
     "   2    -- progress; show progress displays\n"
     "   >= 3 -- more debug output\n"
     "--monitor_verbosity, -m <monitor verbosity level>\n"
     "  Monitor Verbosity levels:\n"
     "   0    -- don't read or print out any GPU monitor information;\n"
     "   1    -- print out all available monitor information before the first "
                 "test and after each test\n"
     "   >= 2 -- print out even more monitor information (test specific)\n";
}

uint32_t ProcessCmdline(RocrTstGlobals* test, int arg_cnt, char** arg_list) {
  int a;
  int ind = -1;

  assert(test != nullptr);

  while (true) {
    a = getopt_long(arg_cnt, arg_list, short_options, long_options, &ind);

    if (a == -1) {
      break;
    }

    switch (a) {
      case 'i':
        test->num_iterations = std::stoi(optarg);
        break;

      case 'v':
        test->verbosity = std::stoi(optarg);
        break;

      case 'm':
        test->monitor_verbosity = std::stoi(optarg);
        break;

      case 'r':
        PrintHelp();
        return 1;

      default:
        PrintHelp();
        return 1;
    }
  }
  return 0;
}

void DumpMonitorInfo(const TestBase *test) {
  int ret = 0;
  uint32_t value;
  uint32_t value2;
  std::string val_str;
  std::vector<std::string> val_vec;

  assert(test != nullptr);
  assert(test->monitor_devices() != nullptr &&
                            "Make sure to call test->set_monitor_devices()");
  auto print_attr_label =
      [&](std::string attrib) -> bool {
          std::cout << "\t** " << attrib;
          if (ret == -1) {
            std::cout << "not available" << std::endl;
            return false;
          }
          return true;
  };

  auto delim = "\t***********************************";

  std::cout << "\t***** Hardware monitor values *****" << std::endl;
  std::cout << delim << std::endl;
  std::cout.setf(std::ios::dec, std::ios::basefield);
  for (auto dev : *test->monitor_devices()) {
    auto print_vector =
                     [&](rocrtst::smi::DevInfoTypes type, std::string label) {
      ret = dev->readDevInfo(type, &val_vec);
      if (print_attr_label(label)) {
        for (auto vs : val_vec) {
          std::cout << "\t**  " << vs << std::endl;
        }
        val_vec.clear();
      }
    };
    auto print_val_str =
                     [&](rocrtst::smi::DevInfoTypes type, std::string label) {
      ret = dev->readDevInfo(type, &val_str);

      std::cout << "\t** " << label;
      if (ret == -1) {
        std::cout << "not available";
      } else {
        std::cout << val_str;
      }
      std::cout << std:: endl;
    };

    print_val_str(rocrtst::smi::kDevDevID, "Device ID: ");
    print_val_str(rocrtst::smi::kDevPerfLevel, "Performance Level: ");
    print_val_str(rocrtst::smi::kDevOverDriveLevel, "OverDrive Level: ");
    print_vector(rocrtst::smi::kDevGPUMClk,
                                 "Supported GPU Memory clock frequencies:\n");
    print_vector(rocrtst::smi::kDevGPUSClk,
                                    "Supported GPU clock frequencies:\n");

    if (dev->monitor() != nullptr) {
      ret = dev->monitor()->readMonitor(rocrtst::smi::kMonName, &val_str);
      if (print_attr_label("Monitor name: ")) {
        std::cout << val_str << std::endl;
      }

      ret = dev->monitor()->readMonitor(rocrtst::smi::kMonTemp, &value);
      if (print_attr_label("Temperature: ")) {
        std::cout << static_cast<float>(value)/1000.0 << "C" << std::endl;
      }

      std::cout.setf(std::ios::dec, std::ios::basefield);

      ret = dev->monitor()->readMonitor(rocrtst::smi::kMonMaxFanSpeed, &value);
      if (ret == 0) {
        ret = dev->monitor()->readMonitor(rocrtst::smi::kMonFanSpeed, &value2);
      }
      if (print_attr_label("Current Fan Speed: ")) {
        std::cout << value2/static_cast<float>(value) * 100 << "% (" <<
                                   value2 << "/" << value << ")" << std::endl;
      }
    }
    std::cout << "\t=======" << std::endl;
  }
  std::cout << delim << std::endl;
}