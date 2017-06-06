/******************************************************************************

Copyright ©2013 Advanced Micro Devices, Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#ifndef _SIMPLE_CONVOLUTION_H_
#define _SIMPLE_CONVOLUTION_H_

#include <vector>
#include <map>

#include "test_kernel.h"

// SimpleConvolution: Class implements OpenCL SimpleConvolution sample
class SimpleConvolution : public TestKernel {
 public:
  // Constructor
  SimpleConvolution();

  // Initialize method
  void init();

  // Return number of compute elements
  uint32_t get_elements_count() const { return width_ * height_; }

  // Print output
  void print_output() const;

  // Return name
  std::string Name() const { return std::string("simpleConvolution"); }

 private:
  // Local kernel arguments declaration
  struct kernel_args_t {
    void* arg1;
    void* arg2;
    void* arg3;
    uint32_t arg4;
    uint32_t arg41;
    uint32_t arg5;
    uint32_t arg51;
  };

  // Width of the Input array
  uint32_t width_;

  // Height of the Input array
  uint32_t height_;

  // Mask dimensions
  uint32_t mask_width_;

  // Mask dimensions
  uint32_t mask_height_;

  // Reference CPU implementation of Simple Convolution
  // @param output Output matrix after performing convolution
  // @param input  Input  matrix on which convolution is to be performed
  // @param mask   mask matrix using which convolution was to be performed
  // @param input_dimensions dimensions of the input matrix
  // @param mask_dimensions  dimensions of the mask matrix
  // @return bool true on success and false on failure
  bool reference_impl(uint32_t* output, const uint32_t* input, const float* mask,
                      const uint32_t width, const uint32_t height, const uint32_t maskWidth,
                      const uint32_t maskHeight);
};

#endif  // _SIMPLE_CONVOLUTION_H_
