/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: test_dlynse.c 818 2008-03-18 12:56:15Z hiro $
 */

/*
 *		sil_dly_nse�˴ؤ���ƥ���
 */

#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "test_dlynse.h"

/*
 *  SIL_DLY_TIM1��SIL_DLY_TIM2�򻲾Ȥ��뤿��ˡ������ͥ��ѤΥإå��ե�
 *  ����򥤥󥯥롼�ɤ��롥
 */
#include "kernel/kernel_impl.h"

#define	NO_LOOP		ULONG_C(1000000)

uint_t	empty_time;

static void
test_empty(void)
{
	SYSTIM	stime, etime;
	volatile ulong_t	i;

	get_tim(&stime);
	for (i = 0; i < NO_LOOP; i++) {
	}
	get_tim(&etime);
	empty_time = (uint_t)(etime - stime);
	syslog(LOG_NOTICE, "empty loop: %u", empty_time);
	logtask_flush(0U);
	dly_tsk(100);
}

static void
test_dly_nse(ulong_t dlytim)
{
	SYSTIM	stime, etime;
	volatile ulong_t	i;

	get_tim(&stime);
	for (i = 0; i < NO_LOOP; i++) {
		sil_dly_nse(dlytim);
	}
	get_tim(&etime);
	syslog(LOG_NOTICE, "sil_dly_nse(%u): %u", (uint_t)(dlytim),
						(uint_t)(etime - stime) - empty_time);
	logtask_flush(0U);
	dly_tsk(100);
}

void
main_task(intptr_t exinf)
{
	test_empty();

	syslog(LOG_NOTICE, "-- for fitting parameters --");
	test_dly_nse(0);
	test_dly_nse(SIL_DLY_TIM1);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 1);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 2);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 3);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 4);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 5);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 10);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 20);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 50);

	syslog(LOG_NOTICE, "-- for checking boundary conditions --");
	test_dly_nse(SIL_DLY_TIM1 + 1);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 1 + 1);
	test_dly_nse(SIL_DLY_TIM1 + SIL_DLY_TIM2 * 2 + 1);

	ext_ker();
}
