/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005 by Freelines CO.,Ltd 
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
 *  @(#) $Id: hw_timer.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�ˑ��^�C�}���W���[���iV850ES/KJ1+�����^�C�}0-ch0(TM00)�p�j
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>

#ifndef _MACRO_ONLY

/* �V�X�e���^�C�}�[��TM00���g�p */
#define	TIMER_INT_PRIORITY		0		/* ���荞�ݗD��x(0���ō���7���Œ�) */
#define	TIMER_COMPAREVALUE		((CPU_CLOCK>>1)/1000)		/* fx/2��1msec����� */


#define WAIT __asm("nop;nop;nop;nop");

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	       (0x10)

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UW	CLOCK;

#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)      ((clock) * 1000 / TIMER_CLOCK)

/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize(void)
{
	/* �^�C�}������ */
	sil_wrb_mem((VP)PRM00, 0);		/* fx/2 */
	sil_wrh_mem((VP)CR000, TIMER_COMPAREVALUE);
	sil_wrb_mem((VP)CRC00, 4);			/* CR0x0���L���v�`�� */
	sil_wrb_mem((VP)TMC00, 0x0c);		/* �L���v�`����Clear&Start */

	/* �����ݗv�����������A�����݋��ɂ��āA�D��x��ݒ肷�� */
	sil_wrb_mem((VP)TM0IC00, TIMER_INT_PRIORITY);
}

/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear(void)
{
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
hw_timer_terminate(void)
{
	/* �����݂��}�X�N���� */
	sil_wrb_mem((VP)TM0IC00, sil_reb_mem((VP)TM0IC00) | 0x40);
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return sil_reb_mem((VP)TM00);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return (sil_reb_mem((VP)TM0IC00) & 0x80) != 0;
}

#endif /* _MACRO_ONLY */

#endif /* _HW_TIMER_H_ */
