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
 *  @(#) $Id: task_sync.c 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		��������°Ʊ����ǽ
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"
#include "wait.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_SLP_TSK_ENTER
#define LOG_SLP_TSK_ENTER()
#endif /* LOG_SLP_TSK_ENTER */

#ifndef LOG_SLP_TSK_LEAVE
#define LOG_SLP_TSK_LEAVE(ercd)
#endif /* LOG_SLP_TSK_LEAVE */

#ifndef LOG_TSLP_TSK_ENTER
#define LOG_TSLP_TSK_ENTER(tmout)
#endif /* LOG_TSLP_TSK_ENTER */

#ifndef LOG_TSLP_TSK_LEAVE
#define LOG_TSLP_TSK_LEAVE(ercd)
#endif /* LOG_TSLP_TSK_LEAVE */

#ifndef LOG_WUP_TSK_ENTER
#define LOG_WUP_TSK_ENTER(tskid)
#endif /* LOG_WUP_TSK_ENTER */

#ifndef LOG_WUP_TSK_LEAVE
#define LOG_WUP_TSK_LEAVE(ercd)
#endif /* LOG_WUP_TSK_LEAVE */

#ifndef LOG_IWUP_TSK_ENTER
#define LOG_IWUP_TSK_ENTER(tskid)
#endif /* LOG_IWUP_TSK_ENTER */

#ifndef LOG_IWUP_TSK_LEAVE
#define LOG_IWUP_TSK_LEAVE(ercd)
#endif /* LOG_IWUP_TSK_LEAVE */

#ifndef LOG_CAN_WUP_ENTER
#define LOG_CAN_WUP_ENTER(tskid)
#endif /* LOG_CAN_WUP_ENTER */

#ifndef LOG_CAN_WUP_LEAVE
#define LOG_CAN_WUP_LEAVE(ercd)
#endif /* LOG_CAN_WUP_LEAVE */

#ifndef LOG_REL_WAI_ENTER
#define LOG_REL_WAI_ENTER(tskid)
#endif /* LOG_REL_WAI_ENTER */

#ifndef LOG_REL_WAI_LEAVE
#define LOG_REL_WAI_LEAVE(ercd)
#endif /* LOG_REL_WAI_LEAVE */

#ifndef LOG_IREL_WAI_ENTER
#define LOG_IREL_WAI_ENTER(tskid)
#endif /* LOG_IREL_WAI_ENTER */

#ifndef LOG_IREL_WAI_LEAVE
#define LOG_IREL_WAI_LEAVE(ercd)
#endif /* LOG_IREL_WAI_LEAVE */

#ifndef LOG_SUS_TSK_ENTER
#define LOG_SUS_TSK_ENTER(tskid)
#endif /* LOG_SUS_TSK_ENTER */

#ifndef LOG_SUS_TSK_LEAVE
#define LOG_SUS_TSK_LEAVE(ercd)
#endif /* LOG_SUS_TSK_LEAVE */

#ifndef LOG_RSM_TSK_ENTER
#define LOG_RSM_TSK_ENTER(tskid)
#endif /* LOG_RSM_TSK_ENTER */

#ifndef LOG_RSM_TSK_LEAVE
#define LOG_RSM_TSK_LEAVE(ercd)
#endif /* LOG_RSM_TSK_LEAVE */

#ifndef LOG_DLY_TSK_ENTER
#define LOG_DLY_TSK_ENTER(dlytim)
#endif /* LOG_DLY_TSK_ENTER */

#ifndef LOG_DLY_TSK_LEAVE
#define LOG_DLY_TSK_LEAVE(ercd)
#endif /* LOG_DLY_TSK_LEAVE */

/*
 *  �����Ԥ�
 */
#ifdef TOPPERS_slp_tsk

ER
slp_tsk(void)
{
	WINFO	winfo;
	ER		ercd;

	LOG_SLP_TSK_ENTER();
	CHECK_DISPATCH();

	t_lock_cpu();
	if (p_runtsk->wupque) {
		p_runtsk->wupque = false;
		ercd = E_OK;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_SLP);
		make_wait(&winfo);
		LOG_TSKSTAT(p_runtsk);
		dispatch();
		ercd = winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_SLP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_slp_tsk */

/*
 *  �����Ԥ��ʥ����ॢ���Ȥ����
 */
#ifdef TOPPERS_tslp_tsk

ER
tslp_tsk(TMO tmout)
{
	WINFO	winfo;
	TMEVTB	tmevtb;
	ER		ercd;

	LOG_TSLP_TSK_ENTER(tmout);
	CHECK_DISPATCH();
	CHECK_TMOUT(tmout);

	t_lock_cpu();
	if (p_runtsk->wupque) {
		p_runtsk->wupque = false;
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		p_runtsk->tstat = (TS_WAITING | TS_WAIT_SLP);
		make_wait_tmout(&winfo, &tmevtb, tmout);
		LOG_TSKSTAT(p_runtsk);
		dispatch();
		ercd = winfo.wercd;
	}
	t_unlock_cpu();

  error_exit:
	LOG_TSLP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_tslp_tsk */

/*
 *  �������ε���
 */
#ifdef TOPPERS_wup_tsk

ER
wup_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_WUP_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (TSTAT_WAIT_SLP(p_tcb->tstat)) {
		if (wait_complete(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (!(p_tcb->wupque)) {
		p_tcb->wupque = true;
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	t_unlock_cpu();

  error_exit:
	LOG_WUP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_wup_tsk */

/*
 *  �������ε������󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_iwup_tsk

ER
iwup_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_IWUP_TSK_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (TSTAT_WAIT_SLP(p_tcb->tstat)) {
		if (wait_complete(p_tcb)) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	else if (!(p_tcb->wupque)) {
		p_tcb->wupque = true;
		ercd = E_OK;
	}
	else {
		ercd = E_QOVR;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IWUP_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_iwup_tsk */

/*
 *  �����������׵�Υ���󥻥�
 */
#ifdef TOPPERS_can_wup

ER_UINT
can_wup(ID tskid)
{
	TCB		*p_tcb;
	ER_UINT	ercd;

	LOG_CAN_WUP_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		ercd = p_tcb->wupque ? 1 : 0;
		p_tcb->wupque = false;
	}
	t_unlock_cpu();

  error_exit:
	LOG_CAN_WUP_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_can_wup */

/*
 *  �Ԥ����֤ζ������
 */
#ifdef TOPPERS_rel_wai

ER
rel_wai(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_REL_WAI_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	t_lock_cpu();
	if (!TSTAT_WAITING(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		if (wait_release(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_REL_WAI_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_rel_wai */

/*
 *  �Ԥ����֤ζ���������󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_irel_wai

ER
irel_wai(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_IREL_WAI_ENTER(tskid);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	if (!TSTAT_WAITING(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else {
		if (wait_release(p_tcb)) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IREL_WAI_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_irel_wai */

/*
 *  �����Ԥ����֤ؤΰܹ�
 */
#ifdef TOPPERS_sus_tsk

ER
sus_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_SUS_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (p_tcb == p_runtsk && !dspflg) {
		ercd = E_CTX;
	}
	else if (TSTAT_DORMANT(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (TSTAT_RUNNABLE(p_tcb->tstat)) {
		/*
		 *  �¹ԤǤ�����֤��鶯���Ԥ����֤ؤ�����
		 */
		p_tcb->tstat = TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		if (make_non_runnable(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if (TSTAT_SUSPENDED(p_tcb->tstat)) {
		ercd = E_QOVR;
	}
	else {
		/*
		 *  �Ԥ����֤�������Ԥ����֤ؤ�����
		 */
		p_tcb->tstat |= TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_SUS_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_sus_tsk */

/*
 *  �����Ԥ����֤���κƳ�
 */
#ifdef TOPPERS_rsm_tsk

ER
rsm_tsk(ID tskid)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_RSM_TSK_ENTER(tskid);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID(tskid);
	p_tcb = get_tcb(tskid);

	t_lock_cpu();
	if (!TSTAT_SUSPENDED(p_tcb->tstat)) {
		ercd = E_OBJ;
	}
	else if (!TSTAT_WAITING(p_tcb->tstat)) {
		/*
		 *  �����Ԥ����֤���¹ԤǤ�����֤ؤ�����
		 */
		if (make_runnable(p_tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		/*
		 *  ����Ԥ����֤����Ԥ����֤ؤ�����
		 */
		p_tcb->tstat &= ~TS_SUSPENDED;
		LOG_TSKSTAT(p_tcb);
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_RSM_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_rsm_tsk */

/*
 *  �����������ٱ�
 */
#ifdef TOPPERS_dly_tsk

ER
dly_tsk(RELTIM dlytim)
{
	WINFO	winfo;
	TMEVTB	tmevtb;
	ER		ercd;

	LOG_DLY_TSK_ENTER(dlytim);
	CHECK_DISPATCH();
	CHECK_PAR(dlytim <= TMAX_RELTIM);

	t_lock_cpu();
	p_runtsk->tstat = (TS_WAITING | TS_WAIT_DLY);
	(void) make_non_runnable(p_runtsk);
	p_runtsk->p_winfo = &winfo;
	winfo.p_tmevtb = &tmevtb;
	tmevtb_enqueue(&tmevtb, dlytim, (CBACK) wait_tmout_ok, (void *) p_runtsk);
	LOG_TSKSTAT(p_runtsk);
	dispatch();
	ercd = winfo.wercd;
	t_unlock_cpu();

  error_exit:
	LOG_DLY_TSK_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_dly_tsk */
