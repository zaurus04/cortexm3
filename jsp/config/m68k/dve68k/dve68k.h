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
 *  @(#) $Id: dve68k.h,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

/*
 *	DVE68K/40 CPU�{�[�h�̃n�[�h�E�F�A�����̒�`
 */

#ifndef _DVE68K_H_
#define _DVE68K_H_

/*
 *  �����݃x�N�g���̒�`
 */
#define	TVEC_G0I	0x40u		/* �O���[�v0 �����݃x�N�g�� */
#define TVEC_SQR	0x42u		/* SQR �����݃x�N�g�� */
#define TVEC_ABT	0x46u		/* �A�{�[�g�����݃x�N�g�� */

#define	TVEC_G1I	0x48u		/* �O���[�v1 �����݃x�N�g�� */
#define	TVEC_GP0	0x48u		/* �V���A��I/O �����݃x�N�g�� */
#define	TVEC_TT0	0x4cu		/* �^�C�}0 �����݃x�N�g�� */

#define	TVEC_SWI	0X50u		/* �\�t�g�E�F�A�����݃x�N�g�� */
#define	TVEC_SPRI	0x40u		/* �X�v���A�X�����݃x�N�g�� */

/*
 *  CPU�{�[�h��̃��W�X�^
 */
#define TADR_BOARD_REG0		0xfff48000
#define TADR_BOARD_REG1		0xfff48004
#define TADR_BOARD_REG2		0xfff48008

/*
 *  DGA-001�̃��W�X�^�̃A�h���X
 */
#define TADR_DGA_CSR0		0xfff44000
#define TADR_DGA_CSR1		0xfff44004
#define TADR_DGA_CSR3		0xfff4400c
#define TADR_DGA_CSR4		0xfff44010
#define TADR_DGA_CSR5		0xfff44014
#define TADR_DGA_CSR12		0xfff44030
#define TADR_DGA_CSR13		0xfff44034
#define	TADR_DGA_CSR19		0xfff4404c
#define	TADR_DGA_CSR20		0xfff44050
#define	TADR_DGA_CSR21		0xfff44054
#define TADR_DGA_CSR23		0xfff4405c
#define TADR_DGA_CSR24		0xfff44060
#define	TADR_DGA_CSR25		0xfff44064
#define	TADR_DGA_IFR0		0xfff44070
#define TADR_DGA_IFR3		0xfff4407c

/*
 *  DGA�ւ̃A�N�Z�X�֐�
 */
#define	dga_rew_reg(addr)		sil_rew_mem(addr)
#define dga_wrw_reg(addr, val)		sil_wrw_mem(addr, val)

/*
 *  ��PD72001�iMPSC�j�̃��W�X�^�̃A�h���X
 */
#define	TADR_UPD72001_DATAA	0xfff45003
#define	TADR_UPD72001_CTRLA	0xfff45007
#define	TADR_UPD72001_DATAB	0xfff4500b
#define	TADR_UPD72001_CTRLB	0xfff4500f

/*
 *  ��PD72001�ւ̃A�N�Z�X�֐�
 */
#define	upd72001_reb_reg(addr)		sil_reb_mem(addr)
#define upd72001_wrb_reg(addr, val)	sil_wrb_mem(addr, val)

/*
 *  GDB STUB�ďo�����[�`��
 */
#ifndef _MACRO_ONLY
#ifdef GDB_STUB

Inline void
dve68k_exit()
{
	Asm("trap #2");
}

Inline void
dve68k_putc(char c)
{
	Asm("move.l %0, %%d1; trap #3"
	  : /* no output */
	  : "g"((INT) c)
	  : "d0", "d1", "d2", "d6", "d7");
}

/*
 *  ���j�^�ďo�����[�`��
 */
#else /* GDB_STUB */

Inline void
dve68k_exit()
{
	Asm("clr.l %%d0; trap #3"
	  : /* no output */
	  : /* no input */
	  : "d0", "d1", "d2", "d6", "d7");
}

Inline char
dve68k_getc()
{
	INT	c;

	Asm("moveq.l #3, %%d0; trap #3; move.l %%d0, %0"
	  : "=g"(c)
	  : /* no input */
	  : "d0", "d1", "d2", "d6", "d7");
	  return((char) c);
}

Inline void
dve68k_putc(char c)
{
	Asm("moveq.l #5, %%d0; move.l %0, %%d1; trap #3"
	  : /* no output */
	  : "g"((INT) c)
	  : "d0", "d1", "d2", "d6", "d7");
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _DVE68K_H_ */
