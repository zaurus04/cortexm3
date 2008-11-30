/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by Advanced Data Controls, Corp
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
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iIntegrator�p�j
 */

#include "jsp_kernel.h"
#include <integrator.h>

/*�V�X�e�����O�̂��߂̃|�[�g*/
#ifndef MULTI_IO
#include <hw_sysio.h>
#else
#include <stdio.h>
#endif





/*interrupt mask*/
UW irq_mask[MAX_INT_NUM]={
    MASK_IRQ_SOFTINT,
    MASK_IRQ_UART0,
    MASK_IRQ_UART1,
    MASK_IRQ_KBDINT,
    MASK_IRQ_MOUSEINT,
    MASK_IRQ_TM0,
    MASK_IRQ_TM1,
    MASK_IRQ_TM2,
    MASK_IRQ_RTCINT,
    MASK_IRQ_EXPINT0,
    MASK_IRQ_EXPINT1,
    MASK_IRQ_EXPINT2,
    MASK_IRQ_EXPINT3,
    MASK_IRQ_PCIINT0,
    MASK_IRQ_PCIINT1,
    MASK_IRQ_PCIINT2,
    MASK_IRQ_PCIINT3,
    MASK_IRQ_LINT,
    MASK_IRQ_DEGINT,
    MASK_IRQ_ENUMINT,
    MASK_IRQ_PCILBINT,
    MASK_IRQ_EXTINT
};

extern UW int_stack[];
/*
 * �����݃n���h���o�^�p�e�[�u��
 */
FP   int_table[MAX_INT_NUM];


/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
    int i;

    /*
     *  �����݃e�[�u���̏�����
     */
    for(i = 0; i < MAX_INT_NUM; i++){
        int_table[i] = 0x00;        /* ���Z�b�g */
   
    }

    /*
     *  ARM�̃x�N�^�e�[�u���֊����݃n���h����o�^
     */
    arm_install_handler(IRQ_Number,IRQ_Handler);
     
    /*
     *  �����݊֘A�̏�����
     */
    sil_wrw_mem((VP)IRQ0_ENABLECLR,INT_DISABLE_ALL);
    /*initialize system port*/
#ifndef MULTI_IO
    hw_sysio_initialize();
#endif
}


/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit(void)
{
    syslog(LOG_EMERG, "End Kernel.....!");
    while(1);
}


/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */

void
sys_putc(char c)
{
#ifndef MULTI_IO
    hw_sysio_putchar(c);
#else
    putchar(c);
#endif
}


/*
 *  �����݃n���h���̐ݒ�
 *
 *  �����ݔԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
void
define_inh(INHNO inhno, FP inthdr)
{
    assert(inhno < MAX_INT_NUM);
    int_table[inhno] = inthdr;

}

/*
 *  ����`�̊����݂��������ꍇ�̏���
 */
void
undef_interrupt(){
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
    while(1);
}


/*IRQ���W�X�^���N���A�����܂ő҂�*/
#define INT_CLEAR_DELAY  0x70
void poll_intreg(int int_mask)
{
    int i;
    
    //while(*IRQ0_ENABLESET & int_mask);
    for(i=0;i<INT_CLEAR_DELAY;i++);
    enaint();

}

/*�����������荞�݃r�b�g������*/

UINT find_bit(UINT bitmap)
{
    return (ffs(bitmap)-1);
}

