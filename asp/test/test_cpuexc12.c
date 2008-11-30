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
 *  @(#) $Id: test_cpuexc12.c 818 2008-03-18 12:56:15Z hiro $
 */

/* 
 *		CPU�㳰�����Υƥ���(12)
 *
 * �ڥƥ��Ȥ���Ū��
 *
 *  �����ͥ���٥ޥ�����TIPM_ENAALL���ǥ����ѥå��ػ߾��֡��������㳰��
 *  �߾��֤�ȯ������CPU�㳰�ˤ����륷���ƥ���֤Υƥ��ȡ�
 *
 * �ڥƥ��ȹ��ܡ�
 *
 *  ������⡤�����ͥ���٥ޥ�����TIPM_ENAALL���ǥ����ѥå��ػ߾��֡���
 *  �����㳰�ػ߾��֤�ȯ������CPU�㳰�ˤ����ơ�
 *
 *	(A) CPU�㳰�ϥ�ɥ�¹Գ��ϻ���CPU��å��ե饰���Ѳ����ʤ�����
 *	(B) CPU�㳰�ϥ�ɥ�¹Գ��ϻ��˳����ͥ���٥ޥ������Ѳ����ʤ�����
 *		��CPU�㳰�ϥ�ɥ���ǳ����ͥ���٥ޥ������ɤ�ʤ����ᡤ�ƥ��Ȥ�
 *		���ʤ���
 *	(C) CPU�㳰�ϥ�ɥ�¹Գ��ϻ��˥ǥ����ѥå��ػߥե饰���Ѳ����ʤ�����
 *	(D) CPU�㳰�ϥ�ɥ�¹Գ��ϻ��˥������㳰�����ػߥե饰���Ѳ����ʤ�����
 *	(E) CPU�㳰�ϥ�ɥ�꥿�������CPU��å��ե饰��������뤳��
 *		��CPU�㳰�ϥ�ɥ餫��꥿����Ǥ�����Τߥƥ��Ȥ��롥
 *	(F) CPU�㳰�ϥ�ɥ�꥿������˳����ͥ���٥ޥ�����������뤳��
 *		��CPU�㳰�ϥ�ɥ餫��꥿����Ǥ�����Τߥƥ��Ȥ��롥
 *	(G) CPU�㳰�ϥ�ɥ�꥿������˥ǥ����ѥå��ػߥե饰���Ѳ����ʤ�����
 *		��CPU�㳰�ϥ�ɥ餫��꥿����Ǥ�����Τߥƥ��Ȥ��롥
 *	(H) CPU�㳰�ϥ�ɥ�꥿������˥������㳰�����ػߥե饰���Ѳ����ʤ�����
 *		��CPU�㳰�ϥ�ɥ餫��꥿����Ǥ�����Τߥƥ��Ȥ��롥
 *	(I) xsns_xpn��true���֤�����
 *	(J) xsns_dpn��true���֤�����
 *
 * �ڻ��ѥ꥽������
 *
 *	TASK1: TA_ACT����ͥ���١��������㳰�����롼������Ͽ
 *	CPUEXC1: TA_NULL
 *
 * �ڥƥ��ȥ������󥹡�
 *
 *	== TASK1����ͥ���١�==
 *	1:	���֤Υ����å�
 *		dis_dsp()
 *	2:	���֤Υ����å�
 *		RAISE_CPU_EXCEPTION
 *	== CPUEXC1 ==
 *	3:	���֤Υ����å�				... (A),(C),(D)
 *		xsns_xpn() == true			... (I)
 *		xsns_dpn() == true			... (J)
 *	4:	CPU�㳰�ϥ�ɥ餫��꥿����Ǥ��ʤ����ϡ������ǽ�λ
 *	4:	iloc_cpu()
 *		�꥿����
 *	== TASK1��³����==
 *	5:	���֤Υ����å�				... (E)(F)(G)(H)
 *	6:	�ƥ��Ƚ�λ
 */

#include <kernel.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "test_lib.h"
#include "test_cpuexc.h"

void
task1(intptr_t exinf)
{
	ER		ercd;

	check_point(1);
	check_state(false, false, TIPM_ENAALL, false, false, true);
	ercd = dis_dsp();
	check_ercd(ercd, E_OK);

	check_point(2);
	check_state(false, false, TIPM_ENAALL, true, true, true);
	RAISE_CPU_EXCEPTION;

	check_point(5);
	check_state(false, false, TIPM_ENAALL, true, true, true);

	check_finish(6);
}

void
tex_task1(TEXPTN texptn, intptr_t exinf)
{
	check_point(0);
}

void
task2(intptr_t exinf)
{
	check_point(0);
}

void
alarm1_handler(intptr_t exinf)
{
	check_point(0);
}

void
cpuexc_handler(void *p_excinf)
{
	ER		ercd;

	check_point(3);
	check_state_i(true, false, true, true, true);
	check_assert(xsns_xpn(p_excinf) == true);
	check_assert(xsns_dpn(p_excinf) == true);

#ifdef CANNOT_RETURN_CPUEXC
	check_finish(4);
#endif /* CANNOT_RETURN_CPUEXC */

	check_point(4);
	ercd = iloc_cpu();
	check_ercd(ercd, E_OK);
}
