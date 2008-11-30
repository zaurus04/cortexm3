/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 */

#ifndef _VR4131_H_
#define _VR4131_H_

/*
 *  VR4131 �n�[�h�E�F�A��`
 */

/* CP0�n�U�[�h�̂��߂̎��ԉ҂� NOP_FOR_CP0_HAZARD  */
/* VR4131�ł�mtc0���߂̒��ォ�犄���݋֎~�ɂȂ��Ă���̂�nop���߂�}�����Ȃ��Ă�
   ���v */
#define NOP_FOR_CP0_HAZARD

/* Config���W�X�^  */
#define BP		BIT16	/* ����\���̐ݒ� */

/* TLB �̃G���g���̍ő�l  */
#define TMAX_TLB	31

/* TLB�}�X�N�l */
#define TLB_VPN2	0x800

/* �L���b�V������ */
#define Index_Invalidate_I	(0x0+0x0)
#define Index_Store_Tag_I       (0x8+0x0)
#define Index_Store_Tag_D       (0x8+0x1)

/* �L���b�V���̃��C���T�C�Y(�o�C�g�P��)  */
#define D_CACHE_LINE_SIZE 	0x10	/* 16�o�C�g */
#define I_CACHE_LINE_SIZE 	0x10	/* 16�o�C�g */

/*============================================================================*/

#ifndef _MACRO_ONLY

Inline void
vr4131_exit() {
	while(1);
	/* GDB_STUB �g�p���ɂ́ASTUB�̓��ɔ�ԏ������K�v�����B */
}

#endif /* _MACRO_ONLY */

/*============================================================================*/
/* �ȉ��̒�`�́A�e���j�b�g���ƂɁAvr4131_xxx.h�Ƃ��Ă܂Ƃ߂邱�Ƃ��K�v�����B */

/*
 * �N���b�N�}�X�N���j�b�g(CMU)�֌W�̒�`
 */
#define CMUCLKMSK	0x0f000060

#define MSKSIU		BIT1	/* SIU, DSIU�ւ�TClock�����̐��� */
#define MSKSSIU		BIT8	/* SIU�ւ�18.432MHz�N���b�N�����̐��� */
#define MSKDSIU		BIT11	/* DSIU�ւ�18.432MHz�N���b�N�����̐��� */

/*
 * �p���[�}�l�[�W�����g���j�b�g(PMU)�֌W�̒�`
 */
#define PMUINTREG	0x0f0000c0	/* PMU �����݁^�X�e�[�^�X���W�X�^ */
#define PMUCNTREG	0x0f0000c2	/* PMU �R���g���[�����W�X�^ */
#define PMUTCLKDIVREG	0x0f0000cc

/* for PMUINTREG */
#define TIMOUTRST	BIT5		/* HALTimer���Z�b�g���o */

/* for PMUCNTREG */
#define HALTIMERRST	BIT2		/* HALTimer���Z�b�g*/

/* for PMUTCLKDIVREG */
#define VTDIV_3		(BIT1 | BIT0)

/*
 * �o�X�R���g���[�����j�b�g(BCU)�֌W�̒�`
 */
#define BCUCNTREG1	0x0f000000
#define ROMSIZEREG	0x0f000004
#define ROMSPEEDREG	0x0f000006
#define IO0SPEEDREG	0x0f000008
#define IO1SPEEDREG	0x0f00000a
#define BCUCNTREG3	0x0f000016

/* for ROMSIZEREG */
#define SIZE3_4			BIT12
#define SIZE2_4			BIT8
#define SIZE1_4			BIT4
#define SIZE0_4			BIT0

/* for ROMSPEEDREG */
#define ROM4_WAIT_5VTClock	(BIT13 | BIT12)
#define ROM2_WAIT_8VTClock	(BIT2 | BIT0)

/* for IO0SPEEDREG */
#define IO0_1_WAIT_4		(BIT1 | BIT0)

/* for IO1SPEEDREG */
#define IO1_3_WAIT_11		BIT11

/* for BCUCNTREG3 */
#define EXT_ROMCS_3ROM_2ROM	(BIT13 | BIT12)
#define IO32			BIT7
#define LCDSEL1_BUFFER		BIT1
#define LCDSEL0_BUFFER		BIT0

/*
 * SDRAM�R���g���[�����j�b�g(SDRAMU)�֌W�̒�`
 */
#define SDRAMMODEREG	0x0f000400
#define SDRAMCNTREG	0x0f000402
#define BCURFCNTREG	0x0f000404
#define BCURFCOUNTREG	0x0f000406
#define RAMSIZEREG	0x0f000408

/* for SDRAMMODEREG */
#define SCLK		BIT15
#define LTMODE_2	BIT5

/* for SDRAMCNTREG */
#define TRC_3VTClock	(BIT9 | BIT8)
#define TDAL_2VTClock	BIT5
#define TRCD_2VTClock	BIT1

/* for RAMSIZEREG */
#define SIZE3_64	(BIT14 | BIT12)
#define SIZE2_64	(BIT10 | BIT8)
#define SIZE1_64	(BIT6 | BIT4)
#define SIZE0_64	(BIT2 | BIT0)

/*
 * �V���A���C���^�t�F�[�X���j�b�g(SIU)�֌W�̒�`
 */
#define SIURESET	0x0f000809

/* for SIURESET */
#define DSIURESET	BIT1	/*  DSIU�����Z�b�g����t���O  */

#endif /* _VR4131_H_ */
