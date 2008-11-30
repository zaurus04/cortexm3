/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005 by Freelines CO.,Ltd
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
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

/*
 * �^�[�Q�b�g�ˑ��V���A��I/O���W���[���iV850ES/SG2 �����񓯊��V���A��ch0/ch1/ch2�p�j
 *   �{�[���[�g�ݒ��SERIAL_COMPAREVALUE��ύX����B
 *   �f�[�^�t�H�[�}�b�g��8bit data, non-parity, 1stop-bit�Œ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>

/*
 *  �V���A���|�[�g�̏������u���b�N
 */

typedef struct sio_port_initialization_block {
} SIOPINIB;

/*
 *  �V���A���|�[�g�̐���u���b�N
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*inib;		/* �������u���b�N	*/
	VP_INT		exinf;		/* �g�����		*/
	BOOL		openflag;	/* �I�[�v���ς݃t���O	*/
	int			port_id;	/* �|�[�g�ԍ�(0�`) */
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ����Ǘ��u���b�N�ւ̕ϊ��}�N��
 */

#define INDEX_SIO(sioid)	((UINT)((sioid) - 1))
#define get_siopcb(sioid)	(&(siopcb_table[INDEX_SIO(sioid)]))

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */

#define SIO_ERDY_SND		1u			/* ���M�\�R�[���o�b�N			*/
#define SIO_ERDY_RCV		2u			/* ��M�ʒm�R�[���o�b�N			*/

/*
 *  �V���A���|�[�g�̃n�[�h�E�F�A�ˑ����̒�`
 */

#define SERIAL_PORT				(CONSOLE_PORTID-1)		/* �V�X�e���̃|�[�g�ԍ� */
#define SERIAL_INT_PRIORITY		1	/* ���荞�ݗD��x */
#define SERIAL_CLKDIV			3	/* clk = fxx/8     */
#define SERIAL_COMPAREVALUE		11	/* 9600bps=130, 19200bps=65, 38400bps=33, 57600bps=22, 115200bps=11 */

/* �V���A���֘A���W�X�^ */
#define UAnCTL0(x)  (UA0CTL0 + ((x) * 0x10))
#define UAnCTL1(x)  (UA0CTL1 + ((x) * 0x10))
#define UAnCTL2(x)  (UA0CTL2 + ((x) * 0x10))
#define UAnOPT0(x)  (UA0OPT0 + ((x) * 0x10))
#define UAnSTR(x)   (UA0STR  + ((x) * 0x10))
#define UAnRX(x)    (UA0RX   + ((x) * 0x10))
#define UAnTX(x)    (UA0TX   + ((x) * 0x10))
#define UAnRIC(x)	(UA0RIC  + ((x) * 0x4))
#define UAnTIC(x)	(UA0TIC  + ((x) * 0x4))

/*
 *  �V���A��I/O�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SERIAL_IN		(0x31 + (SERIAL_PORT * 2))
#define INHNO_SERIAL_OUT	(0x32 + (SERIAL_PORT * 2))


/*
 *  �჌�x���|�[�g���Ǘ��u���b�N�̏����l
 */

#define NUM_PORT	1	/* �T�|�[�g����V���A���|�[�g�̐� */

#define FLG_RECEIVED 1
#define FLG_TXRBUSY  2

extern unsigned int _serial_flag[TNUM_PORT];

/*
 *  �V���A��I/O�|�[�g�̏�����
 */
Inline BOOL
hw_port_initialize(int port_id)
{
   	_serial_flag[port_id] = 0;
	if( (sil_reb_mem((VP)UAnCTL0(port_id)) & 0x80) == 0 )
	{
    	/* �񓯊��V���A���ʐM�H�̏����� */

		sil_wrb_mem((VP)UAnCTL0(port_id), 0x80);	/* UART enable */
		/* �|�[�g���J���� */
		if (port_id == 0) {
			sil_wrh_mem((VP)PFC3, sil_reh_mem((VP)PFC3) & ~0x0003);
			sil_wrh_mem((VP)PMC3, sil_reh_mem((VP)PMC3) | 0x0003);
		} else if (port_id == 1) {
			sil_wrh_mem((VP)PFCE9, sil_reh_mem((VP)PFCE9) | 0x0003);
			sil_wrh_mem((VP)PFC9,  sil_reh_mem((VP)PFC9)  & ~0x0003);
			sil_wrh_mem((VP)PMC9,  sil_reh_mem((VP)PMC9)  | 0x0003);
		} else {
			sil_wrh_mem((VP)PFC3, sil_reh_mem((VP)PFC3) & ~0x0300);
			sil_wrh_mem((VP)PMC3, sil_reh_mem((VP)PMC3) | 0x0300);
		}
		/* �{�[���[�g������̏����� */
		sil_wrb_mem((VP)UAnCTL1(port_id), SERIAL_CLKDIV);
		sil_wrb_mem((VP)UAnCTL2(port_id), SERIAL_COMPAREVALUE);

		__asm("nop; nop");

		sil_wrb_mem((VP)UAnCTL0(port_id), sil_reb_mem((VP)UAnCTL0(port_id)) | 0x12);	/* 8bit data, non-parity, 1-stopbit */

		__asm("nop; nop");

		sil_wrb_mem((VP)UAnCTL0(port_id), sil_reb_mem((VP)UAnCTL0(port_id)) | 0x60);	/* Tx, Rx enable */

		/* �����ݐ��� */
		sil_wrb_mem((VP)UAnRIC(port_id), SERIAL_INT_PRIORITY);
		sil_wrb_mem((VP)UAnTIC(port_id), SERIAL_INT_PRIORITY);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g�̏I��
 */
Inline void
hw_port_terminate(int port_id)
{
}

/*
 *  �V���A���|�[�g�����݃T�[�r�X���[�`���i�O���Q�Ɓj
 */
extern void	serial_handler_in(int portid);
extern void	serial_handler_out(int portid);

/*
 *  ��������M�������H
 */
Inline BOOL
hw_port_getready(int port_id)
{
	return (_serial_flag[port_id] & FLG_RECEIVED) != 0 ? TRUE : FALSE;
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
hw_port_putready(int port_id)
{
//	return (sil_reb_mem((VP)UAnSTR(port_id)) & 0x80) != 0 ? FALSE : TRUE;
	return (_serial_flag[port_id] & FLG_TXRBUSY) != 0 ? FALSE : TRUE;
}

Inline BOOL
hw_port_putready2(int port_id)
{
	return (sil_reb_mem((VP)UAnSTR(port_id)) & 0x80) != 0 ? FALSE : TRUE;
//	return (_serial_flag[port_id] & FLG_TXRBUSY) != 0 ? FALSE : TRUE;
}

/*
 *  ��M���������̎��o��
 */
Inline unsigned char
hw_port_getchar(int port_id)
{
	_serial_flag[port_id] &= ~FLG_RECEIVED;
	sil_wrb_mem((VP)UAnRIC(port_id), sil_reb_mem((VP)UAnRIC(port_id)) & 0x7f);
	return sil_reb_mem((VP)UAnRX(port_id));
}

/*
 *  ���M���镶���̏�������
 */
Inline void
hw_port_putchar(int port_id, unsigned char c)
{
	sil_wrb_mem((VP)UAnTX(port_id), c);
	_serial_flag[port_id] |= FLG_TXRBUSY;
}

/*
 *  ���M���镶���̏������݁i���M�\�ɂȂ�܂ő҂j
 */
Inline void
hw_port_wait_putchar(int port_id, unsigned char c)
{
	while( !hw_port_putready2(port_id) ) ;
	hw_port_putchar(port_id, c);
}

/*
 *  ���M����֐�
 */
Inline void
hw_port_sendstart(int port_id)
{
}

Inline void
hw_port_sendstop(int port_id)
{
}

extern void	sio_ierdy_rcv(VP_INT exinf);
extern void	sio_ierdy_snd(VP_INT exinf);

Inline void
hw_port_handler_in(int port_id)
{
	_serial_flag[port_id] |= FLG_RECEIVED;
    sio_ierdy_rcv(siopcb_table[port_id].exinf);
}

Inline void
hw_port_handler_out(int port_id)
{
	_serial_flag[port_id] &= ~FLG_TXRBUSY;
	sio_ierdy_snd(siopcb_table[port_id].exinf);
}

/***********************************************************************************/

/*
 *  sio_initialize -- �V���A���|�[�g�h���C�o�̏�����
 */
Inline void
sio_initialize (void)
{
	int ix;

	/* SIO �Ǘ��u���b�N�̏����� */
	for (ix = TNUM_PORT; ix -- > 0; ) {
		siopcb_table[ix].openflag = FALSE;
	}
}

/*
 *  sio_opn_por -- �|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID sioid, VP_INT exinf)
{
	SIOPCB	*pcb;

	pcb = get_siopcb(sioid);
	pcb->inib     = NULL;
	pcb->exinf    = exinf;
	pcb->openflag = TRUE;
	pcb->port_id  = sioid-1;
	hw_port_initialize(pcb->port_id);
	return pcb;
}

/*
 *  sio_snd_chr -- �������M
 */
Inline BOOL
sio_snd_chr(SIOPCB *pcb, INT chr)
{
	if (hw_port_putready(pcb->port_id)) {
		hw_port_putchar(pcb->port_id, (UB)chr);
		return TRUE;
		}
	else
		return FALSE;
}

/*
 *  sio_rcv_chr -- ������M
 */
Inline INT
sio_rcv_chr(SIOPCB *pcb)
{
	if (hw_port_getready(pcb->port_id))
		return hw_port_getchar(pcb->port_id);
	else
		return -1;
}

/*
 *  sio_ena_cbr -- �V���A�� I/O ����̃R�[���o�b�N�̋���
 */
Inline void
sio_ena_cbr(SIOPCB *pcb, UINT cbrtn)
{
}

/*
 *  sio_dis_cbr -- �V���A�� I/O ����̃R�[���o�b�N�̋֎~
 */
Inline void
sio_dis_cbr(SIOPCB *pcb, UINT cbrtn)
{
}

/*
 *  sio_cls_por -- �|�[�g�̃N���[�Y
 */
Inline void
sio_cls_por(SIOPCB *pcb)
{
	sio_dis_cbr(pcb, SIO_ERDY_SND);
	sio_dis_cbr(pcb, SIO_ERDY_RCV);
	pcb->openflag = FALSE;
}

Inline void
sio_in_handler(void)
{
	hw_port_handler_in(0);
}

Inline void
sio_out_handler(void)
{
	hw_port_handler_out(0);
}

#if TNUM_PORT > 1
Inline void
sio_in_handler2(void)
{
	hw_port_handler_in(1);
}

Inline void
sio_out_handler2(void)
{
	hw_port_handler_out(1);
}
#endif

#endif /* _HW_SERIAL_H_ */
