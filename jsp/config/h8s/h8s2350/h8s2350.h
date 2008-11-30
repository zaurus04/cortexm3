/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

#ifndef _H8S_2350_H_
#define _H8S_2350_H_

/*
 *  H8S/2350 �p��`
 */
/*
 *  ���W���[���X�g�b�v�R���g���[�����W�X�^
 *  (�l�X�ȃ��W���[���� ON�AOFF �Ɏg���Ă���̂ŁA�����Œ�`����B)
 */
#define MSTPCR		0xff3c	/* ���W���[���X�g�b�v�R���g���[�����W�X�^ */

/*
 *  I/O �|�[�g
 */

/* �e�|�[�g���W�X�^�̃A�h���X */

/* port1 */
#define P1DDR		0xfeb0
#define P1DR		0xff60
#define PORT1		0xff50

/* port2 */
#define P2DDR		0xfeb1
#define P2DR		0xff61
#define PORT2		0xff51

/* port3 */
#define P3DDR		0xfeb2
#define P3DR		0xff62
#define PORT3		0xff52
#define P3ODR		0xff76

/* port4 */
#define PORT4		0xff53

/* port5 */
#define P5DDR		0xfeb4
#define P5DR		0xff64
#define PORT5		0xff54

/* port6 */
#define P6DDR		0xfeb5
#define P6DR		0xff65
#define PORT6 		0xff55

/*  portA  */
#define PADDR		0xfeb9
#define PADR		0xff69
#define PORTA		0xff59

/*  portE  */
#define PEDDR		0xfebd
#define PEDR		0xff6d
#define PORTE		0xff5d
#define PEPCR		0xff74

/*  portF  */
#define PFDDR		0xfebe
#define PFDR		0xff6e
#define PORTF		0xff5e

/*  portG  */
#define PGDDR		0xfebf	/* �|�[�g�f�f�[�^�f�B�X�N���v�V�������W�X�^ */
#define PGDR		0xff6f	/* �|�[�g�f�f�[�^���W�X�^ */
#define PORTG		0xff5f	/* �|�[�g�f���W�X�^ */

/* �e���W�X�^�̃r�b�g�p�^�[�� */

/* P2DDR */
#define P27DDR		BIT7
#define P26DDR		BIT6
#define P25DDR		BIT5
#define P24DDR		BIT4
#define P23DDR		BIT3
#define P22DDR		BIT2
#define P21DDR		BIT1
#define P20DDR		BIT0

/* P3DDR */
#define P37DDR		BIT7
#define P36DDR		BIT6
#define P35DDR		BIT5
#define P34DDR		BIT4
#define P33DDR		BIT3
#define P32DDR		BIT2
#define P31DDR		BIT1
#define P30DDR		BIT0

/* PGDDR */
#define PG4DDR		BIT4
#define PG3DDR		BIT3
#define PG2DDR		BIT2
#define PG1DDR		BIT1
#define PG0DDR		BIT0

#endif /* _H8S_2350_H_ */
