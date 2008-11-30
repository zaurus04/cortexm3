/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <h8s_tpu.h>

/*
 *   �^�C�}�h���C�o�iH8S�t�@�~���[�p�j
 *     H8S�t�@�~���[�ɂ́ATPU(16bit�^�C�}) �� 8bit�^�C�} �̂Q��ނ�����
 *     ����Ă���A���̓��ږ{���́A�e�v���Z�b�T�ɂ��قȂ�B
 *     �{�����ł́ATPU(16bit�^�C�}) �𗘗p���Ă���B�i���Ƀ`�����l���O�j
 *     ����H8S�v���Z�b�T�ɂ����āA8bit�^�C�} �𗘗p����ꍇ�́A�ύX��
 *     �s���K�v������B
 */

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	IRQ_TGI0A

#ifndef _MACRO_ONLY

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UH	CLOCK;

#endif	/* _MACRO_ONLY */

/*
 *  �^�C�}�����̒P�ʂ�����\���ɕϊ�
 *  	jsp/kernel/time_manage.c�ł��g�p
 */
#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)

/*
 *  �^�C�}�����̒P�ʂ�����\���ɕϊ�
 */
#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  ���\�]���p�V�X�e�����������o���ۂ̏������Ԃ̌��ς�l
 *	�i�P�ʂ͓����\���j
 *	���Ӂi�{���͕����N���b�N�Ɉˑ��j
 */

#define GET_TOLERANCE	100u
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

#ifndef _MACRO_ONLY

/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear(void)
{
	/* �`���l���O�̊��荞�ݗv���N���A (TGFA = 0) */
	h8s_andb( (VP) TSR0, ~TGFA );
}

/*
 *  �^�C�}�̋N������
 *    �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize(void)
{
	/* ���W���[���X�g�b�v���[�h���� */
	h8s_andh( (VP) MSTPCR, ~BIT13 );

	/* �`���l���O�̓����~ */
	h8s_andb( (VP) TSTR, ~CST0 );

	/* TCR �̐ݒ�
	   �ETGRA�R���y�A�}�b�`�ŃJ�E���^���N���A(CCLR = 1)
	   �E�����オ��G�b�W�ŃJ�E���g(CKEG1,0 = 0)
	�A �E�����N���b�N��/4�ŃJ�E���g(������ݒ�GTPSC0 =1) */
	h8s_wrb_mem( (VP) TCR0, (CCLR0 | TPSC0) );

	/* TIER �̐ݒ�
	   �ETGFA�r�b�g�ɂ�銄���ݗv�������� */
	h8s_wrb_mem( (VP) TIER0, TGIEA );

	/* TIOR �̐ݒ�
	   �ETGRA�R���y�A�}�b�`�ɂ��[�q�o�͋֎~ */
	/* �ݒ肷�ׂ����͖̂����B */

	/* TGR0A �̐ݒ�
	   �ETGRA���W�X�^�ݒ�i�J�E���^�ڕW�l�j*/
	h8s_wrh_mem( (VP) TGR0A, CLOCK_PER_TICK );

	h8s_wrh_mem( (VP) TCNT0, 0 );		/* �J�E���^���N���A */

	/*
	 *  �����݊֘A�̐ݒ�
	 */
	icu_set_ilv( (VP) IPRF, IPR_UPR, TPU0_INT_LVL );
						/* �����݃��x���ݒ� */
	hw_timer_int_clear();			/* �����ݗv�����N���A */

	/* �`���l���O�̓���J�n */
	h8s_orb( (VP) TSTR, CST0 );
}

/*
 *  �^�C�}�̒�~����
 */
Inline void
hw_timer_terminate(void)
{
	/* �`���l���O�̓����~ */
	h8s_andb( (VP) TSTR, ~CST0 );

	hw_timer_int_clear();			/* �����ݗv�����N���A */
}

/*
 *  �^�C�}�̌��ݒl�̓ǂݏo��
 *    �����݋֎~��Ԓ��ŌĂяo�����ƁD
 */
Inline CLOCK
hw_timer_get_current(void)
{
	/* �A�b�v�J�E���^�Ȃ̂ŁB */
	return( (CLOCK) h8s_reh_mem( (VP) TCNT0 ) );
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return( h8s_reb_mem( (VP) TSR0 ) & TGFA );
}

#endif	/* _MACRO_ONLY */

#endif /* _HW_TIMER_H_ */
