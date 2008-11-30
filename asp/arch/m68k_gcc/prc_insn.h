/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: prc_insn.h 591 2007-11-12 02:39:38Z asp $
 */

/*
 *		�ץ��å����ü�̿��Υ���饤��ؿ������M68040�ѡ�
 */

#ifndef	TOPPERS_PRC_INSN_H
#define	TOPPERS_PRC_INSN_H

/*
 *  ���ơ������쥸������SR�ˤθ����ͤ��ɽФ�
 */
Inline uint16_t
current_sr(void)
{
	uint16_t	sr;

	Asm("move.w %%sr, %0" : "=g"(sr));
	return(sr);
}

/*
 *  ���ơ������쥸������SR�ˤθ����ͤ�����
 */
Inline void
set_sr(uint16_t sr)
{
	Asm("move.w %0, %%sr" : : "g"(sr) : "cc");
}

/*
 *  NMI��������٤Ƥγ���ߤζػ�
 *
 *  set_sr���Ѥ��Ƽ¸����뤳�Ȥ�Ǥ��뤬���̤�̿����Ѥ��Ƽ¸���������
 *  ��Ψ���ɤ�������Ѱդ��Ƥ��롥
 */
Inline void
disint(void)
{
	Asm("or.w #0x0700, %sr");
}

/*
 *  ���٤Ƥγ���ߤε���
 *
 *  set_sr���Ѥ��Ƽ¸����뤳�Ȥ�Ǥ��뤬���̤�̿����Ѥ��Ƽ¸���������
 *  ��Ψ���ɤ�������Ѱդ��Ƥ��롥
 */
Inline void
enaint(void)
{
	Asm("and.w #~0x0700, %sr");
}

/*
 *  �٥����١����쥸������VBR�ˤθ����ͤ��ɽФ�
 */
Inline void
*current_vbr(void)
{
	void	*vbr;

	Asm("movec.l %%vbr, %0" : "=r"(vbr));
	return(vbr);
}

/*
 *  �٥����١����쥸������VBR�ˤθ����ͤ�����
 */
Inline void
set_vbr(void *vbr)
{
	Asm("movec.l %0, %%vbr" : : "r"(vbr));
}

/*
 *  ��ǥ����塼�������Τ���Υӥåȥޥåץ������ؿ�
 *
 *  bfffo̿��ϺǾ�̥ӥåȤ��饵�������뤿�ᡤ�Ǿ�̥ӥåȤ�ǹ�ͥ����
 *  ���б������롥
 */
#define	OMIT_BITMAP_SEARCH
#define	PRIMAP_BIT(pri)		(0x8000U >> (pri))

Inline uint_t
bitmap_search(uint16_t bitmap)
{
	uint32_t	offset;

	Asm("bfffo %1{16,16}, %0" : "=d"(offset) : "d"((uint32_t) bitmap));
	return((uint_t)(offset - 16));
}

#endif /* TOPPERS_PRC_INSN_H */
