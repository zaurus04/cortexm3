/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *  �v���Z�b�T�ˑ����W���[���iARM4vT�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �J�[�l���������ʖ��̃��l�[��
 */
#include "cpu_rename.h"

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
#define    TBIT_TCB_TSTAT       8    /* tstat �t�B�[���h�̃r�b�g�� */
#define    TBIT_TCB_PRIORITY    8    /* priority �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
    VP    sp;        /* �X�^�b�N�|�C���^ */
    FP    pc;        /* �v���O�����J�E���^ */
} CTXB;

/*
 * ���荞�݂̃l�X�g�񐔂̃J�E���g
 */
extern UW interrupt_count;


/*
 *  �V�X�e����ԎQ��
 */
Inline UB
current_mode()
{
    return(current_sr() & CPSR_MODE_MASK);
}

Inline BOOL
sense_context()
{
    return(interrupt_count > 0);
}

Inline BOOL
sense_lock()
{
    return(current_sr() & CPSR_IRQ_BIT);
}

#define t_sense_lock    sense_lock
#define i_sense_lock    sense_lock


/*
 *  CPU���b�N�Ƃ��̉���
 *
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
 * ��O�x�N�^�ɏ������܂ꂽ�W�����v���߂��Q�Ƃ���A�h���X
 */
extern UW * arm_vector_add[8];


/*
 * ��O�ɉ������n���h���̋N���Ԓn
 */
extern UW arm_handler_add[8];


/*
 *  CPU��O�n���h���̐ݒ�
 */
extern void define_exc(EXCNO excno, FP exchdr);


Inline void
arm_install_handler(EXCNO excno, FP exchdr)
{
    *arm_vector_add[excno] = (UW)exchdr;
}


/*
 *  CPU��O�n���h���̏o��������
 */


/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 */
#define __EXCHDR_ENTRY(exchdr, stacktop)    \
extern void exchdr##_entry(VP sp);          \
asm(".text                             \n"  \
#exchdr "_entry:                       \n"  \
"       ldr   sp,.int_stack_"#exchdr"  \n"  /* �X�^�b�N�̐؂�ւ�        */\
"       sub   lr,lr,#4                 \n"  /* undef�ł�����ł�����?    */\
"       stmfd sp!, {r0 - r2,lr}        \n"  /* �ꎞ�I��int_stack�ɑҔ�   */ \
"       mrs   r1, spsr                 \n"  /* SVC���[�h�ɐ؂�ւ��邽�� */ \
"       mov   r0, sp                   \n"  /* �ۑ�����                  */ \
"       mov   r2,#0xd3                 \n"  /* CPSR�̏�������(SVC���[�h��)*/ \
"       msr   cpsr,r2                  \n" \
"       ldr   r2,[r0,#0x0C]            \n"     /* load  PC            */\
"       stmfd sp!,{r2}                 \n"     /* Store PC            */\
"       stmfd sp!,{r3,ip,lr}           \n"     /* Store r3,ip,lr      */\
"       ldmfd r0!,{r2,ip,lr}           \n"     /* load  r0,r1,r2      */\
"       stmfd sp!,{r1,r2,ip,lr}        \n"     /* SPSR,Store r0,r1,r2 */\
"       ldr   r2, .interrupt_count_"#exchdr"\n" /* ���d���荞�݂�����  */\
"       ldr   r3, [r2]                 \n" \
"       add   r0,r3,#1                 \n" \
"       str   r0, [r2]                 \n" \
"       mov   r0,sp                    \n" /* ��O�n���h���ւ̈��� */\
"       cmp   r3, #0x00                \n" \
"       ldreq   sp,stack_"#exchdr"     \n" /* �X�^�b�N�̕ύX       */\
"       stmeqfd sp!,{r0}               \n" /* �^�X�N�X�^�b�N�̕ۑ� */\
"       and   r2, r1, #0xc0            \n" /* ��O��������CPU���b�N���(IRQ) */\
"       orr   r2, r2, #0x13            \n" /* ��FIQ���p��. SVC���[�h */\
"       msr   cpsr,r2                  \n" \
"       bl    "#exchdr"                \n" /* �n���h���Ăяo��     */\
"       mrs   r2, cpsr                 \n" /* FIQ���p��            */\
"       and   r2, r2, #0x40            \n" /*                      */\
"       orr   r2, r2, #0x93            \n" /* ���荞�݋֎~         */\
"       msr   cpsr,r2                  \n" \
"       ldr   r2,.interrupt_count_"#exchdr" \n"/* ���荞�݉񐔂�   */\
"       ldr   r1, [r2]                 \n"     /* �f�N�������g     */\
"       sub   r3,r1,#1                 \n"\
"       str   r3, [r2]                 \n"\
"       cmp   r3,#0x00                 \n" /* ���荞�݃l�X�g��?    */\
"       bne   return_to_task_"#exchdr" \n" \
"       ldmfd sp!,{r0}                 \n" /* �^�X�N�X�^�b�N�̕��A */\
"       mov   sp, r0                   \n"\
"       ldr   r1, reqflg_"#exchdr"     \n" /* Check reqflg         */\
"       ldr   r0,[r1]                  \n"\
"       cmp   r0,#0                    \n"\
"       beq   return_to_task_"#exchdr" \n"\
"       mov   r0,#0                    \n"\
"       str   r0,[r1]                  \n" /* Clear reqflg   */\
"       b     _kernel_ret_exc          \n" /* ret_int��      */\
"return_to_task_"#exchdr":             \n" \
"       ldmfd sp!,{r1}                 \n" /* CPSR�̕��A���� r1 <- cpsr*/\
"       mrs   r2, cpsr                 \n" /* FIQ���p��            */\
"       and   r2, r2, #0x40            \n" /*                      */\
"       and   r1, r1, #~0x40           \n" /*                      */\
"       orr   r1, r1, r2               \n" /*                      */\
"       msr   spsr, r1                 \n" /* ���荞�݋���   */\
"       ldmfd sp!,{r0-r3,ip,lr,pc}^    \n"\
"       .align 4                       \n"\
".int_stack_"#exchdr":                 \n"\
"       .long _kernel_int_stack + 6 * 4 \n"\
"reqflg_"#exchdr":                     \n"\
"       .long     _kernel_reqflg       \n"\
"stack_"#exchdr":                      \n"\
"       .long   " #stacktop "          \n"\
".interrupt_count_"#exchdr":            \n"\
"       .long   _kernel_interrupt_count \n")


#define _EXCHDR_ENTRY(exchdr, stacktop)    __EXCHDR_ENTRY(exchdr, stacktop)

#define EXCHDR_ENTRY(exchdr)    _EXCHDR_ENTRY(exchdr, STACKTOP)

#define EXC_ENTRY(exchdr) exchdr##_entry


/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃f�B�X�p�b�`
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
    return((*((UW *)p_excinf) & CPSR_IRQ_BIT) == CPSR_IRQ_BIT );
}


/*
 * ����`�̗�O���������ꍇ
 */
extern void undef_exception();
extern void swi_exception();
extern void prefetch_exception();
extern void data_abort_exception();
extern void irq_abort_exception();
extern void fiq_abort_exception();


/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void    cpu_initialize(void);


/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void    cpu_terminate(void);


/*
 * CPU/�����݃n���h���̏o����������ňꎞ�I�Ɏg�p����X�^�b�N
 */
#define INT_STACK_SIZE 6
extern UW int_stack[INT_STACK_SIZE];


#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
