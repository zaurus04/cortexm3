/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă���
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ���̏����̂����ꂩ�𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
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
 *  @(#) $Id: sh7615.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

#ifndef _SH7615_H_
#define _SH7615_H_

#include <sil.h>

/*
 *  �����݂̃x�N�^�ԍ���`
 */
#define GII	 4					/*  ��ʕs������:General Illegal Instruction  */
#define SII	 6					/*  �X���b�g�s������:Slot Illegal Instruction */
#define CAE	 9					/*  CPU�A�h���X�G���[:CPU Address Error       */
#define DAE	10					/*  DMA�A�h���X�G���[:DMA Address Error       */

#define NMI	11					/*  NMI         */
#define USBK	12				/*  ���[�U�[�u���[�N    */
#define HUDI	13				/*  ���[�U�[�f�o�b�O�C���^�[�t�F�[�X    */
/* �O���x�N�^�ԍ����w�肷��ꍇ�A�Ē�`���ʂɒ�`���� */
#define IRQ0	64				/*  �O�������ݗv��      */
#define IRQ1	65
#define IRQ2	66
#define IRQ3	67
#define IRL1	64
#define IRL2	65
#define IRL3	65
#define IRL4	66
#define IRL5	66
#define IRL6	67
#define IRL7	67
#define IRL8	68
#define IRL9	68
#define IRL10	69
#define IRL11	69
#define IRL12	70
#define IRL13	70
#define IRL14	71
#define IRL15	71

/* �x�N�^�ԍ������R�Ɏw�肷��ꍇ�A�Ē�`���ʂɒ�`���� */
	/*  DMAC:�_�C���N�g�������A�N�Z�X�R���g���[��  */
#define DMAC0	72				/*  DMAC0  */
#define DMAC1	73				/*  DMAC1  */

#define ITI	74					/*  WDT:�E�H�b�`�h�b�N�^�C�}        */
#define CMI	75					/*  REF:DRAM���t���b�V������        */
#define EINT	76				/*  EINT:EtherC���荞��         */

	/*  FRT:�t���[�����j���O�^�C�}  */
#define ICI	77					/*  FRT  */
#define OCI	78
#define OVI	79

	/*  TPU:�^�C�}�p���X���j�b�g  */
#define TGI0A	80				/*  TPU0  */
#define TGI0B	81
#define TGI0C	82
#define TGI0D	83
#define TCI0V	84
#define TGI1A	85				/*  TPU1  */
#define TGI1B	86
#define TCI1V	87
#define TCI1U	88
#define TGI2A	89				/*  TPU2  */
#define TGI2B	90
#define TCI2V	91
#define TCI2U	92

	/*  SCIF:�V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X  */
#define ERI1	93				/*  SCI1  */
#define RXI1	94
#define BRI1	95
#define TXI1	96
#define ERI2	97				/*  SCI2  */
#define RXI2	98
#define BRI2	99
#define TXI2	100

	/*  SIO:�V���A��I/O  */
#define EREI0	101				/*  SCI0  */
#define TERI0	102
#define RDFI0	103
#define TDEI0	104
#define EREI1	105				/*  SCI1  */
#define TERI1	106
#define RDFI1	107
#define TDEI1	108
#define EREI2	109				/*  SCI2  */
#define TERI2	110
#define RDFI2	111
#define TDEI2	112



#ifndef _MACRO_ONLY

/*
 *  SH2�̓������W�X�^��`
 */

/* ���W�X�^�̃A�N�Z�X�͌���32bit�� */
/*
 *   �o�X�X�e�[�g�R���g���[��
 */
/* �o�X�R���g���[�����W�X�^ */
#define BCR1    ((VW *)0xffffffe0)
#define BCR2    ((VW *)0xffffffe4)
#define BCR3    ((VW *)0xfffffffc)
/* �E�F�C�g�R���g���[�����W�X�^ */
#define WCR1    ((VW *)0xffffffe8)
#define WCR2    ((VW *)0xffffffc0)
#define WCR3    ((VW *)0xffffffc4)
/* �ʃ������R���g���[�����W�X�^ */
#define MCR     ((VW *)0xffffffec)
/* ���t���b�V���^�C�}�R���g���[��/�X�e�[�^�X���W�X�^ */
#define RTCSR   ((VW *)0xfffffff0)
/* ���t���b�V���^�C�}�J�E���^ */
#define RTCNT   ((VW *)0xfffffff4)
/* ���t���b�V���^�C���R���X�^���g���W�X�^ */
#define RTCOR   ((VW *)0xfffffff8)
/*-----�������U��H-----*/
#define FMR     ((VB *)0xfffffe90)

/*
 * �s���t�@���N�V�����R���g���[��
 */
#define PACR    ((VH *)0xfffffc80)	/*  �|�[�gA �R���g���[�����W�X�^  */
#define PAIOR   ((VH *)0xfffffc82)	/*  �|�[�gA I/O���W�X�^       */
#define PBCR    ((VH *)0xfffffc88)	/*  �|�[�gB �R���g���[�����W�X�^  */
#define PBIOR   ((VH *)0xfffffc8a)	/*  �|�[�gB I/O���W�X�^       */
#define PBCR2   ((VH *)0xfffffc8e)	/*  �|�[�gB �R���g���[�����W�X�^2 */
#define PADR    ((VH *)0xfffffc84)	/*  �|�[�gA �f�[�^���W�X�^        */
#define PBDR    ((VH *)0xfffffc8c)	/*  �|�[�gB �f�[�^���W�X�^        */

/* ���荞�ݗD��x���x���ݒ背�W�X�^ */
#define IPRA    ((VH *)0xfffffee2)
#define IPRB    ((VH *)0xfffffe60)
#define IPRC    ((VH *)0xfffffee6)
#define IPRD    ((VH *)0xfffffe40)
#define IPRE    ((VH *)0xfffffec0)
/* �x�N�^�ԍ��ݒ背�W�X�^ */
#define VCRA    ((VH *)0xfffffe62)
#define VCRB    ((VH *)0xfffffe64)
#define VCRC    ((VH *)0xfffffe66)
#define VCRD    ((VH *)0xfffffe68)
#define VCRE    ((VH *)0xfffffe42)
#define VCRF    ((VH *)0xfffffe44)
#define VCRG    ((VH *)0xfffffe46)
#define VCRH    ((VH *)0xfffffe48)
#define VCRI    ((VH *)0xfffffe4a)
#define VCRJ    ((VH *)0xfffffe4c)
#define VCRK    ((VH *)0xfffffe4e)
#define VCRL    ((VH *)0xfffffe50)
#define VCRM    ((VH *)0xfffffe52)
#define VCRN    ((VH *)0xfffffe54)
#define VCRO    ((VH *)0xfffffe56)
#define VCRP    ((VH *)0xfffffec2)
#define VCRQ    ((VH *)0xfffffec4)
#define VCRR    ((VH *)0xfffffec6)
#define VCRS    ((VH *)0xfffffec8)
#define VCRT    ((VH *)0xfffffeca)
#define VCRU    ((VH *)0xfffffecc)
#define VCRWDT  ((VH *)0xfffffee4)
#define DMA_VCRDMA0     ((VW *)0xffffffa0)
#define DMA_VCRDMA1     ((VW *)0xffffffa8)
/* ���荞�݃R���g���[�����W�X�^ */
#define ICR     ((VH *)0xfffffee0)
/* ���荞�݃R���g���[��/�X�e�[�^�X���W�X�^ */
#define IRQCSR  ((VH *)0xfffffee8)

/*
 * ���荞�݃R���g���[���̏�����
 */
Inline void
sh2_init_intcontorller (void)
{
	sil_wrh_mem (IPRA, 0x0000);
	sil_wrh_mem (IPRB, 0x0000);
	sil_wrh_mem (IPRC, 0x0000);
	sil_wrh_mem (IPRD, 0x0000);
	sil_wrh_mem (IPRE, 0x0000);
}

#endif /* _MACRO_ONLY */

#endif /* _SH7615_H_ */
