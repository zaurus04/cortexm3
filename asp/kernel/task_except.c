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
 *  @(#) $Id: task_except.c 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�������㳰������ǽ
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_RAS_TEX_ENTER
#define LOG_RAS_TEX_ENTER(tskid, rasptn)
#endif /* LOG_RAS_TEX_ENTER */

#ifndef LOG_RAS_TEX_LEAVE
#define LOG_RAS_TEX_LEAVE(ercd)
#endif /* LOG_RAS_TEX_LEAVE */

#ifndef LOG_IRAS_TEX_ENTER
#define LOG_IRAS_TEX_ENTER(tskid, rasptn)
#endif /* LOG_IRAS_TEX_ENTER */

#ifndef LOG_IRAS_TEX_LEAVE
#define LOG_IRAS_TEX_LEAVE(ercd)
#endif /* LOG_IRAS_TEX_LEAVE */

#ifndef LOG_DIS_TEX_ENTER
#define LOG_DIS_TEX_ENTER()
#endif /* LOG_DIS_TEX_ENTER */

#ifndef LOG_DIS_TEX_LEAVE
#define LOG_DIS_TEX_LEAVE(ercd)
#endif /* LOG_DIS_TEX_LEAVE */

#ifndef LOG_ENA_TEX_ENTER
#define LOG_ENA_TEX_ENTER()
#endif /* LOG_ENA_TEX_ENTER */

#ifndef LOG_ENA_TEX_LEAVE
#define LOG_ENA_TEX_LEAVE(ercd)
#endif /* LOG_ENA_TEX_LEAVE */

#ifndef LOG_SNS_TEX_ENTER
#define LOG_SNS_TEX_ENTER()
#endif /* LOG_SNS_TEX_ENTER */

#ifndef LOG_SNS_TEX_LEAVE
#define LOG_SNS_TEX_LEAVE(state)
#endif /* LOG_SNS_TEX_LEAVE */

#ifndef LOG_REF_TEX_ENTER
#define LOG_REF_TEX_ENTER(tskid, pk_rtex)
#endif /* LOG_REF_TEX_ENTER */

#ifndef LOG_REF_TEX_LEAVE
#define LOG_REF_TEX_LEAVE(ercd, pk_rtex)
#endif /* LOG_REF_TEX_LEAVE */

/*
 *  �������㳰�������׵�
 */
#ifdef TOPPERS_ras_tex

ER
ras_tex(ID tskid, TEXPTN rasptn)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_RAS_TEX_ENTER(tskid, rasptn);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	CHECK_PAR(rasptn != 0U);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat) || p_tcb->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		p_tcb->texptn |= rasptn;
		if (p_tcb == p_runtsk && p_runtsk->enatex) {
			call_texrtn();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_RAS_TEX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ras_tex */

/*
 *  �������㳰�������׵���󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_iras_tex

ER
iras_tex(ID tskid, TEXPTN rasptn)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_IRAS_TEX_ENTER(tskid, rasptn);
	CHECK_INTCTX_UNL();
	CHECK_TSKID(tskid);
	CHECK_PAR(rasptn != 0U);
	p_tcb = get_tcb(tskid);

	i_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat) || p_tcb->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		p_tcb->texptn |= rasptn;
		if (p_tcb == p_runtsk && p_runtsk->enatex) {
			reqflg = true;
		}
		ercd = E_OK;
	}
	i_unlock_cpu();

  error_exit:
	LOG_IRAS_TEX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_iras_tex */

/*
 *  �������㳰�����ζػ�
 */
#ifdef TOPPERS_dis_tex

ER
dis_tex(void)
{
	ER		ercd;

	LOG_DIS_TEX_ENTER();
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	if (p_runtsk->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		p_runtsk->enatex = false;
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_DIS_TEX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_dis_tex */

/*
 *  �������㳰�����ε���
 */
#ifdef TOPPERS_ena_tex

ER
ena_tex(void)
{
	ER		ercd;

	LOG_ENA_TEX_ENTER();
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	if (p_runtsk->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		p_runtsk->enatex = true;
		if (p_runtsk->texptn != 0U) {
			call_texrtn();
		}
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_ENA_TEX_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ena_tex */

/*
 *  �������㳰�����ػ߾��֤λ���
 */
#ifdef TOPPERS_sns_tex

bool_t
sns_tex(void)
{
	bool_t	state;

	LOG_SNS_TEX_ENTER();
	state = (p_runtsk != NULL && p_runtsk->enatex) ? false : true;
	LOG_SNS_TEX_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_sns_tex */

/*
 *  �������㳰�����ξ��ֻ���
 */
#ifdef TOPPERS_ref_tex

ER
ref_tex(ID tskid, T_RTEX *pk_rtex)
{
	TCB		*p_tcb;
	ER		ercd;

	LOG_REF_TEX_ENTER(tskid, pk_rtex);
	CHECK_TSKCTX_UNL();
	CHECK_TSKID_SELF(tskid);
	p_tcb = get_tcb_self(tskid);

	t_lock_cpu();
	if (TSTAT_DORMANT(p_tcb->tstat) || p_tcb->p_tinib->texrtn == NULL) {
		ercd = E_OBJ;
	}
	else {
		pk_rtex->texstat = (p_tcb->enatex) ? TTEX_ENA : TTEX_DIS;
		pk_rtex->pndptn = p_tcb->texptn;
		ercd = E_OK;
	}
	t_unlock_cpu();

  error_exit:
	LOG_REF_TEX_LEAVE(ercd, pk_rtex);
	return(ercd);
}

#endif /* TOPPERS_ref_tex */
