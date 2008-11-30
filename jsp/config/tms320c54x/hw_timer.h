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
 *  @(#) $Id: hw_timer.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include "c54x.h"

#define INHNO_TIMER TINT0_VEC

#ifndef _MACRO_ONLY

#define TO_CLOCK(nume,deno) (TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)       ((clock) * 1000 / TIMER_CLOCK)

#define MAX_CLOCK ((CLOCK) 0xffff)

#define GET_TOLERANCE 100

#define BEFORE_IREQ(clock) \
  ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


typedef UH CLOCK;

Inline void
hw_timer_initialize()
{
	CLOCK	c = TO_CLOCK(TIC_NUME,TIC_DENO);

	/* 0.25 ��sec�ŃJ�E���g���� */
	sil_wrh_mem((VP) TMU0_TCR, TCR_TSS | 0x0009);
//	sil_wrh_mem((VP) TMU0_TCR, TCR_TSS | 0x0001);
	/* �J�E���^�̐ݒ� */
	sil_wrh_mem((VP) TMU0_PRD, c - 1);
	/* �_�E���J�E���^�̏����l�ݒ� */
	sil_wrh_mem((VP) TMU0_TCR, (sil_reh_mem((VP) TMU0_TCR) | TCR_TRB));
	/* �^�C�}�̋N�� */
	sil_wrh_mem((VP) TMU0_TCR, (sil_reh_mem((VP) TMU0_TCR) & ~TCR_TSS));

	sil_wrh_mem((VP) IFR, (sil_reh_mem((VP) IFR) | (0x1 << TINT0)));
	sil_wrh_mem((VP) IMR, (sil_reh_mem((VP) IMR) | (0x1 << TINT0)));
}

Inline void
hw_timer_int_clear()
{
}

Inline void
hw_timer_terminate()
{
	sil_wrh_mem((VP) TMU0_TCR, (sil_reh_mem((VP) TMU0_TCR) | TCR_TSS));
	sil_wrh_mem((VP) IMR, (sil_reh_mem((VP) IMR) & ~(0x1 << TINT0)));
	sil_wrh_mem((VP) IFR, (sil_reh_mem((VP) IFR) | (0x1 << TINT0)));
}

Inline CLOCK
hw_timer_get_current(void)
{
	return(TO_CLOCK(TIC_NUME,TIC_DENO) - sil_reh_mem((VP) TMU0_TIM));
}

Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return(sil_reh_mem((VP) IFR) & (0x1 << TINT0));
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
