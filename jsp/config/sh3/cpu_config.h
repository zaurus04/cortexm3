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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */


/*
 *  �v���Z�b�T�ˑ����W���[���iSH3/4�p�j
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_


/*
 *  �J�[�l���������ʖ��̃��l�[��
 */
#include <cpu_rename.h>


#ifdef SH4
#include <sh4.h>        
#else  /* SH3 */
#include <sh3.h>        
#endif /* SH4 */


/*
 *  �ݒ�\�ȍō��D��x
 */
#ifdef GDB_STUB
#define MAX_IPM  0xe
#else
#define MAX_IPM  0xf
#endif 


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
        VP	sp;             /* �X�^�b�N�|�C���^ */
        FP  pc;             /* �v���O�����J�E���^ */
} CTXB;

/*
 *  �����݃}�X�N���색�C�u����
 *
 *  �����݃}�X�N�iintmask�j�́CIPM�iInterrupt Priority Mask�j��4�r�b�g
 *  ���ɃV�t�g�������̂ł���D
 */


/*
 *  ���݂̊����݃}�X�N�̓Ǐo��
 */
Inline UW
current_intmask()
{
	return(current_sr() & 0x000000f0);
}


/*
 *  �����݃}�X�N�̐ݒ�
 */
Inline void
set_intmask(UW intmask)
{
	set_sr((current_sr() & ~0x000000f0) | intmask);
}


/*
 *  �V�X�e����ԎQ��
 */

Inline BOOL
sense_context()
{
    UW  nest;
    Asm("stc r7_bank,%0":"=r"(nest));
        
	return(nest > 0);    
}


Inline BOOL
sense_lock()
{
	return(current_intmask() == MAX_IPM << 4);
}


#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock


/*
 *  CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *
 *  task_intmask �́Cchg_ipm ���T�|�[�g���邽�߂̕ϐ��Dchg_ipm ���T�|�[
 *  �g���Ȃ��ꍇ�ɂ́Ct_unlock_cpu ���� task_intmask �� 0 �ɒu��������
 *  �悢�D
 */

#ifdef SUPPORT_CHG_IPM
extern UW	task_intmask;	/* �^�X�N�R���e�L�X�g�ł̊����݃}�X�N */
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

extern UW	int_intmask;	/* ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N */

Inline void
i_lock_cpu()
{
	UW	intmask;

	/*
	 *  �ꎞ�ϐ� intmask ���g���Ă���̂́Ccurrent_intmask()���Ă�
	 *  ������Ɋ����݂��������C�N�����ꂽ�����݃n���h������
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
 *  �x�N�^�x�[�X�̒�`
 */
extern void   BASE_VBR(void);


/*
 *  ��O�x�N�^�e�[�u���̍\���̒�`
 */
typedef struct exc_vector_entry {
	FP	exchdr;			/* ��O�n���h���̋N���Ԓn */
} EXCVE;



/*
 *  ���荞�݃n���h���̋^���e�[�u��
 *  SH3�ȍ~�̓x�N�^�e�[�u���������Ȃ����ߊ��荞�ݏ����ŗ�O�v����
 *  �I�t�Z�b�g�ɂ����^���e�[�u�����n���h���̎��s�Ԓn�y��
 *  ���荞�݃}�X�N�̒l���擾����
 */
extern FP	int_table[];
extern VW   int_plevel_table[];


/*
 *  CPU��O�n���h���̋^���e�[�u��
 */
extern FP	exc_table[(0x1E0 >> 5) + 1];


/*
 *
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 *  �^���e�[�u���ɓo�^����
 *  stub���g���ꍇ��stub�Ăяo���ɂ��stub�ɓo�^����
 *  
 */

extern FP general_exception();
extern FP interrupt();


Inline void
define_inh(INHNO inhno, FP inthdr)
{
        int_table[inhno >> 5] = inthdr;
#ifdef GDB_STUB
        Asm("mov #0x8,r0;  mov %0,r4; mov %1,r5; trapa #0x3f"
	    : /* no output */
	    : "r"(inhno),"r"(interrupt)
	    : "r0", "r4", "r5");
#endif /* GDB_STUB */
}


/*
 *   CPU��O�n���h���̐ݒ�
 *   �[���x�N�^�[�e�[�u���ɓo�^
 */   
Inline void
define_exc(EXCNO excno, FP exchdr)
{
        exc_table[excno >> 5] = exchdr;
#ifdef  GDB_STUB 
        Asm("mov #0x8,r0;  mov %0,r4; mov %1,r5;  trapa #0x3f"
	    : /* no output */
	    : "r"(excno),"r"(general_exception)
	    : "r0", "r4", "r5");
#endif /* GDB_STUB */
}


/*
 *  ���荞�݃��x���̐ݒ�
 */
Inline void
define_int_plevel(UINT dintno, UW plevel)
{
    int_plevel_table[dintno >> 5] = (plevel << 4) | 0x40000000;
}


/*
 *  �����݃n���h���^CPU��O�n���h���̏o��������
 *  
 */

/*
 *  �����݃n���h���̏o���������̐����}�N��
 */

#define	INTHDR_ENTRY(inthdr)  extern void inthdr(void)

#define INT_ENTRY(inthdr) inthdr

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 */
#define	EXCHDR_ENTRY(exchdr)  extern void exchdr(VP sp)

#define	EXC_ENTRY(exchdr)     exchdr


/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g����
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
    UW  nest;
    Asm("stc r7_bank,%0":"=r"(nest));
        
	return(nest > 1);
}


/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((*((UW *)p_excinf + 11) & 0x00000f0) == MAX_IPM << 4);
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
 * ���o�^�̊�����/��O�������̃��O�o��
 */
extern void     cpu_expevt(VW,VW,VW,VW);
extern void     cpu_interrupt(VW,VW,VW,VW);
extern void     no_reg_interrupt(void);


/*
 *  �V���A���R���g���[���̃{�[���[�g�ݒ莞�̑҂����Ԃ̐ݒ�
 *  �o�X�X�e�[�g�R���g���[���̃��t���b�V���J�E���^���g��
 */
#define WAIT_RFCR_FOR_SCI    200

/*
 *  gdb stub�ɂ��o��
 */
Inline int
stub_putc(int c)
{
  Asm("mov #0x00,r0; mov %0,r4; trapa #0x3f"
               : /* no output */
               : "r"(c)
               : "r0","r4");
  return(c);
}


#endif /* _MACRO_ONLY_ */
#endif /* _CPU_CONFIG_H_ */
