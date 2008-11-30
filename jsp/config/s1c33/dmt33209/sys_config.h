/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */

/*
 *  �^�[�Q�b�g�V�X�e���ˑ����W���[��(DMT33209)
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */

#include "sys_rename.h"

/*
 *  �������ԑ���p�T�[�r�X�R�[�����T�|�[�g���Ȃ�
 */
#define OMIT_VGET_TIM

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g��
 */
#define TARGET_NAME	"EPSON S1C33 Standard Macro"

/*
 *  �T�|�[�g����V���A���f�B�o�C�X�̐��͍ő� 1
 */
#define TNUM_PORT		1
#define LOGTASK_PORTID		1

/*
 *  �V���A�����荞�݂�����/�o�͂ňقȂ邩�ǂ����̒�`
 */
#define SEPARATE_SIO_INT

#include "s1c33.h"
#include "dmt33209.h"

#ifndef _MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���D
 */
extern void sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���D
 *
 */
extern void sys_putc(char c);

/*
 *  �����ݐ��䃌�W�X�^�̃I�t�Z�b�g�ʒu�擾
 */
/*
 *  ���荞�݃v���C�I���e�B���W�X�^�ʒu���菈��
 */
Inline ER
get_Offset(INTNO intno)
{
	INT		iOffset;
	switch(intno)
	{
		case S1C33_INHNO_PINT0:			/* Key, Port0-3 group */
		case S1C33_INHNO_PINT1:
		case S1C33_INHNO_PINT2:
		case S1C33_INHNO_PINT3:
		case S1C33_INHNO_KINT0:
		case S1C33_INHNO_KINT1:
			iOffset = 0;
			break;

		case S1C33_INHNO_HSDMA0:		/* DMA group */
		case S1C33_INHNO_HSDMA1:
		case S1C33_INHNO_HSDMA2:
		case S1C33_INHNO_HSDMA3:
		case S1C33_INHNO_IDMA:
			iOffset = 1;
			break;

		case S1C33_INHNO_P16TIMER0B:		/* 16bit timer0/1 group */
		case S1C33_INHNO_P16TIMER0A:
		case S1C33_INHNO_P16TIMER1B:
		case S1C33_INHNO_P16TIMER1A:
			iOffset = 2;
			break;

		case S1C33_INHNO_P16TIMER2B:		/* 16bit timer2/3 group */
		case S1C33_INHNO_P16TIMER2A:
		case S1C33_INHNO_P16TIMER3B:
		case S1C33_INHNO_P16TIMER3A:
			iOffset = 3;
			break;

		case S1C33_INHNO_P16TIMER4B:		/* 16bit timer4/5 group */
		case S1C33_INHNO_P16TIMER4A:
		case S1C33_INHNO_P16TIMER5B:
		case S1C33_INHNO_P16TIMER5A:
			iOffset = 4;
			break;

		case S1C33_INHNO_P8TIMER0:		/* 8bit timer group */
		case S1C33_INHNO_P8TIMER1:
		case S1C33_INHNO_P8TIMER2:
		case S1C33_INHNO_P8TIMER3:
			iOffset = 5;
			break;

		case S1C33_INHNO_SERIAL0ERR:		/* Serial I/O group */
		case S1C33_INHNO_SERIAL0RX:
		case S1C33_INHNO_SERIAL0TX:
		case S1C33_INHNO_SERIAL1ERR:
		case S1C33_INHNO_SERIAL1RX:
		case S1C33_INHNO_SERIAL1TX:
			iOffset = 6;
			break;

		case S1C33_INHNO_AD:			/* A/DConv, clocktimer, */
		case S1C33_INHNO_CLKTIMER:		/* Port 4-7 group	*/
		case S1C33_INHNO_PINT4:
		case S1C33_INHNO_PINT5:
		case S1C33_INHNO_PINT6:
		case S1C33_INHNO_PINT7:
			iOffset = 7;
			break;

		default:
			iOffset = E_PAR;
	}

	return (iOffset);
}

/*
 *  ���荞�ݐ���r�b�g�ʒu���菈��
 */
Inline ER
get_BitFlag(INTNO intno)
{
	INT	iBitFlag;

	switch(intno)
	{
		case S1C33_INHNO_PINT0:			/* D0 group*/
		case S1C33_INHNO_HSDMA0:
		case S1C33_INHNO_P8TIMER0:
		case S1C33_INHNO_SERIAL0ERR:
		case S1C33_INHNO_AD:
			iBitFlag = 0x01;
			break;

		case S1C33_INHNO_PINT1:			/* D1 group*/
		case S1C33_INHNO_HSDMA1:
		case S1C33_INHNO_P8TIMER1:
		case S1C33_INHNO_SERIAL0RX:
		case S1C33_INHNO_CLKTIMER:
			iBitFlag = 0x02;
			break;

		case S1C33_INHNO_PINT2:			/* D2 group*/
		case S1C33_INHNO_HSDMA2:
		case S1C33_INHNO_P16TIMER0B:
		case S1C33_INHNO_P16TIMER2B:
		case S1C33_INHNO_P16TIMER4B:
		case S1C33_INHNO_P8TIMER2:
		case S1C33_INHNO_SERIAL0TX:
		case S1C33_INHNO_PINT4:
			iBitFlag = 0x04;
			break;

		case S1C33_INHNO_PINT3:			/* D3 group*/
		case S1C33_INHNO_HSDMA3:
		case S1C33_INHNO_P16TIMER0A:
		case S1C33_INHNO_P16TIMER2A:
		case S1C33_INHNO_P16TIMER4A:
		case S1C33_INHNO_P8TIMER3:
		case S1C33_INHNO_SERIAL1ERR:
		case S1C33_INHNO_PINT5:
			iBitFlag = 0x08;
			break;

		case S1C33_INHNO_KINT0:			/* D4 group*/
		case S1C33_INHNO_IDMA:
		case S1C33_INHNO_SERIAL1RX:
		case S1C33_INHNO_PINT6:
			iBitFlag = 0x10;
			break;

		case S1C33_INHNO_KINT1:			/* D5 group*/
		case S1C33_INHNO_SERIAL1TX:
		case S1C33_INHNO_PINT7:
			iBitFlag = 0x20;
			break;

		case S1C33_INHNO_P16TIMER1B:		/* D6 group*/
		case S1C33_INHNO_P16TIMER3B:
		case S1C33_INHNO_P16TIMER5B:
			iBitFlag = 0x40;
			break;

		case S1C33_INHNO_P16TIMER1A:		/* D7 group*/
		case S1C33_INHNO_P16TIMER3A:
		case S1C33_INHNO_P16TIMER5A:
			iBitFlag = 0x80;
			break;

		default:
			iBitFlag = E_PAR;
	}

	return (iBitFlag);
}

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONFIG_H_ */
