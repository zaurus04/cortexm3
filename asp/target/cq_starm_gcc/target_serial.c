/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 * �V���A���h���C�o�iCQ-STARM�p�j
 */

#include <kernel.h>
#include <sil.h>
#include "target_serial.h"
#include "target_syssvc.h"

/*
 * ���W�X�^�ݒ�l
 */
#define PORT2SIOPID(x)	((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])

/*
 * USART���W�X�^��`
 */
#define USART_SR(x)		(x)
#define USART_DR(x)		(x + 0x04)
#define USART_BRR(x)	(x + 0x08)
#define USART_CR1(x)	(x + 0x0C)
#define USART_CR2(x)	(x + 0x10)
#define USART_CR3(x)	(x + 0x14)
#define USART_GTPR(x)	(x + 0x18)

#define SR_TXE			(0x0080)
#define SR_RXNE			(0x0020)
#define SR_ORE			(0x0008)
#define SR_FE			(0x0002)
#define SR_PE			(0x0001)
#define CR1_UE			(0x2000)
#define CR1_TXEIE		(0x0080)
#define CR1_RXNEIE		(0x0020)
#define CR1_TE			(0x0008)
#define CR1_RE			(0x0004)
#define CR3_EIE			(0x0001)

/*
 * �V���A��I/O�|�[�g�Ǘ��u���b�N�G���A
 */
SIOPCB siopcb_table[TNUM_PORT];

static const uint32_t sioreg_table[TNUM_PORT] = {
	USART1_BASE,
#if (TNUM_PORT >= 2)
	USART2_BASE
#endif
};

Inline bool_t  sio_putready(SIOPCB* siopcb)
{
	return (sil_rew_mem((void*)USART_SR(siopcb->reg)) & SR_TXE) != 0;
}

Inline bool_t sio_getready(SIOPCB* siopcb)
{
	return (sil_rew_mem((void*)USART_SR(siopcb->reg)) & SR_RXNE) != 0;
}

/*
 *  �^�[�Q�b�g�̃V���A��������
 */
void target_usart_init(ID siopid)
{
	uint32_t tmp, usartdiv, fraction;
	uint32_t reg = sioreg_table[INDEX_PORT(siopid)];
	uint32_t src_clock;

	/* USART�̖����� */
	sil_andw((void*)USART_CR1(reg), ~CR1_UE);

	/* 1STOP BIT */
	sil_wrw_mem((void*)USART_CR2(reg), 0);

	/* 1START BIT, 8DATA bits, Parity�Ȃ� */
	sil_wrw_mem((void*)USART_CR1(reg), 0);

	/* CR3������ */
	sil_wrw_mem((void*)USART_CR3(reg), 0);

	/* �ʐM���x�ݒ� */
	if (siopid == 1) {
		/* fck=72MHz */
		src_clock = PCLK2_CLOCK;
	} else {
		/* fck=36MHz */
		src_clock = PCLK1_CLOCK;
	}
	tmp = (1000 * (src_clock / 100)) / ((BPS_SETTING / 100) * 16);
	usartdiv = (tmp / 1000) << 4;
	fraction = tmp - ((usartdiv >> 4) * 1000);
	fraction = ((16 * fraction) + 500) / 1000;
	usartdiv |= (fraction & 0x0F);
	sil_wrw_mem((void*)USART_BRR(reg), usartdiv);

	/* ����M�̗L�����A�G���[�����݂̗L���� */
	sil_orw((void*)USART_CR1(reg), CR1_RE | CR1_TE);
	sil_orw((void*)USART_CR3(reg), CR3_EIE);

	/* USART�̗L���� */
	sil_orw((void*)USART_CR1(reg), CR1_UE);
}

/*
 *  �^�[�Q�b�g�̃V���A���I��
 */
void target_usart_term(ID siopid)
{
	uint32_t reg = sioreg_table[INDEX_PORT(siopid)];

	/* USART�̖����� */
	sil_andw((void*)USART_CR1(reg),  ~CR1_UE);
}

/*
 *  SIO������
 */
void sio_initialize(intptr_t exinf)
{
	int i;

	for (i = 0; i < TNUM_PORT; i++) {
		siopcb_table[i].port = i;
		siopcb_table[i].reg = sioreg_table[i];
		siopcb_table[i].exinf = 0;
	}
}

/*
 *  �V���A���I�[�v��
 */
SIOPCB *sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB* siopcb;

	if (siopid > TNUM_PORT) {
		return NULL;
	}

	siopcb = GET_SIOPCB(siopid);
	siopcb->exinf = exinf;

	target_usart_init(siopid);

	return siopcb;
}

/*
 *  �V���A���N���[�Y
 */
void sio_cls_por(SIOPCB *p_siopcb)
{
	target_usart_term(PORT2SIOPID(p_siopcb->port));
}

/*
 *  �����݃n���h��
 */
void sio_isr(intptr_t exinf)
{
	SIOPCB* siopcb = GET_SIOPCB(exinf);

	if (sio_putready(siopcb)) {
		sio_irdy_snd(siopcb->exinf);
	}
	if (sio_getready(siopcb)) {
		sio_irdy_rcv(siopcb->exinf);
	}
}

/*
 *  1�������M
 */
bool_t sio_snd_chr(SIOPCB *siopcb, char_t c)
{
	if (sio_putready(siopcb)) {
		sil_wrw_mem((void*)USART_DR(siopcb->reg), c);

		return true;
	}

	return false;
}

/*
 *  1������M
 */
int_t sio_rcv_chr(SIOPCB *siopcb)
{
	int_t c = -1;

	if (sio_getready(siopcb)) {
		c = sil_rew_mem((void*)USART_DR(siopcb->reg)) & 0xFF;
	}

	return c;
}

/*
 *  �R�[���o�b�N�̋���
 */
void sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	case SIO_RDY_SND:
		sil_orw((void*)USART_CR1(siopcb->reg), CR1_TXEIE);
		break;
	case SIO_RDY_RCV:
		sil_orw((void*)USART_CR1(siopcb->reg), CR1_RXNEIE);
		break;
	default:
		break;
	}
}

/* 
 *  �R�[���o�b�N�̋֎~
 */
void sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	case SIO_RDY_SND:
		sil_andw((void*)USART_CR1(siopcb->reg), ~CR1_TXEIE);
		break;
	case SIO_RDY_RCV:
		sil_andw((void*)USART_CR1(siopcb->reg), ~CR1_RXNEIE);
		break;
	default:
		break;
	}
}

/*
 *  1�����o�́i�|�[�����O�ł̏o�́j
 */
void sio_pol_snd_chr(char_t c, ID siopid)
{
	uint32_t reg = sioreg_table[INDEX_PORT(siopid)];

	sil_wrw_mem((void*)USART_DR(reg), c);

	while ((sil_rew_mem((void*)USART_SR(reg)) & SR_TXE) == 0) ;
}
