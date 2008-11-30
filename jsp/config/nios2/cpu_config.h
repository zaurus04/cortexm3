/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


/*
 *  �v���Z�b�T�ˑ����W���[���iNiosII�p�j
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
 *  TCB �֘A�̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 */
#define    TBIT_TCB_PRIORITY    8    /* priority �t�B�[���h�̃r�b�g�� */
#define    TBIT_TCB_TSTAT       8    /* tstat �t�B�[���h�̃r�b�g�� */


#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
        VP    sp;             /* �X�^�b�N�|�C���^ */
        FP  pc;             /* �v���O�����J�E���^ */
} CTXB;


/*
 * ���荞�݂̃l�X�g�񐔂̃J�E���g
 */
extern UW interrupt_count;

/*
 *  �V�X�e����ԎQ��
 */
Inline BOOL
sense_context()
{
    return(interrupt_count > 0);    
}

Inline BOOL
sense_lock()
{
    return((current_status() & STATUS_PIE) == 0);
}

#define t_sense_lock    sense_lock
#define i_sense_lock    sense_lock


/*
 *  CPU���b�N�Ƃ��̉���
 */
#define t_lock_cpu      lock_cpu
#define i_lock_cpu      lock_cpu
#define t_unlock_cpu    unlock_cpu
#define i_unlock_cpu    unlock_cpu

Inline void
lock_cpu()
{
    disint();
}

Inline void
unlock_cpu()
{
    enaint();
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
extern void    dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.S�j
 *
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void    exit_and_dispatch(void);


/*
 *  �����݃n���h���^CPU��O�n���h���̐ݒ�
 */

/*
 *  ���荞�݃n���h��/�r�b�g�}�X�N�̃e�[�u��
 *  int_handler_table[] �͊����݃n���h����o�^����e�[�u��
 *  int_bit_table[]�͊����݂̗D�揇�ʂɉ������r�b�g�̃e�[�u���ł���C
 *  
 */
extern FP   int_handler_table[MAX_INT_NUM];
extern UW   int_bit_table[MAX_INT_NUM];

/*
 *  CPU��O�n���h���̋^���e�[�u��
 */
extern FP    exc_handler_table[];

/*
 *
 *  �����݃n���h���̐ݒ�
 *
 *  �����ݗD��x inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 *  �^���e�[�u���ɓo�^����
 *  
 */

Inline void
define_inh(INHNO inhno, FP inthdr)
{
    int_handler_table[inhno] = inthdr;
}

/*
 *   CPU��O�n���h���̐ݒ�
 *   �[���x�N�^�[�e�[�u���ɓo�^
 */   
Inline void
define_exc(EXCNO excno, FP exchdr)
{
    exc_handler_table[excno] = exchdr;
}


/*
 *  �����݃n���h���^CPU��O�n���h���̏o��������
 *  
 */


/*
 *  �����݃n���h���̏o���������̐����}�N��
 */

#define INTHDR_ENTRY(inthdr)  extern void inthdr(void);

#define INT_ENTRY(inthdr) inthdr

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 */
#define    EXCHDR_ENTRY(exchdr)  extern void exchdr(VP sp);

#define    EXC_ENTRY(exchdr)     exchdr

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g����
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
    return(interrupt_count > 1); 
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
    return((*(UW*)p_excinf & STATUS_PIE) == 0);
}


/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void    cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void    cpu_terminate(void);


/*
 * ���o�^�̊�����/��O�������̃��O�o��
 */
extern void     no_reg_interrupt(void);
extern void     no_reg_exception(void);

#endif /* _MACRO_ONLY_ */

/*
 *  vxget_tim ���T�|�[�g���邩�ǂ����̒�`
 */
#define    SUPPORT_VXGET_TIM

/*                                                                             
 *  �V���A���|�[�g�ԍ��Ɋւ����`      
 */
#define TNUM_PORT   1   /* �T�|�[�g����V���A���|�[�g�̐� */
#define TNUM_SIOP   1   /* �T�|�[�g����V���A��I/O�|�[�g�̐� */

/*
 *  �V�X�e���^�X�N�Ɋւ����`
 */
#define    LOGTASK_PORTID    1    /* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ� */


#endif /* _CPU_CONFIG_H_ */
