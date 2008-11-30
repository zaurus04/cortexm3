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
 *	�^�C�}�h���C�o�iuPD71054�p�j
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <upd71054.h>

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	INTNO_TIMER0

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
#define MAX_CLOCK		((CLOCK) 0xffff)	/* �Q�o�C�g */

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE		100u	/* �����x��̌��ς�l(�P�ʂ͓����\��) */
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

	icu_wrb( (VP) ICU_INTR, TIMER0 );
}


/*
 *  �^�C�}�̋N������
 *  �E�^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void hw_timer_initialize() {

	upd71054_wrb( (VP) PCNTL, (COUNTER_0 | LOW_HIGH_BYTE | MODE_2 | BINARY) );

	/*
	 *  �^�C�}������ݒ肵�C�^�C�}�̓�����J�n����D
	 */
	assert( CLOCK_PER_TICK <= MAX_CLOCK );

	upd71054_wrb( (VP) PCNT0, (UB) LO8(CLOCK_PER_TICK) );
	upd71054_wrb( (VP) PCNT0, (UB) HI8(CLOCK_PER_TICK) );

	/*
	 *  �^�C�}�����݂̊����݃��x����ݒ肵�C�v�����N���A������C
	 *  �}�X�N����������D
	 */
	all_set_ilv( INHNO_TIMER, &((IPM) IPM_TIMER0) );/* �����݃��x���̐ݒ� */

	hw_timer_int_clear();				/* �����ݗv�����N���A */

	icu_orb( (VP) ICU_INT0M, TIMER0 );		/* �����݃}�X�N���� */
}

/*
 *  �^�C�}�̒�~����
 *  �^�C�}�̓�����~������D
 */
Inline void hw_timer_terminate() {

	/*  �^�C�}�̓�����~����  */
	upd71054_wrb( (VP) PCNTL, (COUNTER_0 | LOW_HIGH_BYTE | MODE_2 | BINARY) );

	upd71054_wrb( (VP) PCNT0, 0 );
	upd71054_wrb( (VP) PCNT0, 0 );

	/*
	 *  �^�C�}�����݂��}�X�N���C�v�����N���A����D
	 */
	icu_andb( (VP) ICU_INT0M, ~TIMER0 );		/* �����݂��}�X�N */

	hw_timer_int_clear();				/* �����ݗv�����N���A */
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK hw_timer_get_current() {

	UH 	count;
	UB	hi, lo;

	/* �J�E���^�l�̓ǂݏo�� */
	upd71054_wrb( (VP) PCNTL, (COUNTER_0 | COUNT_LATCH_COMM) );

	lo = upd71054_reb( (VP) PCNT0 );
	hi = upd71054_reb( (VP) PCNT0 );
	count = JOIN8( hi, lo );

	return (CLOCK_PER_TICK - count);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL hw_timer_fetch_interrupt() {

	return( ( icu_reb( (VP) ICU_INTR ) & TIMER0 ) != 0);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
