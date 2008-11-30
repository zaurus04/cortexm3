/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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

#ifndef _H8S_TPU_H_
#define _H8S_TPU_H_

#include <s_services.h>		/* �f�o�C�X�h���C�o�p�W���C���N���[�h�t�@�C�� */

/*
 *  H8S����16�r�b�g�^�C�}�p���X���j�b�g(TPU)�֘A�̒�`
 */

/* TPU�����W�X�^�̃A�h���X */

/* �`���l���O */
#define TCR0		0xffd0		/* �^�C�}�R���g���[�����W�X�^�O */
#define TMDR0		0xffd1		/* �^�C�}���[�h���W�X�^�O */
#define TIOR0H		0xffd2		/* �^�C�}I/O�R���g���[�����W�X�^�O�g */
#define TIOR0L		0xffd3		/* �^�C�}I/O�R���g���[�����W�X�^�O�k */
#define TIER0		0xffd4		/* �^�C�}�C���^���v�g�C�l�[�u�����W�X�^�O */
#define TSR0		0xffd5		/* �^�C�}�X�e�[�^�X���W�X�^�O */
#define TCNT0		0xffd6		/* �^�C�}�J�E���^�O */
#define TGR0A		0xffd8		/* �^�C�}�W�F�l�������W�X�^�O�` */
#define TGR0B		0xffda		/* �^�C�}�W�F�l�������W�X�^�O�a */
#define TGR0C		0xffdc		/* �^�C�}�W�F�l�������W�X�^�O�b */
#define TGR0D		0xffde		/* �^�C�}�W�F�l�������W�X�^�O�c */

/* �`���l���P */
#define TCR1		0xffe0		/* �^�C�}�R���g���[�����W�X�^�P */
#define TMDR1		0xffe1		/* �^�C�}���[�h���W�X�^�P */
#define TIOR1		0xffe2		/* �^�C�}I/O�R���g���[�����W�X�^�P */
#define TIER1		0xffe4		/* �^�C�}�C���^���v�g�C�l�[�u�����W�X�^�P */
#define TSR1		0xffe5		/* �^�C�}�X�e�[�^�X���W�X�^�P */
#define TCNT1		0xffe6		/* �^�C�}�J�E���^�P */
#define TGR1A		0xffe8		/* �^�C�}�W�F�l�������W�X�^�P�` */
#define TGR1B		0xffea		/* �^�C�}�W�F�l�������W�X�^�P�a */

/* �`���l���Q */
#define TCR2		0xfff0		/* �^�C�}�R���g���[�����W�X�^�Q */
#define TMDR2		0xfff1		/* �^�C�}���[�h���W�X�^�Q */
#define TIOR2		0xfff2		/* �^�C�}I/O�R���g���[�����W�X�^�Q */
#define TIER2		0xfff4		/* �^�C�}�C���^���v�g�C�l�[�u�����W�X�^�Q */
#define TSR2		0xfff5		/* �^�C�}�X�e�[�^�X���W�X�^�Q */
#define TCNT2		0xfff6		/* �^�C�}�J�E���^�Q */
#define TGR2A		0xfff8		/* �^�C�}�W�F�l�������W�X�^�Q�` */
#define TGR2B		0xfffa		/* �^�C�}�W�F�l�������W�X�^�Q�a */

/* �`���l���R */
#define TCR3		0xfe80		/* �^�C�}�R���g���[�����W�X�^�R */
#define TMDR3		0xfe81		/* �^�C�}���[�h���W�X�^�R */
#define TIOR3H		0xfe82		/* �^�C�}I/O�R���g���[�����W�X�^�R�g */
#define TIOR3L		0xfe83		/* �^�C�}I/O�R���g���[�����W�X�^�R�k */
#define TIER3		0xfe84		/* �^�C�}�C���^���v�g�C�l�[�u�����W�X�^�R */
#define TSR3		0xfe85		/* �^�C�}�X�e�[�^�X���W�X�^�R */
#define TCNT3		0xfe86		/* �^�C�}�J�E���^�R */
#define TGR3A		0xfe88		/* �^�C�}�W�F�l�������W�X�^�R�` */
#define TGR3B		0xfe8a		/* �^�C�}�W�F�l�������W�X�^�R�a */
#define TGR3C		0xfe8c		/* �^�C�}�W�F�l�������W�X�^�R�b */
#define TGR3D		0xfe8e		/* �^�C�}�W�F�l�������W�X�^�R�c */

/* �`���l���S */
#define TCR4		0xfe90		/* �^�C�}�R���g���[�����W�X�^�S */
#define TMDR4		0xfe91		/* �^�C�}���[�h���W�X�^�S */
#define TIOR4		0xfe92		/* �^�C�}I/O�R���g���[�����W�X�^�S */
#define TIER4		0xfe94		/* �^�C�}�C���^���v�g�C�l�[�u�����W�X�^�S */
#define TSR4		0xfe95		/* �^�C�}�X�e�[�^�X���W�X�^�S */
#define TCNT4		0xfe96		/* �^�C�}�J�E���^�S */
#define TGR4A		0xfe98		/* �^�C�}�W�F�l�������W�X�^�S�` */
#define TGR4B		0xfe9a		/* �^�C�}�W�F�l�������W�X�^�S�a */

/* �`���l���T */
#define TCR5		0xfea0		/* �^�C�}�R���g���[�����W�X�^�T */
#define TMDR5		0xfea1		/* �^�C�}���[�h���W�X�^�T */
#define TIOR5		0xfea2		/* �^�C�}I/O�R���g���[�����W�X�^�T */
#define TIER5		0xfea4		/* �^�C�}�C���^���v�g�C�l�[�u�����W�X�^�T */
#define TSR5		0xfea5		/* �^�C�}�X�e�[�^�X���W�X�^�T */
#define TCNT		0xfea6		/* �^�C�}�J�E���^�T */
#define TGR5A		0xfea8		/* �^�C�}�W�F�l�������W�X�^�T�` */
#define TGR5B		0xfeaa		/* �^�C�}�W�F�l�������W�X�^�T�a */

/* ���� */
#define TSTR		0xffc0		/* �^�C�}�X�e�[�g���W�X�^ */
#define TSYR		0xffc1		/* �^�C�}�V���N�����W�X�^ */

/* �e���W�X�^�̃r�b�g�p�^�[�� */

/* TCR */
#define CCLR2		BIT7		/* �`���l���O�A�R�̂� */
#define CCLR1		BIT6
#define CCLR0		BIT5
#define CKEG1		BIT4
#define CKEG0		BIT3
#define TPSC2		BIT2
#define TPSC1		BIT1
#define TPSC0		BIT0

/* TMDR */
#define BFB		BIT5		/* �`���l���O�A�R�̂� */
#define BFA		BIT4		/* �`���l���O�A�R�̂� */
#define MD3		BIT3
#define MD2		BIT2
#define MD1		BIT1
#define MD0		BIT0

/* TIOR */
/* TIORx�A�܂��́ATIORxH */
#define IOB3		BIT7
#define IOB2		BIT6
#define IOB1		BIT5
#define IOB0		BIT4
#define IOA3		BIT3
#define IOA2		BIT2
#define IOA1		BIT1
#define IOA0		BIT0

/* TIORxL */
#define IOD3		BIT7
#define IOD2		BIT6
#define IOD1		BIT5
#define IOD0		BIT4
#define IOC3		BIT3
#define IOC2		BIT2
#define IOC1		BIT1
#define IOC0		BIT0

/* TIER */
#define TTGE		BIT7
#define TCIEU		BIT5		/* �`���l���P�C�Q�C�S�C�T�̂� */
#define TCIEV		BIT4
#define TGIED		BIT3		/* �`���l���O�C�R�̂� */
#define TGIEC		BIT2		/* �`���l���O�C�R�̂� */
#define TGIEB		BIT1
#define TGIEA		BIT0

/* TSR */
#define TCFD		BIT7
#define TCFU		BIT5		/* �`���l���P�C�Q�C�S�C�T�̂� */
#define TCFV		BIT4
#define TGFD		BIT3		/* �`���l���O�C�R�̂� */
#define TGFC		BIT2		/* �`���l���O�C�R�̂� */
#define TGFB		BIT1
#define TGFA		BIT0

/* TCNT, TGR */
/* ��`���ׂ����̂́A���ɖ��� */

/* TSTR */
#define CST5		BIT5
#define CST4		BIT4
#define CST3		BIT3
#define CST2		BIT2
#define CST1		BIT1
#define CST0		BIT0

/* TSYR */
#define SYNC5		BIT5
#define SYNC4		BIT4
#define SYNC3		BIT3
#define SYNC2		BIT2
#define SYNC1		BIT1
#define SYNC0		BIT0

#endif /* _H8S_TPU_H_ */
