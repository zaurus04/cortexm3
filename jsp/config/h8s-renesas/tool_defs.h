/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: tool_defs.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *�@�J�����Ɉˑ������`
 *�@�@�A�v���P�[�V�������K�v�Ƃ����`
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_stddef.h �� itron.h �̐擪�ŃC���N���[
 *  �h�����D���̃t�@�C������͒��ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃C
 *  ���N���[�h�t�@�C���ɐ旧���ď�������邽�߁C���̃C���N���[�h�t�@�C
 *  ���Ɉˑ����Ă͂Ȃ�Ȃ��D
 */

#ifndef _TOOL_DEFS_H_
#define _TOOL_DEFS_H_

#include <sys_tool_defs.h>	/*  �{�[�h���̃f�o�b�O����`  */

/*
 *  �R���p�C���ˑ��̃f�[�^�^�̒�`
 */
#define _int8_          char            /* 8�r�b�g�̐����^      */
#define _int16_         int             /* 16�r�b�g�̐����^     */
#define _int32_         long            /* 32�r�b�g�̐����^     */
/* 64�r�b�g�̐����^�͖��T�|�[�g */

/*
 * _bool_�͖���`��OK
 * �@�f�t�H���g��BOOL�^��int�^�i16�r�b�g�j
 *
 * _vp_int_�͖���`��OK
 * �@�f�t�H���g��VP_INT�^��VP�^��void *�^
 * �@�@32�r�b�g�Ȃ̂ŁAint�^���|�C���^�^���i�[�ł���
 *
 * _intptr_�͖���`��OK
 * �@�f�t�H���g��long���g�p�����̂ŁAint�^���|�C���^�^���i�[�ł���
 */

/*
 *  �R���p�C���̊g���@�\�̂��߂̃}�N����`
 */
#ifndef __cplusplus                     /* C++ �ɂ� inline ������ */
#ifdef __STDC_VERSION__
#if __STDC_VERSION__ < 199901L          /* C99 �ɂ� inline ������ */
#define inline          __inline
#endif /* __STDC_VERSION__ < 199901L */
#endif /* __STDC_VERSION__ */
#endif /* __cplusplus */

#define Inline          static inline

/*
 *  �C�����C���A�Z���u����#pragma inline_asm�錾�����Ȃ���
 *�@�g���Ȃ����߁Aasm,Asm�}�N���̒�`�͏ȗ�����
 *�@�i�֐��̃v���g�^�C�v�錾�ɃL�[���[�h��ǉ����Ă������j
 */

#endif /* _TOOL_DEFS_H_ */
