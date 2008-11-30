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

#ifndef _H8S_H_
#define _H8S_H_

#include <util.h>

/*
 *  H8S/2600, H8S/2000 CPU �p��`
 *    ����сA�o�X�R���g���[���A�����݃R���g���[���֘A�̒�`
 */

/*
 *  �R���f�B�V�����R�[�h���W�X�^(CCR)
 */
#define CCR_I		BIT7
#define CCR_UI		BIT6
#define CCR_H		BIT5
#define CCR_U		BIT4
#define CCR_N		BIT3
#define CCR_Z		BIT2
#define CCR_V		BIT1
#define CCR_C		BIT0

/*
 *  �G�N�X�e���h���W�X�^(EXR)
 */
#define EXR_T		BIT7		/* �g���[�X�r�b�g */
#define EXR_I2		BIT2		/* �����݃}�X�N�r�b�g */
#define EXR_I1		BIT1		/* �����݃}�X�N�r�b�g */
#define EXR_I0		BIT0		/* �����݃}�X�N�r�b�g */

/* �����݃}�X�N�r�b�g�擾�p�}�X�N */
#define EXR_I_MASK	(EXR_I2|EXR_I1|EXR_I0)

/*
 *  MCU���샂�[�h�֘A�̃��W�X�^
 */

/* ���W�X�^�̃A�h���X */
#define MDCR		0xff3b
#define SYSCR		0xff39

/* �e���W�X�^�̃r�b�g�p�^�[�� */

/* MDCR */
#define MDS2		BIT2
#define MDS1		BIT1
#define MDS0		BIT0

/* SYSCR */
#define INTM1		BIT5
#define INTM0		BIT4
#define NMIEG		BIT3
#define RAME		BIT0

#define RAME_BIT	0x0

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
/* 2-4 �́A��O�����x�N�^�e�[�u���ɑΉ�����̂ŁA�ȗ� */
#define IRQ_TRACE	5		/* �g���[�X */
/* 6 �́A��O�����x�N�^�e�[�u���ɑΉ�����̂ŁA�ȗ� */
#define IRQ_NMI		7		/* �O���[�q */
#define IRQ_TRAP0	8		/* �g���b�v���� */
#define IRQ_TRAP1	9		/* �g���b�v���� */
#define IRQ_TRAP2	10		/* �g���b�v���� */
#define IRQ_TRAP3	11		/* �g���b�v���� */
/* 12-15 �́A��O�����x�N�^�e�[�u���ɑΉ�����̂ŁA�ȗ� */
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
/* 88, 89, 90, 91 �Ԃ́A���U�[�u */

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
 *  �����ݎ��̃X�^�b�N�ɂ�����EXR���W�X�^�̃I�t�Z�b�g
 */
#define EXR_offset	28

/*
 *  ����`�����ݔ������̃G���[�o�͎��̃X�^�b�N�\���̒�`
 */
#ifndef _MACRO_ONLY

typedef struct exc_stack {
	UW	er6;
	UW	er5;
	UW	er4;
	UW	er3;
	UW	er2;
	UW	er1;
	UW	er0;
	UB	exr;
	UB	tmp;
	UH	ccr;	/* 1 byte : 1 byte = CCR : PC(��ʂP�o�C�g) */
	UH	pc;	/* 1 byte : 1 byte = PC(���ʂQ�o�C�g) */
} EXCSTACK;

#endif /* _MACRO_ONLY */

#endif /* _H8S_H_ */
