/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2005 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: start.S,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#define _MACRO_ONLY
#include <t_config.h>
#include <sys_defs.h>


     .section .entry, "xa"
     .align 2
     .global __reset
__reset:
#if NIOS2_ICACHE_SIZE > 0
    /* 
     * The assumption here is that the instruction cache size is always
     * a power of two.
     */

#if NIOS2_ICACHE_SIZE > 0x8000
    movhi r2, %hi(NIOS2_ICACHE_SIZE)
#else 
    movui r2, NIOS2_ICACHE_SIZE
#endif
0:
    initi r2
    addi r2, r2, -NIOS2_ICACHE_LINE_SIZE
    bgt r2, zero, 0b
1:

    .pushsection .debug_alt_sim_info
    .int 1, 1, 0b, 1b
    .popsection
#endif /* NIOS2_ICACHE_SIZE > 0 */

#ifndef BOOT_ROM
    movhi r3, %hiadj(_start)
    addi r3, r3, %lo(_start)
    jmp r3    
#else
    br _boot_rom
#endif  /* BOOT_ROM */


#ifdef BOOT_ROM
    .section .text
    .align 2
    .globl _
    .type _boot_rom, @function
_boot_rom:
#if NIOS2_DCACHE_SIZE > 0
#if NIOS2_DCACHE_SIZE > 0x8000
    movhi r2, %hi(NIOS2_DCACHE_SIZE)
#else
    movui r2, NIOS2_DCACHE_SIZE
#endif
0:
    initd 0(r2)
    addi r2, r2, -NIOS2_DCACHE_LINE_SIZE
    bgt r2, zero, 0b
1:
    .pushsection .debug_alt_sim_info
    .int 2, 1, 0b, 1b
    .popsection
#endif /* NIOS2_DCACHE_SIZE > 0 */

_boot_rom_1:
    movhi   r3, %hiadj(ROM_BASE)  /* r3 source */
    addi    r3, r3, %lo(ROM_BASE)
    movhi   r4, %hiadj(RAM_BASE)  /* r4 destination */
    addi    r4, r4, %lo(RAM_BASE)
    movhi   r2, %hiadj(_edata)
    addi    r2, r2, %lo(_edata)

_flash_copy:    
    ldw     r5, 0(r3)
    addi    r3, r3, 1
    stw     r5, 0(r4)
    addi    r4, r4, 1
    bgeu    r2, r4, _flash_copy

    movhi r2, %hiadj(_start)
    addi  r2, r2, %lo(_start)
    jmp   r2    
     nop
    
#endif /* BOOT_ROM */


    .section .text
    .align 2
    .globl _start
    .type _start, @function
_start:
#if NIOS2_DCACHE_SIZE > 0
#if NIOS2_DCACHE_SIZE > 0x8000
    movhi r2, %hi(NIOS2_DCACHE_SIZE)
#else
    movui r2, NIOS2_DCACHE_SIZE
#endif
0:
    initd 0(r2)
    addi r2, r2, -NIOS2_DCACHE_LINE_SIZE
    bgt r2, zero, 0b
1:
    .pushsection .debug_alt_sim_info
    .int 2, 1, 0b, 1b
    .popsection
#endif /* NIOS2_DCACHE_SIZE > 0 */

    /*
     *  �X�^�b�N�̐ݒ�
     */
    movhi sp, %hiadj(STACKTOP)
    addi  sp, sp, %lo(STACKTOP)
    
    /* 
     * set up the global pointer. 
     */
    movhi gp, %hiadj(_gp)
    addi  gp, gp, %lo(_gp)

start_0:
    movhi r2, %hiadj(_hardware_init_hook)
    addi  r2, r2, %lo(_hardware_init_hook)
    beq   zero, r2, start_1
    callr r2
    
    /*
     * Clear bss.
     */
start_1:
    movhi r3, %hiadj(__bss_start)
    addi  r3, r3, %lo(__bss_start)

    movhi r2, %hiadj(__bss_end)
    addi  r2, r2, %lo(__bss_end)

    beq   r3, r2, start_3
start_2:
    stw  zero, (r3)
    addi r3, r3, 4
    bltu r3, r2, start_2

start_3:
    movhi r2, %hiadj(_software_init_hook)
    addi  r2, r2, %lo(_software_init_hook)
    beq   zero, r2, start_4
    callr r2

start_4:
    
    call kernel_start

crt0_end:
    br crt0_end    