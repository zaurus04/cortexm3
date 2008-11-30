/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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

/*
 *  H8S����SCI�p �Ȉ�SIO�h���C�o
 *  �E���L�́A�Q�`�����l���p�ɋL�q���Ă���BH8S�V���[�Y�̒��ɂ́A�R�`�����l��
 *    �ȏ�T�|�[�g���Ă���`�b�v�����邪�A���̂Ƃ��̑Ή��͗e�Ղł���B
 */

#include <h8s_sci.h>

/* SCI���W�X�^�̃A�h���X */
/* �x�[�X�A�h���X */
#define SCI0_BASE_ADDR	0xff78	/* �`���l���O */
#define SCI1_BASE_ADDR	0xff80	/* �`���l���P */
#define SCI2_BASE_ADDR	0xff88	/* �`���l���Q */

/* ���W�X�^�I�t�Z�b�g */
#define SMR		0	/* �V���A�����[�h���W�X�^ */
#define BRR		1	/* �r�b�g���[�g���W�X�^ */
#define SCR		2	/* �V���A���R���g���[�����W�X�^ */
#define TDR		3	/* �g�����X�~�b�g�f�[�^���W�X�^ */
#define SSR		4	/* �V���A���X�e�[�^�X���W�X�^ */
#define RDR		5	/* ���V�[�u�f�[�^���W�X�^ */
#define SCMR		6	/* �X�}�[�g�J�[�h���[�h���W�X�^ */

/* �e���W�X�^�̃r�b�g�p�^�[�� */

/* RSR, RDR, TSR, TDR */
/* ��`���ׂ����̂́A���ɖ��� */

/* SMR */
#define CA	BIT7
#define	CHR	BIT6	/* 8bit = 0 / 7bit = 1 */
#define	PE	BIT5	/* Parity OFF = 0 / Parity ON = 1 */
#define	OE	BIT4	/* EVEN Parity = 0 / ODD Parity = 1 */
#define	STOP	BIT3	/* 1 STOP BIT = 0 / 2 STOP BIT = 1 */
#define MP	BIT2
#define	CSK1	BIT1
#define	CSK0	BIT0

/*
 *�@SMR�̏����l
 *
 *�@�r�b�g7=0�F�������������[�h
 *�@�r�b�g6=0�F�L�����N�^�����O�X=8�r�b�g
 *�@�r�b�g5=0�F�p���e�B�̕t���A�`�F�b�N���֎~
 *�@�r�b�g4�@�F�p���e�B���[�h�i���g�p�j
 *�@�r�b�g3=0�F�X�g�b�v�r�b�g�����O�X��1�r�b�g
 *�@�r�b�g1,0�F�{�[���[�g�W�F�l���[�^�ւ̃N���b�N�\�[�X�I��
 *�@�@�@�@�@�@�@�{�[�h�ˑ�����SCRn_CKS�Ƃ��Ē�`�in��ch�ԍ��j
 */
#define SMR_INIT	0

/* SCR */
#define TIE	BIT7
#define	RIE	BIT6
#define	TE	BIT5
#define	RE	BIT4
#define	MPIE	BIT3
#define TEIE	BIT2
#define	CKE1	BIT1
#define	CKE0	BIT0

/* SSR */
#define TDRE	BIT7
#define	RDRF	BIT6
#define	ORER	BIT5
#define	FER	BIT4
#define	PER	BIT3
#define TEND	BIT2
#define	MPB	BIT1
#define	MPBT	BIT0


/* 
 * TNUM_PORT : �V���A���h���C�o�iserial.c�j�A�܂� GDIC���x���ŃT�|�[�g����
 * �@�@�@�@�@�@�V���A���|�[�g�̐� 
 * TNUM_SIOP : PDIC���x���i�v���Z�b�T����SIO�j�ŃT�|�[�g����V���A��I/O�|�[�g
 *�@�@�@�@�@�@ �̐��i���݂̎����ł͍ő�3�j
 *  
 *�@�������user_config.h�Œ�`����B
 */

/* �ȉ��ŁA���W�X�^�̃A�h���X���AUW �^�փL���X�g�����Ă���B����́A�x�[�X
   �A�h���X�ɃI�t�Z�b�g�l�������āA�ŏI�I�ȃ��W�X�^�̃A�h���X�����߂Ă���
   ���߂ł���B�擾��ɁA�ŏI�I�� VP �^�ɃL���X�g����Ă���B(h8s_sci.h) */

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̒�`
 */
typedef struct sio_port_initialization_block {
	UW	reg_base;	/* ���W�X�^�̃x�[�X�A�h���X */
	UH	boud_rate;	/* �{�[���[�g[bps]�@*/
	UB	boud_brr_def;	/* BRR �ݒ�l�i�{�[���[�g�̐ݒ�l�j */
	UB	smr_def;	/* SMR �ݒ�l
				   (����M�r�b�g���A�X�g�b�v�r�b�g�C�p���e�B) */
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
	{ (UW)SCI0_BASE_ADDR,
	  (UH)BAUD_RATE1,
	  (UB)BRR0_RATE,			/* N �l */
	  (UB)(SMR_INIT | (SCR0_CKS & (CKE1 | CKE0)))
	},
#if TNUM_SIOP >= 2
	{ (UW)SCI1_BASE_ADDR,
	  (UH)BAUD_RATE1,
	  (UB)BRR1_RATE,			/* N �l */
	  (UB)(SMR_INIT | (SCR1_CKS & (CKE1 | CKE0)))
	}
#endif /* TNUM_SIOP >= 2 */
#if TNUM_SIOP >= 3
	,{(UW)SCI2_BASE_ADDR,
	  (UH)BAUD_RATE2,
	  (UB)BRR2_RATE,			/* N �l */
	  (UB)(SMR_INIT | (SCR2_CKS & (CKE1 | CKE0)))
	}
#endif /* TNUM_SIOP >= 3 */
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
 *  SCI�p�V�X�e���C���^�t�F�[�X���C��
 *
 *   base : �|�[�g�̃x�[�X�A�h���X
 *   offset : ���W�X�^�I�t�Z�b�g
 *   val : ���W�X�^�l 
 */
#define h8s_sci_wrb( base, offset, val ) h8s_wrb_reg( (base) + (offset), (val) )
#define h8s_sci_reb( base, offset )	h8s_reb_reg( (base) + (offset) )

/*
 *  SCI�p���W�X�^����֐�
 */
Inline void
h8s_sci_or( const SIOPINIB *siopinib, INT offset, INT val )
{
	UB reg = h8s_sci_reb( siopinib->reg_base, offset );
	h8s_sci_wrb( siopinib->reg_base, offset, reg | (UB)val );
}

Inline void
h8s_sci_and( const SIOPINIB *siopinib, INT offset, INT val )
{
	UB reg = h8s_sci_reb( siopinib->reg_base, offset );
	h8s_sci_wrb( siopinib->reg_base, offset, reg & (UB)val );
}

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
h8s_sci_getready(SIOPCB *siopcb)
{
	UB ssr;
	
	siopcb->getready = FALSE;
	ssr =  h8s_sci_reb( siopcb->siopinib->reg_base, SSR );
	if( ssr & RDRF ) {
		siopcb->getready = TRUE;
	}
	return( siopcb->getready );
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
h8s_sci_putready(SIOPCB *siopcb)
{
	siopcb->putready = FALSE;
	if( h8s_sci_reb( siopcb->siopinib->reg_base, SSR ) & TDRE ) {
		siopcb->putready = TRUE;
	}
	return( siopcb->putready );
}

/*
 *  ��M���������̎�o��
 */
Inline char
h8s_sci_getchar(SIOPCB *siopcb)
{
	/* RDRF�N���A */
	h8s_sci_and( siopcb->siopinib, SSR, ~RDRF );

	return( (char) h8s_sci_reb( siopcb->siopinib->reg_base, RDR ) );
}

/*
 *  ���M���镶���̏�����
 */
Inline void
h8s_sci_putchar(SIOPCB *siopcb, char c)
{
	h8s_sci_wrb( siopcb->siopinib->reg_base, TDR, c );

	/* TDRE�N���A */
	h8s_sci_and( siopcb->siopinib, SSR, ~TDRE );
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
h8s_sci_initialize(void)
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
	h8s_sci_and( siopinib, SCR, ~( TE | RE ) );

	/* �r�b�g���Ȃǐݒ� */
	h8s_sci_wrb( siopinib->reg_base, SMR, siopinib->smr_def );

	/* �{�[���[�g�ݒ� */
	h8s_sci_wrb( siopinib->reg_base, BRR, siopinib->boud_brr_def );

	/*
	 *  �����݋֎~�ƃN���b�N�\�[�X�I��
	 *�@�@�N���b�N�\�[�X�͓����N���b�N��I��
	 */
	h8s_sci_and( siopinib, SCR, ~( TIE | RIE | MPIE | TEIE | CKE1 | CKE0 ) );

	/* �{�[���[�g�̈��艻(1bit���̑҂�) */
	sil_dly_nse_long( 1000000000ul / (siopinib->boud_rate) );

	/* �G���[�t���O���N���A */
	h8s_sci_and( siopinib, SSR, ~( ORER | FER | PER ) );	/* �C�� */

	/* ����M���A��M�����݋��� */
	h8s_sci_or( siopinib, SCR, ( RIE | TE | RE ) );
}


/*
 *  SCI0�̐ݒ�ɖ������Ȃ����`�F�b�N
 */
#if defined(OMIT_SCI0) && (POL_PORTID == 1)
#error h8s_sci_putchar_pol serial port ID error.
#endif

/*
 *  �J�[�l���N�����̃o�[�i�[�o�͗p�̏�����
 */
void
h8s_sci_init(void)
{
	h8s_sci_init_siopinib( get_siopinib(POL_PORTID) );
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
h8s_sci_openflag(void)
{
	BOOL ret;
#ifndef OMIT_SCI0
	ret = siopcb_table[0].openflag;
#else /* OMIT_SCI0 */
	ret = FALSE;
#endif /* OMIT_SCI0 */

#if TNUM_SIOP >= 2
	ret |= siopcb_table[1].openflag;
#endif /* TNUM_SIOP >= 2 */

#if TNUM_SIOP >= 3
	ret |= siopcb_table[2].openflag;
#endif /* TNUM_SIOP >= 3 */

	return(ret);
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
h8s_sci_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB 		*siopcb = get_siopcb(siopid);
	const SIOPINIB  *siopinib = siopcb->siopinib;

	/* SCI���W�X�^�̏����� */
	h8s_sci_init_siopinib( siopinib );

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
	while ( !(h8s_sci_reb( siopcb->siopinib->reg_base, SSR ) & TEND ) );

	h8s_sci_and( siopcb->siopinib, SCR, ~( TE | RE ) );	/* �C�� */
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
			/* UB �̃L���X�g�́A�����g����h�~���邽�� */
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
		h8s_sci_or( siopcb->siopinib, SCR, TIE );
		return;
	case SIO_ERDY_RCV:
		h8s_sci_or( siopcb->siopinib, SCR, RIE );
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
		h8s_sci_and( siopcb->siopinib, SCR, ~TIE );
		return;
	case SIO_ERDY_RCV:
		h8s_sci_and( siopcb->siopinib, SCR, ~RIE );
		return;
	}
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 *�@�@�S�`���l�����ʕ������C�����C���֐��Ƃ��Ē�`���Ă���
 */
Inline void
h8s_scix_isr_in(ID portid)
{
	SIOPCB *siopcb = get_siopcb(portid);

	/* ��M�ʒm�R�[���o�b�N���[�`���̌Ăяo�� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_rcv( siopcb->exinf );
	}
}

Inline void
h8s_scix_isr_out(ID portid)
{
	SIOPCB *siopcb = get_siopcb(portid);

	/* ���M�\�R�[���o�b�N���[�`���̌Ăяo�� */
	if( siopcb->openflag ) {
		h8s_sci_ierdy_snd( siopcb->exinf );
	}
}

/*
 *  SIO�̎�M�G���[�����݃T�[�r�X���[�`��
 *�@�@�S�`���l�����ʕ������C�����C���֐��Ƃ��Ē�`���Ă���
 *
 *  �G���[�����́A���L�G���[�t���O�̃N���A�̂݁B
 *  �E�I�[�o�[�����G���[�A�t���[�~���O�G���[�A�p���e�B�G���[
 */
Inline void
h8s_scix_isr_error(INT portid)
{
	SIOPCB *siopcb = get_siopcb(portid);

	if( siopcb->openflag ) {
		/*  �G���[�t���O�N���A  */
		h8s_sci_and( siopcb->siopinib, SSR, ~( RDRF | ORER | FER | PER ) );
	}
}


#ifndef OMIT_SCI0
/*
 *  SIO�̊����݃T�[�r�X���[�`�� (SCI0��p)
 */
void
h8s_sci0_isr_in(void)
{
	h8s_scix_isr_in(1);
}

void
h8s_sci0_isr_out(void)
{
	h8s_scix_isr_out(1);
}

/*
 *  SIO�̎�M�G���[�����݃T�[�r�X���[�`�� (SCI0��p)
 */
void
h8s_sci0_isr_error(void)
{
	h8s_scix_isr_error(1);
}

#endif /*  OMIT_SCI0  */

#if TNUM_SIOP >=2
/*
 *  SIO�̊����݃T�[�r�X���[�`�� (SCI1��p)
 */
void
h8s_sci1_isr_in(void)
{
	h8s_scix_isr_in(2);
}

void
h8s_sci1_isr_out(void)
{
	h8s_scix_isr_out(2);
}

/*
 *  SIO�̎�M�G���[�����݃T�[�r�X���[�`�� (SCI1��p)
 */
void
h8s_sci1_isr_error(void)
{
	h8s_scix_isr_error(2);
}
#endif /* TNUM_SIOP >=2 */

#if TNUM_SIOP >=3
/*
 *  SIO�̊����݃T�[�r�X���[�`�� (SCI2��p)
 */
void
h8s_sci2_isr_in(void)
{
	h8s_scix_isr_in(3);
}

void
h8s_sci2_isr_out(void)
{
	h8s_scix_isr_out(3);
}

/*
 *  SIO�̎�M�G���[�����݃T�[�r�X���[�`�� (SCI2��p)
 */
void
h8s_sci2_isr_error(void)
{
	h8s_scix_isr_error(3);
}
#endif /* TNUM_SIOP >=3 */


/*
 *  H8S ���� SCI �p�|�[�����O�o�� (POL_PORTID��p�Asys_putc�ŗ��p)
 */
void
h8s_sci_putchar_pol( char c )
{

	const SIOPINIB  *siopinib = get_siopinib( POL_PORTID );

	/* TDRE �� 1 �ɂȂ�܂ő҂� */
	while ( !(h8s_sci_reb( siopinib->reg_base, SSR ) & TDRE ) );

	h8s_sci_wrb( siopinib->reg_base, TDR, c );

	/* TDRE�N���A */
	h8s_sci_and( siopinib, SSR, ~TDRE );

	/* TEND �� 1 �ɂȂ�܂ő҂� */
	while ( !(h8s_sci_reb( siopinib->reg_base, SSR ) & TEND ) );
}
