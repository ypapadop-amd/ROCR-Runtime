//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
//  Trade secret of Advanced Micro Devices, Inc.
//  Copyright 2014, Advanced Micro Devices, Inc., (unpublished)
//
//  All rights reserved.  This notice is intended as a precaution against
//  inadvertent publication and does not imply publication or any waiver
//  of confidentiality.  The year included in the foregoing notice is the
//  year of creation of the work.
//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#ifndef F32_PFP_PM4_PACKETS_H
#define F32_PFP_PM4_PACKETS_H

namespace pm4_profile {
namespace gfx9 {

#ifndef PM4_PFP_HEADER_DEFINED
#define PM4_PFP_HEADER_DEFINED
typedef union PM4_PFP_TYPE_3_HEADER {
  struct {
    uint32_t predicate : 1;   ///< apply predicate flag to this packet
    uint32_t shaderType : 1;  ///< shader type: 0=GFX, 1=Compute
    uint32_t reserved1 : 6;   ///< reserved
    uint32_t opcode : 8;      ///< IT opcode
    uint32_t count : 14;      ///< number of DWORDs - 1 in the information body.
    uint32_t type : 2;        ///< packet identifier. It should be 3 for type 3 packets
  };
  uint32_t u32All;
} PM4_PFP_TYPE_3_HEADER;
#endif  // PM4_PFP_HEADER_DEFINED

//--------------------PFP_ACQUIRE_MEM--------------------

#ifndef PM4_PFP_ACQUIRE_MEM_DEFINED
#define PM4_PFP_ACQUIRE_MEM_DEFINED
enum PFP_ACQUIRE_MEM_engine_sel_enum { engine_sel__pfp_acquire_mem__prefetch_parser = 0 };


typedef struct PM4_PFP_ACQUIRE_MEM {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t coher_cntl : 31;
      PFP_ACQUIRE_MEM_engine_sel_enum engine_sel : 1;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t coher_size;

  union {
    struct {
      uint32_t coher_size_hi : 24;
      uint32_t reserved1 : 8;
    } bitfields4;
    uint32_t ordinal4;
  };

  uint32_t coher_base_lo;

  union {
    struct {
      uint32_t coher_base_hi : 24;
      uint32_t reserved2 : 8;
    } bitfields6;
    uint32_t ordinal6;
  };

  union {
    struct {
      uint32_t poll_interval : 16;
      uint32_t reserved3 : 16;
    } bitfields7;
    uint32_t ordinal7;
  };

} PM4PFP_ACQUIRE_MEM, *PPM4PFP_ACQUIRE_MEM;
#endif

//--------------------PFP_ATOMIC_GDS--------------------

#ifndef PM4_PFP_ATOMIC_GDS_DEFINED
#define PM4_PFP_ATOMIC_GDS_DEFINED
enum PFP_ATOMIC_GDS_atom_cmp_swap_enum {
  atom_cmp_swap__pfp_atomic_gds__dont_repeat = 0,
  atom_cmp_swap__pfp_atomic_gds__repeat_until_pass = 1
};

enum PFP_ATOMIC_GDS_atom_complete_enum {
  atom_complete__pfp_atomic_gds__dont_wait = 0,
  atom_complete__pfp_atomic_gds__wait_for_completion = 1
};

enum PFP_ATOMIC_GDS_atom_read_enum {
  atom_read__pfp_atomic_gds__dont_read_preop_data = 0,
  atom_read__pfp_atomic_gds__read_preop_data = 1
};

enum PFP_ATOMIC_GDS_atom_rd_cntl_enum {
  atom_rd_cntl__pfp_atomic_gds__32bits_1returnval = 0,
  atom_rd_cntl__pfp_atomic_gds__32bits_2returnval = 1,
  atom_rd_cntl__pfp_atomic_gds__64bits_1returnval = 2,
  atom_rd_cntl__pfp_atomic_gds__64bits_2returnval = 3
};

enum PFP_ATOMIC_GDS_engine_sel_enum { engine_sel__pfp_atomic_gds__prefetch_parser = 1 };


typedef struct PM4_PFP_ATOMIC_GDS {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t atom_op : 7;
      uint32_t reserved1 : 9;
      PFP_ATOMIC_GDS_atom_cmp_swap_enum atom_cmp_swap : 1;
      PFP_ATOMIC_GDS_atom_complete_enum atom_complete : 1;
      PFP_ATOMIC_GDS_atom_read_enum atom_read : 1;
      PFP_ATOMIC_GDS_atom_rd_cntl_enum atom_rd_cntl : 2;
      uint32_t reserved2 : 9;
      PFP_ATOMIC_GDS_engine_sel_enum engine_sel : 2;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t auto_inc_bytes : 6;
      uint32_t reserved3 : 2;
      uint32_t dmode : 1;
      uint32_t reserved4 : 23;
    } bitfields3;
    uint32_t ordinal3;
  };

  union {
    struct {
      uint32_t atom_base : 16;
      uint32_t reserved5 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  union {
    struct {
      uint32_t atom_size : 16;
      uint32_t reserved6 : 16;
    } bitfields5;
    uint32_t ordinal5;
  };

  union {
    struct {
      uint32_t atom_offset0 : 8;
      uint32_t reserved7 : 8;
      uint32_t atom_offset1 : 8;
      uint32_t reserved8 : 8;
    } bitfields6;
    uint32_t ordinal6;
  };

  uint32_t atom_dst;

  uint32_t atom_src0;

  uint32_t atom_src0_u;

  uint32_t atom_src1;

  uint32_t atom_src1_u;

} PM4PFP_ATOMIC_GDS, *PPM4PFP_ATOMIC_GDS;
#endif

//--------------------PFP_ATOMIC_MEM--------------------

#ifndef PM4_PFP_ATOMIC_MEM_DEFINED
#define PM4_PFP_ATOMIC_MEM_DEFINED
enum PFP_ATOMIC_MEM_command_enum {
  command__pfp_atomic_mem__single_pass_atomic = 0,
  command__pfp_atomic_mem__loop_until_compare_satisfied = 1
};

enum PFP_ATOMIC_MEM_cache_policy_enum {
  cache_policy__pfp_atomic_mem__lru = 0,
  cache_policy__pfp_atomic_mem__stream = 1
};

enum PFP_ATOMIC_MEM_engine_sel_enum { engine_sel__pfp_atomic_mem__prefetch_parser = 1 };


typedef struct PM4_PFP_ATOMIC_MEM {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t atomic : 7;
      uint32_t reserved1 : 1;
      PFP_ATOMIC_MEM_command_enum command : 4;
      uint32_t reserved2 : 13;
      PFP_ATOMIC_MEM_cache_policy_enum cache_policy : 2;
      uint32_t reserved3 : 3;
      PFP_ATOMIC_MEM_engine_sel_enum engine_sel : 2;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t addr_lo;

  uint32_t addr_hi;

  uint32_t src_data_lo;

  uint32_t src_data_hi;

  uint32_t cmp_data_lo;

  uint32_t cmp_data_hi;

  union {
    struct {
      uint32_t loop_interval : 13;
      uint32_t reserved4 : 19;
    } bitfields9;
    uint32_t ordinal9;
  };

} PM4PFP_ATOMIC_MEM, *PPM4PFP_ATOMIC_MEM;
#endif

//--------------------PFP_CLEAR_STATE--------------------

#ifndef PM4_PFP_CLEAR_STATE_DEFINED
#define PM4_PFP_CLEAR_STATE_DEFINED
enum PFP_CLEAR_STATE_cmd_enum {
  cmd__pfp_clear_state__clear_state = 0,
  cmd__pfp_clear_state__push_state = 1,
  cmd__pfp_clear_state__pop_state = 2,
  cmd__pfp_clear_state__push_clear_state = 3
};


typedef struct PM4_PFP_CLEAR_STATE {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_CLEAR_STATE_cmd_enum cmd : 4;
      uint32_t reserved1 : 28;
    } bitfields2;
    uint32_t ordinal2;
  };

} PM4PFP_CLEAR_STATE, *PPM4PFP_CLEAR_STATE;
#endif

//--------------------PFP_COND_EXEC--------------------

#ifndef PM4_PFP_COND_EXEC_DEFINED
#define PM4_PFP_COND_EXEC_DEFINED

typedef struct PM4_PFP_COND_EXEC {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 2;
      uint32_t addr_lo : 30;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t addr_hi;

  uint32_t reserved2;

  union {
    struct {
      uint32_t exec_count : 14;
      uint32_t reserved3 : 18;
    } bitfields5;
    uint32_t ordinal5;
  };

} PM4PFP_COND_EXEC, *PPM4PFP_COND_EXEC;
#endif

//--------------------PFP_COND_INDIRECT_BUFFER--------------------

#ifndef PM4_PFP_COND_INDIRECT_BUFFER_DEFINED
#define PM4_PFP_COND_INDIRECT_BUFFER_DEFINED
enum PFP_COND_INDIRECT_BUFFER_mode_enum {
  mode__pfp_cond_indirect_buffer__if_then = 1,
  mode__pfp_cond_indirect_buffer__if_then_else = 2
};

enum PFP_COND_INDIRECT_BUFFER_function_enum {
  function__pfp_cond_indirect_buffer__always_pass = 0,
  function__pfp_cond_indirect_buffer__less_than_ref_value = 1,
  function__pfp_cond_indirect_buffer__less_than_equal_to_the_ref_value = 2,
  function__pfp_cond_indirect_buffer__equal_to_the_reference_value = 3,
  function__pfp_cond_indirect_buffer__not_equal_reference_value = 4,
  function__pfp_cond_indirect_buffer__greater_than_or_equal_reference_value = 5,
  function__pfp_cond_indirect_buffer__greater_than_reference_value = 6
};

enum PFP_COND_INDIRECT_BUFFER_cache_policy1_enum {
  cache_policy1__pfp_cond_indirect_buffer__lru = 0,
  cache_policy1__pfp_cond_indirect_buffer__stream = 1
};

enum PFP_COND_INDIRECT_BUFFER_cache_policy2_enum {
  cache_policy2__pfp_cond_indirect_buffer__lru = 0,
  cache_policy2__pfp_cond_indirect_buffer__stream = 1
};


typedef struct PM4_PFP_COND_INDIRECT_BUFFER {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_COND_INDIRECT_BUFFER_mode_enum mode : 2;
      uint32_t reserved1 : 6;
      PFP_COND_INDIRECT_BUFFER_function_enum function : 3;
      uint32_t reserved2 : 21;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t reserved3 : 3;
      uint32_t compare_addr_lo : 29;
    } bitfields3;
    uint32_t ordinal3;
  };

  uint32_t compare_addr_hi;

  uint32_t mask_lo;

  uint32_t mask_hi;

  uint32_t reference_lo;

  uint32_t reference_hi;

  union {
    struct {
      uint32_t reserved4 : 2;
      uint32_t ib_base1_lo : 30;
    } bitfields9;
    uint32_t ordinal9;
  };

  uint32_t ib_base1_hi;

  union {
    struct {
      uint32_t ib_size1 : 20;
      uint32_t reserved5 : 8;
      PFP_COND_INDIRECT_BUFFER_cache_policy1_enum cache_policy1 : 2;
      uint32_t reserved6 : 2;
    } bitfields11;
    uint32_t ordinal11;
  };

  union {
    struct {
      uint32_t reserved7 : 2;
      uint32_t ib_base2_lo : 30;
    } bitfields12;
    uint32_t ordinal12;
  };

  uint32_t ib_base2_hi;

  union {
    struct {
      uint32_t ib_size2 : 20;
      uint32_t reserved8 : 8;
      PFP_COND_INDIRECT_BUFFER_cache_policy2_enum cache_policy2 : 2;
      uint32_t reserved9 : 2;
    } bitfields14;
    uint32_t ordinal14;
  };

} PM4PFP_COND_INDIRECT_BUFFER, *PPM4PFP_COND_INDIRECT_BUFFER;
#endif

//--------------------PFP_CONTEXT_CONTROL--------------------

#ifndef PM4_PFP_CONTEXT_CONTROL_DEFINED
#define PM4_PFP_CONTEXT_CONTROL_DEFINED

typedef struct PM4_PFP_CONTEXT_CONTROL {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t load_global_config : 1;
      uint32_t load_per_context_state : 1;
      uint32_t reserved1 : 13;
      uint32_t load_global_uconfig : 1;
      uint32_t load_gfx_sh_regs : 1;
      uint32_t reserved2 : 7;
      uint32_t load_cs_sh_regs : 1;
      uint32_t reserved3 : 3;
      uint32_t load_ce_ram : 1;
      uint32_t reserved4 : 2;
      uint32_t load_enable : 1;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t shadow_global_config : 1;
      uint32_t shadow_per_context_state : 1;
      uint32_t reserved5 : 13;
      uint32_t shadow_global_uconfig : 1;
      uint32_t shadow_gfx_sh_regs : 1;
      uint32_t reserved6 : 7;
      uint32_t shadow_cs_sh_regs : 1;
      uint32_t reserved7 : 6;
      uint32_t shadow_enable : 1;
    } bitfields3;
    uint32_t ordinal3;
  };

} PM4PFP_CONTEXT_CONTROL, *PPM4PFP_CONTEXT_CONTROL;
#endif

//--------------------PFP_CONTEXT_REG_RMW--------------------

#ifndef PM4_PFP_CONTEXT_REG_RMW_DEFINED
#define PM4_PFP_CONTEXT_REG_RMW_DEFINED

typedef struct PM4_PFP_CONTEXT_REG_RMW {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved1 : 16;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t reg_mask;

  uint32_t reg_data;

} PM4PFP_CONTEXT_REG_RMW, *PPM4PFP_CONTEXT_REG_RMW;
#endif

//--------------------PFP_COPY_DATA--------------------

#ifndef PM4_PFP_COPY_DATA_DEFINED
#define PM4_PFP_COPY_DATA_DEFINED
enum PFP_COPY_DATA_src_sel_enum {
  src_sel__pfp_copy_data__mem_mapped_register = 0,
  src_sel__pfp_copy_data__memory = 1,
  src_sel__pfp_copy_data__tc_l2 = 2,
  src_sel__pfp_copy_data__immediate_data = 5
};

enum PFP_COPY_DATA_dst_sel_enum {
  dst_sel__pfp_copy_data__mem_mapped_register = 0,
  dst_sel__pfp_copy_data__tc_l2 = 2,
  dst_sel__pfp_copy_data__memory = 5
};

enum PFP_COPY_DATA_src_cache_policy_enum {
  src_cache_policy__pfp_copy_data__lru = 0,
  src_cache_policy__pfp_copy_data__stream = 1
};

enum PFP_COPY_DATA_count_sel_enum {
  count_sel__pfp_copy_data__32_bits_of_data = 0,
  count_sel__pfp_copy_data__64_bits_of_data = 1
};

enum PFP_COPY_DATA_wr_confirm_enum {
  wr_confirm__pfp_copy_data__do_not_wait_for_confirmation = 0,
  wr_confirm__pfp_copy_data__wait_for_confirmation = 1
};

enum PFP_COPY_DATA_dst_cache_policy_enum {
  dst_cache_policy__pfp_copy_data__lru = 0,
  dst_cache_policy__pfp_copy_data__stream = 1
};

enum PFP_COPY_DATA_engine_sel_enum { engine_sel__pfp_copy_data__prefetch_parser = 1 };


typedef struct PM4_PFP_COPY_DATA {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_COPY_DATA_src_sel_enum src_sel : 4;
      uint32_t reserved1 : 4;
      PFP_COPY_DATA_dst_sel_enum dst_sel : 4;
      uint32_t reserved2 : 1;
      PFP_COPY_DATA_src_cache_policy_enum src_cache_policy : 2;
      uint32_t reserved3 : 1;
      PFP_COPY_DATA_count_sel_enum count_sel : 1;
      uint32_t reserved4 : 3;
      PFP_COPY_DATA_wr_confirm_enum wr_confirm : 1;
      uint32_t reserved5 : 4;
      PFP_COPY_DATA_dst_cache_policy_enum dst_cache_policy : 2;
      uint32_t reserved6 : 3;
      PFP_COPY_DATA_engine_sel_enum engine_sel : 2;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t src_reg_offset : 18;
      uint32_t reserved7 : 14;
    } bitfields3a;
    struct {
      uint32_t reserved8 : 2;
      uint32_t src_32b_addr_lo : 30;
    } bitfields3b;
    struct {
      uint32_t reserved9 : 3;
      uint32_t src_64b_addr_lo : 29;
    } bitfields3c;
    uint32_t imm_data;

    uint32_t ordinal3;
  };

  union {
    uint32_t src_memtc_addr_hi;

    uint32_t src_imm_data;

    uint32_t ordinal4;
  };

  union {
    struct {
      uint32_t dst_reg_offset : 18;
      uint32_t reserved10 : 14;
    } bitfields5a;
    struct {
      uint32_t reserved11 : 2;
      uint32_t dst_32b_addr_lo : 30;
    } bitfields5b;
    struct {
      uint32_t reserved12 : 3;
      uint32_t dst_64b_addr_lo : 29;
    } bitfields5c;
    uint32_t ordinal5;
  };

  uint32_t dst_addr_hi;

} PM4PFP_COPY_DATA, *PPM4PFP_COPY_DATA;
#endif

//--------------------PFP_COPY_DATA_RB--------------------

#ifndef PM4_PFP_COPY_DATA_RB_DEFINED
#define PM4_PFP_COPY_DATA_RB_DEFINED

typedef struct PM4_PFP_COPY_DATA_RB {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t src_addr_lo;

  uint32_t src_addr_hi;

  uint32_t ptr_addr_lo;

  uint32_t ptr_addr_hi;

  uint32_t data_size;

  uint32_t circular_buffer_size;

  uint32_t circular_buffer_addr_lo;

  uint32_t circular_buffer_addr_hi;

} PM4PFP_COPY_DATA_RB, *PPM4PFP_COPY_DATA_RB;
#endif

//--------------------PFP_DISPATCH_DIRECT--------------------

#ifndef PM4_PFP_DISPATCH_DIRECT_DEFINED
#define PM4_PFP_DISPATCH_DIRECT_DEFINED

typedef struct PM4_PFP_DISPATCH_DIRECT {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t dim_x;

  uint32_t dim_y;

  uint32_t dim_z;

  uint32_t dispatch_initiator;

} PM4PFP_DISPATCH_DIRECT, *PPM4PFP_DISPATCH_DIRECT;
#endif

//--------------------PFP_DISPATCH_INDIRECT--------------------

#ifndef PM4_PFP_DISPATCH_INDIRECT_DEFINED
#define PM4_PFP_DISPATCH_INDIRECT_DEFINED

typedef struct PM4_PFP_DISPATCH_INDIRECT {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t data_offset;

  uint32_t dispatch_initiator;

} PM4PFP_DISPATCH_INDIRECT, *PPM4PFP_DISPATCH_INDIRECT;
#endif

//--------------------PFP_DMA_DATA--------------------

#ifndef PM4_PFP_DMA_DATA_DEFINED
#define PM4_PFP_DMA_DATA_DEFINED
enum PFP_DMA_DATA_engine_sel_enum { engine_sel__pfp_dma_data__prefetch_parser = 1 };

enum PFP_DMA_DATA_src_cache_policy_enum {
  src_cache_policy__pfp_dma_data__lru = 0,
  src_cache_policy__pfp_dma_data__stream = 1
};

enum PFP_DMA_DATA_dst_sel_enum {
  dst_sel__pfp_dma_data__dst_addr_using_das = 0,
  dst_sel__pfp_dma_data__gds = 1,
  dst_sel__pfp_dma_data__dst_nowhere = 2,
  dst_sel__pfp_dma_data__dst_addr_using_l2 = 3
};

enum PFP_DMA_DATA_dst_cache_policy_enum {
  dst_cache_policy__pfp_dma_data__lru = 0,
  dst_cache_policy__pfp_dma_data__stream = 1
};

enum PFP_DMA_DATA_src_sel_enum {
  src_sel__pfp_dma_data__src_addr_using_sas = 0,
  src_sel__pfp_dma_data__gds = 1,
  src_sel__pfp_dma_data__data = 2,
  src_sel__pfp_dma_data__src_addr_using_l2 = 3
};

enum PFP_DMA_DATA_sas_enum { sas__pfp_dma_data__memory = 0, sas__pfp_dma_data__register = 1 };

enum PFP_DMA_DATA_das_enum { das__pfp_dma_data__memory = 0, das__pfp_dma_data__register = 1 };

enum PFP_DMA_DATA_saic_enum {
  saic__pfp_dma_data__increment = 0,
  saic__pfp_dma_data__no_increment = 1
};

enum PFP_DMA_DATA_daic_enum {
  daic__pfp_dma_data__increment = 0,
  daic__pfp_dma_data__no_increment = 1
};


typedef struct PM4_PFP_DMA_DATA {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_DMA_DATA_engine_sel_enum engine_sel : 1;
      uint32_t reserved1 : 12;
      PFP_DMA_DATA_src_cache_policy_enum src_cache_policy : 2;
      uint32_t reserved2 : 5;
      PFP_DMA_DATA_dst_sel_enum dst_sel : 2;
      uint32_t reserved3 : 3;
      PFP_DMA_DATA_dst_cache_policy_enum dst_cache_policy : 2;
      uint32_t reserved4 : 2;
      PFP_DMA_DATA_src_sel_enum src_sel : 2;
      uint32_t cp_sync : 1;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t src_addr_lo_or_data;

  uint32_t src_addr_hi;

  uint32_t dst_addr_lo;

  uint32_t dst_addr_hi;

  union {
    struct {
      uint32_t byte_count : 26;
      PFP_DMA_DATA_sas_enum sas : 1;
      PFP_DMA_DATA_das_enum das : 1;
      PFP_DMA_DATA_saic_enum saic : 1;
      PFP_DMA_DATA_daic_enum daic : 1;
      uint32_t raw_wait : 1;
      uint32_t dis_wc : 1;
    } bitfields7;
    uint32_t ordinal7;
  };

} PM4PFP_DMA_DATA, *PPM4PFP_DMA_DATA;
#endif

//--------------------PFP_DMA_DATA_FILL_MULTI--------------------

#ifndef PM4_PFP_DMA_DATA_FILL_MULTI_DEFINED
#define PM4_PFP_DMA_DATA_FILL_MULTI_DEFINED
enum PFP_DMA_DATA_FILL_MULTI_engine_sel_enum {
  engine_sel__pfp_dma_data_fill_multi__micro_engine = 0,
  engine_sel__pfp_dma_data_fill_multi__prefetch_parser = 1
};

enum PFP_DMA_DATA_FILL_MULTI_dst_sel_enum {
  dst_sel__pfp_dma_data_fill_multi__dst_addr_using_l2 = 3
};

enum PFP_DMA_DATA_FILL_MULTI_dst_cache_policy_enum {
  dst_cache_policy__pfp_dma_data_fill_multi__lru = 0,
  dst_cache_policy__pfp_dma_data_fill_multi__stream = 1
};

enum PFP_DMA_DATA_FILL_MULTI_src_sel_enum { src_sel__pfp_dma_data_fill_multi__data = 2 };


typedef struct PM4_PFP_DMA_DATA_FILL_MULTI {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_DMA_DATA_FILL_MULTI_engine_sel_enum engine_sel : 1;
      uint32_t reserved1 : 9;
      uint32_t memlog_clear : 1;
      uint32_t reserved2 : 9;
      PFP_DMA_DATA_FILL_MULTI_dst_sel_enum dst_sel : 2;
      uint32_t reserved3 : 3;
      PFP_DMA_DATA_FILL_MULTI_dst_cache_policy_enum dst_cache_policy : 2;
      uint32_t reserved4 : 2;
      PFP_DMA_DATA_FILL_MULTI_src_sel_enum src_sel : 2;
      uint32_t cp_sync : 1;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t byte_stride;

  uint32_t dma_count;

  uint32_t dst_addr_lo;

  uint32_t dst_addr_hi;

  union {
    struct {
      uint32_t byte_count : 26;
      uint32_t reserved5 : 6;
    } bitfields7;
    uint32_t ordinal7;
  };

} PM4PFP_DMA_DATA_FILL_MULTI, *PPM4PFP_DMA_DATA_FILL_MULTI;
#endif

//--------------------PFP_DRAW_INDEX_2--------------------

#ifndef PM4_PFP_DRAW_INDEX_2_DEFINED
#define PM4_PFP_DRAW_INDEX_2_DEFINED

typedef struct PM4_PFP_DRAW_INDEX_2 {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t max_size;

  uint32_t index_base_lo;

  uint32_t index_base_hi;

  uint32_t index_count;

  uint32_t draw_initiator;

} PM4PFP_DRAW_INDEX_2, *PPM4PFP_DRAW_INDEX_2;
#endif

//--------------------PFP_DRAW_INDEX_AUTO--------------------

#ifndef PM4_PFP_DRAW_INDEX_AUTO_DEFINED
#define PM4_PFP_DRAW_INDEX_AUTO_DEFINED

typedef struct PM4_PFP_DRAW_INDEX_AUTO {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t index_count;

  uint32_t draw_initiator;

} PM4PFP_DRAW_INDEX_AUTO, *PPM4PFP_DRAW_INDEX_AUTO;
#endif

//--------------------PFP_DRAW_INDEX_INDIRECT--------------------

#ifndef PM4_PFP_DRAW_INDEX_INDIRECT_DEFINED
#define PM4_PFP_DRAW_INDEX_INDIRECT_DEFINED

typedef struct PM4_PFP_DRAW_INDEX_INDIRECT {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t data_offset;

  union {
    struct {
      uint32_t base_vtx_loc : 16;
      uint32_t reserved1 : 16;
    } bitfields3;
    uint32_t ordinal3;
  };

  union {
    struct {
      uint32_t start_inst_loc : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  uint32_t draw_initiator;

} PM4PFP_DRAW_INDEX_INDIRECT, *PPM4PFP_DRAW_INDEX_INDIRECT;
#endif

//--------------------PFP_DRAW_INDEX_INDIRECT_MULTI--------------------

#ifndef PM4_PFP_DRAW_INDEX_INDIRECT_MULTI_DEFINED
#define PM4_PFP_DRAW_INDEX_INDIRECT_MULTI_DEFINED

typedef struct PM4_PFP_DRAW_INDEX_INDIRECT_MULTI {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t data_offset;

  union {
    struct {
      uint32_t base_vtx_loc : 16;
      uint32_t reserved1 : 16;
    } bitfields3;
    uint32_t ordinal3;
  };

  union {
    struct {
      uint32_t start_inst_loc : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  union {
    struct {
      uint32_t draw_index_loc : 16;
      uint32_t reserved3 : 14;
      uint32_t count_indirect_enable : 1;
      uint32_t draw_index_enable : 1;
    } bitfields5;
    uint32_t ordinal5;
  };

  uint32_t count;

  union {
    struct {
      uint32_t count_addr_lo : 30;
      uint32_t reserved4 : 2;
    } bitfields7;
    uint32_t ordinal7;
  };

  uint32_t count_addr_hi;

  uint32_t stride;

  uint32_t draw_initiator;

} PM4PFP_DRAW_INDEX_INDIRECT_MULTI, *PPM4PFP_DRAW_INDEX_INDIRECT_MULTI;
#endif

//--------------------PFP_DRAW_INDEX_MULTI_AUTO--------------------

#ifndef PM4_PFP_DRAW_INDEX_MULTI_AUTO_DEFINED
#define PM4_PFP_DRAW_INDEX_MULTI_AUTO_DEFINED

typedef struct PM4_PFP_DRAW_INDEX_MULTI_AUTO {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t prim_count;

  uint32_t draw_initiator;

  union {
    struct {
      uint32_t index_offset : 16;
      uint32_t prim_type : 5;
      uint32_t index_count : 11;
    } bitfields4;
    uint32_t ordinal4;
  };

} PM4PFP_DRAW_INDEX_MULTI_AUTO, *PPM4PFP_DRAW_INDEX_MULTI_AUTO;
#endif

//--------------------PFP_DRAW_INDEX_MULTI_INST--------------------

#ifndef PM4_PFP_DRAW_INDEX_MULTI_INST_DEFINED
#define PM4_PFP_DRAW_INDEX_MULTI_INST_DEFINED

typedef struct PM4_PFP_DRAW_INDEX_MULTI_INST {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t instance_count;

  uint32_t obj_id_addr_lo;

  uint32_t obj_id_addr_hi;

  uint32_t max_size;

  uint32_t index_base_lo;

  uint32_t index_base_hi;

  uint32_t index_count;

  uint32_t draw_initiator;

} PM4PFP_DRAW_INDEX_MULTI_INST, *PPM4PFP_DRAW_INDEX_MULTI_INST;
#endif

//--------------------PFP_DRAW_INDEX_OFFSET_2--------------------

#ifndef PM4_PFP_DRAW_INDEX_OFFSET_2_DEFINED
#define PM4_PFP_DRAW_INDEX_OFFSET_2_DEFINED

typedef struct PM4_PFP_DRAW_INDEX_OFFSET_2 {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t max_size;

  uint32_t index_offset;

  uint32_t index_count;

  uint32_t draw_initiator;

} PM4PFP_DRAW_INDEX_OFFSET_2, *PPM4PFP_DRAW_INDEX_OFFSET_2;
#endif

//--------------------PFP_DRAW_INDIRECT--------------------

#ifndef PM4_PFP_DRAW_INDIRECT_DEFINED
#define PM4_PFP_DRAW_INDIRECT_DEFINED

typedef struct PM4_PFP_DRAW_INDIRECT {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t data_offset;

  union {
    struct {
      uint32_t base_vtx_loc : 16;
      uint32_t reserved1 : 16;
    } bitfields3;
    uint32_t ordinal3;
  };

  union {
    struct {
      uint32_t start_inst_loc : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  uint32_t draw_initiator;

} PM4PFP_DRAW_INDIRECT, *PPM4PFP_DRAW_INDIRECT;
#endif

//--------------------PFP_DRAW_INDIRECT_MULTI--------------------

#ifndef PM4_PFP_DRAW_INDIRECT_MULTI_DEFINED
#define PM4_PFP_DRAW_INDIRECT_MULTI_DEFINED

typedef struct PM4_PFP_DRAW_INDIRECT_MULTI {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t data_offset;

  union {
    struct {
      uint32_t base_vtx_loc : 16;
      uint32_t reserved1 : 16;
    } bitfields3;
    uint32_t ordinal3;
  };

  union {
    struct {
      uint32_t start_inst_loc : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  union {
    struct {
      uint32_t draw_index_loc : 16;
      uint32_t reserved3 : 14;
      uint32_t count_indirect_enable : 1;
      uint32_t draw_index_enable : 1;
    } bitfields5;
    uint32_t ordinal5;
  };

  uint32_t count;

  union {
    struct {
      uint32_t count_addr_lo : 30;
      uint32_t reserved4 : 2;
    } bitfields7;
    uint32_t ordinal7;
  };

  uint32_t count_addr_hi;

  uint32_t stride;

  uint32_t draw_initiator;

} PM4PFP_DRAW_INDIRECT_MULTI, *PPM4PFP_DRAW_INDIRECT_MULTI;
#endif

//--------------------PFP_FRAME_CONTROL--------------------

#ifndef PM4_PFP_FRAME_CONTROL_DEFINED
#define PM4_PFP_FRAME_CONTROL_DEFINED
enum PFP_FRAME_CONTROL_command_enum {
  command__pfp_frame_control__tmz_begin = 0,
  command__pfp_frame_control__tmz_end = 1
};


typedef struct PM4_PFP_FRAME_CONTROL {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t tmz : 1;
      uint32_t reserved1 : 27;
      PFP_FRAME_CONTROL_command_enum command : 4;
    } bitfields2;
    uint32_t ordinal2;
  };

} PM4PFP_FRAME_CONTROL, *PPM4PFP_FRAME_CONTROL;
#endif

//--------------------PFP_GEN_PDEPTE--------------------

#ifndef PM4_PFP_GEN_PDEPTE_DEFINED
#define PM4_PFP_GEN_PDEPTE_DEFINED

typedef struct PM4_PFP_GEN_PDEPTE {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t dst_addr_lo;

  uint32_t dst_addr_hi;

  uint32_t mask_lo;

  uint32_t mask_hi;

  uint32_t init_value_lo;

  uint32_t init_value_hi;

  uint32_t incr_lo;

  uint32_t incr_hi;

  uint32_t loop_count;

} PM4PFP_GEN_PDEPTE, *PPM4PFP_GEN_PDEPTE;
#endif

//--------------------PFP_INDEX_ATTRIBUTES_INDIRECT--------------------

#ifndef PM4_PFP_INDEX_ATTRIBUTES_INDIRECT_DEFINED
#define PM4_PFP_INDEX_ATTRIBUTES_INDIRECT_DEFINED

typedef struct PM4_PFP_INDEX_ATTRIBUTES_INDIRECT {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 3;
      uint32_t attribute_base_lo : 29;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t attribute_base_hi;

  union {
    struct {
      uint32_t attribute_index : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

} PM4PFP_INDEX_ATTRIBUTES_INDIRECT, *PPM4PFP_INDEX_ATTRIBUTES_INDIRECT;
#endif

//--------------------PFP_INDEX_BASE--------------------

#ifndef PM4_PFP_INDEX_BASE_DEFINED
#define PM4_PFP_INDEX_BASE_DEFINED

typedef struct PM4_PFP_INDEX_BASE {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 1;
      uint32_t index_base_lo : 31;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t index_base_hi;

} PM4PFP_INDEX_BASE, *PPM4PFP_INDEX_BASE;
#endif

//--------------------PFP_INDEX_BUFFER_SIZE--------------------

#ifndef PM4_PFP_INDEX_BUFFER_SIZE_DEFINED
#define PM4_PFP_INDEX_BUFFER_SIZE_DEFINED

typedef struct PM4_PFP_INDEX_BUFFER_SIZE {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t index_buffer_size;

} PM4PFP_INDEX_BUFFER_SIZE, *PPM4PFP_INDEX_BUFFER_SIZE;
#endif

//--------------------PFP_INDIRECT_BUFFER--------------------

#ifndef PM4_PFP_INDIRECT_BUFFER_DEFINED
#define PM4_PFP_INDIRECT_BUFFER_DEFINED
enum PFP_INDIRECT_BUFFER_cache_policy_enum {
  cache_policy__pfp_indirect_buffer__lru = 0,
  cache_policy__pfp_indirect_buffer__stream = 1
};


typedef struct PM4_PFP_INDIRECT_BUFFER {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 2;
      uint32_t ib_base_lo : 30;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t ib_base_hi;

  union {
    struct {
      uint32_t ib_size : 20;
      uint32_t chain : 1;
      uint32_t pre_ena : 1;
      uint32_t reserved2 : 2;
      uint32_t vmid : 4;
      PFP_INDIRECT_BUFFER_cache_policy_enum cache_policy : 2;
      uint32_t pre_resume : 1;
      uint32_t priv : 1;
    } bitfields4;
    uint32_t ordinal4;
  };

} PM4PFP_INDIRECT_BUFFER, *PPM4PFP_INDIRECT_BUFFER;
#endif

//--------------------PFP_LOAD_CONFIG_REG--------------------

#ifndef PM4_PFP_LOAD_CONFIG_REG_DEFINED
#define PM4_PFP_LOAD_CONFIG_REG_DEFINED

typedef struct PM4_PFP_LOAD_CONFIG_REG {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 2;
      uint32_t base_addr_lo : 30;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t base_addr_hi;

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  union {
    struct {
      uint32_t num_dwords : 14;
      uint32_t reserved3 : 18;
    } bitfields5;
    uint32_t ordinal5;
  };

} PM4PFP_LOAD_CONFIG_REG, *PPM4PFP_LOAD_CONFIG_REG;
#endif

//--------------------PFP_LOAD_CONTEXT_REG--------------------

#ifndef PM4_PFP_LOAD_CONTEXT_REG_DEFINED
#define PM4_PFP_LOAD_CONTEXT_REG_DEFINED

typedef struct PM4_PFP_LOAD_CONTEXT_REG {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 2;
      uint32_t base_addr_lo : 30;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t base_addr_hi;

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  union {
    struct {
      uint32_t num_dwords : 14;
      uint32_t reserved3 : 18;
    } bitfields5;
    uint32_t ordinal5;
  };

} PM4PFP_LOAD_CONTEXT_REG, *PPM4PFP_LOAD_CONTEXT_REG;
#endif

//--------------------PFP_LOAD_SH_REG--------------------

#ifndef PM4_PFP_LOAD_SH_REG_DEFINED
#define PM4_PFP_LOAD_SH_REG_DEFINED

typedef struct PM4_PFP_LOAD_SH_REG {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 2;
      uint32_t base_address_lo : 30;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t base_address_hi;

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  union {
    struct {
      uint32_t num_dword : 14;
      uint32_t reserved3 : 18;
    } bitfields5;
    uint32_t ordinal5;
  };

} PM4PFP_LOAD_SH_REG, *PPM4PFP_LOAD_SH_REG;
#endif

//--------------------PFP_LOAD_UCONFIG_REG--------------------

#ifndef PM4_PFP_LOAD_UCONFIG_REG_DEFINED
#define PM4_PFP_LOAD_UCONFIG_REG_DEFINED

typedef struct PM4_PFP_LOAD_UCONFIG_REG {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 2;
      uint32_t base_address_lo : 30;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t base_address_hi;

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved2 : 16;
    } bitfields4;
    uint32_t ordinal4;
  };

  union {
    struct {
      uint32_t num_dwords : 14;
      uint32_t reserved3 : 18;
    } bitfields5;
    uint32_t ordinal5;
  };

} PM4PFP_LOAD_UCONFIG_REG, *PPM4PFP_LOAD_UCONFIG_REG;
#endif

//--------------------PFP_NOP--------------------

#ifndef PM4_PFP_NOP_DEFINED
#define PM4_PFP_NOP_DEFINED

typedef struct PM4_PFP_NOP {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  //  uint32_t data_block[];  // N-DWords

} PM4PFP_NOP, *PPM4PFP_NOP;
#endif

//--------------------PFP_NUM_INSTANCES--------------------

#ifndef PM4_PFP_NUM_INSTANCES_DEFINED
#define PM4_PFP_NUM_INSTANCES_DEFINED

typedef struct PM4_PFP_NUM_INSTANCES {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t num_instances;

} PM4PFP_NUM_INSTANCES, *PPM4PFP_NUM_INSTANCES;
#endif

//--------------------PFP_OCCLUSION_QUERY--------------------

#ifndef PM4_PFP_OCCLUSION_QUERY_DEFINED
#define PM4_PFP_OCCLUSION_QUERY_DEFINED

typedef struct PM4_PFP_OCCLUSION_QUERY {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 4;
      uint32_t start_addr_lo : 28;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t start_addr_hi;

  union {
    struct {
      uint32_t reserved2 : 2;
      uint32_t query_addr_lo : 30;
    } bitfields4;
    uint32_t ordinal4;
  };

  uint32_t query_addr_hi;

} PM4PFP_OCCLUSION_QUERY, *PPM4PFP_OCCLUSION_QUERY;
#endif

//--------------------PFP_PFP_SYNC_ME--------------------

#ifndef PM4_PFP_PFP_SYNC_ME_DEFINED
#define PM4_PFP_PFP_SYNC_ME_DEFINED

typedef struct PM4_PFP_PFP_SYNC_ME {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  uint32_t dummy_data;

} PM4PFP_PFP_SYNC_ME, *PPM4PFP_PFP_SYNC_ME;
#endif

//--------------------PFP_PREAMBLE_CNTL--------------------

#ifndef PM4_PFP_PREAMBLE_CNTL_DEFINED
#define PM4_PFP_PREAMBLE_CNTL_DEFINED
enum PFP_PREAMBLE_CNTL_command_enum {
  command__pfp_preamble_cntl__preamble_begin = 0,
  command__pfp_preamble_cntl__preamble_end = 1,
  command__pfp_preamble_cntl__begin_of_clear_state_initialization = 2,
  command__pfp_preamble_cntl__end_of_clear_state_initialization = 3
};


typedef struct PM4_PFP_PREAMBLE_CNTL {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 28;
      PFP_PREAMBLE_CNTL_command_enum command : 4;
    } bitfields2;
    uint32_t ordinal2;
  };

} PM4PFP_PREAMBLE_CNTL, *PPM4PFP_PREAMBLE_CNTL;
#endif

//--------------------PFP_PRED_EXEC--------------------

#ifndef PM4_PFP_PRED_EXEC_DEFINED
#define PM4_PFP_PRED_EXEC_DEFINED

typedef struct PM4_PFP_PRED_EXEC {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t exec_count : 14;
      uint32_t reserved1 : 10;
      uint32_t device_select : 8;
    } bitfields2;
    uint32_t ordinal2;
  };

} PM4PFP_PRED_EXEC, *PPM4PFP_PRED_EXEC;
#endif

//--------------------PFP_PRIME_UTCL2--------------------

#ifndef PM4_PFP_PRIME_UTCL2_DEFINED
#define PM4_PFP_PRIME_UTCL2_DEFINED
enum PFP_PRIME_UTCL2_cache_perm_enum {
  cache_perm__pfp_prime_utcl2__read = 0,
  cache_perm__pfp_prime_utcl2__write = 1,
  cache_perm__pfp_prime_utcl2__execute = 2
};

enum PFP_PRIME_UTCL2_prime_mode_enum {
  prime_mode__pfp_prime_utcl2__dont_wait_for_xack = 0,
  prime_mode__pfp_prime_utcl2__wait_for_xack = 1
};

enum PFP_PRIME_UTCL2_engine_sel_enum { engine_sel__pfp_prime_utcl2__prefetch_parser = 1 };


typedef struct PM4_PFP_PRIME_UTCL2 {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_PRIME_UTCL2_cache_perm_enum cache_perm : 3;
      PFP_PRIME_UTCL2_prime_mode_enum prime_mode : 1;
      uint32_t reserved1 : 26;
      PFP_PRIME_UTCL2_engine_sel_enum engine_sel : 2;
    } bitfields2;
    uint32_t ordinal2;
  };

  uint32_t addr_lo;

  uint32_t addr_hi;

  union {
    struct {
      uint32_t requested_pages : 14;
      uint32_t reserved2 : 18;
    } bitfields5;
    uint32_t ordinal5;
  };

} PM4PFP_PRIME_UTCL2, *PPM4PFP_PRIME_UTCL2;
#endif

//--------------------PFP_REWIND--------------------

#ifndef PM4_PFP_REWIND_DEFINED
#define PM4_PFP_REWIND_DEFINED

typedef struct PM4_PFP_REWIND {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 31;
      uint32_t valid : 1;
    } bitfields2;
    uint32_t ordinal2;
  };

} PM4PFP_REWIND, *PPM4PFP_REWIND;
#endif

//--------------------PFP_SET_BASE--------------------

#ifndef PM4_PFP_SET_BASE_DEFINED
#define PM4_PFP_SET_BASE_DEFINED
enum PFP_SET_BASE_base_index_enum {
  base_index__pfp_set_base__display_list_patch_table_base = 0,
  base_index__pfp_set_base__patch_table_base = 1,
  base_index__pfp_set_base__shader_or_context_reg_base_addr = 4,
  base_index__pfp_set_base__indirect_data_base = 5
};


typedef struct PM4_PFP_SET_BASE {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_SET_BASE_base_index_enum base_index : 4;
      uint32_t reserved1 : 28;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t reserved2 : 3;
      uint32_t address_lo : 29;
    } bitfields3;
    uint32_t ordinal3;
  };

  uint32_t address_hi;

} PM4PFP_SET_BASE, *PPM4PFP_SET_BASE;
#endif

//--------------------PFP_SET_CONTEXT_REG--------------------

#ifndef PM4_PFP_SET_CONTEXT_REG_DEFINED
#define PM4_PFP_SET_CONTEXT_REG_DEFINED
enum PFP_SET_CONTEXT_REG_index_enum {
  index__pfp_set_context_reg__default = 0,
  index__pfp_set_context_reg__vgt_ls_hs_config = 2
};


typedef struct PM4_PFP_SET_CONTEXT_REG {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved1 : 12;
      PFP_SET_CONTEXT_REG_index_enum index : 4;
    } bitfields2;
    uint32_t ordinal2;
  };

  //  uint32_t reg_data[];  // N-DWords

} PM4PFP_SET_CONTEXT_REG, *PPM4PFP_SET_CONTEXT_REG;
#endif

//--------------------PFP_SET_PREDICATION--------------------

#ifndef PM4_PFP_SET_PREDICATION_DEFINED
#define PM4_PFP_SET_PREDICATION_DEFINED
enum PFP_SET_PREDICATION_pred_bool_enum {
  pred_bool__pfp_set_predication__draw_if_not_visible_or_overflow = 0,
  pred_bool__pfp_set_predication__draw_if_visible_or_no_overflow = 1
};

enum PFP_SET_PREDICATION_hint_enum {
  hint__pfp_set_predication__wait_until_final_zpass_written = 0,
  hint__pfp_set_predication__draw_if_not_final_zpass_written = 1
};

enum PFP_SET_PREDICATION_pred_op_enum {
  pred_op__pfp_set_predication__clear_predicate = 0,
  pred_op__pfp_set_predication__set_zpass_predicate = 1,
  pred_op__pfp_set_predication__set_primcount_predicate = 2,
  pred_op__pfp_set_predication__DX12 = 3
};

enum PFP_SET_PREDICATION_continue_bit_enum {
  continue_bit__pfp_set_predication__new_set_predication = 0,
  continue_bit__pfp_set_predication__continue_set_predication = 1
};


typedef struct PM4_PFP_SET_PREDICATION {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 8;
      PFP_SET_PREDICATION_pred_bool_enum pred_bool : 1;
      uint32_t reserved2 : 3;
      PFP_SET_PREDICATION_hint_enum hint : 1;
      uint32_t reserved3 : 3;
      PFP_SET_PREDICATION_pred_op_enum pred_op : 3;
      uint32_t reserved4 : 12;
      PFP_SET_PREDICATION_continue_bit_enum continue_bit : 1;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t reserved5 : 4;
      uint32_t start_addr_lo : 28;
    } bitfields3;
    uint32_t ordinal3;
  };

  uint32_t start_addr_hi;

} PM4PFP_SET_PREDICATION, *PPM4PFP_SET_PREDICATION;
#endif

//--------------------PFP_SET_SH_REG_INDEX--------------------

#ifndef PM4_PFP_SET_SH_REG_INDEX_DEFINED
#define PM4_PFP_SET_SH_REG_INDEX_DEFINED
enum PFP_SET_SH_REG_INDEX_index_enum { index__pfp_set_sh_reg_index__apply_kmd_cu_and_mask = 3 };


typedef struct PM4_PFP_SET_SH_REG_INDEX {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved1 : 12;
      PFP_SET_SH_REG_INDEX_index_enum index : 4;
    } bitfields2;
    uint32_t ordinal2;
  };

  //  uint32_t reg_data[];  // N-DWords

} PM4PFP_SET_SH_REG_INDEX, *PPM4PFP_SET_SH_REG_INDEX;
#endif

//--------------------PFP_SET_SH_REG_OFFSET--------------------

#ifndef PM4_PFP_SET_SH_REG_OFFSET_DEFINED
#define PM4_PFP_SET_SH_REG_OFFSET_DEFINED
enum PFP_SET_SH_REG_OFFSET_index_enum {
  index__pfp_set_sh_reg_offset__normal_operation = 0,
  index__pfp_set_sh_reg_offset__data_indirect = 1
};


typedef struct PM4_PFP_SET_SH_REG_OFFSET {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved1 : 15;
      PFP_SET_SH_REG_OFFSET_index_enum index : 1;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    uint32_t ib_offset;

    uint32_t data_offset;

    uint32_t ordinal3;
  };

  union {
    struct {
      uint32_t reserved2 : 16;
      uint32_t driver_data : 16;
    } bitfields4a;
    uint32_t dummy;

    uint32_t ordinal4;
  };

} PM4PFP_SET_SH_REG_OFFSET, *PPM4PFP_SET_SH_REG_OFFSET;
#endif

//--------------------PFP_SET_UCONFIG_REG--------------------

#ifndef PM4_PFP_SET_UCONFIG_REG_DEFINED
#define PM4_PFP_SET_UCONFIG_REG_DEFINED
enum PFP_SET_UCONFIG_REG_index_enum {
  index__pfp_set_uconfig_reg__default = 0,
  index__pfp_set_uconfig_reg__prim_type = 1,
  index__pfp_set_uconfig_reg__index_type = 2,
  index__pfp_set_uconfig_reg__num_instances = 3,
  index__pfp_set_uconfig_reg__multi_vgt_param = 4
};


typedef struct PM4_PFP_SET_UCONFIG_REG {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reg_offset : 16;
      uint32_t reserved1 : 12;
      PFP_SET_UCONFIG_REG_index_enum index : 4;
    } bitfields2;
    uint32_t ordinal2;
  };

  //  uint32_t reg_data[];  // N-DWords

} PM4PFP_SET_UCONFIG_REG, *PPM4PFP_SET_UCONFIG_REG;
#endif

//--------------------PFP_STRMOUT_BUFFER_UPDATE--------------------

#ifndef PM4_PFP_STRMOUT_BUFFER_UPDATE_DEFINED
#define PM4_PFP_STRMOUT_BUFFER_UPDATE_DEFINED
enum PFP_STRMOUT_BUFFER_UPDATE_update_memory_enum {
  update_memory__pfp_strmout_buffer_update__dont_update_memory = 0,
  update_memory__pfp_strmout_buffer_update__update_memory_at_dst_address = 1
};

enum PFP_STRMOUT_BUFFER_UPDATE_source_select_enum {
  source_select__pfp_strmout_buffer_update__use_buffer_offset = 0,
  source_select__pfp_strmout_buffer_update__read_vgt_strmout_buffer_filled_size = 1,
  source_select__pfp_strmout_buffer_update__from_src_address = 2,
  source_select__pfp_strmout_buffer_update__none = 3
};

enum PFP_STRMOUT_BUFFER_UPDATE_data_type_enum {
  data_type__pfp_strmout_buffer_update__dwords = 0,
  data_type__pfp_strmout_buffer_update__bytes = 1
};

enum PFP_STRMOUT_BUFFER_UPDATE_buffer_select_enum {
  buffer_select__pfp_strmout_buffer_update__stream_out_buffer_0 = 0,
  buffer_select__pfp_strmout_buffer_update__stream_out_buffer_1 = 1,
  buffer_select__pfp_strmout_buffer_update__stream_out_buffer_2 = 2,
  buffer_select__pfp_strmout_buffer_update__stream_out_buffer_3 = 3
};


typedef struct PM4_PFP_STRMOUT_BUFFER_UPDATE {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_STRMOUT_BUFFER_UPDATE_update_memory_enum update_memory : 1;
      PFP_STRMOUT_BUFFER_UPDATE_source_select_enum source_select : 2;
      uint32_t reserved1 : 4;
      PFP_STRMOUT_BUFFER_UPDATE_data_type_enum data_type : 1;
      PFP_STRMOUT_BUFFER_UPDATE_buffer_select_enum buffer_select : 2;
      uint32_t reserved2 : 22;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t reserved3 : 2;
      uint32_t dst_address_lo : 30;
    } bitfields3;
    uint32_t ordinal3;
  };

  uint32_t dst_address_hi;

  uint32_t offset_or_address_lo;

  uint32_t src_address_hi;

} PM4PFP_STRMOUT_BUFFER_UPDATE, *PPM4PFP_STRMOUT_BUFFER_UPDATE;
#endif

//--------------------PFP_WAIT_REG_MEM--------------------

#ifndef PM4_PFP_WAIT_REG_MEM_DEFINED
#define PM4_PFP_WAIT_REG_MEM_DEFINED
enum PFP_WAIT_REG_MEM_function_enum {
  function__pfp_wait_reg_mem__always_pass = 0,
  function__pfp_wait_reg_mem__less_than_ref_value = 1,
  function__pfp_wait_reg_mem__less_than_equal_to_the_ref_value = 2,
  function__pfp_wait_reg_mem__equal_to_the_reference_value = 3,
  function__pfp_wait_reg_mem__not_equal_reference_value = 4,
  function__pfp_wait_reg_mem__greater_than_or_equal_reference_value = 5,
  function__pfp_wait_reg_mem__greater_than_reference_value = 6
};

enum PFP_WAIT_REG_MEM_mem_space_enum {
  mem_space__pfp_wait_reg_mem__register_space = 0,
  mem_space__pfp_wait_reg_mem__memory_space = 1
};

enum PFP_WAIT_REG_MEM_operation_enum {
  operation__pfp_wait_reg_mem__wait_reg_mem = 0,
  operation__pfp_wait_reg_mem__wr_wait_wr_reg = 1,
  operation__pfp_wait_reg_mem__wait_mem_preemptable = 3
};

enum PFP_WAIT_REG_MEM_engine_sel_enum { engine_sel__pfp_wait_reg_mem__prefetch_parser = 1 };


typedef struct PM4_PFP_WAIT_REG_MEM {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_WAIT_REG_MEM_function_enum function : 3;
      uint32_t reserved1 : 1;
      PFP_WAIT_REG_MEM_mem_space_enum mem_space : 2;
      PFP_WAIT_REG_MEM_operation_enum operation : 2;
      PFP_WAIT_REG_MEM_engine_sel_enum engine_sel : 2;
      uint32_t reserved2 : 22;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t reserved3 : 2;
      uint32_t mem_poll_addr_lo : 30;
    } bitfields3a;
    struct {
      uint32_t reg_poll_addr : 18;
      uint32_t reserved4 : 14;
    } bitfields3b;
    struct {
      uint32_t reg_write_addr1 : 18;
      uint32_t reserved5 : 14;
    } bitfields3c;
    uint32_t ordinal3;
  };

  union {
    uint32_t mem_poll_addr_hi;

    struct {
      uint32_t reg_write_addr2 : 18;
      uint32_t reserved6 : 14;
    } bitfields4b;
    uint32_t ordinal4;
  };

  uint32_t reference;

  uint32_t mask;

  union {
    struct {
      uint32_t poll_interval : 16;
      uint32_t reserved7 : 16;
    } bitfields7;
    uint32_t ordinal7;
  };

} PM4PFP_WAIT_REG_MEM, *PPM4PFP_WAIT_REG_MEM;
#endif

//--------------------PFP_WAIT_REG_MEM64--------------------

#ifndef PM4_PFP_WAIT_REG_MEM64_DEFINED
#define PM4_PFP_WAIT_REG_MEM64_DEFINED
enum PFP_WAIT_REG_MEM64_function_enum {
  function__pfp_wait_reg_mem64__always_pass = 0,
  function__pfp_wait_reg_mem64__less_than_ref_value = 1,
  function__pfp_wait_reg_mem64__less_than_equal_to_the_ref_value = 2,
  function__pfp_wait_reg_mem64__equal_to_the_reference_value = 3,
  function__pfp_wait_reg_mem64__not_equal_reference_value = 4,
  function__pfp_wait_reg_mem64__greater_than_or_equal_reference_value = 5,
  function__pfp_wait_reg_mem64__greater_than_reference_value = 6
};

enum PFP_WAIT_REG_MEM64_mem_space_enum {
  mem_space__pfp_wait_reg_mem64__register_space = 0,
  mem_space__pfp_wait_reg_mem64__memory_space = 1
};

enum PFP_WAIT_REG_MEM64_operation_enum {
  operation__pfp_wait_reg_mem64__wait_reg_mem = 0,
  operation__pfp_wait_reg_mem64__wr_wait_wr_reg = 1,
  operation__pfp_wait_reg_mem64__wait_mem_preemptable = 3
};

enum PFP_WAIT_REG_MEM64_engine_sel_enum {
  engine_sel__pfp_wait_reg_mem64__micro_engine = 0,
  engine_sel__pfp_wait_reg_mem64__prefetch_parser = 1,
  engine_sel__pfp_wait_reg_mem64__constant_engine = 2
};


typedef struct PM4_PFP_WAIT_REG_MEM64 {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      PFP_WAIT_REG_MEM64_function_enum function : 3;
      uint32_t reserved1 : 1;
      PFP_WAIT_REG_MEM64_mem_space_enum mem_space : 2;
      PFP_WAIT_REG_MEM64_operation_enum operation : 2;
      PFP_WAIT_REG_MEM64_engine_sel_enum engine_sel : 2;
      uint32_t reserved2 : 22;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t reserved3 : 3;
      uint32_t mem_poll_addr_lo : 29;
    } bitfields3a;
    struct {
      uint32_t reg_poll_addr : 18;
      uint32_t reserved4 : 14;
    } bitfields3b;
    struct {
      uint32_t reg_write_addr1 : 18;
      uint32_t reserved5 : 14;
    } bitfields3c;
    uint32_t ordinal3;
  };

  union {
    uint32_t mem_poll_addr_hi;

    struct {
      uint32_t reg_write_addr2 : 18;
      uint32_t reserved6 : 14;
    } bitfields4b;
    uint32_t ordinal4;
  };

  uint32_t reference;

  uint32_t reference_hi;

  uint32_t mask;

  uint32_t mask_hi;

  union {
    struct {
      uint32_t poll_interval : 16;
      uint32_t reserved7 : 16;
    } bitfields9;
    uint32_t ordinal9;
  };

} PM4PFP_WAIT_REG_MEM64, *PPM4PFP_WAIT_REG_MEM64;
#endif

//--------------------PFP_WRITE_DATA--------------------

#ifndef PM4_PFP_WRITE_DATA_DEFINED
#define PM4_PFP_WRITE_DATA_DEFINED
enum PFP_WRITE_DATA_dst_sel_enum {
  dst_sel__pfp_write_data__mem_mapped_register = 0,
  dst_sel__pfp_write_data__tc_l2 = 2,
  dst_sel__pfp_write_data__memory = 5,
  dst_sel__pfp_write_data__preemption_meta_memory = 8
};

enum PFP_WRITE_DATA_addr_incr_enum {
  addr_incr__pfp_write_data__increment_address = 0,
  addr_incr__pfp_write_data__do_not_increment_address = 1
};

enum PFP_WRITE_DATA_wr_confirm_enum {
  wr_confirm__pfp_write_data__do_not_wait_for_write_confirmation = 0,
  wr_confirm__pfp_write_data__wait_for_write_confirmation = 1
};

enum PFP_WRITE_DATA_cache_policy_enum {
  cache_policy__pfp_write_data__lru = 0,
  cache_policy__pfp_write_data__stream = 1
};

enum PFP_WRITE_DATA_engine_sel_enum { engine_sel__pfp_write_data__prefetch_parser = 1 };


typedef struct PM4_PFP_WRITE_DATA {
  union {
    PM4_PFP_TYPE_3_HEADER header;  /// header
    uint32_t ordinal1;
  };

  union {
    struct {
      uint32_t reserved1 : 8;
      PFP_WRITE_DATA_dst_sel_enum dst_sel : 4;
      uint32_t reserved2 : 4;
      PFP_WRITE_DATA_addr_incr_enum addr_incr : 1;
      uint32_t reserved3 : 2;
      uint32_t resume_vf : 1;
      PFP_WRITE_DATA_wr_confirm_enum wr_confirm : 1;
      uint32_t reserved4 : 4;
      PFP_WRITE_DATA_cache_policy_enum cache_policy : 2;
      uint32_t reserved5 : 3;
      PFP_WRITE_DATA_engine_sel_enum engine_sel : 2;
    } bitfields2;
    uint32_t ordinal2;
  };

  union {
    struct {
      uint32_t dst_mmreg_addr : 18;
      uint32_t reserved6 : 14;
    } bitfields3a;
    struct {
      uint32_t reserved7 : 2;
      uint32_t dst_mem_addr_lo : 30;
    } bitfields3b;
    uint32_t ordinal3;
  };

  uint32_t dst_mem_addr_hi;

  //  uint32_t data[];  // N-DWords

} PM4PFP_WRITE_DATA, *PPM4PFP_WRITE_DATA;
#endif

}  // gfx9
}  // pm4_profile

#endif