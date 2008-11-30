/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <sys_rename.h>

/*
 *  �V�X�e���ˑ��̃C���N���[�h�t�@�C���̓ǂݍ���
 */
#include <h8s2350.h>
#include <mispo_h8s2350.h>

/*
 *  vgxet_tim ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_VXGET_TIM

/*
 *  �V���A���|�[�g���̒�`
 */
#define TNUM_PORT	2u	/* �T�|�[�g����V���A���|�[�g�̐� */
#define	TNUM_SIOP	2u	/* �T�|�[�g����V���A��I/O�|�[�g�̐� */

/*
 *  �V�X�e���^�X�N�Ɋւ����`
 */
#define	LOGTASK_PORTID	1	/* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ� */
#define	CONSOLE_PORTID	1	/* �R���\�[���p���o�͂���V���A���|�[�g�ԍ� */
		/* CONSOLE_PORTID : monitor ���� */

/*
 *  �������ԑ҂��̂��߂̒�`
 */
#define	SIL_DLY_TIM1	22620
#define	SIL_DLY_TIM2	3865

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

extern void	sys_putc(char c) throw();

#endif /* _MACRO_ONLY */

/*============================================================================*/
/* �ȉ��́A���ʃh�L�������g�ɖ����Ǝ��̒�` */

/*
 *  JSP�J�[�l�����쎞�̃������}�b�v (release.ld)
 *      0x000000 - 0x01ffff     �R�[�h�̈�(128kB)
 *      0x200000 -              �f�[�^�̈�(128kB)
 *               - 0x21ffff     �^�X�N�Ɨ����p�X�^�b�N�C�������I��
 */

/*
 *  JSP�J�[�l�����쎞�̃������}�b�v (debug.ld)
 *      0x200000 - 0x20ffff     �R�[�h�̈�(64kB)
 *      0x210000 -              �f�[�^�̈�(64kB-8kB(for GDB_STUB))
 *               - 0x21efff     �^�X�N�Ɨ����p�X�^�b�N�C�������I��
 */

/*
 *   �X�^�b�N�̈�̒�`
 */
#ifndef GDB_STUB
#define STACKTOP    	0x21fffc	/* �^�X�N�Ɨ����p�X�^�b�N�̏����l */
#else /* GDB_STUB */
#define STACKTOP    	0x21effc	/* �^�X�N�Ɨ����p�X�^�b�N�̏����l */
#endif /* GDB_STUB */

#define str_STACKTOP	TO_STRING(STACKTOP)

/*
 *  �����݃��x����`
 */
#define SCI0_INT_LVL	3u		/* SCI�`���l��0�̊��荞�݃��x�� */
#define SCI1_INT_LVL	3u		/* SCI�`���l��1�̊��荞�݃��x�� */
#define TPU0_INT_LVL	5u		/* TPU�`���l��0�̊��荞�݃��x�� */

/*
 *  �V���A���R���g���[���̃{�[���[�g�̐ݒ�
 */
/* #define BAUD_RATE	9600u */	/* bps */
#define BAUD_RATE	38400u
/* #define BAUD_RATE	57600u */

#endif /* _SYS_CONFIG_H_ */
