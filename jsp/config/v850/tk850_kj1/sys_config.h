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
 *  @(#) $Id: sys_config.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iTK-850/KJ1+�p �O��SRAM�{�[�h�t���j
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */

#include <sys_rename.h>

/*
 *  �^�[�Q�b�g�V�X�e���̃n�[�h�E�F�A�����̒�`
 */
#include "v850es_kj1.h"

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define	TARGET_NAME	"TK-850/KJ1+"

/*
 *  vxget_tim ���T�|�[�g���邩�ǂ����̒�`
 */
/* #define	SUPPORT_VXGET_TIM */

/*
 *  JSP�J�[�l�����쎞�̃������}�b�v�Ɗ֘A�����`
 */
#define	STACKTOP	(IRAM_TOP+IRAM_SIZE)	/* ��^�X�N�R���e�L�X�g�p�̃X�^�b�N�̏����l */

/* CPU����N���b�N���g���F20MHz(5MHz�~4) */
#define	CPU_CLOCK		20000000

/* ���荞�ݗv���̐� */
#define NUM_INTERRUPT	0x3B

/*
 *  �T�|�[�g����V���A���f�B�o�C�X�̐��͍ő� 2
 */
#define	CONSOLE_PORTID	1	/* �R���\�[���p�ɗp����V���A���|�[�g�ԍ��iKJ1+�ł�1or2�B3�͊��荞�݃x�N�^�[�̔Ԓn�����ł���̂ŕs�j */
#define TNUM_PORT		1
#define SEPARATE_SIO_INT	/* ��M���荞�݂Ƒ��M�������荞�݂���ʂ��ꂽ���荞�݂ɂȂ��Ă��邩 */
#define	LOGTASK_PORTID		CONSOLE_PORTID	/* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ�	*/

#ifndef _MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void	sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���DROM���j�^�ďo���Ŏ������邱�Ƃ�z�肵
 *  �Ă���D
 */
extern void	sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���DROM���j�^�ďo���Ŏ������邱
 *  �Ƃ�z�肵�Ă���D
 */
Inline void
sys_putc(char c)
{
	extern void cpu_putc(char c);
	/* ROM���j�^�Ȃǂ̃R���\�[���փ��b�Z�[�W�o�͂���჌�x���֐���z�肵�Ă��邪
	   �ʓ|�Ȃ̂ŃV�X�e���̃V���A���|�[�g�֏o�͂��� */
	cpu_putc(c);
}

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONFIG_H_ */
