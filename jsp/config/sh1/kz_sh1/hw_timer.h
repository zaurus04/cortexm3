/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 * 
 *  @(#) $Id: hw_timer.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�^�C�}�h���C�o�iKZ-SH1�p�j
 *�@�@�@�@�@SH1������TMU0���g�p
 *
 *�@�@�@�@�@�����݃R���g���[���ˑ��͂��̃t�@�C���ɋL�q����
 *�@�@�@�@�@�^�C�}�f�o�C�X���̂Ɉˑ����鏈����sh1itu.h�ɋL�q����
 *
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <sh1_sil.h>

#ifndef _MACRO_ONLY
#include <sh1itu.h>
#endif /* _MACRO_ONLY */

/*
 *  �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_TIMER	IMIA0

#ifndef _MACRO_ONLY

/*  �����݃��x����ݒ背�W�X�^�ɑ������Ƃ��̃V�t�g��  */
#define ITU_BIT_SHIFT	4



/*
 *  �^�C�}�����ݗv���̃N���A
 */
#define hw_timer_int_clear	sh1_itu_int_clear


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize(void)
{
	/*
	 *  �^�C�}�f�o�C�X���̂̏�����
	 */
	sh1_itu_initialize();

	/*
	 *  �����݊֘A�̐ݒ�
	 */
						/* ���荞�݃��x���ݒ� 	*/
	define_int_plevel(IPRC, TIMER_INTLVL, ITU_BIT_SHIFT);
	sh1_itu_int_clear();		/*  �����ݗv�����N���A  */

	sh1_itu_start();		/* �^�C�}�X�^�[�g    	*/
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
#define hw_timer_terminate		sh1_itu_terminate

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 *�@�@�@�^�C�}�̓�����ꎞ�I�ɒ�~���C�^�C�}�l��ǂݏo���D
 */
#define hw_timer_get_current		sh1_itu_get_current

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
#define hw_timer_fetch_interrupt	sh1_itu_fetch_interrupt

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */