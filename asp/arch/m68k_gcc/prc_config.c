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
 *  @(#) $Id: prc_config.c 759 2008-03-07 23:01:20Z hiro $
 */

/*
 *		�ץ��å���¸�⥸�塼���M68040�ѡ�
 */

#include "kernel_impl.h"
#include "check.h"
#include "task.h"

/*
 *  CPU��å��ե饰�¸��Τ�����ѿ�
 */
volatile bool_t		lock_flag;		/* CPU��å��ե饰���ͤ��ݻ������ѿ� */
volatile uint16_t	saved_iipm;		/* �����ͥ���٥ޥ�������¸�����ѿ� */

/*
 *  �ץ��å���¸�ν����
 */
void
prc_initialize(void)
{
	/*
	 *  CPU��å��ե饰�¸��Τ�����ѿ��ν����
	 */
	lock_flag = true;
	saved_iipm = IIPM_ENAALL;

	/*
	 *  �㳰�٥����ơ��֥�ν����
	 */
#ifdef EXCVT_KERNEL
	memcpy(EXCVT_KERNEL, EXCVT_ORIG, EXCVT_LEN);
	set_vbr(EXCVT_KERNEL);
#endif /* EXCVT_KERNEL */
}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
prc_terminate(void)
{
#ifdef EXCVT_KERNEL
	set_vbr(EXCVT_ORIG);
#endif /* EXCVT_KERNEL */
}

/*
 *  CPU�㳰��ȯ�������Υ�����
 *
 *  CPU�㳰�ϥ�ɥ���椫�顤CPU�㳰����ݥ��󥿡�p_excinf�ˤ�����Ȥ�
 *  �ƸƤӽФ����Ȥǡ�CPU�㳰��ȯ�������򥷥��ƥ���˽��Ϥ��롥
 */
#ifdef SUPPORT_XLOG_SYS

void
xlog_sys(void *p_excinf)
{
	char	*excsp = (char *) p_excinf;
	uint_t	format;

	syslog_0(LOG_ERROR, "CPU Exception Information:");
	syslog_4(LOG_ERROR, "SR = %04x (M = %d, S = %d, IPM = %d)",
				*((uint16_t *) excsp),
				(*((uint16_t *) excsp) & 0x1000U) >> 12,
				(*((uint16_t *) excsp) & 0x2000U) >> 13,
				(*((uint16_t *) excsp) & 0x0700U) >> 8);
	syslog_1(LOG_ERROR, "PC = %08x", *((uint32_t *)(excsp + 2)));
	format = (*((uint16_t *)(excsp + 6)) & 0xf000U) >> 12;
	syslog_2(LOG_ERROR, "Format = %d, Vector Offset = %03x",
				format, (*((uint16_t *)(excsp + 6)) & 0x0fffU));
	if (format >= 2U) {
		syslog_1(LOG_ERROR, "ADR = %08x", *((uint32_t *)(excsp + 8)));
	}
}

#endif /* SUPPORT_XLOG_SYS */
