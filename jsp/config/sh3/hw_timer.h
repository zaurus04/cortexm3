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
 *  @(#) $Id: hw_timer.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  CPU�ˑ��^�C�}���W���[���iSH3/4�p�j
 *  TMU0���g�p
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>

/*
 *  �^�C�}�����݃n���h����INTEVT�ԍ�
 */
#define	INHNO_TIMER	TMU0_INTEVT

#ifndef _MACRO_ONLY

/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UW	CLOCK;

#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)      ((clock) * 1000 / TIMER_CLOCK)

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define MAX_CLOCK	((CLOCK) 0xffffffff)

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define GET_TOLERANCE	100
#define BEFORE_IREQ(clock) \
        ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize()
{
	CLOCK	cyc = TO_CLOCK(TIC_NUME, TIC_DENO);
        
	/*
	 *  �^�C�}�֘A�̐ݒ�
	 */
    sil_wrb_mem((VP)TMU_TSTR,
                (sil_reb_mem((VP)TMU_TSTR) & ~TMU_STR0));  /* �^�C�}��~ */
    assert(cyc <= MAX_CLOCK);		     /* �^�C�}����l�̃`�F�b�N */

    /* ������ݒ�A���荞�݋��� */
    sil_wrh_mem((VP)TMU_TCR0,(0x020 | TCR0_TPSC));
    
    sil_wrw_mem((VP)TMU_TCOR0, cyc); /* timer constant���W�X�^���Z�b�g */
    sil_wrw_mem((VP)TMU_TCNT0, cyc); /* �J�E���^�[���Z�b�g */
    /* �^�C�}0�X�^�[�g */
    sil_wrb_mem((VP)TMU_TSTR,
                (sil_reb_mem((VP)TMU_TSTR) | TMU_STR0));

    
    /*
	 *  �����݊֘A�̐ݒ�
	 */
    define_int_plevel(TMU0_INTEVT,KTIM_INT_LV); /* ���荞�݃��x���ݒ�(SF) */
    /* ���荞�݃��x���ݒ�(HW) */
    sil_wrh_mem((VP)IPRA,
                ((sil_reh_mem((VP)IPRA) & 0x0fff) | (KTIM_INT_LV<<12)));
    /* ���荞�ݗv�����N���A */
    sil_wrh_mem((VP)TMU_TCR0,
                (sil_reh_mem((VP)TMU_TCR0) & ~TCR_UNF));
}


/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear()
{
    /* ���荞�ݗv�����N���A */
    sil_wrh_mem((VP)TMU_TCR0,
                (sil_reh_mem((VP)TMU_TCR0) & ~TCR_UNF));    
}

/*
 *  �^�C�}�̒�~����
 */
Inline void
hw_timer_terminate()
{
    /* �^�C�}���~ */
    sil_wrb_mem((VP)TMU_TSTR,
                (sil_reb_mem((VP)TMU_TSTR) & ~TMU_STR0));
    /* ���荞�ݗv�����N���A */
    sil_wrh_mem((VP)TMU_TCR0,0);
}

/*
 *  �^�C�}�̌��ݒl�̓ǂ݂���
 *
 *  �����݋֎~��Ԓ��ŌĂяo�����ƁD
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return(TO_CLOCK(TIC_NUME, TIC_DENO) - sil_rew_mem((VP)TMU_TCNT0));
}

Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return(sil_reh_mem((VP)TMU_TCR0) & TCR_UNF);
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */



