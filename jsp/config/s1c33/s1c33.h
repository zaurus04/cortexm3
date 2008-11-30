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
 *  �n�[�h�E�F�A�����̒�`
 */
#ifndef _S1C33_H_
#define _S1C33_H_

/*
 *  �ėp���W�X�^��
 */
#define S1C33_GR_NUM		16

/*
 *  PSR
 */
#define S1C33_PSR_INITIAL	0x00000000
#define S1C33_PSR_MASK_IL	0x00000F00
#define S1C33_PSR_FLAG_IE	0x00000010

/*
 *  ��{�������}�b�v
 */
#define S1C33_AREA00_BASE	0x00000000
#define S1C33_AREA01_BASE	0x00040000
#define S1C33_AREA02_BASE	0x00060000
#define S1C33_AREA03_BASE	0x00080000
#define S1C33_AREA04_BASE	0x00100000
#define S1C33_AREA05_BASE	0x00200000
#define S1C33_AREA06_BASE	0x00300000
#define S1C33_AREA07_BASE	0x00400000
#define S1C33_AREA08_BASE	0x00600000
#define S1C33_AREA09_BASE	0x00800000
#define S1C33_AREA10_BASE	0x00c00000
#define S1C33_AREA11_BASE	0x01000000
#define S1C33_AREA12_BASE	0x01800000
#define S1C33_AREA13_BASE	0x02000000
#define S1C33_AREA14_BASE	0x03000000
#define S1C33_AREA15_BASE	0x04000000
#define S1C33_AREA16_BASE	0x06000000
#define S1C33_AREA17_BASE	0x08000000
#define S1C33_AREA18_BASE	0x0c000000

#define S1C33_INTERNAL_RAM_BASE		S1C33_AREA00_BASE
#define S1C33_INT08_DEVICE_BASE		(S1C33_AREA01_BASE + 0x0000000)
#define S1C33_INT16_DEVICE_BASE		(S1C33_AREA01_BASE + 0x0008000)
#define S1C33_EXT08_DEVICE_BASE		(S1C33_AREA06_BASE + 0x0000000)
#define S1C33_EXT16_DEVICE_BASE		(S1C33_AREA06_BASE + 0x0080000)

#define S1C33_TIMER_CONTROL_BASE	(S1C33_INT08_DEVICE_BASE + 0x0000140)
#define S1C33_CLKTIMER_BASE		(S1C33_INT08_DEVICE_BASE + 0x0000150)
#define S1C33_P8TIMER_BASE		(S1C33_INT08_DEVICE_BASE + 0x0000160)
#define S1C33_WATCHDOG_BASE		(S1C33_INT08_DEVICE_BASE + 0x0000170)
#define S1C33_POWER_BASE		(S1C33_INT08_DEVICE_BASE + 0x0000180)
#define S1C33_SERIAL_BASE		(S1C33_INT08_DEVICE_BASE + 0x00001e0)
#define S1C33_AD_BASE			(S1C33_INT08_DEVICE_BASE + 0x0000240)
#define S1C33_INTC_BASE			(S1C33_INT08_DEVICE_BASE + 0x0000260)
#define S1C33_DMAC_BASE			(S1C33_INT08_DEVICE_BASE + 0x0000290)
#define S1C33_PORT_BASE			(S1C33_INT08_DEVICE_BASE + 0x00002c0)

#define S1C33_BCU_BASE			(S1C33_INT16_DEVICE_BASE + 0x0000120)
#define S1C33_P16TIMER_BASE		(S1C33_INT16_DEVICE_BASE + 0x0000180)
#define S1C33_IDMA_BASE			(S1C33_INT16_DEVICE_BASE + 0x0000200)
#define S1C33_HSDMA_BASE		(S1C33_INT16_DEVICE_BASE + 0x0000220)

/*
 *  ���荞�݃x�N�^�ԍ�
 */
#define S1C33_INHNO_RESET		0x00
#define S1C33_INHNO_ZERO		0x04
#define S1C33_INHNO_ADDRESS		0x06
#define S1C33_INHNO_DEBUG		0x07
#define S1C33_INHNO_NMI			0x08
#define S1C33_INHNO_INT0		0x0c
#define S1C33_INHNO_INT1		0x0d
#define S1C33_INHNO_INT2		0x0e
#define S1C33_INHNO_INT3		0x0f
#define S1C33_INHNO_PINT0		0x10
#define S1C33_INHNO_PINT1		0x11
#define S1C33_INHNO_PINT2		0x12
#define S1C33_INHNO_PINT3		0x13
#define S1C33_INHNO_KINT0		0x14
#define S1C33_INHNO_KINT1		0x15
#define S1C33_INHNO_HSDMA0		0x16
#define S1C33_INHNO_HSDMA1		0x17
#define S1C33_INHNO_HSDMA2		0x18
#define S1C33_INHNO_HSDMA3		0x19
#define S1C33_INHNO_IDMA		0x1a
#define S1C33_INHNO_P16TIMER0B		0x1e
#define S1C33_INHNO_P16TIMER0A		0x1f
#define S1C33_INHNO_P16TIMER1B		0x22
#define S1C33_INHNO_P16TIMER1A		0x23
#define S1C33_INHNO_P16TIMER2B		0x26
#define S1C33_INHNO_P16TIMER2A		0x27
#define S1C33_INHNO_P16TIMER3B		0x2a
#define S1C33_INHNO_P16TIMER3A		0x2b
#define S1C33_INHNO_P16TIMER4B		0x2e
#define S1C33_INHNO_P16TIMER4A		0x2f
#define S1C33_INHNO_P16TIMER5B		0x32
#define S1C33_INHNO_P16TIMER5A		0x33
#define S1C33_INHNO_P8TIMER0		0x34
#define S1C33_INHNO_P8TIMER1		0x35
#define S1C33_INHNO_P8TIMER2		0x36
#define S1C33_INHNO_P8TIMER3		0x37
#define S1C33_INHNO_SERIAL0ERR		0x38
#define S1C33_INHNO_SERIAL0RX		0x39
#define S1C33_INHNO_SERIAL0TX		0x3a
#define S1C33_INHNO_SERIAL1ERR		0x3c
#define S1C33_INHNO_SERIAL1RX		0x3d
#define S1C33_INHNO_SERIAL1TX		0x3e
#define S1C33_INHNO_AD			0x40
#define S1C33_INHNO_CLKTIMER		0x41
#define S1C33_INHNO_PINT4		0x44
#define S1C33_INHNO_PINT5		0x45
#define S1C33_INHNO_PINT6		0x46
#define S1C33_INHNO_PINT7		0x47
#define S1C33_INHNO_P8TIMER4		0x48
#define S1C33_INHNO_P8TIMER5		0x49
#define S1C33_INHNO_SERIAL2ERR		0x4c
#define S1C33_INHNO_SERIAL2RX		0x4d
#define S1C33_INHNO_SERIAL2TX		0x4e
#define S1C33_INHNO_SERIAL3ERR		0x50
#define S1C33_INHNO_SERIAL3RX		0x51
#define S1C33_INHNO_SERIAL3TX		0x52

/*
 *  �A�h�o���X�g�}�N���ŗL�̊��荞�݃x�N�^
 */
#define S1C33_INHNO_PINT8		0x54
#define S1C33_INHNO_PINT9		0x55
#define S1C33_INHNO_PINT10		0x56
#define S1C33_INHNO_PINT11		0x57
#define S1C33_INHNO_PINT12		0x58
#define S1C33_INHNO_PINT13		0x59
#define S1C33_INHNO_PINT14		0x5a
#define S1C33_INHNO_PINT15		0x5b
#define S1C33_INHNO_P16TIMER6B		0x5e
#define S1C33_INHNO_P16TIMER6A		0x5f
#define S1C33_INHNO_P16TIMER7B		0x62
#define S1C33_INHNO_P16TIMER7A		0x63
#define S1C33_INHNO_P16TIMER8B		0x66
#define S1C33_INHNO_P16TIMER8A		0x67
#define S1C33_INHNO_P16TIMER9B		0x6a
#define S1C33_INHNO_P16TIMER9A		0x6b


#ifndef _MACRO_ONLY

typedef unsigned char   byte;
typedef unsigned short  word;
typedef volatile byte   IOREG;
typedef volatile word   HIOREG;
typedef volatile int    LIOREG;

/*
 * ���W�X�^(TIMER_CONTROL 140)
 */
typedef struct {
	IOREG bP8ClkSelect45;
	IOREG bDummy[4];
	IOREG bP8ClkCtrl45;
	IOREG bP8ClkSelect;
	IOREG bP16ClkCtrl[6];
	IOREG bP8ClkCtrl[2];
	IOREG bADClkCtrl;
} s1c33TimerControl_t;

/*
 *  ���W�X�^(SERIAL 1e0)
 */
typedef struct {
	struct {
		IOREG bTxd;
		IOREG bRxd;
		IOREG bStatus;
		IOREG bControl;
		IOREG bIrDA;
	} stChannel01[2];

	IOREG Dummy0[6];

	struct {
		IOREG bTxd;
		IOREG bRxd;
		IOREG bStatus;
		IOREG bControl;
		IOREG bIrDA;
	} stChannel23[2];
#ifdef	__c33adv
	IOREG Dummy1[5];
	IOREG bSioAdv;
#endif	// __c33adv
} s1c33Serial_t;

/*
 *  ���W�X�^(INTC 260)
 *
 */
typedef struct {
	IOREG bPriority[15];	/* C33209�ł̃A�T�C����bPriority[14] +	*/
	IOREG bDummy0[1];	/* bDummy0[2]�̍\���Ɠ�����		*/

	IOREG bIntEnable[10];	/* C33209�ł̃A�T�C����bIntEnable[8] +	*/
	IOREG bDummy1[6];	/* bDummy1[8]�̍\���Ɠ�����		*/

	IOREG bIntFactor[10];	/* C33209�ł̃A�T�C����bIntFactor[8] +	*/
	IOREG bDummy2[6];	/* bDummy2[8]�̍\���Ɠ�����		*/

	IOREG bIDMAReq[4];
	IOREG bIDMAEnable[4];
	IOREG bHSDMATriger[2];
	IOREG bHSDMASoftTrg;

	IOREG bIDMAReqExt;	/* C33209�ł̃A�T�C����bDummy3[4]��	*/
	IOREG bIDMAEnableExt;	/* �\���Ɠ�����*/
	IOREG bDummy3[2];

	IOREG bReset;
} s1c33Intc_t;

/*
 *  ���W�X�^(PORT 2c0)
 */
typedef struct {
	struct {
		IOREG bFuncSwitch;
		IOREG bData;
	} stK5Port;

	IOREG bDummy;

	struct {
		IOREG bFuncSwitch;
		IOREG bData;
	} stK6Port;

	IOREG bIntFPSwitch;		/* C33L11�ł͖��g�p		*/

	struct {
		IOREG bSpt[2];
		IOREG bSppt;
		IOREG bSept;
	} stPINT;

	struct {
		IOREG bSppk;
		IOREG bTM16Switch;	/* C33L11�ł͖��g�p		*/
		IOREG bScpk[2];
		IOREG bSmpk[2];
	} stKINT;

	struct {
		IOREG bFuncSwitch;
		IOREG bData;
		IOREG bControl;
		IOREG bFuncExt		/* stPPort[0]�̂�C33209,C33L11	*/;
					/* �Ƃ����g�p			*/
	} stPPort[4];
} s1c33Port_t;

/*
 *  ���W�X�^(BCU 120)
 */
typedef struct {
	HIOREG uwA18_15;
	HIOREG uwA14_13;
	HIOREG uwA12_11;
	HIOREG uwA10_09;
	HIOREG uwA08_07;
	HIOREG uwA06_04;
	IOREG  bDummy;
	IOREG  bTtbrProt;
	HIOREG uwBus;
	HIOREG uwDram;
	HIOREG uwAccess;
	LIOREG ulTtbr;
	HIOREG uwGACtrl;
	IOREG  bBClk;
} s1c33Bcu_t;

/*
 *  ���W�X�^(P16TIMER 180)
 */
typedef struct {
	struct {
		HIOREG uwComp[2];
		HIOREG uwCount;
		IOREG  bControl;
		IOREG  bDummy;
	} stChannel[6];
} s1c33P16Timer_t;

#endif /* _MACRO_ONLY */
#endif /* _S1C33_H_ */
