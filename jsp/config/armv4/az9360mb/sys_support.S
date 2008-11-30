/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005-2007 by Y.D.K.Co.,LTD Technologies company
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
 *  @(#) $Id: sys_support.S,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

#define _MACRO_ONLY
#include "jsp_kernel.h"
#include <ns9360.h>

/* �v���Z�b�T���[�h */
Mode_SVC    =   0x13

/* �X�e�[�^�X���W�X�^���荞��bit */
I_Bit       =   0x80
F_Bit       =   0x40

/*  BBUS reset register */
BBUS_RESET_BASE     = 0x90600000


/*
 *  �჌�x���̃^�[�Q�b�g�V�X�e���ˑ��̏�����
 *
 *  �X�^�[�g�A�b�v���W���[���̒��ŁC�������������̑O�ɌĂяo�����D          
 */       

        .text
        .align 2
        .global hardware_init_hook
hardware_init_hook: 

/*
 * NS9360�ˑ��̏�����
 */
/*
 * bbus_reset
 */
        mov     r0, #0x0
        ldr     r0, =BBUS_RESET_BASE
        mov     r1, #0x0
        str     r1, [r0, #0]

/*
 * CS�AGPIO Initial
 */
        stmfd sp!, {r4 - r11,lr}   /* ���W�X�^�̕ۑ� */
        bl      cpu_CsGpioInit
        ldmfd sp!,{r4 - r11,lr}

/*----*/
init_done:
        mov     pc, lr


/*
 *
 *  �����݂̏o���������
 *         
 */        
        .text
        .align 4    
        .global IRQ_Handler
IRQ_Handler:

        /* 
         * �����݃��[�h 
         * 
         * cpsr��spsr_irq�ɕ��A�悪r14_irq(lp)�ɓ���C
         * spsr_irq��r14_irq��r13(sp)_irq�� r14,r13�ƂȂ�D
         */

        /* 
         *  �^�X�N�̓��쎞���[�h(�X�[�p�[�o�C�U�[���[�h)��
         */
        mov     sp,#(CPSR_SVC | CPSR_FIQ_BIT | CPSR_IRQ_BIT) 
        msr     cpsr_all, sp
        stmfd   sp!, {r0-r3,ip,lr,pc} /* pc�̓_�~�[ */


        /*
         * spsr�Ɩ߂�Ԓn���擾���邽�߂�IRQ���[�h��
         */
        mov     r0,#(CPSR_IRQ | CPSR_FIQ_BIT | CPSR_IRQ_BIT)
        msr     cpsr,r0
        sub     r0,lr,#4
        mrs     r1,spsr
        

        /*
         *  �X�[�p�[�o�C�U�[���[�h��
         */ 
        and     r2,  r1, #CPSR_FIQ_BIT /* FIQ�r�b�g�̌p�� */
        orr     r2,  r2, #(CPSR_SVC|CPSR_IRQ_BIT)
        msr     cpsr, r2
        str     r0, [sp,#0x18] /* Store pc */
        stmfd   sp!,{r1}       /* spsr */


        /*
         *  ���d���荞�݂�����
         */
        ldr     r2, =interrupt_count
        ldr     r3, [r2]
        add     r0,r3,#1
        str     r0, [r2]
        cmp     r3, #0x00

        moveq   r2,sp            /* �l�X�g���荞�݂łȂ��ꍇ */
        ldreq   sp,=STACKTOP     /* �X�^�b�N�̕ύX    */
        stmeqfd sp!,{r2}         /* �^�X�N�X�^�b�N�̕ۑ� */

        /*
         *  ���荞�ݗv���̔���D
         *  INT_ID�̓ǂݍ��݁D(�����ɂ���K�v�͂Ȃ��D)
         */

        ldr     r3, =ISRADDR_REG
        ldr     r0, [r3]        /* ���荞�݃x�N�^�̓ǂݏo�� */

        /*
         *  ����`�̊����݂��`�F�b�N
         */
        cmp     r0, #0x00
        beq     undefined_interrupt
        
        /* 
         * ���荞�݋��� 
         */
        mrs     r2, cpsr
        and     r2,  r2, #~CPSR_IRQ_BIT /* �����݋��� */
        msr     cpsr,r2

        /* 
         * Call Handler  
         */        
        mov     lr,  pc   
        mov     pc,  r0

        /* 
         * ���荞�݋֎~ 
         */
        mrs     r2, cpsr
        and     r2,  r2, #CPSR_FIQ_BIT /* FIQ�r�b�g�̌p�� */         
        orr     r2,  r2, #(CPSR_SVC|CPSR_IRQ_BIT)
        msr     cpsr,r2

        /* 
         * �����݃l�X�g��(interrupt_count) �f�N�������g 
         */
        ldr     r2, =interrupt_count
        ldr     r1, [r2]        
        sub     r3, r1, #1                        
        str     r3, [r2]
        cmp     r3, #0x00        
        bne     return_to_task_irq
        
        /*
         * �����݃l�X�g�������̂ŁA�S�Ẵ}�X�N���N���A
         */
        ldr     r2,  =ISRADDR_REG
        str     r0,  [r2]       /* �����݃}�X�N�N���A */
        /* 
         * �^�X�N�X�^�b�N�̕��A 
         */
        ldmfd   sp!,{r0}         
        mov     sp, r0        
                
        ldr     r1, =reqflg    /* Check reqflg */
        ldr     r0, [r1]
        cmp     r0, #0
        beq     return_to_task_irq
        mov     r0, #0
        str     r0, [r1]       /* Clear reqflg */
        b       ret_int

return_to_task_irq:
        /*
         *  ���A����
         *  ���荞�݋��ƂȂ邪�^�X�N�R���e�L�X�g��ɕۑ����Ă��邽�߁C
         *  ���͂Ȃ�
         */
        ldmfd   sp!,{r1}           /* CPSR�̕��A���� */
        mrs     r2, cpsr           /* FIQ���p��            */
        and     r2, r2, #CPSR_FIQ_BIT
        and     r1, r1, #~CPSR_FIQ_BIT
        orr     r1, r1, r2            
        msr     spsr, r1           
        ldmfd   sp!,{r0-r3,ip,lr,pc}^ /*�^�X�N���A + �����݋��� */

        /*
         *  ����`�̊����݂��������Ƃ��ɌĂяo��
         */    
undefined_interrupt:
         b      undef_interrupt
    

/*
 * �L���b�V������֌W
 * UW       cpuEnableICache( void );
 * UW       cpuEnableDCache( void );
 * UW       cpuEnableMMU( UW tlbaddr );
 * UW       cpuDCache_Line_Invalid( UW mva );
 * UW       cpuDCache_Line_Flush( UW mva );
 * UW       cpuDCache_Line_FlushInalid( UW mva );
 * UW       cpuDCache_DrainWriteBuffer( void );
 */


        .global cpuEnableICache, cpuEnableDCache
        .global cpuEnableMMU
        .global cpuDCache_Line_Invalid, cpuDCache_Line_Flush
        .global cpuDCache_Line_FlushInvalid, cpuDCache_DrainWriteBuffer


#define CP15_ICACHE     0x1000
#define CP15_DCACHE     0x0004
#define CP15_MMU        0x0001


/*
 * CP15-R1��I-cache bit(b12)=1 �ɂ���B
 * �����Ȃ�
 */
cpuEnableICache:
        mcr     p15, 0, r0, c7, c5, 0       /* ICache invalidate                */
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        mrc     p15, 0, r0, c1, c0, 0       /* CP15 R1                          */
        orr     r0, r0, #CP15_ICACHE        /* I-Cache enable                   */
        mcr     p15, 0, r0, c1, c0, 0       /* Set CP15 R1 I-cache              */
        mov     pc, lr


/*
 * CP15-R7��Dcache invalidate ���{���CP15-R1��D-cache bit(b2)=1�ɂ���B
 * �����Ȃ��B
 */
cpuEnableDCache:
        mcr     p15, 0, r0, c7, c6, 0       /* DC all invalidate                */
        mrc     p15, 0, r0, c1, c0, 0       /* CP15 R1                          */
        orr     r0, r0, #CP15_DCACHE        /* D-Cache enable                   */
        mcr     p15, 0, r0, c1, c0, 0       /* Set CP15 R1 D-cache              */
        mov     pc,lr


/*
 * CP15-R1��MMU bit(bit0)=1�ɂ���BTLB�ݒ���TBL�A�h���X�������ɃR�[������B
 * r0:TLB address
 */
cpuEnableMMU:
        mcr     p15, 0, r0, c2, c0, 0       /* Set CP15 R2 TLB pointer          */
        mov     r0, #0                      /*                                  */
        mvn     r0, r0                      /* all domain is manager            */
        mcr     p15, 0, r0, c3, c0, 0       /* set Domain access (CP15 R3)      */

        mrc     p15, 0, r0, c1, c0, 0       /* CP15 R1                          */
        orr     r0, r0, #CP15_MMU           /* MMU enable                       */
        mcr     p15, 0, r0, c1, c0, 0       /* Set CP15 R1 MMU enable           */
        mov     pc,lr


/*
 * CP15-R7��Invalidate DCache single entry(MVA)�����s����B
 * r0:MVA
 */
cpuDCache_Line_Invalid:
        mcr     p15, 0, r0, c7, c6, 1       /* DC invalidate single entry(MVA)  */
        mov     pc,lr


/*
 * CP15-R7��Clean DCache single entry(MVA)�����s����B
 * r0:MVA
 */
cpuDCache_Line_Flush:
        mcr     p15, 0, r0, c7, c10, 1      /* DC clean single entry(MVA)       */
        mov     pc,lr


/*
 * CP15-R7��Clean & Invalidate DCache single entry(MVA)�����s����B
 * r0:MVA
 */
cpuDCache_Line_FlushInvalid:
        mcr     p15, 0, r0, c7, c14, 1      /* DC clean single entry(MVA)       */
        mov     pc,lr


/*
 * CP15-R7��Drain write buffer�����s����B
 */
cpuDCache_DrainWriteBuffer:
        mcr     p15, 0, r0, c7, c10, 4      /* Drain write buffer               */
        mov     pc,lr
