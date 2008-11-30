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
 *  @(#) $Id: test_task1.c 1232 2008-08-09 13:30:32Z ertl-hiro $
 */

/* 
 *		�����������⥸�塼��Υƥ���(1)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  make_runnable��make_non_runnable������Ū�˥ƥ��Ȥ��롥
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) �¹Ծ��֤Υ���������⤤ͥ���٤Υ�������¹ԤǤ�����֤ˤ���
 *		(A-1) �ǥ����ѥå���α���֤ǤϤʤ����
 *		(A-2) �ǥ����ѥå���α���֤ξ��
 *	(B) �¹Ծ��֤Υ�������Ʊ��ͥ���٤Υ�������¹ԤǤ�����֤ˤ���
 *		��Ʊ��ͥ���٤Υ�������������������뤳�Ȥ��ǧ����
 *	(C) �¹Ծ��֤Υ����������㤤ͥ���٤Υ�������¹ԤǤ�����֤ˤ���
 *		��Ʊ��ͥ���٤Υ�������������������뤳�Ȥ��ǧ����
 *	(D) �¹ԤǤ�����֤Υ��������ʤ����֤ǡ���������¹ԤǤ�����֤ˤ���
 *		�����ξ��ϡ��ǥ����ѥå���α���֤ǤϤʤ�
 *	(E) �ǥ����ѥå���α���֤ǡ��¹Ծ��֤ˤʤ�٤������¹Բ�ǽ���֥���
 *		������⤤ͥ���٤Υ������򡤼¹ԤǤ�����֤ˤ���
 *	(F) �ǥ����ѥå���α���֤ǡ��¹Ծ��֤ˤʤ�٤������¹Բ�ǽ���֥���
 *		����Ʊ��ͥ���٤Υ������򡤼¹ԤǤ�����֤ˤ���
 *	(G) �ǥ����ѥå���α���֤ǡ��¹Ծ��֤ˤʤ�٤������¹Բ�ǽ���֥���
 *		�������㤤ͥ���٤Υ������򡤼¹ԤǤ�����֤ˤ���
 *	(H) �¹Ծ��֤Υ������򡤼¹ԤǤ�����֤Ǥʤ���
 *		(H-1) �¹ԤǤ�����֤Υ��������ʤ��ʤ���
 *		(H-2) Ʊ��ͥ���٤Υ��������ʤ��ʤ���
 *		(H-3) Ʊ��ͥ���٤Υ��������ʤ��ʤ�ʤ����
 *	(I) �¹Բ�ǽ���֤Υ������򡤼¹ԤǤ�����֤Ǥʤ���
 *		(I-1) Ʊ��ͥ���٤Υ��������ʤ��ʤ���
 *		(I-2) Ʊ��ͥ���٤Υ��������ʤ��ʤ�ʤ����
 *	(J) �ǥ����ѥå���α���֤ǡ��¹Ծ��֤ˤʤ�٤������¹Բ�ǽ���֤Ȥʤ�
 *		�Ƥ��륿�����򡤼¹ԤǤ�����֤Ǥʤ���
 *		(J-1) Ʊ��ͥ���٤Υ��������ʤ��ʤ���
 *		(J-2) Ʊ��ͥ���٤Υ��������ʤ��ʤ�ʤ����
 *	(K) �ǥ����ѥå���α���֤ǡ��¹Բ�ǽ���֤ˤʤ�٤������¹Ծ��֤Υ�
 *		�����򡤼¹ԤǤ�����֤Ǥʤ���
 *		���ǥ����ѥå���α�Ǥϡ��¹Ծ��֤Υ��������¹ԤǤ�����֤Ǥʤ�
 *		�ʤ�褦�����ܤ򵯤������Ȥ��Ǥ��ʤ����ᡤ���ξ����ϵ�����ʤ���
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: ��ͥ���٥��������ᥤ�󥿥������ǽ餫�鵯ư
 *	TASK2: ��ͥ���٥�����
 *	TASK3: ��ͥ���٥�����
 *	TASK4: ��ͥ���٥�����
 *	TASK5: ��ͥ���٥�����
 *	TASK6: ��ͥ���٥�����
 *	ALM1:  ���顼��ϥ�ɥ�
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *	1:	act_tsk(TASK2)					... (A-1)
 *	== TASK2��ͥ���١����==
 *	2:	slp_tsk()						... (H-2)
 *	== TASK1��³����==
 *	3:	act_tsk(TASK3)					... (B)
 *	4:	act_tsk(TASK4)					... (B)
 *	5:	slp_tsk()						... (H-3)
 *	== TASK3��ͥ���١����==
 *	6:	slp_tsk()						... (H-3)
 *	== TASK4��ͥ���١����==
 *	7:	wup_tsk(TASK1)
 *	8:	slp_tsk()						... (H-3)
 *	== TASK1��³����==
 *	9:	act_tsk(TASK5)					... (C)
 *	10:	act_tsk(TASK6)					... (C)
 *	11:	sus_tsk(TASK6)					... (I-2)
 *	12:	sus_tsk(TASK5)					... (I-1)
 *	13:	rsm_tsk(TASK5)					... (C)
 *	14:	rsm_tsk(TASK6)					... (C)
 *	15:	slp_tsk()						... (H-2)
 *	== TASK5��ͥ���١����==
 *	16:	slp_tsk()						... (H-3)
 *	== TASK6��ͥ���١����==
 *	17:	dis_dsp()
 *	18:	wup_tsk(TASK1)					... (A-2)
 *	19:	wup_tsk(TASK2)					... (E)
 *	20:	sus_tsk(TASK2)					... (J-1)
 *	21:	wup_tsk(TASK3)					... (F)
 *	22:	wup_tsk(TASK4)					... (F)
 *	23:	sus_tsk(TASK1)					... (J-2)
 *	24:	ena_dsp()
 *	== TASK3��³����==
 *	25:	slp_tsk()						... (H-3)
 *	== TASK4��³����==
 *	26:	slp_tsk()						... (H-2)
 *	== TASK6��³����==
 *	27:	dis_dsp()
 *	28:	rsm_tsk(TASK1)					... (A-2)
 *	29:	wup_tsk(TASK5)					... (G)
 *	30:	ena_dsp()
 *	== TASK1��³����==
 *	31:	slp_tsk()						... (H-2)
 *	== TASK6��³����==
 *	32:	slp_tsk()						... (H-3)
 *	== TASK5��³����==
 *	33:	sus_tsk(LOGTASK)
 *	34:	sta_alm(ALM1, 10)
 *	35:	slp_tsk()						... (H-1)
 *	== ALM1 ==
 *	36:	iget_tid(&tskid)
 *		assert(tskid == TSK_NONE)
 *	37:	iwup_tsk(TASK1)					... (D)
 *	38:	RETURN
 *	== TASK1��³����==
 *	39:	rsm_tsk(LOGTASK)
 *	40: END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_task1.h"

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;
	ID		tskid;

	check_point(36);
	ercd = iget_tid(&tskid);
	check_ercd(ercd, E_OK);
	check_assert(tskid == TSK_NONE);

	check_point(37);
	ercd = iwup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(38);
	return;

	check_point(0);
}

void
task1(intptr_t exinf)
{
	ER		ercd;

	check_point(1);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(3);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(5);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(9);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(10);
	ercd = act_tsk(TASK6);
	check_ercd(ercd, E_OK);

	check_point(11);
	ercd = sus_tsk(TASK6);
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = sus_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(13);
	ercd = rsm_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = rsm_tsk(TASK6);
	check_ercd(ercd, E_OK);

	check_point(15);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(39);
	ercd = rsm_tsk(LOGTASK);
	check_ercd(ercd, E_OK);

	check_finish(40);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	check_point(2);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	check_point(6);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;

	check_point(7);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(26);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;

	check_point(16);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = sus_tsk(LOGTASK);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}

void
task6(intptr_t exinf)
{
	ER		ercd;

	check_point(17);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = wup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = wup_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = wup_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(22);
	ercd = wup_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(23);
	ercd = sus_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(27);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = rsm_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = wup_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(30);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(0);
}
