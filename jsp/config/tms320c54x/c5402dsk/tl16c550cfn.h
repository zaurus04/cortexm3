/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: tl16c550cfn.h,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

/*
 * TL16C550CFN�p �Ȉ�SIO�h���C�o
 */
#ifndef _TL16C550CFN_H_
#define _TL16C550CFN_H_

#include <t_config.h>

/***********************************************
 *  I/O  �������E�}�b�v�h�E���W�X�^            *
***********************************************/
/*
 *  complex Programmable Logic Device (CPLD)   *
 *  I/O �������E�}�b�v�h�E���W�X�^                 *
 */

/*  ���W�X�^�@�A�h���X�@*/
#ifndef _MACRO_ONLY
volatile ioport UH	port0;
volatile ioport UH	port1;
volatile ioport UH	port2;
volatile ioport UH	port3;
volatile ioport UH	port4;
volatile ioport UH	port5;
volatile ioport UH	port6;
#endif /* _MACRO_ONLY */

/*  CPLD�@���W�X�^ */
#define CPLD_CTRL1	port0
#define CPLD_STAT	port1
#define CPLD_DMCTRL	port2
#define CPLD_DBIO	port3
#define CPLD_CTRL2	port4
#define CPLD_SEM0	port5
#define CPLD_SEM1	port6

/*
 *  UART I/O �������E�}�b�v�h�E���W�X�^ *
 */
/*  ���W�X�^ �A�h���X */
#ifndef _MACRO_ONLY
volatile ioport UH	port4000;
volatile ioport UH	port4001;
volatile ioport UH	port4002;
volatile ioport UH	port4003;
volatile ioport UH	port4004;
volatile ioport UH	port4005;
volatile ioport UH	port4006;
volatile ioport UH	port4007;
#endif /* _MACRO_ONLY */

/*  UART ���W�X�^  */
#define UART_RBR	port4000
#define UART_THR	port4000
#define UART_IER	port4001
#define UART_IIR	port4002
#define UART_FCR	port4002
#define UART_LCR	port4003
#define UART_MCR	port4004
#define UART_LSR	port4005
#define UART_MSR	port4006
#define UART_SCR	port4007
/*
 *  �ȉ��̃��W�X�^�ɃA�N�Z�X����O�ɁA
 *  DLAB=1 (b7 of LCR) ���Z�b�g����K�v������
 */
#define UART_DLL	port4000
#define UART_DLM	port4001

/*
 *  �r�b�g�t�B�[���h�̒�`
 */
#define FCR_FIFO	0x01
#define FCR_RFRST	0x02
#define FCR_TFRST	0x04
#define FIFO_TRIG	0x00

#define LCR_DLAB	0x80

/* ��M���M���荞�݂̒�` */
#define IER_ERBI	0x01  /* ��M���荞�� */
#define IER_RIE		IER_ERBI 
#define IER_ETBEI	0x02  /* ���M���荞�� */
#define IER_TIE		IER_ETBEI

#define LSR_DR		0x01
#define LSR_THRE	0x20
#define LSR_TEMT	0x40

#define IIR_RXINT	0x04
#define IIR_TXINT	0x02

/*
 *  UART�̃{�[���[�g�̐ݒ�
 */
/*
 * BAUD RATE 2 : 115200 bps
 * BAUD RATE 4 : 57600  bps
 */
#define UART_BAUD_RATE    2



#ifndef _MACRO_ONLY

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block {
	VP	dummy;
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*siopinib;  /* �V���A��I/O�|�[�g�������u���b�N */
	VP_INT	exinf;			/* �g����� */
	BOOL	openflag;		/* �I�[�v���ς݃t���O */
	BOOL	getready;		/* ��������M������� */
	BOOL	putready;		/* ��������M�ł����� */
} SIOPCB;

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND    1u              /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u              /* ��M�ʒm�R�[���o�b�N */

/*
 * �J�[�l���N�����p�̏�����(sys_putc���g�p���邽��)
 */
extern void	uart_init(void);

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void	uart_initialize(void);

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL	uart_openflag(void);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB	*uart_opn_por(ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void	uart_cls_por(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL	uart_snd_chr(SIOPCB *siopcb, char chr);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT	uart_rcv_chr(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void	uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void	uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void	uart_isr(void);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void	uart_ierdy_snd(VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void	uart_ierdy_rcv(VP_INT exinf);

/* �|�[�����O�ŃV���A���ɑ��M */
Inline char
uart_putc(char c)
{
	while ((UART_LSR & LSR_THRE) == 0);      /*  ���M���W�X�^���󂩂ǂ���  */
	UART_THR = c;
	return(c);
}

#endif /* _MACRO_ONLY */

#endif /* _TL16C550CFN_H_ */
