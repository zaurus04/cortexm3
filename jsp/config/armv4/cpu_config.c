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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iARM4vT�p�j
 */

#include "jsp_kernel.h"
#include "check.h"
#include <armv4.h>
#include "task.h"

/*
 * ��O�x�N�^�ɏ������܂ꂽ�W�����v���߂��Q�Ƃ���A�h���X
 * 
 */
UW *arm_vector_add[8];


/*
 * ��O�ɉ������n���h���̋N���Ԓn
 */
UW arm_handler_add[8];


/*
 * ���荞�݂̃l�X�g�񐔂̃J�E���g
 */
UW interrupt_count;


/*
 * CPU/�����݃n���h���̏o���������ňꎞ�I�Ɏg�p����X�^�b�N
 */
UW int_stack[INT_STACK_SIZE];


/*
 *  CPU��O�n���h���̐ݒ�
 */
void
define_exc(EXCNO excno, FP exchdr)
{
    arm_install_handler(excno,exchdr);
}


/*
 *  ����`�̗�O���������ꍇ�̏���
 */
void
undef_exception(){
  syslog(LOG_EMERG, "Unregistered Exception occurs. UNDEF");
    while(1);
}

void
swi_exception(){
  syslog(LOG_EMERG, "Unregistered Exception occurs. SWI");
  while(1);
}

void
prefetch_exception(){
  syslog(LOG_EMERG, "Unregistered Exception occurs. PREFETCH");
  while(1);
}

void
data_abort_exception(){
  syslog(LOG_EMERG, "Unregistered Exception occurs. DATA ABORT");
  while(1);
}


void
irq_exception(){
  syslog(LOG_EMERG, "Unregistered Exception occurs. IRQ");
  while(1);
}

void
fiq_exception(){
  syslog(LOG_EMERG, "Unregistered Exception occurs. FIQ");
  while(1);
}



/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize()
{

    UW i,vector_value;

	interrupt_count = 1;
	
    /*
     * ��O�x�N�^�ɓo�^����Ă��閽�߂���Q�Ƃ����A�h���X�ƁC
     *���̃A�h���X�̓��e(�n���h���̎��s��)��ۑ�����D
     */
    for(i = 0; i <=7; i++){
        vector_value = *(volatile UW *)(i*4);
        vector_value &= 0x00000fff;
        arm_vector_add[i] =  (UW *)(vector_value + 8) + i;
        arm_handler_add[i] = *(arm_vector_add[i]);
    }
}


/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{
    UW i;
    /*  �x�N�^�e�[�u�������ɖ߂��D*/
    for(i = 0; i <=7; i++)
        *arm_vector_add[i] = arm_handler_add[i];
}
