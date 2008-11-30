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
 *  @(#) $Id: sh1.h,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */

#ifndef _SH1_H_
#define _SH1_H_

/*
 *  �����݂̃x�N�^�ԍ���`
 */
#define GII	 4	/*  ��ʕs������:General Illegal Instruction  */
#define SII	 6	/*  �X���b�g�s������:Slot Illegal Instruction */
#define CAE	 9	/*  CPU�A�h���X�G���[:CPU Address Error       */
#define DAE	10	/*  DMA�A�h���X�G���[:DMA Address Error       */

#define NMI	11	/*  NMI  		*/
#define USBK	12	/*  ���[�U�[�u���[�N  	*/
#define IRQ0	64	/*  �O�������ݗv��  	*/
#define IRQ1	65
#define IRQ2	66
#define IRQ3	67
#define IRQ4	68
#define IRQ5	69
#define IRQ6	70
#define IRQ7	71

	/*  DMAC:�_�C���N�g�������A�N�Z�X�R���g���[��  */
#define DEI0	72	/*  DMAC0  */
#define DEI1	74	/*  DMAC1  */
#define DEI2	76	/*  DMAC2  */
#define DEI3	78	/*  DMAC3  */

	/*  ITU:�C���e�N���[�e�b�h�^�C�}�p���X���j�b�g  */
#define IMIA0	80	/*  ITU0  */
#define IMIB0	81
#define OVI0	82
#define IMIA1	84	/*  ITU1  */
#define IMIB1	85
#define OVI1	86
#define IMIA2	88	/*  ITU2  */
#define IMIB2	89
#define OVI2	90
#define IMIA3	92	/*  ITU3  */
#define IMIB3	93
#define OVI3	94
#define IMIA4	96	/*  ITU4  */
#define IMIB4	97
#define OVI4	98

	/*  SCI:�V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X  */
#define ERI0	100	/*  SCI0  */
#define RXI0	101
#define TXI0	102
#define TEI0	103
#define ERI1	104	/*  SCI1  */
#define RXI1	105
#define TXI1	106
#define TEI1	107

#define PEI	108	/*  PRT:�o�X�R���g���[���̃p���e�B����  */
#define ADI	109	/*  A/D�R���o�[�^  			*/
#define ITI	112	/*  WDT:�E�H�b�`�h�b�N�^�C�}  		*/
#define CMI	113	/*  REF:DRAM���t���b�V������  		*/



#ifndef _MACRO_ONLY

/*
 *  SH1�̓������W�X�^��`
 *  
 *  �@�R���p�C���̌^�`�F�b�N�@�\��L���ɂ��邽�߁A�|�C���^�^�ɂ�
 *  �@VP�ł͂Ȃ��AVB *,VH *, VW *��p���Ă���B
 */

/*
 * �s���t�@���N�V�����R���g���[�� �i�T�C�Y��2�o�C�g�j
 */
#define	PAIOR	((VH *)0x5ffffc4)	/*  �|�[�gA I/O���W�X�^  	  */
#define	PACR1	((VH *)0x5ffffc8)	/*  �|�[�gA �R���g���[�����W�X�^1 */
#define	PACR2	((VH *)0x5ffffca)	/*  �|�[�gA �R���g���[�����W�X�^2 */
#define	PBIOR	((VH *)0x5ffffc6)	/*  �|�[�gB I/O���W�X�^  	  */
#define	PBCR1	((VH *)0x5ffffcc)	/*  �|�[�gB �R���g���[�����W�X�^1 */
#define	PBCR2	((VH *)0x5ffffce)	/*  �|�[�gB �R���g���[�����W�X�^2 */
#define	PADR	((VH *)0x5ffffc0)	/*  �|�[�gA �f�[�^���W�X�^  	  */

#define PBCR1_TD0_RD0_MASK 	~0xfu	/*  TxD0,RxD0�[�q�ݒ�p�}�X�N	*/
#define PBCR1_TD0 		 0x8u	/*  TxD0�[�q�ݒ�p�}�N��  	*/
#define PBCR1_RD0 		 0x2u	/*  RxD0�[�q�ݒ�p�}�N��  	*/


/*
 * ���荞�݃R���g���[�����W�X�^
 */
#define	IPRA	((VH *)0x5ffff84)	/*  �����݃��x���ݒ背�W�X�^  */
#define	IPRB	((VH *)0x5ffff86)	/*  �i�T�C�Y��2�o�C�g�j  */
#define	IPRC	((VH *)0x5ffff88)
#define	IPRD	((VH *)0x5ffff8a)
#define	IPRE	((VH *)0x5ffff8c)
#define	ICR	((VH *)0x5ffff8e)	/*  �����݃R���g���[�����W�X�^  */
					/*  �i�T�C�Y��2�o�C�g�j  */

#endif /* _MACRO_ONLY */

#endif /* _SH1_H_ */
