/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2003 by Industrial Technology Institute,
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
 *  @(#) $Id: sys_config.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���̃T���v��
 *�@�@�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@�@�@�f�[�^�^�A�}�N���A�֐��̃v���g�^�C�v�錾
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  ���[�U�[��`���
 */
#include <user_config.h>

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <sys_rename.h>

/*
 *  �^�[�Q�b�g�V�X�e���̃n�[�h�E�F�A�����̒�`
 */
//#include <******.h>
//#include <******.h>


/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define	TARGET_NAME	"Target name"

/*
 *  �������ԑ҂��̂��߂̒�`
 */
#define	SIL_DLY_TIM1	1425
#define	SIL_DLY_TIM2	 350

#ifndef _MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void	sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���D
 *�@�@ROM���j�^�^GDB STUB�ďo���͖�����
 */
extern void	sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���D
 *�@�@ROM���j�^�^GDB STUB�ďo���͖�����
 */
extern void	sys_putc(char c) throw();

#endif /* _MACRO_ONLY */

/*  --------------------------------------------------------------  */
/*
 * PowerPC���ʕ��Ƃ̃C���^�[�t�F�[�X�̒�`
 */

/*
 *   MSR�̏����l
 */
#define INIT_MSR    	0

/*
 *  �����݂̖{��
 */
#define TMAX_INTNO       10

/*
 *  �����ݏ�����ICU�ˑ�����
 *  �@�������e
 *  �@�@�E�����ݗv���̔���
 *  �@�@�E�����݃}�X�N�̐ݒ�
 *  �@�@�E�����݋���
 *  �@�@�EC���ꃋ�[�`���Ăяo��
 *  �@�@�E�����݋֎~
 *  �@�@�E�i�K�v�ł���΁j���荞�ݗv���t���O�̃N���A
 *  �@
 *  �@����
 *  �@  label�F���x�����ʗp������
 *  �@  �@�@�@�@�i�����ӏ��ł��̃}�N�����g�p�ł���悤�ɂ��邽�߁j
 */
#define _PROC_ICU(label)

/* �}�N������label���m���ɓW�J���邽�߁A�}�N����2�d�ɂ��Ă��� */
#define PROC_ICU(label) _PROC_ICU(label)


/*
 * ���荞�݃R���g���[���̃}�X�NIPM�֘A�̒�`
 */

/*  IPM�̑Ҕ�  */
    /*  ���ӁFsp��4�o�C�g���E�Ɉێ�����  */
#define PUSH_ICU_IPM

/*  IPM�̕���  */
    /*  ���ӁFsp��4�o�C�g���E�Ɉێ�����  */
#define POP_ICU_IPM


#ifdef SUPPORT_CHG_IPM
/*
 * ICU�ɐݒ肷��IPM�p�����[�^�̃`�F�b�N
 *
 *�@C�����
 *  �@if (ipm�̒l���s��) {
 *	ercd = E_PAR;
 *	goto exit;
 *    }
 *�@�Ɠ����̏������s���}�N��
 */
#define CHECK_IPM(ipm)

/*
 * ���荞�݃R���g���[���̃}�X�N�擾
 */
#define GET_IPM(p_ipm)	

/*
 * ���荞�݃R���g���[���̃}�X�N�ݒ�
 */
#define CHG_IPM(ipm)

#endif	/*  SUPPORT_CHG_IPM  */


#ifndef _MACRO_ONLY

/*
 *  �����݃}�X�N�p�[���x�N�^�e�[�u��
 *	ipm_table���̂�$(CPU)�Ƃ̃C���^�[�t�F�[�X�Ɋ܂܂�Ȃ�
 *�@�@�@�idefine_ipm�ɂ��A�B������Ă���j
 */
extern IPM ipm_table[];

/*
 *  ���荞�݃��x���̐ݒ�
 *	�����ݔԍ�inhno�̊����݂��󂯕t�����Ƃ��Ɋ����݃R���g���[����
 *	IPM�ɐݒ肷��l���`����B
 *	�f�o�C�X�h���C�o�̏����������Ŏg�p����邱�Ƃ�z�肵�Ă���B
 *
 *�@�@�@����
 *�@�@�@�@inhno�F�����݃n���h���ԍ�
 *�@�@�@�@ipm�F�����݃}�X�N
 *
 */
Inline void
define_ipm(INHNO inhno, IPM ipm)
{
	ipm_table[inhno] = ipm;
}

#endif /* _MACRO_ONLY */

/*  
 *  �ȓd�̓��[�h�ւ̈ڍs�Ɗ����݋���
 *  �@���s���ׂ��^�X�N���Ȃ��Ċ����ݑ҂��ɂȂ�Ƃ���
 *  �@�f�B�X�p�b�`���̒��Ŏg�p�����B
 */ 
#define SAVE_POWPER	/*  �������e���A�Z���u���ŋL�q����  */


/* ----------------------------------------------------------------- */
/*
 * The IBM PowerPC Embedded Environment�p�̒�`
 */

/*
 * ��O�������[�`���̒�`�i�K�{�����j
 */

/*
 *  Critical Interrupt
 *  �@�I�t�Z�b�g�F0x100
 *  �@Critical Interrupt�̓C���v�������e�[�V�����ˑ��Ȃ̂�
 *  �@�������e�̓}�N����`���Ă����B
 *  �@�@�}�N�����FCRITICAL_INTERRUPT_EXCEPTION_PROC
 *  �@���̏������e��0x100�o�C�g�𒴂��Ă͂����Ȃ��B
 *  �@�i������ꍇ�͎c��̕�����ʂ̏ꏊ�ɔz�u���āA
 *  �@�@�����ɕ��򂷂邱�Ɓj
 *
 *  �@Critical Interrupt�̓J�[�l���Ǘ��O�̗�O�Ƃ���B
 *  �@�i���̏������[�`�����ŃT�[�r�X�R�[�����g�p���Ȃ��B�j
 *
 *�@�@��O�N���X�FCritical
 *  �@�@���^�[�����߂�rfci(Return From Critical Interrupt)
 *  �@�@��p����B
 */
#define CRITICAL_INTERRUPT_EXCEPTION_PROC	rfci
				/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */


/*
 *  �}�V���E�`�F�b�N��O
 *  �@���̏������e��0x100�o�C�g�𒴂��Ă͂����Ȃ��B
 *  �@�i������ꍇ�͎c��̕�����ʂ̏ꏊ�ɔz�u���āA
 *  �@�@�����ɕ��򂷂邱�Ɓj
 *
 *  �@�J�[�l���Ǘ��O�̗�O�Ƃ���B
 *  �@�i���̏������[�`�����ŃT�[�r�X�R�[�����g�p���Ȃ��B�j
 *
 *�@�@��O�N���X�FCritical
 *  �@�@���^�[�����߂�rfci(Return From Critical Interrupt)
 *  �@�@��p����B
 */
#define MACHINE_CHECK_PROC	rfci
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */

/*
 *  Programmable Interval timer
 *  �@�I�t�Z�b�g�F0x1000
 *  �@0x10�o�C�g�����̈悪���蓖�Ă��Ă��Ȃ��̂Œ���
 */
#define PROGRAMMABLE_INTERVAL_TIMER_PROC
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */

/*
 *  Fixed Interval timer
 *  �@�I�t�Z�b�g�F0x1010
 *  �@0x10�o�C�g�����̈悪���蓖�Ă��Ă��Ȃ��̂Œ���
 */
#define FIXED_INTERVAL_TIMER_PROC
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */

/*
 *  Watchdog timer
 *  �@�I�t�Z�b�g�F0x1020
 *
 *�@�@��O�N���X�FCritical
 *  �@�@���^�[�����߂�rfci(Return From Critical Interrupt)
 *  �@�@��p����B
 *
 *  �@0x10�o�C�g�����̈悪���蓖�Ă��Ă��Ȃ��̂Œ���
 *  �@�J�[�l���Ǘ��O�̗�O�Ƃ���B
 *  �@�i���̏������[�`�����ŃT�[�r�X�R�[�����g�p���Ȃ��B�j
 */
#define WATCHDOG_TIMER_PROC	rfci
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */

/*
 *  Data TLB miss
 *  �@�I�t�Z�b�g�F0x1100
 *  �@0x10�o�C�g�����̈悪���蓖�Ă��Ă��Ȃ��̂Œ���
 */
#define DATA_TLB_MISS_PROC
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */

/*
 *  Instruction TLB miss
 *  �@�I�t�Z�b�g�F0x1200
 *  �@0x10�o�C�g�����̈悪���蓖�Ă��Ă��Ȃ��̂Œ���
 */
#define INSTRUCTION_TLB_MISS_PROC
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */


/*
 *  Debug��O
 *  �@�I�t�Z�b�g�F0x2000
 *
 *�@�@��O�N���X�FCritical
 *  �@�@���^�[�����߂�rfci(Return From Critical Interrupt)
 *  �@�@��p����B
 *  �@
 *  �@�v���͈ȉ���7���
 *  �@�@Trap
 *  �@�@Instruction address compare
 *  �@�@Data address compare
 *  �@�@Instruction complete
 *  �@�@Branch taken
 *  �@�@Exception
 *  �@�@Unconditional debug event
 *  �@
 *  �@�J�[�l���Ǘ��O�̗�O�Ƃ���B
 *  �@�i���̏������[�`�����ŃT�[�r�X�R�[�����g�p���Ȃ��B�j
 *  �@
 *  �@0x10�o�C�g�����̈悪���蓖�Ă��Ă��Ȃ��̂Œ���
 */
#define DEBUG_PROC	rfci
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */

/*
 *  �C���v�������e�[�V������p�̏����i�I�t�Z�b�g�F0xd00-0xff0�j
 *    �C���v�������e�[�V�����ŗL�̗�O�x�N�^
 * �@ �I�t�Z�b�g�̎w����@�ɒ��ӂ��邱�ƁB
 *  �@��̓I�ɂ�
 *     .org �I�t�Z�b�g - EXCEPTION_VECTOR_BASE
 * �@ �̂悤�Ɏw�肷��B�ڂ����͑��̗�O�v���̊Y�������Q�ƁB
 *    �Ⴆ�΁APowerPC405�ł̓I�t�Z�b�g0xf20��
 *    APU Unavailable��O�̏�����z�u����
 */
//#define IMPLEMENT_EXCEPTION_D00_PROC
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */

/*
 * ��O�������[�`���̒�`�i�I�v�V���������j
 */
/*
 *  �C���v�������e�[�V������p�̏����i�I�t�Z�b�g�F0x2010-0x2ff0�j
 *    �C���v�������e�[�V�����ŗL�̗�O�x�N�^�i�P�Ƃ͌���Ȃ��j��
 *    ���̗p�r�Ɏg�p�����
 * �@ �I�t�Z�b�g�̎w����@�ɒ��ӂ��邱�ƁB
 *  �@��̓I�ɂ�
 *     .org �I�t�Z�b�g - EXCEPTION_VECTOR_BASE
 * �@ �̂悤�Ɏw�肷��B�ڂ����͑��̗�O�v���̊Y�������Q�ƁB
 */
// #define IMPLEMENT_EXCEPTION_02010_PROC
						/*  �A�Z���u���ŋL�q����  */
/*  ���̃}�N����`�̓f�o�C�X�ɍ��킹�Ċe�����������ĉ������B  */


#endif /* _SYS_CONFIG_H_ */

/*  end of file  */
