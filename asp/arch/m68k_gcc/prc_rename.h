/* This file is generated from prc_rename.def by genrename. */

#ifndef TOPPERS_PRC_RENAME_H
#define TOPPERS_PRC_RENAME_H

#define start_r						_kernel_start_r
#define ret_int						_kernel_ret_int
#define ret_exc						_kernel_ret_exc
#define lock_flag					_kernel_lock_flag
#define saved_iipm					_kernel_saved_iipm

#ifdef TOPPERS_LABEL_ASM

#define _start_r					__kernel_start_r
#define _ret_int					__kernel_ret_int
#define _ret_exc					__kernel_ret_exc
#define _lock_flag					__kernel_lock_flag
#define _saved_iipm					__kernel_saved_iipm

#endif /* TOPPERS_LABEL_ASM */


#endif /* TOPPERS_PRC_RENAME_H */
