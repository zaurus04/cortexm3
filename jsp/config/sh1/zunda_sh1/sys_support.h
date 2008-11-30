/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD. JAPAN
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
#ifndef _SYS_SUPPORT_H_
#define _SYS_SUPPORT_H_

/*
 *  �|�[�g�`�E�g���h�^�n�֊J���[�q�̒�`
 *  ���ׂăv���A�b�v����
 */
/*
 *  PA15 �I������@�\�� 1 �ɃZ�b�g���Ă�������
 */
#define	PA15_PORT_IN	1	/* �ėp���̓|�[�g		PI15	*/
#define	PA15_PORT_OUT	0	/* �ėp�o�̓|�[�g		PO15	*/
#define	PA15_IRQ3	0	/* ���荞�ݗv������		IRQ3	*/
#define	PA15_DREQ1	0	/* �c�l�`�]���v������		DREQ1	*/

/*
 *  PA14 �I������@�\�� 1 �ɃZ�b�g���Ă�������
 */
#define	PA14_PORT_IN	1	/* �ėp���̓|�[�g		PI14	*/
#define	PA14_PORT_OUT	0	/* �ėp�o�̓|�[�g		PO14	*/
#define	PA14_IRQ2	0	/* ���荞�ݗv������ 		IRQ2	*/
#define	PA14_DACK1	0	/* �c�l�`�]���v����t�o��	DACK1	*/

/*
 *  PA13 �I������@�\�� 1 �ɃZ�b�g���Ă�������
 */
#define	PA13_PORT_IN	1	/* �ėp���̓|�[�g		PI13	*/
#define	PA13_PORT_OUT	0	/* �ėp�o�̓|�[�g		PO13	*/
#define	PA13_IRQ1	0	/* ���荞�ݗv������ 		IRQ1	*/
#define	PA13_TCLKB	0	/* �h�s�t�^�C�}�N���b�N����	TCLKB	*/
#define	PA13_DREQ0	0	/* �c�l�`�]���v������		DREQ0	*/

/*
 *  PA12 �I������@�\�� 1 �ɃZ�b�g���Ă�������
 */
#define	PA12_PORT_IN	1	/* �ėp���̓|�[�g		PI12	*/
#define	PA12_PORT_OUT	0	/* �ėp�o�̓|�[�g		PO12	*/
#define	PA12_IRQ0	0	/* ���荞�ݗv������ 		IRQ0	*/
#define	PA13_TCLKA	0	/* �h�s�t�^�C�}�N���b�N����	TCLKA	*/
#define	PA13_DACK0	0	/* �c�l�`�]���v����t�o��	DACK0	*/

/*
 *  PA03 �I������@�\�� 1 �ɃZ�b�g���Ă�������
 */
#define	PA03_PORT_IN	1	/* �ėp���̓|�[�g		PI03	*/
#define	PA03_PORT_OUT	0	/* �ėp�o�̓|�[�g		PO03	*/
#define	PA03_CS7	0	/* �`�b�v�Z���N�g�V�o��		CS7	*/
#define	PA03_WAIT	0	/* �E�G�C�g�X�e�[�g����		WAIT	*/

/*
 *  PA01 �I������@�\�� 1 �ɃZ�b�g���Ă�������
 */
#define	PA01_PORT_IN	1	/* �ėp���̓|�[�g		PI01	*/
#define	PA01_PORT_OUT	0	/* �ėp�o�̓|�[�g		PO01	*/
#define	PA01_CS5	0	/* �`�b�v�Z���N�g�T�o��		CS5	*/
#define	PA01_RAS	0	/* ���E�A�h���X�X�g���[�u�o��	RAS	*/

/*####################################################
 *
 *  �ȉ��ҏW���Ȃ�����
 *
 *####################################################*/
/*
 *  �o�`�A�o�a�o�̓o�b�t�@�����l
 *  ���̃s���t�@���N�V������`���Q�Ƃ��Ă�������
 */
#define	VAL_PA_DR 	(1<<10 | 1<<9 | 1<<8)	/* RTC-4553-CS=1,RTC-4553-WR=1,LEDCTL1=1(off) */
#define	VAL_PB_DR 	(1<<11 | 1<<9 | 1<<6)	/* TXD1=1,TXD0=1,LEDCTL2=1(off) */

/*
 *  PA �Œ�@�\�iPA15,14,13,12,03,01�������j
 *
 *  PNO  I/O PAIOR  PACR1/2
 *  PA15 IN   [0]    [00] �| �g���h�^�n�ɊJ��
 *  PA14 IN   [0]    [00] �| �g���h�^�n�ɊJ��
 *  PA13 IN   [0]    [00] �| �g���h�^�n�ɊJ��
 *  PA12 IN   [0]    [00] �| �g���h�^�n�ɊJ��
 *  PA11 IN   [0]    [00] �| RTC-4553-SOUT
 *  PA10 OUT  [1]    [00] �| RTC-4553-CS[active-low]
 *  PA09 OUT  [1]    [00] �| RTC-4553-WR[active-low]
 *  PA08 OUT  [1]    [10] �| LEDCTL1 LED1����[active-low]
 *  PA07 IN   [0]    [10] �| ���g�p
 *  PA06 �|   [0]    [11] �| RD �Ɋ��蓖�ā|
 *  PA05 OUT  [1]    [10] �| WD-PULSE �E�H�b�`�h�b�N���Z�b�g�p���X�����Q�ɂ�
 *  PA04 �|   [0]    [11] �| WR �Ɋ��蓖��
 *  PA03 �|   [0]    [00] �| �g���h�^�n�ɊJ��
 *  PA02 �|   [0]    [01] �| CS6 �Ɋ��蓖�āi�k�`�m�R���g���[���p�j
 *  PA01 �|   [0]    [00] �| �g���h�^�n�ɊJ��
 *  PA00 �|   [0]    [01] �| CS4 �Ɋ��蓖�āiROMICE �p�j
 */
#define	PAIOR_BASE	0x0720
#define	PACR1_BASE	0x0002
#define	PACR2_BASE	0xbb11

#if PA15_PORT_IN == 1
#define	PA15MD			0	/* �ėp���̓|�[�g		PI15	*/
#define	PA15IOR			0
#endif
#if PA15_PORT_OUT == 1
#ifdef PA15MD
#error : 'PA15MD' redefined.
#endif
#define	PA15MD			0	/* �ėp�o�̓|�[�g		PO15	*/
#define	PA15IOR			1
#endif
#if PA15_IRQ3 == 1
#ifdef PA15MD
#error : 'PA15MD' redefined.
#endif
#define	PA15MD			1	/* ���荞�ݗv������		IRQ3	*/
#define	PA15IOR			0
#endif
#if PA15_DREQ1 == 1
#ifdef PA15MD
#error : 'PA15MD' redefined.
#endif
#define	PA15MD			3	/* �c�l�`�]���v������		DREQ1	*/
#define	PA15IOR			0
#endif
#ifndef	PA15MD
#error : 'PA15MD' is not set up.
#endif

#if PA14_PORT_IN == 1
#define	PA14MD			0	/* �ėp���̓|�[�g		PI14	*/
#define	PA14IOR			0
#endif
#if PA14_PORT_OUT == 1
#ifdef PA14MD
#error : 'PA14MD' redefined.
#endif
#define	PA14MD			0	/* �ėp�o�̓|�[�g		PO14	*/
#define	PA14IOR			1
#endif
#if PA14_IRQ2 == 1
#ifdef PA14MD
#error : 'PA14MD' redefined.
#endif
#define	PA14MD			1	/* ���荞�ݗv������		IRQ2	*/
#define	PA14IOR			0
#endif
#if PA14_DACK1 == 1
#ifdef PA14MD
#error : 'PA14MD' redefined.
#endif
#define	PA14MD			3	/* �c�l�`�]���v����t�o��	DACK1	*/
#define	PA14IOR			0
#endif
#ifndef PA14MD
#error : 'PA14MD' is not set up.
#endif

#if PA13_PORT_IN == 1
#define	PA13MD			0	/* �ėp���̓|�[�g		PI13	*/
#define	PA13IOR			0
#endif
#if PA13_PORT_OUT == 1
#ifdef PA13MD
#error : 'PA13MD' redefined.
#endif
#define	PA13MD			0	/* �ėp�o�̓|�[�g		PO13	*/
#define	PA13IOR			1
#endif
#if PA13_IRQ1 == 1
#ifdef PA13MD
#error : 'PA13MD' redefined.
#endif
#define	PA13MD			1	/* ���荞�ݗv������		IRQ1	*/
#define	PA13IOR			0
#endif
#if PA13_TCLKB == 1
#ifdef PA13MD
#error : 'PA13MD' redefined.
#endif
#define	PA13MD			2	/* �h�s�t�^�C�}�N���b�N����	TCLKB	*/
#define	PA13IOR			0
#endif
#if PA13_DREQ0 == 1
#ifdef PA13MD
#error : 'PA13MD' redefined.
#endif
#define	PA13MD			3	/* �c�l�`�]���v������		DREQ0	*/
#define	PA13IOR			0
#endif
#ifndef PA13MD
#error : 'PA13MD' is not set up.
#endif

#if PA12_PORT_IN == 1
#define	PA12MD			0	/* �ėp���̓|�[�g		PI12	*/
#define	PA12IOR			0
#endif
#if PA12_PORT_OUT == 1
#ifdef PA12MD
#error : 'PA12MD' redefined.
#endif
#define	PA12MD			0	/* �ėp�o�̓|�[�g		PO12	*/
#define	PA12IOR			1
#endif
#if PA12_IRQ0 == 1
#ifdef PA12MD
#error : 'PA12MD' redefined.
#endif
#define	PA12MD			1	/* ���荞�ݗv������		IRQ0	*/
#define	PA12IOR			0
#endif
#if PA13_TCLKA == 1
#ifdef PA12MD
#error : 'PA12MD' redefined.
#endif
#define	PA12MD			2	/* �h�s�t�^�C�}�N���b�N����	TCLKA	*/
#define	PA12IOR			0
#endif
#if PA13_DACK0 == 1
#ifdef PA12MD
#error : 'PA12MD' redefined.
#endif
#define	PA12MD			3	/* �c�l�`�]���v����t�o��	DACK0	*/
#define	PA12IOR			0
#endif
#ifndef PA12MD
#error : 'PA12MD' is not set up.
#endif

#if PA03_PORT_IN == 1
#define	PA03MD			0	/* �ėp���̓|�[�g		PI03	*/
#define	PA03IOR			0
#endif
#if PA03_PORT_OUT == 1
#ifdef PA03MD
#error : 'PA03MD' redefined.
#endif
#define	PA03MD			0	/* �ėp�o�̓|�[�g		PO03	*/
#define	PA03IOR			1
#endif
#if PA03_CS7 == 1
#ifdef PA03MD
#error : 'PA03MD' redefined.
#endif
#define	PA03MD			1	/* �`�b�v�Z���N�g�V�o��		CS7	*/
#define	PA03IOR			0
#endif
#if PA03_WAIT == 1
#ifdef PA03MD
#error : 'PA03MD' redefined.
#endif
#define	PA03MD			2	/* �E�G�C�g�X�e�[�g����		WAIT	*/
#define	PA03IOR			0
#endif
#ifndef PA03MD
#error : 'PA03MD' is not set up.
#endif

#if PA01_PORT_IN == 1
#define	PA01MD			0	/* �ėp���̓|�[�g		PI01	*/
#define	PA01IOR			0
#endif
#if PA01_PORT_OUT == 1
#ifdef PA01MD
#error : 'PA01MD' redefined.
#endif
#define	PA01MD			0	/* �ėp�o�̓|�[�g		PO01	*/
#define	PA01IOR			1
#endif
#if PA01_CS5 == 1
#ifdef PA01MD
#error : 'PA01MD' redefined.
#endif
#define	PA01MD			1	/* �`�b�v�Z���N�g�T�o��		CS5	*/
#define	PA01IOR			0
#endif
#if PA01_RAS == 1
#ifdef PA01MD
#error : 'PA01MD' redefined.
#endif
#define	PA01MD			2	/* ���E�A�h���X�X�g���[�u�o��	RAS	*/
#define	PA01IOR			0
#endif
#ifndef PA01MD
#error : 'PA01MD' is not set up.
#endif

/*
 *  �|�[�g�`�s���t�@���N�V������`
 */
#define VAL_PFC_PAIOR   (PAIOR_BASE | PA15IOR<<15 | PA14IOR<<14 | PA13IOR<<13 | PA12IOR<<12 | PA03IOR<<3 | PA01IOR<<1)
#define VAL_PFC_PACR1   (PACR1_BASE | PA15MD<<14  | PA14MD<<12  | PA13MD<<10  | PA12MD<<8)
#define VAL_PFC_PACR2   (PACR2_BASE | PA03MD<<6   | PA01MD<<2)

/*
 *  �|�[�g�a�s���t�@���N�V������`
 */
#define VAL_PFC_PBIOR   0x107b
#define VAL_PFC_PBCR1   0x14aa
#define VAL_PFC_PBCR2   0x0000
 /*
 *  PNO  I/O PBIOR  PBCR1/2
 *  PB15 IN   [0]    [00] �| ���g�p IRQ7 �Ɋ��蓖�āi�q�s�b�p�j
 *  PB14 �|   [0]    [01] �| IRQ6 �Ɋ��蓖�āi�t�r�a�R���g���[���p�j
 *  PB13 �|   [0]    [01] �| IRQ5 �Ɋ��蓖�āi�k�`�m�R���g���[���p�j
 *  PB12 OUT  [1]    [00] �| LEDCTL3 LED3 ����[active-low]
 *  PB11 �|   [0]    [10] �| TDX1 �Ɋ��蓖�āiRS485 �f�[�^�o�́j
 *  PB10 �|   [0]    [10] �| RDX1 �Ɋ��蓖�āiRS485 �f�[�^���́j
 *  PB09 �|   [0]    [10] �| TDX0 �Ɋ��蓖�āiRS-232C �f�[�^�o�́j
 *  PB08 �|   [0]    [10] �| RDX0 �Ɋ��蓖�āiRS-232C �f�[�^���́j
 *  PB07 IN   [0]    [00] �| �V���A��EEPROM-DO
 *  PB06 OUT  [1]    [00] �| LEDCTL2 LED2 ����[active-low]
 *  PB05 OUT  [1]    [00] �| TXE0 RS485 ���M�C�l�[�u���o�͑��M��~
 *  PB04 OUT  [1]    [00] �| �V���A��EEPROM-CS[active-high]
 *  PB03 OUT  [1]    [00] �| CTS0 RS232C ��CTS �M���i�������j
 *  PB02 IN   [0]    [00] �| RTS0 RS232C ��RTS �M���i�������j
 *  PB01 OUT  [1]    [00] �| �V���A��EEPROM-SK�ARTC-4553-SCK
 *  PB00 OUT  [1]    [00] �| �V���A��EEPROM-DI�ARTC-4553-SIN
 *
 *  PBIOR=0x107b
 *  PBCR1=0x14aa
 *  PBCR2=0x0000
 *
 */

/*
 *  �J�����A�h���X�X�g���[�u�s���R���g���[����`
 */
#define VAL_PFC_CASCR   0x5fff

#ifndef _MACRO_ONLY
/*
 * �֐��錾
 */
void	software_init_hook(void);
void	hardware_init_hook(void);

#endif /* _MACRO_ONLY */
#endif	/* _SYS_SUPPORT_H_ */


