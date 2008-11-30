/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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

#include <s_services.h>
#include <h8_sil.h>

#ifndef _MACRO_ONLY

/*
 *  CPU�ˑ��^�C�}���W���[���iH8�p�j
 */

/*
 *  �^�C�}�l�̓����\���̌^
 */

typedef UH	CLOCK;

/*
 *  �^�C�}�����̒P�ʂ�����\���ɕϊ�
 *  	jsp/kernel/time_manage.c�ł��g�p
 */

#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)

/*
 *  �^�C�}�����̒P�ʂ�����\���ɕϊ�
 */

#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */

#define MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  ���\�]���p�V�X�e�����������o���ۂ̏������Ԃ̌��ς�l
 *	�i�P�ʂ͓����\���j
 *	���Ӂi�{���͕����N���b�N�Ɉˑ��j
 */

#define GET_TOLERANCE	100
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �v���C�I���e�B���x���ݒ�p�̃f�[�^
 *      �{���͊����݃R���g���[���ˑ������𕪗����ׂ�
 *
 *      �{����hw_timer.h�Ɏ��̂��L�q����ׂ������A���������
 *      hw_timer.h���C���N���[�h�����t�@�C���ł��ׂĎ��̉������
 *�@�@�@�������̈���L���Ă��܂����߁A���̂�cpu_config.c�ɋL�q����B
 */
extern const IRC TIMER_IRC;

/*
 *  �^�C�}�����ݗv���̃N���A
 *	TCR���W�X�^��IMFA�r�b�g��1��ǂݏo������ɂO����������
 */

Inline void
hw_timer_int_clear(void)
{
    /* GRA�R���y�A�}�b�`�̊��荞�ݗv���t���O���N���A */
    bitclr((UB *)SYSTEM_TIMER_IFR, SYSTEM_TIMER_IF_BIT);
}

/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */

Inline void
hw_timer_initialize(void)
{
    /* �^�C�}��~ */
    bitclr((UB *)SYSTEM_TIMER_TSTR, SYSTEM_TIMER_STR_BIT);

    /*  GRA�R���y�A�}�b�`�ŃJ�E���^���N���A�A������ݒ� */
    sil_wrb_mem((VP)SYSTEM_TIMER_TCR, SYSTEM_TIMER_TCR_BIT);

    /*  GRA�R���y�A�}�b�`�ɂ�銄���ݗv�������� */
    sil_wrb_mem((VP)SYSTEM_TIMER_IER, SYSTEM_TIMER_IE);

    /*  GRA�R���y�A�}�b�`�ɂ��[�q�o�͋֎~ */
    sil_wrb_mem((VP)SYSTEM_TIMER_TIOR, SYSTEM_TIMER_TIOR_BIT);

    /*  GRA���W�X�^�ݒ�i�J�E���^�ڕW�l�j  	*/
    sil_wrh_mem((VP)SYSTEM_TIMER_GR, CLOCK_PER_TICK);

    sil_wrh_mem((VP)SYSTEM_TIMER_CNT, 0);	/* �J�E���^���N���A	*/

    hw_timer_int_clear();			/*  �����ݗv�����N���A	*/

    /*
     *  �v���C�I���e�B�E���x���̐ݒ�
     *  �{���͊����݃R���g���[���ˑ������𕪗����ׂ�
     */
    define_int_plevel(&TIMER_IRC);

    /* �^�C�}�X�^�[�g */
    bitset((UB *)SYSTEM_TIMER_TSTR, SYSTEM_TIMER_STR_BIT);
}

/*
 *  �^�C�}�̒�~����
 */

Inline void
hw_timer_terminate(void)
{
    					/* �^�C�}��~ */
    bitclr((UB *)SYSTEM_TIMER_TSTR, SYSTEM_TIMER_STR_BIT);
    hw_timer_int_clear();		/* ���荞�ݗv�����N���A */
}

/*
 *  �^�C�}�̌��ݒl�̓ǂݏo��
 *
 *  �����݋֎~��Ԓ��ŌĂяo�����ƁD
 */

Inline CLOCK
hw_timer_get_current(void)
{
	return((CLOCK)(sil_reh_mem((VP)SYSTEM_TIMER_CNT)));
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */

Inline BOOL
hw_timer_fetch_interrupt(void)
{
	UB ifr = sil_reb_mem((VP)SYSTEM_TIMER_IFR);
	return(ifr & SYSTEM_TIMER_IF);
}

#endif	/* of #ifndef _MACRO_ONLY */

#endif /* _HW_TIMER_H_ */
