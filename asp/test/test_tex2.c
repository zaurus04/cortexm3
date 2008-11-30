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
 *  @(#) $Id: test_tex2.c 818 2008-03-18 12:56:15Z hiro $
 */

/* 
 *		�������㳰�����˴ؤ���ƥ���(2)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ����ߥϥ�ɥ�ʥ��顼��ϥ�ɥ�ˤ����CPU�㳰�ϥ�ɥ餫�饿������
 *  �������롼�����ư�������������Ū�˥ƥ��Ȥ��롥
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) iras_tex�Υ��顼����
 *		(A-1) �оݥ��������ٻ߾���
 *		(A-2) �оݥ������Υ������㳰�����롼�����������Ƥ��ʤ�
 *	(B) ����ߥϥ�ɥ餫��ƤФ줿iras_tex���������
 *		(B-1) �оݥ��������¹Ծ��֤Υ��������ĥ������㳰��������
 *		(B-2) �оݥ��������¹Ծ��֤Υ������Ǥʤ�
 *		(B-3) �оݥ��������¹Ծ��֤Υ����������������㳰�����ػ�
 *	(C) CPU�㳰�ϥ�ɥ餫��ƤФ줿iras_tex���������
 *		(C-1) �оݥ��������¹Ծ��֤Υ��������ĥ������㳰��������
 *		(C-2) �оݥ��������¹Ծ��֤Υ������Ǥʤ�
 *		(C-3) �оݥ��������¹Ծ��֤Υ����������������㳰�����ػ�
 *				�� �»ܤ��ʤ��ʥ������å����¸�˼¸��Ǥ��ʤ���
 *	(D) ����ߥϥ�ɥ�νи������ˤ�뵯ư
 *		(D-1) �ǥ����ѥå���Υ��������������㳰���Ĥǥ������㳰������
 *			  �ᤢ��
 *	(E) CPU�㳰�ϥ�ɥ�νи������ˤ�뵯ư
 *		(E-1) �ǥ����ѥå���Υ��������������㳰���Ĥǥ������㳰������
 *			  �ᤢ��
 *	(F) sns_tex�Ǽ¹Ծ��֤Υ��������ʤ�
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: �ᥤ��Υ��������¹Ծ��֤Υ��������Ф��ƥ������㳰�������׵᤹
 *		   ���оݥ�����
 *	TASK2: �¹Ծ��֤Ǥʤ����������Ф��ƥ������㳰�������׵᤹���оݥ�����
 *	TASK3: �������㳰�����롼�����������Ƥ��ʤ�������
 *	TASK4: �ٻ߾��֤Υ�����
 *	ALM1:  ���顼��ϥ�ɥ�1
 *	ALM2:  ���顼��ϥ�ɥ�2
 *	ALM3:  ���顼��ϥ�ɥ�3
 *	CPUEXC1: CPU�㳰�ϥ�ɥ�
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١�10��==
 *	1:	������֤Υ����å�
 *		ref_tex(TSK_SELF, &rtex)
 *	2:	sta_alm(ALM1, 1U)
 *		���顼��ϥ�ɥ�1�μ¹Ԥ��Ԥ�
 *	== ALM1 ==
 *	3:	������֤Υ����å�
 *		iras_tex(TASK3, 0x0001)		... (A-2)
 *		iras_tex(TASK4, 0x0001)		... (A-1)
 *		iras_tex(TASK2, 0x0001)		... (B-2)
 *		iras_tex(TASK1, 0x0001)		... (B-3)
 *		�꥿����
 *	== TASK1��³����==
 *	4:	ena_tex()
 *	== TASK1�������㳰�����롼�����1���ܡ�==
 *	5:	������֤Υ����å�
 *	6:	dis_dsp() ... 4�Ĥξ��֤򤽤줾���Ѳ�������
 *		chg_ipm(TMAX_INTPRI)
 *		ena_tex()
 *		loc_cpu()
 *		�꥿����
 *	== TASK1��³����==
 *	7:	��äƤ������֤Υ����å�
 *		ref_tex(TSK_SELF, &rtex)
 *	8:	sta_alm(ALM2, 1U)
 *		���顼��ϥ�ɥ�2�μ¹Ԥ��Ԥ�
 *	== ALM2 ==
 *	9:	������֤Υ����å�
 *		iras_tex(TASK1, 0x0002)		... (B-1)
 *		�꥿����					... (D-1)
 *	== TASK1�������㳰�����롼�����2���ܡ�==
 *	10:	������֤Υ����å�
 *		�꥿����
 *	== TASK1��³����==
 *	11:	sus_tsk(TASK2)
 *		sus_tsk(TASK3)
 *		sus_tsk(LOGTASK)
 *	12:	sta_alm(ALM3, 10U)
 *	13:	dly_tsk(50U)
 *	== ALM3 ==
 *	14:	������֤Υ����å�
 *		��sns_tex()��ޤ��			... (F)
 *		iget_tid(&tskid)
 *		iras_tex(TASK1, 0x0004)		... (B-2)
 *		�꥿����
 *	== TASK1�������㳰�����롼�����3���ܡ�==
 *	15:	������֤Υ����å�
 *		�꥿����
 *	== TASK1��³����==
 *	16:	rsm_tsk(TASK2)
 *		rsm_tsk(TASK3)
 *		rsm_tsk(LOGTASK)
 *		dis_dsp()
 *	17:	RAISE_CPU_EXCEPTION
 *	== CPUEXC1 ==
 *	18:	������֤Υ����å�
 *		xsns_xpn(p_excinf)
 *		iras_tex(TASK3, 0x0010)		... (A-2)
 *		iras_tex(TASK4, 0x0010)		... (A-1)
 *		iras_tex(TASK2, 0x0010)		... (C-2)
 *		iras_tex(TASK1, 0x0010)		... (C-1)
 *		�꥿����					... (E-1)
 *	== TASK1�������㳰�����롼�����4���ܡ�==
 *	19:	������֤Υ����å�
 *	20:	ext_tsk()
 *	== TASK2��ͥ���١�10��==
 *	21:	������֤Υ����å�
 *	22:	ena_tex()
 *	== TASK2�������㳰�����롼���� ==
 *	23:	������֤Υ����å�
 *		�꥿����
 *	== TASK2��³����==
 *	24:	sus_tsk(TASK3)
 *	25:	�ƥ��Ƚ�λ
 */

#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_tex2.h"

volatile bool_t	alm1_flag = false;
volatile bool_t	alm2_flag = false;
volatile bool_t	alm3_flag = false;

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(5);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		/*
		 *  �ǥ����ѥå��ػߡ������ͥ���٥ޥ����ѹ����������㳰�������ġ�
		 *  CPU��å�
		 */
		check_point(6);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = ena_tex();
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TMAX_INTPRI, true, true, false);
		break;

	case 0x0002:
		check_point(10);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	case 0x0004:
		check_point(15);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	case 0x0010:
		check_point(19);
		check_state(false, false, TIPM_ENAALL, true, true, true);

		/*
		 *  ��������λ
		 */
		check_point(20);
		ercd = ext_tsk();
		check_point(0);
		break;

	default:
		check_point(0);
		break;
	}
}

void
task1(intptr_t exinf)
{
	ER		ercd;
	T_RTEX	rtex;

	/*
	 *  ������֤Υ����å�
	 */
	check_point(1);
	check_state(false, false, TIPM_ENAALL, false, false, true);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_DIS) != 0);
	check_assert(rtex.pndptn == 0);

	/*
	 *  ���顼��ϥ�ɥ�1��ư���
	 */
	check_point(2);
	ercd = sta_alm(ALM1, 1U);
	check_ercd(ercd, E_OK);

	/*
	 *  ���顼��ϥ�ɥ�1�μ¹Ԥ��Ԥ�
	 */
	while (!(alm1_flag));

	/*
	 *  �������㳰���������
	 */
	check_point(4);
	ercd = ena_tex();
	/* �����ǥ������㳰�����롼����ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  �������㳰��������Υ꥿����ˤ�긵�ξ��֤���äƤ��뤳�Ȥ�
	 *  �����å�
	 */
	check_point(7);
	check_state(false, false, TIPM_ENAALL, false, false, false);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_ENA) != 0);
	check_assert(rtex.pndptn == 0);

	/*
	 *  ���顼��ϥ�ɥ�2��ư���
	 */
	check_point(8);
	ercd = sta_alm(ALM2, 1U);
	check_ercd(ercd, E_OK);

	/*
	 *  ���顼��ϥ�ɥ�2�μ¹Ԥ��Ԥ�
	 */
	while (!(alm2_flag));

	/*
	 *  TASK2��TASK3��ߤ�롥
	 */
	check_point(11);
	ercd = sus_tsk(TASK2);
	check_ercd(ercd, E_OK);
	ercd = sus_tsk(TASK3);
	check_ercd(ercd, E_OK);
	ercd = sus_tsk(LOGTASK);
	check_ercd(ercd, E_OK);

	/*
	 *  ���顼��ϥ�ɥ�3��ư���
	 */
	check_point(12);
	ercd = sta_alm(ALM3, 10U);
	check_ercd(ercd, E_OK);

	/*
	 *  �¹��ٱ�
	 */
	check_point(13);
	ercd = dly_tsk(50U);
	/* ���顼��ϥ�ɥ�3��ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  TASK2��TASK3��Ƴ����롥
	 */
	check_point(16);
	ercd = rsm_tsk(TASK2);
	check_ercd(ercd, E_OK);
	ercd = rsm_tsk(TASK3);
	check_ercd(ercd, E_OK);
	ercd = rsm_tsk(LOGTASK);
	check_ercd(ercd, E_OK);

	/*
	 *  �ǥ����ѥå��ػ�
	 */
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	/*
	 *  CPU�㳰��ȯ��������
	 */
	check_point(17);
	RAISE_CPU_EXCEPTION;

	check_point(0);
}

void
tex_task2(TEXPTN texptn, intptr_t exinf)
{
	switch (texptn) {
	case 0x0011:
		check_point(23);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	default:
		check_point(0);
		break;
	}
}

void
task2(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  ������֤Υ����å�
	 */
	check_point(21);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �������㳰���������
	 */
	check_point(22);
	ercd = ena_tex();
	/* �����ǥ������㳰�����롼����ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  TASK3��ߤ�롥
	 */
	check_point(24);
	ercd = sus_tsk(TASK3);
	check_ercd(ercd, E_OK);

	/*
	 *  �ƥ��Ƚ�λ
	 */
	check_finish(25);
}

void
task3(intptr_t exinf)
{
	check_point(0);
}

void
task4(intptr_t exinf)
{
	check_point(0);
}

void
tex_task4(TEXPTN texptn, intptr_t exinf)
{
	check_point(0);
}

void
alarm1_handler(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  ������֤Υ����å�
	 */
	check_point(3);
	check_state_i(true, false, false, true, true);

	/*
	 *  iras_tex�Υ��顼����
	 */
	ercd = iras_tex(TASK3, 0x0001);
	check_ercd(ercd, E_OBJ);
	ercd = iras_tex(TASK4, 0x0001);
	check_ercd(ercd, E_OBJ);

	/*
	 *  �������㳰�������׵�
	 */
	ercd = iras_tex(TASK2, 0x0001);
	check_ercd(ercd, E_OK);
	ercd = iras_tex(TASK1, 0x0001);
	check_ercd(ercd, E_OK);

	alm1_flag = true;
}

void
alarm2_handler(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  ������֤Υ����å�
	 */
	check_point(9);
	check_state_i(true, false, false, true, false);

	/*
	 *  �������㳰�������׵�
	 */
	ercd = iras_tex(TASK1, 0x0002);
	check_ercd(ercd, E_OK);

	alm2_flag = true;
}

void
alarm3_handler(intptr_t exinf)
{
	ER		ercd;
	ID		tskid;

	check_point(14);
	check_state_i(true, false, false, true, true);
	ercd = iget_tid(&tskid);
	check_ercd(ercd, E_OK);
	check_assert(tskid == TSK_NONE);

	/*
	 *  �������㳰�������׵�
	 */
	ercd = iras_tex(TASK1, 0x0004);
	check_ercd(ercd, E_OK);

	alm3_flag = true;
}

void
cpuexc_handler(void *p_excinf)
{
	ER		ercd;

	/*
	 *  ������֤Υ����å�
	 */
	check_point(18);
	check_state_i(true, false, true, true, false);
	check_assert(xsns_xpn(p_excinf) == false);

	/*
	 *  iras_tex�Υ��顼����
	 */
	ercd = iras_tex(TASK3, 0x0010);
	check_ercd(ercd, E_OBJ);
	ercd = iras_tex(TASK4, 0x0010);
	check_ercd(ercd, E_OBJ);

	/*
	 *  �������㳰�������׵�
	 */
	ercd = iras_tex(TASK2, 0x0010);
	check_ercd(ercd, E_OK);
	ercd = iras_tex(TASK1, 0x0010);
	check_ercd(ercd, E_OK);
}
