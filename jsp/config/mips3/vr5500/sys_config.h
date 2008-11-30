/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 *  �����݃R���g���[���E�{�[�h�ˑ��̃C���N���[�h�t�@�C���̓ǂݍ���
 */
#include <pic_icu.h>	/* �����݃R���g���[���֌W�̏���<CPU>�ɓn���� */
#include <vr5500.h>	/* NOP_FOR_CP0_HAZARD�̏���cpu_support.S�ɓn���� */

/*
 *  vgxet_tim ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_VXGET_TIM

/*
 *  �V���A���|�[�g���̒�`
 */
#ifndef GDB_STUB
#define TNUM_SIOP	2u	/* �T�|�[�g����V���A���|�[�g�̐� */
#define TNUM_PORT	2u	/* �T�|�[�g����V���A��I/O�|�[�g�̐� */
#else  /* GDB_STUB */
#define TNUM_SIOP	1u	/* �T�|�[�g����V���A���|�[�g�̐� */
#define TNUM_PORT	1u	/* �T�|�[�g����V���A��I/O�|�[�g�̐� */
				/* GDB_STUB �𗘗p����Ƃ��́ASCC1�� GDB_STUB ��
				   ���p���邽�߂ɁASCC0�݂̂������p�ł��Ȃ��B */
#endif /* GDB_STUB */


/*
 *  �V�X�e���^�X�N�Ɋւ����`
 */
#define	LOGTASK_PORTID	1u	/* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ� */

/*
 *  �������ԑ҂��̂��߂̒�`
 */
#define	SIL_DLY_TIM1	2865
#define	SIL_DLY_TIM2	398

/*
 *  �����݃}�X�N�̏����l (MIPS3�R�A�̂��^�[�Q�b�g�V�X�e���ˑ��Ȃ̂ŁA�����Œ�`)
 */

/*  MIPS3�R�A�̊֌W */
/*  �����I�Ȋ����ݐ���́A�O�������݃R���g���[���ōs�����߁AMIPS3�R�A�Ɋւ��Ă�
    �\�ȕ���������B*/
/*  RTE-VR5500-CB�ł�2�{�̊����ݐ����ڑ�����Ă���B */
#define INIT_CORE_IPM	( Cause_Int1 | Cause_Int0 )

/*  �O�������݃R���g���[���֌W  */
/*  (�����ݐ��O�ɂ����āA�^�C�}�O�̂݊����݋��j */
#define INIT_INT0M	TIMER0
#define INIT_INT1M	0u

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
 *  �X�e�[�^�X���W�X�^�̏����l
 */
#define INIT_SR		(SR_BEV | INIT_CORE_IPM | SR_DE)
	/*
	 *  BEV = 1�F��O�x�N�^��kseg0�Z�O�����g�ɔz�u
	 *  IM = 0�FCPU���b�N��� (�����݋֎~)
	 *  DE = 1 : �L���b�V���p���e�B�G���[�ɂ���O�����̋֎~
	 */

/*
 *  �R���t�B�O���W�X�^�����l�ݒ�p�}�X�N
 */
#define INIT_CONFIG_MASK	0x0

/*
 *  �V���A���R���g���[���̃{�[���[�g�̐ݒ� (������ݒ�f�[�^�G[bps]�Ŏw��)
 */
#define DEVIDE_RATIO	9600u	/*  9600bps��I��  */

#endif /* _SYS_CONFIG_H_ */
