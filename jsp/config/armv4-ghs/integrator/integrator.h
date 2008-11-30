/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by Advanced Data Controls, Corp
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
 *  @(#) $Id: integrator.h,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_

#ifndef _MACRO_ONLY
#include <itron.h>
#include <sil.h>
#endif /* _MACRO_ONLY */

#include "armv4.h"
#include "sys_config.h"
#include "cpu_config.h"


/*
 * Interrupt controller
 */

#define IRQ_BASE_REG    0x14000000
#define IRQ0_STATUS     (IRQ_BASE_REG)
#define IRQ0_RAWSTAT    (IRQ_BASE_REG + 0x04)
#define IRQ0_ENABLESET  (IRQ_BASE_REG + 0x08)
#define IRQ0_ENABLECLR  (IRQ_BASE_REG + 0x0c)

#define IRQ_EXTINT_BIT		0x15
#define IRQ_PCILBINT_BIT	0x14
#define IRQ_ENUMINT_BIT		0x13
#define IRQ_DEGINT_BIT		0x12
#define IRQ_LINT_BIT		0x11
#define IRQ_PCIINT3_BIT		0x10
#define IRQ_PCIINT2_BIT		0x0f
#define IRQ_PCIINT1_BIT		0x0e
#define IRQ_PCIINT0_BIT		0x0d
#define IRQ_EXPINT3_BIT		0x0c
#define IRQ_EXPINT2_BIT		0x0b
#define IRQ_EXPINT1_BIT		0x0a
#define IRQ_EXPINT0_BIT		0x09
#define IRQ_RTCINT_BIT		0x08
#define IRQ_TM2_BIT		0x07
#define IRQ_TM1_BIT		0x06
#define IRQ_TM0_BIT		0x05
#define IRQ_MOUSEINT_BIT	0x04
#define IRQ_KBDINT_BIT		0x03
#define IRQ_UART1_BIT   	0x02
#define IRQ_UART0_BIT		0x01
#define IRQ_SOFTINT_BIT 	0x00

#define IRQ_EXTINT	(1 << IRQ_EXTINT_BIT)
#define IRQ_PCILBIN	(1 << IRQ_PCILBIN_BIT)
#define IRQ_ENUMINT	(1 << IRQ_ENUMINT_BIT)
#define IRQ_DEGINT	(1 << IRQ_DEGINT_BIT)
#define IRQ_LINT	(1 << IRQ_LINT_BIT)
#define IRQ_PCIINT3	(1 << IRQ_PCIINT3_BIT)
#define IRQ_PCIINT2	(1 << IRQ_PCIINT2_BIT)
#define IRQ_PCIINT1	(1 << IRQ_PCIINT1_BIT)
#define IRQ_PCIINT0	(1 << IRQ_PCIINT0_BIT)
#define IRQ_EXPINT3	(1 << IRQ_EXPINT3_BIT)
#define IRQ_EXPINT2	(1 << IRQ_EXPINT2_BIT)
#define IRQ_EXPINT1	(1 << IRQ_EXPINT1_BIT)
#define IRQ_EXPINT0	(1 << IRQ_EXPINT0_BIT)
#define IRQ_RTCINT	(1 << IRQ_RTCINT_BIT)
#define IRQ_TM2		(1 << IRQ_TM2_BIT)
#define IRQ_TM1		(1 << IRQ_TM1_BIT)
#define IRQ_TM0		(1 << IRQ_TM0_BIT)
#define IRQ_MOUSEINT	(1 << IRQ_MOUSEINT_BIT)
#define IRQ_KBDINT	(1 << IRQ_KBDINT_BIT)
#define IRQ_UART1	(1 << IRQ_UART1_BIT)
#define IRQ_UART0	(1 << IRQ_UART0_BIT)
#define IRQ_SOFTINT	(1 << IRQ_SOFTINT_BIT)


/*Interrupt Mask
 *Timer2�͍ō��D��x������ ??
 *
 */
#define MASK_IRQ_TM2         0x3FFFFF
#define MASK_IRQ_TM1         0x3FFF7F
#define MASK_IRQ_TM0         0x3FFF3F
#define MASK_IRQ_MOUSEINT    0x3FFF1F
#define MASK_IRQ_KBDINT      0x3FFF0F
#define MASK_IRQ_UART1       0x3FFF07
#define MASK_IRQ_UART0       0x3FFF03
#define MASK_IRQ_SOFTINT     0x3FFF01

#define MASK_IRQ_EXTINT         0x3FFF00
#define MASK_IRQ_PCILBINT       0x1FFF00
#define MASK_IRQ_ENUMINT        0x0FFF00
#define MASK_IRQ_DEGINT         0x07FF00
#define MASK_IRQ_LINT           0x03FF00
#define MASK_IRQ_PCIINT3        0x01FF00
#define MASK_IRQ_PCIINT2        0x00FF00
#define MASK_IRQ_PCIINT1        0x007F00
#define MASK_IRQ_PCIINT0        0x003F00
#define MASK_IRQ_EXPINT3        0x001F00
#define MASK_IRQ_EXPINT2        0x000F00
#define MASK_IRQ_EXPINT1        0x000700
#define MASK_IRQ_EXPINT0        0x000300
#define MASK_IRQ_RTCINT         0x000100

#define INT_DISABLE_ALL    0x3FFFFF

#define TIMER_BASE_REG     0x13000000
#define IRQ0_BASE_REG      0x14000000
#define UART0_BASE_REG     0x16000000
#define UART1_BASE_REG    0x17000000

/*UART0 Base Reg*/

#define UART0_DR    (UART0_BASE_REG)
#define UART0_RSR   (UART0_BASE_REG + 0x04)
#define UART0_ECR   (UART0_BASE_REG + 0x04)
#define UART0_LCRH  (UART0_BASE_REG + 0x08)
#define UART0_LCRM  (UART0_BASE_REG + 0x0C)
#define UART0_LCRL  (UART0_BASE_REG + 0x10)
#define UART0_CR    (UART0_BASE_REG + 0x14)
#define UART0_FR    (UART0_BASE_REG + 0x18)
#define UART0_IIR   (UART0_BASE_REG + 0x1C)
#define UART0_ICR   (UART0_BASE_REG + 0x1C)


/*
 *UART1 Control Registers
 */

#define UART1_DR    (UART1_BASE_REG)
#define UART1_RSR   (UART1_BASE_REG + 0x04)
#define UART1_ECR   (UART1_BASE_REG + 0x04)
#define UART1_LCRH  (UART1_BASE_REG + 0x08)
#define UART1_LCRM  (UART1_BASE_REG + 0x0C)
#define UART1_LCRL  (UART1_BASE_REG + 0x10)
#define UART1_CR    (UART1_BASE_REG + 0x14)
#define UART1_FR    (UART1_BASE_REG + 0x18)
#define UART1_IIR   (UART1_BASE_REG + 0x1C)
#define UART1_ICR   (UART1_BASE_REG + 0x1C)



/*Receive Error Constants:UARTx_RSR*/

#define URSR_OVERRUN  0x8
#define URSR_BREAK    0x4
#define URSR_PARITY   0x2
#define URSR_FRAMING  0x1

/*---Line Control Constants: UARTx_LCRH---*/
/*[6:5] Word Length*/
#define ULCRH_WLEN_8BIT      	0x60
#define ULCRH_WLEN_7BIT      	0x40
#define ULCRH_WLEN_6BIT     	0x20
#define ULCRH_WLEN_5BIT      	0x00
/*[4] FIFO*/
#define ULCRH_FEN    	0x10
/*[3] Stop Bit*/
#define ULCRH_STP2	0x08
/*[2] Even Parity Select*/
#define ULCRH_EPS 	0x04
/*[1] Parity Enable*/
#define ULCRH_PEN	0x02
/*[0] Send Break*/
#define ULCRH_BRK	0x01
/*--------------------------------------*/

/*Line Control Constants: UARTx_LCRM*/
/*[7:0] Baud Rate*/

#define ULCRM_460800	0x00
#define ULCRL_460800	0x01

#define ULCRM_230400	0x00
#define ULCRL_230400	0x03

#define ULCRM_115200	0x00
#define ULCRL_115200	0x07

#define ULCRM_76800	0x00
#define ULCRL_76800	0x0B

#define ULCRM_57600	0x00
#define ULCRL_57600	0x0F

#define ULCRM_38400  0x0
#define ULCRL_38400  0x17

#define ULCRM_19200  0x00
#define ULCRL_19200  0x2F

#define ULCRM_14400	0x00
#define ULCRL_14400	0x3F

#define ULCRM_9600	0x0
#define ULCRL_9600	0x5F

#define ULCRM_2400	0x00
#define ULCRL_2400	0x7F

#define ULCRM_1200	0x00
#define ULCRL_1200	0xFF


/*Control Register Constants: UARTx_CR*/
/*[7] Loop Back Enable*/
#define UCR_LBE		0x80
/*[6] Receive Timeout Interrupt Enable*/
#define UCR_RTIE	0x40
/*[5] Transmit Interrupt Enable*/
#define UCR_TIE		0x20
/*[4] Receive Interrupt Enable*/
#define UCR_RIE		0x10
/*[3] Modem Status Interrupt Enable*/
#define UCR_MSIE	0x08
/*[0] UART Enable*/
#define UCR_UARTEN	0x01

/*Flag Register Constants UARTx_FR*/
/*[7] Transmit FIFO Empty*/
#define UFR_TXFE	0x80
/*[6] Receive FIFO Full*/
#define UFR_RXFF	0x40
/*[5] Transmit FIFO Full*/
#define UFR_TXFF	0x20
/*[4] Receive FIFO Empty*/
#define UFR_RXFE	0x10
/*[3] UART Busy*/
#define UFR_BUSY	0x08
/*[2] Data Carrier Detect*/
#define UFR_DCD		0x04
/*[1] Data Set Ready*/
#define UFR_DSR		0x02
/*[0] Clear To Send*/
#define UFR_CTS		0x01

/*Interrupt Identifier Constants: UARTx_IIR*/
/*[3] Receive Timeout Interrupt Status*/
#define IIR_TRIS	0x08
/*[2] Transmit Interrupt Status*/
#define IIR_TIS		0x04
/*[1] Receive Interrupt Status*/
#define IIR_RIS		0x02
/*[0] Modem Interrupt Status*/
#define IIR_MIS		0x01


#ifndef _MACRO_ONLY
/*
 * ����UART�p �Ȉ�SIO�h���C�o
 */
/*
 * �J�[�l���N�����p�̏�����(sys_putc���g�p���邽��)
 */
extern void uart_init(void);

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block 
{
    VP uart_data;
    VP uart_control;
    VP linectrl_lo;
    VP linectrl_mid;
    VP linectrl_hi;
    VP int_identifier;
    VP flag_register;
    VW irq_bit;
}
SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
typedef struct sio_port_control_block 
{
    const SIOPINIB  *siopinib;  /* �V���A��I/O�|�[�g�������u���b�N */
    VP_INT          exinf;       /* �g����� */
    BOOL    openflag;       /* �I�[�v���ς݃t���O */
    BOOL    sendflag;     /* ���M�����݃C�l�[�u���t���O */
    BOOL    getready;     /* ��������M������� */
    BOOL    putready;        /* �����𑗐M�ł����� */

}SIOPCB;




/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND    1u      /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u      /* ��M�ʒm�R�[���o�b�N */

/*
 *  �I���`�b�v��UART����̃|�[�����O�o��
 */
extern void uart_putc(char c);

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void uart_initialize(void);

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL uart_openflag(void);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB   *uart_opn_por(ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void uart_cls_por(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL uart_snd_chr(SIOPCB *siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT  uart_rcv_chr(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void uart_in_isr(void);
extern void uart_out_isr(void);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void uart_ierdy_snd(VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void uart_ierdy_rcv(VP_INT exinf);



#endif /* _MACRO_ONLY */

/*
 *   TM controller
 */

#define TIMER_BASE_REG     0x13000000

/*timer 1*/
#define TM1_LOAD  (TIMER_BASE_REG + 0x100)
#define TM1_VAL   (TIMER_BASE_REG + 0x104)
#define TM1_CTRL  (TIMER_BASE_REG + 0x108)
#define TM1_CLR   (TIMER_BASE_REG + 0x10c)

/*timer 0*/
#define TM2_LOAD   (TIMER_BASE_REG + 0x200)
#define TM2_VAL    (TIMER_BASE_REG + 0x204)
#define TM2_CTRL   (TIMER_BASE_REG + 0x208)
#define TM2_CLR    (TIMER_BASE_REG + 0x20C)

/*Timer Constants*/
#define TCTRL_STOP 0x0 
/*start bit (7th bit) enabled
 *periodic bit (6th bit) enabled
 */
#define TCTRL_START 0xC0
#define TCLR_CLEAR 0x01

#define  TCTRL_D016  0x04
#define  TCTRL_D256 0x08


/*disable timer1 interrupt*/
#define TCLR_DISABLE 0x20
/*-------------------------------------------------*/

/*�L���b�V���ݒ�FARM920T*/
#define ICACHE_ENABLE_BIT 12
#define RESERVED_BIT      6

#define CACHE_ENABLE 0x1078
#endif  /*  _INTEGRATOR_H_ */
