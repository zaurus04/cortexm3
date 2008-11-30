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
 *  @(#) $Id: start.S,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */
                
/*
 *    �J�[�l���p�̃X�^�[�g�A�b�v���W���[��(ARMv4�p)
 */
#define _MACRO_ONLY
#include <armv4.h>
#include <sys_defs.h>
        
#include <t_config.h>
 


        /*
         * Vector�e�[�u���ƃW�����v�e�[�u��
         * �T�C�Y�͍��v0x3c
         */
        .section .vector,"a"
        .code 32
        .align 0
        .global vector_table
vector_table:
        ldr pc, reset_vector       /* ���Z�b�g             */
        ldr pc, undef_vector       /* ����`����           */
        ldr pc, swi_vector         /* �\�t�g�E�F�A������   */
        ldr pc, prefech_vector     /* �v���t�F�b�`�A�{�[�h */
        ldr pc, data_abort_vector  /* �f�[�^�A�{�[�h       */
        ldr pc, reset_vector
        ldr pc, irq_vector         /* IRQ                  */
        ldr pc, fiq_vector         /* IRQ                  */

/*
 *  �x�N�^�[�e�[�u��
 */
reset_vector:
        .long   start
undef_vector:
        .long   undef_exception
swi_vector:
        .long   swi_exception
prefech_vector:
        .long   prefetch_exception
data_abort_vector:
        .long   data_abort_exception
irq_vector:
        .long   irq_exception
fiq_vector:
        .long   fiq_exception




        .text
        .code 32
        .align     0
        .global    start
start:
        mov  r1,  #(CPSR_SVC|CPSR_FIQ_BIT|CPSR_IRQ_BIT) /* To System mode */
		msr  cpsr, r1

        /*
         * �X�^�b�N�|�C���^�ƁC�t���[���|�C���^�̏�����
         * SL(�X�^�b�N������W�X�^r10)�͐ݒ肷��K�v�����邩?
         * gcc�̓f�B�t�H���g�ł�-mapcs�Ȃ̂ŕK�v�Ȃ�
         */
        ldr  r3, =STACKTOP
        mov  sp, r3
        mov  r11, #0        /* Arm���[�h�p�t���[���|�C���^   */         
        mov  r7, #0         /* Thubm���[�h�p�t���[���|�C���^ */

        /*
         * hardware_init_hook�̌Ăяo�� �i0�łȂ��ꍇ�j
         *
         * �^�[�Q�b�g�n�[�h�E�F�A�Ɉˑ����ĕK�v�ȏ���������������ꍇ
         * �́Chardware_init_hook �Ƃ����֐���p�ӂ���
         */
        ldr  r0, =hardware_init_hook
        cmp  r0, #0x00
        blne hardware_init_hook


        /*
         *  bss�Z�N�V�����̃N���A
         */        
start_1:
        ldr  r1, =__bss_start
        ldr  r2, =__bss_end
        cmp  r1,r2
        bhs  start_3
        mov  r0,#0
start_2:
        str  r0,[r1],#4
        cmp  r1, r2
        blo  start_2
        
        /*
         *  data�Z�N�V�����̏�����(ROM���Ή�)
         *  __idata_start ���� __idata_end �܂ł��C__data_start �ȍ~��
         *  �R�s�[����
         */
start_3:
#if 0
        ldr  r1, =__idata_start
        ldr  r3, =__idata_end
        cmp  r1, r3
        bhs  start_5
        ldr  r2, =__data_start
start_4:        
        ldr  r0, [r1],#4
        str  r0, [r2],#4
        cmp  r1, r3
        blo  start_4
#endif
        
        /*
         *  software_init_hook ���ďo���i0 �łȂ��ꍇ�j
         *
         *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�������
         *  ��������ꍇ�́Csoftware_init_hook �Ƃ����֐���p�ӂ����
         *  �悢�D
         */
start_5:
        ldr   r0, =software_init_hook
        cmp   r0, #0x00
        blne  software_init_hook

start_6:        
        bl    kernel_start