/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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

#include <h8s_sci.h>

/*
 *  H8S����SCI�p �Ȉ�SIO�h���C�o
 *  �E���L�́A�Q�`�����l���p�ɋL�q���Ă���BH8S�V���[�Y�̒��ɂ́A�Q�`�����l��
 *    �ȏ�T�|�[�g���Ă���`�b�v�����邪�A���̂Ƃ��̑Ή��͗e�Ղł���B
 */

/* TNUM_SIOP : �T�|�[�g����V���A���|�[�g�̐� (�f�t�H���g�l 2)
   TNUM_PORT : �T�|�[�g����V���A��I/O�|�[�g�̐� (�f�t�H���g�l 2)
   (sys_config.h �ɋL��) */

/* �ȉ��ŁA���W�X�^�̃A�h���X���AUW �^�փL���X�g�����Ă���B����́A�x�[�X
   �A�h���X�ɃI�t�Z�b�g�l�������āA�ŏI�I�ȃ��W�X�^�̃A�h���X�����߂Ă���
   ���߂ł���B�擾��ɁA�ŏI�I�� VP �^�ɃL���X�g����Ă���B(h8s_sci.h) */

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̒�`
 */
typedef struct sio_port_initialization_block {
	UW	reg_base;	/* ���W�X�^�̃x�[�X�A�h���X */
	UB	smr_def;	/* SMR �ݒ�l b6-b3;
				   (����M�r�b�g���A�X�g�b�v�r�b�g�C�p���e�B) */
	UB	boud_brr_def;	/* BRR �ݒ�l�i�{�[���[�g�̐ݒ�l�j */
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
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{ (UW)	SCI0_BASE_ADDR,
	  (UB)	0,
	  (UB)	BRR_RATE		/* N �l */
	},
#if TNUM_SIOP >= 2
	{ (UW)	SCI1_BASE_ADDR,
	  (UB)	0,
	  (UB)	BRR_RATE		/* N �l */
	}
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
 *  SCI�p���W�X�^����֐�
 */
Inline void
h8s_sci_or( const SIOPINIB *siopinib, UW reg, UB val )
{
	h8s_sci_wrb( siopinib->reg_base, reg, h8s_sci_reb( siopinib->reg_base, reg ) | val );
}

Inline void
h8s_sci_and( const SIOPINIB *siopinib, UW reg, UB val )
{
	h8s_sci_wrb( siopinib->reg_base, reg, h8s_sci_reb( siopinib->reg_base, reg ) & val );
}

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
h8s_sci_getready(SIOPCB *siopcb)
{
	siopcb->getready = FALSE;
	if( h8s_sci_reb( siopcb->siopinib->reg_base, (UW) SSR ) & RDRF )
		siopcb->getready = TRUE;

	return( siopcb->getready );
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
h8s_sci_putready(SIOPCB *siopcb)
{
	siopcb->putready = FALSE;
	if( h8s_sci_reb( siopcb->siopinib->reg_base, (UW) SSR ) & TDRE )
		siopcb->putready = TRUE;

	return( siopcb->putready );
}

/*
 *  ��M���������̎�o��
 */
Inline char
h8s_sci_getchar(SIOPCB *siopcb)
{
	/* RDRF�N���A */
	h8s_sci_and( siopcb->siopinib, (UW) SSR, (UB) ~RDRF );

	return( (char) h8s_sci_reb( siopcb->siopinib->reg_base, (UW) RDR ) );
}

/*
 *  ���M���镶���̏�����
 */
Inline void
h8s_sci_putchar(SIOPCB *siopcb, char c)
{
#ifndef GDB_STUB
	h8s_sci_wrb( siopcb->siopinib->reg_base, (UW) TDR, c );

	/* TDRE�N���A */
	h8s_sci_and( siopcb->siopinib, (UW) SSR, (UB) ~TDRE );
#else
	stub_putc( c );
#endif
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
h8s_sci_initialize()
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
h8s_sci_init_siopinib( const SIOPINIB  *siopinib )
{
	/*
	 * SCI���W�X�^�̏�����
	 */

	/* ����M��~ */
	h8s_sci_and( siopinib, (UW) SCR, (UB) ~( TE | RE ) );

	/* �r�b�g���Ȃǐݒ� */
	h8s_sci_wrb( siopinib->reg_base, (UW) SMR, siopinib->smr_def );

	/* �{�[���[�g�ݒ� */
	h8s_sci_wrb( siopinib->reg_base, (UW) BRR, siopinib->boud_brr_def );

	/* �����݋֎~�ƃN���b�N�\�[�X�I�� */
	h8s_sci_and( siopinib, (UW) SCR, (UB) ~( TIE | RIE | MPIE | TEIE | CKE1 | CKE0 ) );

	/* �{�[���[�g�̈��艻(1bit���̑҂�) */
	sil_dly_nse( 1/BAUD_RATE );

	/* �G���[�t���O���N���A */
	h8s_sci_and( siopinib, (UW) SSR, ~( ORER | FER | PER ) );

	/* ����M���A��M�����݋��� */
	h8s_sci_or( siopinib, (UW) SCR, ( RIE | TE | RE ) );
}

/*
 *  �J�[�l���N�����̃o�[�i�[�o�͗p�̏�����
 */
void
h8s_sci_init(void)
{
	h8s_sci_init_siopinib( get_siopinib(1) );
#if TNUM_SIOP >= 2
	h8s_sci_init_siopinib( get_siopinib(2) );
#endif /* TNUM_SIOP >= 2 */
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
h8s_sci_openflag(void)
{
#if TNUM_SIOP < 2
	return( siopcb_table[0].openflag );
#else /* TNUM_SIOP < 2 */
	return( siopcb_table[0].openflag || siopcb_table[1].openflag );
#endif /* TNUM_SIOP < 2 */
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
h8s_sci_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB 		*siopcb = get_siopcb(siopid);
	const SIOPINIB  *siopinib = siopcb->siopinib;

#ifndef GDB_STUB
	/* SCI���W�X�^�̏����� */
	h8s_sci_init_siopinib( siopinib );
#endif	/* GDB_STUB */

	/* �����݃��x���ݒ�A�����ݗv���N���A�́Asio_opn_por �ōs���B */

	siopcb->exinf = exinf;
	siopcb->getready = siopcb->putready = FALSE;
	siopcb->openflag = TRUE;

	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
h8s_sci_cls_por(SIOPCB *siopcb)
{
	/* TEND �� 1 �ɂȂ�܂ő҂� */
	while ( !(h8s_sci_reb( siopcb->siopinib->reg_base, (UW) SSR ) & TEND ) );

	h8s_sci_and( siopcb->siopinib, (UW) SCR, ~( TE | RE ) );
	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
h8s_sci_snd_chr(SIOPCB *siopcb, char c)
{
	if( h8s_sci_putready(siopcb) ) {
		h8s_sci_putchar(siopcb, c);
		siopcb->putready = FALSE;
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
h8s_sci_rcv_chr(SIOPCB *siopcb)
{
	if( h8s_sci_getready(siopcb) ) {
		siopcb->getready = FALSE;
		return( (INT)(UB) h8s_sci_getchar(siopcb) );
			/* UB �̃L���X�g�́A�����g���h�~���邽�� */
	}

	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
h8s_sci_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		h8s_sci_or( siopcb->siopinib, (UW) SCR, TIE );
		return;
	case SIO_ERDY_RCV:
		h8s_sci_or( siopcb->siopinib, (UW) SCR, RIE );
		return;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
h8s_sci_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch( cbrtn ) {
	case SIO_ERDY_SND:
		h8s_sci_and( siopcb->siopinib, (UW) SCR, (UB) ~TIE );
		return;
	case SIO_ERDY_RCV:
		h8s_sci_and( siopcb->siopinib, (UW) SCR, (UB) ~RIE );
		return;
	}
}

/*
 *  SIO�̊����݃T�[�r�X���[�`�� (SCI0��p)
 */
void
h8s_sci0_isr_in()
{
	SIOPCB *siopcb = get_siopcb(1);

	/* ��M�ʒm�R�[���o�b�N���[�`���̌Ăяo�� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_rcv( siopcb->exinf );
	}
}

void
h8s_sci0_isr_out()
{
	SIOPCB *siopcb = get_siopcb(1);

	/* ���M�\�R�[���o�b�N���[�`���̌Ăяo�� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_snd( siopcb->exinf );
	}
}

/*
 *  SIO�̎�M�G���[�����݃T�[�r�X���[�`�� (SCI0��p)
 *
 *  �G���[�����́A���L�G���[�t���O�̃N���A�̂݁B
 *  �E�I�[�o�[�����G���[�A�t���[�~���O�G���[�A�p���e�B�G���[
 */
void
h8s_sci0_isr_error(void)
{
	SIOPCB *siopcb = get_siopcb(1);

	if( siopcb->openflag ) {
		/*  �G���[�t���O�N���A  */
		h8s_sci_and( siopcb->siopinib, (UW) SSR, ~( RDRF | ORER | FER | PER ) );
	}
}

/*
 *  SIO�̊����݃T�[�r�X���[�`�� (SCI1��p)
 */
void
h8s_sci1_isr_in()
{
	SIOPCB *siopcb = get_siopcb(2);

	/* ��M�ʒm�R�[���o�b�N���[�`���̌Ăяo�� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_rcv( siopcb->exinf );
	}
}

void
h8s_sci1_isr_out()
{
	SIOPCB *siopcb = get_siopcb(2);

	/* ���M�\�R�[���o�b�N���[�`���̌Ăяo�� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_snd( siopcb->exinf );
	}
}

/*
 *  SIO�̎�M�G���[�����݃T�[�r�X���[�`�� (SCI1��p)
 *
 *  �G���[�����́A���L�G���[�t���O�̃N���A�̂݁B
 *  �E�I�[�o�[�����G���[�A�t���[�~���O�G���[�A�p���e�B�G���[
 */
void
h8s_sci1_isr_error(void)
{
	SIOPCB *siopcb = get_siopcb(2);

	if( siopcb->openflag ) {
		/*  �G���[�t���O�N���A  */
		h8s_sci_and( siopcb->siopinib, (UW) SSR, ~( RDRF | ORER | FER | PER ) );
	}
}

/*
 *  H8S ���� SCI �p�|�[�����O�o�� (LOGTASK_PORTID��p�Asys_putc�ŗ��p)
 */
void
h8s_sci0_putchar_pol( char c )
{

	const SIOPINIB  *siopinib = get_siopinib( LOGTASK_PORTID );

	/* TDRE �� 1 �ɂȂ�܂ő҂� */
	while ( !(h8s_sci_reb( siopinib->reg_base, (UW) SSR ) & TDRE ) );

	h8s_sci_wrb( siopinib->reg_base, (UW) TDR, (UB) c );

	/* TDRE�N���A */
	h8s_sci_and( siopinib, (UW) SSR, (UB) ~TDRE );

	/* TEND �� 1 �ɂȂ�܂ő҂� */
	while ( !(h8s_sci_reb( siopinib->reg_base, (UW) SSR ) & TEND ) );
}
