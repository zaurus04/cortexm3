/* 
 *
 *  TOPPERS/JSP Kernel
 *     Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 * ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 * �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 * �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 * �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 * ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 * (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *     ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *     �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 * (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *     �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *     �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *     �̖��ۏ؋K����f�ڂ��邱�ƁD
 * (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *     �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *     �ƁD
 *   (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *       �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *   (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *       �񍐂��邱�ƁD
 * (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *     �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *
 * �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 * ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 * �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 * �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 *
 *  @(#) $Id: cpu_support.S,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#define _MACRO_ONLY
        
/*
 *  �A�v���P�[�V�����Ƌ��ʂ̃C���N���[�h�t�@�C��
 */
#include <kernel.h>
                
/*
 *  �^�[�Q�b�g�ˑ����̒�`
 */
#include <t_config.h>

#include "jsp_kernel.h"
#include "offset.h"
#include <microblaze_asm.inc>
#include <microblaze.h>


/*
 * INTC�̐݌v�ɂ��āC
 *
 *  �ۑ����郌�W�X�^
 *  R3-R4   Return Valus        (Volatile)
 *  R5-R10  Passing parameters  (Volatile)
 *  R11-R12 Temporaries         (Volatile)
 *  R14     Return address for interrupt
 *  R15     Return address for Sub-routine
 *  R16     Return address for Trap(Debugger)
 *  R17     Return address for Exeptions
 * ?R18     Reserved for Assember    
 */

#define STACK_TOP (STACKTOP - 0x4) 

#define INTC_ISR (INTC_BASE + INTC_INT_STATUS_REG)
#define INTC_IPR (INTC_BASE + INTC_INT_PENDING_REG)
#define INTC_IER (INTC_BASE + INTC_INT_ENABLE_REG)
#define INTC_IAR (INTC_BASE + INTC_INT_ACK_REG)
#define INTC_SIE (INTC_BASE + INTC_SET_INT_ENABLE)
#define INTC_CIE (INTC_BASE + INTC_CLEAR_INT_ENABLE)
#define INTC_IVR (INTC_BASE + INTC_INT_VECTOR_REG)
#define INTC_MER (INTC_BASE + INTC_MASTER_ENABLE_REG)


/*
 *  ��O�G���g��
 *  Not Support!
 */
	.text
	.globl exception_entry
	.align 2
exception_entry:
	nop
	



	.text
	.globl interrupt_entry
	.align 2
interrupt_entry:
/*
 * �X�^�b�N�|�C���^�̐؂�ւ����K�v
 */
	addik r1,r1,-64
	swi r3,  r1, 60
	swi r4,  r1, 56
	swi r5,  r1, 52
	swi r6,  r1, 48
	swi r7,  r1, 44
	swi r8,  r1, 40
	swi r9,  r1, 36
	swi r10, r1, 32
	swi r11, r1, 28
	swi r12, r1, 24
	swi r14, r1, 20
	swi r15, r1, 16
	swi r16, r1, 12
	swi r17, r1, 8
	swi r18, r1, 4
	mfs r3,  rmsr     /* msr�̕ۑ� */
	swi r3,  r1, 0

	lwi   r5,  r13, interrupt_count
	bgti  r5,  nest_int      /* �l�X�g�񐔂�1�ȏ�Ȃ�X�^�b�N��؂�ւ��Ȃ� */
	
	/*
	 * �X�^�b�N�|�C���^�؂�ւ�
	 */
	la    r4,  r0, STACK_TOP   /* �^�X�N�Ɨ����̃X�^�b�N�̓ǂݍ��� */
	sw    r1,  r0, r4          /* �^�X�N�X�^�b�N�̕ۑ�             */
	Mov   r1,  r4              /* �X�^�b�N�|�C���^�؂�ւ�         */
nest_int:
	/* 
     * �����݃l�X�g�񐔂̃C���N�������g
	 */
	addi  r5,  r5,  1 
	swi   r5,  r13, interrupt_count

	lwi   r3,  r0, INTC_IVR    /* �x�N�^�̓ǂݍ���                 */
	add   r3,  r3, r3          /* �x�N�^��4�{                      */
	add   r3,  r3, r3	        
	lwi   r5,  r3, int_handler_table /* �n���h���A�h���X�̓ǂݍ��� */
	lwi   r6,  r3, int_bit_table     /* �}�X�N�r�b�g�̓ǂݍ���     */
	swi   r6,  r0, INTC_CIE          /* �������������݂��}�X�N     */
	ori   r4,  r0, 0x02 | MSR_CACHE_SETTING /* r4 = 0x02           */
	Push  r6                         /* �}�X�N�r�b�g���X�^�b�N��   */

	mts   rmsr,r4                    /* �����݋���(MSR(IE)���Z�b�g)*/

	brald r15, r5             /* �n���h���Ăяo�� */
	 nop

    la    r4, r0, MSR_CACHE_SETTING  
	mts   rmsr,r4                    /* �����݋֎~                 */

//    ori   r4,  r0, 0x03       /* r4 = 0x03                         */
//    swi   r4,  r0, INTC_MER   /* INTC_MER = 0x0 INTC�X�^�[�g       */

	Pop   r6                         /* �}�X�N�r�b�g�̎��o��     */
//	swi   r6,  r0, INTC_IAR          /* ACK                        */        
	swi   r6,  r0, INTC_SIE          /* ���������݂̋���           */

	/*
	 *  �����݃l�X�g�񐔂̃f�N�������g
     */
	lwi   r5,  r13, interrupt_count
	addi  r5,  r5,  -1 
	swi   r5,  r13, interrupt_count
	
	bgti  r5,  ret_to_task_int      /* �l�X�g�񐔂�1�ȏ�Ȃ�߂� */

	lw    r1,  r0, r1	            /* �X�^�b�N�|�C���^��߂�    */  
	lwi   r4,  r13, reqflg          /* reqflg �̃`�F�b�N         */
	beqi  r4,  ret_to_task_int      /* FALSE �Ȃ� �^�X�N�ɖ߂�   */
	bri   ret_int                   /* TRUE �Ȃ� ret_int ��      */
ret_to_task_int:
	lwi  r3,  r1, 0
	mts  rmsr,r3
	lwi  r18, r1, 4
	lwi  r17, r1, 8
	lwi  r16, r1, 12
	lwi  r15, r1, 16
	lwi  r14, r1, 20
	lwi  r12, r1, 24
	lwi  r11, r1, 28
	lwi  r10, r1, 32
	lwi  r9,  r1, 36
	lwi  r8,  r1, 40
	lwi  r7,  r1, 44
	lwi  r6,  r1, 48
	lwi  r5,  r1, 52
	lwi  r4,  r1, 56
	lwi  r3,  r1, 60
	rtid r14,0 
	addik r1,r1,64



	/*
	 * ���o�^�̊����݂���������ƌĂяo�����
	 * Not Yet!
	 */
	.globl no_reg_interrupt
	.align 2
no_reg_interrupt:
	nop


	/*
	 * �^�X�N�f�B�X�p�b�`��
	 * 
	 * dispatch �́Cinterrupt_count = 0 
     * MSR�� IE=0 �̊����݋֎~��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
	 * exit_and_dispatch �����l�ɁCinterrupt_count = 0 �����݋֎~��Ԃ�
     * �Ăяo���̂������ł��邪�C�J�[�l���N�����ɑΉ����邽�߁C
     * interrupt_count = 1 �ŌĂяo�����ꍇ�ɂ��Ή����Ă���D
	 *    
	 */
	
	.globl dispatch
	.align  2
dispatch:
	addi  r1,  r1,  -64  /* �X�N���b�`���W�X�^�ȊO��ۑ����� */
	swi   r15, r1,  60
	mfs   r3,  rmsr      /* msr�̕ۑ�(�L���b�V���̐ݒ�̕ۑ�) */
	swi   r3,  r1,  56                
	swi   r18, r1,  52   /* �K�v��? */
	swi   r19, r1,  48
	swi   r20, r1,  44
	swi   r21, r1,  40
	swi   r22, r1,  36
	swi   r23, r1,  32
	swi   r24, r1,  28
	swi   r25, r1,  24
	swi   r26, r1,  20
	swi   r27, r1,  16
	swi   r28, r1,  12
	swi   r29, r1,  8
	swi   r30, r1,  4
	swi   r31, r1,  0
	lwi   r4 , r13, runtsk     /* r4 <- runtsk */
	swi   r1 , r4,  TCB_sp 	   /* �^�X�N�X�^�b�N��TCB�ɕۑ� */	
	la    r5 , r0,  dispatch_r /* ���s�ĊJ�Ԓn��ۑ� */
	swi   r5 , r4,  TCB_pc     /* ���s�ĊJ�Ԓn��TCB�ɕۑ�   */
	bri   dispatcher

dispatch_r:
	lwi  r31,  r1, 0      /* ���W�X�^�𕜋A */
	lwi  r30,  r1, 4
	lwi  r29,  r1, 8
	lwi  r28,  r1, 12
	lwi  r27,  r1, 16
	lwi  r26,  r1, 20
	lwi  r25,  r1, 24
	lwi  r24,  r1, 28
	lwi  r23,  r1, 32
	lwi  r22,  r1, 36
	lwi  r21,  r1, 40
	lwi  r20,  r1, 44
	lwi  r19,  r1, 48
	lwi  r18,  r1, 52
    lwi  r3,   r1, 56   /* MSR��߂�(�L���b�V���̐ݒ��߂�) */
    mts  rmsr,r3            
	addi r1,   r1, 60   /* �X�^�b�N�|�C���^��߂� */
	/*
	 *  �^�X�N��O�������[�`���̋N��
	 *  dispatch_r �� dispatcher ����Ăяo����邽�߁C
	 *  tcb �̃A�h���X�� r4 �ɓ����Ă���
     *  Not Yet!
	 */
	lwi  r5,  r4,  TCB_enatex  /* r5 <- enatex                 */
	andi r6,  r5,  TCB_enatex_mask  
	beqi r6,  dispatch_r_1     /* enatex �� FALSE �Ȃ烊�^�[�� */
	lwi  r7,  r4,  TCB_texptn  /* r5 <- texptn                 */
	beqi r7,  dispatch_r_1     /* texptn �� 0 �łȂ����       */
	brlid r15  call_texrtn     /* �^�X�N��O���[�`���̌Ăяo�� */	
	 nop
dispatch_r_1:
	Pop     r15
	rtsd	r15,8 
	 nop



	.globl exit_and_dispatch
exit_and_dispatch:
	/* interrupt_count ���N���A */
	swi   r0,  r13, interrupt_count 
dispatcher:
	/*
	 * �����͊����݋֎~�ŗ��邱��
	 */
	lwi  r4,  r13, schedtsk  /* r4 <- schedtsk              */
	swi  r4,  r13, runtsk    /* schedtsk �� runtsk ��       */        
	beqi r4,  dispatcher_1   /* schedtsk �����邩           */
	lwi  r1,  r4,  TCB_sp    /* TCB����^�X�N�X�^�b�N�𕜋A */
	lwi  r5,  r4,  TCB_pc    /* TCB������s�ĊJ�Ԓn�𕜋A   */
	bra  r5	  
dispatcher_1:
	/*
	 * �����Ŋ����݃��[�h�ɐ؂�ւ���̂́C�����Ŕ������銄���ݏ���
     * �ɂǂ̃X�^�b�N���g�����Ƃ������̉����ƁC�����݃n���h������
	 * �̃^�X�N�f�B�X�p�b�`�̖h�~�Ƃ���2�̈Ӗ�������D
	 */
	la   r1,  r0,  STACKTOP         /* �����݃X�^�b�N�ɕύX             */
	la   r6,  r0,  1                /* interrupt_count ��1��            */
	swi  r6,  r13, interrupt_count
	la   r5,  r0, 0x02 | MSR_CACHE_SETTING /* IE = '1'               */
	la   r4,  r0, MSR_CACHE_SETTING        /* IE = '0'               */        
dispatcher_2:
	mts   rmsr, r5   /* �����݋���(MSR(IE)���Z�b�g)      */
	nop
	nop
	mts   rmsr, r4                  /* �����݋֎~(MSR(IE)���N���A)      */
	lwi   r6,  r13,  reqflg         /* r6 <- reqflg                     */
	beqi  r6,  dispatcher_2         /* reqflg �� FALSE �Ȃ�             */
	swi   r0,  r13, interrupt_count /* interrupt_count ���N���A         */
	swi   r0,  r13,  reqflg         /* reqflg �� FALSE ��               */	
	bri   dispatcher

	/*
	 *  �����݃n���h��/CPU��O�n���h���o������
	 * 
	 * �߂�悪�^�X�N�� reqflg ���Z�b�g����Ă���ꍇ�݂̂����ɂ���D
	 * interrupt_count = 0�C�����݋֎~��ԁC�X�N���b�`���W�X�^��ۑ�����
	 * ��ԂŌĂяo�����ƁD
	 */
	.align 2
	.globl ret_int
	.globl ret_exc
ret_exc:
ret_int:
	swi  r0,  r13,  reqflg   /* reqflg �� FALSE �� */
	lwi  r4,  r13,  runtsk   /* r4 <- runtsk        */
	lwi  r6,  r13,  enadsp   /* r6 <- enadsp        */
	beqi r6,  ret_int_1      /* enadsp �� FALSE �Ȃ� ret_int_1 �� */
	lwi  r5,  r13,  schedtsk /* r5 <- schedtsk                    */
	sub  r6,  r5,   r4       /* runtsk �� schedtsk �������Ȃ�     */
	beqi r6,  ret_int_1      /* ret_int_1 ��                      */
	addi  r1,  r1,  -52      /* �c��̃��W�X�^��ۑ�����          */
	swi   r19, r1,  48
	swi   r20, r1,  44
	swi   r21, r1,  40
	swi   r22, r1,  36
	swi   r23, r1,  32
	swi   r24, r1,  28
	swi   r25, r1,  24
	swi   r26, r1,  20
	swi   r27, r1,  16
	swi   r28, r1,  12
	swi   r29, r1,  8
	swi   r30, r1,  4
	swi   r31, r1,  0	
	swi   r1 , r4,  TCB_sp 	   /* �^�X�N�X�^�b�N��TCB�ɕۑ� */	
	la    r6 , r0,  ret_int_r  /* ���s�ĊJ�Ԓn��ۑ� */
	swi   r6 , r4,  TCB_pc     /* ���s�ĊJ�Ԓn��TCB�ɕۑ�   */
	bri   dispatcher

ret_int_r:	
	lwi  r31,  r1,  0      /* ���W�X�^�𕜋A */
	lwi  r30,  r1,  4
	lwi  r29,  r1,  8
	lwi  r28,  r1,  12
	lwi  r27,  r1,  16
	lwi  r26,  r1,  20
	lwi  r25,  r1,  24
	lwi  r24,  r1,  28
	lwi  r23,  r1,  32
	lwi  r22,  r1,  36
	lwi  r21,  r1,  40
	lwi  r20,  r1,  44
	lwi  r19,  r1,  48
	addi r1,   r1,  52
	lwi  r3,   r1,   0    /* MSR ��߂��i�L���b�V���̐ݒ��߂��j*/
	mts  rmsr, r3                
ret_int_1:
	/*
	 * �^�X�N��O���[�`���̋N��
	 * ret_int_r �� dispatcher ����Ăяo����邽�߁C
	 * tcb �̃A�h���X�� r4 �ɓ����Ă���
	 */
	lwi  r5,  r4,  TCB_enatex  /* r5 <- enatex                 */
	andi r6,  r5,  TCB_enatex_mask  
	beqi r6,  ret_int_2        /* enatex �� FALSE �Ȃ烊�^�[�� */
	lwi  r7,  r4,  TCB_texptn  /* r5 <- texptn                 */
	beqi r7,  ret_int_2        /* texptn �� 0 �łȂ����       */
	brlid r15  call_texrtn     /* �^�X�N��O���[�`���̌Ăяo�� */	
	 nop
ret_int_2:
	lwi  r3,  r1, 0    /* MSR ��߂��i������IE=0�Ŋ����݋֎~�ɂȂ�j*/
	mts  rmsr,r3
	lwi  r18, r1, 4
	lwi  r17, r1, 8
	lwi  r16, r1, 12
	lwi  r15, r1, 16
	lwi  r14, r1, 20
	lwi  r12, r1, 24
	lwi  r11, r1, 28
	lwi  r10, r1, 32
	lwi  r9,  r1, 36
	lwi  r8,  r1, 40
	lwi  r7,  r1, 44
	lwi  r6,  r1, 48
	lwi  r5,  r1, 52
	lwi  r4,  r1, 56
	lwi  r3,  r1, 60
	rtid r14,0 
	 addik r1,r1,64	



	/*
	 * �^�X�N�N������
     *   
     *  �X�^�b�N�̎���
     *  Microblaze Processor Reference Guide 52�`53���
     *  �֐��ďo���̂��������́Cr5�`r10 �Ɋi�[����D
     *  ����Ɠ����Ɍďo�����̓X�^�b�N�t���[���Ɉ����̊i�[�ꏊ���m�ۂ���K�v
     *  ������D����ɂ��̏�ɂ̓����N���W�X�^(R15)�̕��̗̈悪�K�v�ƂȂ�D
     *  �ďo����͍X�ɑ��̊֐����Ăяo���ꍇ���� r5�`r10 �����̗̈�ɕۑ���
     * ��D
     *  Low Address
     *             --------------------
     *  new_sp -> | Link Register(R15) |
     *             --------------------
     *            |   Arg1�p�̗̈�     |
     *             --------------------
     *            |   Arg2�p�̗̈�     |
     *             --------------------        
     *            |      ....          |
     *             --------------------
     *  High Address
	 */

	.text
	.globl activate_r
	.align 2
activate_r:
	ori   r4,  r0, 0x02 | MSR_CACHE_SETTING  /* msr�̏����l        */
	mts   rmsr,r4              /* �����݋���(MSR(IE)���Z�b�g)      */
    lw    r11, r1, r0          /* �^�X�N�̎��s�Ԓn                 */
    lwi   r5,  r1,  4          /* �����iexinf�j                    */
	la    r15, r0,  ext_tsk -8 /* �^�X�N����̖߂��               */
	bra   r11                  /* �^�X�N�̎��s�J�n                 */


        
    /*
     * �������ԑ҂�
     */
     .globl _sil_dly_nse
_sil_dly_nse:
     addi   r5, r5, -SIL_DLY_TIM1
     bgti   r5, _sil_dly_nse_1
     rtsd   r15, 8
      nop  
_sil_dly_nse_1:
     addi   r5, r5, -SIL_DLY_TIM2
     bgti   r5, _sil_dly_nse_1
     rtsd   r15, 8
      nop          