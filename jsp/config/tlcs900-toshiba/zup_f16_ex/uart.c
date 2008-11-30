/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *  @(#) $Id: uart.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *  �񓯊��ʐM (UART)�V���A���`�����l���f�o�C�X�iSIO�j�h���C�o
 *  �iZup-F16�g���{�[�h�p�j
 */
#include <s_services.h>
#include <sil.h>
#include <tmp91cy22.h>
#include <uart.h>

/*
 *  �V���A��I/O���䃌�W�X�^�ւ̃I�t�Z�b�g��`
 */
#define		TOFFSET_SC0BUF			0x0000
#define		TOFFSET_SC0CR			0x0001
#define		TOFFSET_SC0MOD0			0x0002
#define		TOFFSET_BR0CR			0x0003
#define		TOFFSET_BR0ADD			0x0004
#define		TOFFSET_SC0MOD1			0x0005
 
/*
 *  �V���A��I/O�|�[�g��ԃt���O�̒�`
 */
#define		TBIT_STS_DEF			0x00
#define		TBIT_TXB_EMPTY			0x01
#define		TBIT_ENE_TXCBR			0x02
#define		TBIT_ENE_RXCBR			0x04
#define		TBIT_LOG_PORT			0x80

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 *
 *  ID = 1 ��uart1�CID = 2 ��uart0�ɑΉ������Ă���D
 */
static const SIOPINIB siopinib_table[TNUM_PORT] = {
	{ TADR_SFR_SC1BUF, TADR_SFR_INTES1, 0x08, (TBIT_SIOSMU8 | TBIT_SIORXE | TBIT_SIOSCBRG),
	  0x00, BRCR_19200, BRADD_19200, TBIT_RX1_CLR }	/* ID1�p UART1 19200bps	*/
/*	{ TADR_SFR_SC1BUF, TADR_SFR_INTES1, 0x08, (TBIT_SIOSMU8 | TBIT_SIORXE | TBIT_SIOSCBRG),
	  0x00, BRCR_38400, BRADD_38400, TBIT_RX1_CLR }*/	/* ID1�p UART1 38400bps	*/
/*	{ TADR_SFR_SC0BUF, TADR_SFR_INTES0, 0x01, (TBIT_SIOSMU8 | TBIT_SIORXE | TBIT_SIOSCBRG),
	  0x00, BRCR_19200, BRADD_19200, TBIT_RX0_CLR }*/	/* ID2�p UART0 19200bps	*/
};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
static SIOPCB siopcb_table[TNUM_PORT];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
uart_initialize()
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_PORT; siopcb++, i++) {
		siopcb->siopinib = &(siopinib_table[i]);
		siopcb->sts_flag = TBIT_STS_DEF;
		siopcb->rxb = -1;
	}
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB		*siopcb;
	const SIOPINIB	*siopinib;
	int i;

	/* �|�[�gID����Ǘ��u���b�N���擾	*/
	siopcb = get_siopcb(siopid);
	siopinib = siopcb->siopinib;

	/* �Ǘ��u���b�N�ɏ��ݒ�	*/
	siopcb->sts_flag |= TBIT_TXB_EMPTY;
	siopcb->exinf = exinf;
	if( siopid == LOGTASK_PORTID ){	/* �V�X�e�����O�p�̃|�[�g�̏ꍇ	*/
		siopcb->sts_flag |= TBIT_LOG_PORT;
		if( log_io_busy == TRUE ){
			/* ���M���̏ꍇ�͊����܂ő҂�	*/
			while( (sil_reb_mem((VP)(siopinib->hint)) & TBIT_INTC_H) == 0 );
		}
		log_io_busy = FALSE;	/* �������Ȃ̂Ŗ����I�ɍs���Ă���   */
	}

	/* ��M��~	*/
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0MOD0), 0x00 );
	/* �|�[�g�ݒ�(TXD�Ƃ��Ďg�p)	*/
	sil_wrb_mem((VP)(TADR_SFR_P9FC), siopinib->pcrfc_def );
	sil_wrb_mem((VP)(TADR_SFR_P9CR), siopinib->pcrfc_def );

	/* ���샂�[�h�ݒ�	*/
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0MOD0), siopinib->scmod0_def );
	sil_reb_mem((VP)(siopinib->cntrl+TOFFSET_SC0CR));	/* �Ǐo���ɂ��G���[�t���O�N���A	*/
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0CR), siopinib->sccr_def );
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_BR0CR), siopinib->brcr_def);
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_BR0ADD), siopinib->bradd_def);
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0MOD1), TBIT_SIOI2S);

	/* �V���A�������݂̐ݒ肨��їv���t���O�N���A	 */
	sil_wrb_mem((VP)TADR_SFR_INTCLR, (siopinib->int_clr) );		/* ��M�v���N���A	*/
	sil_wrb_mem((VP)TADR_SFR_INTCLR, (VB)(siopinib->int_clr + 1) );	/* ���M�v���N���A	*/
	sil_wrb_mem((VP)(siopinib->hint), (VB)((INT_LEVEL_UART << 4) | INT_LEVEL_UART) );

	/*
	 * �_�~�[�f�[�^��M
	 */
	sil_reb_mem((VP)(siopinib->cntrl+TOFFSET_SC0BUF));
	sil_reb_mem((VP)(siopinib->cntrl+TOFFSET_SC0BUF));

	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
uart_cls_por(SIOPCB *siopcb)
{
	const SIOPINIB	*siopinib;

	siopinib = siopcb->siopinib;

	/* ��M��~	*/
	sil_wrb_mem((VP)(siopinib->cntrl+TOFFSET_SC0MOD0), 0x00 );

	/* �V�X�e�����O�p�|�[�g�̏���	*/
	if( (siopcb->sts_flag & TBIT_LOG_PORT) == TBIT_LOG_PORT ){
		if( log_io_busy == TRUE ){
			/* ���M���̏ꍇ�͊����܂ő҂�	*/
			while( (sil_reb_mem((VP)(TADR_SFR_INTES0)) & TBIT_INTC_H) == 0 );
		}
		log_io_busy = FALSE;
	}

	/* �V���A�������݂̋֎~����їv���t���O�N���A	 */
	sil_wrb_mem((VP)(siopinib->hint), 0x00 );
	sil_wrb_mem((VP)TADR_SFR_INTCLR, (siopinib->int_clr) );		/* ��M�v���N���A	*/
	sil_wrb_mem((VP)TADR_SFR_INTCLR, (VB)(siopinib->int_clr + 1) );	/* ���M�v���N���A	*/
	/* �|�[�g�ݒ�(�|�[�g�Ƃ��Ďg�p)	*/
	sil_wrb_mem((VP)(TADR_SFR_P9FC), 0x00 );
	sil_wrb_mem((VP)(TADR_SFR_P9CR), 0x00 );

	siopcb->sts_flag = TBIT_STS_DEF;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
	if( (siopcb->sts_flag & TBIT_TXB_EMPTY) == TBIT_TXB_EMPTY ){
		siopcb->sts_flag &= (UB)~TBIT_TXB_EMPTY;
		sil_wrb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0BUF), c);

	/* �V�X�e�����O�p�|�[�g�̏���	*/
		if( (siopcb->sts_flag & TBIT_LOG_PORT) == TBIT_LOG_PORT ){
			log_io_busy = TRUE;	/* ���M��	*/
		}
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
uart_rcv_chr(SIOPCB *siopcb)
{
	return(siopcb->rxb);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case UART_ERDY_SND:
		siopcb->sts_flag |= TBIT_ENE_TXCBR;
		break;
	case UART_ERDY_RCV:
		siopcb->sts_flag |= TBIT_ENE_RXCBR;
		break;
	default:
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case UART_ERDY_SND:
		siopcb->sts_flag &= (UB)~TBIT_ENE_TXCBR;
		break;
	case UART_ERDY_RCV:
		siopcb->sts_flag &= (UB)~TBIT_ENE_RXCBR;
		break;
	default:
		break;
	}
}

/*
 *  �|�[�gID=1�Ɏw�肳��Ă���SIO�`�����l��(uart1)����̎�M������
 */
void serial_in_handler1()
{
	SIOPCB *siopcb = &siopcb_table[0];

	/* �G���[�̏ꍇ�������Ȃ�   */
	if( ( sil_reb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0CR)) & 0x1c ) == 0 ){

		/* �f�[�^��M	*/
		siopcb->rxb = (INT)sil_reb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0BUF));

		/* �R�[���o�b�N��������Ă���ꍇ	*/
		if( (siopcb->sts_flag & TBIT_ENE_RXCBR) == TBIT_ENE_RXCBR ){
			/*
			 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
			 */
			uart_ierdy_rcv(siopcb->exinf);
		}
	}
}

/*
 *  �|�[�gID=1�Ɏw�肳��Ă���SIO�`�����l��(uart1)����̑��M������
 */
void serial_out_handler1()
{
	SIOPCB *siopcb = &siopcb_table[0];

	/* �f�[�^���M�����t���OON	*/
	siopcb->sts_flag |= TBIT_TXB_EMPTY;

	/* �V�X�e�����O�p�|�[�g�̏���	*/
	if( (siopcb->sts_flag & TBIT_LOG_PORT) == TBIT_LOG_PORT ){
		log_io_busy = FALSE;	/* ���M����	*/
	}

	/* �R�[���o�b�N��������Ă���ꍇ	*/
	if( (siopcb->sts_flag & TBIT_ENE_TXCBR) == TBIT_ENE_TXCBR ){
		/*
		 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
		 */
		uart_ierdy_snd(siopcb->exinf);
	}
}

#if TNUM_PORT >= 2
/*
 *  �|�[�gID=2�Ɏw�肳��Ă���SIO�`�����l��(uart0)����̎�M������
 */
void serial_in_handler2()
{
	SIOPCB *siopcb = &siopcb_table[1];

	/* �G���[�̏ꍇ�������Ȃ�   */
	if( ( sil_reb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0CR)) & 0x1c ) == 0 ){

		/* �f�[�^��M	*/
		siopcb->rxb = (INT)sil_reb_mem((VP)(siopcb->siopinib->cntrl+TOFFSET_SC0BUF));

		/* �R�[���o�b�N��������Ă���ꍇ	*/
		if( (siopcb->sts_flag & TBIT_ENE_RXCBR) == TBIT_ENE_RXCBR ){
			/*
			 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
			 */
			uart_ierdy_rcv(siopcb->exinf);
		}
	}
}

/*
 *  �|�[�gID=2�Ɏw�肳��Ă���SIO�`�����l��(uart0)����̑��M������
 */
void serial_out_handler2()
{
	SIOPCB *siopcb = &siopcb_table[1];

	/* �f�[�^���M�����t���OON	*/
	siopcb->sts_flag |= TBIT_TXB_EMPTY;

	/* �V�X�e�����O�p�|�[�g�̏���	*/
	if( (siopcb->sts_flag & TBIT_LOG_PORT) == TBIT_LOG_PORT ){
		log_io_busy = FALSE;	/* ���M����	*/
	}

	/* �R�[���o�b�N��������Ă���ꍇ	*/
	if( (siopcb->sts_flag & TBIT_ENE_TXCBR) == TBIT_ENE_TXCBR ){
		/*
		 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
		 */
		uart_ierdy_snd(siopcb->exinf);
	}
}

#endif

