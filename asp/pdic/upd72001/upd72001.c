/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: upd72001.c 873 2008-04-11 10:32:26Z hiro $
 */

/*
 *		��PD72001�� �ʰ�SIO�ɥ饤��
 */

#include <sil.h>
#include "target_syssvc.h"
#include "upd72001.h"

/*
 *  �ǥХ����쥸�����Υ��������ֳֻ��֡�nsecñ�̡�
 *
 *  200�Ȥ����ͤˤ��ޤ꺬��Ϥʤ���
 */
#define	UPD72001_DELAY	200U

/*
 *  ��PD72001�Υ쥸�������ֹ�
 */
#define	UPD72001_CR0	0x00U		/* ����ȥ���쥸���� */
#define	UPD72001_CR1	0x01U
#define	UPD72001_CR2	0x02U
#define	UPD72001_CR3	0x03U
#define	UPD72001_CR4	0x04U
#define	UPD72001_CR5	0x05U
#define	UPD72001_CR10	0x0aU
#define	UPD72001_CR12	0x0cU
#define	UPD72001_CR14	0x0eU
#define	UPD72001_CR15	0x0fU

#define	UPD72001_SR0	0x00U		/* ���ơ������쥸���� */

/*
 *  ����ȥ���쥸������������
 */
#define CR_RESET	0x18U		/* �ݡ��ȥꥻ�åȥ��ޥ�� */

#define CR0_EOI		0x38U		/* EOI��End of Interrupt��*/

#define CR1_DOWN	0x00U		/* ������ߤ�ػ� */
#define CR1_RECV	0x10U		/* ��������ߵ��ĥӥå� */
#define CR1_SEND	0x02U		/* ��������ߵ��ĥӥå� */

#define CR3_DEF		0xc1U		/* �ǡ��� 8bit���������͡��֥� */
#define CR4_DEF		0x44U		/* ���ȥåץӥå� 1bit���ѥ�ƥ��ʤ� */
#define CR5_DEF		0xeaU		/* �ǡ��� 8bit���������͡��֥� */

#define CR10_DEF	0x00U		/* NRZ */
#define CR14_DEF	0x07U		/* �ܡ��졼�ȥ����ͥ졼�����͡��֥� */
#define CR15_DEF	0x56U		/* �ܡ��졼�ȥ����ͥ졼������ */

#define SR0_RECV	0x01U		/* �������Υӥå� */
#define SR0_SEND	0x04U		/* ������ǽ�ӥå� */

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å������
 */
typedef struct sio_port_initialization_block {
	void		*data;			/* �ǡ����쥸���������� */
	void		*ctrl;			/* ����ȥ���쥸���������� */

	uint8_t		cr3_def;		/* CR3�������͡ʼ����ӥåȿ���*/
	uint8_t		cr4_def;		/* CR4�������͡ʥ��ȥåץӥåȡ��ѥ�ƥ���*/
	uint8_t		cr5_def;		/* CR5�������͡������ӥåȿ���*/
	uint8_t		brg1_def;		/* �ܡ��졼�Ⱦ�̤������� */
	uint8_t		brg2_def;		/* �ܡ��졼�Ȳ��̤������� */
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
struct sio_port_control_block {
	const SIOPINIB *p_siopinib;	/* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
	intptr_t	exinf;			/* ��ĥ���� */
	bool_t		openflag;		/* �����ץ�Ѥߥե饰 */
	uint8_t		cr1;			/* CR1�������͡ʳ���ߵ��ġ�*/
	bool_t		getready;		/* ʸ��������������� */
	bool_t		putready;		/* ʸ���������Ǥ������ */
};

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ (void *) TADR_UPD72001_DATAA, (void *) TADR_UPD72001_CTRLA,
					CR3_DEF, CR4_DEF, CR5_DEF, BRG1_DEF, BRG2_DEF },
	{ (void *) TADR_UPD72001_DATAB, (void *) TADR_UPD72001_CTRLB,
					CR3_DEF, CR4_DEF, CR5_DEF, BRG1_DEF, BRG2_DEF }
};

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	((uint_t)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  �ǥХ����쥸�����ؤΥ��������ؿ�
 */
Inline uint8_t
upd72001_read_reg(void *addr)
{
	uint8_t	val;

	val = upd72001_reb_reg(addr);
	sil_dly_nse(UPD72001_DELAY);
	return(val);
}

Inline void
upd72001_write_reg(void *addr, uint8_t val)
{
	upd72001_wrb_reg(addr, val);
	sil_dly_nse(UPD72001_DELAY);
}

Inline uint8_t
upd72001_read_ctrl(void *addr, uint8_t reg)
{
	upd72001_write_reg(addr, reg);
	return(upd72001_read_reg(addr));
}

Inline void
upd72001_write_ctrl(void *addr, uint8_t reg, uint8_t val)
{
	upd72001_write_reg(addr, reg);
	upd72001_write_reg(addr, val);
}

Inline void
upd72001_write_brg(void *addr, uint8_t reg, uint8_t val,
									uint8_t brg2, uint8_t brg1)
{
	upd72001_write_reg(addr, reg);
	upd72001_write_reg(addr, val);
	upd72001_write_reg(addr, brg2);
	upd72001_write_reg(addr, brg1);
	(void) upd72001_read_reg(addr);		/* ���ߡ��꡼�� */
}

/*
 *  ���֤��ɽФ���SR0���ɽФ���
 *
 *  ��PD72001�ϡ����֡�SR0�ˤ�����ɤ�ȼ������ΥӥåȤ�����Ƥ��ޤ���
 *  �ᡤ���֤��ɤ߽Ф��ؿ����ߤ������ꥢ��I/O�ݡ��ȴ����֥�å����
 *  getready�˼������ξ��֡�putready��������ǽ���֤���¸���Ƥ��������
 *  ��ǽ���֤���¸�����פ��⤷��ʤ��ˡ�
 *  ���֥쥸�������ɤ�Ǥ�������ΥӥåȤ�����ʤ��ǥХ����ʤ����餬��
 *  �̤Ȼפ���ˤǤϡ����δؿ���ɬ�פʤ���
 */
static void
upd72001_get_stat(SIOPCB *p_siopcb)
{
	uint8_t	sr0;

	sr0 = upd72001_read_ctrl(p_siopcb->p_siopinib->ctrl, UPD72001_SR0);
	if ((sr0 & SR0_RECV) != 0) {
		p_siopcb->getready = true;
	}
	if ((sr0 & SR0_SEND) != 0) {
		p_siopcb->putready = true;
	}
}

/*
 *  ʸ��������Ǥ��뤫��
 */
Inline bool_t
upd72001_getready(SIOPCB *p_siopcb)
{
	upd72001_get_stat(p_siopcb);
	return(p_siopcb->getready);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline bool_t
upd72001_putready(SIOPCB *p_siopcb)
{
	upd72001_get_stat(p_siopcb);
	return(p_siopcb->putready);
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char_t
upd72001_getchar(SIOPCB *p_siopcb)
{
	p_siopcb->getready = false;
	return((char_t) upd72001_read_reg(p_siopcb->p_siopinib->data));
}

/*
 *  ��������ʸ���ν����
 */
Inline void
upd72001_putchar(SIOPCB *p_siopcb, char_t c)
{
	p_siopcb->putready = false;
	upd72001_write_reg(p_siopcb->p_siopinib->data, (uint8_t) c);
}

/*
 *  EOI��End Of Interrupt��ȯ��
 */
Inline void
upd72001_eoi(void)
{
	upd72001_write_ctrl((void *) TADR_UPD72001_CTRLA, UPD72001_CR0, CR0_EOI);
}

/*
 *  SIO�ɥ饤�Фν����
 */
void
upd72001_initialize(void)
{
	SIOPCB	*p_siopcb;
	uint_t	i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (p_siopcb = siopcb_table, i = 0; i < TNUM_SIOP; p_siopcb++, i++) {
		p_siopcb->p_siopinib = &(siopinib_table[i]);
		p_siopcb->openflag = false;
	}
}

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
bool_t
upd72001_openflag(void)
{
	return(siopcb_table[0].openflag || siopcb_table[1].openflag);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
upd72001_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB		*p_siopcb;
	const SIOPINIB	*p_siopinib;

	p_siopcb = get_siopcb(siopid);
	p_siopinib = p_siopcb->p_siopinib;

	upd72001_write_reg(p_siopinib->ctrl, CR_RESET);
	if (!upd72001_openflag()) {
		upd72001_write_ctrl((void *) TADR_UPD72001_CTRLA, UPD72001_CR2, 0x18);
		upd72001_write_ctrl((void *) TADR_UPD72001_CTRLB, UPD72001_CR2, 0x00);
	}
	p_siopcb->cr1 = CR1_DOWN;
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR1, p_siopcb->cr1);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR4, p_siopinib->cr4_def);
	upd72001_write_brg(p_siopinib->ctrl, UPD72001_CR12, 0x01U,
							p_siopinib->brg2_def, p_siopinib->brg1_def);
	upd72001_write_brg(p_siopinib->ctrl, UPD72001_CR12, 0x02U,
							p_siopinib->brg2_def, p_siopinib->brg1_def);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR15, CR15_DEF);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR14, CR14_DEF);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR10, CR10_DEF);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR3, p_siopinib->cr3_def);
	upd72001_write_ctrl(p_siopinib->ctrl, UPD72001_CR5, p_siopinib->cr5_def);
	p_siopcb->exinf = exinf;
	p_siopcb->getready = p_siopcb->putready = false;
	p_siopcb->openflag = true;
	return(p_siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
upd72001_cls_por(SIOPCB *p_siopcb)
{
	upd72001_write_ctrl(p_siopcb->p_siopinib->ctrl, UPD72001_CR1, CR1_DOWN);
	p_siopcb->openflag = false;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
bool_t
upd72001_snd_chr(SIOPCB *p_siopcb, char_t c)
{
	if (upd72001_putready(p_siopcb)) {
		upd72001_putchar(p_siopcb, c);
		return(true);
	}
	return(false);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
int_t
upd72001_rcv_chr(SIOPCB *p_siopcb)
{
	if (upd72001_getready(p_siopcb)) {
		return((int_t)(uint8_t) upd72001_getchar(p_siopcb));
	}
	return(-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
upd72001_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	uint8_t	cr1_bit = 0;

	switch (cbrtn) {
	case SIO_RDY_SND:
		cr1_bit = CR1_SEND;
		break;
	case SIO_RDY_RCV:
		cr1_bit = CR1_RECV;
		break;
	}
	p_siopcb->cr1 |= cr1_bit;
	upd72001_write_ctrl(p_siopcb->p_siopinib->ctrl,
									UPD72001_CR1, p_siopcb->cr1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
upd72001_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	uint8_t	cr1_bit = 0;

	switch (cbrtn) {
	case SIO_RDY_SND:
		cr1_bit = CR1_SEND;
		break;
	case SIO_RDY_RCV:
		cr1_bit = CR1_RECV;
		break;
	}
	p_siopcb->cr1 &= ~cr1_bit;
	upd72001_write_ctrl(p_siopcb->p_siopinib->ctrl,
									UPD72001_CR1, p_siopcb->cr1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф������߽���
 */
static void
upd72001_isr_siop(SIOPCB *p_siopcb)
{
	if ((p_siopcb->cr1 & CR1_RECV) != 0U && upd72001_getready(p_siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		upd72001_irdy_rcv(p_siopcb->exinf);
	}
	if ((p_siopcb->cr1 & CR1_SEND) != 0U && upd72001_putready(p_siopcb)) {
		/*
		 *  ������ǽ������Хå��롼�����ƤӽФ���
		 */
		upd72001_irdy_snd(p_siopcb->exinf);
	}
}

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
void
upd72001_isr(void)
{
	if (siopcb_table[0].openflag) {
		upd72001_isr_siop(&(siopcb_table[0]));
	}
	if (siopcb_table[1].openflag) {
		upd72001_isr_siop(&(siopcb_table[1]));
	}
	upd72001_eoi();
}
