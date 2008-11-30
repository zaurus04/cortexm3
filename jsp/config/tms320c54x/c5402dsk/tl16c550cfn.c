/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
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
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: tl16c550cfn.c,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

/*
 * TL16c550cfn �p�h���C�o
 */

#include <s_services.h>
#include "tl16c550cfn.h"

/*
 * �J�[�l���N�����p�̏�����(sys_putc���g�p���邽��)
 */
void
uart_init(void)
{
	/*  FIFO��L���ɂ��A��M���MFIFO���N���A�A
	 *  �g���K���x�����P(��M���M���ʁj
	 *  8�f�[�^�A1�X�g�b�v�r�b�g�Ano parity 
	 */ 
	UART_FCR = (FCR_FIFO | FCR_RFRST | FCR_TFRST | FIFO_TRIG);
	UART_LCR = 0x03;
	 /*  �{�[���[�g���W�X�^�ɃA�N�Z�X */
	UART_LCR |= LCR_DLAB;
	UART_DLL = UART_BAUD_RATE;
	UART_DLM = UART_BAUD_RATE >> 8;
	/*  BAUD RATE�ݒ�I��  */
	UART_LCR &= ~LCR_DLAB;
	UART_SCR = UART_LSR;
}

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {0};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ��������M�������H
 */
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
	return((UART_LSR & LSR_DR) != 0);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
	return((UART_LSR & LSR_THRE) != 0);
}

/*
 *  ��M���������̎�o��
 */
Inline char
uart_getchar(SIOPCB *siopcb)
{
	return((char) UART_RBR);
}

/*
 *  ���M���镶���̏�����
 */
Inline void
uart_putchar(SIOPCB *siopcb, char c)
{
	UART_THR = (UB) c;
}

/*
 *  ���M�����݋���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
	UART_IER |= IER_TIE;
}

/*
 *  ���M�����݋֎~
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
	UART_IER &= ~IER_TIE;
}

/*
 *  ��M�����݋���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
	UART_IER = IER_RIE;
}

/*
 *  ��M�����݋֎~
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
	UART_IER &= ~IER_RIE;
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
uart_initialize()
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->siopinib = &(siopinib_table[i]);
		siopcb->openflag = FALSE;
	}
}

/*
 * �I�[�v�����Ă���|�[�g�����邩
 */
BOOL
uart_openflag(void)
{
	return(siopcb_table[0].openflag);
}



/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;

	siopcb = get_siopcb(siopid);
	
	/*  FIFO��L���ɂ��A��M���MFIFO���N���A�A
	 *  �g���K���x�����P(��M���M���ʁj
	 *  8�f�[�^�A1�X�g�b�v�r�b�g�Ano parity 
	 */
	UART_FCR = (FCR_FIFO | FCR_RFRST | FCR_TFRST | FIFO_TRIG);
	UART_LCR = 0x03;
	/*  �{�[���[�g���W�X�^�ɃA�N�Z�X */
	UART_LCR |= LCR_DLAB;
	UART_DLL = UART_BAUD_RATE;
	UART_DLM = UART_BAUD_RATE >> 8;
	/*  BAUD RATE�ݒ�I��  */
	UART_LCR &= ~LCR_DLAB;
	/*  �G���[�t���O���N���A  */
	UART_SCR = UART_LSR;
	UART_IER = IER_RIE;       /*  ��M���荞�݋���  */
	
	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	siopcb->getready = siopcb->putready = FALSE;

	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
uart_cls_por(SIOPCB *siopcb)
{
	/* ���M��M���荞�ݗv���֎~ */
	UART_IER = 0;
	
	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char chr)
{
	if (uart_putready(siopcb)) {
		uart_putchar(siopcb, chr);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
uart_rcv_chr(SIOPCB *siopcb)
{
	if (uart_getready(siopcb)) {
		return((INT)(UB) uart_getchar(siopcb));
	}
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	    case SIO_ERDY_SND:
		uart_enable_send(siopcb);
		break;
	    case SIO_ERDY_RCV:
		uart_enable_rcv(siopcb);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	    case SIO_ERDY_SND:
		uart_disable_send(siopcb);
		break;
	    case SIO_ERDY_RCV:
		uart_disable_rcv(siopcb);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
uart_isr_siop(SIOPCB *siopcb)
{
	if (uart_getready(siopcb)) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		uart_ierdy_rcv(siopcb->exinf);
	}
	if (uart_putready(siopcb)) {
		/*
		 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
		 */
		uart_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
uart_isr()
{
	if (siopcb_table[0].openflag) {
		uart_isr_siop(&(siopcb_table[0]));
	}
}
