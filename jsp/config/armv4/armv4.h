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
 *  @(#) $Id: armv4.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *    ARMv4�̒�`
 */

#ifndef _ARMV4_H_
#define _ARMV4_H_

/*
 *  ARM Exception Vector
 */
#define SVC_Vector    0x00
#define UND_Vector    0x04
#define SWI_Vector    0x08
#define PRFA_Vector   0x0C
#define DATAA_Vector  0x10
#define IRQ_Vector    0x18
#define FIQ_Vector    0x1C


/*
 * ARM Exception Vector Number
 */
#define SVC_Number    0
#define UND_Number    1
#define SWI_Number    2
#define PRFA_Number   3
#define DATAA_Number  4
#define UNNOWN_Number 5
#define IRQ_Number    6
#define FIQ_Number    7

/*
 *  CPSR �����݋֎~�r�b�g
 */
#define CPSR_INT_MASK 0xC0
#define CPSR_IRQ_BIT  0x80
#define CPSR_FIQ_BIT  0x40

/*
 *  CPSR �̃��[�h�r�b�g
 */
#define CPSR_MODE_MASK   0x1f
#define CPSR_USER        0x10
#define CPSR_FIQ         0x11
#define CPSR_IRQ         0x12
#define CPSR_SVC         0x13
#define CPSR_ABT         0x17
#define CPSR_SYS         0x1F


/*
 * Stub Call
 */
#ifndef _MACRO_ONLY
Inline void
stub_exit(void){
    Asm("swi 0xff");
}

Inline void
stub_putc(char c)
{
    Asm("mov r0,#0x0; mov r4,%0; swi 0x123456"
        :: "r"(c):"r0","r4");
}

Inline void
stub_write(const char *string)
{
    int pos = 0;
    
    while(string[pos] !=0)
        stub_putc(string[pos++]);
}

Inline void
stub_set_inh(INHNO inhno, FP inthdr)
{
    Asm("mov r0,#0x1; mov r4,%0; mov r5,%1; swi 0x123456"
        : /* no output */
        : "r"(inhno),"r"(inthdr)
        : "r0", "r4", "r5");
    
}

#endif /* _MACRO_ONLY */

#endif /* _ARMV4_H_ */
