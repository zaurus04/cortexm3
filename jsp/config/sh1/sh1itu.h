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
 *  @(#) $Id: sh1itu.h,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */

/*
 *	�^�C�}�h���C�o
 *�@�@�@�@�@SH1�����̃C���e�O���[�e�b�h�E�^�C�}�E�p���X�E���j�b�gITU��
 *�@�@�@�@�@�`���l��0���g�p
 */

#ifndef _SH1ITU_H_
#define _SH1ITU_H_

/*
 *  �N���b�N���g���ˑ��̐ݒ�
 *  
 *  �@�@�N���b�N���g���̓R���p�C���I�v�V�����ŗ^������
 */

/*
 *   �^�C�}�ւ̓��̓N���b�N�̕�����ݒ�
 *   	f/8�ŃJ�E���g
 */
#define TCR_TPSC	0x3u

/*
 *   �^�C�}�ɋ��������N���b�N���g��[kHz]
 *   	20MHz/8 =2.5MHz =2500kHz
 */
#ifdef CONFIG_20MHZ
#define TIMER_CLOCK	2500
#endif

/*
 *   	19.6608MHz/8 =2.4576MHz =2457.6kHz
 */
#ifdef CONFIG_19MHZ
#define TIMER_CLOCK	2458
#endif

/*
 *   	16MHz/8 =2MHz =2000kHz
 */
#ifdef CONFIG_16MHZ
#define TIMER_CLOCK	2000
#endif



/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UH	CLOCK;

/*
 *  �^�C�}�l�̓����\���ƃ~���b�E�ʕb�P�ʂƂ̕ϊ�
 *
 */
#define	TO_CLOCK(nume, deno)	(TIMER_CLOCK * (nume) / (deno))
#define	TO_USEC(clock)		((clock) * 1000 / TIMER_CLOCK)
#define CLOCK_PER_TICK	((CLOCK) TO_CLOCK(TIC_NUME, TIC_DENO))

/*
 *  �ݒ�ł���ő�̃^�C�}�����i�P�ʂ͓����\���j
 */
#define	MAX_CLOCK	((CLOCK) 0xffffu)

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE	100	/* �����x��̌��ς�l�i�P�ʂ͓����\���j*/
#define	BEFORE_IREQ(clock)  \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)


/*
 *  �R���g���[�����W�X�^�̃A�h���X
 */

    	/*  ����  */
#define ITU_TSTR (VB *)0x5ffff00 /*  �^�C�}�X�^�[�g���W�X�^ �i1�o�C�g�j*/
#define ITU_TSNC (VB *)0x5ffff01 /*  �^�C�}�V���N�����W�X�^ �i1�o�C�g�j*/
#define ITU_TMDR (VB *)0x5ffff02 /*  �^�C�}���[�h���W�X�^ �i1�o�C�g�j  */
	/*  �^�C�}�t�@���N�V�����R���g���[�����W�X�^ �i1�o�C�g�j */
#define ITU_TFCR (VB *)0x5ffff03 
	/*  �^�C�}�A�E�g�v�b�g�R���g���[�����W�X�^ �i1�o�C�g�j   */
#define ITU_TOCR (VB *)0x5ffff31

	/*  ITU0  */
#define ITU_TCR0  (VB *)0x5ffff04 /*  �^�C�}�R���g���[�����W�X�^0 �i1�o�C�g�j*/
		/*  �^�C�}I/O�R���g���[�����W�X�^0 �i1�o�C�g�j*/
#define ITU_TIOR0 (VB *)0x5ffff05 
		/*  �^�C�}�C���^���v�g�C�l�[�u�����W�X�^0 �i1�o�C�g�j*/
#define ITU_TIER0 (VB *)0x5ffff06 
#define ITU_TSR0  (VB *)0x5ffff07 /*  �^�C�}�X�e�[�^�X���W�X�^0 �i1�o�C�g�j*/
#define ITU_TCNT0 (VH *)0x5ffff08 /*  �^�C�}�J�E���^0 �i2�o�C�g�j*/
#define ITU_GRA0  (VH *)0x5ffff0a /*  �W�F�l�������W�X�^A0 �i2�o�C�g�j*/
#define ITU_GRB0  (VH *)0x5ffff0b /*  �W�F�l�������W�X�^B0 �i2�o�C�g�j*/


/*
 *  �R���g���[�����W�X�^�̐ݒ�l
 */
#define TSR_IMFA	0x01u	/*  GRA�R���y�A�}�b�`�t���O  		*/
#define TSTR_STR0	0x01u	/*  �^�C�}�X�^�[�g�r�b�g  		*/
#define TCR_CCLR_GRA	0x20u	/*  GRA�R���y�A�}�b�`�ŃJ�E���^���N���A */
#define TIER_RESERVE	0x78u	/*  TIER���W�X�^�̗\��r�b�g  		*/
#define TIER_IMIEA	0x01u	/*  GRA�R���y�A�}�b�`�ɂ�銄���ݗv�������� */
#define TIOR_RESERVE	0x08u	/*  TIOR���W�X�^�̗\��r�b�g  		*/
#define TIOR_IOA	0x00u	/*  GRA�R���y�A�}�b�`�ɂ��[�q�o�͋֎~ */


#ifndef _MACRO_ONLY

/*
 *  �^�C�}�X�^�[�g
 */
Inline void
sh1_itu_start(void)
{
	sh1_orb_reg(ITU_TSTR, TSTR_STR0);
}

/*
 *  �^�C�}�ꎞ��~
 */
Inline void
sh1_itu_stop(void)
{
	sh1_anb_reg(ITU_TSTR, (VB)~TSTR_STR0);
}

/*
 *  �^�C�}�����ݗv���̃N���A
 *	TCR���W�X�^��IMFA�r�b�g��1��ǂݏo������ɂO����������
 */
Inline void
sh1_itu_int_clear(void)
{
	/* ���荞�ݗv�����N���A 	*/
	/*  �iGRA�R���y�A�}�b�`�t���O�j */
	sh1_anb_reg(ITU_TSR0, (VB)~TSR_IMFA);
}


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
sh1_itu_initialize(void)
{
	CLOCK	cyc = TO_CLOCK(TIC_NUME, TIC_DENO);


	/*
	 *  �^�C�}�֘A�̐ݒ�
	 */
	sh1_itu_stop();		/* �^�C�}��~ */
			     		/* �^�C�}����l�̃`�F�b�N */
	assert(cyc <= MAX_CLOCK);
			/*  GRA�R���y�A�}�b�`�ŃJ�E���^���N���A */
			/*  ������ݒ�  			*/
	sil_wrb_mem(ITU_TCR0, TCR_CCLR_GRA | TCR_TPSC);
			/*  GRA�R���y�A�}�b�`�ɂ�銄���ݗv�������� */
	sil_wrb_mem(ITU_TIER0, TIER_RESERVE | TIER_IMIEA);
			/*  GRA�R���y�A�}�b�`�ɂ��[�q�o�͋֎~ */
	sil_wrb_mem(ITU_TIOR0, TIOR_RESERVE | TIOR_IOA);
			/*  GRA���W�X�^�ݒ�i�J�E���^�ڕW�l�j  	*/
	sil_wrh_mem(ITU_GRA0, CLOCK_PER_TICK);
	sil_wrh_mem(ITU_TCNT0, 0);	/* �J�E���^���N���A 	*/

}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
sh1_itu_terminate(void)
{
	sh1_itu_stop();			/* �^�C�}���~ 	*/
	sh1_itu_int_clear();		/* ���荞�ݗv�����N���A */

					/* �^�C�}�����݂��֎~   */
			/*  �iOVIE,IMIEB,IMIEA�r�b�g���N���A�j  */
	sil_wrb_mem(ITU_TIER0, TIER_RESERVE);
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 *�@�@�@�^�C�}�̓�����ꎞ�I�ɒ�~���C�^�C�}�l��ǂݏo���D
 */
Inline CLOCK
sh1_itu_get_current(void)
{
	CLOCK	clk;
	

	sh1_itu_stop();			/*  �^�C�}��~  */
	
	/*  �{���͑҂����Ԃ�����ׂ�  */
	
	clk = sil_reh_mem(ITU_TCNT0);
	sh1_itu_start();			/*  �^�C�}�X�^�[�g  */
	
	return(clk);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
sh1_itu_fetch_interrupt(void)
{
	VB tsr0 = sil_reb_mem(ITU_TSR0);
	return(tsr0 & TSR_IMFA);
}

#endif /* _MACRO_ONLY */
#endif /* _SH1ITU_H_ */
