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
 *  @(#) $Id: cyclic.c 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�����ϥ�ɥ鵡ǽ
 */

#include "kernel_impl.h"
#include "check.h"
#include "cyclic.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_CYC_ENTER
#define LOG_CYC_ENTER(p_cyccb)
#endif /* LOG_CYC_ENTER */

#ifndef LOG_CYC_LEAVE
#define LOG_CYC_LEAVE(p_cyccb)
#endif /* LOG_CYC_LEAVE */

#ifndef LOG_STA_CYC_ENTER
#define LOG_STA_CYC_ENTER(cycid)
#endif /* LOG_STA_CYC_ENTER */

#ifndef LOG_STA_CYC_LEAVE
#define LOG_STA_CYC_LEAVE(ercd)
#endif /* LOG_STA_CYC_LEAVE */

#ifndef LOG_STP_CYC_ENTER
#define LOG_STP_CYC_ENTER(cycid)
#endif /* LOG_STP_CYC_ENTER */

#ifndef LOG_STP_CYC_LEAVE
#define LOG_STP_CYC_LEAVE(ercd)
#endif /* LOG_STP_CYC_LEAVE */

#ifndef LOG_REF_CYC_ENTER
#define LOG_REF_CYC_ENTER(cycid, pk_rcyc)
#endif /* LOG_REF_CYC_ENTER */

#ifndef LOG_REF_CYC_LEAVE
#define LOG_REF_CYC_LEAVE(ercd, pk_rcyc)
#endif /* LOG_REF_CYC_LEAVE */

/*
 *  �����ϥ�ɥ�ο�
 */
#define tnum_cyc	((uint_t)(tmax_cycid - TMIN_CYCID + 1))

/*
 *  �����ϥ�ɥ�ID��������ϥ�ɥ�����֥�å�����Ф�����Υޥ���
 */
#define INDEX_CYC(cycid)	((uint_t)((cycid) - TMIN_CYCID))
#define get_cyccb(cycid)	(&(cyccb_table[INDEX_CYC(cycid)]))

/*
 *  �����ϥ�ɥ鵯ư�Τ���Υ����।�٥�ȥ֥�å�����Ͽ
 */
Inline void
tmevtb_enqueue_cyc(CYCCB *p_cyccb, EVTTIM evttim)
{
	tmevtb_enqueue_evttim(&(p_cyccb->tmevtb), evttim,
								(CBACK) call_cychdr, (void *) p_cyccb);
	p_cyccb->evttim = evttim;
}

/*
 *  �����ϥ�ɥ鵡ǽ�ν����
 */
#ifdef TOPPERS_cycini

void
initialize_cyclic(void)
{
	uint_t	i;
	CYCCB	*p_cyccb;

	for (p_cyccb = cyccb_table, i = 0; i < tnum_cyc; p_cyccb++, i++) {
		p_cyccb->p_cycinib = &(cycinib_table[i]);
		if ((p_cyccb->p_cycinib->cycatr & TA_STA) != 0U) {
			p_cyccb->cycsta = true;
			tmevtb_enqueue_cyc(p_cyccb, (EVTTIM)(p_cyccb->p_cycinib->cycphs));
		}
		else {
			p_cyccb->cycsta = false;
		}
	}
}

#endif /* TOPPERS_cycini */

/*
 *  �����ϥ�ɥ��ư���
 */
#ifdef TOPPERS_sta_cyc

ER
sta_cyc(ID cycid)
{
	CYCCB	*p_cyccb;
	ER		ercd;

	LOG_STA_CYC_ENTER(cycid);
	CHECK_TSKCTX_UNL();
	CHECK_CYCID(cycid);
	p_cyccb = get_cyccb(cycid);

	t_lock_cpu();
	if (p_cyccb->cycsta) {
		tmevtb_dequeue(&(p_cyccb->tmevtb));
	}
	else {
		p_cyccb->cycsta = true;
	}
	tmevtb_enqueue_cyc(p_cyccb, base_time + p_cyccb->p_cycinib->cyctim);
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STA_CYC_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_sta_cyc */

/*
 *  �����ϥ�ɥ��ư�����
 */
#ifdef TOPPERS_stp_cyc

ER
stp_cyc(ID cycid)
{
	CYCCB	*p_cyccb;
	ER		ercd;

	LOG_STP_CYC_ENTER(cycid);
	CHECK_TSKCTX_UNL();
	CHECK_CYCID(cycid);
	p_cyccb = get_cyccb(cycid);

	t_lock_cpu();
	if (p_cyccb->cycsta) {
		p_cyccb->cycsta = false;
		tmevtb_dequeue(&(p_cyccb->tmevtb));
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_STP_CYC_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_stp_cyc */

/*
 *  �����ϥ�ɥ�ξ��ֻ���
 */
#ifdef TOPPERS_ref_cyc

ER
ref_cyc(ID cycid, T_RCYC *pk_rcyc)
{
	CYCCB	*p_cyccb;
	ER		ercd;
    
	LOG_REF_CYC_ENTER(cycid, pk_rcyc);
	CHECK_TSKCTX_UNL();
	CHECK_CYCID(cycid);
	p_cyccb = get_cyccb(cycid);

	t_lock_cpu();
	if (p_cyccb->cycsta) {
		pk_rcyc->cycstat = TCYC_STA;
		pk_rcyc->lefttim = tmevt_lefttim(&(p_cyccb->tmevtb));
	}
	else {
		pk_rcyc->cycstat = TCYC_STP;
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_REF_CYC_LEAVE(ercd, pk_rcyc);
	return(ercd);
}

#endif /* TOPPERS_ref_cyc */

/*
 *  �����ϥ�ɥ鵯ư�롼����
 */
#ifdef TOPPERS_cyccal

void
call_cychdr(CYCCB *p_cyccb)
{
	PRI		saved_ipm;

	/*
	 *  ����ε�ư�Τ���Υ����।�٥�ȥ֥�å�����Ͽ���롥
	 *
	 *  Ʊ��������ƥ��å��Ǽ����ϥ�ɥ����ٵ�ư���٤����ˤϡ�����
	 *  �ؿ�����signal_time����ä���ˡ����٤��δؿ����ƤФ�뤳�Ȥˤ�
	 *  �롥
	 */
	tmevtb_enqueue_cyc(p_cyccb, p_cyccb->evttim + p_cyccb->p_cycinib->cyctim);

	/*
	 *  �����ϥ�ɥ��CPU��å�������֤ǸƤӽФ���
	 */
	saved_ipm = i_get_ipm();
	i_unlock_cpu();

	LOG_CYC_ENTER(p_cyccb);
	(*((CYCHDR)(p_cyccb->p_cycinib->cychdr)))(p_cyccb->p_cycinib->exinf);
	LOG_CYC_LEAVE(p_cyccb);

	if (!i_sense_lock()) {
		i_lock_cpu();
	}
	i_set_ipm(saved_ipm);
}

#endif /* TOPPERS_cyccal */
