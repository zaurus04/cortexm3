/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 *  @(#) $Id: pit.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�^�C�}�h���C�o
 *�@�@�@�@�@MPC860T�����̎��������݃^�C�}PIT���g�p
 */

#ifndef _PIT_H_
#define _PIT_H_

#include <mpc860_sil.h>

/*
 *  SIU�̓��������݃��x���i�r�b�g�p�^�[���j
 */
#define SIU_INT_PIT	LEVEL_TO_BIT_PATTERN(INTLVL_PIT)


/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UH	CLOCK;

/*
 *	�^�C�}�ɋ��������N���b�N���g��[kHz]
 *   	TIMER_CLOCK=SYSTEM_CLOCK[MHz] / 4
 */
#define	TIMER_CLOCK		(SYSTEM_CLOCK * 1000 / 4)

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)
#define CLOCK_PER_TICK	((CLOCK) (TO_CLOCK(TIC_NUME, TIC_DENO) - 1))

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define	MAX_CLOCK	((CLOCK) 0xffffu)

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE	100	/* �����x��̌��ς�l�i�P�ʂ͓����\���j*/
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �R���g���[�����W�X�^�̒�`
 */

/*  ���������݃X�e�[�^�X����ѐ��䃌�W�X�^  */
#define PISCR       (VH *)(IMMR_BASE + 0x240)
#define PISCRK      (VW *)(IMMR_BASE + 0x340)  /*  �L�[���W�X�^  */
#define PISCR_PIRQ  0xff00      /*  ���������ݗv�����x���r�b�g  */  
#define PISCR_PS    BIT8_16     /*  ���������݃X�e�[�^�X  */    
#define PISCR_PIE   BIT13_16    /*  ���������݃C�l�[�u��  */
#define PISCR_PITF  BIT14_16    /*  PIT�t���[�Y�E�C�l�[�u��  */
#define PISCR_PTE   BIT15_16    /*  �����^�C�}�E�C�l�[�u��  */

/*  PIT�J�E���g���W�X�^�i���2�o�C�g�̂݁j  */
#define PITC        (VH *)(IMMR_BASE + 0x244)
#define PITCK       (VW *)(IMMR_BASE + 0x344)  /*  �L�[���W�X�^  */

/*  PIT���W�X�^�i���2�o�C�g�̂݁j  */
#define PITR        (VH *)(IMMR_BASE + 0x248)



#ifndef _MACRO_ONLY

/*
 *  �������W�X�^�ی�̃��b�N�ƃA�����b�N
 */

/*  PISCR���b�N  */
Inline void
lock_piscr()
{
    	/*  �l��UNLOCK_KEY�ȊO�ł���Ηǂ�  */
    mpc860_wrw_mem(PISCRK, 0);
}

/*  PISCR�A�����b�N  */
Inline void
unlock_piscr()
{
    mpc860_wrw_mem(PISCRK, UNLOCK_KEY);
}

/*  PITC���b�N  */
Inline void
lock_pitc()
{
    	/*  �l��UNLOCK_KEY�ȊO�ł���Ηǂ�  */
    mpc860_wrw_mem(PITCK, 0);
}

/*  PITC�A�����b�N  */
Inline void
unlock_pitc()
{
    mpc860_wrw_mem(PITCK, UNLOCK_KEY);
}

/*
 *  �^�C�}�X�^�[�g
 */
Inline void
pit_start()
{
    unlock_piscr();         	/*  PISCR�A�����b�N  */
    mpc860_orh_mem(PISCR, PISCR_PTE);
    lock_piscr();         	/*  PISCR���b�N  */
}

/*
 *  �^�C�}�ꎞ��~
 */
Inline void
pit_stop()
{
    unlock_piscr();         	/*  PISCR�A�����b�N  */
    mpc860_andh_mem(PISCR, ~PISCR_PTE);
    lock_piscr();         	/*  PISCR���b�N  */
}

/*
 *  �^�C�}�����ݗv���̃N���A
 *          PISCR���W�X�^��PS�r�b�g��1����������
 */
Inline void
pit_int_clear()
{
	/*
	 *  SIL���g�p�����Ƃ��̃��O�@�\���I�t��
	 */
#ifdef SIL_DEBUG
    BOOL sil_debug_tmp = sil_debug_on;
    sil_debug_on = FALSE;
#endif /* SIL_DEBUG */

    unlock_piscr();         	/*  PISCR�A�����b�N  */
    mpc860_orh_mem(PISCR, PISCR_PS);
    lock_piscr();         	/*  PISCR���b�N  */

	/*
	 *  SIL���g�p�����Ƃ��̃��O�@�\�𕜌�
	 */
#ifdef SIL_DEBUG
    sil_debug_on = sil_debug_tmp;
#endif /* SIL_DEBUG */

}


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
pit_initialize()
{
    VH piscr;
    VW sccr;
    
    /* �^�C�}����l=�ϐ��̍ő�l�Ȃ̂Ń`�F�b�N�͏ȗ� */

    pit_stop();		/* �^�C�}��~ */
    
    /*
     *  �^�C�}�֘A�̐ݒ�
     */
    
    /*  �N���b�N�\�[�X�I���A������ݒ�  */
    unlock_sccr();              /*  SCCR�A�����b�N  */
    sccr = mpc860_rew_mem(SCCR);
    sccr = (sccr & ~SCCR_RTDIV) /*  ���A���^�C���N���b�N����:4  */
            | SCCR_RTSEL;       /*  �N���b�N�\�[�X�FEXTCLK  */
    mpc860_wrw_mem(SCCR, sccr);
    lock_sccr();                /*  SCCR���b�N  */


    /*  �J�E���^�ڕW�l�ݒ�  */
    unlock_pitc();                  /*  PITC�A�����b�N  */
    mpc860_wrh_mem(PITC, CLOCK_PER_TICK);
    lock_pitc();                    /*  PITC���b�N  */
    
    
    unlock_piscr();                 /*  PISCR�A�����b�N  */
    piscr = mpc860_reh_mem(PISCR);
    piscr = (piscr & ~PISCR_PIRQ)
            | (SIU_INT_PIT << 8)	/*  �����݃��x���ݒ�  */
            | PISCR_PIE;                /*  PIT�����݋���  */
    mpc860_wrh_mem(PISCR, piscr);
    lock_piscr();                   /*  PISCR���b�N  */
}

/*
 *  �^�C�}�̒�~����
 *
 *  �@�^�C�}�̓�����~������D
 */
Inline void
pit_terminate()
{
    pit_stop();				/* �^�C�}���~ 	*/
    pit_int_clear();			/* ���荞�ݗv�����N���A */

    unlock_piscr();                 	/*  PISCR�A�����b�N  */
    mpc860_andh_mem(PISCR, ~PISCR_PIE);	/* �^�C�}�����݂��֎~   */
    lock_piscr();                   	/*  PISCR���b�N  */
    
    /*  �{���̓^�C�}�ւ̃N���b�N�������~����  */
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 *�@�@�@�����݋֎~��Ԓ��ŌĂяo������
 */
Inline CLOCK
pit_get_current()
{
    CLOCK pitr;
    
    pitr = mpc860_reh_mem(PITR);
    return(CLOCK_PER_TICK - pitr);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
pit_fetch_interrupt()
{
    VH piscr;
    
    /*  �ǂݏo���Ȃ̂ŁA�A�����b�N���Ȃ��ėǂ�  */
    piscr = mpc860_reh_mem(PISCR);
    return(piscr & PISCR_PS);
}

#endif /* _MACRO_ONLY */
#endif /* _PIT_H_ */
/*  end of file  */
