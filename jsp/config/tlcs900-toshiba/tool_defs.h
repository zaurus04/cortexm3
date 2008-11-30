/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *	�J�����Ɉˑ������`
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_stddef.h �� itron.h �̐擪�ŃC���N���[
 *  �h�����D���̃t�@�C������͒��ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃C
 *  ���N���[�h�t�@�C���ɐ旧���ď�������邽�߁C���̃C���N���[�h�t�@�C
 *  ���Ɉˑ����Ă͂Ȃ�Ȃ��D
 */

#ifndef _TOOL_DEFS_H_
#define _TOOL_DEFS_H_

/*
 *  �R���p�C���ˑ��̃f�[�^�^�̒�`
 */
#define	_int8_		char		/* 8�r�b�g�̐����^ */
#define	_int16_		int		/* 16�r�b�g�̐����^ */
#define	_int32_		long		/* 32�r�b�g�̐����^ */

/*
 *  �R���p�C���̊g���@�\�̂��߂̃}�N����`
 */

#include "api.h"

/*
 *  TOSHIBA IDE�ł�#pragma inline�L�q�ɂăC�����C���֐����`����
 *  ���̂��߃J�[�l�������ɂ݈̂ȉ��̏�����K�p����D
 *  �J�[�l�����ʕ���Inline�����inline�̒�`�͑S�Ė����Ƃ��C���m��
 *  �C�����C���֐��ɑ΂���#pragma inline��`��kernel_inline_defs.h
 *  �ɋL�ڂ��C���̃t�@�C����{�ӏ��ɂăC���N���[�h����D
 */

#ifndef _MACRO_ONLY
#include "kernel_inline_defs.h"
#endif	/* _MACRO_ONLY	*/

#define	Inline


/*
 *  TOSHIBA IDE�ł͂Q��ނ̃C�����C���A�Z���u�����߂�����
 *  __asm	: ���W�X�^�ޔ�L��(�ᑬ�������W�X�^�j�󂪂Ȃ�)
 *  __ASM	: ���W�X�^�ޔ𖳂�(�����������W�X�^�j��ɒ���)
 *  �J�[�l�������Ŏg�p���邱�Ƃ�O���__AMS���̗p����
 */
#ifndef __cplusplus			/* C++ �ɂ� asm ������ */
#define	asm		__ASM
#endif /* __cplusplus */

#define	Asm		__ASM

#endif /* _TOOL_DEFS_H_ */
