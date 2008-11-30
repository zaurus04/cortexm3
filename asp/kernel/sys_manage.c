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
 *  @(#) $Id: sys_manage.c 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		�����ƥ���ִ�����ǽ
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_ROT_RDQ_ENTER
#define LOG_ROT_RDQ_ENTER(tskpri)
#endif /* LOG_ROT_RDQ_ENTER */

#ifndef LOG_ROT_RDQ_LEAVE
#define LOG_ROT_RDQ_LEAVE(ercd)
#endif /* LOG_ROT_RDQ_LEAVE */

#ifndef LOG_IROT_RDQ_ENTER
#define LOG_IROT_RDQ_ENTER(tskpri)
#endif /* LOG_IROT_RDQ_ENTER */

#ifndef LOG_IROT_RDQ_LEAVE
#define LOG_IROT_RDQ_LEAVE(ercd)
#endif /* LOG_IROT_RDQ_LEAVE */

#ifndef LOG_GET_TID_ENTER
#define LOG_GET_TID_ENTER(p_tskid)
#endif /* LOG_GET_TID_ENTER */

#ifndef LOG_GET_TID_LEAVE
#define LOG_GET_TID_LEAVE(ercd, tskid)
#endif /* LOG_GET_TID_LEAVE */

#ifndef LOG_IGET_TID_ENTER
#define LOG_IGET_TID_ENTER(p_tskid)
#endif /* LOG_IGET_TID_ENTER */

#ifndef LOG_IGET_TID_LEAVE
#define LOG_IGET_TID_LEAVE(ercd, tskid)
#endif /* LOG_IGET_TID_LEAVE */

#ifndef LOG_LOC_CPU_ENTER
#define LOG_LOC_CPU_ENTER()
#endif /* LOG_LOC_CPU_ENTER */

#ifndef LOG_LOC_CPU_LEAVE
#define LOG_LOC_CPU_LEAVE(ercd)
#endif /* LOG_LOC_CPU_LEAVE */

#ifndef LOG_ILOC_CPU_ENTER
#define LOG_ILOC_CPU_ENTER()
#endif /* LOG_ILOC_CPU_ENTER */

#ifndef LOG_ILOC_CPU_LEAVE
#define LOG_ILOC_CPU_LEAVE(ercd)
#endif /* LOG_ILOC_CPU_LEAVE */

#ifndef LOG_UNL_CPU_ENTER
#define LOG_UNL_CPU_ENTER()
#endif /* LOG_UNL_CPU_ENTER */

#ifndef LOG_UNL_CPU_LEAVE
#define LOG_UNL_CPU_LEAVE(ercd)
#endif /* LOG_UNL_CPU_LEAVE */

#ifndef LOG_IUNL_CPU_ENTER
#define LOG_IUNL_CPU_ENTER()
#endif /* LOG_IUNL_CPU_ENTER */

#ifndef LOG_IUNL_CPU_LEAVE
#define LOG_IUNL_CPU_LEAVE(ercd)
#endif /* LOG_IUNL_CPU_LEAVE */

#ifndef LOG_DIS_DSP_ENTER
#define LOG_DIS_DSP_ENTER()
#endif /* LOG_DIS_DSP_ENTER */

#ifndef LOG_DIS_DSP_LEAVE
#define LOG_DIS_DSP_LEAVE(ercd)
#endif /* LOG_DIS_DSP_LEAVE */

#ifndef LOG_ENA_DSP_ENTER
#define LOG_ENA_DSP_ENTER()
#endif /* LOG_ENA_DSP_ENTER */

#ifndef LOG_ENA_DSP_LEAVE
#define LOG_ENA_DSP_LEAVE(ercd)
#endif /* LOG_ENA_DSP_LEAVE */

#ifndef LOG_SNS_CTX_ENTER
#define LOG_SNS_CTX_ENTER()
#endif /* LOG_SNS_CTX_ENTER */

#ifndef LOG_SNS_CTX_LEAVE
#define LOG_SNS_CTX_LEAVE(state)
#endif /* LOG_SNS_CTX_LEAVE */

#ifndef LOG_SNS_LOC_ENTER
#define LOG_SNS_LOC_ENTER()
#endif /* LOG_SNS_LOC_ENTER */

#ifndef LOG_SNS_LOC_LEAVE
#define LOG_SNS_LOC_LEAVE(state)
#endif /* LOG_SNS_LOC_LEAVE */

#ifndef LOG_SNS_DSP_ENTER
#define LOG_SNS_DSP_ENTER()
#endif /* LOG_SNS_DSP_ENTER */

#ifndef LOG_SNS_DSP_LEAVE
#define LOG_SNS_DSP_LEAVE(state)
#endif /* LOG_SNS_DSP_LEAVE */

#ifndef LOG_SNS_DPN_ENTER
#define LOG_SNS_DPN_ENTER()
#endif /* LOG_SNS_DPN_ENTER */

#ifndef LOG_SNS_DPN_LEAVE
#define LOG_SNS_DPN_LEAVE(state)
#endif /* LOG_SNS_DPN_LEAVE */

#ifndef LOG_SNS_KER_ENTER
#define LOG_SNS_KER_ENTER()
#endif /* LOG_SNS_KER_ENTER */

#ifndef LOG_SNS_KER_LEAVE
#define LOG_SNS_KER_LEAVE(state)
#endif /* LOG_SNS_KER_LEAVE */

/*
 *  ��������ͥ���̤β�ž
 */
#ifdef TOPPERS_rot_rdq

ER
rot_rdq(PRI tskpri)
{
	uint_t	pri;
	ER		ercd;

	LOG_ROT_RDQ_ENTER(tskpri);
	CHECK_TSKCTX_UNL();
	CHECK_TPRI_SELF(tskpri);

	t_lock_cpu();
	pri = (tskpri == TPRI_SELF) ? p_runtsk->priority : INT_PRIORITY(tskpri);
	if (rotate_ready_queue(pri)) {
		dispatch();
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_ROT_RDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_rot_rdq */

/*
 *  ��������ͥ���̤β�ž���󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_irot_rdq

ER
irot_rdq(PRI tskpri)
{
	ER		ercd;

	LOG_IROT_RDQ_ENTER(tskpri);
	CHECK_INTCTX_UNL();
	CHECK_TPRI(tskpri);

	i_lock_cpu();
	if (rotate_ready_queue(INT_PRIORITY(tskpri))) {
		reqflg = true;
	}
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_IROT_RDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_irot_rdq */

/*
 *  �¹Ծ��֤Υ�����ID�λ���
 */
#ifdef TOPPERS_get_tid

ER
get_tid(ID *p_tskid)
{
	ER		ercd;

	LOG_GET_TID_ENTER(p_tskid);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_tskid = TSKID(p_runtsk);
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_GET_TID_LEAVE(ercd, *p_tskid);
	return(ercd);
}

#endif /* TOPPERS_get_tid */

/*
 *  �¹Ծ��֤Υ�����ID�λ��ȡ��󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_iget_tid

ER
iget_tid(ID *p_tskid)
{
	ER		ercd;

	LOG_IGET_TID_ENTER(p_tskid);
	CHECK_INTCTX_UNL();

	i_lock_cpu();
	*p_tskid = (p_runtsk == NULL) ? TSK_NONE : TSKID(p_runtsk);
	ercd = E_OK;
	i_unlock_cpu();

  error_exit:
	LOG_IGET_TID_LEAVE(ercd, *p_tskid);
	return(ercd);
}

#endif /* TOPPERS_iget_tid */

/*
 *  CPU��å����֤ؤΰܹ�
 */
#ifdef TOPPERS_loc_cpu

ER
loc_cpu(void)
{
	ER		ercd;

	LOG_LOC_CPU_ENTER();
	CHECK_TSKCTX();

	if (!t_sense_lock()) {
		t_lock_cpu();
	}
	ercd = E_OK;

  error_exit:
	LOG_LOC_CPU_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_loc_cpu */

/*
 *  CPU��å����֤ؤΰܹԡ��󥿥�������ƥ������ѡ�
 */
#ifdef TOPPERS_iloc_cpu

ER
iloc_cpu(void)
{
	ER		ercd;

	LOG_ILOC_CPU_ENTER();
	CHECK_INTCTX();

	if (!i_sense_lock()) {
		i_lock_cpu();
	}
	ercd = E_OK;

  error_exit:
	LOG_ILOC_CPU_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_iloc_cpu */

/*
 *  CPU��å����֤β��
 *
 *  CPU��å���ϡ��ǥ����ѥå���ɬ�פȤʤ륵���ӥ��������ƤӽФ���
 *  �ȤϤǤ��ʤ����ᡤCPU��å����֤β�����˥ǥ����ѥå����ư����
 *  ɬ�פϤʤ���
 */
#ifdef TOPPERS_unl_cpu

ER
unl_cpu(void)
{
	ER		ercd;

	LOG_UNL_CPU_ENTER();
	CHECK_TSKCTX();

	if (t_sense_lock()) {
		t_unlock_cpu();
	}
	ercd = E_OK;

  error_exit:
	LOG_UNL_CPU_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_unl_cpu */

/*
 *  CPU��å����֤β�����󥿥�������ƥ������ѡ�
 *
 *  CPU��å���ϡ��ǥ����ѥå���ɬ�פȤʤ륵���ӥ��������ƤӽФ���
 *  �ȤϤǤ��ʤ����ᡤCPU��å����֤β�����˥ǥ����ѥå���ε�ư����
 *  �᤹��ɬ�פϤʤ���
 */
#ifdef TOPPERS_iunl_cpu

ER
iunl_cpu(void)
{
	ER		ercd;

	LOG_IUNL_CPU_ENTER();
	CHECK_INTCTX();

	if (i_sense_lock()) {
		i_unlock_cpu();
	}
	ercd = E_OK;

  error_exit:
	LOG_IUNL_CPU_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_iunl_cpu */

/*
 *  �ǥ����ѥå��ζػ�
 */
#ifdef TOPPERS_dis_dsp

ER
dis_dsp(void)
{
	ER		ercd;

	LOG_DIS_DSP_ENTER();
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	disdsp = true;
	dspflg = false;
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_DIS_DSP_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_dis_dsp */

/*
 *  �ǥ����ѥå��ε���
 */
#ifdef TOPPERS_ena_dsp

ER
ena_dsp(void)
{
	ER		ercd;

	LOG_ENA_DSP_ENTER();
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	disdsp = false;
	if (t_get_ipm() == TIPM_ENAALL) {
		dspflg = true;
		if (p_runtsk != p_schedtsk) {
			dispatch();
		}
	}
	ercd = E_OK;
	t_unlock_cpu();

  error_exit:
	LOG_ENA_DSP_LEAVE(ercd);
	return(ercd);
}

#endif /* TOPPERS_ena_dsp */

/*
 *  ����ƥ����Ȥλ���
 */
#ifdef TOPPERS_sns_ctx

bool_t
sns_ctx(void)
{
	bool_t	state;

	LOG_SNS_CTX_ENTER();
	state = sense_context() ? true : false;
	LOG_SNS_CTX_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_sns_ctx */

/*
 *  CPU��å����֤λ���
 */
#ifdef TOPPERS_sns_loc

bool_t
sns_loc(void)
{
	bool_t	state;

	LOG_SNS_LOC_ENTER();
	state = x_sense_lock() ? true : false;
	LOG_SNS_LOC_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_sns_loc */

/*
 *  �ǥ����ѥå��ػ߾��֤λ���
 */
#ifdef TOPPERS_sns_dsp

bool_t
sns_dsp(void)
{
	bool_t	state;

	LOG_SNS_DSP_ENTER();
	state = disdsp;
	LOG_SNS_DSP_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_sns_dsp */

/*
 *  �ǥ����ѥå���α���֤λ���
 */
#ifdef TOPPERS_sns_dpn

bool_t
sns_dpn(void)
{
	bool_t	state;

	LOG_SNS_DPN_ENTER();
	state = (sense_context() || t_sense_lock() || !dspflg) ? true : false;
	LOG_SNS_DPN_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_sns_dpn */

/*
 *  �����ͥ���ư����֤λ���
 */
#ifdef TOPPERS_sns_ker

bool_t
sns_ker(void)
{
	bool_t	state;

	LOG_SNS_KER_ENTER();
	state = kerflg ? false : true;
	LOG_SNS_KER_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_sns_ker */
