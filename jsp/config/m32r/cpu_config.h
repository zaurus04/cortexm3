/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006 by Monami Software Limited Partnership, JAPAN	
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

//#include <sys_config.h>

/*
 *	�v���Z�b�T�ˑ����W���[���iM32R�p�j
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

#include <cpu_rename.h>

#include "m32r.h"

/*
 *  chg_ipm/get_ipm ���T�|�[�g���邩�ǂ����̒�`
 */
/*#define	SUPPORT_CHG_IPM*/

/*
 *  TCB �֘A�̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 */
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	unsigned long sp;		/* �X�^�b�N�|�C���^ */
	FP	pc;					/* �v���O�����J�E���^ */
} CTXB;

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU���b�N�Ƃ��̉���
 *
 *  CPU���b�N��CPU���������ݗv������/�֎~�ɑΉ��t����BPSW��IE�r�b�g
 *  �𑀍삷��B
 */

#define t_lock_cpu		lock_cpu
#define i_lock_cpu		lock_cpu
#define t_unlock_cpu	unlock_cpu
#define i_unlock_cpu	unlock_cpu
#define ena_int			lock_cpu
#define dis_int			unlock_cpu

Inline void
lock_cpu()
{
	__asm("mvfc r0, psw        \n"
	      "and3 r0, r0, 0xffbf \n"
	      "mvtc r0, psw " : : : "r0");
}

Inline void
unlock_cpu()
{
	__asm("mvfc r0, psw       \n"
	      "or3  r0, r0, 0x40  \n"
	      "mvtc r0, psw " : : : "r0");
}

/*
 *  sense_context
 *  
 *  ���[�U�X�^�b�N���g���Ă���Ȃ�^�X�N�R���e�L�X�g
 */

Inline BOOL
sense_context(void)
{
	int psw;
	__asm("mvfc	%0, psw" : "=r"(psw));
	return (psw & 0x80) != 0 ? FALSE : TRUE;
}

/*
 *  sense_lock
 *  
 *  �����݋֎~�Ȃ�CPU���b�N���
 */
Inline BOOL
sense_lock(void)
{
	int psw;
	__asm("mvfc	%0, psw" : "=r"(psw));
	return (psw & 0x40) != 0 ? FALSE : TRUE;
}

/*
 *  �^�X�N�f�B�X�p�b�`��
 */

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�icpu_support.S�j
 *
 *  dispatch �́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[������
 *  ���ŁCCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.S�j
 *
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	exit_and_dispatch(void);

/*
 *  �����݃n���h���^CPU��O�n���h���̐ݒ�
 */

extern FP InterruptHandlerEntry[NUM_INTERRUPT];
extern FP ExceptionHandlerEntry[NUM_EXCEPTION];

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{
	InterruptHandlerEntry[inhno-1] = inthdr;
}

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ肷��D
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
	ExceptionHandlerEntry[excno-1] = exchdr;
}

/*
 *  �����݃n���h���^CPU��O�n���h���̏o��������
 */


/*
 *  �����݃n���h���̏o���������̐����}�N��
 *
 *  reqflg ���`�F�b�N����O�Ɋ����݂��֎~���Ȃ��ƁCreqflg ���`�F�b�N��
 *  �ɋN�����ꂽ�����݃n���h�����Ńf�B�X�p�b�`���v�����ꂽ�ꍇ�ɁC�f�B
 *  �X�p�b�`����Ȃ��D
 */
#define INT_ENTRY(hdr) hdr
#define INTHDR_ENTRY(entry)	extern void entry();

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 *  CPU��O�n���h���́C��^�X�N�R���e�L�X�g�Ŏ��s����D���̂��߁CCPU��
 *  �O�n���h�����Ăяo���O�Ɋ����݃��[�h�Ɉڍs���C���^�[�����Ă������
 *  ���̃��[�h�ɖ߂��D���̃��[�h�ɖ߂����߂ɁC�����݃��[�h�Ɉڍs����O
 *  �� SR �������݃X�^�b�N��ɕۑ�����DCPU��O���^�X�N�R���e�L�X�g��
 *  �������Creqflg �� TRUE �ɂȂ������ɁCret_exc �֕��򂷂�D
 *  reqflg ���`�F�b�N����O�Ɋ����݂��֎~���Ȃ��ƁCreqflg ���`�F�b�N��
 *  �ɋN�����ꂽ�����݃n���h�����Ńf�B�X�p�b�`���v�����ꂽ�ꍇ�ɁC�f�B
 *  �X�p�b�`����Ȃ��D
 */
#define EXC_ENTRY(hdr) hdr
#define EXCHDR_ENTRY(entry)	extern void entry();

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g
 *
 *  ��^�X�N�R���e�L�X�g�̏ꍇ��TRUE��Ԃ��Dp_excinf�ɗ�O�n���h������
 *  �яo���ۂ̃X�^�b�N�|�C���^���i�[����Ă���icpu_support.S�j�̂ŁC
 *  ���������O��������psw���擾���R���e�L�X�g�𔻒f����D
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return (((unsigned int*)p_excinf)[1] & 0x8000) == 0;
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return (((unsigned int*)p_excinf)[1] & 0x4000) == 0;
}

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void	cpu_terminate(void);

/*
 * ���ݏ������̊����ݗD��x
 */
extern ER get_ipr(IPR *);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
