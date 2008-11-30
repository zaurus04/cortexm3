/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 *  @(#) $Id: sh7615scif.c,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *   SH2�����V���A���R�~���j�P�[�V�����C���^�t�F�[�XSCIF�p �ȈՃh���C�o
 */

#include <s_services.h>
#include "sh7615scif.h"

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
/* ���o�̓|�[�g�̐ݒ��sys_config.c */
/* �����݃x�N�^�ԍ��̐ݒ��hw_serial.h */
/* �Ǘ��u���b�N�̐ݒ��sh7615scif.c */

#ifndef GDB_STUB

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{0xfffffcc0, BRR9600, 0x0, 6}, /* SCIF1 */
#if TNUM_PORT >= 2
	{0xfffffce0, BRR9600, 0x0, 6}, /* SCIF2 */
#endif /* TNUM_PORT >= 2 */
};

#else /* GDB_STUB */

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{0xfffffce0, BRR9600, 0x0, 6}, /* SCIF2 */
};

#endif /* GDB_STUB */

#if defined(TTM)
/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 *  �@2ch�T�|�[�g�Ɋg������ꍇ�͏����l�p�̃f�[�^���܂߂�
 */
struct sio_port_control_block
{
	VP_INT exinf;				/* �g����� */
	BOOL openflag;				/* �I�[�v���ς݃t���O */
};
#endif
/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
static SIOPCB siopcb_table[TNUM_PORT];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
sh2scif_getready (SIOPCB * siopcb)
{
	/*  ���V�[�u�f�[�^���W�X�^�t���E�t���O�̃`�F�b�N  */
	return (sil_reh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR)) &
			SC1SSR_RDRF);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
sh2scif_putready (SIOPCB * siopcb)
{
	/*  �g�����X�~�b�gFIFO�f�[�^���W�X�^�G���v�e�B�E�t���O�̃`�F�b�N */
	return (sil_reh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR)) &
			SC1SSR_TDFE);
}

/*
 *  ��M���������̎�o��
 */
Inline char
sh2scif_getchar (SIOPCB * siopcb)
{
	VB data;

	data = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFRDR));
	/*  ���V�[�u�f�[�^���W�X�^�t���E�t���O�̃N���A  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_RDRF);
	return data;
}

/*
 *  ���M���镶���̏�����
 */
Inline void
sh2scif_putchar (SIOPCB * siopcb, char c)
{
	/*  �g�����X�~�b�gFIFO�f�[�^���W�X�^�G���v�e�B�E�t���O�̃N���A */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFTDR), c);
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_TDFE);
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
sh2scif_initialize ()
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
sh2scif_openflag (ID siopid)
{
	return (siopcb_table[siopid - 1].openflag);
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sh2scif_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;

	siopcb = get_siopcb (siopid);

	/*  ����M��~  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
									  SCIF_SCSCR)) & ~(SCSCR_TE | SCSCR_RE));

	/*  SCI�f�[�^���o�̓|�[�g�̐ݒ�  */
	/*  �s���A�T�C�� */
	/* sys_initialize�Őݒ� */

	/*  FIFO�̏�����  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFCR),
				 (VB) (SCFCR_TFRST | SCFCR_RFRST));

	/*  ����M�t�H�[�}�b�g  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSMR), 0x00);
	/*  ����������  */
	/*  8�r�b�g�A�p���e�B�Ȃ�  */
	/*  �X�g�b�v�r�b�g�����O�X�F1   */
	/*  �N���b�N�Z���N�g */

	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCBRR), (VB) siopcb->siopinib->brr);	/* �{�[���[�g�ݒ� */


	/*
	 * �{�[���[�g�̐ݒ��A1�J�E���g���҂��Ȃ���΂Ȃ�Ȃ��B
	 */
	sil_dly_nse (sh2scif_DELAY);	/* �l�͂����P�Ɠ��� */

	/*  FIFO�̐ݒ�  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFCR), 0x00);

	/* �G���[�t���O���N���A */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_ER);

	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 (VB) (SCSCR_RIE | SCSCR_TE | SCSCR_RE));

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return (siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
sh2scif_cls_por (SIOPCB * siopcb)
{
	/*  ����M��~�A�����݋֎~  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 (VB) ~ (SCSCR_TIE | SCSCR_RIE | SCSCR_TE | SCSCR_RE));

	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
sh2scif_snd_chr (SIOPCB * siopcb, char c)
{
	if (sh2scif_putready (siopcb)) {
		sh2scif_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
sh2scif_rcv_chr (SIOPCB * siopcb)
{
	if (sh2scif_getready (siopcb)) {
		return ((INT) (UB) sh2scif_getchar (siopcb));
	}
	return (-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
sh2scif_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* ���M���荞�ݗv�������� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) | SCSCR_TIE);
		break;
	case SIO_ERDY_RCV:			/* ��M���荞�ݗv�������� */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) | SCSCR_RIE);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
sh2scif_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* ���M���荞�ݗv�����֎~ */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) & ~SCSCR_TIE);
		break;
	case SIO_ERDY_RCV:			/* ��M���荞�ݗv�����֎~ */
		sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reb_mem ((VB *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) & ~SCSCR_RIE);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
Inline void
sh2scif_isr_siop_out (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR));

	if ((scr0 & SCSCR_TIE) != 0 && sh2scif_putready (siopcb)) {
		/*
		 *  ���M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh2scif_ierdy_snd (siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�����ݏ���
 */
Inline void
sh2scif_isr_siop_in (SIOPCB * siopcb)
{
	VB scr0 = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCSCR));

	if ((scr0 & SCSCR_RIE) != 0 && sh2scif_getready (siopcb)) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh2scif_ierdy_rcv (siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�G���[�����ݏ���
 */
Inline void
sh2scif_isr_siop_err (SIOPCB * siopcb)
{
	/* �G���[�t���O���N���A */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_ER);
	/*  FIFO�̏�����  */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFCR),
				 (VB) SCFCR_RFRST);
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFCR), 0x30);
}

/* �u���[�N���o���� */
/* �t���O�����Z�b�g���� */
Inline void
sh2scif_isr_siop_brk (SIOPCB * siopcb)
{
	/* �t���O���N���A */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SC1SSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SC1SSR)) & ~SC1SSR_BRK);
}

/*
 *  SCI���M�����݃T�[�r�X���[�`�� �����P�Ɠ���
 *  
 *  �@SH1������SCI�ł͊����ݔԍ�������M�ʁA�`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI0�̑��M�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  
 */
void
sh2scif_isr_out ()
{
	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_out (get_siopcb (1));
	}
}

/*
 *  SCI��M�����݃T�[�r�X���[�`���@�����P�Ɠ���
 *  
 *  �@SH1������SCI�ł͊����ݔԍ�������M�ʁA�`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI0�̎�M�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  
 */
void
sh2scif_isr_in ()
{
	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_in (get_siopcb (1));
	}
}

/*
 *  SIO��M�G���[�����݃T�[�r�X���[�`���@�����P�Ɠ���
 *  
 *  �@SH1������SCI�ł͊����ݔԍ����`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI0�̎�M�G���[�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  �@
 *  �@�G���[�������̂̓G���[�t���O�̃N���A�݂̂ɂƂǂ߂Ă���B
 *  �@�@�@�E�I�[�o�[�����G���[
 *  �@�@�@�E�t���[�~���O�G���[
 *  �@�@�@�E�p���e�B�G���[
 */
void
sh2scif_isr_error (void)
{

	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_err (get_siopcb (1));
	}
}

/* �u���[�N���o */
void
sh2scif_isr_brk (void)
{

	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_brk (get_siopcb (1));
	}
}

/*
 * �|�[�����O�ɂ�镶���̑��M
 */
void
sh2scif_putc_pol (ID portid, char c)
{
	while (!sh2scif_putready (&siopcb_table[portid - 1]));
	sh2scif_putchar (&siopcb_table[portid - 1], c);
}

#if TNUM_PORT >= 2
/*
 *  SCI��M�����݃T�[�r�X���[�`��
 *  
 */
void
sh2scif_isr2_in (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_in (get_siopcb (2));
	}
}

/*
 *  SCI���M�����݃T�[�r�X���[�`��
 *  
 */
void
sh2scif_isr2_out (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_out (get_siopcb (2));
	}
}

/*
 *  SCI��M�G���[�����݃T�[�r�X���[�`��
 */
void
sh2scif_isr2_error (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_err (get_siopcb (2));
	}
}

/* �u���[�N���o */
void
sh2scif_isr2_brk (void)
{

	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_brk (get_siopcb (2));
	}
}
#endif /* of #if TNUM_PORT >= 2 */
