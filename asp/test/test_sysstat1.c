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
 *  @(#) $Id: test_sysstat1.c 818 2008-03-18 12:56:15Z hiro $
 */

/* 
 *		�����ƥ���֤˴ؤ���ƥ���(1)
 *
 *  �ƥ��ȥ������󥹡�
 *
 *	== TASK1��ͥ���١�10��==
 *	1:	������֤Υ����å�
 *	2:	loc_cpu() ... �����ƥ���֤��������Ѳ�������
 *	3:	chg_ipm(TMAX_INTPRI)
 *	4:	unl_cpu()
 *	5:	dis_dsp()
 *	6:	ena_tex()
 *	7:	chg_ipm(TIPM_ENAALL)
 *	8:	ena_dsp()
 *	9:	dis_tex()
 *	10:	dis_dsp() ... �������㳰�����롼�����ƤӽФ�����
 *		chg_ipm(TMIN_INTPRI)
 *		ena_tex()
 *	11:	ras_tex(TSK_SELF, 0x0001)
 *	== TASK1�������㳰�����롼�����1���ܡ�==
 *	12:	������֤Υ����å�
 *	13:	ena_dsp() ... 3�Ĥξ��֤��Ѳ��������꥿����Ǹ��ˤ�ɤ뤫Ĵ�٤�
 *		chg_ipm(TIPM_ENAALL)
 *		ena_tex()
 *		�꥿����
 *	== TASK1��³����==
 *	14:	��äƤ������֤Υ����å�
 *	15:	loc_cpu() ... CPU��å����֤Τޤޥ�������λ������
 *	16:	�꥿����ʡ᥿������λ��
 *	== TASK2��ͥ���١�10��	==
 *	17:	������֤Υ����å�
 *	18:	��λ
 */

#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_sysstat1.h"

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	ER		ercd;

	switch (texptn) {
	case 0x0001:
		check_point(12);
		check_state(false, false, TMIN_INTPRI, true, true, true);

		/*
		 *  �ǥ����ѥå����ġ������ͥ���٥ޥ����ѹ����������㳰��������
		 */
		check_point(13);
		ercd = ena_dsp();
		check_ercd(ercd, E_OK);
		ercd = chg_ipm(TIPM_ENAALL);
		check_ercd(ercd, E_OK);
		ercd = ena_tex();
		check_ercd(ercd, E_OK);
		check_state(false, false, TIPM_ENAALL, false, false, false);
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

	/*
	 *  ������֤Υ����å�
	 */
	check_point(1);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  CPU��å����֤Υ����å�
	 */
	check_point(2);
	ercd = loc_cpu();
	check_ercd(ercd, E_OK);
	check_state(false, true, TIPM_ENAALL, false, true, true);

	/*
	 *  �����ͥ���٥ޥ����ѹ��Υ����å�
	 */
	check_point(3);
	ercd = chg_ipm(TMAX_INTPRI);
	check_ercd(ercd, E_OK);
	check_state(false, true, TMAX_INTPRI, false, true, true);

	/*
	 *  CPU��å�����Υ����å�
	 */
	check_point(4);
	ercd = unl_cpu();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMAX_INTPRI, false, true, true);

	/*
	 *  �ǥ����ѥå��ػߤΥ����å�
	 */
	check_point(5);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMAX_INTPRI, true, true, true);

	/*
	 *  �������㳰�������ĤΥ����å�
	 */
	check_point(6);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMAX_INTPRI, true, true, false);

	/*
	 *  �����ͥ���٥ޥ���������Υ����å�
	 */
	check_point(7);
	ercd = chg_ipm(TIPM_ENAALL);
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, true, true, false);

	/*
	 *  �ǥ����ѥå����ĤΥ����å�
	 */
	check_point(8);
	ercd = ena_dsp();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, false);

	/*
	 *  �������㳰�����ػߤΥ����å�
	 */
	check_point(9);
	ercd = dis_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	/*
	 *  �ǥ����ѥå��ػߡ������ͥ���٥ޥ����ѹ����������㳰��������
	 */
	check_point(10);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);
	ercd = chg_ipm(TMIN_INTPRI);
	check_ercd(ercd, E_OK);
	ercd = ena_tex();
	check_ercd(ercd, E_OK);
	check_state(false, false, TMIN_INTPRI, true, true, false);

	/*
	 *  �������㳰�������׵�
	 */
	check_point(11);
	ercd = ras_tex(TSK_SELF, 0x0001);
	/* �����ǥ������㳰�����롼����ư��� */
	check_ercd(ercd, E_OK);

	/*
	 *  �������㳰��������Υ꥿����ˤ�긵�ξ��֤���äƤ��뤳�Ȥ�
	 *  �����å�
	 */
	check_point(14);
	check_state(false, false, TMIN_INTPRI, true, true, false);

	/*
	 *  CPU��å����֤�
	 */
	check_point(15);
	ercd = loc_cpu();
	check_ercd(ercd, E_OK);

	/*
	 *  ���Τޤޥ�������λ
	 */
	check_point(16);
}

void
task2(intptr_t exinf)
{
	/*
	 *  ������֤Υ����å�
	 */
	check_point(17);
	check_state(false, false, TIPM_ENAALL, false, false, true);

	check_finish(18);
}
