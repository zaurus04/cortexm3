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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *  �v���Z�b�T�ˑ����W���[���iNios2�p�j
 */
#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <nios2.h>

/*
 * ���荞�݃n���h��/�r�b�g�}�X�N�e�[�u��
 */
FP  int_handler_table[MAX_INT_NUM];
UW  int_bit_table[MAX_INT_NUM];

/*
 * CPU��O�n���h���e�[�u��
 */
FP	exc_handler_table[MAX_EXC_NUM]; 

/*
 * ���荞�݂̃l�X�g�񐔂̃J�E���g
 * �J�[�l���N�����̓^�X�N�Ɨ����Ƃ݂Ȃ�����1�ŏ���������
 */
UW interrupt_count = 1;

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize()
{
    int i;
    
    /*
     * int_handler_table[],int_plevel_table[]�̏�����
     * ���o�^�̊����ݔ�������cpu_interrup()���Ăяo�����悤��
     * no_reg_interrup()��o�^����
     */
    for(i = 0; i < MAX_INT_NUM; i++){
        int_handler_table[i] = no_reg_interrupt;
        int_bit_table[i]  = 1 << i; /* �r�b�g�p�^�[���̐��� */
    }

    /*
     *  CPU��O�n���h���e�[�u��
     */
    for(i = 0; i < MAX_EXC_NUM; i++){
        exc_handler_table[i] = no_reg_exception; 
    }
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 *  �����݋֎~
 */
void
cpu_terminate()
{
    disint();
}


/*
 * �����݂̋���/�֎~
 */
SYSCALL ER
ena_int(INTNO intno){
    set_ienable((1 << intno) | current_ienable()); 
}

SYSCALL ER
dis_int(INTNO intno){
    set_ienable(~(1 << intno) & current_ienable());    
}


/*
 * ���o�^�̊����݂����������ꍇ�ɌĂяo�����
 */
void
no_reg_interrupt(void)
{
    syslog(LOG_EMERG, "Unregisted Interrupt Occur!");
    while(1);
}

/*
 * ���o�^�̗�O�����������ꍇ�ɌĂяo�����
 */
void
no_reg_exception(void)
{
    syslog(LOG_EMERG, "Unregisted Exception Occur!");
    while(1);    
}

/*
 * �����ݗv���̔���Ɗ����݃n���h���̌Ăяo��
 */
void
int_handler_call(){
    UW status;
    UW mask;
    int i;
    
    interrupt_count++;
    status = current_ipending();
    for(i = 0; i < 32; i++){
        if((status & (1 << i)) != 0x00){
            mask = current_ienable();
            set_ienable(~int_bit_table[i] & mask);
            
            enaint();
            (int_handler_table[i])();
            disint();
            
            set_ienable(mask);
            break;
        }
    }
    interrupt_count--;    
}

/*
 *  ��O�̔����CPU��O�n���h���̌Ăяo��
 *  ���݂͖��������ߗ�O�݂̂��T�|�[�g 
 */
void
exc_handler_call(VP p_excinf){
    interrupt_count++;

    enaint();
    (exc_handler_table[0])(p_excinf);
    disint();
    
    interrupt_count--;    
}
