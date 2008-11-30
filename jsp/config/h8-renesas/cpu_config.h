/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *      �v���Z�b�T�ˑ����W���[���iH8�p�j
 *�@�@�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@�@�@�f�[�^�^�A�}�N���A�֐��̃v���g�^�C�v�錾
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

#include <h8.h>

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
#define TBIT_TCB_TSTAT          8       /* tstat �t�B�[���h�̃r�b�g�� */
#define TBIT_TCB_PRIORITY       8       /* priority �t�B�[���h�̃r�b�g�� */


#ifndef _MACRO_ONLY

/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */

typedef struct task_context_block {
        VP      sp;             /* �X�^�b�N�|�C���^ */
        FP      pc;             /* �v���O�����J�E���^ */
} CTXB;

/*
 *  �����݃}�X�N���색�C�u����
 */

/*
 *  ���݂̊����݃}�X�N�̓Ǐo��
 */
Inline UB
current_intmask(void)
{
        UB ccr = current_ccr();
        
        ccr &= (UB)CCR_DISINT_ALL;
        return(ccr);
}

/*
 *  �����݃}�X�N�̐ݒ�
 */
Inline void
set_intmask(UB intmask)
{
        UB ccr = current_ccr();
        
        /*
         *�@and_ccr(),or_ccr()��p�����Ƀ��[�J���ϐ�ccr�Ɉ�x�A���
         *�@���闝�R
         *
         *�@�Eunloc_cou()����Ă΂��̂ŁAintmask�̒l�����f�����܂�
         *�@�@�����݋��ɂȂ��Ă͂����Ȃ��B
         *  �E�R���p�C���̌x����}�����邽�߁A�L���X�g���Ă���B 
         */
        ccr = (UB)((ccr & CCR_ENAINT_ALL) | intmask);
        set_ccr(ccr);
}

/*
 *  �����݃l�X�g�J�E���^
 */

extern volatile UB       intnest;

/*
 *  �R���e�L�X�g�Q��
 *
 *  �����݃l�X�g�J�E���^��ǂݏo��������Ɋ����݂��������Ă��A�߂�����
 *  ���ɂ̓R���e�L�X�g�����ɖ߂��Ă���
 */
Inline BOOL
sense_context(void)
{
	BOOL ret;
	
	ret = (intnest != 0) ? TRUE : FALSE;
	return(ret);
}

/*
 *  CPU���b�N��Ԃ̎Q��
 */

/*
 *  CPU���b�N��Ԃ�\���t���O
 */
extern volatile BOOL     iscpulocked;

#define sense_lock()    iscpulocked
#define t_sense_lock    sense_lock
#define i_sense_lock    sense_lock

/*
 *  CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *
 *  task_intmask �́Achg_ipm ���T�|�[�g���邽�߂̕ϐ��Bchg_ipm ���T�|�[�g
 *  ���Ȃ��ꍇ�ɂ́At_unlock_cpu ���� task_intmask �� 0 �ɒu�������Ă悢�B
 */

#ifdef SUPPORT_CHG_IPM
extern volatile UB       task_intmask;   /* �^�X�N�R���e�L�X�g�ł̊����݃}�X�N */
#endif /* SUPPORT_CHG_IPM */

Inline void
t_lock_cpu(void)
{
        disint();
        iscpulocked = TRUE;
}

Inline void
t_unlock_cpu(void)
{
        iscpulocked = FALSE;
#ifdef SUPPORT_CHG_IPM
        /*
         *  t_unlock_cpu ���Ăяo�����̂� CPU���b�N��Ԃ݂̂ł��邽�߁B
         *  �����̓r���� task_intmask ����������邱�Ƃ͂Ȃ��B
         */
        set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
        enaint();               /* cpu_insn.h */
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU���b�N�Ƃ��̉����i��^�X�N�R���e�L�X�g�p�j
 */

extern volatile UB       int_intmask;    /* ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N */

Inline void
i_lock_cpu(void)
{
        UB      intmask = current_intmask();
        /*
         *  �ꎞ�ϐ� intmask ���g���Ă���̂́Ccurrent_intmask()���Ă�
         *  ������Ɋ����݂��������C�N�����ꂽ�����݃n���h������
         *  int_intmask ���ύX�����\�������邽�߂ł���D
         */

        disint();
        int_intmask = intmask;
        iscpulocked = TRUE;
}

Inline void
i_unlock_cpu(void)
{
        iscpulocked = FALSE;
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

extern void     dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.S�j
 *
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */

extern void     exit_and_dispatch(void);

/*
 *
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 *
 *�@H8�łł͉������������Ȃ�
 *�@�i�x�N�^�e�[�u�����}�j���A���ŕҏW����j
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{
}

/*
 *  CPU��O�n���h���̐ݒ�
 *�@�@H8�łł͎g�p����Ȃ�
 */

Inline void
define_exc(EXCNO excno, FP exchdr)
{
}

/*
 *  �����݃n���h���̏o��������
 *�@�@H8C�pH8�ˑ����ł͊����݂̏o�����������A�Z���u���\�[�X����
 *�@�@�������邽�߁A�{����C���ꒆ�Œ�`����K�v���Ȃ��B
 *�@�@�����ł͋��ʕ��Ƃ̃C���^�[�t�F�[�X�����킹�邽�߁A
 *�@�@�K�v�ȃ}�N����`�݂̂��Ă���B
 */

/*
 *  C���ꃋ�[�`���̊֐���������������̃��x���𐶐�
 *�@�@H8C�pH8�ˑ����ł͓���������vector.src���̃��[�J���E�V���{����
 *�@�@�ł���̂ŁA�O���[�o���Ɍ��J����K�v���Ȃ��B
 *�@�@�����ł͋��ʕ��Ƃ̃C���^�[�t�F�[�X�����킹�邽�߁A
 *�@�@�_�~�[�̃��x����^���Ă���B
 */
#define INT_ENTRY(inthdr) _kernel_common_interrupt_process
#define EXC_ENTRY(exchdr) _kernel_common_interrupt_process

/*
 *  �����݃n���h���̏o���������̐����}�N��
 *�@�@�@C�����ł͂��܂������ł��Ȃ����߁A�A�Z���u���\�[�X����
 *�@�@�@�ʓr�p�ӂ���B
 */
#define INTHDR_ENTRY(inthdr) extern void INT_ENTRY(inthdr)(void) throw()

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 */
#define EXCHDR_ENTRY(exchdr) extern void EXC_ENTRY(exchdr)(void) throw()

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g����
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
        /* H8�łł͌Ă΂�Ȃ��B */
        return(TRUE);
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
        /* H8�łł͌Ă΂�Ȃ��B */
        return(TRUE);
}

/*
 *  �v���Z�b�T�ˑ��̏�����
 */

extern void     cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */

extern void     cpu_terminate(void);

/*
 *  ����`�����ݔ������̃G���[�o�͎��̃X�^�b�N�\���̒�`
 */

typedef struct exc_stack {
	UW	er0;
	UW	er1;
	UW	er2;
	UW	er3;
	UW	er4;
	UW	er5;
	UW	er6;
	UW	pc;	/*  �v���O�����E�J�E���^  	*/
} EXCSTACK;

/*
 * ����`�����ݔ������̃G���[�o�� (cpu_config.c, cpu_support.S)
 */

extern void     cpu_experr(EXCSTACK *sp);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���D
 */
extern void cpu_putc(char c);

#endif /* _MACRO_ONLY_ */

#endif /* _CPU_CONFIG_H_ */
