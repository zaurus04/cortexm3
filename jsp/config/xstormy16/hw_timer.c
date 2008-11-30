/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2005 by Embedded and Real-Time Systems Laboratory
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
 */

/*
 *  �^�C�}�h���C�o�iXstormy16�p�j
 */

#include <kernel.h>
#include <s_services.h>
#include <hw_timer.h>
#include <cpu_sfrs.h>

/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
void hw_timer_initialize(void)
{
                                /*
                                 *  �^�C���e�B�b�N�����̐ݒ�
                                 */
    _kernel_tic_nume = 5u ;
                                /*
                                 *  ����RC���M��p��5ms�̊��荞�݂𔭐�
                                 */
    __SFR_BITCLR( __OCR0, 4 ) ;         /* start internal-RC                 */
    __SFRW(__T0LR) = 5000-1 ;           /* Internl-RC is almost 1MHz,        */
                                        /*  so set 5000-1 for 5ms            */
    __SFR(__T0PR) = 0 ;                 /* Prescaler = 1/1                   */
    __SFR(__T0CNT) = 0x0d ;             /* Select internal-RC,               */
                                        /*  start timer and enable interrupt */
                                /*
                                 *  �f�t�H���g�̃^�C�}�[���荞�݃n���h����o�^����
                                 */
    _kernel_define_inh( INHNO_TIMER, hw_timer_handler ) ;
                                /*
                                 *  �^�C�}�[���荞�݂�Level1�ɐݒ�
                                 */
    __SFR_BITCLR( __IL1L, 5 ) ;
    __SFR_BITSET( __IL1L, 4 ) ;
}

/*
 *  �^�C�}�����ݗv���̃N���A
 */
void hw_timer_int_clear(void)
{
    __SFR_BITCLR( __T0CNT, 1 ) ;
}

/*
 *  �^�C�}�̒�~����
 */
void hw_timer_terminate(void)
{
                                /*
                                 *  �^�C�}�̓�����~������D
                                 */
    __SFR(__T0CNT) = 0x00 ;
                                /*
                                 *  �^�C�}�[���荞�݂��֎~
                                 */
    __SFR_BITCLR( __IL1L, 5 ) ;
    __SFR_BITCLR( __IL1L, 4 ) ;
}

/*
 *  �f�t�H���g�̃^�C�}�����݃n���h��
 */
void hw_timer_handler( void )
{
                                /*
                                 *  �^�C�}�����ݗv���̃N���A
                                 */
    hw_timer_int_clear() ;
                                /*
                                 *  �^�C���e�B�b�N�̋���
                                 */
    isig_tim();
}

