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
 *  @(#) $Id: sys_config.h,v 1.12 2008/07/09 22:52:44 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iDVE68K/40�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <sys_rename.h>


/*
 * CORTEX-M3�ڐA���́u���ߑ��v�B�R���p�C���G���[���Ԃ����߂�
 * �֋X��A��ɂ����֐��̒���CM3NI�Ə����Ă����B�ȉ���#define��`��
 * �R�����g�A�E�g����ƁA�ڐA���������Ă��Ȃ��֐���􂢏o����B
 * 
 * CORTEX-M3 Not Implemented
 */
#ifndef CM3NI
#define CM3NI
#endif

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define	TARGET_NAME	"CQ-STARM"

/*
 * NVIC���荞���܂߂���O�x�N�g���̃G���g�����B
 * 
 * STM32F103V�̏ꍇ�ANVIC���Ǘ����Ȃ�16�ƁA�Ǘ�����43�̌v59.
 * 
 * !!!!���ӁI�I�I�I
 * ��O�x�N�g���́A���̃T�C�Y�����傫��2�̙p[BYTE]�ɐ��񂵂Ȃ���΂Ȃ�Ȃ��B����� .ld�t�@�C����
 * �w������B
 * ( CORTEX-M3 Technical Reference Manual 8.2.2 NIVC Register Description ��
 * "Vector Table Offset Register" )
 */

#define EXCEPTION_VECTOR_ENTRY_NUM (16+43)

/*
 * ���荞�݃X�^�b�N�̃T�C�Y[BYTE]
 * 
 * TOPPERS/JSP�̊��荞�݂����p����X�^�b�N�B�\�Ȃ��ׂẴl�X�g���z���ł���傫���łȂ���΂Ȃ�Ȃ��B
 */

#define MASTER_STACK_SIZE 256

/*
 *  vxget_tim ���T�|�[�g���邩�ǂ����̒�`
 * 
 * �����ɔ����邪�A�^�[�Q�b�g�ˑ����ŗp�ӂ��Ȃ��Ȃ�ASUPPORT_VXGET_TIM��錾����B
 */
#define	SUPPORT_VXGET_TIM


/*
 *  �V���A���|�[�g���̒�`
 *  CORTEX-M3 : TNUM_PORT, TNUM_SIOP�̐��Ɋւ��Ă͗v����
 */
 CM3NI
#define TNUM_PORT	1	/* �T�|�[�g����V���A���|�[�g�̐� */
#define	TNUM_SIOP	1	/* �T�|�[�g����V���A��I/O�|�[�g�̐� */

/*
 *  �V���A���|�[�g�ԍ��Ɋւ����`
 */
#define	LOGTASK_PORTID	1	/* �V�X�e�����O�ɗp����V���A���|�[�g�ԍ� */

/*
 *  �V���A���|�[�g�̃{�[���[�g�Ɋւ����`
 *
 *  ��PD72001�̃{�[���[�g�W�F�l���[�^�ɐݒ肷�ׂ��l�D
 */
#define BRG1_DEF	0x00u		/* 9600bps�i��ʁj*/
#define BRG2_DEF	0x1eu		/* 9600bps�i���ʁj*/

/*
 *  �������ԑ҂��̂��߂̒�`
 */
#define	SIL_DLY_TIM1	420
#define	SIL_DLY_TIM2	90

#ifndef _MACRO_ONLY
/*
 *  �v���Z�b�T���ʂ̂��߂̕ϐ��i�}���`�v���Z�b�T�Ή��j
 */
extern UINT	board_id;	/* �{�[�hID */
extern VP	board_addr;	/* ���[�J���������̐擪�A�h���X */

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void	sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���DROM���j�^�^GDB STUB�ďo���Ŏ�������D
 */
extern void	sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���DROM���j�^�^GDB STUB�ďo���Ŏ�
 *  ������D
 */
extern void	sys_putc(char c);

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONFIG_H_ */
