/* cfg1_out.c */
#define TOPPERS_CFG1_OUT  1
#include "kernel/kernel_int.h"
#include "target_timer.h"
#include "syssvc/syslog.h"
#include "syssvc/banner.h"
#include "target_syssvc.h"
#include "target_serial.h"
#include "syssvc/serial.h"
#include "syssvc/logtask.h"
#include "sample1.h"


#ifdef INT64_MAX
  typedef int64_t signed_t;
  typedef uint64_t unsigned_t;
#else
  typedef int32_t signed_t;
  typedef uint32_t unsigned_t;
#endif

#include <target_cfg1_out.h>

const uint32_t TOPPERS_cfg_magic_number = 0x12345678;
const uint32_t TOPPERS_cfg_sizeof_signed_t = sizeof(signed_t);
const unsigned_t TOPPERS_cfg_CHAR_BIT = CHAR_BIT;
const unsigned_t TOPPERS_cfg_CHAR_MAX = CHAR_MAX;
const unsigned_t TOPPERS_cfg_CHAR_MIN = CHAR_MIN;
const unsigned_t TOPPERS_cfg_SCHAR_MAX = SCHAR_MAX;
const unsigned_t TOPPERS_cfg_SHRT_MAX = SHRT_MAX;
const unsigned_t TOPPERS_cfg_INT_MAX = INT_MAX;
const unsigned_t TOPPERS_cfg_LONG_MAX = LONG_MAX;

const unsigned_t TOPPERS_cfg_TA_NULL = TA_NULL;
const unsigned_t TOPPERS_cfg_TA_ACT = TA_ACT;
const unsigned_t TOPPERS_cfg_TA_TPRI = TA_TPRI;
const unsigned_t TOPPERS_cfg_TA_MPRI = TA_MPRI;
const unsigned_t TOPPERS_cfg_TA_WMUL = TA_WMUL;
const unsigned_t TOPPERS_cfg_TA_CLR = TA_CLR;
const unsigned_t TOPPERS_cfg_TA_STA = TA_STA;
const unsigned_t TOPPERS_cfg_TA_NONKERNEL = TA_NONKERNEL;
const unsigned_t TOPPERS_cfg_TA_ENAINT = TA_ENAINT;
const unsigned_t TOPPERS_cfg_TA_EDGE = TA_EDGE;
const signed_t TOPPERS_cfg_TMIN_TPRI = TMIN_TPRI;
const signed_t TOPPERS_cfg_TMAX_TPRI = TMAX_TPRI;
const signed_t TOPPERS_cfg_TMIN_DPRI = TMIN_DPRI;
const signed_t TOPPERS_cfg_TMAX_DPRI = TMAX_DPRI;
const signed_t TOPPERS_cfg_TMIN_MPRI = TMIN_MPRI;
const signed_t TOPPERS_cfg_TMAX_MPRI = TMAX_MPRI;
const signed_t TOPPERS_cfg_TMIN_ISRPRI = TMIN_ISRPRI;
const signed_t TOPPERS_cfg_TMAX_ISRPRI = TMAX_ISRPRI;
const unsigned_t TOPPERS_cfg_TMAX_MAXSEM = TMAX_MAXSEM;
const unsigned_t TOPPERS_cfg_TMAX_RELTIM = TMAX_RELTIM;
const signed_t TOPPERS_cfg_TMIN_INTPRI = TMIN_INTPRI;
const unsigned_t TOPPERS_cfg_sizeof_ID = sizeof(ID);
const unsigned_t TOPPERS_cfg_sizeof_uint_t = sizeof(uint_t);
const unsigned_t TOPPERS_cfg_sizeof_SIZE = sizeof(SIZE);
const unsigned_t TOPPERS_cfg_sizeof_ATR = sizeof(ATR);
const unsigned_t TOPPERS_cfg_sizeof_PRI = sizeof(PRI);
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_VP = sizeof(void*);
const unsigned_t TOPPERS_cfg_sizeof_intptr_t = sizeof(intptr_t);
const unsigned_t TOPPERS_cfg_sizeof_FP = sizeof(FP);
const unsigned_t TOPPERS_cfg_sizeof_TINIB = sizeof(TINIB);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_tskatr = offsetof(TINIB,tskatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exinf = offsetof(TINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = offsetof(TINIB,task);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_ipriority = offsetof(TINIB,ipriority);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stksz = offsetof(TINIB,stksz);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = offsetof(TINIB,stk);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texatr = offsetof(TINIB,texatr);
const unsigned_t TOPPERS_cfg_offsetof_TINIB_texrtn = offsetof(TINIB,texrtn);
const unsigned_t TOPPERS_cfg_sizeof_SEMINIB = sizeof(SEMINIB);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_sematr = offsetof(SEMINIB,sematr);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_isemcnt = offsetof(SEMINIB,isemcnt);
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_maxsem = offsetof(SEMINIB,maxsem);
const unsigned_t TOPPERS_cfg_sizeof_FLGPTN = sizeof(FLGPTN);
const unsigned_t TOPPERS_cfg_sizeof_FLGINIB = sizeof(FLGINIB);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_flgatr = offsetof(FLGINIB,flgatr);
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_iflgptn = offsetof(FLGINIB,iflgptn);
const unsigned_t TOPPERS_cfg_sizeof_DTQINIB = sizeof(DTQINIB);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqatr = offsetof(DTQINIB,dtqatr);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqcnt = offsetof(DTQINIB,dtqcnt);
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_p_dtqmb = offsetof(DTQINIB,p_dtqmb);
const unsigned_t TOPPERS_cfg_sizeof_MBXINIB = sizeof(MBXINIB);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_mbxatr = offsetof(MBXINIB,mbxatr);
const unsigned_t TOPPERS_cfg_offsetof_MBXINIB_maxmpri = offsetof(MBXINIB,maxmpri);
const unsigned_t TOPPERS_cfg_sizeof_PDQINIB = sizeof(PDQINIB);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqatr = offsetof(PDQINIB,pdqatr);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqcnt = offsetof(PDQINIB,pdqcnt);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_maxdpri = offsetof(PDQINIB,maxdpri);
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_p_pdqmb = offsetof(PDQINIB,p_pdqmb);
const unsigned_t TOPPERS_cfg_sizeof_MPFINIB = sizeof(MPFINIB);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpfatr = offsetof(MPFINIB,mpfatr);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blkcnt = offsetof(MPFINIB,blkcnt);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blksz = offsetof(MPFINIB,blksz);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpf = offsetof(MPFINIB,mpf);
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_p_mpfmb = offsetof(MPFINIB,p_mpfmb);
const unsigned_t TOPPERS_cfg_sizeof_CYCINIB = sizeof(CYCINIB);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycatr = offsetof(CYCINIB,cycatr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_exinf = offsetof(CYCINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cychdr = offsetof(CYCINIB,cychdr);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cyctim = offsetof(CYCINIB,cyctim);
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycphs = offsetof(CYCINIB,cycphs);
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = sizeof(ALMINIB);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almatr = offsetof(ALMINIB,almatr);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_exinf = offsetof(ALMINIB,exinf);
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almhdr = offsetof(ALMINIB,almhdr);
const unsigned_t TOPPERS_cfg_sizeof_INHNO = sizeof(INHNO);
const unsigned_t TOPPERS_cfg_sizeof_INTNO = sizeof(INTNO);
const unsigned_t TOPPERS_cfg_sizeof_EXCNO = sizeof(EXCNO);
const unsigned_t TOPPERS_cfg_TMAX_INTNO = TMAX_INTNO;
const unsigned_t TOPPERS_cfg_TIPM_LOCK = TIPM_LOCK ;
const unsigned_t TOPPERS_cfg_TBITW_IPRI = TBITW_IPRI;
/* #include "target_timer.h" */

#line 8 "../arch/arm_m_gcc/prc_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_0 = 0;
const unsigned_t TOPPERS_cfg_valueof_iniatr_0 = ( TA_NULL ); 
#line 9 "../arch/arm_m_gcc/prc_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_1 = 1;
const unsigned_t TOPPERS_cfg_valueof_teratr_1 = ( TA_NULL ); 
#line 10 "../arch/arm_m_gcc/prc_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_2 = 2;
const unsigned_t TOPPERS_cfg_valueof_inhno_2 = ( INHNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_inhatr_2 = ( TA_NULL ); 
#line 11 "../arch/arm_m_gcc/prc_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_3 = 3;
const unsigned_t TOPPERS_cfg_valueof_intno_3 = ( INTNO_TIMER ); const unsigned_t TOPPERS_cfg_valueof_intatr_3 = ( TA_ENAINT|INTATR_TIMER ); const signed_t TOPPERS_cfg_valueof_intpri_3 = ( INTPRI_TIMER ); /* #include "syssvc/syslog.h" */

#line 10 "../syssvc/syslog.cfg"
const unsigned_t TOPPERS_cfg_static_api_4 = 4;
const unsigned_t TOPPERS_cfg_valueof_iniatr_4 = ( TA_NULL ); /* #include "syssvc/banner.h" */

#line 10 "../syssvc/banner.cfg"
const unsigned_t TOPPERS_cfg_static_api_5 = 5;
const unsigned_t TOPPERS_cfg_valueof_iniatr_5 = ( TA_NULL ); /* #include "target_syssvc.h" */
/* #include "target_serial.h" */

#line 6 "../target/cq_starm_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_6 = 6;
const unsigned_t TOPPERS_cfg_valueof_iniatr_6 = ( TA_NULL ); 
#line 7 "../target/cq_starm_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_7 = 7;
const unsigned_t TOPPERS_cfg_valueof_isratr_7 = ( TA_NULL ); const unsigned_t TOPPERS_cfg_valueof_intno_7 = ( INTNO_SIO ); const signed_t TOPPERS_cfg_valueof_isrpri_7 = ( 1 ); 
#line 8 "../target/cq_starm_gcc/target_serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_8 = 8;
const unsigned_t TOPPERS_cfg_valueof_intno_8 = ( INTNO_SIO ); const unsigned_t TOPPERS_cfg_valueof_intatr_8 = ( TA_ENAINT|INTATR_SIO ); const signed_t TOPPERS_cfg_valueof_intpri_8 = ( INTPRI_SIO ); /* #include "syssvc/serial.h" */

#line 13 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_9 = 9;
const unsigned_t TOPPERS_cfg_valueof_iniatr_9 = ( TA_NULL ); 
#line 15 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_10 = 10;
#define SERIAL_RCV_SEM1	(<>)

#line 15 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_10 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_10 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_10 = ( 1 ); 
#line 16 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_11 = 11;
#define SERIAL_SND_SEM1	(<>)

#line 16 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_11 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_11 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_11 = ( 1 ); 
#if TNUM_PORT >= 2

#line 18 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_12 = 12;
#define SERIAL_RCV_SEM2	(<>)

#line 18 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_12 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_12 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_12 = ( 1 ); 
#line 19 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_13 = 13;
#define SERIAL_SND_SEM2	(<>)

#line 19 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_13 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_13 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_13 = ( 1 ); 
#endif 

#if TNUM_PORT >= 3

#line 22 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_14 = 14;
#define SERIAL_RCV_SEM3	(<>)

#line 22 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_14 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_14 = ( 0 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_14 = ( 1 ); 
#line 23 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_static_api_15 = 15;
#define SERIAL_SND_SEM3	(<>)

#line 23 "../syssvc/serial.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_15 = ( TA_TPRI ); const unsigned_t TOPPERS_cfg_valueof_isemcnt_15 = ( 1 ); const unsigned_t TOPPERS_cfg_valueof_maxsem_15 = ( 1 ); 
#endif 
/* #include "syssvc/logtask.h" */

#line 10 "../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_static_api_16 = 16;
#define LOGTASK	(<>)

#line 10 "../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_16 = ( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_16 = ( LOGTASK_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_16 = ( LOGTASK_STACK_SIZE ); 
#line 12 "../syssvc/logtask.cfg"
const unsigned_t TOPPERS_cfg_static_api_17 = 17;
const unsigned_t TOPPERS_cfg_valueof_teratr_17 = ( TA_NULL ); /* #include "sample1.h" */

#line 11 "sample1.cfg"
const unsigned_t TOPPERS_cfg_static_api_18 = 18;
#define TASK_ID1	(<>)

#line 11 "sample1.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_18 = ( TA_ACT ); const signed_t TOPPERS_cfg_valueof_itskpri_18 = ( MID_PRIORITY ); const unsigned_t TOPPERS_cfg_valueof_stksz_18 = ( STACK_SIZE ); 
