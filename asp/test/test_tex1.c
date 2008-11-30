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
 *  @(#) $Id: test_tex1.c 818 2008-03-18 12:56:15Z hiro $
 */

/* 
 *		�������㳰�����˴ؤ���ƥ���(1)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  ���������饿�����㳰�����롼�����ư�������������Ū�˥ƥ��Ȥ��롥
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *	(A) ras_tex��ref_tex�Υ��顼����
 *		(A-1) �оݥ��������ٻ߾���
 *		(A-2) �оݥ������Υ������㳰�����롼�����������Ƥ��ʤ�
 *	(B) dis_tex��ena_tex�Υ��顼����
 *		(B-1) ���������Υ������㳰�����롼�����������Ƥ��ʤ�
 *	(C) ras_tex���������
 *		(C-1) �оݥ������������������ĥ������㳰�������Ĥǡ������˵�ư
 *		(C-2) �оݥ����������������Ǥʤ�
 *		(C-3) �оݥ��������������������������㳰�����ػ�
 *	(D) ena_tex���������
 *		(D-1) �������㳰�����׵᤬���ꡤ�����˵�ư
 *		(D-2) �������㳰�����׵᤬�ʤ�
 *	(E) �������ǥ����ѥå���ˤ�뵯ư
 *		(E-1) �ǥ����ѥå���Υ��������������㳰���Ĥǥ������㳰������
 *			  �ᤢ��
 *	(F) �������㳰�����롼���󤫤�Υ꥿����ˤ�뵯ư��Ϣ³��ư��
 *	(G) �������㳰�����롼���󤫤�������ˤ���������
 *		(G-1) ����������äƤ����
 *		(G-2) �������㳰�����롼����Ϣ³��ư������
 *	(H) �������㳰�����롼�����¿�ŵ�ư
 *	(I) �������㳰�����롼���󤫤�������Υ������ڴ���
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: �ᥤ��Υ������������������Ф��ƥ������㳰�������׵᤹��
 *	TASK2: ¾���������Ф��ƥ������㳰�������׵᤹���оݥ�����
 *	TASK3: �������㳰�����롼�����������Ƥ��ʤ�������
 *	TASK4: �ٻ߾��֤Υ�����
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١�10��==
 *	1:	������֤Υ����å�
 *		ref_tex(TSK_SELF, &rtex)
 *		ras_tex(TASK3, 0x0001)		... (A-2)
 *		ras_tex(TASK4, 0x0001)		... (A-1)
 *		ref_tex(TASK3, &rtex)		... (A-2)
 *		ref_tex(TASK4, &rtex)		... (A-1)
 *	2:	ena_tex()					... (D-2)
 *		ref_tex(TSK_SELF, &rtex)
 *	3:	ras_tex(TSK_SELF, 0x0001)	... (C-1)
 *	== TASK1�������㳰�����롼�����1���ܡ�==
 *	4:	������֤Υ����å�
 *	5:	dis_dsp() ... 4�Ĥξ��֤򤽤줾���Ѳ�������
 *		chg_ipm(TMAX_INTPRI)
 *		ena_tex()
 *		loc_cpu()
 *		�꥿����
 *	== TASK1��³����==
 *	6:	��äƤ������֤Υ����å�	... (G-1)
 *	7:	dis_dsp() ... 3�Ĥξ��֤򤽤줾���Ѳ�������
 *		chg_ipm(TMIN_INTPRI)
 *		dis_tex()
 *	8:	ras_tex(TASK1, 0x0002)		... (C-3)
 *		ref_tex(TSK_SELF, &rtex)
 *	9:	ena_tex()					... (D-1)
 *	== TASK1�������㳰�����롼�����2���ܡ�==
 *	10:	������֤Υ����å�
 *	11:	ras_tex(TASK1, 0x0001)		... (C-3)
 *		ras_tex(TASK1, 0x0002)		... (C-3)
 *	12:	ena_dsp() ... 3�Ĥξ��֤򤽤줾���Ѳ�������
 *		chg_ipm(TMAX_INTPRI)
 *		loc_cpu()
 *		�꥿����					... (F)
 *	== TASK1�������㳰�����롼�����3���ܡ�==
 *	13:	������֤Υ����å�
 *	14:	ena_dsp() ... 3�Ĥξ��֤򤽤줾���Ѳ�������
 *		chg_ipm(TMAX_INTPRI)
 *		ena_tex()
 *	15: ras_tex(TSK_SELF, 0x0004)	... (H)
 *	== TASK1�������㳰�����롼�����4���ܡ�==
 *	16:	������֤Υ����å�
 *	17:	dis_dsp() ... 3�Ĥξ��֤򤽤줾���Ѳ�������
 *		chg_ipm(TIPM_ENAALL)
 *		loc_cpu()
 *		�꥿����
 *	== TASK1�������㳰�����롼�����3����³����==
 *	18:	��äƤ������֤Υ����å�	... (G-2)
 *		�꥿����
 *	== TASK1��³����==
 *	19:	��äƤ������֤Υ����å�	... (G-1)
 *	20: ena_dsp()
 *		chg_ipm(TIPM_ENAALL)
 *		rot_rdq(TPRI_SELF)
 *	== TASK2��ͥ���١�10��	==
 *	21:	������֤Υ����å�
 *	22:	ena_tex()
 *		rot_rdq(TPRI_SELF)
 *	== TASK3��ͥ���١�10��	==
 *	23:	������֤Υ����å�
 *	24:	ena_tex()
 *	25:	dis_tex()					... (B-1)
 *		ext_tsk()					... (B-1)
 *	== TASK1��³����==
 *	26: ras_tex(TASK2, 0x0001)		... (C-2)
 *		ref_tex(TASK2, &rtex)
 *	27:	rot_rdq(TPRI_SELF)			... (E-1)
 *	== TASK2�������㳰�����롼�����1���ܡ�==
 *	28:	������֤Υ����å�
 *		�꥿����
 *	== TASK2��³����==
 *	29: ras_tex(TSK_SELF, 0x0002)
 *	== TASK2�������㳰�����롼�����2���ܡ�==
 *	30:	������֤Υ����å�
 *	31:	dis_dsp
 *		rot_rdq(TPRI_SELF)
 *	32:	�꥿����					... (I)
 *	== TASK1��³����==
 *	33:	�꥿����ʥ�������λ��
 *	== TASK2��³����==
 *	34:	�ƥ��Ƚ�λ
 */

#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_tex1.h"

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(4);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		/*
		 *  �ǥ����ѥå��ػߡ������ͥ���٥ޥ����ѹ����������㳰��������
		 */
		check_point(5);
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
		check_state(false, false, TMIN_INTPRI, true, true, true);

		/*
		 *  �������㳰�������׵�
		 */
		check_point(11);
		ercd = ras_tex(TSK_SELF, 0x0001);
		check_ercd(ercd, E_OK);
		ercd = ras_tex(TSK_SELF, 0x0002);
		check_ercd(ercd, E_OK);

		/*
		 *  �ǥ����ѥå����ġ������ͥ���٥ޥ����ѹ���CPU��å�
		 */
		check_point(12);
		ercd = ena_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TMAX_INTPRI, false, true, true);
		break;

	case 0x0003:
		check_point(13);
		check_state(false, false, TMIN_INTPRI, true, true, true);

		/*
		 *  �ǥ����ѥå����ġ������ͥ���٥ޥ����ѹ����������㳰����
		 */
		check_point(14);
		ercd = ena_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TMAX_INTPRI);
		check_ercd(ercd, E_OK);
		ercd = ena_tex();
		check_ercd(ercd, E_OK);
		check_state(false, false, TMAX_INTPRI, false, true, false);

		/*
		 *  �������㳰�������׵�
		 */
		check_point(15);
		ercd = ras_tex(TSK_SELF, 0x0004);
		/* �����ǥ������㳰�����롼����ư��� */
		check_ercd(ercd, E_OK);

		/*
		 *  �������㳰��������Υ꥿����ˤ�긵�ξ��֤���äƤ��뤳��
		 *  ������å�
		 */
		check_point(18);
		check_state(false, false, TMAX_INTPRI, false, true, false);
		break;

	case 0x0004:
		check_point(16);
		check_state(false, false, TMAX_INTPRI, false, true, true);

		/*
		 *  �ǥ����ѥå��ػߡ������ͥ���٥ޥ����ѹ���CPU��å�
		 */
		check_point(17);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TIPM_ENAALL);
		check_ercd(ercd, E_OK);
		ercd = loc_cpu();
		check_ercd(ercd, E_OK);
		check_state(false, true, TIPM_ENAALL, true, true, true);
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
	 *  ras_tex�Υ��顼����
	 */
	ercd = ras_tex(TASK3, 0x0001);
	check_ercd(ercd, E_OBJ);
	ercd = ras_tex(TASK4, 0x0001);
	check_ercd(ercd, E_OBJ);

	/*
	 *  ref_tex�Υ��顼����
	 */
	ercd = ref_tex(TASK3, &rtex);
	check_ercd(ercd, E_OBJ);
	ercd = ref_tex(TASK4, &rtex);
	check_ercd(ercd, E_OBJ);

	/*
	 *  �������㳰�����ε���
	 */
	check_point(2);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, false);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_ENA) != 0);
	check_assert(rtex.pndptn == 0);

	/*
	 *  �������㳰�������׵�
	 */
	check_point(3);
	ercd = ras_tex(TSK_SELF, 0x0001);
	/* �����ǥ������㳰�����롼����ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  �������㳰��������Υ꥿����ˤ�긵�ξ��֤���äƤ��뤳�Ȥ�
	 *  �����å�
	 */
	check_point(6);
	check_state(false, false, TIPM_ENAALL, false, false, false);

	/*
	 *  �ǥ����ѥå��ػߡ������ͥ���٥ޥ����ѹ����������㳰�����ػ�
	 */
	check_point(7);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);
	ercd = chg_ipm(TMIN_INTPRI);
	check_ercd(ercd, E_OK);
	ercd = dis_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMIN_INTPRI, true, true, true);

	/*
	 *  �������㳰�������׵�
	 */
	check_point(8);
	ercd = ras_tex(TASK1, 0x0002);
	check_ercd(ercd, E_OK);
	ercd = ref_tex(TSK_SELF, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_DIS) != 0);
	check_assert(rtex.pndptn == 0x0002);

	/*
	 *  �������㳰���������
	 */
	check_point(9);
	ercd = ena_tex();
	/* �����ǥ������㳰�����롼����ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  �������㳰��������Υ꥿����ˤ�긵�ξ��֤���äƤ��뤳�Ȥ�
	 *  �����å�
	 */
	check_point(19);
	check_state(false, false, TMIN_INTPRI, true, true, false);

	/*
	 *  ������2���ڤ괹����
	 */
	check_point(20);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);
	ercd = chg_ipm(TIPM_ENAALL);
	check_ercd(ercd, E_OK);
	ercd = rot_rdq(TPRI_SELF);
	/* ������¾�Υ�������ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  ������2���Ф��ƥ������㳰�������׵�
	 */
	check_point(26);
	ercd = ras_tex(TASK2, 0x0001);
	check_ercd(ercd, E_OK);
	ercd = ref_tex(TASK2, &rtex);
	check_ercd(ercd, E_OK);
	check_assert((rtex.texstat & TTEX_ENA) != 0);
	check_assert(rtex.pndptn == 0x0001);

	/*
	 *  ������2���ڤ괹����
	 */
	check_point(27);
	ercd = rot_rdq(TPRI_SELF);
	/* ������¾�Υ�������ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  ��������λ
	 */
	check_point(33);
}

void
tex_task2(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(28);
		check_state(false, false, TIPM_ENAALL, false, false, true);
		break;

	case 0x0002:
		check_point(30);
		check_state(false, false, TIPM_ENAALL, false, false, true);

		/*
		 *  �ǥ����ѥå���ػߤ��ơ��������ڴ������׵᤹�롥
		 */
		check_point(31);
		ercd = dis_dsp();
		check_ercd(ercd, E_OK);
		ercd = rot_rdq(TPRI_SELF);
		check_ercd(ercd, E_OK);

		/*
		 *  �������㳰�����롼���󤫤�Υ꥿����ǡ��������ڴ�����ȯ��
		 *  ���롥
		 */
		check_point(32);
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
	 *  �������㳰�����ε���
	 */
	check_point(22);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, false);

	/*
	 *  ������3���ڤ괹����
	 */
	ercd = rot_rdq(TPRI_SELF);
	/* ������¾�Υ�������ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  �������㳰�������׵�
	 */
	check_point(29);
	ercd = ras_tex(TSK_SELF, 0x0002);
	/* �����ǥ������㳰�����롼����ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  �ƥ��Ƚ�λ
	 */
	check_finish(34);
}

void
task3(intptr_t exinf)
{
	ER		ercd;

	/*
	 *  ������֤Υ����å�
	 */
	check_point(23);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �������㳰�����ε���
	 */
	check_point(24);
	ercd = ena_tex();
	check_ercd(ercd, E_OBJ);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �������㳰�����ζػ�
	 */
	check_point(25);
	ercd = dis_tex();
	check_ercd(ercd, E_OBJ);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  ��������λ
	 */
	ercd = ext_tsk();
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
