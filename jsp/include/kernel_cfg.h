/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: kernel_cfg.h,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *	kernel_cfg.c �p�C���N���[�h�t�@�C��
 */

#ifndef _KERNEL_CFG_H_
#define _KERNEL_CFG_H_

/*
 *  �J�[�l���W���C���N���[�h�t�@�C��
 */
#include <../kernel/jsp_kernel.h>

/*
 *  �J�[�l���̊e�C���N���[�h�t�@�C��
 */
#include <../kernel/task.h>
#include <../kernel/semaphore.h>
#include <../kernel/eventflag.h>
#include <../kernel/dataqueue.h>
#include <../kernel/mailbox.h>
#include <../kernel/mempfix.h>
#include <../kernel/cyclic.h>
#include <../kernel/interrupt.h>
#include <../kernel/exception.h>
#include <../kernel/time_event.h>

/*
 *  �J�[�l���̃��[�N�G���A���`���邽�߂̃f�[�^�^
 *
 *  �X�^�b�N�̈�ƌŒ蒷�������v�[���̈���CVP�^�̃T�C�Y�����傫���P
 *  �ʂŃA���C��������K�v������ꍇ�ɂ́C__STK_UNIT ��__MPF_UNIT ���C
 *  ���ꂼ��A���C��������P�ʂ̃f�[�^�^�ɒ�`����D
 *
 *  �ȉ��̒�`�́C__STK_UNIT ����� __MPF_UNIT �̃T�C�Y�� 2�̋Џ�ł�
 *  �邱�Ƃ����肵�Ă���D
 */

#ifndef __STK_UNIT
typedef VP	__STK_UNIT;
#endif /* __STK_UNIT */

#ifndef __MPF_UNIT
typedef VP	__MPF_UNIT;
#endif /* __MPF_UNIT */

#define __TROUND_STK_UNIT(sz) \
		(((sz) + sizeof(__STK_UNIT) - 1) & ~(sizeof(__STK_UNIT) - 1))
#define __TCOUNT_STK_UNIT(sz) \
		(((sz) + sizeof(__STK_UNIT) - 1) / sizeof(__STK_UNIT))

#define __TROUND_MPF_UNIT(sz) \
		(((sz) + sizeof(__MPF_UNIT) - 1) & ~(sizeof(__MPF_UNIT) - 1))
#define __TCOUNT_MPF_UNIT(sz) \
		(((sz) + sizeof(__MPF_UNIT) - 1) / sizeof(__MPF_UNIT))

/*
 *  ���l�[�������V���{�������ɖ߂����߂̃C���N���[�h�t�@�C��
 */
#include <../kernel/jsp_unrename.h>
#include <sys_unrename.h>
#include <cpu_unrename.h>

#endif /* _KERNEL_CFG_H_ */
