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
 *  @(#) $Id: hw_timer.h,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

/*
 *	�^�C�}�h���C�o�iDVE68K/40�p�j
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <dve68k_dga.h>

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	TVEC_TT0

#ifndef _MACRO_ONLY

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UW	CLOCK;

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *
 *  DVE68K/40 CPU�{�[�h�ł́C�^�C�}��1�ʕb���ɃJ�E���g�A�b�v����D
 */
#define	TIMER_CLOCK		1000
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define	MAX_CLOCK	((CLOCK) 0xffffff)

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE	100	/* �����x��̌��ς�l�i�P�ʂ͓����\���j*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �^�C�}��~�܂ł̎��ԁinsec�P�ʁj
 *
 *  �l�ɍ����͂Ȃ��D
 */
#define	TIMER_STOP_DELAY	200

/*
 *  ���W�X�^�̐ݒ�l
 */
#define	CSR12_START	0x80000000u	/* �^�C�}���� */

/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize()
{
	CLOCK	cyc = TO_CLOCK(TIC_NUME, TIC_DENO);

	/*
	 *  �^�C�}������ݒ肵�C�^�C�}�̓�����J�n����D
	 */
	assert(cyc <= MAX_CLOCK);
	dga_write((VP) TADR_DGA_CSR12, CSR12_START | cyc);

	/*
	 *  �^�C�}�����݂̊����݃��x����ݒ肵�C�v�����N���A������C
	 *  �}�X�N����������D
	 */
	dga_set_ilv((VP) TADR_DGA_CSR25, TBIT_TT0IL, TIRQ_LEVEL4);
	dga_write((VP) TADR_DGA_CSR23, TBIT_TT0);
	dga_bit_or((VP) TADR_DGA_CSR21, TBIT_TT0);
}

/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear()
{
	dga_write((VP) TADR_DGA_CSR23, TBIT_TT0);
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
hw_timer_terminate()
{
	/*
	 *  �^�C�}�̓�����~����D
	 */
	dga_bit_and((VP) TADR_DGA_CSR12, ~CSR12_START);

	/*
	 *  �^�C�}�����݂��}�X�N���C�v�����N���A����D
	 */
	dga_bit_and((VP) TADR_DGA_CSR21, ~TBIT_TT0);
	dga_write((VP) TADR_DGA_CSR23, TBIT_TT0);
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK
hw_timer_get_current()
{
	CLOCK	clk;

	/*
	 *  �^�C�}�̓�����ꎞ�I�ɒ�~���C�^�C�}�l��ǂݏo���D
	 */
	dga_bit_and((VP) TADR_DGA_CSR12, ~CSR12_START);
	sil_dly_nse(TIMER_STOP_DELAY);
	clk = dga_read((VP) TADR_DGA_CSR13) & 0x00ffffffu;
	dga_bit_or((VP) TADR_DGA_CSR12, CSR12_START);
	return(clk);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
hw_timer_fetch_interrupt()
{
	return((dga_read((VP) TADR_DGA_CSR20) & TBIT_TT0) != 0);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
