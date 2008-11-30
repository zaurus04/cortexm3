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
 *  �^�[�Q�b�g�ˑ��V���A��I/O���W���[��
 */

#include "jsp_kernel.h"
#include "hw_serial.h"

/*
 *  �V���A���|�[�g�̏������u���b�N
 */

const SIOPINIB siopinib_table[TNUM_PORT] = {

	{
		0,
		S1C33_INHNO_SERIAL0ERR,
		S1C33_INHNO_SERIAL0RX,
		S1C33_INHNO_SERIAL0TX,
	},
#if TNUM_PORT == 2
	{
		1,
		S1C33_INHN1_SERIAL0ERR,
		S1C33_INHN1_SERIAL0RX,
		S1C33_INHN1_SERIAL0TX,
	},
#endif	/* of #if TNUM_PORT == 2 */
};


/*
 *  �V���A���|�[�g�̐���u���b�N
 */

SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ����Ǘ��u���b�N�ւ̕ϊ��}�N��
 */
#define get_siopinib(sioid)	(&(siopinib_table[INDEX_SIO(sioid)]))
#define get_siopcb(sioid)	(&(siopcb_table[INDEX_SIO(sioid)]))

/*
 *  ��M���荞�݃T�[�r�X���[�`��.
 */

void
sio_in_service(ID sioid)
{
	SIOPCB	*pcb;

	sio_clr_errflag(INDEX_SIO(sioid));
	pcb = get_siopcb(sioid);
	if (pcb->rx_cbrflag){
		/* ��M�\�R�[���o�b�N���[�`�����ďo���B*/
		sio_ierdy_rcv(pcb->exinf);
	}
}

/*
 *  ���M�������荞�݃T�[�r�X���[�`��
 */

void
sio_out_service(ID sioid)
{
	SIOPCB	*pcb;

	pcb = get_siopcb(sioid);
	if (pcb->tx_cbrflag){
		/* ���M�\�R�[���o�b�N���[�`�����ďo���B*/
		sio_ierdy_snd(pcb->exinf);
	}
}

#ifdef SIO_ERR_HANDLER

/*
 *  ��M�G���[���荞�݃T�[�r�X���[�`��
 */

void
sio_err_service(ID sioid)
{
	SIOPCB	*pcb;
	UB	status;

	/* �G���[�t���O���N���A */
	sio_clr_errflag(INDEX_SIO(sioid));

	/* �|�[�g���ēx���������� */
	sio_opn_por(sioid, (VP_INT)NULL);
}

#endif	/* of #ifdef SIO_ERR_HANDLER */

/*
 *  �V���A���|�[�g����e�[�u��������
 */

void
sio_initialize (void)
{
	int iLoop;

	/*
	 *  SIO ����u���b�N�̏�����
	 */
	for (iLoop = 0 ; iLoop < TNUM_PORT ; iLoop++ ) {
		siopcb_table[iLoop].inib     = &siopinib_table[iLoop];
		siopcb_table[iLoop].exinf    = (VP_INT)NULL;
		siopcb_table[iLoop].openflag = FALSE;
		siopcb_table[iLoop].tx_cbrflag  = FALSE;
		siopcb_table[iLoop].rx_cbrflag  = FALSE;
	}
}

/*
 *  �R�[���o�b�N��������
 */
void
sio_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ch_no, sio_ctl;

	ch_no  = siopcb->inib->ch_no;
	sio_ctl = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bControl;
	switch (cbrtn){
	case	SIO_ERDY_SND:
		siopcb->tx_cbrflag = TRUE;
		break;
	case	SIO_ERDY_RCV:
		siopcb->rx_cbrflag = TRUE;
		break;
	}

	return;
}

/*
 *  �R�[���o�b�N���֎~����
 */
void
sio_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ch_no, sio_ctl;

	ch_no  = siopcb->inib->ch_no;
	sio_ctl = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bControl;
	switch (cbrtn){
	case	SIO_ERDY_SND:
		siopcb->tx_cbrflag = FALSE;
		break;
	case	SIO_ERDY_RCV:
		siopcb->rx_cbrflag = FALSE;
		break;
	}

	/*
	 *  ���M�@�\�L���r�b�g��ݒ肷��
	 */
	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bControl = sio_ctl;

	return;
}

/*
 *  SIO ���荞��
 */

void
sio_in_handler (void)
{
	sio_clr_factor(SIO_INT_RCV);
	sio_in_service(1);
}

void
sio_out_handler (void)
{
	sio_clr_factor(SIO_INT_SND);
	sio_out_service(1);
	}

#ifdef SIO_ERR_HANDLER

void
sio_err_handler (void)
{
	sio_clr_factor(SIO_INT_ERR);
	sio_err_service(1);
	}

#endif	/* of #ifdef SIO_ERR_HANDLER */

#if TNUM_PORT >= 2

void
sio_in2_handler (void)
{
	sio_clr_factor(SIO_INT_RCV << 3);
	sio_in_handler(2);
	}

void
sio_out2_handler (void)
{
	sio_clr_factor(SIO_INT_SND << 3);
	sio_out_handler(2);
	}

#ifdef SIO_ERR_HANDLER

void
sio_err2_handler (void)
{
	sio_clr_factor(SIO_INT_ERR << 3)
	sio_err_handler(2);
	}

#endif	/* of #ifdef SIO_ERR_HANDLER */

#endif	/* of #if TNUM_PORT >= 2 */
