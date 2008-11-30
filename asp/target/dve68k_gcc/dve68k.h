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
 *  @(#) $Id: dve68k.h 817 2008-03-18 01:33:12Z hiro $
 */

/*
 *		DVE-68K/40 CPU�ܡ��ɤΥϡ��ɥ������񸻤����
 */

#ifndef TOPPERS_DVE68K_H
#define TOPPERS_DVE68K_H

#include <sil.h>

/*
 *  ������ֹ��intno�ˤ����
 */
#define TINTNO_ACF		1U			/* ACFAIL����� */
#define TINTNO_ABT		2U			/* ���ܡ��ȳ���� */
#define TINTNO_SF		3U			/* SYSFAIL����� */
#define TINTNO_BER		4U			/* �Х����顼����� */
#define TINTNO_IAK		5U			/* IAK����� */
#define TINTNO_SRQ		6U			/* SRQ����� */
#define TINTNO_SAK		7U			/* SAK����� */
#define TINTNO_GP7		9U			/* GP7����� */
#define TINTNO_DMA		10U			/* DMA����� */
#define TINTNO_TT1		11U			/* ������1����� */
#define TINTNO_TT0		12U			/* ������0����� */
#define TINTNO_GP3		13U			/* �ե�å���������� */
#define TINTNO_GP2		14U			/* SCSI����� */
#define TINTNO_GP1		15U			/* Ethernet����� */
#define TINTNO_GP0		16U			/* ���ꥢ��I/O����� */
#define TINTNO_SWI7		17U			/* ���եȥ����������7 */
#define TINTNO_SWI6		18U			/* ���եȥ����������6 */
#define TINTNO_SWI5		19U			/* ���եȥ����������5 */
#define TINTNO_SWI4		20U			/* ���եȥ����������4 */
#define TINTNO_SWI3		21U			/* ���եȥ����������3 */
#define TINTNO_SWI2		22U			/* ���եȥ����������2 */
#define TINTNO_SWI1		23U			/* ���եȥ����������1 */
#define TINTNO_SWI0		24U			/* ���եȥ����������0 */
#define TINTNO_VM7		25U			/* VME�����7 */
#define TINTNO_VM6		26U			/* VME�����6 */
#define TINTNO_VM5		27U			/* VME�����5 */
#define TINTNO_VM4		28U			/* VME�����4 */
#define TINTNO_VM3		29U			/* VME�����3 */
#define TINTNO_VM2		30U			/* VME�����2 */
#define TINTNO_VM1		31U			/* VME�����1 */

/*
 *  ����ߥ٥��ȥ�������ͤ����
 */
#define TVEC_G0I		0x40U		/* ���롼��0����ߥ٥��ȥ� */
#define TVEC_G1I		0x48U		/* ���롼��1����ߥ٥��ȥ� */
#define TVEC_SWI		0x50U		/* ���եȥ���������ߥ٥��ȥ� */
#define TVEC_SPRI		0x40U		/* ���ץꥢ������ߥ٥��ȥ� */

/*
 *  ����ߥϥ�ɥ��ֹ��inhno�ˤ����
 */
#define TINHNO_ACF		0x47U		/* ACFAIL����� */
#define TINHNO_ABT		0x46U		/* ���ܡ��ȳ���� */
#define TINHNO_SF		0x45U		/* SYSFAIL����� */
#define TINHNO_BER		0x44U		/* �Х����顼����� */
#define TINHNO_IAK		0x43U		/* IAK����� */
#define TINHNO_SRQ		0x42U		/* SRQ����� */
#define TINHNO_SAK		0x41U		/* SAK����� */
#define TINHNO_GP7		0x4fU		/* GP7����� */
#define TINHNO_DMA		0x4eU		/* DMA����� */
#define TINHNO_TT1		0x4dU		/* ������1����� */
#define TINHNO_TT0		0x4cU		/* ������0����� */
#define TINHNO_GP3		0x4bU		/* �ե�å���������� */
#define TINHNO_GP2		0x4aU		/* SCSI����� */
#define TINHNO_GP1		0x49U		/* Ethernet����� */
#define TINHNO_GP0		0x48U		/* ���ꥢ��I/O����� */
#define TINHNO_SWI7		0x57U		/* ���եȥ����������7 */
#define TINHNO_SWI6		0x56U		/* ���եȥ����������6 */
#define TINHNO_SWI5		0x55U		/* ���եȥ����������5 */
#define TINHNO_SWI4		0x54U		/* ���եȥ����������4 */
#define TINHNO_SWI3		0x53U		/* ���եȥ����������3 */
#define TINHNO_SWI2		0x52U		/* ���եȥ����������2 */
#define TINHNO_SWI1		0x51U		/* ���եȥ����������1 */
#define TINHNO_SWI0		0x50U		/* ���եȥ����������0 */
#define TINHNO_SPRI		0x40U		/* ���ץꥢ������� */

/*
 *  CPU�ܡ��ɾ�Υ쥸����
 */
#define TADR_BOARD_REG0		0xfff48000
#define TADR_BOARD_REG1		0xfff48004
#define TADR_BOARD_REG2		0xfff48008

/*
 *  DGA-001�Υ쥸�����Υ��ɥ쥹
 */
#define TADR_DGA_CSR0		0xfff44000
#define TADR_DGA_CSR1		0xfff44004
#define TADR_DGA_CSR3		0xfff4400c
#define TADR_DGA_CSR4		0xfff44010
#define TADR_DGA_CSR5		0xfff44014
#define TADR_DGA_CSR12		0xfff44030
#define TADR_DGA_CSR13		0xfff44034
#define TADR_DGA_CSR14		0xfff44038
#define TADR_DGA_CSR15		0xfff4403c
#define TADR_DGA_CSR18		0xfff44048
#define TADR_DGA_CSR19		0xfff4404c
#define TADR_DGA_CSR20		0xfff44050
#define TADR_DGA_CSR21		0xfff44054
#define TADR_DGA_CSR23		0xfff4405c
#define TADR_DGA_CSR24		0xfff44060
#define TADR_DGA_IFR0		0xfff44070
#define TADR_DGA_IFR3		0xfff4407c

/*
 *  DGA-001�γ����ͥ��������Τ�������
 */
#define TIRQ_NMI		(-7)		/* �Υ�ޥ����֥����� */
#define TIRQ_LEVEL6		(-6)		/* ����ߥ�٥�6 */
#define TIRQ_LEVEL5		(-5)		/* ����ߥ�٥�5 */
#define TIRQ_LEVEL4		(-4)		/* ����ߥ�٥�4 */
#define TIRQ_LEVEL3		(-3)		/* ����ߥ�٥�3 */
#define TIRQ_LEVEL2		(-2)		/* ����ߥ�٥�2 */
#define TIRQ_LEVEL1		(-1)		/* ����ߥ�٥�1 */

/*
 *  DGA�ؤΥ��������ؿ�
 */
#define dga_rew_reg(addr)			sil_rew_mem(addr)
#define dga_wrw_reg(addr, val)		sil_wrw_mem(addr, val)

/*
 *  DGA�Υ쥸�����ؤΥ��������ؿ�
 */
#ifndef TOPPERS_MACRO_ONLY

Inline uint32_t
dga_read(void *addr)
{
	return((uint32_t) dga_rew_reg(addr));
}

Inline void
dga_write(void *addr, uint32_t val)
{
	dga_wrw_reg(addr, val);
}

Inline void
dga_bit_or(void *addr, uint32_t bitpat)
{
	dga_write(addr, dga_read(addr) | bitpat);
}

Inline void
dga_bit_and(void *addr, uint32_t bitpat)
{
	dga_write(addr, dga_read(addr) & bitpat);
}

Inline void
dga_set_ilv(void *addr, uint_t shift, uint_t level)
{
	dga_write(addr, (dga_read(addr) & ~(0x07 << shift)) | (level << shift));
} 

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ��PD72001��MPSC�ˤΥ쥸�����Υ��ɥ쥹
 */
#define TADR_UPD72001_DATAA		0xfff45003U
#define TADR_UPD72001_CTRLA		0xfff45007U
#define TADR_UPD72001_DATAB		0xfff4500bU
#define TADR_UPD72001_CTRLB		0xfff4500fU

/*
 *  ��PD72001�ؤΥ��������ؿ�
 */
#define upd72001_reb_reg(addr)			sil_reb_mem(addr)
#define upd72001_wrb_reg(addr, val)		sil_wrb_mem(addr, val)

/*
 *  ��ȯ�Ķ���¸�ν���
 */
#ifndef TOPPERS_MACRO_ONLY
#ifdef TOPPERS_GDB_STUB				/* GDB������ */

Inline void
dve68k_exit(void)
{
	Asm("trap #2");
}

Inline void
dve68k_putc(char_t c)
{
	Asm("move.l %0, %%d1; trap #3"
	  : /* no output */
	  : "g"(c)
	  : "d0", "d1", "d2", "d6", "d7");
}

#else /* TOPPERS_GDB_STUB */		/* ����¾�γ�ȯ�Ķ� */

extern void		dve68k_exit(void) NoReturn;
extern void		dve68k_putc(char_t c);

#endif /* TOPPERS_GDB_STUB */
#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_DVE68K_H */
