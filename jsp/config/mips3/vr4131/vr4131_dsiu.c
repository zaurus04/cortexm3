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
 */
 
#include <vr4131_dsiu.h>

/*
 *	VR4131����DSIU�p �Ȉ�SIO�h���C�o
 */

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̒�`
 */
typedef struct sio_port_initialization_block {
	UB	lcr_def;	/* LCR�ݒ�l b0-b6;
				   (����M�r�b�g���A�X�g�b�v�r�b�g�C�p���e�B) */
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
 *  �i�|�[�g�͂P�����Ȃ����A���̃\�[�X�R�[�h�Ƃ̐e�a������z��Œ�`����j
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ (UB)	WORD_LENGTH_8 | STOP_BITS_1 | PARITY_NON,
	  (UB)	HI8(DIVISOR),
	  (UB)	LO8(DIVISOR) }
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
 *  ��Ԃ̓Ǐo���iIID�̓Ǐo���j
 */
static void
vr4131_dsiu_get_stat(SIOPCB *siopcb)
{
	UB	iid;

	iid = vr4131_reb_mem( (VP) DSIUIID ) & INT_MASK;

	switch( iid ) {
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
vr4131_dsiu_getready(SIOPCB *siopcb)
{
	return(siopcb->getready);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
vr4131_dsiu_putready(SIOPCB *siopcb)
{
	return(siopcb->putready);
}

/*
 *  ��M���������̎�o��
 */
Inline char
vr4131_dsiu_getchar(SIOPCB *siopcb)
{
	siopcb->getready = FALSE;
	return((char) vr4131_reb_mem( (VP) DSIURB ));
}

/*
 *  ���M���镶���̏�����
 */
Inline void
vr4131_dsiu_putchar(SIOPCB *siopcb, char c)
{
	siopcb->putready = FALSE;

#ifndef GDB_STUB
	vr4131_wrb_mem( (VP) DSIUTH, c );
#else /* GDB_STUB */
	stub_putc( c );
#endif /* GDB_STUB */
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
vr4131_dsiu_initialize()
{
	SIOPCB	*siopcb = siopcb_table;
	UINT	i = 0;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	siopcb->siopinib = &(siopinib_table[i]);
	siopcb->openflag = FALSE;
}

/*
 *  SIO���W�X�^���������[�`��
 */
void
vr4131_dsiu_init_siopinib( const SIOPINIB  *siopinib )
{
	/*
	 * DSIU���W�X�^�̏�����
	 */
	/* �������� */
	vr4131_wrb_mem( (VP) DSIUIE,  DIS_INT );

	/* �{�[���[�g�̐ݒ� */
	vr4131_wrb_mem( (VP) DSIULC,  siopinib->lcr_def | DIVISOR_LATCH_ACC );

	vr4131_wrb_mem( (VP) DSIUDLL, siopinib->boud_lo_def );
	vr4131_wrb_mem( (VP) DSIUDLM, siopinib->boud_hi_def );

	/* ���[�h�̐ݒ� */
	vr4131_wrb_mem( (VP) DSIULC,  siopinib->lcr_def );

	/* FIFO�̐ݒ� */
	vr4131_wrb_mem( (VP) DSIUFC,  FIFO_ENABLE );
	vr4131_wrb_mem( (VP) DSIUFC,  FIFO_ENABLE | RECEIVE_FIFO_RESET | TRANS_FIFO_RESET | RECEIVE_TRIG_1_BYTE );
	vr4131_wrb_mem( (VP) DSIUFC,  FIFO_ENABLE | RECEIVE_TRIG_1_BYTE );

	/* �I������ */
	vr4131_wrb_mem( (VP) DSIUMC,  RTS );

	vr4131_wrb_mem( (VP) DSIUIE,  RECEIVE_DATA_AVAILABLE);
}

/*
 *  �J�[�l���N�����̃o�[�i�[�o�͗p�̏�����
 */
void
vr4131_dsiu_init(void)
{
	vr4131_dsiu_init_siopinib( get_siopinib(1) );
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
vr4131_dsiu_openflag(void)
{
	return( siopcb_table[0].openflag );
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
vr4131_dsiu_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB		*siopcb = get_siopcb(siopid);
	const SIOPINIB	*siopinib = siopcb->siopinib;

#ifndef GDB_STUB
	/* DSIU���W�X�^�̏����� */
	vr4131_dsiu_init_siopinib( siopinib );
#endif	/*  GDB_STUB  */

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
vr4131_dsiu_cls_por(SIOPCB *siopcb)
{
	vr4131_wrb_mem( (VP) DSIUIE, DIS_INT );

	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
vr4131_dsiu_snd_chr(SIOPCB *siopcb, char c)
{
	if (vr4131_dsiu_putready(siopcb)) {
		vr4131_dsiu_putchar(siopcb, c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
vr4131_dsiu_rcv_chr(SIOPCB *siopcb)
{
	if (vr4131_dsiu_getready(siopcb)) {
		return((INT)(UB) vr4131_dsiu_getchar(siopcb));
	}
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
vr4131_dsiu_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ie_bit = 0;

	switch (cbrtn) {
	case SIO_ERDY_SND:
		ie_bit = TRANS_REG_EMPTY;
		break;
	case SIO_ERDY_RCV:
		ie_bit = RECEIVE_DATA_AVAILABLE | RECEIVE_LINE_STATUS;
		break;
	}

	vr4131_orb( (VP) DSIUIE, ie_bit );
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
vr4131_dsiu_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	ie_bit = 0;

	switch (cbrtn) {
	case SIO_ERDY_SND:
		ie_bit = TRANS_REG_EMPTY;
		break;
	case SIO_ERDY_RCV:
		ie_bit = RECEIVE_DATA_AVAILABLE | RECEIVE_LINE_STATUS;
		break;
	}

	vr4131_andb( (VP) DSIUIE, ~ie_bit );
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
vr4131_dsiu_isr_siop(SIOPCB *siopcb)
{
	vr4131_dsiu_get_stat(siopcb);

	if ( vr4131_dsiu_getready(siopcb) ) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		vr4131_dsiu_ierdy_rcv(siopcb->exinf);
	}
	if ( vr4131_dsiu_putready(siopcb) ) {
		/*
		 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
		 */
		vr4131_dsiu_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
vr4131_dsiu_isr()
{
	if (siopcb_table[0].openflag) {
		vr4131_dsiu_isr_siop(&(siopcb_table[0]));
	}
}

/*
 *  VR4131 ���� DSIU �p�|�[�����O�o�� (sys_putc�ŗ��p)
 */
void
vr4131_dsiu_putchar_pol( char val ) {

	/* ���M���G���v�e�B�ɂȂ�܂ő҂B */
	while( (vr4131_reb_mem( (VP)DSIULS ) & (TEMT) ) == 0 );

	vr4131_wrb_mem( (VP)DSIUTH, (VB) val );
}
