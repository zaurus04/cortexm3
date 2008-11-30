/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2006-2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: perf1.c 818 2008-03-18 12:56:15Z hiro $
 */

/*
 *		�����ͥ���ǽɾ���ץ����(1)
 *
 *  slp_tsk��wup_tsk�ˤ�륿�����ڴ������֤��¬���뤿��Υץ���ࡥ
 */

#include <kernel.h>
#include <t_syslog.h>
#include <histogram.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "perf1.h"

/*
 *  ��¬����ȼ¹Ի���ʬ�ۤ�Ͽ����������
 */
#define NO_MEASURE	10000U			/* ��¬��� */
#define MAX_TIME	1000U			/* �¹Ի���ʬ�ۤ�Ͽ���������� */

/*
 *  �¹Ի���ʬ�ۤ�Ͽ��������ΰ�
 */
static uint_t	histarea1[MAX_TIME + 1];
static uint_t	histarea2[MAX_TIME + 1];

/*
 *  ��¬������1�ʹ�ͥ���١�
 */
void task1(intptr_t exinf)
{
	uint_t	i;

	slp_tsk();
	end_measure(1);
	for (i = 1; i < NO_MEASURE; i++) {
		begin_measure(2);
		slp_tsk();
		end_measure(1);
	}
	begin_measure(2);
	slp_tsk();
}

/*
 *  ��¬������2����ͥ���١�
 */
void task2(intptr_t exinf)
{
	uint_t	i;

	for (i = 0; i < NO_MEASURE; i++) {
		begin_measure(1);
		wup_tsk(TASK1);
		end_measure(2);
	}
	wup_tsk(TASK1);
}

/*
 *  �ᥤ�󥿥�������ͥ���١�
 */
void main_task(intptr_t exinf)
{
	syslog_0(LOG_NOTICE, "Performance evaluation program (1)");
	init_hist(1, MAX_TIME, histarea1);
	init_hist(2, MAX_TIME, histarea2);
	logtask_flush(0U);

	sus_tsk(LOGTASK);		/* �����ƥ����������ư���ߤ�� */
	act_tsk(TASK1);
	act_tsk(TASK2);
	rsm_tsk(LOGTASK);		/* �����ƥ����������ư���Ƴ����� */

	syslog_0(LOG_NOTICE, "Execution times of wup_tsk -> slp_tsk");
	print_hist(1);
	syslog_0(LOG_NOTICE, "Execution times of slp_tsk -> wup_tsk");
	print_hist(2);
	ext_ker();
}
