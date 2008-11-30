/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
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
 *  @(#) $Id: test_sem1.c 1232 2008-08-09 13:30:32Z ertl-hiro $
 */

/* 
 *		���ޥե���ǽ�Υƥ���(1)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  sig_sem��wai_sem��CRE_SEM������Ū�˥ƥ��Ȥ��롥
 *  ��������CRE_SEM�Υ��顼�Υƥ��ȤϽ�����
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) sig_sem����Ū���顼�Υƥ���
 *		(A-1) �󥿥�������ƥ����Ȥ���θƽФ�
 *		(A-2) CPU��å����֤���θƽФ�
 *		(A-3) semid�������ʾ����������
 *		(A-4) semid���������礭�������
 *	(B) sig_sem�ˤ�ꥻ�ޥե��Ԥ����֤Υ��������Ԥ���������
 *		(B-1) �Ԥ�������줿���������ڤ괹���
 *		(B-2) �ǥ����ѥå���α���֤ǡ��ڤ괹���ʤ�
 *		(B-3) �Ԥ�������줿�������������Ԥ����֤ǡ��ڤ괹���ʤ�
 *		(B-4) �Ԥ�������줿��������ͥ���٤��㤯���ڤ괹���ʤ�
 *	(C) sig_sem�ˤ�ꥻ�ޥե��λ񸻿���1������
 *		(C-1) ���ޥե��λ񸻿���0����1�ˤʤ�
 *		(C-2) ���ޥե��λ񸻿���1����2�ˤʤ�
 *	(D) sig_sem��E_QOVR���顼�Ȥʤ�
 *		(D-1) ���ޥե��κ���񸻿���1�λ�
 *		(D-2) ���ޥե��κ���񸻿���2�λ�
 *	(E) wai_sem����Ū���顼�Υƥ���
 *		(E-1) �󥿥�������ƥ����Ȥ���θƽФ�
 *		(E-2) CPU��å����֤���θƽФ�
 *		(E-3) �ǥ����ѥå��ػ߾��֤���θƽФ�
 *		(E-4) �����ͥ���٥ޥ���������Ǥʤ����֤���θƽФ�
 *		(E-5) semid�������ʾ����������
 *		(E-6) semid���������礭�������
 *	(F) wai_sem�ˤ�ꥻ�ޥե��λ񸻿���1����
 *		(F-1) ���ޥե��λ񸻿���1����0�ˤʤ�
 *		(F-2) ���ޥե��λ񸻿���2����1�ˤʤ�
 *	(G) wai_sem�ˤ�ꥻ�ޥե��Ԥ����֤ˤʤ�
 *		(G-1) TA_TNULL°���Υ��ޥե��ǡ��ԤäƤ��륿�������ʤ��ä����
 *		(G-2) TA_TNULL°���Υ��ޥե��ǡ��ԤäƤ��륿���������ä����
 *		(G-3) TA_TPRI°���Υ��ޥե��ǡ��ԤäƤ��륿�������ʤ��ä����
 *		(G-4) TA_TPRI°���Υ��ޥե��ǡ�ͥ���٤��⤤���������ԤäƤ�����
 *		(G-5) TA_TPRI°���Υ��ޥե��ǡ�ͥ���٤�Ʊ�����������ԤäƤ�����
 *		(G-6) TA_TPRI°���Υ��ޥե��ǡ�ͥ���٤��㤤���������ԤäƤ�����
 *	(H) ���ޥե��Ԥ����֤�������������
 *	(I) ���ޥե��Ԥ����֤δ֤˥��ޥե�������������
 *	(J) ���ޥե��λ񸻿��ν���ͤ����������ꤵ���
 *		(J-1) ���ޥե��λ񸻿��ν���ͤ�0
 *		(J-2) ���ޥե��λ񸻿��ν���ͤ�1
 *		(J-3) ���ޥե��λ񸻿��ν���ͤ�2
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: ��ͥ���٥�������TA_ACT°��
 *	TASK2: ��ͥ���٥�����
 *	TASK3: ��ͥ���٥�����
 *	TASK4: ��ͥ���٥�����
 *	TASK5: ��ͥ���٥�����
 *	ALM1:  ���顼��ϥ�ɥ�
 *  SEM1:  TA_NULL°��������񸻿�1������񸻿�1
 *  SEM2:  TA_NULL°��������񸻿�2������񸻿�2
 *  SEM3:  TA_TPRI°��������񸻿�0������񸻿�1
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١����==
 *  1:	ref_sem(SEM1, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 1)			... (J-2)
 *  	ref_sem(SEM2, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 2)			... (J-3)
 *  	ref_sem(SEM3, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 0)			... (J-1)
 *	2:	loc_cpu()
 *		sig_sem(SEM1) -> E_CTX				... (A-2)
 *		wai_sem(SEM1) -> E_CTX				... (E-2)
 *		unl_cpu()
 *		dis_dsp()
 *		wai_sem(SEM1) -> E_CTX				... (E-3)
 *		ena_dsp()
 *		chg_ipm(TMAX_INTPRI)
 *		wai_sem(SEM1) -> E_CTX				... (E-4)
 *		chg_ipm(TIPM_ENAALL)
 *		sig_sem(0) -> E_ID					... (A-3)
 *		wai_sem(0) -> E_ID					... (E-5)
 *		sig_sem(TNUM_SEMID+1) -> E_ID		... (A-4)
 *		wai_sem(TNUM_SEMID+1) -> E_ID		... (E-6)
 *	3:	act_tsk(TASK3)
 *	4:	slp_tsk()
 *	== TASK3��ͥ���١����==
 *	5:	wai_sem(SEM1)						... (F-1)
 *  6:	ref_sem(SEM1, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 0)
 *	7:	sta_alm(ALM1, 10)
 *	8:	wai_sem(SEM1)						... (G-1)
 *	== ALM1 ==
 *	9:	sig_sem(SEM1) -> E_CTX				... (A-1)
 *		wai_sem(SEM1) -> E_CTX				... (E-1)
 *	10:	iwup_tsk(TASK1)
 *	11:	RETURN
 *	== TASK1��³����==
 *	12:	act_tsk(TASK2)
 *	== TASK2��ͥ���١����==
 *	13:	wai_sem(SEM1)						... (G-2)
 *	== TASK1��³����==
 *  14:	ref_sem(SEM1, &rsem)
 *		assert(rsem.wtskid == TASK3)
 *		assert(rsem.semcnt == 0)
 *	15:	sig_sem(SEM1)						... (B-4)
 *	16:	sig_sem(SEM1)						... (B-1)
 *	== TASK2��³����==
 *	17:	wai_sem(SEM1)						... (G-1)
 *	== TASK1��³����==
 *	18: dis_dsp()
 *	19:	sig_sem(SEM1)						... (B-2)
 *	20:	ena_dsp()
 *	== TASK2��³����==
 *	21:	wai_sem(SEM1)						... (G-1)
 *	== TASK1��³����==
 *	22: sus_tsk(TASK2)
 *	23:	sig_sem(SEM1)						... (B-3)
 *	24: sig_sem(SEM1)						... (C-1)
 *	25: sig_sem(SEM1) -> E_QOVR				... (D-1)
 *  26:	ref_sem(SEM1, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 1)
 *	27:	rsm_tsk(TASK2)
 *	== TASK2��³����==
 *	28:	wai_sem(SEM2)						... (F-2)
 *  29:	ref_sem(SEM2, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 1)
 *	30:	wai_sem(SEM2)						... (F-1)
 *	31: wai_sem(SEM2)						... (G-1)
 *	== TASK1��³����==
 *	32:	sig_sem(SEM2)						... (B-1)
 *	== TASK2��³����==
 *	33:	wai_sem(SEM3)						... (G-3)
 *	== TASK1��³����==
 *	34:	sig_sem(SEM2)						... (C-1)
 *	35:	sig_sem(SEM2)						... (C-2)
 *  36:	ref_sem(SEM2, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 2)
 *	37:	sig_sem(SEM2) -> E_QOVR				... (D-2)
 *  38:	ref_sem(SEM2, &rsem)
 *		assert(rsem.wtskid == TSK_NONE)
 *		assert(rsem.semcnt == 2)
 *	39:	MISSING
 *	40:	tslp_tsk(10) -> E_TMOUT
 *	== TASK3��³����==
 *	41:	wai_sem(SEM3)						... (G-4)
 *	== TASK1��³����==
 *	42:	act_tsk(TASK4)
 *	43:	act_tsk(TASK5)
 *	44:	rot_rdq(TPRI_SELF)
 *	== TASK4��ͥ���١����==
 *	45:	wai_sem(SEM3)						... (G-6)
 *	== TASK5��ͥ���١����==
 *	46:	wai_sem(SEM3)						... (G-5)
 *	== TASK1��³����==
 *	47:	sig_sem(SEM3)						... (B-1)
 *	== TASK2��³����==
 *	48:	wai_sem(SEM1)
 *		wai_sem(SEM1) -> E_RLWAI
 *	== TASK1��³����==
 *	49:	sig_sem(SEM3)						... (B-4)
 *	50:	tslp_tsk(10) -> E_TMOUT
 *	== TASK4��³����==
 *	51:	ext_tsk() -> noreturn
 *	== TASK1��³����==
 *	52:	sig_sem(SEM3)						... (B-4)
 *	53:	tslp_tsk(10) -> E_TMOUT
 *	== TASK5��³����==
 *	54:	ext_tsk() -> noreturn
 *	== TASK1��³����==
 *	55:	sig_sem(SEM3)						... (B-4)
 *	56:	tslp_tsk(10) -> E_TMOUT
 *	== TASK3��³����==
 *	57:	ext_tsk() -> noreturn
 *	== TASK1��³����==
 *	58: rel_wai(TASK2)						... (H)
 *	== TASK2��³����==
 *	59:	wai_sem(SEM1) -> E_DLT
 *	== TASK1��³����==
 *	60: ini_sem(SEM1)						... (H)
 *	== TASK2��³����==
 *	61: ext_tsk() -> noreturn
 *	== TASK1��³����==
 *	62: END
 */

#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_sem1.h"

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;

	check_point(9);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_CTX);

	check_point(10);
	ercd = iwup_tsk(TASK1);
	check_ercd(ercd, E_OK);

	check_point(11);
	return;

	check_point(0);
}

void
task1(intptr_t exinf)
{
	ER		ercd;
	T_RSEM	rsem;

	check_point(1);
	ercd = ref_sem(SEM1, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 1);

	ercd = ref_sem(SEM2, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 2);

	ercd = ref_sem(SEM3, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 0);

	check_point(2);
	ercd = loc_cpu();
	check_ercd(ercd, E_OK);

	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = unl_cpu();
	check_ercd(ercd, E_OK);

	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	ercd = chg_ipm(TMAX_INTPRI);
	check_ercd(ercd, E_OK);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_CTX);

	ercd = chg_ipm(TIPM_ENAALL);
	check_ercd(ercd, E_OK);

	ercd = sig_sem(0);
	check_ercd(ercd, E_ID);

	ercd = wai_sem(0);
	check_ercd(ercd, E_ID);

	ercd = sig_sem(TNUM_SEMID+1);
	check_ercd(ercd, E_ID);

	ercd = wai_sem(TNUM_SEMID+1);
	check_ercd(ercd, E_ID);

	check_point(3);
	ercd = act_tsk(TASK3);
	check_ercd(ercd, E_OK);

	check_point(4);
	ercd = slp_tsk();
	check_ercd(ercd, E_OK);

	check_point(12);
	ercd = act_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(14);
	ercd = ref_sem(SEM1, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TASK3);
	check_assert(rsem.semcnt == 0);

	check_point(15);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(16);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(18);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(19);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(20);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);

	check_point(22);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(23);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(24);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(25);
	ercd = sig_sem(SEM1);
	check_ercd(ercd, E_QOVR);

	check_point(26);
	ercd = ref_sem(SEM1, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 1);

	check_point(27);
	ercd = rsm_tsk(TASK2);
	check_ercd(ercd, E_OK);

	check_point(32);
	ercd = sig_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(34);
	ercd = sig_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(35);
	ercd = sig_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(36);
	ercd = ref_sem(SEM2, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 2);

	check_point(37);
	ercd = sig_sem(SEM2);
	check_ercd(ercd, E_QOVR);

	check_point(38);
	ercd = ref_sem(SEM2, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 2);

	check_point(39);

	check_point(40);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(42);
	ercd = act_tsk(TASK4);
	check_ercd(ercd, E_OK);

	check_point(43);
	ercd = act_tsk(TASK5);
	check_ercd(ercd, E_OK);

	check_point(44);
	ercd = rot_rdq(TPRI_SELF);
	check_ercd(ercd, E_OK);

	check_point(47);
	ercd = sig_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(49);
	ercd = sig_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(50);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(52);
	ercd = sig_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(53);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(55);
	ercd = sig_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(56);
	ercd = tslp_tsk(10);
	check_ercd(ercd, E_TMOUT);

	check_point(58);
	ercd = rel_wai(TASK2);
	check_ercd(ercd, E_OK);

	check_point(60);
	ercd = ini_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_finish(62);

	check_point(0);
}

void
task2(intptr_t exinf)
{
	ER		ercd;
	T_RSEM	rsem;

	check_point(13);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(17);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(21);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(28);
	ercd = wai_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(29);
	ercd = ref_sem(SEM2, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 1);

	check_point(30);
	ercd = wai_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(31);
	ercd = wai_sem(SEM2);
	check_ercd(ercd, E_OK);

	check_point(33);
	ercd = wai_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(48);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_RLWAI);

	check_point(59);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_DLT);

	check_point(61);
	ercd = ext_tsk();

	check_point(0);
}

void
task3(intptr_t exinf)
{
	ER		ercd;
	T_RSEM	rsem;

	check_point(5);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(6);
	ercd = ref_sem(SEM1, &rsem);
	check_ercd(ercd, E_OK);
	check_assert(rsem.wtskid == TSK_NONE);
	check_assert(rsem.semcnt == 0);

	check_point(7);
	ercd = sta_alm(ALM1, 10);
	check_ercd(ercd, E_OK);

	check_point(8);
	ercd = wai_sem(SEM1);
	check_ercd(ercd, E_OK);

	check_point(41);
	ercd = wai_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(57);
	ercd = ext_tsk();

	check_point(0);
}

void
task4(intptr_t exinf)
{
	ER		ercd;

	check_point(45);
	ercd = wai_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(51);
	ercd = ext_tsk();

	check_point(0);
}

void
task5(intptr_t exinf)
{
	ER		ercd;

	check_point(46);
	ercd = wai_sem(SEM3);
	check_ercd(ercd, E_OK);

	check_point(54);
	ercd = ext_tsk();

	check_point(0);
}
