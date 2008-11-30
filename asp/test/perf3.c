/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 * 
 *  Copyright (C) 2007,2008 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: perf3.c 1116 2008-06-14 07:07:20Z ertl-hiro $
 */

/*
 *		�����ͥ���ǽɾ���ץ����(3)
 *
 *  �Ԥ�������륿�����ο��ˤ�ꡤset_flg�ν������֤��ɤΤ褦���Ѳ�����
 *  �����¬���뤿��Υץ���ࡥ
 */

#include <kernel.h>
#include <t_syslog.h>
#include <histogram.h>
#include "syssvc/logtask.h"
#include "kernel_cfg.h"
#include "perf3.h"

/*
 *  ��¬����ȼ¹Ի���ʬ�ۤ�Ͽ����������
 */
#define NO_MEASURE	10000U			/* ��¬��� */
#define MAX_TIME	1000U			/* �¹Ի���ʬ�ۤ�Ͽ���������� */

/*
 *  �¹Ի���ʬ�ۤ�Ͽ��������ΰ�
 */
static uint_t	histarea1[MAX_TIME + 1];

/*
 *  ��¬�������Υꥹ��
 */
static ID task_list[20] = {
	TASK1, TASK2, TASK3, TASK4, TASK5,
	TASK6, TASK7, TASK8, TASK9, TASK10,
	TASK11, TASK12, TASK13, TASK14, TASK15,
	TASK16, TASK17, TASK18, TASK19, TASK20
};

/*
 *  ��¬����������ͥ���١�
 */
void task(intptr_t exinf)
{
	FLGPTN	flgptn;

	wai_flg(FLG1, 0x01U, TWF_ORW, &flgptn);
}

/*
 *  ��¬�롼����
 */
void
perf_eval(uint_t n)
{
	uint_t		i, j;

	init_hist(1, MAX_TIME, histarea1);

	sus_tsk(LOGTASK);		/* �����ƥ����������ư���ߤ�� */
	for (i = 0; i < NO_MEASURE; i++) {
		ini_flg(FLG1);
		for (j = 0; j < n; j++) {
			act_tsk(task_list[j]);
		}
		chg_pri(TSK_SELF, MAIN_PRIORITY_LOW);
		/* ���������Ԥ����֤�����Τ��Ԥ� */
		chg_pri(TSK_SELF, TPRI_INI);

		begin_measure(1);
		set_flg(FLG1, 0x01U);
		end_measure(1);

		chg_pri(TSK_SELF, MAIN_PRIORITY_LOW);
		/* ����������λ����Τ��Ԥ� */
		chg_pri(TSK_SELF, TPRI_INI);
	}
	rsm_tsk(LOGTASK);		/* �����ƥ����������ư���Ƴ����� */

	syslog_1(LOG_NOTICE, "Execution times of set_flg"
							" when %d tasks are released from waiting.", n);
	print_hist(1);
	logtask_flush(0U);
}

/*
 *  �ᥤ�󥿥����ʹ�ͥ���١�
 */
void main_task(intptr_t exinf)
{
	syslog_0(LOG_NOTICE, "Performance evaluation program (3)");
	logtask_flush(0U);

	perf_eval(0);
	perf_eval(1);
	perf_eval(2);
	perf_eval(3);
	perf_eval(4);
	perf_eval(5);
	perf_eval(10);
	perf_eval(20);
	ext_ker();
}
