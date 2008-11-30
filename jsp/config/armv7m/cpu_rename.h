/* This file is generated from cpu_rename.def by genrename. */

#ifndef _CPU_RENAME_H_
#define _CPU_RENAME_H_

#define activate_r			_kernel_activate_r
#define ret_int				_kernel_ret_int
#define ret_exc				_kernel_ret_exc
#define task_intmask		_kernel_task_intmask
#define int_intmask			_kernel_int_intmask
#define master_stack		_kernel_master_stack
#define exception_vector	_kernel_exception_vector
#define vector_table		_kernel_vector_table

#ifdef LABEL_ASM

#define _activate_r			__kernel_activate_r
#define _ret_int			__kernel_ret_int
#define _ret_exc			__kernel_ret_exc
#define _task_intmask		__kernel_task_intmask
#define _int_intmask		__kernel_int_intmask
#define _master_stack		__kernel_master_stack
#define _exception_vector	__kernel_exception_vector
#define _vector_table		__kernel_vector_table

#endif /* LABEL_ASM */
#endif /* _CPU_RENAME_H_ */
