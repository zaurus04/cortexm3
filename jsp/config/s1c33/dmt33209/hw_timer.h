/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include "s_services.h"

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_TIMER		S1C33_INHNO_P16TIMER1B

#define S1C33_P16TIMER_CLOCK	40000000

#ifndef _MACRO_ONLY
/*
 *  �O���֐��̎Q��
 */
extern	ER	ena_int(INHNO);
extern	ER	dis_int(INHNO);

/*
 *  16�r�b�g�^�C�}1�̏�����
 */
Inline void
hw_timer_initialize(void)
{
	/*
	 *  16�r�b�g�^�C�}1B �����݋֎~
	 */
	dis_int(INHNO_TIMER);

	/*
	 *  16�r�b�g�^�C�}1B �����ݗv���N���A
	 */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntFactor[2] |= 0x40;

	/*
	 *  16bit�^�C�}1�ݒ�
	 *
	 *  �^�C�}�N���b�NON  16����  16�r�b�g�^�C�}1B ���� 1ms
	 */
	(*(s1c33TimerControl_t *) S1C33_TIMER_CONTROL_BASE).bP16ClkCtrl[1]
		= 0x0b;
	(*(s1c33P16Timer_t *) S1C33_P16TIMER_BASE).stChannel[1].uwComp[1]
		= ((S1C33_P16TIMER_CLOCK * 1) / (16 * 1000));

	/*
	 *  16�r�b�g�^�C�}���Z�b�g
	 */
	(*(s1c33P16Timer_t *) S1C33_P16TIMER_BASE).stChannel[1].bControl = 0x02;

	/*
	 *  16�r�b�g�^�C�}1B �����݋���
	 */
	ena_int(INHNO_TIMER);


	/*
	 *  16�r�b�g�^�C�}1 ����J�n
	 */
	(*(s1c33P16Timer_t *) S1C33_P16TIMER_BASE).stChannel[1].bControl = 0x01;

	return;
}

/*
 *  16�r�b�g�^�C�}1�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear(void)
{
	/*
	 *  16�r�b�g�^�C�}1B �����ݗv���N���A
	 */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntFactor[2] |= 0x40;

	return;
}

/*
 *  16�r�b�g�^�C�}1�̒�~
 */
Inline void
hw_timer_terminate(void)
{
	/*
	 *  16�r�b�g�^�C�}1B �����݋֎~
	 */
	dis_int(INHNO_TIMER);

	/*
	 *  16�r�b�g�^�C�}1��~
	 */
	(*(s1c33P16Timer_t *) S1C33_P16TIMER_BASE).stChannel[1].bControl = 0x00;

	return;
}

#endif /* _MACRO_ONLY  */
#endif /* _HW_TIMER_H_ */
