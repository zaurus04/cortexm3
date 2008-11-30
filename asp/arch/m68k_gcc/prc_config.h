/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2008 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: prc_config.h 1138 2008-06-19 07:02:20Z ertl-hiro $
 */

/*
 *		�ץ��å���¸�⥸�塼���M68040�ѡ�
 *
 *  ���Υ��󥯥롼�ɥե�����ϡ�target_config.h�ʤޤ��ϡ��������饤��
 *  �롼�ɤ����ե�����ˤΤߤ��饤�󥯥롼�ɤ���롥¾�Υե����뤫��
 *  ľ�ܥ��󥯥롼�ɤ��ƤϤʤ�ʤ���
 */

#ifndef TOPPERS_PRC_CONFIG_H
#define TOPPERS_PRC_CONFIG_H

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ץ��å����ü�̿��Υ���饤��ؿ����
 */
#include "prc_insn.h"

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	void	*msp;		/* �����å��ݥ��� */
	FP		pc;			/* �ץ���५���� */
} CTXB;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  �����ͥ���٥ޥ������饤�֥��
 *
 *  M68040�Ǥϡ����ơ������쥸������SR�ˤβ�����8��10�ӥåȤ��3�ӥå�
 *  �˳����ͥ���٥ޥ����ʥϡ��ɥ������γ����ͥ���٥ޥ�����IPM�ˤ��֤�
 *  ��Ƥ��롥IPM����¸���Ƥ�������ˡ������ͥ���٤γ���ɽ����-1����Ϣ
 *  ³��������͡ˤ�Ȥ����Ȥ��ǽ�Ǥ��뤬��;�פʺ����ӥåȥ��եȤ���
 *  ��ȿž��ɬ�פˤʤ롥������򤱤뤿��ˡ�IPM����¸������ˤϡ�SR��
 *  8��10�ӥåȤ����Ф����ͤ�Ȥ����Ȥˤ��롥�����ͤ�����ͥ���٥�
 *  ����������ɽ���ȸƤӡ�IIPM�Ƚ񤯤��Ȥˤ��롥
 */

/*
 *  �����ͥ���٥ޥ����γ���ɽ��������ɽ�����Ѵ�
 */
#define EXT_IPM(iipm)	(-CAST(PRI, (iipm) >> 8))		/* ����ɽ�����Ѵ� */
#define INT_IPM(ipm)	(CAST(uint16_t, -(ipm)) << 8)	/* ����ɽ�����Ѵ� */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ���������ɽ���ˤθ����ͤ��ɽФ�
 */
Inline uint16_t
current_iipm(void)
{
	return(current_sr() & 0x0700U);
}

/*
 *  IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ���������ɽ���ˤθ����ͤ�����
 */
Inline void
set_iipm(uint16_t iipm)
{
	set_sr((current_sr() & ~0x0700U) | iipm);
}

/*
 *  TOPPERSɸ�����߽�����ǥ�μ¸�
 *
 *  M68040�ϡ����ơ������쥸������SR����˳����ͥ���٥ޥ����ʥϡ��ɥ���
 *  ���γ����ͥ���٥ޥ�����IPM�ˤ���äƤ��뤬��CPU��å��ե饰������
 *  ���뵡ǽ������ʤ������Τ��ᡤCPU��å��ե饰�ε�ǽ��IPM�ˤ�ä�
 *  �¸����롥
 *
 *  �ޤ�CPU��å��ե饰���͡ʤ��ʤ����CPU��å����֤�CPU��å��������
 *  ���ˤϡ����Τ�����ѿ���lock_flag�ˤ��Ѱդ����ݻ����롥
 *
 *  CPU��å��ե饰�����ꥢ����Ƥ���֡ʤ��ʤ����CPU��å�������֤�
 *  �֡ˤϡ�IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ����ˤ򡤥�ǥ��γ����
 *  ͥ���٥ޥ������ͤ����ꤹ�롥���δ֤ϡ���ǥ��γ����ͥ���٥ޥ���
 *  �ϡ�IPM���Ѥ����ݻ����롥
 *
 *  ������Ф���CPU��å��ե饰�����åȤ���Ƥ���֡ʤ��ʤ����CPU���
 *  �����֤δ֡ˤϡ�IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ����ˤ򡤥����ͥ�
 *  �����γ���ߤ򤹤٤ƥޥ��������͡�TIPM_LOCK�ˤȡ���ǥ��γ����ͥ
 *  ���٥ޥ����Ȥι⤤�������ꤹ�롥���δ֤Υ�ǥ��γ����ͥ���٥ޥ�
 *  ���ϡ����Τ�����ѿ���saved_iipm������ɽ�����ݻ��ˤ��Ѱդ����ݻ���
 *  �롥
 */

/*
 *  ����ƥ����Ȥλ���
 *
 *  M68040�Ǥϡ�����������ƥ����Ȥ�ޥ����⡼�ɤǡ��󥿥�������ƥ���
 *  �Ȥ����ߥ⡼�ɤǼ¹Ԥ��롥�ޥ����⡼�ɤ�����ߥ⡼�ɤ��ϡ����ơ�
 *  �����쥸������SR����γ���ߥ⡼�ɥӥåȤˤ��Ƚ�̤Ǥ��롥
 */
Inline bool_t
sense_context(void)
{
	return((current_sr() & 0x1000U) == 0U);
}

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  CPU��å����֤Ǥγ����ͥ���٥ޥ���
 *
 *  TIPM_LOCK�ϡ������ͥ�����γ���ߤ򤹤٤ƥޥ��������ͤ�������롥��
 *  ��Ū�ˤϡ�TMIN_INTPRI��-6�λ���TIPM_LOCK��-7�ˡ������Ǥʤ����ˤ�
 *  TIPM_LOCK��TMIN_INTPRI�˰��פ����롥
 */
#if TMIN_INTPRI == -6		/* NMI�ʳ��˥����ͥ�������γ���ߤ��ߤ��ʤ� */
#define TIPM_LOCK		(-7)
#else /* TMIN_INTPRI == -6 */
#if (-1 >= TMIN_INTPRI) && (TMIN_INTPRI > -6)
#define TIPM_LOCK		TMIN_INTPRI
#else /* (-1 >= TMIN_INTPRI) && (TMIN_INTPRI > -6) */
#error TMIN_INTPRI out of range.
#endif /* (-1 >= TMIN_INTPRI) && (TMIN_INTPRI > -6) */
#endif /* TMIN_INTPRI == -6 */

/*
 *  CPU��å����֤Ǥγ����ͥ���٥ޥ���������ɽ��
 */
#define IIPM_LOCK		INT_IPM(TIPM_LOCK)

/*
 *  TIPM_ENAALL�ʳ����ͥ���٥ޥ���������ˤ�����ɽ��
 */
#define IIPM_ENAALL		INT_IPM(TIPM_ENAALL)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  CPU��å��ե饰�¸��Τ�����ѿ�
 *
 *  �������ѿ��ϡ�CPU��å����֤λ��Τ߽񤭴����Ƥ褤��ΤȤ��롥
 */
extern volatile bool_t		lock_flag;	/* CPU��å��ե饰���ͤ��ݻ������ѿ� */
extern volatile uint16_t	saved_iipm;	/* �����ͥ���٥ޥ�������¸�����ѿ� */

/*
 *  CPU��å����֤ؤΰܹ�
 *
 *  IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ����ˤ�saved_iipm����¸��������
 *  �ͥ�����γ���ߤ򤹤٤ƥޥ��������͡�TIPM_LOCK�ˤ����ꤹ�롥�ޤ���
 *  lock_flag��true�ˤ��롥
 *
 *  IPM�����ǽ餫��TIPM_LOCK��Ʊ����������⤤���ˤϡ������
 *  saved_iipm����¸����Τߤǡ�TIPM_LOCK�ˤ����ꤷ�ʤ�������ϡ���ǥ�
 *  ��γ����ͥ���٥ޥ�������TIPM_LOCK��Ʊ����������⤤��٥������
 *  ����Ƥ�����֤ˤ����롥
 *
 *  ���δؿ��ϡ�CPU��å����֡�lock_flag��true�ξ��֡ˤǸƤФ�뤳�Ȥ�
 *  �ʤ���Τ����ꤷ�Ƥ��롥
 */
Inline void
x_lock_cpu(void)
{
	uint16_t	iipm;

	/*
	 *  current_iipm()���֤��ͤ�ľ��saved_iipm����¸����������ѿ�iipm
	 *  ���Ѥ��Ƥ���Τϡ�current_iipm()��Ƥ��ľ��˳���ߤ�ȯ������
	 *  ��ư���줿����߽�����saved_iipm���ѹ�������ǽ�������뤿���
	 *  ���롥
	 */
	iipm = current_iipm();
#if TIPM_LOCK == -7
	disint();
#else /* TIPM_LOCK == -7 */
	if (IIPM_LOCK > iipm) {
		set_iipm(IIPM_LOCK);
	}
#endif /* TIPM_LOCK == -7 */
	saved_iipm = iipm;
	lock_flag = true;
	Asm("":::"memory");
}

#define t_lock_cpu()	x_lock_cpu()
#define i_lock_cpu()	x_lock_cpu()

/*
 *  CPU��å����֤β��
 *
 *  lock_flag��false�ˤ���IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ����ˤ�
 *  saved_iipm����¸�����ͤ��᤹��
 *
 *  ���δؿ��ϡ�CPU��å����֡�lock_flag��true�ξ��֡ˤǤΤ߸ƤФ���
 *  �Τ����ꤷ�Ƥ��롥
 */
Inline void
x_unlock_cpu(void)
{
	Asm("":::"memory");
	lock_flag = false;
	set_iipm(saved_iipm);
}

#define t_unlock_cpu()	x_unlock_cpu()
#define i_unlock_cpu()	x_unlock_cpu()

/*
 *  CPU��å����֤λ���
 */
Inline bool_t
x_sense_lock(void)
{
	return(lock_flag);
}

#define t_sense_lock()	x_sense_lock()
#define i_sense_lock()	x_sense_lock()

/*
 *  chg_ipm��ͭ���ʳ����ͥ���٤��ϰϤ�Ƚ��
 *
 *  TMIN_INTPRI���ͤˤ�餺��chg_ipm�Ǥϡ�-6��TIPM_ENAALL�ʡ�0�ˤ��ϰ�
 *  ������Ǥ��뤳�ȤȤ���ʥ������å�����γ�ĥ�ˡ�
 */
#define VALID_INTPRI_CHGIPM(intpri) \
				(-6 <= (intpri) && (intpri) <= TIPM_ENAALL)

/*
 * �ʥ�ǥ��Ρ˳����ͥ���٥ޥ���������
 *
 *  CPU��å��ե饰�����ꥢ����Ƥ�����ϡ��ϡ��ɥ������γ����ͥ���٥�
 *  ���������ꤹ�롥CPU��å��ե饰�����åȤ���Ƥ�����ϡ�saved_iipm
 *  �����ꤷ������ˡ��ϡ��ɥ������γ����ͥ���٥ޥ��������ꤷ�褦��
 *  �����ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����TIPM_LOCK�ι⤤�������ꤹ�롥
 */
Inline void
x_set_ipm(PRI intpri)
{
	uint16_t	iipm = INT_IPM(intpri);

	if (!lock_flag) {
		set_iipm(iipm);
	}
	else {
		saved_iipm = iipm;
#if TIPM_LOCK == -7
		/*
		 *  TIPM_LOCK��-7�ξ��ˤϡ����λ����ǥϡ��ɥ������γ����ͥ��
		 *  �٥ޥ�����ɬ��7�����ꤵ��Ƥ��뤿�ᡤ���ꤷ�ʤ���ɬ�פ��ʤ���
		 */
#else /* TIPM_LOCK == -7 */
		set_iipm(iipm > IIPM_LOCK ? iipm : IIPM_LOCK);
#endif /* TIPM_LOCK == -7 */
	}
}

#define t_set_ipm(intpri)	x_set_ipm(intpri)
#define i_set_ipm(intpri)	x_set_ipm(intpri)

/*
 * �ʥ�ǥ��Ρ˳����ͥ���٥ޥ����λ���
 *
 *  CPU��å��ե饰�����ꥢ����Ƥ�����ϥϡ��ɥ������γ����ͥ���٥�
 *  �����򡤥��åȤ���Ƥ������saved_iipm�򻲾Ȥ��롥
 */
Inline PRI
x_get_ipm(void)
{
	uint16_t	iipm;

	if (!lock_flag) {
		iipm = current_iipm();
	}
	else {
		iipm = saved_iipm;
	}
	return(EXT_IPM(iipm));
}

#define t_get_ipm()		x_get_ipm()
#define i_get_ipm()		x_get_ipm()

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���prc_support.S��
 *
 *  dispatch�ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ������������
 *  ��ƤӽФ��٤���Τǡ�����������ƥ����ȡ�CPU��å����֡��ǥ����ѥ�
 *  �����ľ��֡��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤ǸƤӽФ���
 *  ����Фʤ�ʤ���
 */
extern void	dispatch(void);

/*
 *  �ǥ����ѥå����ư��ϡ�prc_support.S��
 *
 *  start_dispatch�ϡ������ͥ뵯ư���˸ƤӽФ��٤���Τǡ����٤Ƥγ��
 *  �ߤ�ػߤ������֡ʳ���ߥ�å����֤�Ʊ���ξ��֡ˤǸƤӽФ��ʤ����
 *  �ʤ�ʤ���
 */
extern void	start_dispatch(void) NoReturn;

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���prc_support.S��
 *
 *  exit_and_dispatch�ϡ�ext_tsk����ƤӽФ��٤���Τǡ�����������ƥ�
 *  ���ȡ�CPU��å����֡��ǥ����ѥå����ľ��֡��ʥ�ǥ��Ρ˳����ͥ��
 *  �٥ޥ�����������֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void	exit_and_dispatch(void) NoReturn;

/*
 *  �����ͥ�ν�λ�����θƽФ���prc_support.S��
 *
 *  call_exit_kernel�ϡ������ͥ�ν�λ���˸ƤӽФ��٤���Τǡ��󥿥���
 *  ����ƥ����Ȥ��ڤ괹���ơ������ͥ�ν�λ������exit_kernel�ˤ�Ƥӽ�
 *  ����
 */
extern void call_exit_kernel(void) NoReturn;

/*
 *  ����������ƥ����Ȥν����
 *
 *  ���������ٻ߾��֤���¹ԤǤ�����֤˰ܹԤ�����˸ƤФ�롥���λ���
 *  �ǥ����å��ΰ��ȤäƤϤʤ�ʤ���
 *
 *  activate_context�򡤥���饤��ؿ��ǤϤʤ��ޥ�������Ȥ��Ƥ���Τϡ�
 *  ���λ����Ǥ�TCB���������Ƥ��ʤ�����Ǥ��롥
 */
extern void	start_r(void);

#define activate_context(p_tcb)											\
{																		\
	(p_tcb)->tskctxb.msp = (void *)((char *)((p_tcb)->p_tinib->stk)		\
										+ (p_tcb)->p_tinib->stksz);		\
	(p_tcb)->tskctxb.pc = (void *) start_r;								\
}

/*
 *  calltex�ϻ��Ѥ��ʤ�
 */
#define OMIT_CALLTEX

/*
 *  �㳰�٥����ơ��֥�ι�¤�����
 */
typedef struct exc_vector_entry {
	FP		exc_handler;		/* �㳰�ϥ�ɥ�ε�ư���� */
} EXCVE;

/*
 *  ����ߥϥ�ɥ��ֹ��CPU�㳰�ϥ�ɥ��ֹ���ϰϤ�Ƚ��
 */
#define VALID_INHNO_DEFINH(inhno)	((0x10U <= (inhno) && (inhno) <= 0x1fU) \
									|| (0x40U <= (inhno) && (inhno) <= 0xffU))
#define VALID_EXCNO_DEFEXC(excno)	((0x02U <= (excno) && (excno) <= 0x0fU) \
									|| (0x20U <= (excno) && (excno) <= 0x3fU))

/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ�inhno�γ���ߥϥ�ɥ�ν��������������Ϥ�int_entry����
 *  �ꤹ�롥
 */
Inline void
x_define_inh(INHNO inhno, FP int_entry)
{
	EXCVE	*excvt;

	assert(VALID_INHNO_DEFINH(inhno));

#ifdef EXCVT_KERNEL
	/*
	 *  EXCVT_KERNEL���������Ƥ�����ϡ���������������VBR��
	 *  EXCVT_KERNEL�����ꤹ��Τǡ�EXCVT_KERNEL��Ȥ���
	 */
	excvt = (EXCVE *) EXCVT_KERNEL;
#else /* EXCVT_KERNEL */
	excvt = (EXCVE *) current_vbr();
#endif /* EXCVT_KERNEL */
	excvt[inhno].exc_handler = int_entry;
}

/*
 *  CPU�㳰�ϥ�ɥ������
 *
 *  �٥��ȥ��ֹ�excno��CPU�㳰�ϥ�ɥ�ν��������������Ϥ�exc_entry����
 *  �ꤹ�롥
 */
Inline void
x_define_exc(EXCNO excno, FP exc_entry)
{
	EXCVE	*excvt;

	assert(VALID_EXCNO_DEFEXC(excno));

#ifdef EXCVT_KERNEL
	/*
	 *  EXCVT_KERNEL���������Ƥ�����ϡ���������������VBR��
	 *  EXCVT_KERNEL�����ꤹ��Τǡ�EXCVT_KERNEL��Ȥ���
	 */
	excvt = (EXCVE *) EXCVT_KERNEL;
#else /* EXCVT_KERNEL */
	excvt = (EXCVE *) current_vbr();
#endif /* EXCVT_KERNEL */
	excvt[excno].exc_handler = exc_entry;
}

/*
 *  ����ߥϥ�ɥ�ν���������������
 */

/*
 *  ����ߥϥ�ɥ�ν����������Υ�٥����ޥ���
 */
#define INT_ENTRY(inhno, inthdr)	_kernel_##inthdr##_##inhno

/*
 *  LOG_INH_ENTER���ޥ����������Ƥ�����ˡ�CALL_LOG_INH_ENTER��
 *  inhno_num��ѥ�᡼���Ȥ���log_inh_enter��ƤӽФ�������֥���쥳��
 *  �ɤ˥ޥ���������롥
 */
#ifdef LOG_INH_ENTER

#define CALL_LOG_INH_ENTER(inhno_num) \
"	move.l #" #inhno_num ", -(%sp)	\n"  /* inhno_num��ѥ�᡼���� */ \
"	jsr _kernel_log_inh_enter		\n"  /* log_inh_enter��ƤӽФ� */ \
"	addq.l #4, %sp					\n"

#else /* LOG_INH_ENTER */
#define CALL_LOG_INH_ENTER(inhno_num)
#endif /* LOG_INH_ENTER */

#ifdef LOG_INH_LEAVE

/*
 *  CALL_LOG_INH_LEAVE��inhno_num��ѥ�᡼���Ȥ���log_inh_leave���
 *  �ӽФ�������֥���쥳���ɤ˥ޥ���������롥
 */
#define CALL_LOG_INH_LEAVE(inhno_num) \
"	move.l #" #inhno_num ", -(%sp)	\n"  /* inhno_num��ѥ�᡼���� */ \
"	jsr _kernel_log_inh_leave		\n"  /* log_inh_leave��ƤӽФ� */ \
"	addq.l #4, %sp					\n"

/*
 *  LOG_INH_LEAVE���ޥ����������Ƥ�����γ���ߥϥ�ɥ�ν�����������
 *  ����ߥϥ�ɥ�򥵥֥롼���󥳡��뤷����äƤ����顤�ȥ졼������
 *  �����塤ret_int��ʬ�����롥
 */
#define INTHDR_ENTRY(inhno, inhno_num, inthdr) \
extern void _kernel_##inthdr##_##inhno(void); \
asm(".text							\n" \
"_kernel_" #inthdr "_" #inhno ":	\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n"  /* ������å��쥸��������¸ */ \
	CALL_LOG_INH_ENTER(inhno_num) \
"	jsr " #inthdr "					\n"  /* ����ߥϥ�ɥ��ƤӽФ� */ \
	CALL_LOG_INH_LEAVE(inhno_num) \
"	jmp _kernel_ret_int				\n");/* ret_int��ʬ�� */

#else /* LOG_INH_LEAVE */

/*
 *  LOG_INH_LEAVE���ޥ����������Ƥ��ʤ����γ���ߥϥ�ɥ�ν�������
 *  ����������ϤȤ���ret_int�򥹥��å����Ѥ���塤����ߥϥ�ɥ�ε�ư
 *  ���Ϥ�ʬ�����롥����ߥϥ�ɥ餫��Υ꥿����ˤ�ꡤret_int��ʬ����
 *  �롥
 */
#define INTHDR_ENTRY(inhno, inhno_num, inthdr) \
extern void _kernel_##inthdr##_##inhno(void); \
asm(".text							\n" \
"_kernel_" #inthdr "_" #inhno ":	\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n"  /* ������å��쥸��������¸ */ \
	CALL_LOG_INH_ENTER(inhno_num) \
"	move.l #_kernel_ret_int, -(%sp)	\n"  /* ������Ϥ򥹥��å����Ѥ� */ \
"	jmp " #inthdr "					\n");/* ����ߥϥ�ɥ��ʬ�� */

#endif /* LOG_INH_LEAVE */

/*
 *  CPU�㳰�ϥ�ɥ�ν���������������
 *
 *  CPU�㳰�ϥ�ɥ�ϡ��󥿥�������ƥ����ȤǼ¹Ԥ��롥���Τ��ᡤCPU��
 *  ���ϥ�ɥ��ƤӽФ����˳���ߥ⡼�ɤ˰ܹԤ����꥿���󤷤Ƥ������
 *  ���Υ⡼�ɤ��᤹�����Υ⡼�ɤ��᤹����ˡ�����ߥ⡼�ɤ˰ܹԤ�����
 *  ��SR�����ߥ����å������¸����ʥ꥿�������SR�򻲾Ȥ����⤢��
 *  ���������������å������¸������礬���ꡤ���Ȥ���Τ����ݡˡ�
 */

/*
 *  CPU�㳰�ϥ�ɥ�ν����������Υ�٥����ޥ���
 */
#define EXC_ENTRY(excno, exchdr)	_kernel_##exchdr##_##excno

/*
 *  LOG_EXC_ENTER���ޥ����������Ƥ�����ˡ�CALL_LOG_EXC_ENTER��
 *  excno_num��ѥ�᡼���Ȥ���log_exc_enter��ƤӽФ�������֥���쥳��
 *  �ɤ˥ޥ���������롥
 */
#ifdef LOG_EXC_ENTER

#define CALL_LOG_EXC_ENTER(excno_num) \
"	move.l #" #excno_num ", -(%sp)	\n"  /* excno_num��ѥ�᡼���� */ \
"	jsr _kernel_log_exc_enter		\n"  /* log_exc_enter��ƤӽФ� */ \
"	addq.l #4, %sp					\n"

#else /* LOG_EXC_ENTER */
#define CALL_LOG_EXC_ENTER(excno_num)
#endif /* LOG_EXC_ENTER */

#ifdef LOG_EXC_LEAVE

/*
 *  CALL_LOG_EXC_LEAVE��excno_num��ѥ�᡼���Ȥ���log_exc_leave���
 *  �ӽФ�������֥���쥳���ɤ˥ޥ���������롥
 */
#define CALL_LOG_EXC_LEAVE(excno_num) \
"	move.l #" #excno_num ", -(%sp)	\n"  /* excno_num��ѥ�᡼���� */ \
"	jsr _kernel_log_exc_leave		\n"  /* log_exc_leave��ƤӽФ� */ \
"	addq.l #4, %sp					\n"

/*
 *  LOG_EXC_LEAVE���ޥ����������Ƥ������CPU�㳰�ϥ�ɥ�ν�������
 *  ����CPU�㳰�ϥ�ɥ�򥵥֥롼���󥳡��뤷����äƤ����顤�ȥ졼����
 *  ���μ����塤ret_exc��ʬ�����롥
 */
#define EXCHDR_ENTRY(excno, excno_num, exchdr) \
extern void _kernel_##exchdr##_##excno(void *sp); \
asm(".text							\n" \
"_kernel_" #exchdr "_" #excno ":	\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n"  /* ������å��쥸��������¸ */ \
"	lea.l 16(%sp), %a0				\n"  /* �㳰�ե졼�����Ƭ��A0�� */ \
"	move.w %sr, %d0					\n"  /* SR��D0�� */ \
"	and.w #~0x1000, %sr				\n"  /* ����ߥ⡼�ɡʥ����å��ڴ�����*/ \
"	move.l %d0, -(%sp)				\n"  /* ����SR�򥹥��å�����¸ */ \
"	move.l _kernel_lock_flag, %d0	\n"  /* ����lock_flag�򥹥��å�����¸ */ \
"	move.l %d0, -(%sp)				\n" \
"	move.l %a0, -(%sp)				\n"  /* A0��ѥ�᡼���Ȥ����Ϥ� */ \
	CALL_LOG_EXC_ENTER(excno_num) \
"	jsr " #exchdr "					\n"  /* CPU�㳰�ϥ�ɥ��ʬ�� */ \
	CALL_LOG_EXC_LEAVE(excno_num) \
"	jmp _kernel_ret_exc				\n");/* ������Ϥ򥹥��å����Ѥ� */

#else /* LOG_EXC_LEAVE */

/*
 *  LOG_EXC_LEAVE���ޥ����������Ƥ��ʤ�����CPU�㳰�ϥ�ɥ�ν�����
 *  ������������ϤȤ���ret_exc�򥹥��å����Ѥ���塤CPU�㳰�ϥ�ɥ��
 *  ��ư���Ϥ�ʬ�����롥CPU�㳰�ϥ�ɥ餫��Υ꥿����ˤ�ꡤret_exc��
 *  ʬ�����롥
 */
#define EXCHDR_ENTRY(excno, excno_num, exchdr) \
extern void _kernel_##exchdr##_##excno(void *sp); \
asm(".text							\n" \
"_kernel_" #exchdr "_" #excno ":	\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n"  /* ������å��쥸��������¸ */ \
"	lea.l 16(%sp), %a0				\n"  /* �㳰�ե졼�����Ƭ��A0�� */ \
"	move.w %sr, %d0					\n"  /* SR��D0�� */ \
"	and.w #~0x1000, %sr				\n"  /* ����ߥ⡼�ɡʥ����å��ڴ�����*/ \
"	move.l %d0, -(%sp)				\n"  /* ����SR�򥹥��å�����¸ */ \
"	move.l _kernel_lock_flag, %d0	\n"  /* ����lock_flag�򥹥��å�����¸ */ \
"	move.l %d0, -(%sp)				\n" \
"	move.l %a0, -(%sp)				\n"  /* A0��ѥ�᡼���Ȥ����Ϥ� */ \
	CALL_LOG_EXC_ENTER(excno_num) \
"	move.l #_kernel_ret_exc, -(%sp)	\n"  /* ������Ϥ򥹥��å����Ѥ� */ \
"	jmp " #exchdr "					\n");/* CPU�㳰�ϥ�ɥ��ʬ�� */

#endif /* LOG_EXC_LEAVE */

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥλ���
 *
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥ�������������ƥ����Ȥλ���false��
 *  �����Ǥʤ�����true���֤���
 */
Inline bool_t
exc_sense_context(void *p_excinf)
{
	return((*((uint16_t *) p_excinf) & 0x1000U) == 0U);
}

/*
 *  CPU�㳰��ȯ����������IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ���������ɽ
 *  ���ˤλ���
 */
Inline uint16_t
exc_get_iipm(void *p_excinf)
{
	return(*((uint16_t *) p_excinf) & 0x0700U);
}

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥȳ���ߤΥޥ������֤λ���
 *
 *  CPU�㳰��ȯ���������Υ����ƥ���֤��������ͥ�¹���Ǥʤ�����������
 *  ��ƥ����ȤǤ��ꡤ����ߥ�å����֤Ǥʤ���CPU��å����֤Ǥʤ����ʥ�
 *  �ǥ��Ρ˳����ͥ���٥ޥ�����������֤Ǥ������true�������Ǥʤ���
 *  ��false���֤���CPU�㳰�������ͥ�������γ���߽������ȯ���������
 *  �ˤ�false���֤��ˡ�
 *
 *  M68040�Ǥϡ�CPU�㳰��ȯ����������IPM�ʥϡ��ɥ������γ����ͥ���٥�
 *  �����ˤ����٤Ƥγ���ߤ���Ĥ�����֤Ǥ��뤳�Ȥ�����å����뤳�Ȥǡ�
 *  �����ͥ�¹���Ǥʤ����ȡ�����ߥ�å����֤Ǥʤ����ȡ�CPU��å�����
 *  �Ǥʤ����ȡ��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤Ǥ��뤳�Ȥ�
 *  4�Ĥξ�������å����뤳�Ȥ��Ǥ����CPU�㳰��ȯ����������
 *  lock_flag�򻲾Ȥ���ɬ�פϤʤ��ˡ�
 */
Inline bool_t
exc_sense_intmask(void *p_excinf)
{
	return(!exc_sense_context(p_excinf)
					&& exc_get_iipm(p_excinf) == IIPM_ENAALL);
}

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥȳ���ߡ�CPU��å����֤λ���
 *
 *  CPU�㳰��ȯ���������Υ����ƥ���֤��������ͥ�¹���Ǥʤ�����������
 *  ��ƥ����ȤǤ��ꡤ����ߥ�å����֤Ǥʤ���CPU��å����֤Ǥʤ�����
 *  true�������Ǥʤ�����false���֤���CPU�㳰�������ͥ�������γ���߽�
 *  �����ȯ���������ˤ�false���֤��ˡ�
 *
 *  M68040�Ǥϡ�CPU�㳰��ȯ����������IPM�ʥϡ��ɥ������γ����ͥ���٥�
 *  �����ˤ�TIPM_LOCK����㤤���Ȥ�����å����뤳�Ȥǡ������ͥ�¹����
 *  �ʤ����ȡ�����ߥ�å����֤Ǥʤ����ȡ�CPU��å����֤Ǥʤ����Ȥ�3��
 *  �ξ�������å����Ƥ����CPU�㳰��ȯ����������lock_flag�ϻ��Ȥ���
 *  ���ʤ��ˡ�����ˤ�ꡤ�ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����TIPM_LOCK��
 *  ���Ϥ�����⤤�ͤ����ꤷ�ƥ�������¹Ԥ��Ƥ�����ˤ�false ���֤�
 *  �Ƥ��ޤ�����Ƚ�Ǥ����Τˤ��뤿��Υ����Хإåɤ��礭�����Ȥ��顤��
 *  �Ƥ��뤳�Ȥˤ��롥
 */
Inline bool_t
exc_sense_unlock(void *p_excinf)
{
	return(!exc_sense_context(p_excinf)
					&& exc_get_iipm(p_excinf) < IIPM_LOCK);
}

/*
 *  �ץ��å���¸�ν����
 */
extern void	prc_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void	prc_terminate(void);

/*
 *  atexit�ν����ȥǥ��ȥ饯���μ¹�
 */
Inline void
call_atexit(void)
{
	extern void	software_term_hook(void);
	void (*volatile fp)(void) = software_term_hook;

	/*
	 *  software_term_hook�ؤΥݥ��󥿤򡤰�övolatile����Τ���fp����
	 *  �����Ƥ���Ȥ��Τϡ�0�Ȥ���Ӥ���Ŭ���Ǻ������ʤ��褦�ˤ��뤿
	 *  ��Ǥ��롥
	 */
	if (fp != 0) {
		(*fp)();
	}
}

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_PRC_CONFIG_H */
