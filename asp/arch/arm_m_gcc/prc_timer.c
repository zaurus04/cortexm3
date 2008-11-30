/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: prc_timer.c 1304 2008-08-27 07:28:36Z ertl-honda $
 */

/*
 *  �����ޥɥ饤�С�SYSTIC�ѡ�
 */
#include <sil.h>
#include "kernel_impl.h"
#include "time_event.h"
#include "target_timer.h"

/*
 *  �����ޤε�ư����
 */
void
target_timer_initialize(intptr_t exinf)
{
	CLOCK    cyc;
	uint32_t tmp;

#ifdef SYSTIC_USE_CALIBRATION
	/* CALIBRATION�쥸�������ͤ���� */
	cyc = (sil_rew_mem((void *)SYSTIC_CALIBRATION) & SYSTIC_TENMS) / 10;
#else 
	cyc = TO_CLOCK(TIC_NUME, TIC_DENO) - 1;
#endif /* SYSTIC_USE_CALIBRATION */

	/* ��� */
	tmp = sil_rew_mem((void *)SYSTIC_CONTROL_STATUS);
	tmp &= ~SYSTIC_ENABLE;
	sil_wrw_mem((void *)SYSTIC_CONTROL_STATUS, tmp);

	sil_wrw_mem((void *)SYSTIC_RELOAD_VALUE, cyc);
	sil_wrw_mem((void *)SYSTIC_CURRENT_VALUE, cyc);

	tmp = sil_rew_mem((void *)SYSTIC_CONTROL_STATUS);

#ifdef SYSTIC_USE_STCLK
	/* ��������å��λ��� */
	tmp |= SYSTIC_ENABLE;
#else
	/* �ץ��å�����å��λ��� */
	tmp |= SYSTIC_ENABLE|SYSTIC_CLKSOURCE;
#endif /* SYSTIC_USE_STCLK */

	sil_wrw_mem((void *)SYSTIC_CONTROL_STATUS, tmp);
}

/*
 *  �����ޤ���߽���
 */
void
target_timer_terminate(intptr_t exinf)
{
	/* �����ޤ���� */
	sil_wrw_mem((void*)SYSTIC_CONTROL_STATUS, 0x00);
}

/*
 *  �����޳���ߥϥ�ɥ�
 */
void
target_timer_handler(void)
{
	unsigned int tmp;

	/* probe_int �Τ��ᡤCOUNTFLAG�򥯥ꥢ */
	tmp = sil_rew_mem((void *)SYSTIC_CONTROL_STATUS);

	i_begin_int(INTNO_TIMER);
	signal_time();                    /* ������ƥ��å��ζ��� */
	i_end_int(INTNO_TIMER);
}
