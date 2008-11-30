/* 
 *
 *  TOPPERS/JSP Kernel
 *     Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
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
#include <nios2.h>

    .set noat
    .section .exceptions, "xa"
    .align 2
    .global _irq_entry
    .type   _irq_entry, @function
_irq_entry:
    /*
     *  ��O�v���̔���
     */
    rdctl   et, estatus
    andi    et, et, 1
    beq     et, zero, _check_trap
    rdctl   et, ipending
    beq     et, zero, _check_trap

    
   /*
    * ��O�v���͊�����
    */
    addi ea, ea, -4      /* �߂�Ԓn���f�N�������g */

    addi  sp, sp, -76    /* ���W�X�^�̕ۑ� */
    rdctl et, estatus
    stw   et,   0(sp)
    stw   at,   4(sp)
    stw   r2,   8(sp)
    stw   r3,  12(sp)
    stw   r4,  16(sp)
    stw   r5,  20(sp)
    stw   r6,  24(sp)
    stw   r7,  28(sp)
    stw   r8,  32(sp)
    stw   r9,  36(sp)
    stw   r10, 40(sp)
    stw   r11, 44(sp)
    stw   r12, 48(sp)
    stw   r13, 52(sp)
    stw   r14, 56(sp)
    stw   r15, 60(sp)
    stw   fp,  64(sp)
    stw   ra,  68(sp)
    stw   ea,  72(sp)

    /*
     * ���d�����݂�����
     */
    ldw   r3, %gprel(interrupt_count)(gp)  /* �l�X�g�񐔂̃`�F�b�N */
    bltu  zero, r3,  nest_int

    movhi r2, %hiadj(STACKTOP-4)
    addi  r2, r2, %lo(STACKTOP-4)
    stw   sp, 0(r2)     /* �X�^�b�N�|�C���^�̕ۑ� */        
    mov   sp, r2        /* �X�^�b�N�|�C���^�̓���ւ� */
nest_int:
    /*
     *  �����ݗv���̔���ƌĂяo��
     */
    call int_handler_call

ret_from_int:
    ldw   r3, %gprel(interrupt_count)(gp)   
    bltu  zero, r3, res_reg_and_ret /* �l�X�g�񐔂�1�ȏ�Ȃ�߂� */

    ldw   r2, 0(sp)                 /* �X�^�b�N�|�C���^��߂� */
    mov   sp, r2                    /* �X�^�b�N�|�C���^��߂� */

    ldw   r3, %gprel(reqflg)(gp)    /* reqflg�̃`�F�b�N */
    beq   r3, zero, res_reg_and_ret
    br    ret_int

res_reg_and_ret:
    ldw   et,   0(sp)  /* ���W�X�^�̕��A */
    wrctl estatus, et
    ldw   at,   4(sp)
    ldw   r2,   8(sp)
    ldw   r3,  12(sp)
    ldw   r4,  16(sp)
    ldw   r5,  20(sp)
    ldw   r6,  24(sp)
    ldw   r7,  28(sp)
    ldw   r8,  32(sp)
    ldw   r9,  36(sp)
    ldw   r10, 40(sp)
    ldw   r11, 44(sp)
    ldw   r12, 48(sp)
    ldw   r13, 52(sp)
    ldw   r14, 56(sp)
    ldw   r15, 60(sp)
    ldw   fp,  64(sp)
    ldw   ra,  68(sp)
    ldw   ea,  72(sp)
    addi  sp, sp, 76        
    eret      


_check_trap:        
    /*
     *  Trap������
     */
    ldw   et, -4(ea)               /* ��O���o�������߂��擾 */
    xorhi et, et, 0x003b           /*  ���16bit             */
    xori  et, et, 0x683a           /*  ����16bit             */
    beq   et, zero, trap_handler

_check_exc:
    addi  sp, sp, -76
    rdctl et,   estatus
    stw   et,    0(sp)
    stw   at,    4(sp)
    stw   r2,    8(sp)
    stw   r3,   12(sp)
    stw   r4,   16(sp)
    stw   r5,   20(sp)
    stw   r6,   24(sp)
    stw   r7,   28(sp)
    stw   r8,   32(sp)
    stw   r9,   36(sp)
    stw   r10,  40(sp)
    stw   r11,  44(sp)
    stw   r12,  48(sp)
    stw   r13,  52(sp)
    stw   r14,  56(sp)
    stw   r15,  60(sp)
    stw   fp,   64(sp)
    stw   ra,   68(sp)
    stw   ea,   72(sp)
    mov   r4,   sp     /* �n���h���̈��� */

    /*
     * ���d�����݂�����
     */
    ldw   r3, %gprel(interrupt_count)(gp)  /* �l�X�g�񐔂̃`�F�b�N */
    bltu  zero, r3,  nest_int_exc
    
    movhi r2, %hiadj(STACKTOP-4)
    addi  r2, r2, %lo(STACKTOP-4)
    stw   sp, 0(r2)     /* �X�^�b�N�|�C���^�̕ۑ� */        
    mov   sp, r2        /* �X�^�b�N�|�C���^�̓���ւ� */
nest_int_exc:
    
    call exc_handler_call  /* CPU��O�n���h���Ăяo�����[�`���̎��s */

    br ret_from_int        /* ���^�[������ */


trap_handler:
   /*
    *  Trap�n���h���[
    */
    eret  



    .set noat
    .align  2
    .global ret_int
    .global ret_exc
ret_int:
ret_exc:
    stw   zero, %gprel(reqflg)(gp)   /* reqflg �� FALSE�� */
    ldw   r5,   %gprel(runtsk)(gp)   /* r5 <- runtsk      */
    ldw   r6,   %gprel(enadsp)(gp)   /* r6 <- enadsp      */
    beq   r6,   zero, ret_int_1      /* enadsp �� FALSE �Ȃ� ret_int_1 �� */
    ldw   r4,   %gprel(schedtsk)(gp) /* r4 <- schedtsk    */
    beq   r4,   r5, ret_int_1        /* runtsk �� schedtsk�������Ȃ�ret_int_1�� */
    addi  sp,   sp, -32              /* �c��̃��W�X�^��ۑ� */    
    stw   r16,  0(sp)
    stw   r17,  4(sp)
    stw   r18,  8(sp)
    stw   r19, 12(sp)
    stw   r20, 16(sp)
    stw   r21, 20(sp)
    stw   r22, 24(sp)
    stw   r23, 28(sp)
    stw   sp,  TCB_sp(r5)         /* �^�X�N�X�^�b�N��TCB�ɕۑ� */
    movhi r2,  %hiadj(ret_int_r)  /* ���s�J�n�Ԓn��ۑ�        */
    addi  r2,  r2, %lo(ret_int_r)
    stw   r2,  TCB_pc(r5)         /* ���s�ĊJ�Ԓn��TCB�ɕۑ�   */
    br    dispatcher

ret_int_r:
    ldw   r16,  0(sp)       /* ���W�X�^�𕜋A */
    ldw   r17,  4(sp)
    ldw   r18,  8(sp)
    ldw   r19, 12(sp)
    ldw   r20, 16(sp)
    ldw   r21, 20(sp)
    ldw   r22, 24(sp)
    ldw   r23, 28(sp)
    addi  sp, sp, 32    
ret_int_1:
    /*
     *  �^�X�N��O���[�`���̋N��    
     *  ret_int_r �� dispatcher ����Ăяo����邽�߁C
     *  tcb�̃A�h���X�� r4 �ɓ����Ă���
     */
    ldw  r5, TCB_enatex(r4)       /* r5 <- enatex */
#if TCB_enatex_mask > 0xffff
    andhi r6, r5, %hi(TCB_enatex_mask)
#else
    andi r6, r5, %lo(TCB_enatex_mask)
#endif /* TCB_enatex_mask > 0xffff */
    andhi r6, r5, 4
    beq  r6, zero, ret_int_2      /* enatex �� FALSE �Ȃ烊�^�[�� */
    ldw  r7, TCB_texptn(r4)       /* r7 <- texptn, texptn��0�łȂ���� */
    beq  zero, r7, ret_int_2      
    call call_texrtn              /* �^�X�N��O���[�`���̌Ăяo�� */

ret_int_2:
    ldw   et,   0(sp)    /* ���W�X�^�𕜋A */
    wrctl estatus, et
    ldw   at,   4(sp)
    ldw   r2,   8(sp)
    ldw   r3,  12(sp)
    ldw   r4,  16(sp)
    ldw   r5,  20(sp)
    ldw   r6,  24(sp)
    ldw   r7,  28(sp)
    ldw   r8,  32(sp)
    ldw   r9,  36(sp)
    ldw   r10, 40(sp)
    ldw   r11, 44(sp)
    ldw   r12, 48(sp)
    ldw   r13, 52(sp)
    ldw   r14, 56(sp)
    ldw   r15, 60(sp)
    ldw   fp,  64(sp)
    ldw   ra,  68(sp)
    ldw   ea,  72(sp)
    addi  sp, sp, 76        
    eret      


    

    .global dispatch
    .align  2
dispatch:
    addi  sp, sp, -40                /* ���W�X�^��ۑ� */    
    stw   r16,  0(sp)
    stw   r17,  4(sp)
    stw   r18,  8(sp)
    stw   r19, 12(sp)
    stw   r20, 16(sp)
    stw   r21, 20(sp)
    stw   r22, 24(sp)
    stw   r23, 28(sp)
    stw   fp,  32(sp)
    stw   ra,  36(sp)
    ldw   r4,  %gprel(runtsk)(gp)  /* r4 <- runtsk              */
    stw   sp,  TCB_sp(r4)          /* �^�X�N�X�^�b�N��TCB�ɕۑ� */
    movhi r5,  %hiadj(dispatch_r)  /* ���s�J�n�Ԓn��ۑ�        */
    addi  r5,  r5, %lo(dispatch_r)
    stw   r5,  TCB_pc(r4)          /* ���s�ĊJ�Ԓn��TCB�ɕۑ�   */
    br    dispatcher

dispatch_r:
    ldw   r16,  0(sp)              /* ���W�X�^�𕜋A */
    ldw   r17,  4(sp)
    ldw   r18,  8(sp)
    ldw   r19, 12(sp)
    ldw   r20, 16(sp)
    ldw   r21, 20(sp)
    ldw   r22, 24(sp)
    ldw   r23, 28(sp)
    ldw   fp,  32(sp)     
    /*
     * �^�X�N��O���[�`���̋N��
     *  dispatch_r �� dispatcher ����Ăяo����邽�߁C
     *  tcb �̃A�h���X�� r4 �ɓ����Ă���
     */    
    ldw  r5, TCB_enatex(r4)       /* r5 <- enatex */
#if TCB_enatex_mask > 0xffff
    andhi r6, r5, %hi(TCB_enatex_mask)
#else
    andi r6, r5, %lo(TCB_enatex_mask)
#endif /* TCB_enatex_mask > 0xffff */
    beq  r6, zero, dispatch_r_1   /* enatex �� FALSE �Ȃ烊�^�[�� */
    ldw  r7, TCB_texptn(r4)       /* r7 <- texptn, texptn��0�łȂ���� */
    beq  r7, zero, dispatch_r_1    
    call call_texrtn              /* �^�X�N��O���[�`���̌Ăяo�� */

dispatch_r_1:
    ldw   ra, 36(sp)              /* �c��̃��W�X�^�𕜋A */    
    addi  sp, sp, 40                
    ret



    .global exit_and_dispatch
exit_and_dispatch:
    stw      zero, %gprel(interrupt_count)(gp)  /* interrupt_count ���N���A */
dispatcher:
    /*
     * �����͊����݋֎~�ŗ��邱��
     */    
    ldw   r4,   %gprel(schedtsk)(gp) /* r4 <- schedtsk              */
    stw   r4,   %gprel(runtsk)(gp)   /* schedtsk �� runtsk��        */
    beq   r4,   zero, dispatcher_1   /* schedtsk�����邩            */
    ldw   sp,   TCB_sp(r4)           /* TCB����^�X�N�X�^�b�N�𕜋A */
    ldw   r5,   TCB_pc(r4)           /* TCB������s�ĊJ�Ԓn�𕜋A   */
    jmp   r5
dispatcher_1:
    /*
     * �����Ŋ����݃��[�h�ɐ؂�ւ���̂́C�����Ŕ������銄���ݏ���
     * �ɂǂ̃X�^�b�N���g�����Ƃ������̉����ƁC�����݃n���h������
     * �̃^�X�N�f�B�X�p�b�`�̖h�~�Ƃ���2�̈Ӗ�������D
     */
    movhi sp, %hiadj(STACKTOP)            /* �����݃X�^�b�N�ɕύX  */
    addi  sp, sp, %lo(STACKTOP)              
    movi  r5, 1                           /* interrupt_count ��1�� */
    stw   r5, %gprel(interrupt_count)(gp)  
dispatcher_2:
    wrctl status, r5      /* �����݂̋��� */
    nop
    nop
    nop
    nop
    wrctl status, zero                      /* �����݂̋֎~             */
    ldw   r6, %gprel(reqflg)(gp)            /* r6 <- reqflg             */
    beq   r6, zero, dispatcher_2            /* reqflg �� FALSE �Ȃ�     */
    stw   zero, %gprel(interrupt_count)(gp) /* interrupt_count ���N���A */ 
    stw   zero, %gprel(reqflg)(gp)          /* reqflg �� FALSE ��       */ 
    br    dispatcher


    .text
    .global activate_r
    .align 2
activate_r:
    movi  r2, 1
    wrctl status, r2      /* �����݋���       */
    ldw   r4, 4(sp)       /* ����(exinf)      */
    ldw   r2, 0(sp)       /* �^�X�N�̎��s�Ԓn */
    addi  sp, sp, 8
    movhi ra, %hiadj(ext_tsk)
    addi  ra, ra, %lo(ext_tsk)
    jmp   r2              /* �^�X�N�̎��s�J�n */

