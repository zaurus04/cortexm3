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
 *  @(#) $Id: hw_serial.c,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *	�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iM32102�����񓯊��V���A���p�j
 */

#include <sil.h>
#include <hw_serial.h>

#include <cpu_rename.h>
#include <sys_rename.h>

SIOPCB siopcb_table[TNUM_PORT];

extern FP InterruptHandlerEntry[];

/* 
 *  ��Ɨp�֐� 
 */
#define ID_PORT(x)		((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])

/*
 *  �V���A���|�[�g�̏�����
 */
void
sio_initialize(void)
{
	int i;

	for(i=0;i<TNUM_PORT;i++)
	{
		siopcb_table[i].flags = SIO_TYP_M32RUART;
		siopcb_table[i].port  = i;
		siopcb_table[i].exinf = 0;

		InterruptHandlerEntry[INT_SIO0RCV + (siopcb_table[i].port * 2) - 1] = sio_handler_in;
		InterruptHandlerEntry[INT_SIO0XMT + (siopcb_table[i].port * 2) - 1] = sio_handler_out;
	}
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB * siopcb = GET_SIOPCB(siopid);

	siopcb->exinf = exinf;

	switch(SIO_TYP(siopcb->flags)) {
	case SIO_TYP_M32RUART:

		/* UART������ */
		sil_wrb_mem((void *)(SIOCR(siopcb->port)+3), 0);

		/* �|�[�g���J��(UART0) */
		sil_wrb_mem((void *)PDATA(5), 0);
		sil_wrb_mem((void *)PDIR(5),  0x80);

		/* UART, Non-parity, 1 stop-bit */
		sil_wrb_mem((void *)(SIOMOD0(siopcb->port)+3), 0);

		/* 8bit, internal clock */
		sil_wrh_mem((void *)(SIOMOD1(siopcb->port)+2), 0x0800);

		/* M32R(32102) - f(BLK)=16MHz��115200bps */
		sil_wrh_mem((void *)(SIOBAUR(siopcb->port)+2), SERIAL_CLKDIV);
		sil_wrb_mem((void *)(SIORBAUR(siopcb->port)+3), SERIAL_CLKCMP);

		/* ����M�����ݔ������� */
		sil_wrh_mem((void *)(SIOTRCR(siopcb->port)+2), 0x0006);

		/* �X�e�[�^�X�N���A, ����M����J�n */
		sil_wrb_mem((void *)(SIOCR(siopcb->port)+2), 0x3);
		sil_wrb_mem((void *)(SIOCR(siopcb->port)+3), 0x3);

		/* ��M�����ݎ�t���� */
		sil_wrh_mem((void *)(ICUCR(SIO,siopcb->port)+2), 0x1000);
		sil_wrh_mem((void *)(ICUCR(SIO,siopcb->port)+6), 0x1000);

		/* TxD,RxD�s���L��(UART0) */
		sil_wrh_mem((void *)PMOD(5), 0x5500);

		break;
	}

	return siopcb;
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
sio_cls_por(SIOPCB *siopcb)
{
	switch(SIO_TYP(siopcb->flags))
	{
	case SIO_TYP_M32RUART:
		/* ����M������֎~���� */
		sil_wrb_mem((void *)(SIOCR(siopcb->port)+3), 0);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT sio_rcv_chr(SIOPCB * siopcb)
{
	switch(SIO_TYP(siopcb->flags))
	{
	case SIO_TYP_M32RUART:
		return sil_reb_mem((void *)(SIORXB(siopcb->port)+3));
	}

	return -1;
}


/*
 *  ��������M���������`�F�b�N
 */

inline BOOL
hw_port_getready(SIOPCB *p)
{
	switch(SIO_TYP(p->flags))
	{
	case SIO_TYP_M32RUART:
		return (sil_reb_mem((void *)(SIOSTS(p->port)+3)) & 0x4) != 0 ? TRUE : FALSE;
	}
	return FALSE;
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N����
 */
void sio_ena_cbr(SIOPCB * siopcb, UINT cbrtn)
{}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�֎~
 */
void sio_dis_cbr(SIOPCB * siopcb, UINT cbrtn)
{}

void sio_handler_in(void)
{
	int port;

	for(port = 0; port < TNUM_PORT; ++ port)
	{
		if( hw_port_getready(&siopcb_table[port]) == TRUE )
			sio_ierdy_rcv(GET_SIOPCB(ID_PORT(port))->exinf);
	}
}

void sio_handler_out(void)
{
	int port;

	for(port = 0; port < TNUM_PORT; ++ port)
	{
		if((siopcb_table[port].flags & SIO_STS_SENDING) != 0)
		{
			/* ���M�X�e�[�^�X������ */
			sil_wrb_mem((void *)(SIOCR(port)+2), 0x1);
			siopcb_table[port].flags &= ~SIO_STS_SENDING;

			sio_ierdy_snd(GET_SIOPCB(ID_PORT(port))->exinf);
		}
	}
}
