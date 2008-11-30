/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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
 *  @(#) $Id: sh7145sci.c,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *   SH2�����V���A���R�~���j�P�[�V�����C���^�t�F�[�XSCI�p �ȈՃh���C�o
 */

#include <s_services.h>
#include "sh7145sci.h"

/*
 * �V���A��I/O�|�[�g�������u���b�N
 */
#ifndef GDB_STUB
const SIOPINIB siopinib_table[TNUM_PORT] = {
	{0xffff81b0, BRR9600, 0x0, 6}, /* SCI1 */
#if TNUM_PORT >= 2
	{0xffff81a0, BRR9600, 0x0, 6}, /* SCI0 */
#endif /* TNUM_PORT >= 2 */
};
#else /* GDB_STUB */
const SIOPINIB siopinib_table[TNUM_PORT] = {
	{0xffff81a0, BRR9600, 0x0, 6}, /* SCI0 */
};
#endif /* GDB_STUB */


/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
static SIOPCB siopcb_table[TNUM_PORT];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
				/*  �|�[�gID����f�o�C�X�ԍ������߂�}�N��  */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
sh2sci_getready (SIOPCB * siopcb)
{
	/*  ���V�[�u�f�[�^���W�X�^�t���E�t���O�̃`�F�b�N  */
	return (sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR)) &
			SSR_RDRF);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
sh2sci_putready (SIOPCB * siopcb)
{
	/*  �g�����X�~�b�g�f�[�^���W�X�^�G���v�e�B�E�t���O�̃`�F�b�N */
	return (sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR)) &
			SSR_TDRE);
}

/*
 *  ��M���������̎�o��
 */
Inline char
sh2sci_getchar (SIOPCB * siopcb)
{
	char data;

	data = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_RDR));
	/*  ���V�[�u�f�[�^���W�X�^�t���E�t���O�̃N���A  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SSR)) & ~SSR_RDRF);
	return data;
}

/*
 *  ���M���镶���̏�����
 */
Inline void
sh2sci_putchar (SIOPCB * siopcb, char c)
{
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_TDR), c);
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SSR)) & ~SSR_TDRE);
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
sh2sci_initialize ()
{
	SIOPCB *siopcb;
	UINT i;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_PORT; siopcb++, i++) {
		siopcb->openflag = FALSE;
		siopcb->siopinib = (&siopinib_table[i]);
	}
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
sh2sci_openflag (ID siopid)
{
	return (siopcb_table[siopid - 1].openflag);
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sh2sci_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb = get_siopcb (siopid);

	/*  ����M��~  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR), 0x00);

	/*  SCI�f�[�^���o�̓|�[�g�̐ݒ�  */
	/*  �s���A�T�C�� */
	/* sys_initialize�Őݒ� */

	/*  ����M�t�H�[�}�b�g  */
	/*  ����������  */
	/*  8�r�b�g�A�p���e�B�Ȃ�  */
	/*  �X�g�b�v�r�b�g�����O�X�F1   */
	/*  �N���b�N�Z���N�g */

	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SMR),
				 siopcb->siopinib->smr);
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_BRR),
				 (VB) siopcb->siopinib->brr);

	/*
	 * �{�[���[�g�̐ݒ��A1�J�E���g���҂��Ȃ���΂Ȃ�Ȃ��B
	 */
	sil_dly_nse (sh2sci_DELAY);	/* �l�͂����P�Ɠ��� */

	/* �G���[�t���O���N���A */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SSR)) & ~(SSR_ORER | SSR_FER |
													SSR_PER));
	/*����M���A��M���荞�݋��� */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
				 (VB) (SCI_RIE | SCI_TE | SCI_RE));

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return (siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
sh2sci_cls_por (SIOPCB * siopcb)
{
	/*  ����M��~�A�����݋֎~  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SCR)) & (VB) ~ (SCI_TIE | SCI_RIE |
														  SCI_TE | SCI_RE));
	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
sh2sci_snd_chr (SIOPCB * siopcb, char c)
{
	if (sh2sci_putready (siopcb)) {
		sh2sci_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
sh2sci_rcv_chr (SIOPCB * siopcb)
{
	if (sh2sci_getready (siopcb)) {
		return ((INT) (UB) sh2sci_getchar (siopcb));
		/*  (UB)�ŃL���X�g����̂̓[���g���ɂ��邽��  */
	}
	return (-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
sh2sci_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* ���M���荞�ݗv�������� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCI_SCR)) | SCI_TIE);
		break;
	case SIO_ERDY_RCV:			/* ��M���荞�ݗv�������� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCI_SCR)) | SCI_RIE);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
sh2sci_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* ���M���荞�ݗv�����֎~ */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCI_SCR)) & ~SCI_TIE);
		break;
	case SIO_ERDY_RCV:			/* ��M���荞�ݗv�����֎~ */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCI_SCR)) & ~SCI_RIE);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
Inline void
sh2sci_isr_siop_out (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR));

	if ((scr0 & SCI_TIE) != 0 && sh2sci_putready (siopcb)) {
		/*
		 *  ���M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh2sci_ierdy_snd (siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�����ݏ���
 */
Inline void
sh2sci_isr_siop_in (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SCR));

	if ((scr0 & SCI_RIE) != 0 && sh2sci_getready (siopcb)) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh2sci_ierdy_rcv (siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�G���[�����ݏ���
 */
Inline void
sh2sci_isr_siop_err (SIOPCB * siopcb)
{
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCI_SSR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCI_SSR)) & ~(SSR_ORER | SSR_FER |
													SSR_PER));
}

/*
 *  SCI���M�����݃T�[�r�X���[�`��
 *  
 */
void
sh2sci_isr_out (void)
{
	if (siopcb_table[0].openflag) {
		sh2sci_isr_siop_out (get_siopcb (1));
	}
}

/*
 *  SIO��M�����݃T�[�r�X���[�`��
 *  
 */
void
sh2sci_isr_in (void)
{
	if (siopcb_table[0].openflag) {
		sh2sci_isr_siop_in (get_siopcb (1));
	}
}

/*
 *  SIO��M�G���[�����݃T�[�r�X���[�`��
 */
void
sh2sci_isr_error (void)
{
	if (siopcb_table[0].openflag) {
		sh2sci_isr_siop_err (get_siopcb (1));
	}
}

/*
 * �|�[�����O�ɂ�镶���̑��M
 */
void
sh2sci_putc_pol (ID portid, char c)
{
	while (!sh2sci_putready (&siopcb_table[portid - 1]));
	sh2sci_putchar (&siopcb_table[portid - 1], c);
}


#if TNUM_PORT >= 2
/*
 *  SIO��M�����݃T�[�r�X���[�`��
 *  
 */
void
sh2sci_isr2_in (void)
{
	if (siopcb_table[1].openflag) {
		sh2sci_isr_siop_in (get_siopcb (2));
	}
}

/*
 *  SCI���M�����݃T�[�r�X���[�`��
 *  
 */
void
sh2sci_isr2_out (void)
{
	if (siopcb_table[1].openflag) {
		sh2sci_isr_siop_out (get_siopcb (2));
	}
}

/*
 *  SIO��M�G���[�����݃T�[�r�X���[�`��
 */
void
sh2sci_isr2_error (void)
{
	if (siopcb_table[1].openflag) {
		sh2sci_isr_siop_err (get_siopcb (2));
	}
}
#endif /* of #if TNUM_PORT >= 2 */
