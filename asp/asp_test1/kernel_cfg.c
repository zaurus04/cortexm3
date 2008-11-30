/* kernel_cfg.c */
#include "kernel/kernel_int.h"
#include "kernel_cfg.h"

#ifndef TOPPERS_EMPTY_LABEL
#define TOPPERS_EMPTY_LABEL(x,y) x y[0]
#endif

#if TKERNEL_PRID != 0x07u
#error "The kernel does not match this configuration file."
#endif

/*
 *  Include Directives (#include)
 */

#include "target_timer.h"
#include "syssvc/syslog.h"
#include "syssvc/banner.h"
#include "target_syssvc.h"
#include "target_serial.h"
#include "syssvc/serial.h"
#include "syssvc/logtask.h"
#include "sample1.h"

/*
 *  Default Definitions of Trace Log Macros
 */

#ifndef LOG_ISR_ENTER
#define LOG_ISR_ENTER(intno)
#endif /* LOG_ISR_ENTER */

#ifndef LOG_ISR_LEAVE
#define LOG_ISR_LEAVE(intno)
#endif /* LOG_ISR_LEAVE */

/*
 *  Task Management Functions
 */

const ID _kernel_tmax_tskid = (TMIN_TSKID + TNUM_TSKID - 1);

static STK_T _kernel_stack_LOGTASK[COUNT_STK_T(LOGTASK_STACK_SIZE)];
static STK_T _kernel_stack_TASK_ID1[COUNT_STK_T(STACK_SIZE)];

const TINIB _kernel_tinib_table[TNUM_TSKID] = {
	{ (TA_ACT), (intptr_t)(LOGTASK_PORTID), (logtask_main), INT_PRIORITY(LOGTASK_PRIORITY), ROUND_STK_T(LOGTASK_STACK_SIZE), (_kernel_stack_LOGTASK), (TA_NULL), (NULL) },
	{ (TA_ACT), (intptr_t)(1), (task1), INT_PRIORITY(MID_PRIORITY), ROUND_STK_T(STACK_SIZE), (_kernel_stack_TASK_ID1), (TA_NULL), (NULL) }
};

TCB _kernel_tcb_table[TNUM_TSKID];

const ID _kernel_torder_table[TNUM_TSKID] = {
	LOGTASK, TASK_ID1
};

/*
 *  Semaphore Functions
 */

const ID _kernel_tmax_semid = (TMIN_SEMID + TNUM_SEMID - 1);

const SEMINIB _kernel_seminib_table[TNUM_SEMID] = {
	{ (TA_TPRI), (0), (1) },
	{ (TA_TPRI), (1), (1) }
};

SEMCB _kernel_semcb_table[TNUM_SEMID];

/*
 *  Eventflag Functions
 */

const ID _kernel_tmax_flgid = (TMIN_FLGID + TNUM_FLGID - 1);

TOPPERS_EMPTY_LABEL(const FLGINIB, _kernel_flginib_table);
TOPPERS_EMPTY_LABEL(FLGCB, _kernel_flgcb_table);

/*
 *  Dataqueue Functions
 */

const ID _kernel_tmax_dtqid = (TMIN_DTQID + TNUM_DTQID - 1);

TOPPERS_EMPTY_LABEL(const DTQINIB, _kernel_dtqinib_table);
TOPPERS_EMPTY_LABEL(DTQCB, _kernel_dtqcb_table);

/*
 *  Priority Dataqueue Functions
 */

const ID _kernel_tmax_pdqid = (TMIN_PDQID + TNUM_PDQID - 1);

TOPPERS_EMPTY_LABEL(const PDQINIB, _kernel_pdqinib_table);
TOPPERS_EMPTY_LABEL(PDQCB, _kernel_pdqcb_table);

/*
 *  Mailbox Functions
 */

const ID _kernel_tmax_mbxid = (TMIN_MBXID + TNUM_MBXID - 1);

TOPPERS_EMPTY_LABEL(const MBXINIB, _kernel_mbxinib_table);
TOPPERS_EMPTY_LABEL(MBXCB, _kernel_mbxcb_table);

/*
 *  Fixed-sized Memorypool Functions
 */

const ID _kernel_tmax_mpfid = (TMIN_MPFID + TNUM_MPFID - 1);

TOPPERS_EMPTY_LABEL(const MPFINIB, _kernel_mpfinib_table);
TOPPERS_EMPTY_LABEL(MPFCB, _kernel_mpfcb_table);

/*
 *  Cyclic Handler Functions
 */

const ID _kernel_tmax_cycid = (TMIN_CYCID + TNUM_CYCID - 1);

TOPPERS_EMPTY_LABEL(const CYCINIB, _kernel_cycinib_table);
TOPPERS_EMPTY_LABEL(CYCCB, _kernel_cyccb_table);

/*
 *  Alarm Handler Functions
 */

const ID _kernel_tmax_almid = (TMIN_ALMID + TNUM_ALMID - 1);

TOPPERS_EMPTY_LABEL(const ALMINIB, _kernel_alminib_table);
TOPPERS_EMPTY_LABEL(ALMCB, _kernel_almcb_table);

/*
 *  Interrupt Management Functions
 */

void
_kernel_inthdr_53(void)
{
	i_begin_int(53);
	LOG_ISR_ENTER(53);
	sio_isr((intptr_t)(SIO_PORTID));
	LOG_ISR_LEAVE(53);
	i_end_int(53);
}

#define TNUM_INHNO	2
const uint_t _kernel_tnum_inhno = TNUM_INHNO;

INTHDR_ENTRY(INHNO_TIMER, 15, target_timer_handler)
INTHDR_ENTRY(53, 53, _kernel_inthdr_53)

const INHINIB _kernel_inhinib_table[TNUM_INHNO] = {
	{ (INHNO_TIMER), (TA_NULL), (FP)(INT_ENTRY(INHNO_TIMER, target_timer_handler)) },
	{ (53), (TA_NULL), (FP)(INT_ENTRY(53, _kernel_inthdr_53)) }
};

#define TNUM_INTNO	2
const uint_t _kernel_tnum_intno = TNUM_INTNO;

const INTINIB _kernel_intinib_table[TNUM_INTNO] = {
	{ (INTNO_TIMER), (TA_ENAINT|INTATR_TIMER), (INTPRI_TIMER) },
	{ (INTNO_SIO), (TA_ENAINT|INTATR_SIO), (INTPRI_SIO) }
};

/*
 *  CPU Exception Handler
 */

#define TNUM_EXCNO	0
const uint_t _kernel_tnum_excno = TNUM_EXCNO;


TOPPERS_EMPTY_LABEL(const EXCINIB, _kernel_excinib_table);

/*
 *  Stack Area for Non-task Context
 */

#ifdef DEFAULT_ISTK

#define TOPPERS_ISTKSZ		DEFAULT_ISTKSZ
#define TOPPERS_ISTK		DEFAULT_ISTK

#else /* DEAULT_ISTK */

static STK_T				_kernel_istack[COUNT_STK_T(DEFAULT_ISTKSZ)];
#define TOPPERS_ISTKSZ		ROUND_STK_T(DEFAULT_ISTKSZ)
#define TOPPERS_ISTK		_kernel_istack

#endif /* DEAULT_ISTK */

const SIZE		_kernel_istksz = TOPPERS_ISTKSZ;
STK_T *const	_kernel_istk = TOPPERS_ISTK;

#ifdef TOPPERS_ISTKPT
STK_T *const	_kernel_istkpt = TOPPERS_ISTKPT(TOPPERS_ISTK, TOPPERS_ISTKSZ);
#endif /* TOPPERS_ISTKPT */

/*
 *  Time Event Management
 */

TMEVTN   _kernel_tmevt_heap[TNUM_TSKID + TNUM_CYCID + TNUM_ALMID];

/*
 *  Module Initialization Function
 */

void
_kernel_initialize_object(void)
{
	_kernel_initialize_task();
	_kernel_initialize_semaphore();
	_kernel_initialize_interrupt();
	_kernel_initialize_exception();
}

/*
 *  Initialization Routine
 */

void
_kernel_call_inirtn(void)
{
	(target_timer_initialize)((intptr_t)(0));
	(syslog_initialize)((intptr_t)(0));
	(print_banner)((intptr_t)(0));
	(sio_initialize)((intptr_t)(0));
	(serial_initialize)((intptr_t)(0));
}

/*
 *  Termination Routine
 */

void
_kernel_call_terrtn(void)
{
	(logtask_terminate)((intptr_t)(0));
	(target_timer_terminate)((intptr_t)(0));
}

/*
 *  Target-dependent Definitions (ARM-M)
 */



__attribute__ ((section(".vector"))) 
const FP _kernel_vector_table[] =      
 {                                    
	(FP)(TOPPERS_ISTKPT(TOPPERS_ISTK, TOPPERS_ISTKSZ)),   // 0 The initial stack pointer 
	(FP)_start,                 // 1 The reset handler         
 	(FP)(_kernel_exc_entry), /* 2 */
 	(FP)(_kernel_exc_entry), /* 3 */
 	(FP)(_kernel_exc_entry), /* 4 */
 	(FP)(_kernel_exc_entry), /* 5 */
 	(FP)(_kernel_exc_entry), /* 6 */
 	(FP)(_kernel_exc_entry), /* 7 */
 	(FP)(_kernel_exc_entry), /* 8 */
 	(FP)(_kernel_exc_entry), /* 9 */
 	(FP)(_kernel_exc_entry), /* 10 */
 	(FP)(_kernel_svc_handler),      // 11 SVCall handler /* 11 */
 	(FP)(_kernel_exc_entry), /* 12 */
 	(FP)(_kernel_exc_entry), /* 13 */
 	(FP)(_kernel_exc_entry), /* 14 */
 	(FP)(_kernel_int_entry), /* 15 */
 	(FP)(_kernel_int_entry), /* 16 */
 	(FP)(_kernel_int_entry), /* 17 */
 	(FP)(_kernel_int_entry), /* 18 */
 	(FP)(_kernel_int_entry), /* 19 */
 	(FP)(_kernel_int_entry), /* 20 */
 	(FP)(_kernel_int_entry), /* 21 */
 	(FP)(_kernel_int_entry), /* 22 */
 	(FP)(_kernel_int_entry), /* 23 */
 	(FP)(_kernel_int_entry), /* 24 */
 	(FP)(_kernel_int_entry), /* 25 */
 	(FP)(_kernel_int_entry), /* 26 */
 	(FP)(_kernel_int_entry), /* 27 */
 	(FP)(_kernel_int_entry), /* 28 */
 	(FP)(_kernel_int_entry), /* 29 */
 	(FP)(_kernel_int_entry), /* 30 */
 	(FP)(_kernel_int_entry), /* 31 */
 	(FP)(_kernel_int_entry), /* 32 */
 	(FP)(_kernel_int_entry), /* 33 */
 	(FP)(_kernel_int_entry), /* 34 */
 	(FP)(_kernel_int_entry), /* 35 */
 	(FP)(_kernel_int_entry), /* 36 */
 	(FP)(_kernel_int_entry), /* 37 */
 	(FP)(_kernel_int_entry), /* 38 */
 	(FP)(_kernel_int_entry), /* 39 */
 	(FP)(_kernel_int_entry), /* 40 */
 	(FP)(_kernel_int_entry), /* 41 */
 	(FP)(_kernel_int_entry), /* 42 */
 	(FP)(_kernel_int_entry), /* 43 */
 	(FP)(_kernel_int_entry), /* 44 */
 	(FP)(_kernel_int_entry), /* 45 */
 	(FP)(_kernel_int_entry), /* 46 */
 	(FP)(_kernel_int_entry), /* 47 */
 	(FP)(_kernel_int_entry), /* 48 */
 	(FP)(_kernel_int_entry), /* 49 */
 	(FP)(_kernel_int_entry), /* 50 */
 	(FP)(_kernel_int_entry), /* 51 */
 	(FP)(_kernel_int_entry), /* 52 */
 	(FP)(_kernel_int_entry), /* 53 */
 	(FP)(_kernel_int_entry), /* 54 */
 	(FP)(_kernel_int_entry), /* 55 */
 	(FP)(_kernel_int_entry), /* 56 */
 	(FP)(_kernel_int_entry), /* 57 */
 	(FP)(_kernel_int_entry), /* 58 */

};


const FP _kernel_exc_tbl[] = 
{
	(FP)(_kernel_default_exc_handler), /* 0 */
	(FP)(_kernel_default_exc_handler), /* 1 */
	(FP)(_kernel_default_exc_handler), /* 2 */
	(FP)(_kernel_default_exc_handler), /* 3 */
	(FP)(_kernel_default_exc_handler), /* 4 */
	(FP)(_kernel_default_exc_handler), /* 5 */
	(FP)(_kernel_default_exc_handler), /* 6 */
	(FP)(_kernel_default_exc_handler), /* 7 */
	(FP)(_kernel_default_exc_handler), /* 8 */
	(FP)(_kernel_default_exc_handler), /* 9 */
	(FP)(_kernel_default_exc_handler), /* 10 */
	(FP)(_kernel_default_exc_handler), /* 11 */
	(FP)(_kernel_default_exc_handler), /* 12 */
	(FP)(_kernel_default_exc_handler), /* 13 */
	(FP)(_kernel_default_exc_handler), /* 14 */
	(FP)(target_timer_handler), /* 15 */
	(FP)(_kernel_default_int_handler), /* 16 */
	(FP)(_kernel_default_int_handler), /* 17 */
	(FP)(_kernel_default_int_handler), /* 18 */
	(FP)(_kernel_default_int_handler), /* 19 */
	(FP)(_kernel_default_int_handler), /* 20 */
	(FP)(_kernel_default_int_handler), /* 21 */
	(FP)(_kernel_default_int_handler), /* 22 */
	(FP)(_kernel_default_int_handler), /* 23 */
	(FP)(_kernel_default_int_handler), /* 24 */
	(FP)(_kernel_default_int_handler), /* 25 */
	(FP)(_kernel_default_int_handler), /* 26 */
	(FP)(_kernel_default_int_handler), /* 27 */
	(FP)(_kernel_default_int_handler), /* 28 */
	(FP)(_kernel_default_int_handler), /* 29 */
	(FP)(_kernel_default_int_handler), /* 30 */
	(FP)(_kernel_default_int_handler), /* 31 */
	(FP)(_kernel_default_int_handler), /* 32 */
	(FP)(_kernel_default_int_handler), /* 33 */
	(FP)(_kernel_default_int_handler), /* 34 */
	(FP)(_kernel_default_int_handler), /* 35 */
	(FP)(_kernel_default_int_handler), /* 36 */
	(FP)(_kernel_default_int_handler), /* 37 */
	(FP)(_kernel_default_int_handler), /* 38 */
	(FP)(_kernel_default_int_handler), /* 39 */
	(FP)(_kernel_default_int_handler), /* 40 */
	(FP)(_kernel_default_int_handler), /* 41 */
	(FP)(_kernel_default_int_handler), /* 42 */
	(FP)(_kernel_default_int_handler), /* 43 */
	(FP)(_kernel_default_int_handler), /* 44 */
	(FP)(_kernel_default_int_handler), /* 45 */
	(FP)(_kernel_default_int_handler), /* 46 */
	(FP)(_kernel_default_int_handler), /* 47 */
	(FP)(_kernel_default_int_handler), /* 48 */
	(FP)(_kernel_default_int_handler), /* 49 */
	(FP)(_kernel_default_int_handler), /* 50 */
	(FP)(_kernel_default_int_handler), /* 51 */
	(FP)(_kernel_default_int_handler), /* 52 */
	(FP)(_kernel_inthdr_53), /* 53 */
	(FP)(_kernel_default_int_handler), /* 54 */
	(FP)(_kernel_default_int_handler), /* 55 */
	(FP)(_kernel_default_int_handler), /* 56 */
	(FP)(_kernel_default_int_handler), /* 57 */
	(FP)(_kernel_default_int_handler), /* 58 */

};

const uint32_t _kernel_bitpat_cfgint[4] = {
	UINT32_C(0x00008000), 
	UINT32_C(0x00200000), 
	UINT32_C(0x00000000), 
	UINT32_C(0x00000000), 

};

