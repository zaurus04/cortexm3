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
 *  @(#) $Id: target_config.c 885 2008-04-11 11:14:50Z hiro $
 */

/*
 *		�������åȰ�¸�⥸�塼���DVE68K/40�ѡ�
 */

#include "kernel_impl.h"
#include <sil.h>

/*
 *  �ץ��å����̤Τ�����ѿ��ʥޥ���ץ��å��б���
 */
uint_t	board_id;			/* �ܡ���ID */
void	*board_addr;		/* ������������Ƭ���ɥ쥹 */

/*
 *  �������åȰ�¸�ν����
 */
void
target_initialize(void)
{
	/*
	 *  �ץ��å���¸�ν����
	 */
	prc_initialize();

	/*
	 *  �ץ��å����̤Τ�����ѿ��ν����
	 */
	board_id = ((uint_t)(sil_rew_mem((void *) TADR_BOARD_REG0)) & 0x1fU);
	board_addr = (void *)(board_id << 24);

	/*
	 *  ����ߴ�Ϣ�ν����
	 *
	 *  �����°�������ꤵ��Ƥ��뤫��Ƚ�̤��뤿����ѿ����������롥
	 *  �ޤ������٤Ƥγ���ߤ�ޥ��������ꥢ��������ߥ٥��ȥ�����ꤹ
	 *  �롥
	 */
	dga_write((void *) TADR_DGA_CSR21, 0U);
	dga_write((void *) TADR_DGA_CSR23, ~0U);
	dga_write((void *) TADR_DGA_CSR19, (TVEC_G0I << 24) | (TVEC_G1I << 16)
										| (TVEC_SWI << 8) | TVEC_SPRI);

	/*
	 *  ���ܡ��ȳ���ߤ������NMI��
	 *
	 *  ���ܡ��ȳ���ߤ򥨥å��ȥꥬ������ߥ�٥��NMI�����ꤷ���ޥ���
	 *  �������롥
	 */
	x_config_int(TINTNO_ABT, TA_EDGE, TIRQ_NMI);

	/*
	 *  �����ΰ������
	 *
	 *  ����������VME�Х���Ǥ���Ƭ���ɥ쥹�ȥ�������16MB�ˤ�����
	 *  ������������դ���褦�����ꤹ�롥�ޤ���VME�Х������ĥ���ɥ쥹
	 *  ��������������դ���褦�ˤ����ꤹ�롥
	 */
	dga_write((void *) TADR_DGA_CSR4, (uint32_t) board_addr | 0x00ffU);
	dga_write((void *) TADR_DGA_CSR5, 0x0000012fU);

	/*
	 *  ���󥿥ե������쥸������IFR�ˤ�����
	 *
	 *  ���󥿥ե������쥸�����Υ١������ɥ쥹�����ꤹ�롥�ޤ�������
	 *  �ե������쥸����0�Υ����ӥ��ꥯ�����ȥե饰�򥯥ꥢ�����󥿥ե���
	 *  ���쥸����3�˥ܡ��ɤ�ID�ֹ�����ꡥ
	 */
	dga_write((void *) TADR_DGA_CSR3, (board_id << 4) | 0x3U);
	dga_write((void *) TADR_DGA_IFR0, 0x80000000U);
	dga_write((void *) TADR_DGA_IFR3, board_id);

	/*
	 *  �饦��ɥ�ӥ�⡼�ɤ�����ʥޥ���ץ��å��б���
	 */
	dga_write((void *) TADR_DGA_CSR1,
						(dga_read((void *) TADR_DGA_CSR1) & 0xffeffcffU)
									| (1U << 20) | ((board_id % 4) << 8));
}

/*
 *  �������åȰ�¸�ν�λ����
 */
void
target_exit(void)
{
	/*
	 *  �ץ��å���¸�ν�λ����
	 */
	prc_terminate();

	/*
	 *  ���٤Ƥγ���ߤ�ޥ��������ꥢ���롥
	 */
	dga_write((void *) TADR_DGA_CSR21, 0U);
	dga_write((void *) TADR_DGA_CSR23, ~0U);

	/*
	 *  ��ȯ�Ķ���¸�ν�λ����
	 */
	dve68k_exit();
}

/*
 *  �����ƥ�������٥���ϤΤ����ʸ������
 */
void
target_fput_log(char_t c)
{
	if (c == '\n') {
		dve68k_putc('\r');
	}
	dve68k_putc(c);
}

/*
 *  ������׵�饤���°��������
 *
 *  ASP�����ͥ�Ǥ����Ѥ����ꤷ�ơ��ѥ�᡼�����顼�ϥ����������ǥ�����
 *  �����Ƥ��롥cfg_int�����ӥ���������ߤ�����ˤϡ����顼���֤��褦
 *  �ˤ��٤��Ǥ�����
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	uint32_t	bitpat = DGA_INT_BITPAT(intno);

	assert(VALID_INTNO_CFGINT(intno));
	assert(TIRQ_NMI <= intpri && intpri <= TIRQ_LEVEL1);

	/*
	 *  ����ߤΥޥ���
	 *
	 *  ����ߤ�����դ����ޤޡ���٥�ȥꥬ�����å��ȥꥬ������䡤��
	 *  ����ͥ���٤������Ԥ��Τϴ��ʤ��ᡤ�����°���ˤ�����餺��
	 *  ��ö�ޥ������롥
	 */
	(void) x_disable_int(intno);

	/*
	 *  ��٥�ȥꥬ�����å��ȥꥬ������
	 */
	if ((bitpat & DGA_INT_TRG_CONF) != 0U) {
		/*
		 *  ������ˤ�����Ǥ�����
		 */
		if ((intatr & TA_EDGE) != 0U) {
			dga_bit_or((void *) TADR_DGA_CSR18, (1U << (24 - (intno))));
			x_clear_int(intno);
		}
		else {
			dga_bit_and((void *) TADR_DGA_CSR18, ~(1U << (24 - (intno))));
		}
	}
	else if ((bitpat & DGA_INT_TRG_EDGE) != 0U) {
		/*
		 *  ���å��ȥꥬ�˸��ꤵ��Ƥ�����
		 */
		assert((intatr & TA_EDGE) != 0U);
		x_clear_int(intno);
	}
	else {
		/*
		 *  ��٥�ȥꥬ�˸��ꤵ��Ƥ�����
		 */
		assert((intatr & TA_EDGE) == 0U);
	}

	/*
	 *  �����ͥ���٤�����
	 */
	dga_set_ilv((void *)(TADR_DGA_CSR24 + (intno - 1) / 8 * 4),
				(uint_t)(((32 - intno) % 8) * 4), (uint_t)(7 + intpri));

	/*
	 *  ����ߤΥޥ��������ɬ�פʾ���
 	 */
	if ((intatr & TA_ENAINT) != 0U) {
		(void) x_enable_int(intno);
	}
}
