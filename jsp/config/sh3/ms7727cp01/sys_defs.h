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
 *  @(#) $Id: sys_defs.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *  �^�[�Q�b�g�V�X�e���Ɉˑ������`�iMS7717CP01�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

/*
 *  �V�X�e���Ɉˑ������`
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g��
 */
#define	TARGET_NAME	"MS7727CP01(SH7727 T-Engine)"

/*
 * �v���Z�b�T�̎��(DSP�ɂ͑Ή����Ă��Ȃ�)
 */
#define SH3
#define SH7727

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN  SIL_ENDIAN_LITTLE  /* ���g���G���f�B�A�� */


/*
 *  JSP�J�[�l�����쎞�̃������}�b�v
 *      0x8c000000 - 0x8c000000 �x�N�^�e�[�u��
 *      0x8c000500 - 0x8c001fff T-Monitor�g�p�̈�
 *      0x8c002000 - 0x8cffffff �R�[�h�̈�(1MB)
 *      0x8c100000 -            �f�[�^�̈�(3MB)
 *                 - 0x8c3fffff �^�X�N�Ɨ����p�X�^�b�N
 *                 - 0x8e000000 �������I��
 *
 */

/*
 *   �X�^�b�N�̈�̒�`
 */
#define STACKTOP    0x8c400000    /* �^�X�N�Ɨ����p�X�^�b�N�̏����l */

/*
 *  �^�C���e�B�b�N�̒�`
 */
#define	TIC_NUME	1		/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1		/* �^�C���e�B�b�N�̎����̕��� */

/*
 *  �^�C�}�[�̊��荞�݃��x��
 */
#define KTIM_INT_LV   4

/*
 *  �^�C�}�l�̓����\���� msec �P�ʂƂ̕ϊ�
 *  MS7727CP01�ł́AP�N���b�N��24MHz
 *  ������ /4,/16,/64/256 �̂����ꂩ��I��
 *  /4:  6Mhz     tick 6000   0.16 ��sec
 *  /16: 1.5Mhz   tick 1500   0.6 ��sec
 *  /64: 0.375Mhz tick 375    2.6 ��sec
 *  /256:0.097Mhz tick 97     10 ��sec
 *
 *  /16 ��I��
 *  TMU�̃N���b�N�̏����2Mhz
 */

#define TCR0_TPSC  0x0001


/*
 *  �^�C�}�l�̓����\���ƃ~���b�P�ʂƂ̕ϊ�
 */
#define TIMER_CLOCK     1600

/*
 *  �������ԑ҂��̂��߂̒�`
 */
#define	SIL_DLY_TIM1	 90
#define	SIL_DLY_TIM2	 50


#ifndef _MACRO_ONLY


Inline void
kernel_abort()
{
    UW sr = 0x10000000;
    
    /*
     * �����I�Ƀ��Z�b�g�𔭐�������
     */
    /*
     * BL�r�b�g�𗧂Ă�
     */
	Asm("ldc %0, sr" : : "r"(sr) );
    
    /*
     * �����ݗ�O
     */
    *((volatile int *) 0xFFFFFEC1) = 0;
}
#endif /* _MACRO_ONLY */


#endif /* _SYS_DEFS_H_ */













