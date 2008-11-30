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
 *  �^�[�Q�b�g�V�X�e���Ɉˑ������`�iSolution Engine�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

/*
 *  �^�[�Q�b�g�{�[�h���̐ݒ��Ǎ���
 */
#ifdef MS7729RSE01
#include <ms7729rse01.h>
#elif  MS7709ASE01
#include <ms7709ase01.h>
#elif MS7750SE01
#include <ms7750se01.h>
#endif /* MS7729RSE01 */


/*
 *  JSP�J�[�l�����쎞�̃������}�b�v 
 *      0c000000 - 0c000fff     stub�̃��[�N�G���A
 *      0c001000 - 0c100000     �R�[�h�̈�(1MB)
 *      0c100000 -              �f�[�^�̈�(3MB)
 *               - 0c3fffff     �^�X�N�Ɨ����p�X�^�b�N
 *               - 0c400000     �������I��
 *
 */

/*
 *   �X�^�b�N�̈�̒�`
 */
#define STACKTOP    0x0c400000    /* �^�X�N�Ɨ����p�X�^�b�N�̏����l */


/*
 *  �^�C���e�B�b�N�̒�`
 */
#define	TIC_NUME	1		/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1		/* �^�C���e�B�b�N�̎����̕��� */

/*
 *  �^�C�}�[�̊��荞�݃��x��
 */
#define KTIM_INT_LV   4


#ifndef _MACRO_ONLY

/*
 * �V�X�e���̒��f����
 */
#ifdef GDB_STUB
Inline void
kernel_abort()
{
    Asm("trapa #0xff");
}

#else /* GDB_STUB */

Inline void
kernel_abort()
{

}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */


#endif /* _SYS_DEFS_H_ */













