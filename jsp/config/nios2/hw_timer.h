/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: hw_timer.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

/*
 * CPU�ˑ��^�C�}���W���[���iNios2�p�j
 */ 
#include <s_services.h>
#include <nios2.h>

/*
 * �^�C�}�����݃n���h���̊����ݔԍ�
 */
#define INHNO_TIMER TIM_INTLVL

#ifndef _MACRO_ONLY

/*
 * �^�C�}�l�̓����\���̌^
 */
typedef UW CLOCK;

/*                                                                             
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�                               
 *  TIMER_CLOCK �̓^�[�Q�b�g�{�[�h���ɐݒ�                                     
 */
#define TO_CLOCK(nume, deno)  (TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)      ((clock) * 1000 / TIMER_CLOCK)

/*
 *  �ݒ�ł���ő�^�C�}�����i�P�ʂ͓����\���j
 */
#define MAX_CLOCK ((CLOCK) 0xffffffff)

/*
 *  ���\�]���p�V�X�e�����������o���ۂ̏������Ԃ̌��ς�l�i�P�ʂ͓����\���j
 */
#define GET_TOLERANCE	100
#define BEFORE_IREQ(clock) \
        ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


/*
 * �^�C�}�̋N������
 *
 * �^�C�}�����������C�����I�ȃ^�C�}�����݂𔭐�������
 */ 
Inline void
hw_timer_initialize(void)
{
  
    CLOCK cyc = TO_CLOCK(TIC_NUME, TIC_DENO);

    /* �^�C�}�[�X�g�b�v */
    sil_wrw_mem((VP)TIM_CONTROL,TIM_CONTROL_STOP);
    /* �^�C���A�E�g�X�e�[�^�X�N���A */
    sil_wrw_mem((VP)TIM_STATUS, 0x00);
    
      
    assert(cyc <= MAX_CLOCK);                          /* �^�C�}����l�̃`�F�b�N */
    sil_wrw_mem((VP)TIM_PERIODL, (cyc & 0xffff)); /* �J�E���^�[�Z�b�g ����16bit */
    sil_wrw_mem((VP)TIM_PERIODH, (cyc >> 16));    /* �J�E���^�[�Z�b�g ���16bit */
  
    /*
     * �^�C�}�[�X�^�[�g�C�I�[�g�����[�h�C�����݋���
     */
    sil_wrw_mem((VP)TIM_CONTROL, TIM_CONTROL_START
                                 |TIM_CONTROL_COUNT|TIM_CONTROL_ITO);

    /*
     * �����݃R���g���[���̋���
     */
    ena_int(TIM_INTLVL);
}


/*
 *   �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear()
{
    /* TO�r�b�g�̃N���A */
    sil_wrw_mem((VP)TIM_STATUS,0x00);
}


/*
 *   �^�C�}�̋֎~����
 */
Inline void
hw_timer_terminate()
{
    /* �^�C�}��~ */
    sil_wrw_mem((VP)TIM_CONTROL, TIM_CONTROL_STOP);

    /* �����ݗv���̃N���A */
    sil_wrw_mem((VP)TIM_STATUS, 0x00);
}


/*
 *   �^�C�}�̌��ݒl�̓ǂݏo��
 *
 *   �����݋֎~��Ԓ��ŌĂяo������
 */
Inline CLOCK
hw_timer_get_current(void)
{
    CLOCK count;

    /* �X�i�b�v���W�X�^�ɏ������ނƒl���z�[���h���� */
    sil_wrw_mem((VP)TIM_SNAPL, 0x00);

    /* �J�E���g�l��ǂݍ��� */
    count = sil_rew_mem((VP)TIM_SNAPL);
    count |= sil_rew_mem((VP)TIM_SNAPH) << 16; 
    
    return(TIMER_CLOCK - count);
}


/*
 *   �����݂��������Ă��邩�̔���
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
    return(sil_rew_mem((VP)TIM_STATUS) & TIM_STATUS_TO);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
