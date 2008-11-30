/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

/*
 *   �^�C�}�h���C�o�iVR4131����RTC��TClock�^�C�}�p�j
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <vr4131_rtc.h>

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	INTNO_TCLK

#ifndef _MACRO_ONLY

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UH		CLOCK;

#endif /* _MACRO_ONLY */

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *  TIMER_CLOCK�́A�{�[�h�֌W�̃w�b�_�t�@�C���ɋL�ڂ��Ă���B
 */
/* 1�~���b����(isig_tim ���Ăяo������;1kHz)�𔭐������邽�߂̃J�E���g�� */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
/* clock �� usec �P�ʂɕϊ�����}�N�� */
#define	TO_USEC(clock)		((clock) * 1000u / TIMER_CLOCK)

/*
 *  �^�C�}�����̒P�ʂ�����\���ɕϊ�
 *  (���p����^�C�}���_�E���J�E���^�Ȃ̂ŁA���̃}�N��������ƕ֗�)
 */
#define CLOCK_PER_TICK		((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define MAX_CLOCK		((CLOCK) 0x1ffffff)	/*  25�r�b�g  */

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE		100u	/* �����x��̌��ς�l�i�P�ʂ͓����\���j*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �^�C�}��~�܂ł̎��ԁinsec�P�ʁj
 *  �l�ɍ����͂Ȃ��D
 */
#define	TIMER_STOP_DELAY	200u

#ifndef _MACRO_ONLY
/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void hw_timer_int_clear() {

	vr4131_wrh_mem( (VP) RTCINTREG, RTCINTR3 );
}

/*
 *  �^�C�}�̋N������
 *    �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void hw_timer_initialize() {

	/*
	 *  �^�C�}������ݒ肵�C�^�C�}�̓�����J�n����D
	 */
	assert( CLOCK_PER_TICK <= MAX_CLOCK );

	vr4131_wrh_mem( (VP) TCLKLREG, (UH) LO16(CLOCK_PER_TICK) );
	vr4131_wrh_mem( (VP) TCLKHREG, (UH) HI16(CLOCK_PER_TICK) );

	/*
	 *  �^�C�}�����݂̊����݃��x����ݒ肵�C�v�����N���A������C
	 *  �}�X�N����������D
	 */
	all_set_ilv( INHNO_TIMER, &((IPM) IPM_TIMER) );	/* �����݃��x���̐ݒ� */

	hw_timer_int_clear();				/* �����ݗv�����N���A */

	/* �}�X�N��������(���x���P�A���x���Q�ɑ������郌�W�X�^�͖���) */
	vr4131_orh( (VP) MSYSINT2REG, TCLKINTR );
}

/*
 *  �^�C�}�̒�~����
 *  �^�C�}�̓�����~������D
 */
Inline void hw_timer_terminate() {

	/*  �^�C�}�̓�����~����  */
	vr4131_wrh_mem( (VP) TCLKLREG, 0 );
	vr4131_wrh_mem( (VP) TCLKHREG, 0 );

	/*
	 *  �^�C�}�����݂��}�X�N���C�v�����N���A����D
	 */
	/* �}�X�N�ݒ菈��(���x���P�A���x���Q�ɑ������郌�W�X�^�͖���) */
	vr4131_andh( (VP) MSYSINT2REG, ~TCLKINTR );

	hw_timer_int_clear();				/* �����ݗv�����N���A */
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK hw_timer_get_current() {

	UH 	count;
	UH	hi1, lo1, hi2, lo2;

	/* �J�E���^�l�̓ǂݏo�� */
	/* 2��ǂݏo���Ă��闝�R�́A�n�[�h�E�F�A��p261�Q�� */
	lo1 = vr4131_reh_mem( (VP) TCLKCNTLREG );
	hi1 = vr4131_reh_mem( (VP) TCLKCNTHREG );

	lo2 = vr4131_reh_mem( (VP) TCLKCNTLREG );
	hi2 = vr4131_reh_mem( (VP) TCLKCNTHREG );

	if( hi2 == hi1 )
		count = JOIN16( hi1, lo1 );
	else
		count = JOIN16( hi2, lo2 );

	return (CLOCK_PER_TICK - count);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL hw_timer_fetch_interrupt() {

	return( ( vr4131_reh_mem( (VP) RTCINTREG ) & RTCINTR3 ) != 0);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
