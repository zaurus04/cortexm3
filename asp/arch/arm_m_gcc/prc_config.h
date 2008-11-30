/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: prc_config.h 1304 2008-08-27 07:28:36Z ertl-honda $
 */

/*
 *		�ץ��å���¸�⥸�塼���ARM-M�ѡ�
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
 *  �󥿥�������ƥ������ѤΥ����å������
 */
#define TOPPERS_ISTKPT(istk, istksz) ((STK_T *)((istk) + (istksz)))

/*
 *  ����������ƥ����ȥ֥�å������
 */
typedef struct task_context_block {
	void	*sp;		/* �����å��ݥ��� */
	FP		pc;			/* �ץ���५���� */
} CTXB;

#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_MACRO_ONLY
/*
 *  ����ƥ����Ȥλ���
 *
 */
Inline bool_t
sense_context(void)
{
	/*
	 *  PSP��ͭ���ʤ饿��������ƥ����ȡ�MSP��ͭ���ʤ��󥿥�������ƥ�����
	 *  �Ȥ��롥 
	 */
	if ((get_control() & CONTROL_PSP) == CONTROL_PSP){
		return false;
	}
	else {
		return true;
	}
}

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  TOPPERSɸ�����߽�����ǥ�μ¸�
 *
 *  �����ͥ���٥ޥ����Ȥ��Ƥϡ�BASEPRI���Ѥ��롥������ߤ�ػߤ���
 *  ��ǽ�Ȥ��ơ�FAULTMASK��PRIMASK�����뤬�������ͥ�������γ���ߤ�
 *  ���ݡ��Ȥ��뤿�ᡤ������CPU��å��Τ�����Ѥ��ʤ���
 *  ���Τ��ᡤBASEPRI���Ѥ��Ƶ���Ū��CPU��å��ե饰��¸����롥
 *
 *  �ޤ���CPU��å����֤������������ѿ�(lock_flag)���Ѱդ��롥
 *
 *  CPU��å��ե饰�����ꥢ����Ƥ���֤ϡ�BASEPRI���ǥ��γ����
 *  ͥ���٥ޥ������ͤ����ꤹ�롥���δ֤ϡ���ǥ��γ����ͥ���٥ޥ�
 *  ���ϡ�BASEPRI���Ѥ��롥
 * 
 *  ������Ф���CPU��å��ե饰�����åȤ��줤��֤ϡ�BASEPRI�򡤥�����
 *  ��������Τ�Τ�������٤Ƥγ�����׵��ޥ���������(TIPM_LOCK)�ȡ�
 *  ��ǥ��γ����ͥ���٥ޥ����Ȥι⤤�������ꤹ�롥���δ֤Υ�ǥ��
 *  �γ����ͥ���٥ޥ����ϡ����Τ�����ѿ�(saved_iipm, ����ɽ�����ݻ�)
 *  ���Ѱդ����ݻ����롥
 */

/*
 *  �����ͥ���٥ޥ����γ���ɽ��������ɽ�����Ѵ�
 *
 *  ������֥����Υ������ե����뤫�饤�󥯥롼�ɤ�����Τ���ˡ�
 *  CAST�����
 *  �����ͥ���٤Υӥå���(TBITW_IPRI)�� 8 �ξ��ϡ�����ͥ���� 255
 *  �ϡ�����ͥ���� -1 ���б����롥
 */
#define EXT_IPM(iipm)   (CAST(PRI,((iipm >> (8 - TBITW_IPRI)) - (1 << TBITW_IPRI))))       /* ����ɽ������ɽ���� */
#define INT_IPM(ipm)    (((1 << TBITW_IPRI) - CAST(uint8_t, -(ipm)))  << (8 - TBITW_IPRI)) /* ����ɽ��������ɽ���� */

/*
 *  CPU��å����֤Ǥγ����ͥ���٥ޥ���
 */
#define TIPM_LOCK    TMIN_INTPRI

/*
 *  CPU��å����֤Ǥγ����ͥ���٥ޥ���������ɽ��
 *
 *  TIPM_LOCK�ϡ�CPU��å����֤Ǥ�BASEPRI���͡������ͥ�������Τ�Τ�
 *  �������٤Ƥγ���ߤ�ޥ��������ͤ�������롥  
 */
#define IIPM_LOCK    INT_IPM(TIPM_LOCK)

/*
 *  TIPM_ENAALL�ʳ����ͥ���٥ޥ���������ˤ�����ɽ��
 *
 *  BASEPRI�� '0' �����ꤹ�뤳�Ȥǡ�������ߤ���Ĥ��롥
 */
#define IIPM_ENAALL  (0)


#ifndef TOPPERS_MACRO_ONLY

/*
 *  CPU��å��ե饰�¸��Τ�����ѿ�
 * 
 *  �������ѿ��ϡ�CPU��å����֤λ��Τ߽񤭴����Ƥ�褤�Ȥ��롥
 *  ����饤��ؿ���ǡ����������ν�����Ѳ����ʤ��褦��volatile ����ꡥ 
 */
extern volatile bool_t  lock_flag;    /* CPU��å��ե饰���ͤ��ݻ������ѿ� */
extern volatile uint32_t saved_iipm;  /* �����ͥ���٤�ޥ��������ѿ� */

/*
 *  CPU��å����֤ؤΰܹ�
 *
 *  BASEPRI�ʥϡ��ɥ������γ����ͥ���٥ޥ����ˤ�saved_iipm����¸����
 *  �����ͥ�������Τ�Τ�������٤Ƥγ���ߤ�ޥ��������͡�TIPM_LOCK��
 *  �����ꤹ�롥�ޤ���lock_flag��true�ˤ��롥
 *
 *  BASEPRI�����ǽ餫��TIPM_LOCK��Ʊ����������⤤���ˤϡ������
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
	uint32_t iipm;

	/*
	 *  current_iipm()���֤��ͤ�ľ��saved_iipm����¸����������ѿ�iipm
	 *  ���Ѥ��Ƥ���Τϡ�current_iipm()��Ƥ��ľ��˳���ߤ�ȯ������
	 *  ��ư���줿����߽�����saved_iipm���ѹ�������ǽ�������뤿���
	 *  ���롥
	 */
	iipm = get_basepri();
	if ((IIPM_LOCK < iipm) || (IIPM_ENAALL == iipm)) {
		set_basepri(IIPM_LOCK);
	}
	saved_iipm = iipm;
	lock_flag = true;
	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
	Asm("":::"memory");
}

#define t_lock_cpu()    x_lock_cpu()
#define i_lock_cpu()    x_lock_cpu()

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
	/* ����ƥ����륻������������ǥ��꤬�񤭴�����ǽ�������� */
	Asm("":::"memory");
	lock_flag = false;
	set_basepri(saved_iipm);
}

#define t_unlock_cpu()    x_unlock_cpu()
#define i_unlock_cpu()    x_unlock_cpu()

/*
 *  CPU��å����֤λ���
 */
Inline bool_t
x_sense_lock(void)
{
	return(lock_flag);
}

#define t_sense_lock()    x_sense_lock()
#define i_sense_lock()    x_sense_lock()

/*
 *  chg_ipm��ͭ���ʳ����ͥ���٤��ϰϤ�Ƚ��
 *
 *  TMIN_INTPRI���ͤˤ�餺��chg_ipm�Ǥϡ�-(1 << TBITW_IPRI)��TIPM_ENAALL�ʡ�0��
 *  ���ϰϤ�����Ǥ��뤳�ȤȤ���ʥ������å�����γ�ĥ�ˡ�
 *  �����ͥ���٤Υӥå���(TBITW_IPRI)�� 8 �ξ��ϡ�-256 �� 0 �������ǽ�Ǥ��롥
 *   
 */
#define VALID_INTPRI_CHGIPM(intpri) \
				((-((1 << TBITW_IPRI) - 1) <= (intpri) && (intpri) <= TIPM_ENAALL))

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
	uint8_t   iipm = INT_IPM(intpri);

	if (intpri == TIPM_ENAALL){
		iipm = IIPM_ENAALL;
	}

	if (!lock_flag) {
		set_basepri(iipm);
	}
	else {
		saved_iipm = iipm;
		set_basepri(iipm < IIPM_LOCK ? iipm : IIPM_LOCK);
	}
}

#define t_set_ipm(intpri)    x_set_ipm(intpri)
#define i_set_ipm(intpri)    x_set_ipm(intpri)

/*
 * �ʥ�ǥ��Ρ˳����ͥ���٥ޥ����λ���
 *
 *  CPU��å��ե饰�����ꥢ����Ƥ�����ϥϡ��ɥ������γ����ͥ���٥�
 *  �����򡤥��åȤ���Ƥ������saved_iipm�򻲾Ȥ��롥
 */
Inline PRI
x_get_ipm(void)
{
	uint8_t iipm;

	if (!lock_flag) {
		iipm = get_basepri();
	}
	else {
		iipm = saved_iipm;
	}

	if (iipm == IIPM_ENAALL) {
		return(TIPM_ENAALL);
	}
	else {
		return(EXT_IPM(iipm));
	}
}

#define t_get_ipm()    x_get_ipm()
#define i_get_ipm()    x_get_ipm()

/*
 *  SVC�ϥ�ɥ��prc_support.S��
 */
extern void svc_handler(void);

/*
 *  �������ȥ��åץ롼�����start.S��
 */
extern void _start(void);

/*
 *  �ǹ�ͥ���̥������ؤΥǥ����ѥå���prc_support.S��
 *
 *  dispatch�ϡ�����������ƥ����Ȥ���ƤӽФ��줿�����ӥ������������
 *  ��ƤӽФ��٤���Τǡ�����������ƥ����ȡ�CPU��å����֡��ǥ����ѥ�
 *  �����ľ��֡��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤ǸƤӽФ���
 *  ����Фʤ�ʤ���
 */
extern void dispatch(void);

/*
 *  �ǥ����ѥå����ư��ϡ�prc_support.S��
 *
 *  start_dispatch�ϡ������ͥ뵯ư���˸ƤӽФ��٤���Τǡ����٤Ƥγ��
 *  �ߤ�ػߤ������֡ʳ���ߥ�å����֤�Ʊ���ξ��֡ˤǸƤӽФ��ʤ����
 *  �ʤ�ʤ���
 */
extern void start_dispatch(void) NoReturn;

/*
 *  ���ߤΥ���ƥ����Ȥ�ΤƤƥǥ����ѥå���prc_support.S��
 *
 *  exit_and_dispatch�ϡ�ext_tsk����ƤӽФ��٤���Τǡ�����������ƥ�
 *  ���ȡ�CPU��å����֡��ǥ����ѥå����ľ��֡��ʥ�ǥ��Ρ˳����ͥ��
 *  �٥ޥ�����������֤ǸƤӽФ��ʤ���Фʤ�ʤ���
 */
extern void exit_and_dispatch(void) NoReturn;

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
extern void    start_r(void);

#define activate_context(p_tcb)                                         \
{                                                                       \
    (p_tcb)->tskctxb.sp = (void *)((char_t *)((p_tcb)->p_tinib->stk)    \
                                        + (p_tcb)->p_tinib->stksz);     \
    (p_tcb)->tskctxb.pc = (void *) start_r;                             \
}

/*
 *  calltex�ϻ��Ѥ��ʤ�
 */
#define OMIT_CALLTEX

/*
 *  ������ֹ桦����ߥϥ�ɥ��ֹ�
 *
 *  ����ߥϥ�ɥ��ֹ�(inhno)�ȳ�����ֹ�(intno)�ϡ�������ȯ������
 *  EPSR�����ꤵ����㳰�ֹ�Ȥ��롥 
 */

/*
 *  ������ֹ���ϰϤ�Ƚ��
 */
#define VALID_INTNO(intno)           ((TMIN_INTNO <= (intno)) && ((intno) <= TMAX_INTNO))
#define VALID_INTNO_DISINT(intno)    VALID_INTNO(intno)
#define VALID_INTNO_CFGINT(intno)    VALID_INTNO(intno)

/*
 *  ����ߥϥ�ɥ������
 *
 *  �٥��ȥ��ֹ�inhno�γ���ߥϥ�ɥ�ε�ư����int_entry�����ꤹ�롥�����
 *  �ϥ�ɥ�ơ��֥�
 */
Inline void
x_define_inh(INHNO inhno, FP int_entry)
{

}

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 */
#define INT_ENTRY(inhno, inthdr)    inthdr
#define INTHDR_ENTRY(inhno, inhno_num, inthdr) extern void inthdr(void);

/*
 *  ������׵�ػߥե饰
 */

/*
 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ���kernel_cfg.c��
 */
extern const uint32_t	bitpat_cfgint[];

/*
 *  ������׵�ػߥե饰�Υ��å�
 *
 *  �����°�������ꤵ��Ƥ��ʤ�������׵�饤����Ф��Ƴ�����׵�ػ�
 *  �ե饰�򥯥ꥢ���褦�Ȥ������ˤϡ�false���֤���  
 */
Inline bool_t
x_disable_int(INTNO intno)
{
	uint32_t tmp;

	/*
	 *  �����°�������ꤵ��Ƥ��ʤ����
	 */
	if ((bitpat_cfgint[intno >> 5] & (1 << (intno & 0x1f))) == 0x00) {
		return(false);
	}

	if (intno == IRQNO_SYSTICK) {
		tmp = sil_rew_mem((void *)SYSTIC_CONTROL_STATUS);
		tmp &= ~SYSTIC_TICINT;
		sil_wrw_mem((void *)SYSTIC_CONTROL_STATUS, tmp);
	}else {
		tmp = intno - 16;
		sil_wrw_mem((void *)NVIC_CLRENA0 + (tmp >> 5), (1 << (tmp & 0x1f)));
	}

	return(true);
}

#define t_disable_int(intno) x_disable_int(intno)
#define i_disable_int(intno) x_disable_int(intno)

/*
 *  ������׵�ػߥե饰�β��
 *
 *  �����°�������ꤵ��Ƥ��ʤ�������׵�饤����Ф��Ƴ�����׵�ػ�
 *  �ե饰�򥯥ꥢ���褦�Ȥ������ˤϡ�false���֤���
 */
Inline bool_t
x_enable_int(INTNO intno)
{
	uint32_t tmp;

	/*
	 *  �����°�������ꤵ��Ƥ��ʤ����
	 */
	if ((bitpat_cfgint[intno >> 5] & (1 << (intno & 0x1f))) == 0x00) {
		return(false);
	}

	if (intno == IRQNO_SYSTICK) {
		tmp = sil_rew_mem((void *)SYSTIC_CONTROL_STATUS);
		tmp |= SYSTIC_TICINT;
		sil_wrw_mem((void *)SYSTIC_CONTROL_STATUS, tmp);
	}else {
		tmp = intno - 16;
		sil_wrw_mem((void *)((uint32_t *)NVIC_SETENA0 + (tmp >> 5)),
					(1 << (tmp & 0x1f)));
	}
    
	return(true);
}

#define t_enable_int(intno) x_enable_int(intno)
#define i_enable_int(intno) x_enable_int(intno)

/*
 *  ������׵�饤���°��������
 */
extern void x_config_int(INTNO intno, ATR intatr, PRI intpri);

/*
 *  ����ߥϥ�ɥ�������ɬ�פ�IRC���
 */
Inline void
i_begin_int(INTNO intno)
{
}

/*
 *  ����ߥϥ�ɥ�νи���ɬ�פ�IRC���
 */
Inline void
i_end_int(INTNO intno)
{
}

/*
 *  CPU�㳰�ϥ�ɥ�ط�
 */ 

/*
 *  CPU�㳰�ϥ�ɥ��ֹ�
 */
#define VALID_EXCNO_DEFEXC(excno)    (TMIN_EXCNO <= (excno) && (excno) <= TMAX_EXCNO)

/*
 *  CPU�㳰�ϥ�ɥ�ε���
 */
extern void enable_exc(EXCNO excno);

/*
 *  CPU�㳰�ϥ�ɥ�ζػ�
 */
extern void disable_exc(EXCNO excno);

/*
 *  CPU�㳰�ϥ�ɥ������
 */
Inline void
x_define_exc(EXCNO excno, FP exc_entry)
{
	/*
	 *  �������㳰�ϵ��Ĥ�Ԥ�ɬ�פ�����
	 */
	enable_exc(excno);
}

/*
 *  CPU�㳰�ϥ�ɥ�����������������ޥ���
 */
#define EXC_ENTRY(excno, exchdr)    exchdr
#define EXCHDR_ENTRY(excno, excno_num, exchdr) extern void exchdr(void *p_excinf);

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥλ���
 *
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥ�������������ƥ����Ȥλ���false��
 *  �����Ǥʤ�����true���֤���
 */
Inline bool_t
exc_sense_context(void *p_excinf)
{
	uint32_t exc_return;

	exc_return = *((uint32_t *)p_excinf + P_EXCINF_OFFSET_EXC_RETURN);
	if ((exc_return & EXC_RETURN_PSP) == EXC_RETURN_PSP){
		return false;
	}
	else {
		return true;
	}
}

/*
 *  CPU�㳰��ȯ����������IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ���������ɽ
 *  ���ˤλ���
 */
Inline uint32_t
exc_get_iipm(void *p_excinf)
{
	return(*((uint32_t *)p_excinf + P_EXCINF_OFFSET_BASEPRI));
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
 *  PU�㳰��ȯ����������BASEPRI�ʥϡ��ɥ������γ����ͥ���٥ޥ�����
 *  �����٤Ƥγ���ߤ���Ĥ�����֤Ǥ��뤳�Ȥ�����å����뤳�Ȥǡ�����
 *  �ͥ�¹���Ǥʤ����ȡ�����ߥ�å����֤Ǥʤ����ȡ�CPU��å����֤Ǥ�
 *  �����ȡ��ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����������֤Ǥ��뤳�Ȥ�4�Ĥ�
 *  ��������å����뤳�Ȥ��Ǥ����CPU�㳰��ȯ����������lock_flag��
 *  �Ȥ���ɬ�פϤʤ��ˡ�
 */
Inline bool_t
exc_sense_intmask(void *p_excinf)
{
	return(!exc_sense_context(p_excinf)
		   && (exc_get_iipm(p_excinf) == IIPM_ENAALL));
}

/*
 *  CPU�㳰��ȯ���������Υ���ƥ����Ȥȳ���ߡ�CPU��å����֤λ���
 *
 *  CPU�㳰��ȯ���������Υ����ƥ���֤��������ͥ�¹���Ǥʤ�����������
 *  ��ƥ����ȤǤ��ꡤ����ߥ�å����֤Ǥʤ���CPU��å����֤Ǥʤ�����
 *  true�������Ǥʤ�����false���֤���CPU�㳰�������ͥ�������γ���߽�
 *  �����ȯ���������ˤ�false���֤��ˡ�
 *
 *  CPU�㳰��ȯ����������BASEPRI�ʥϡ��ɥ������γ����ͥ���٥�
 *  �����ˤ�TIPM_LOCK����㤤���Ȥ�����å����뤳�Ȥǡ������ͥ�¹����
 *  �ʤ����ȡ�����ߥ�å����֤Ǥʤ����ȡ�CPU��å����֤Ǥʤ����Ȥ�3��
 *  �ξ�������å����Ƥ����CPU�㳰��ȯ����������lock_flag�ϻ��Ȥ���
 *  ���ʤ��ˡ�����ˤ�ꡤ�ʥ�ǥ��Ρ˳����ͥ���٥ޥ�����TIPM_LOCK��
 *  ������ꤷ�ƥ�������¹Ԥ��Ƥ�����ˤ�false���֤äƤ��ޤ�����Ƚ�Ǥ�
 *  ���Τˤ��뤿��Υ����Хإåɤ��礭�����Ȥ��顤���Ƥ��뤳�Ȥˤ��롥
 */
Inline bool_t
exc_sense_unlock(void *p_excinf)
{
	return(!exc_sense_context(p_excinf)
		   && ((exc_get_iipm(p_excinf) > IIPM_LOCK)
			   || exc_get_iipm(p_excinf) == IIPM_ENAALL));
}

/*
 *  CPU�㳰����ȥ��prc_support.S��
 */
extern void exc_entry(void);

/*
 *  ����ߥ���ȥ��prc_support.S��
 */
extern void int_entry(void);

/*
 *  �ץ��å���¸�ν����
 */
extern void prc_initialize(void);

/*
 *  �ץ��å���¸�ν�λ������
 */
extern void prc_terminate(void);

/*
 *  atexit�ν����ȥǥ��ȥ饯���μ¹�
 */
Inline void
call_atexit(void)
{
	extern void    software_term_hook(void);
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

/*
 * ��Ͽ����Ƥ��ʤ��㳰��ȯ������ȸƤӽФ����
 */
extern void default_exc_handler(void *p_excinf);

/*
 * ̤��Ͽ�γ���ߤ�ȯ���������˸ƤӽФ����
 */
extern void default_int_handler(void *p_excinf);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_PRC_CONFIG_H */
