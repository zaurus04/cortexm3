/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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
 *  @(#) $Id: sh7615frt.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *	�^�C�}�h���C�o
 *  FRT���g�p
 */

#ifndef _SH7615FRT_H_
#define _SH7615FRT_H_

/*
 *   �^�C�}�ւ̓��̓N���b�N�̕�����ݒ�
 *   	f/8�ŃJ�E���g
 */
#define TCR_CKS         0x0

/*
 *   �^�C�}�ɋ��������N���b�N���g��[kHz]
 *   	14.7456MHz/8 =1.8432MHz =1843.2kHz
 */
#define TIMER_CLOCK	1843


/*
 *  �^�C�}�l�̓����\���̌^
 */
typedef UH CLOCK;

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
#define	MAX_CLOCK	((CLOCK) 0xffff)

/*
 *  �^�C�}�̌��ݒl�������ݔ����O�̒l�Ƃ݂Ȃ����̔��f
 */
#define	GET_TOLERANCE	100		/* �����x��̌��ς�l�i�P�ʂ͓����\���j */
#define	BEFORE_IREQ(clock) \
		((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �R���g���[�����W�X�^�̃A�h���X
 */

#define FRT_FTCSR	(VB *)0xfffffe11
#define FRT_TOCR	(VB *)0xfffffe17
#define FRT_TCR		(VB *)0xfffffe16
#define FRT_OCRH	(VB *)0xfffffe14
#define FRT_OCRL	(VB *)0xfffffe15
#define FRT_TIER	(VB *)0xfffffe10
#define FRT_FRCH	(VB *)0xfffffe12
#define FRT_FRCL	(VB *)0xfffffe13


#ifndef _MACRO_ONLY

/*
 *  �^�C�}�X�^�[�g
 */
Inline void
sh2_timer_start ()
{
	/* OCRA��v�ɂ�銄���������� */
	sil_wrb_mem (FRT_TIER, sil_reb_mem(FRT_TIER) | 0x08);
}

/*
 *  �^�C�}�ꎞ��~
 */
Inline void
sh2_timer_stop ()
{
	/* OCRA��v�ɂ�銄�������s���� */
	sil_wrb_mem (FRT_TIER, sil_reb_mem(FRT_TIER) & ~0x08);
}
/*
 *  �^�C�}�����ݗv���̃N���A
 *	TCR���W�X�^��IMFA�r�b�g��1��ǂݏo������ɂO����������
 */
Inline void
sh2_timer_int_clear ()
{
	/* ���荞�ݗv�����N���A     */
	/*  �iGRA�R���y�A�}�b�`�t���O�j */
	sil_wrb_mem (FRT_FTCSR, sil_reb_mem (FRT_FTCSR) & 0xf7);
	/* OCRA�R���y�A�}�b�`�t���O�̃N���A */

}


/*
 *  �^�C�}�̋N������
 *
 *  �^�C�}�����������C�����I�ȃ^�C�}�����ݗv���𔭐�������D
 */
Inline void
sh2_timer_initialize ()
{
	CLOCK cyc = TO_CLOCK (TIC_NUME, TIC_DENO);


	/*
	 *  �^�C�}�֘A�̐ݒ�
	 */
	sh2_timer_stop ();			/* �^�C�}��~ */
	/* �^�C�}����l�̃`�F�b�N */
	assert (cyc <= MAX_CLOCK);

	/* OCRA�I�� */
	sil_wrb_mem (FRT_TOCR, 0x00);
	/*  ������ݒ�  clock 1/8   */
	sil_wrb_mem (FRT_TCR, 0x00);
	/* OCRA��v�ɂ��FRC�̃N���A */
	sil_wrb_mem (FRT_FTCSR, sil_reb_mem (FRT_FTCSR) | 0x01);
	/* �R���y�A�}�b�`�t���O�̃N���A */
	sil_wrb_mem (FRT_FTCSR, sil_reb_mem (FRT_FTCSR) & 0xf7);
	/*  OCRA���W�X�^�ݒ�i�J�E���^�ڕW�l�j      */
	sil_wrb_mem (FRT_OCRH, (CLOCK_PER_TICK >> 8) & 0x00ff);
	sil_wrb_mem (FRT_OCRL, (CLOCK_PER_TICK) & 0x00ff);
	/* OCRA��v�ɂ�銄���������� */
	sil_wrb_mem (FRT_TIER, 0x09);
	/* �J�E���^���N���A             */
	sil_wrb_mem (FRT_FRCH, 0);
	sil_wrb_mem (FRT_FRCL, 0);
}

/*
 *  �^�C�}�̒�~����
 *
 *  �^�C�}�̓�����~������D
 */
Inline void
sh2_timer_terminate ()
{
	sh2_timer_stop ();			/* �^�C�}���~     */
	sh2_timer_int_clear ();		/* ���荞�ݗv�����N���A */

	sil_wrb_mem (FRT_TIER, 0x01);	//���荞�ݕs����
	sil_wrb_mem (FRT_FRCH, 0);
	sil_wrb_mem (FRT_FRCL, 0);
	sil_wrb_mem (FRT_OCRH, 0);
	sil_wrb_mem (FRT_OCRL, 0);
}

/*
 *  �^�C�}�̌��ݒl�̓Ǐo��
 *�@�@�@�^�C�}�l��ǂݏo���D
 */
Inline CLOCK
sh2_timer_get_current ()
{
	CLOCK	clk;
	CLOCK up, low;


	up = sil_reb_mem (FRT_FRCH);
	low = sil_reb_mem (FRT_FRCL);
	clk = (up << 8) | low;
	return (clk);
}

/*
 *  �^�C�}�����ݗv���̃`�F�b�N
 */
Inline BOOL
sh2_timer_fetch_interrupt ()
{
	return (sil_reb_mem (FRT_FTCSR) & 0x08);
}

#endif /* _MACRO_ONLY */
#endif /* _SH7615FRT_H_ */
