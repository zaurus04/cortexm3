/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 * 
 */

#include <tl16pir552.h>

/*
 *	TL16PIR552(TI)�p �Ȉ�SIO�h���C�o
 */

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̒�`
 */
typedef struct sio_port_initialization_block {
	VP	channel_addr;	/* �V���A���|�[�g�̊J�n�Ԓn */

	UB	lcr_def;	/* LCR�ݒ�l b0-b6;
				(����M�r�b�g���A�X�g�b�v�r�b�g�C�p���e�B) */
	UB	scr_def;	/* SCR�ݒ�l�i�v���X�P�[���G�j*/
	UB	boud_hi_def;	/* DLM�ݒ�l�i�{�[���[�g��ʂ̐ݒ�l�j */
	UB	boud_lo_def;	/* DLL�ݒ�l�i�{�[���[�g���ʂ̐ݒ�l�j */
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
struct sio_port_control_block {
	const SIOPINIB	*siopinib;	/* �V���A��I/O�|�[�g�������u���b�N */
	VP_INT		exinf;		/* �g����� */
	BOOL		openflag;	/* �I�[�v���ς݃t���O */
	BOOL		getready;	/* ��������M������� */
	BOOL		putready;	/* �����𑗐M�ł����� */
};

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 *    ID = 1 ���|�[�g1�CID = 2 ���|�[�g2�ɑΉ������Ă���D
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ (VP)  UART_CH01,
	  (UB)	WORD_LENGTH_8 | STOP_BITS_1 | PARITY_NON,
	  (UB)	PRE_DIVISOR,
	  (UB)	HI8(DIVISOR),
	  (UB)	LO8(DIVISOR) },
#if TNUM_SIOP >= 2
	{ (VP)  UART_CH02,
	  (UB)	WORD_LENGTH_8 | STOP_BITS_1 | PARITY_NON,
	  (UB)	PRE_DIVISOR,
	  (UB)	HI8(DIVISOR),
	  (UB)	LO8(DIVISOR) },
#endif /* TNUM_SIOP >= 2 */
};

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̎�o��
 */
#define INDEX_SIOPINIB(siopid)	((UINT)((siopid) - 1))
#define get_siopinib(siopid)	(&(siopinib_table[INDEX_SIOPINIB(siopid)]))


/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  SIO�p���W�X�^����֐�
 */
Inline void
tl16pir552_orb( VP addr, UW reg, UB val )
{
	tl16pir552_wrb( addr, reg, tl16pir552_reb( addr, reg ) | val );
}

Inline void
tl16pir552_andb( VP addr, UW reg, UB val )
{
	tl16pir552_wrb( addr, reg, tl16pir552_reb( addr, reg ) & val );
}


/*
 *  ��Ԃ̓Ǐo���iIIR�̓Ǐo���j
 */
static void
tl16pir552_get_stat(SIOPCB *siopcb)
{
	UB	iir;

	iir = tl16pir552_reb( siopcb->siopinib->channel_addr, IIR) & INT_MASK;

	switch( iir ) {
		case INT_TRANS_EMPTY :
			siopcb->putready = TRUE;
			break;
		case INT_RECEIVE_DATA :
		case INT_CHAR_TIME_OUT :
			siopcb->getready = TRUE;
			break;
		default :
			break;
	}

}

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
tl16pir552_getready(SIOPCB *siopcb)
{
	return(siopcb->getready);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
tl16pir552_putready(SIOPCB *siopcb)
{
	return(siopcb->putready);
}

/*
 *  ��M���������̎�o��
 */
Inline char
tl16pir552_getchar(SIOPCB *siopcb)
{
	siopcb->getready = FALSE;
	return((char) tl16pir552_reb( siopcb->siopinib->channel_addr, RBR ));
	/* 1byte �P�ʂł̕����̎��o�����s�������邽�߁Atl16pir552_opn_por����
	   ��M�o�b�t�@�ݒ�𑝂₵���Ƃ��Ă����\�̌���͌����Ȃ��B
	   ���\�̌���ɂ́A�o�b�t�@�S�̂̃u���b�N�]�����s���Ȃǂ̏C�����K�v�B*/
}

/*
 *  ���M���镶���̏�����
 */
Inline void
tl16pir552_putchar(SIOPCB *siopcb, char c)
{
	siopcb->putready = FALSE;
	tl16pir552_wrb( siopcb->siopinib->channel_addr, THR, c );
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
tl16pir552_initialize()
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->siopinib = &(siopinib_table[i]);
		siopcb->openflag = FALSE;
	}
}

/*
 *  SIO���W�X�^���������[�`��
 */
void
tl16pir552_init_siopinib( const SIOPINIB  *siopinib )
{
	/*
	 * SIO���W�X�^�̏�����
	 */
	/* �������� */
	tl16pir552_wrb( siopinib->channel_addr, IER, DIS_INT );

	tl16pir552_wrb( siopinib->channel_addr, MCR, ENABLE_EXT_INT );

	/* �{�[���[�g�̐ݒ� */
	tl16pir552_wrb( siopinib->channel_addr, LCR, siopinib->lcr_def | DIVISOR_LATCH_ACC );

	tl16pir552_wrb( siopinib->channel_addr, SCR, siopinib->scr_def );

	tl16pir552_wrb( siopinib->channel_addr, DLL, siopinib->boud_lo_def );
	tl16pir552_wrb( siopinib->channel_addr, DLM, siopinib->boud_hi_def );

	/* ���[�h�̐ݒ� */
	tl16pir552_wrb( siopinib->channel_addr, LCR, siopinib->lcr_def );

	/* FIFO�̐ݒ� */
	tl16pir552_wrb( siopinib->channel_addr, FCR, FIFO_ENABLE );
	tl16pir552_wrb( siopinib->channel_addr, FCR, FIFO_ENABLE | RECEIVE_FIFO_RESET | TRANS_FIFO_RESET | RECEIVE_TRIG_1_BYTE );
	tl16pir552_wrb( siopinib->channel_addr, FCR, FIFO_ENABLE | RECEIVE_TRIG_1_BYTE );

	/* �I������ */
	tl16pir552_wrb( siopinib->channel_addr, MCR, DTR | RTS | ENABLE_EXT_INT );

	tl16pir552_wrb( siopinib->channel_addr, IER, RECEIVE_DATA_AVAILABLE);
}

/*
 *  �J�[�l���N�����̃o�[�i�[�o�͗p�̏�����
 */
void
tl16pir552_init(void)
{
	tl16pir552_init_siopinib( get_siopinib(1) );
#if TNUM_SIOP >= 2
	tl16pir552_init_siopinib( get_siopinib(2) );
#endif /* TNUM_SIOP >= 2 */
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
tl16pir552_openflag(void)
{
#if TNUM_SIOP < 2
	return(siopcb_table[0].openflag);
#else /* TNUM_SIOP < 2 */
	return(siopcb_table[0].openflag || siopcb_table[1].openflag);
#endif /* TNUM_SIOP < 2 */
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
tl16pir552_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB		*siopcb = get_siopcb(siopid);
	const SIOPINIB	*siopinib = siopcb->siopinib;

	/* �V���A���R���g���[���̏����� */
	tl16pir552_init_siopinib( siopinib );

	/* �����݃��x���ݒ�A�����ݗv���N���A�́Asio_opn_por(hw_serial.h)�ōs���B */

	siopcb->exinf = exinf;
	siopcb->getready = siopcb->putready = FALSE;
	siopcb->openflag = TRUE;

	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
tl16pir552_cls_por(SIOPCB *siopcb)
{
	tl16pir552_wrb( siopcb->siopinib->channel_addr, IER, DIS_INT );

	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
tl16pir552_snd_chr(SIOPCB *siopcb, char c)
{
	if (tl16pir552_putready(siopcb)) {
		tl16pir552_putchar(siopcb, c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
tl16pir552_rcv_chr(SIOPCB *siopcb)
{
	if (tl16pir552_getready(siopcb)) {
		return((INT)(UB) tl16pir552_getchar(siopcb));
	}
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
tl16pir552_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ier_bit = 0;

	switch (cbrtn) {
	case SIO_ERDY_SND:
		ier_bit = TRANS_REG_EMPTY;
		break;
	case SIO_ERDY_RCV:
		ier_bit = (RECEIVE_DATA_AVAILABLE | RECEIVE_LINE_STATUS);
		break;
	}

	tl16pir552_orb( siopcb->siopinib->channel_addr, IER, ier_bit );
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
tl16pir552_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ier_bit = 0;

	switch (cbrtn) {
	case SIO_ERDY_SND:
		ier_bit = TRANS_REG_EMPTY;
		break;
	case SIO_ERDY_RCV:
		ier_bit = (RECEIVE_DATA_AVAILABLE | RECEIVE_LINE_STATUS);
		break;
	}

	tl16pir552_andb( siopcb->siopinib->channel_addr, IER, ~ier_bit );
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
tl16pir552_isr_siop(SIOPCB *siopcb)
{
	tl16pir552_get_stat(siopcb);

	if ( tl16pir552_getready(siopcb) ) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		tl16pir552_ierdy_rcv(siopcb->exinf);
	} else if ( tl16pir552_putready(siopcb) ) {
		/*
		 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
		 */
		tl16pir552_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
tl16pir552_uart0_isr()
{
	if (siopcb_table[0].openflag) {
		tl16pir552_isr_siop(&(siopcb_table[0]));
	}
}

#if TNUM_SIOP >= 2
void
tl16pir552_uart1_isr()
{
	if (siopcb_table[1].openflag) {
		tl16pir552_isr_siop(&(siopcb_table[1]));
	}
}
#endif /* TNUM_SIOP >= 2 */

/*
 *  �V���A��I/O�|�[�g�ւ̃|�[�����O�ł̏o��
 */
void
tl16pir552_putchar_pol( char val ) {

	const SIOPINIB  *siopinib = get_siopinib( LOGTASK_PORTID );

	/* ���M���G���v�e�B�ɂȂ�܂ő҂B */
	while( (tl16pir552_reb( siopinib->channel_addr, LSR ) & (TEMT) ) == 0 );

	tl16pir552_wrb( siopinib->channel_addr, THR, val );
}
