/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 *  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
 * 
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: hw_timer.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�^�C�}�h���C�o�iM3029�p�j
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>
#include <sil.h>
#include <m3029.h>


/*
 *  �^�C�}�[�̊��荞�݃��x��
 */
#define INT_LEVEL_TIMER	0x05

/*
 * �^�C�}�����݃n���h���̃x�N�^�ԍ�
 */
#ifdef USE_TA0
#define	INHNO_TIMER	       INT_TA0
#elif defined(USE_TA1)
#define	INHNO_TIMER	       INT_TA1
#endif


/*
 * �^�C�}���[�h���W�X�^
 */
#ifdef USE_TA0
#define TADR_SFR_TAMR TADR_SFR_TA0MR
#elif  defined(USE_TA1)
#define TADR_SFR_TAMR TADR_SFR_TA1MR
#endif

/*
 * �A�b�v�_�E���t���O
 */
#ifdef USE_TA0
#define TBIT_UDF_TAUD TBIT_UDF_TA0UD
#elif  defined(USE_TA1)
#define TBIT_UDF_TAUD TBIT_UDF_TA1UD  
#endif

/*
 * �^�C�}���W�X�^
 */
#ifdef USE_TA0
#define TADR_SFR_TA TADR_SFR_TA0
#elif  defined(USE_TA1)
#define TADR_SFR_TA TADR_SFR_TA1
#endif

/*
 * �J�E���g�J�n�r�b�g
 */
#ifdef USE_TA0
#define TBIT_TABSR_TS  TBIT_TABSR_TA0S
#elif  defined(USE_TA1)
#define TBIT_TABSR_TS  TBIT_TABSR_TA1S
#endif

/*
 * �����ݐ��䃌�W�X�^�̃I�t�Z�b�g
 */
#ifdef USE_TA0
#define TADR_SFR_TAIC_OFFSET  TADR_SFR_TA0IC_OFFSET
#elif  defined(USE_TA1)
#define TADR_SFR_TAIC_OFFSET  TADR_SFR_TA1IC_OFFSET
#endif


#ifndef _MACRO_ONLY


/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UH	CLOCK;


/*
 *  �^�C�}�l�̓����\���ƃ~���b�P�ʂƂ̕ϊ�
 *
 *  1ms�̃^�C�}�[���荞�݂��g�p����̂ł��̃N���b�N���`����D
 */
#define TIMER_CLOCK		20000
#define TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((unsigned long)(clock) * 1000 / TIMER_CLOCK)


/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define	MAX_CLOCK	((CLOCK) 0xffff)


/*
 *  ���\�]���p�V�X�e�����������o���ۂ̏������Ԃ̌��ς�l�i�P�ʂ͓����\���j
 */
#define	GET_TOLERANCE	100	/* �����x��̌��ς�l�i�P�ʂ͓����\���j*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
hw_timer_initialize()
{
    /*
     * �^�C�}������
     */
    /* �^�C�}�J�E���g��~ */
	sil_wrb_mem((VP)TADR_SFR_TABSR,
                sil_reb_mem((VP)TADR_SFR_TABSR) & ~TBIT_TABSR_TS);
    /* �_�E���J�E���g�ݒ� */
	sil_wrb_mem((VP)TADR_SFR_UDF,
                sil_reb_mem((VP)TADR_SFR_UDF)   & ~TBIT_UDF_TAUD);
    /*  �J�E���g�\�[�Xf1, �^�C�}���[�h  */
	sil_wrb_mem((VP)TADR_SFR_TAMR, 0x00);		
    
	/*
     *  �^�C�}�l�̏�����
	 *  �^�C�}�� 1ms�� TIMER_CLOCK �J�E���g,
	 *  ���W�X�^�ݒ�l�̓}�C�i�X1����.
	 */
	sil_wrh_mem((VP)TADR_SFR_TA, (TIMER_CLOCK - 1));
    
    /* ���荞�݃��x���̐ݒ� */
    set_ic_ilvl((VP)(TADR_SFR_INT_BASE + TADR_SFR_TAIC_OFFSET), INT_LEVEL_TIMER);
    
    /* �J�E���g�J�n	*/
	sil_wrb_mem((VP)TADR_SFR_TABSR,
                sil_reb_mem((VP)TADR_SFR_TABSR) | TBIT_TABSR_TS);
}


/*
 *  �^�C�}�����ݗv���̃N���A
 */
Inline void
hw_timer_int_clear()
{
	/*
	 *  ���̊֐��̓^�C�}���荞�݃n���h����
	 *  isig_tim ���Ăяo���O�Ɏ��s�����.
	 *  �����݂��󂯕t�����Ă���
	 *  �����݃n���h���ɏ������ڂ������_��
	 *  �����ݗv���r�b�g�̓N���A����邽��
	 *  ��������K�v���Ȃ�. 
	 */
}


/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
hw_timer_terminate()
{
    /* �J�E���g��~	*/
	sil_wrb_mem((VP)TADR_SFR_TABSR,
                sil_reb_mem((VP)TADR_SFR_TABSR) & ~TBIT_TABSR_TS);    
}


/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 */
Inline CLOCK
hw_timer_get_current(void)
{
	return ((TIMER_CLOCK-1) - sil_reh_mem((VP)TADR_SFR_TA));
}


/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
hw_timer_fetch_interrupt(void)
{
	return (sil_reb_mem((VP)(TADR_SFR_INT_BASE + TADR_SFR_TAIC_OFFSET)) & TBIT_IC_IR) != 0;
}

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
