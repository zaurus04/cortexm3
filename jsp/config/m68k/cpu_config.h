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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iM68040�p�j
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
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	VP	msp;		/* �X�^�b�N�|�C���^ */
	FP	pc;		/* �v���O�����J�E���^ */
} CTXB;

/*
 *  �����݃}�X�N���색�C�u����
 *
 *  �����݃}�X�N�iintmask�j�́CIPM�iInterrupt Priority Mask�j��8�r�b�g
 *  ���ɃV�t�g�������̂ł���D
 */

/*
 *  ���݂̊����݃}�X�N�̓Ǐo��
 */
Inline UH
current_intmask()
{
	return(current_sr() & 0x0700);
}

/*
 *  �����݃}�X�N�̐ݒ�
 */
Inline void
set_intmask(UH intmask)
{
	set_sr((current_sr() & ~0x0700) | intmask);
}

/*
 *  �V�X�e����ԎQ��
 */

Inline BOOL
sense_context()
{
	return((current_sr() & 0x1000) == 0);
}

Inline BOOL
sense_lock()
{
	return(current_intmask() == 0x0700);
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

Inline void
t_lock_cpu()
{
	disint();
}

Inline void
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

Inline void
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

Inline void
i_unlock_cpu()
{
	set_intmask(int_intmask);
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

/*
 *  ��O�x�N�^�e�[�u���̍\���̒�`
 */
typedef struct exc_vector_entry {
	FP	exchdr;			/* ��O�n���h���̋N���Ԓn */
} EXCVE;

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{
	EXCVE	*excvt;

#ifdef EXCVT_KERNEL
	/*
	 *  EXCVT_KERNEL ����`����Ă��鎞�́C�����������̒��� VBR �� 
	 *  EXCVT_KERNEL �ɐݒ肷��̂ŁCEXCVT_KERNEL ���g���D
	 */
	excvt = (EXCVE *) EXCVT_KERNEL;
#else /* EXCVT_KERNEL */
	excvt = (EXCVE *) current_vbr();
#endif /* EXCVT_KERNEL */
	excvt[inhno].exchdr = inthdr;
}

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ肷��D
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
	define_inh(excno, exchdr);
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

#define	INTHDR_ENTRY(inthdr)		\
extern void inthdr##_entry(void);	\
asm(".text				\n" \
#inthdr "_entry:			\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n" /* �X�N���b�`���W�X�^��ۑ� */ \
"	jsr " #inthdr "			\n" /* �����݃n���h�����Ăяo�� */ \
"	movem.l (%sp)+, %d0-%d1/%a0-%a1	\n" /* �X�N���b�`���W�X�^�𕜋A */ \
"	btst.b #4, (%sp)		\n" /* �߂�悪�����݃��[�h�Ȃ� */ \
"	jbeq 1f				\n" /*           �����Ƀ��^�[�� */ \
"	or.w #0x0700, %sr		\n" /* �����݋֎~ */ \
"	tst.l _kernel_reqflg		\n" /* reqflg �� TRUE �ł���� */ \
"	jbne _kernel_ret_int		\n" /*              ret_int �� */ \
"1:	rte				\n")

#define	INT_ENTRY(inthdr)	inthdr##_entry

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

#define	EXCHDR_ENTRY(exchdr)		\
extern void exchdr##_entry(VP sp);	\
asm(".text				\n" \
#exchdr "_entry:			\n" \
"	movem.l %d0-%d1/%a0-%a1, -(%sp)	\n" /* �X�N���b�`���W�X�^��ۑ� */ \
"	lea.l 16(%sp), %a0		\n" /* ��O�t���[���̐擪�� A0 �� */ \
"	move.w %sr, %d0			\n" /* SR �� D0 �� */ \
"	and.w #~0x1000, %sr		\n" /* �����݃��[�h */ \
"	move.l %d0, -(%sp)		\n" /* ���� SR ���X�^�b�N�ɕۑ� */ \
"	move.l %a0, -(%sp)		\n" /* A0 �������Ƃ��ēn�� */ \
"	jsr " #exchdr "			\n" /* CPU��O�n���h�����Ăяo�� */ \
"	addq.l #4, %sp			\n" \
"	move.l (%sp)+, %d0		\n" \
"	and.w #0x1000, %d0		\n" /* ���������݃��[�h�Ȃ� */ \
"	jbeq 1f				\n" /*       �����Ƀ��^�[�� */ \
"	or.w #0x1700, %sr		\n" /* �}�X�^���[�h�E�����݋֎~ */ \
"	tst.l _kernel_reqflg		\n" /* reqflg �� TRUE �ł���� */ \
"	jbne _kernel_ret_exc		\n" /*              ret_exc �� */ \
"1:	movem.l (%sp)+, %d0-%d1/%a0-%a1	\n" /* �X�N���b�`���W�X�^�𕜋A */ \
"	rte				\n")

#define	EXC_ENTRY(exchdr)	exchdr##_entry

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return((*((UH *) p_excinf) & 0x1000) == 0);
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((*((UH *) p_excinf) & 0x0700) == 0x0700);
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
