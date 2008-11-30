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
 *  @(#) $Id: dve68k_dga.h,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

/*
 *	DGA�̃A�N�Z�X���[�e�B���e�B
 */

#ifndef _DVE68K_DGA_H_
#define _DVE68K_DGA_H_

/*
 *  DGA�̊����ݐ���r�b�g�̒�`
 */
#define TBIT_ABT	0x40000000u	/* �A�{�[�g�����݃r�b�g */
#define TBIT_SQR	0x04000000u	/* SQR �����݃r�b�g */
#define	TBIT_TT0	0x00100000u	/* �^�C�}0 �����݃r�b�g */
#define	TBIT_GP0	0x00010000u	/* �V���A��I/O �����݃r�b�g */

/*
 *  DGA�̊����݃��x���ݒ�̂��߂̒�`
 */
#define	TIRQ_NMI	0x7u		/* �m���}�X�J�u�������� */
#define	TIRQ_LEVEL6	0x6u		/* �����݃��x��6 */
#define	TIRQ_LEVEL5	0x5u		/* �����݃��x��5 */
#define	TIRQ_LEVEL4	0x4u		/* �����݃��x��4 */
#define	TIRQ_LEVEL3	0x3u		/* �����݃��x��3 */
#define	TIRQ_LEVEL2	0x2u		/* �����݃��x��2 */
#define	TIRQ_LEVEL1	0x1u		/* �����݃��x��1 */

#define TBIT_ABTIL	24		/* �A�{�[�g������ */
#define TBIT_SQRIL	8		/* SRQ ������ */

#define TBIT_TT0IL	16		/* �^�C�}0 ������ */
#define TBIT_GP0IL	0		/* �V���A��I/O ������ */

#ifndef _MACRO_ONLY

/*
 *  DGA�̃��W�X�^�ւ̃A�N�Z�X�֐�
 */

Inline UW
dga_read(VP addr)
{
	return((UW) dga_rew_reg(addr));
}

Inline void
dga_write(VP addr, UW val)
{
	dga_wrw_reg(addr, (VW) val);
}

Inline void
dga_bit_or(VP addr, UW bitpat)
{
	dga_write(addr, dga_read(addr) | bitpat);
}

Inline void
dga_bit_and(VP addr, UW bitpat)
{
	dga_write(addr, dga_read(addr) & bitpat);
}

Inline void
dga_set_ilv(VP addr, UINT shift, UINT level)
{
	dga_write(addr, (dga_read(addr) & ~(0x07 << shift))
						| (level << shift));
} 

#endif /* _MACRO_ONLY */
#endif /* _DVE68K_DGA_H_ */
