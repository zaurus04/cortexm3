/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 * 
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iPowerPC�p�j
 *�@�@�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@�@�@�f�[�^�^�A�}�N���A�֐��̃v���g�^�C�v�錾
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
 *  PowerPC�v���Z�b�T�̓������W�X�^�̒�`
 */
#include <powerpc.h>


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
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */

/*
 *  �X�^�b�N�ɕK�v�ȃ}�[�W��
 *  
 *  PowerPC EABI�ŋK�肳��Ă���R�[�����O�E�R���x���V�����ł͊֐��Ă�
 *  �o�����̃t���[���X�^�b�N�|�C���^���w���Ă���8�o�C�g��(sp+4)�`
 *  (sp+7)�Ԓn�ɌĂ΂ꂽ���̏�񂪑Ҕ������B���̂��߁A�A�Z���u�����[
 *  �`������C���ꃋ�[�`�����Ăяo���ӏ��i���Ɋ����݃R���g���[���ˑ�
 *  ���j�ł͒��ӂ��K�v�ł���B
 *  ��̓I�ɂ͈ȉ��̉ӏ����Y������B
 *   �@(1) �X�^�[�g�A�b�v���[�`��
 *   �@(2) �^�X�N�N��
 *   �@  (2-1) �^�X�N��O�������[�`���N��
 *   �@(3) �����݃n���h���N��
 *   �@(4) CPU��O���[�`���N��
 *  
 *  �@�@�@�@�@�@�@�@�@�@�@�@�@�X�^�b�N���L�т����
 *  �@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@��
 *  �@ �֐��Ăяo���O��sp��  ---------------------- 
 *  �@ �@�@�@�@�@           |                      |
 *  �@�@�@�@�@�@         +4  ----------------------�@
 *  �@�@�@�@�@�@            |                      |��C���ꃋ�[�`���̌Ăяo��
 *  �@�@�@�@�@�@         +8  ----------------------   �ɂ�菑�����܂��
 *  �@
 *  �@���l
 *  �@�@64�r�b�g���̍ۂɂ͒��ӂ��K�v�ł���B
 *  �@
 */
#define STACK_MARGIN	8


#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 *�@�@sp��4�o�C�g���E�ł��邱�Ƃ𖾎����邽�߁A
 *�@�@UW*�^�Ő錾���Ă���B
 */

typedef struct task_context_block {
        UW	*sp;            /* �X�^�b�N�|�C���^ */
        FP	pc;             /* �v���O�����J�E���^ */
} CTXB;

/*
 *  �V�X�e����ԎQ��
 */

/*
 *  �R���e�L�X�g�Q��
 *  
 *    �߂�l
 *    �@TRUE �F��^�X�N�R���e�L�X�g
 *    �@FALSE�F�^�X�N�R���e�L�X�g
 *
 *�@SPRG0�������݃l�X�g�J�E���^�ɗp���Ă���
 *  �����݃l�X�g�J�E���^��ǂݏo��������Ɋ����݂��������Ă��A
 *  �߂����Ƃ��ɂ̓R���e�L�X�g�����ɖ߂��Ă���
 *
 */
Inline BOOL
sense_context()
{
    UW intnest;
    
    intnest = current_sprg0();    	/*  intnest �� SPRG0  */
    return(intnest > 0);
}

/*
 *  CPU���b�N��ԎQ��
 *  
 *    �߂�l
 *    �@TRUE �FCPU���b�N���
 *    �@FALSE�FCPU���b�N�������
 *
 *  MSR��ǂݏo��������Ɋ����݂��������Ă��A�߂����Ƃ��ɂ�
 *  MSR�����ɖ߂��Ă���
 *
 */
Inline BOOL
sense_lock()
{
    return(!(current_msr() & MSR_EE));
}

#define t_sense_lock    sense_lock
#define i_sense_lock    sense_lock



/*
 *  CPU���b�N�Ƃ��̉���
 *
 *  �@MSR��EE�r�b�g��CPU���b�N���������Ă���B
 *  �@�����݃}�X�N�͊����݃R���g���[���ɂ���B
 *  �@�����ݑS�֎~�Ɗ����݃}�X�N���Ɨ����Ă��邽�߁A
 *  �@�P���Ɏ����ł���B
 */

/*  �^�X�N�R���e�L�X�g�p  */
#define t_lock_cpu      disint      /*  cpu_insn.h  */
#define t_unlock_cpu    enaint      /*  cpu_insn.h  */

/*  ��^�X�N�R���e�L�X�g�p  */
#define i_lock_cpu      disint      /*  cpu_insn.h  */
#define i_unlock_cpu    enaint      /*  cpu_insn.h  */


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
 *  �����݃n���h���̋[���e�[�u��
 */
extern FP int_table[];

/*
 *  ��O�x�N�^�̋[���e�[�u��
 */
extern FP exc_table[];


Inline void
define_inh(INHNO intno, FP inthdr)
{
    int_table[intno] = inthdr;

#ifdef GDB_STUB     /*  �ۗ�  */

#endif
}

/*
 *   CPU��O�n���h���̐ݒ�
 */

Inline void
define_exc(EXCNO excno, FP exchdr)
{
    exc_table[excno] = exchdr;

#ifdef GDB_STUB     /*  �ۗ�  */

#endif
}


/*
 *  �����݃n���h���̏o���������̐����}�N��
 */

#define INTHDR_ENTRY(inthdr)  extern void inthdr(void)

#define INT_ENTRY(inthdr) inthdr

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 */
#define EXCHDR_ENTRY(exchdr)  extern void exchdr(VP sp)

#define EXC_ENTRY(exchdr)     exchdr

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g����
 *  
 *    �߂�l
 *    �@TRUE �FCPU��O�������ɔ�^�X�N�R���e�L�X�g
 *    �@FALSE�FCPU��O�������Ƀ^�X�N�R���e�L�X�g
 *
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
    UW  intnest;
    
    intnest = current_sprg0();    	/*  intnest �� SPRG0  */

    /*
     * �P�Ɣ�r����̂́A���ݎ��s����CPU��O�̕�
     * �����݃l�X�g�J�E���^���C���N�������g����Ă��邽��
     */
    return(intnest > 1);
}


/*
 * ��O�n���h���̈���p_excinf���w�������Ԓn����
 * �@�@�@�@�@�@�@�@�@�@�@�@SSR1���W�X�^�܂ł̃I�t�Z�b�g
 * 
 * �@�@MSR�̃R�s�[SSR1���W�X�^�́A�X�^�b�N��(OFFSET_SSR1+1)�Ԗڂ�
 * �@�@�ς܂�Ă���B
 * �@�@support.S��SAVE_GPR0_12_SPRG���Q�� 
 */
#define OFFSET_SSR1	12

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 *  
 *    �߂�l
 *    �@TRUE �FCPU��O��������CPU���b�N���
 *    �@FALSE�FCPU��O��������CPU���b�N�������
 *  
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
    UW  ssr1;

    ssr1 = *((volatile UW *)p_excinf + OFFSET_SSR1);
    return( !(ssr1 & MSR_EE) );
}

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void cpu_terminate(void);

/*
 *  ���L�̃��O�o�͎��̃X�^�b�N�\���̒�`
 */
typedef struct exc_stack {
	UW	r0;
	UW	r3;
	UW	r4;
	UW	r5;
	UW	r6;
	UW	r7;
	UW	r8;
	UW	r9;
	UW	r10;
	UW	r11;
	UW	r12;
	UW	srr0;	/*   �Ҕ��^���A���W�X�^0�@*/
	UW	srr1;	/*   �Ҕ��^���A���W�X�^1�@*/
	UW	lr;	/*   �����N�E���W�X�^ 	*/
	UW	ctr;	/*   �J�E���g�E���W�X�^	*/
	UW	cr;	/*   �R���f�B�V�����E���W�X�^ 	*/
	UW	xer;	/*   �����I�y���[�V�����̏������ʃ��W�X�^�@*/
			/*  �@�i�L�����[��I�[�o�t���[�Ȃǁj  */
	UW	exc_no;	/*   ��O�ԍ� 	*/
} EXCSTACK;

/*  �X�^�b�N��̃f�[�^�̕\��  */
void syslog_data_on_stack(EXCSTACK *sp);

/*
 * �o�^����Ă��Ȃ���O�������̃��O�o�� (cpu_config.c)
 */
extern void no_reg_exception(EXCSTACK *);



#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */

/*  end of file  */
