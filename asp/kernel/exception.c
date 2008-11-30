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
 *  @(#) $Id: exception.c 748 2008-03-07 17:18:06Z hiro $
 */

/*
 *		CPU�㳰������ǽ
 */

#include "kernel_impl.h"
#include "task.h"
#include "exception.h"

/*
 *  �ȥ졼�����ޥ���Υǥե�������
 */
#ifndef LOG_XSNS_DPN_ENTER
#define LOG_XSNS_DPN_ENTER(p_excinf)
#endif /* LOG_XSNS_DPN_ENTER */

#ifndef LOG_XSNS_DPN_LEAVE
#define LOG_XSNS_DPN_LEAVE(state)
#endif /* LOG_XSNS_DPN_LEAVE */

#ifndef LOG_XSNS_XPN_ENTER
#define LOG_XSNS_XPN_ENTER(p_excinf)
#endif /* LOG_XSNS_XPN_ENTER */

#ifndef LOG_XSNS_XPN_LEAVE
#define LOG_XSNS_XPN_LEAVE(state)
#endif /* LOG_XSNS_XPN_LEAVE */

/* 
 *  CPU�㳰�ϥ�ɥ������ǽ�ν����
 */
#ifdef TOPPERS_excini
#ifndef OMIT_INITIALIZE_EXCEPTION

void
initialize_exception(void)
{
	uint_t			i;
	const EXCINIB	*p_excinib;

	for (p_excinib = excinib_table, i = 0; i < tnum_excno; p_excinib++, i++) {
		x_define_exc(p_excinib->excno, p_excinib->exc_entry);
	}
}

#endif /* OMIT_INITIALIZE_EXCEPTION */
#endif /* TOPPERS_excini */

/*
 *  CPU�㳰��ȯ����������ƥ����Ȥλ���
 */

/*
 *  CPU�㳰ȯ�����Υǥ����ѥå���α���֤λ���
 *
 *  CPU�㳰�ϥ�ɥ����disdsp���Ѳ����뤳�ȤϤʤ����ᡤCPU�㳰��ȯ����
 *  ������disdsp����¸���Ƥ���ɬ�פϤʤ���
 */
#ifdef TOPPERS_xsns_dpn

bool_t
xsns_dpn(void *p_excinf)
{
	bool_t	state;

	LOG_XSNS_DPN_ENTER(p_excinf);
	state = (exc_sense_intmask(p_excinf) && !disdsp) ? false : true;
	LOG_XSNS_DPN_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_xsns_dpn */

/*
 *  CPU�㳰ȯ�����Υ������㳰������α���֤λ���
 *
 *  CPU�㳰�ϥ�ɥ����p_runtsk��p_runtsk->enatex���Ѳ����뤳�ȤϤʤ�
 *  ���ᡤCPU�㳰��ȯ����������p_runtsk->enatex����¸���Ƥ���ɬ�פϤ�
 *  ����
 */
#ifdef TOPPERS_xsns_xpn

bool_t
xsns_xpn(void *p_excinf)
{
	bool_t	state;

	LOG_XSNS_XPN_ENTER(p_excinf);
	state = (exc_sense_unlock(p_excinf)
				&& p_runtsk != NULL && p_runtsk->enatex) ? false : true;
	LOG_XSNS_XPN_LEAVE(state);
	return(state);
}

#endif /* TOPPERS_xsns_xpn */
