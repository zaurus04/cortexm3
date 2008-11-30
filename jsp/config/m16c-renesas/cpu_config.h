/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */


/*
 *  �v���Z�b�T�ˑ����W���[���iM16C�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

#ifdef NEED_API
#include "api.h"
#endif /* NEED_API */

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <cpu_rename.h>

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 */
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */
#define TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */
#define TBIT_TCB_PRIORITY	4	/* priority �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY

/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	void	*sp;	/* �X�^�b�N�|�C���^(near�Œ�) */
	FP		pc;	/* �v���O�����J�E���^ */
} CTXB;

/* 
 *  ������/CPU��O�l�X�g�J�E���^
 */
extern char	intnest;

/*
 *  �V�X�e����Ԃ̎Q��
 */

/*
 *  ���݂̃R���e�L�X�g��Ԃ��֐�.
 *  ��^�X�N�R���e�L�X�g�Ȃ�TRUE��Ԃ�.
 */
Inline BOOL
sense_context(void)
{
	/*  �l�X�g�J�E���^0����Ȃ��^�X�N�R���e�L�X�g  */
	return(intnest > 0);
}

/*
 *  ���݂�CPU���b�N��Ԃ�Ԃ��֐�.
 *  CPU���b�N��ԂȂ�TRUE��Ԃ�.
 */
Inline BOOL
sense_lock(void)
{
	return((current_flgreg() & FLG_I_MASK) == 0);
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU���b�N�Ƃ��̉���
 */
Inline void
lock_cpu(void)
{
	disint();
}

Inline void
unlock_cpu(void)
{
	enaint();
}

#define t_lock_cpu	lock_cpu
#define i_lock_cpu	lock_cpu
#define t_unlock_cpu	unlock_cpu
#define i_unlock_cpu	unlock_cpu

/*
 *  �^�X�N�f�B�X�p�b�`��
 */

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�icpu_support.a30�j
 *
 *  dispatch �́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ
 *  �T�[�r�X�R�[�������̒�����CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`(cpu_support.a30)
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	exit_and_dispatch(void);

/*
 *  �����݃n���h���^CPU��O�n���h���̐ݒ�
 */

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 *  �����݃n���h����o�^����x�N�^�e�[�u����ROM��Ɏ��,
 *  �����ɏ�������. ���̂��߂����ł͉������Ȃ��D
 */

Inline void
define_inh(INHNO inhno, FP inthdr)
{
}

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ肷��D
 *  �����݃n���h����o�^����x�N�^�e�[�u����ROM��Ɏ��,
 *  �����ɏ�������. ���̂��߂����ł͉������Ȃ��D
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
}

/*
 *  �����݃n���h���^CPU��O�n���h���̏o��������
 *
 *  �����݁^CPU��O����������CPU�̏�Ԃ͎��̂Ƃ���.
 *
 *  FLG���W�X�^��I�r�b�g�� 0(�����݋֎~) 
 *  FLG���W�X�^��IPL�͎󂯕t���������݂�IPL
 *  FLG���W�X�^��U�r�b�g��, �����݂̎�ނɂ���ĈقȂ邪,
 *  �J�[�l���ł�ISP�݂̂��g�p��, USP���g�p���Ă��Ȃ�����,
 *  �����ł͖��ƂȂ�Ȃ�.
 *
 *  ������/��O�������ɂ�, �����I�� FLG, PC���X�^�b�N�֕ۑ������.
 *  �o����������ł͂܂��c��̃��W�X�^���X�^�b�N�ɕۑ�����.
 *  ���i�̊����݂̏ꍇ�̓^�X�N�̃X�^�b�N��,
 *  ���d���荞�݂̏ꍇ�͊����ݗp�̃X�^�b�N��, ���ꂼ��ۑ������.
 *
 *  ���̌�, �X�^�b�N�|�C���^�̒l�� r1 ��, 
 *  �����݃n���h���̃A�h���X�� a1 �� a0 �Ɋi�[������Ԃ�
 *  �����ݏo���������̌㔼�փW�����v����.
 */

/*
 *  �����݃n���h���̏o���������̐����}�N��
 *
 *  �����ݔ������A���s���̃��W�X�^�̒l���X�^�b�N�ɑޔ�����D���̌�A�X
 *  �^�b�N�̒l��R1���W�X�^�ɃZ�b�g���A�Z���u���ŋL�q���ꂽ�n���h�����O
 *  �v���O�����ɕ��򂷂�D
 */

#define INTHDR_ENTRY(inthdr)\
extern void inthdr##_entry(void);\
asm("	.glb _" #inthdr "						");\
asm("	.glb __kernel_interrupt						");\
asm("	.section program, code, align					");\
asm("_" #inthdr "_entry:						");\
asm("	pushm	r0,r1,r2,r3,a0,a1,sb,fb	; ���W�X�^���^�X�N�X�^�b�N�֑ޔ�");\
asm("	stc	isp, r1			; �X�^�b�N�|�C���^�����o��	");\
asm("	mov.w	#_" #inthdr "&0ffffh, a0; �����݃n���h���̉���2�o�C�g	");\
asm("	mov.w	#_" #inthdr ">>16, a1	; �����݃n���h���̏��2�o�C�g	");\
asm("	jmp	__kernel_interrupt	; �����ݏ������[�`���㔼��	");

#define INT_ENTRY(inthdr)	inthdr##_entry

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 *  CPU��O�n���h���̊�{�I�ȏ����͊����݃n���h���Ƌ��L����D�����݃n
 *  ���h���Ƃ̈Ⴂ�̓X�^�b�N�l��ޔ�����R1���W�X�^�̒l��p_excinf�Ƃ���
 *  �g�p���邩�A���Ȃ����̍��ق݂̂ł��D
 */

#define EXCHDR_ENTRY(exchdr)\
extern void exchdr##_entry(void);\
asm("	.glb $" #exchdr "		 				");\
asm("	.glb __kernel_interrupt		 				");\
asm("	.section program, code, align					");\
asm("_" #exchdr "_entry:						");\
asm("	pushm	r0,r1,r2,r3,a0,a1,sb,fb	; ���W�X�^���^�X�N�X�^�b�N�֑ޔ�");\
asm("	stc	isp, r1			; �X�^�b�N�|�C���^�����o��	");\
asm("	mov.w	#$" #exchdr "&0ffffh, a0; �����݃n���h���̉���2�o�C�g	");\
asm("	mov.w	#$" #exchdr ">>16, a1	; �����݃n���h���̏��2�o�C�g	");\
asm("	jmp	__kernel_interrupt	; �����ݏ������[�`���㔼��	");

#define EXC_ENTRY(exchdr) exchdr##_entry

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	/* 
	 *  �l�X�g�J�E���^��1����Ȃ��^�X�N�R���e�L�X�g
	 */
	return( intnest > 1);
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	/*
	 *  ��O�����O��FLG���W�X�^I�r�b�g��0�Ȃ�CPU���b�N���
	 *
	 *  �����̒萔18��CPU��O����������Ń��W�X�^���X�^�b�N�ɂǂ�
	 *  �ۑ�����Ă��邩�Ɉˑ����Č��肷�鐔�l
	 */
	return( ( *(char *)((char *)p_excinf+18) & FLG_I_MASK ) == 0);
}

/*
 *  �v���Z�b�T�ˑ��̏�����(cpu_config.c)
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������(cpu_config.c)
 */
extern void	cpu_terminate(void);

/*
 * ���荞�ݐ��䃌�W�X�^���荞�ݗD��x�ύX
 */
extern void set_ic_ilvl(VP addr, UB val);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
