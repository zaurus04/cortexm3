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
 *  @(#) $Id: target_timer.h 889 2008-04-11 11:17:35Z hiro $
 */

/*
 *		�����ޥɥ饤�С�DVE68K/40�ѡ�
 */

#ifndef TOPPERS_TARGET_TIMER_H
#define TOPPERS_TARGET_TIMER_H

#include <sil.h>
#include "dve68k.h"

/*
 *  �����޳���ߥϥ�ɥ���Ͽ�Τ�������
 */
#define INHNO_TIMER		TINHNO_TT0		/* ����ߥϥ�ɥ��ֹ� */
#define INTNO_TIMER		TINTNO_TT0		/* ������ֹ� */
#define INTPRI_TIMER	TIRQ_LEVEL4		/* �����ͥ���� */
#define INTATR_TIMER	TA_EDGE			/* �����°�� */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef uint32_t	CLOCK;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *
 *  DVE68K/40�Ǥϡ������ޤ�1������˥�����ȥ��åפ��롥
 */
#define TIMER_CLOCK				1000U
#define TO_CLOCK(nume, deno)	((CLOCK)(TIMER_CLOCK * (nume) / (deno)))
#define TO_USEC(clock)			(((SYSUTM) clock) * 1000U / TIMER_CLOCK)

/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define MAX_CLOCK		((CLOCK) 0xffffffU)

/*
 *  ��������ߤޤǤλ��֡�nsecñ�̡�
 *
 *  �ͤ˺���Ϥʤ���
 */
#define TIMER_STOP_DELAY	200U

/*
 *  �쥸������������
 */
#define CSR12_START		0x80000000U		/* ������ư�� */
#define CSR12_STOP		0x00000000U		/* ��������� */

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
extern void	target_timer_initialize(intptr_t exinf);

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
extern void	target_timer_terminate(intptr_t exinf);

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
target_timer_get_current(void)
{
	CLOCK		clk;
	uint32_t	saved_csr12;
	SIL_PRE_LOC;

	/*
	 *  �����ޤ�ư�����Ū����ߤ����������ͤ��ɤ߽Ф��������ޤ�ư��
	 *  ����Ū����ߤ�����ȡ������ƥ���郎����뤿���˾�ޤ����ʤ�
	 *  ����DVE68K/40�Υϡ��ɥ�����Ū������Ǥ��ꡤ���򤨤ʤ��������
	 *  �Ǿ����ޤ��뤿��ˡ�����ߥ�å����֤Ȥ��롥
	 */
	SIL_LOC_INT();
	saved_csr12 = dga_read((void *) TADR_DGA_CSR12);
	dga_write((void *) TADR_DGA_CSR12, CSR12_STOP);
	sil_dly_nse(TIMER_STOP_DELAY);
	clk = dga_read((void *) TADR_DGA_CSR13) & 0x00ffffffU;
	dga_write((void *) TADR_DGA_CSR12, saved_csr12);
	SIL_UNL_INT();
	return(clk);
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline bool_t
target_timer_probe_int(void)
{
	return(x_probe_int(INTNO_TIMER));
}

/*
 *  �����޳���ߥϥ�ɥ�
 */
extern void	target_timer_handler(void);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_TIMER_H */
