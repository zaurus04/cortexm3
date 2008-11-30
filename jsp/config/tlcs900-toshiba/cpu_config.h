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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iTLCS-900L1�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

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
 *  chg_ipm/get_ipm ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_CHG_IPM

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_PRIORITY	4	/* priority �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	VP	xsp;		/* �X�^�b�N�|�C���^ */
	FP	pc;		/* �v���O�����J�E���^ */
} CTXB;

/* 
 *  ������/CPU��O�l�X�g�J�E���^
 */
extern UINT	intcnt;

/*
 *  �����݃}�X�N���색�C�u����
 *
 *  �����݃}�X�N�iintmask�j�́CIPM�iInterrupt Priority Mask�j��12�r�b�g
 *  ���ɃV�t�g�������̂ł���D
 */

/*
 *  ���݂̊����݃}�X�N�̓Ǐo��
 */
#pragma inline current_intmask
UH
current_intmask()
{
	return(current_sr() & 0x7000);
}

/*
 *  �����݃}�X�N�̐ݒ�
 */
#pragma inline set_intmask
void
set_intmask(UH intmask)
{
	set_sr((current_sr() & ~0x7000) | intmask);
}

/*
 *  �V�X�e����ԎQ��
 */

#pragma inline sense_context
BOOL
sense_context()
{
	Asm("	ldc	hl, intnest");
	return __HL;
}

#pragma inline sense_lock
BOOL
sense_lock()
{
	return(current_intmask() == 0x7000);
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *
 *  task_intmask �́Cchg_ipm ���T�|�[�g���邽�߂̕ϐ��Dchg_ipm ���T�|�[
 *  �g���Ȃ��ꍇ�ɂ́Ctask_intmask ����� 0 �ɂȂ��Ă���ƍl����΂悢�D
 */

#ifdef SUPPORT_CHG_IPM
extern UH	task_intmask;	/* �^�X�N�R���e�L�X�g�ł̊����݃}�X�N */
#endif /* SUPPORT_CHG_IPM */

#pragma inline t_lock_cpu
void
t_lock_cpu()
{
	disint();
}

#pragma inline t_unlock_cpu
void
t_unlock_cpu()
{
#ifdef SUPPORT_CHG_IPM
	/*
	 *  t_unlock_cpu ���Ăяo�����̂� CPU���b�N��Ԃ݂̂ł��邽
	 *  �߁C�����̓r���� task_intmask ����������邱�Ƃ͂Ȃ��D
	 */
	set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
	enaint();
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU���b�N�Ƃ��̉����i��^�X�N�R���e�L�X�g�p�j
 */

extern UH	int_intmask;	/* ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N */

#pragma inline i_lock_cpu
void
i_lock_cpu()
{
	UH	intmask;

	/*
	 *  �ꎞ�ϐ� intmask ���g���Ă���̂́Ccurrent_intmask() ����
	 *  �񂾒���Ɋ����݂��������C�N�����ꂽ�����݃n���h������
	 *  int_intmask ���ύX�����\�������邽�߂ł���D
	 */
	intmask = current_intmask();
	disint();
	int_intmask = intmask;
}

#pragma inline i_unlock_cpu
void
i_unlock_cpu()
{
	set_intmask(int_intmask);
}

/*
 *  �^�X�N�f�B�X�p�b�`��
 */

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�icpu_support.asm�j
 *
 *  dispatch �́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[������
 *  ���ŁCCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.asm�j
 *
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

#pragma inline define_inh
void
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
#pragma inline define_exc
void
define_exc(EXCNO excno, FP exchdr)
{
}


/*
 *  �����݃n���h���^CPU��O�n���h���̏o��������
 */

/*
 *  �����݃n���h���̓��������̐����}�N��
 *
 *  �����ݔ������̃X�^�b�N�̐؂�ւ����\�t�g�E�F�A�Ŏ�������D���̂��߁C
 *  �����݃n���h��������ɂĊ����݋֎~�������s���D�Ȃ��C�����ݔ�������
 *  �����݋֎~���s���܂ł̊Ԃɑ��d�����݂���������ƁC���d�����݂ł���
 *  ���Ƃ��\�t�g�E�F�A�Ō��m�ł��Ȃ����߁C�ŏ��ɔ������������ݏ�������
 *  �s���Ȃ��܂܃^�X�N�f�B�X�p�b�`����\��������D���̑��d�����݂���
 *  �m���邽�߂Ƀn�[�h�E�F�A INTNEST ���W�X�^�𗘗p����D
 *
 *  TLCS-900 Family C Compiler �ł� XIZ ���W�X�^�ȊO�͑S�ăX�N���b�`��
 *  �W�X�^�ł���D�Ȃ��C����������Ŏg�p����X�N���b�`���W�X�^�݂̂���
 *  ���ŕێ����C�c��͊����݋��ʏ����ŕێ�����D
 *
 *  �������C������ꍇ�́C����CPU��O�n���h���������������}�N�������l��
 *  �C�����邱�ƁD
 */
#define	INTHDR_ENTRY(inthdr) \
extern void _kernel_interrupt(void); \
extern void inthdr##(void); \
void inthdr##_entry(void) \
{ \
Asm("	push	xwa	");	/* �g�p����X�N���b�`���W�X�^��ۑ� */ \
Asm("	push	sr");	/* �����ݔ�������IFF���擾	*/ \
Asm("	pop		wa"); \
Asm("	ei		7");	/* �����݋֎~	*/ \
Asm("	push	xhl	");	/* �g�p����X�N���b�`���W�X�^��ۑ� */ \
Asm("	ld		xhl, _" #inthdr );	/* ���[�U�n���h���|�C���^���擾	*/ \
Asm("	jp	__kernel_interrupt"	);	/* �����݋��ʏ�����	*/ \
}
/*
 *  ��L���C������ꍇ�́C����CPU��O�n���h���������������}�N�������l��
 *  �C�����邱�ƁD
 */


#define	INT_ENTRY(inthdr)	inthdr##_entry

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 *  CPU��O�n���h���́C��^�X�N�R���e�L�X�g�Ŏ��s����D
 *  CPU��O�n���h���́C�����݃n���h���Ɠ��������Ƃ���D
 *  �Ȃ��C��O�n���h���̈����^���قȂ邽�߁C���������̃}�N����ʓr
 *  ��������D
 *
 *  �������C������ꍇ�́C��̊����݃n���h���������������}�N�������l��
 *  �C�����邱�ƁD
 */

#define	EXCHDR_ENTRY(exchdr) \
extern void _kernel_interrupt(void); \
extern void exchdr##(VP p_excinf); \
void exchdr##_entry(void) \
{ \
Asm("	push	xwa	");	/* �g�p����X�N���b�`���W�X�^��ۑ� */ \
Asm("	push	sr");	/* �����ݔ�������IFF���擾	*/ \
Asm("	pop		wa"); \
Asm("	ei		7");	/* �����݋֎~	*/ \
Asm("	push	xhl	");	/* �g�p����X�N���b�`���W�X�^��ۑ� */ \
Asm("	ld		xhl, _" #exchdr );	/* ���[�U�n���h���|�C���^���擾	*/ \
Asm("	jp	__kernel_interrupt"	);	/* �����݋��ʏ�����	*/ \
}
/*
 *  �������C������ꍇ�́C��̊����݃n���h���������������}�N�������l��
 *  �C�����邱�ƁD
 */

#define	EXC_ENTRY(exchdr)	exchdr##_entry


/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 */
#pragma inline exc_sense_context
BOOL
exc_sense_context(VP p_excinf)
{
	Asm("	ldc	hl, intnest");
	return ( __HL > 1 );
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
#pragma inline exc_sense_lock
BOOL
exc_sense_lock(VP p_excinf)
{
	return ((*((UH *) p_excinf) & 0x7000) == 0x7000);
}

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
