/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
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
 *  @(#) $Id: sfruart.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	OAKS32 UART�p�V���A��I/O���W���[��
 */
#include <s_services.h>
#include "oaks32.h"
#include <sfruart.h>

/*
 *  �f�o�C�X�I�[�v���̃��g���C�J�E���g
 *
 *  500�񃊃g���C����΁A�\���ɏI������D
 */
#define	SFRUART_COUNT	500

/*
 * �V���A���R���g���[�����W�X�^�̐ݒ�l 
 */
#define	MR_DEF		0x05	/* �����N���b�N�A�񓯊��A8�r�b�g�A�p���e�B�Ȃ��A�X���[�v�Ȃ� */
#define MR_DISABLE_DEF	0x00	/* �V���A�����W���[������ */
#define	C0_DEF		0x10	/* RTS/CTS���g�p, �J�E���g�\�[�Xf1, ���M�����ݗv���́u���M�o�b�t�@��v */
#define	C1_DEF		0x00	/* �V���A������M�֎~ */
#define	BRG1_DEF	48	/* 30000000/{(UxBRG+1)*16} = 38400 */
#define	BRG2_DEF	97	/* 30000000/{(UxBRG+1)*16} = 19200 */

#define	TB_LEVEL	4	/* ���M�����݃��x�� */
#define	RB_LEVEL	5	/* ��M�����݃��x�� */
#define DISABLE_LEVEL	0	/* �����݋֎~���x�� */

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̒�`
 */
typedef struct sio_port_initialization_block {
	UH  cntrl_addr;	/* ���䃌�W�X�^�̔Ԓn */
	UH  tic_addr;	/* ���M�����ݐ��䃌�W�X�^�̔Ԓn */
	UH  ric_addr;	/* ��M�����ݐ��䃌�W�X�^�̔Ԓn */

	UB  mr_def;	/* �f�t�H���g�̐ݒ�l (MR) */
	UB  c0_def;	/* �f�t�H���g�̐ݒ�l (C0) */
	UB  brg_def;	/* �f�t�H���g�̐ݒ�l (BRG) */
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*siopinib;	/* �V���A��I/O�|�[�g�������u���b�N */
	VP_INT exinf;	/* �g����� */
	UB     uc1;	/* ����M���䃌�W�X�^UiC1�̐ݒ�l */
};

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 *
 *  ID = 1 ��uart0�CID = 2 ��uart1�ɑΉ������Ă���D
 */
static const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ TADR_SFR_UART0_BASE, (TADR_SFR_INT_BASE+TADR_SFR_S0TIC_OFFSET),
	  (TADR_SFR_INT_BASE+TADR_SFR_S0RIC_OFFSET), MR_DEF, C0_DEF, BRG1_DEF },
#if TNUM_SIOP>1
	{ TADR_SFR_UART1_BASE, (TADR_SFR_INT_BASE+TADR_SFR_S1TIC_OFFSET),
	  (TADR_SFR_INT_BASE+TADR_SFR_S1RIC_OFFSET), MR_DEF, C0_DEF, BRG1_DEF }
#endif
};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
static SIOPCB siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
sfruart_initialize(void)
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->siopinib = &(siopinib_table[i]);
		siopcb->uc1 = C1_DEF;
		/*
		 * �����I�Ƀ|�[�g��s���������Ă���
		 */
		/* ���荞�݋֎~ */
		sil_wrb_mem((VP)(siopcb->siopinib->tic_addr), DISABLE_LEVEL);
		sil_wrb_mem((VP)(siopcb->siopinib->ric_addr), DISABLE_LEVEL);
		/* ����M�֎~ */
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
	}
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sfruart_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB		*siopcb;
	const SIOPINIB	*siopinib;
	int i;

	siopcb = get_siopcb(siopid);
	siopinib = siopcb->siopinib;

	/* ����M�֎~ */
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET),
	   sil_reb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET))&~(TBIT_UiC1_TE | TBIT_UiC1_RE));

	/* �|�[�g�ݒ�(���샂�[�h�A�ʐM���x) */
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UMR_OFFSET), siopinib->mr_def);
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC0_OFFSET), siopinib->c0_def);
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UBRG_OFFSET), siopinib->brg_def);

	/*
	 *  �V���A�������݂̐ݒ�
	 */
	sil_wrb_mem((VP)(siopinib->tic_addr), TB_LEVEL);
	sil_wrb_mem((VP)(siopinib->ric_addr), RB_LEVEL);

	/* �I�[�v�����̓R�[���o�b�N�֎~ */
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);

	/*
	 * �_�~�[�f�[�^��M
	 */
	sil_reb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_URB_OFFSET));
	sil_reb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_URB_OFFSET));

	for(i = 0 ; i < SFRUART_COUNT ; i++){	/* �I�[�v�������MREADY�܂ő҂� */
		if(sil_reb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET)) & TBIT_UiC1_TI)
			break;
	}

	siopcb->exinf = exinf;
	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
sfruart_cls_por(SIOPCB *siopcb)
{
	const SIOPINIB	*siopinib;

	siopinib = siopcb->siopinib;

	/* ���荞�݋֎~ */
	sil_wrb_mem((VP)(siopinib->tic_addr), DISABLE_LEVEL);
	sil_wrb_mem((VP)(siopinib->ric_addr), DISABLE_LEVEL);

	/* ����M�֎~ */
	siopcb->uc1 = C1_DEF;
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);

	/* �V���A�����W���[���𖳌��ɂ��� */
	sil_wrb_mem((VP)(siopinib->cntrl_addr+TADR_SFR_UMR_OFFSET), MR_DISABLE_DEF);
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
sfruart_snd_chr(SIOPCB *siopcb, char c)
{
	if(sil_reb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET)) & TBIT_UiC1_TI){
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UTB_OFFSET), c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
sfruart_rcv_chr(SIOPCB *siopcb)
{
	if(sil_reb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET)) & TBIT_UiC1_RI){
		return((INT)sil_reb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_URB_OFFSET)));
	}
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
sfruart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		siopcb->uc1 |= TBIT_UiC1_TE;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
		break;
	case SIO_ERDY_RCV:
		siopcb->uc1 |= TBIT_UiC1_RE;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
		break;
	default:
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
sfruart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		siopcb->uc1 &= ~TBIT_UiC1_TE;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
		break;
	case SIO_ERDY_RCV:
		siopcb->uc1 &= ~TBIT_UiC1_RE;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl_addr+TADR_SFR_UC1_OFFSET), siopcb->uc1);
		break;
	default:
		break;
	}
}

/*
 *  uart0����̎�M������
 */
void serial_in_handler1(void)
{
	SIOPCB *siopcb = &siopcb_table[0];
	if((siopcb->uc1 & TBIT_UiC1_RE) != 0) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sfruart_ierdy_rcv(siopcb->exinf);
	}
}

/*
 *  uart0����̑��M������
 */
void serial_out_handler1(void)
{
	SIOPCB *siopcb = &siopcb_table[0];

	if((siopcb->uc1 & TBIT_UiC1_TE) != 0) {
		/*
		 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sfruart_ierdy_snd(siopcb->exinf);
	}
}

#if TNUM_SIOP > 1
/*
 *  uart1����̎�M������
 */
void serial_in_handler2(void)
{
	SIOPCB *siopcb = &siopcb_table[1];
	if((siopcb->uc1 & TBIT_UiC1_RE) != 0){
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sfruart_ierdy_rcv(siopcb->exinf);
	}
}

/*
 *  uart1����̑��M������
 */
void serial_out_handler2(void)
{
	SIOPCB *siopcb = &siopcb_table[1];
	if((siopcb->uc1 & TBIT_UiC1_TE) != 0) {
		/*
		 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sfruart_ierdy_snd(siopcb->exinf);
	}
}
#endif
