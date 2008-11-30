/* This file is generated from target_rename.def by genrename. */

#ifndef TOPPERS_TARGET_RENAME_H
#define TOPPERS_TARGET_RENAME_H

/*
 *  target_config.c
 */
#define board_id					_kernel_board_id
#define board_addr					_kernel_board_addr
#define bitpat_cfgint				_kernel_bitpat_cfgint
#define x_config_int				_kernel_x_config_int

/*
 *  prc_config.c, prc_support.S
 */
#define prc_initialize				_kernel_prc_initialize
#define prc_terminate				_kernel_prc_terminate


#ifdef TOPPERS_LABEL_ASM

/*
 *  target_config.c
 */
#define _board_id					__kernel_board_id
#define _board_addr					__kernel_board_addr
#define _bitpat_cfgint				__kernel_bitpat_cfgint
#define _x_config_int				__kernel_x_config_int

/*
 *  prc_config.c, prc_support.S
 */
#define _prc_initialize				__kernel_prc_initialize
#define _prc_terminate				__kernel_prc_terminate


#endif /* TOPPERS_LABEL_ASM */

#include "m68k_gcc/prc_rename.h"

#endif /* TOPPERS_TARGET_RENAME_H */
