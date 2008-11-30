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

#ifndef _H8S_2339F_H_
#define _H8S_2339F_H_

/*
 *  H8S/2339F �p��`
 */

/*
 *  ���W���[���X�g�b�v�R���g���[�����W�X�^
 *  (�l�X�ȃ��W���[���� ON�AOFF �Ɏg���Ă���̂ŁA�����Œ�`����B)
 */
#define MSTPCR		0xff3c
#define MSTPCR_TPU	BIT13
#define MSTPCR_SCI2	BIT7
#define MSTPCR_SCI1	BIT6
#define MSTPCR_SCI0	BIT5


/*
 *  �����݃R���g���[��
 */
/* ���W�X�^�̃A�h���X */
/* �V�X�e���R���g���[�����W�X�^�́A���ɒ�`�ς� */
#define ISCRH		0xff2c		/* IRQ�Z���X�R���g���[�����W�X�^H */
#define ISCRL		0xff2d		/* IRQ�Z���X�R���g���[�����W�X�^L */
#define IER		0xff2e		/* IRQ�C�l�[�u�����W�X�^ */
#define ISR		0xff2f		/* IRQ�X�e�[�^�X���W�X�^ */
#define IPRA		0xfec4		/* �C���^���v�g�v���C�I���e�B���W�X�^A */
#define IPRB 		0xfec5		/* �C���^���v�g�v���C�I���e�B���W�X�^B */
#define IPRC		0xfec6		/* �C���^���v�g�v���C�I���e�B���W�X�^C */
#define IPRD		0xfec7		/* �C���^���v�g�v���C�I���e�B���W�X�^D */
#define IPRE		0xfec8		/* �C���^���v�g�v���C�I���e�B���W�X�^E */
#define IPRF		0xfec9		/* �C���^���v�g�v���C�I���e�B���W�X�^F */
#define IPRG		0xfeca		/* �C���^���v�g�v���C�I���e�B���W�X�^G */
#define IPRH		0xfecb		/* �C���^���v�g�v���C�I���e�B���W�X�^H */
#define IPRI		0xfecc		/* �C���^���v�g�v���C�I���e�B���W�X�^I */
#define IPRJ		0xfecd		/* �C���^���v�g�v���C�I���e�B���W�X�^J */
#define IPRK		0xfece		/* �C���^���v�g�v���C�I���e�B���W�X�^K */

/* �e���W�X�^�̃r�b�g�p�^�[�� */

/* IPRx (x = A-K) */
#define IPR6		BIT6
#define IPR5		BIT5
#define IPR4		BIT4
#define IPR2		BIT2
#define IPR1		BIT1
#define IPR0		BIT0

/* icu_set_ilv�p */
#define IPR_UPR		TRUE
#define IPR_LOW		FALSE
#define IPR_UPR_MASK	(IPR6|IPR5|IPR4)	/* IPR��ʃr�b�g�}�X�N */
#define IPR_LOW_MASK	(IPR2|IPR1|IPR0)	/* IPR���ʃr�b�g�}�X�N */

/* IER */
#define IRQ7E		BIT7
#define IRQ6E		BIT6
#define IRQ5E		BIT5
#define IRQ4E		BIT4
#define IRQ3E		BIT3
#define IRQ2E		BIT2
#define IRQ1E		BIT1
#define IRQ0E		BIT0

/* ISCRH */
#define IRQ7SCB		BIT7
#define IRQ7SCA		BIT6
#define IRQ6SCB		BIT5
#define IRQ6SCA		BIT4
#define IRQ5SCB		BIT3
#define IRQ5SCA		BIT2
#define IRQ4SCB		BIT1
#define IRQ4SCA		BIT0

/* ISCRL */
#define IRQ3SCB		BIT7
#define IRQ3SCA		BIT6
#define IRQ2SCB		BIT5
#define IRQ2SCA		BIT4
#define IRQ1SCB		BIT3
#define IRQ1SCA		BIT2
#define IRQ0SCB		BIT1
#define IRQ0SCA		BIT0

/* ISR */
#define IRQ7F		BIT7
#define IRQ6F		BIT6
#define IRQ5F		BIT5
#define IRQ4F		BIT4
#define IRQ3F		BIT3
#define IRQ2F		BIT2
#define IRQ1F		BIT1
#define IRQ0F		BIT0

/* �����ݗ�O�����x�N�^�e�[�u���̃x�N�^�ԍ� */
					/* �v�������� */
#define IRQ_POWRESET	0		/* �p���[�I�����Z�b�g */
#define IRQ_MANRESET	1		/* �}�j���A�����Z�b�g */
/* 2-4 �́A�V�X�e���\�� */
#define IRQ_TRACE	5		/* �g���[�X */
/* 6 �́A�V�X�e���\�� */
#define IRQ_NMI		7		/* �O���[�q */
#define IRQ_TRAP0	8		/* �g���b�v���� */
#define IRQ_TRAP1	9		/* �g���b�v���� */
#define IRQ_TRAP2	10		/* �g���b�v���� */
#define IRQ_TRAP3	11		/* �g���b�v���� */
/* 12-15 �́A�V�X�e���\�� */
#define IRQ_IRQ0	16		/* �O���[�q */
#define IRQ_IRQ1	17		/* �O���[�q */
#define IRQ_IRQ2	18		/* �O���[�q */
#define IRQ_IRQ3	19		/* �O���[�q */
#define IRQ_IRQ4	20		/* �O���[�q */
#define IRQ_IRQ5	21		/* �O���[�q */
#define IRQ_IRQ6	22		/* �O���[�q */
#define IRQ_IRQ7	23		/* �O���[�q */
#define IRQ_SWDTEND	24		/* DTC */
#define IRQ_WOVI	25		/* �E�H�b�`�h�b�O�^�C�} */
#define IRQ_CMI 	26		/* ���t���b�V���R���g���[�� */
/* 27 �Ԃ́A���U�[�u */
#define IRQ_ADI		28		/* A/D */
/* 29, 30, 31 �Ԃ́A���U�[�u */
#define IRQ_TGI0A	32		/* TPU�`���l��0 */
#define IRQ_TGI0B	33		/* TPU�`���l��0 */
#define IRQ_TGI0C	34		/* TPU�`���l��0 */
#define IRQ_TGI0D	35		/* TPU�`���l��0 */
#define IRQ_TCI0V	36		/* TPU�`���l��0 */
/* 37, 38, 39 �Ԃ́A���U�[�u */
#define IRQ_TGI1A	40		/* TPU�`���l��1 */
#define IRQ_TGI1B	41		/* TPU�`���l��1 */
#define IRQ_TCI1V	42		/* TPU�`���l��1 */
#define IRQ_TCI1U	43		/* TPU�`���l��1 */
#define IRQ_TGI2A	44		/* TPU�`���l��2 */
#define IRQ_TGI2B	45		/* TPU�`���l��2 */
#define IRQ_TCI2V	46		/* TPU�`���l��2 */
#define IRQ_TCI2U	47		/* TPU�`���l��2 */
#define IRQ_TGI3A	48		/* TPU�`���l��3 */
#define IRQ_TGI3B	49		/* TPU�`���l��3 */
#define IRQ_TGI3C	50		/* TPU�`���l��3 */
#define IRQ_TGI3D	51		/* TPU�`���l��3 */
#define IRQ_TCI3V	52		/* TPU�`���l��3 */
/* 53, 54, 55 �Ԃ́A���U�[�u */
#define IRQ_TGI4A	56		/* TPU�`���l��4 */
#define IRQ_TGI4B	57		/* TPU�`���l��4 */
#define IRQ_TCI4V	58		/* TPU�`���l��4 */
#define IRQ_TCI4U	59		/* TPU�`���l��4 */
#define IRQ_TGI5A	60		/* TPU�`���l��5 */
#define IRQ_TGI5B	61		/* TPU�`���l��5 */
#define IRQ_TCI5V	62		/* TPU�`���l��5 */
#define IRQ_TCI5U	63		/* TPU�`���l��5 */
/* 64, 65, 66, 67, 68, 69, 70, 71 �Ԃ́A���U�[�u */
#define IRQ_DEND0A	72		/* DMAC */
#define IRQ_DEND0B	73		/* DMAC */
#define IRQ_DEND1A	74		/* DMAC */
#define IRQ_DEND1B	75		/* DMAC */
/* 76, 77, 78, 79 �Ԃ́A���U�[�u */
#define IRQ_ERI0	80		/* SCI�`���l��0 */
#define IRQ_RXI0	81		/* SCI�`���l��0 */
#define IRQ_TXI0	82		/* SCI�`���l��0 */
#define IRQ_TEI0	83		/* SCI�`���l��0 */
#define IRQ_ERI1	84		/* SCI�`���l��1 */
#define IRQ_RXI1	85		/* SCI�`���l��1 */
#define IRQ_TXI1	86		/* SCI�`���l��1 */
#define IRQ_TEI1	87		/* SCI�`���l��1 */
#define IRQ_ERI2	88		/* SCI�`���l��2 */
#define IRQ_RXI2	89		/* SCI�`���l��2 */
#define IRQ_TXI2	90		/* SCI�`���l��2 */
#define IRQ_TEI2	91		/* SCI�`���l��2 */

/*
 *  �o�X�R���g���[��
 */
/* ���W�X�^�̃A�h���X */
#define ABWCR		0xfed0		/* �o�X���R���g���[�����W�X�^ */
#define ASTCR		0xfed1		/* �A�N�Z�X�X�e�[�g�R���g���[�����W�X�^ */
#define WCRH		0xfed2		/* �E�F�C�g�R���g���[�����W�X�^H */
#define WCRL      	0xfed3		/* �E�F�C�g�R���g���[�����W�X�^L */
#define BCRH		0xfed4		/* �o�X�R���g���[�����W�X�^H */
#define BCRL		0xfed5		/* �o�X�R���g���[�����W�X�^L */
#define MCR		0xfed6		/* �������R���g���[�����W�X�^ */
#define DRAMCR		0xfed7		/* DRAM�R���g���[�����W�X�^ */
#define RTCNT		0xfed8		/* ���t���b�V���^�C�}�J�E���^ */
#define RTCOR		0xfed9		/* ���t���b�V���^�C�}�R���X�^���g���W�X�^ */

/* �e���W�X�^�̃r�b�g�p�^�[�� */

/* ASTCR */
#define AST7 		BIT7
#define AST6 		BIT6
#define AST5 		BIT5
#define AST4 		BIT4
#define AST3 		BIT3
#define AST2 		BIT2
#define AST1 		BIT1
#define AST0 		BIT0

/* WCRH */
#define W71 		BIT7
#define W70 		BIT6
#define W61 		BIT5
#define W60 		BIT4
#define W51 		BIT3
#define W50 		BIT2
#define W41 		BIT1
#define W40 		BIT0

/* WCRL */
#define W31 		BIT7
#define W30 		BIT6
#define W21 		BIT5
#define W20 		BIT4
#define W11 		BIT3
#define W10 		BIT2
#define W01 		BIT1
#define W00 		BIT0

/* BCRH */
#define ICIS1 		BIT7
#define ICIS0 		BIT6
#define BRSTRM		BIT5
#define BRSTS1 		BIT4
#define BRSTS0		BIT3
#define RMTS2		BIT2
#define RMTS1		BIT1
#define RMTS0 		BIT0


/*
 *  I/O �|�[�g
 */

#define TNUM_IO_PORT	15	/*  I/O�|�[�g�̖{��  */

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

/* port7 */
#define P7DDR		0xfeb6

/* port8 */
#define P8DDR		0xfeb7

/* port9 */
#define P9DDR		0xfeb8

/*  portA  */
#define PADDR		0xfeb9
#define PADR		0xff69
#define PORTA		0xff59

/* portB */
#define PBDDR		0xfeba

/* portC */
#define PCDDR		0xfebb

/* portD */
#define PDDDR		0xfebc

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

#endif /* _H8S_2339F_H_ */
