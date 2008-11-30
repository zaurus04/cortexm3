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
 *  @(#) $Id: usart.c,v 1.4 2008/06/22 08:13:28 suikan Exp $
 */

/*
 *	��PD72001�p �Ȉ�SIO�h���C�o
 */

#include <s_services.h>
#include <usart.h>

/*
 *  �f�o�C�X���W�X�^�̃A�N�Z�X�Ԋu���ԁinsec�P�ʁj
 *
 *  200�Ƃ����l�ɂ��܂荪���͂Ȃ��D
 */
#define	UPD72001_DELAY	200

/*
 *  ��PD72001�̃��W�X�^�̔ԍ�
 */
#define	UPD72001_CR0	0x00u		/* �R���g���[�����W�X�^ */
#define	UPD72001_CR1	0x01u
#define	UPD72001_CR2	0x02u
#define	UPD72001_CR3	0x03u
#define	UPD72001_CR4	0x04u
#define	UPD72001_CR5	0x05u
#define	UPD72001_CR10	0x0au
#define	UPD72001_CR12	0x0cu
#define	UPD72001_CR14	0x0eu
#define	UPD72001_CR15	0x0fu

#define	UPD72001_SR0	0x00u		/* �X�e�[�^�X���W�X�^ */

/*
 *  �R���g���[�����W�X�^�̐ݒ�l
 */
#define CR_RESET	0x18u		/* �|�[�g���Z�b�g�R�}���h */

#define CR0_EOI		0x38u		/* EOI�iEnd of Interrupt�j*/

#define CR1_DOWN	0x00u		/* �S�����݂��֎~ */
#define CR1_RECV	0x10u		/* ��M�����݋��r�b�g */
#define CR1_SEND	0x02u		/* ���M�����݋��r�b�g */

#define CR3_DEF		0xc1u		/* �f�[�^ 8bit�C��M�C�l�[�u�� */
#define CR4_DEF		0x44u		/* �X�g�b�v�r�b�g 1bit�C�p���e�B�Ȃ� */
#define CR5_DEF		0xeau		/* �f�[�^ 8bit�C���M�C�l�[�u�� */

#define CR10_DEF	0x00u		/* NRZ */
#define CR14_DEF	0x07u		/* �{�[���[�g�W�F�l���[�^�C�l�[�u�� */
#define CR15_DEF	0x56u		/* �{�[���[�g�W�F�l���[�^�g�p */

#define SR0_RECV	0x01u		/* ��M�ʒm�r�b�g */
#define SR0_SEND	0x04u		/* ���M�\�r�b�g */

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̒�`
 */
typedef struct sio_port_initialization_block {
	VP	data;		/* �f�[�^���W�X�^�̔Ԓn */
	VP	ctrl;		/* �R���g���[�����W�X�^�̔Ԓn */

	UB	cr3_def;	/* CR3�̐ݒ�l�i��M�r�b�g���j*/
	UB	cr4_def;	/* CR4�̐ݒ�l�i�X�g�b�v�r�b�g�C�p���e�B�j*/
	UB	cr5_def;	/* CR5�̐ݒ�l�i���M�r�b�g���j*/
	UB	brg1_def;	/* �{�[���[�g��ʂ̐ݒ�l */
	UB	brg2_def;	/* �{�[���[�g���ʂ̐ݒ�l */
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
struct sio_port_control_block {
	const SIOPINIB	*siopinib;	/* �V���A��I/O�|�[�g�������u���b�N */
	VP_INT		exinf;		/* �g����� */
	BOOL		openflag;	/* �I�[�v���ς݃t���O */
	UB		cr1;		/* CR1�̐ݒ�l�i�����݋��j*/
	BOOL		getready;	/* ��������M������� */
	BOOL		putready;	/* �����𑗐M�ł����� */
};

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 *
 *  ID = 1 ���|�[�gB�CID = 2 ���|�[�gA�ɑΉ������Ă���D
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
//	{ (VP) TADR_UPD72001_DATAB, (VP) TADR_UPD72001_CTRLB,
//		CR3_DEF, CR4_DEF, CR5_DEF, BRG1_DEF, BRG2_DEF },
	{ (VP) 0, (VP) 0,
		0, 0, 0, 0,0 }
#if TNUM_SIOP >= 2
	{ (VP) TADR_UPD72001_DATAA, (VP) TADR_UPD72001_CTRLA,
		CR3_DEF, CR4_DEF, CR5_DEF, BRG1_DEF, BRG2_DEF },
#endif /* TNUM_SIOP >= 2 */
};

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
 *  �f�o�C�X���W�X�^�ւ̃A�N�Z�X�֐�
 */
Inline UB
upd72001_read_reg(VP addr)
{
	CM3NI
	/*
	UB	val;

	val = (UB) upd72001_reb_reg(addr);
	sil_dly_nse(UPD72001_DELAY);
	return(val);
	*/
}

Inline void
upd72001_write_reg(VP addr, UB val)
{
	CM3NI
	/*
	upd72001_wrb_reg(addr, (VB) val);
	sil_dly_nse(UPD72001_DELAY);
	*/
}

Inline UB
upd72001_read_ctrl(VP addr, UB reg)
{
	upd72001_write_reg(addr, reg);
	return(upd72001_read_reg(addr));
}

Inline void
upd72001_write_ctrl(VP addr, UB reg, UB val)
{
	upd72001_write_reg(addr, reg);
	upd72001_write_reg(addr, val);
}

Inline void
upd72001_write_brg(VP addr, UB reg, UB val, UB brg2, UB brg1)
{
	upd72001_write_reg(addr, reg);
	upd72001_write_reg(addr, val);
	upd72001_write_reg(addr, brg2);
	upd72001_write_reg(addr, brg1);
	(void) upd72001_read_reg(addr);		/* �_�~�[���[�h */
}

/*
 *  ��Ԃ̓Ǐo���iSR0�̓Ǐo���j
 *
 *  ��PD72001�́C��ԁiSR0�j����x�ǂނƎ�M�ʒm�r�b�g�������Ă��܂���
 *  �߁C��Ԃ�ǂݏo���֐���݂��C�V���A��I/O�|�[�g�Ǘ��u���b�N����
 *  getready �Ɏ�M�ʒm��ԁCputready �ɑ��M�\��Ԃ�ۑ����Ă���i��
 *  �M�\��Ԃ̕ۑ��͕s�v��������Ȃ��j�D
 *  ��ԃ��W�X�^��ǂ�ł���M�ʒm�r�b�g�������Ȃ��f�o�C�X�i�����炪��
 *  �ʂƎv����j�ł́C���̊֐��͕K�v�Ȃ��D
 */
static void
upd72001_get_stat(SIOPCB *siopcb)
{
	UB	sr0;

	sr0 = upd72001_read_ctrl(siopcb->siopinib->ctrl, UPD72001_SR0);
	if ((sr0 & SR0_RECV) != 0) {
		siopcb->getready = TRUE;
	}
	if ((sr0 & SR0_SEND) != 0) {
		siopcb->putready = TRUE;
	}
}

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
upd72001_getready(SIOPCB *siopcb)
{
	upd72001_get_stat(siopcb);
	return(siopcb->getready);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
upd72001_putready(SIOPCB *siopcb)
{
	upd72001_get_stat(siopcb);
	return(siopcb->putready);
}

/*
 *  ��M���������̎�o��
 */
Inline char
upd72001_getchar(SIOPCB *siopcb)
{
	siopcb->getready = FALSE;
	return((char) upd72001_read_reg(siopcb->siopinib->data));
}

/*
 *  ���M���镶���̏�����
 */
Inline void
upd72001_putchar(SIOPCB *siopcb, char c)
{
	siopcb->putready = FALSE;
	upd72001_write_reg(siopcb->siopinib->data, (UB) c);
}

/*
 *  EOI�iEnd Of Interrupt�j���s
 */
Inline void
upd72001_eoi()
{
	CM3NI
//	upd72001_write_ctrl((VP) TADR_UPD72001_CTRLA, UPD72001_CR0, CR0_EOI);
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
upd72001_initialize()
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
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
upd72001_openflag(void)
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
upd72001_opn_por(ID siopid, VP_INT exinf)
{
	/*
	SIOPCB		*siopcb;
	const SIOPINIB	*siopinib;

	siopcb = get_siopcb(siopid);
	siopinib = siopcb->siopinib;

	upd72001_write_reg(siopinib->ctrl, CR_RESET);
	if (!upd72001_openflag()) {
		upd72001_write_ctrl((VP) TADR_UPD72001_CTRLA,
						UPD72001_CR2, 0x18);
		upd72001_write_ctrl((VP) TADR_UPD72001_CTRLB,
						UPD72001_CR2, 0x00);
	}
	siopcb->cr1 = CR1_DOWN;
	upd72001_write_ctrl(siopinib->ctrl, UPD72001_CR1, siopcb->cr1);
	upd72001_write_ctrl(siopinib->ctrl, UPD72001_CR4, siopinib->cr4_def);
	upd72001_write_brg(siopinib->ctrl, UPD72001_CR12, 
				0x01, siopinib->brg2_def, siopinib->brg1_def);
	upd72001_write_brg(siopinib->ctrl, UPD72001_CR12,
				0x02, siopinib->brg2_def, siopinib->brg1_def);
	upd72001_write_ctrl(siopinib->ctrl, UPD72001_CR15, CR15_DEF);
	upd72001_write_ctrl(siopinib->ctrl, UPD72001_CR14, CR14_DEF);
	upd72001_write_ctrl(siopinib->ctrl, UPD72001_CR10, CR10_DEF);
	upd72001_write_ctrl(siopinib->ctrl, UPD72001_CR3, siopinib->cr3_def);
	upd72001_write_ctrl(siopinib->ctrl, UPD72001_CR5, siopinib->cr5_def);
	siopcb->exinf = exinf;
	siopcb->getready = siopcb->putready = FALSE;
	siopcb->openflag = TRUE;
	return(siopcb);
	*/
	CM3NI
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
upd72001_cls_por(SIOPCB *siopcb)
{
	upd72001_write_ctrl(siopcb->siopinib->ctrl, UPD72001_CR1, CR1_DOWN);
	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
upd72001_snd_chr(SIOPCB *siopcb, char c)
{
	if (upd72001_putready(siopcb)) {
		upd72001_putchar(siopcb, c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
upd72001_rcv_chr(SIOPCB *siopcb)
{
	if (upd72001_getready(siopcb)) {
		return((INT)(UB) upd72001_getchar(siopcb));
	}
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
upd72001_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	cr1_bit = 0;

	switch (cbrtn) {
	case SIO_ERDY_SND:
		cr1_bit = CR1_SEND;
		break;
	case SIO_ERDY_RCV:
		cr1_bit = CR1_RECV;
		break;
	}
	siopcb->cr1 |= cr1_bit;
	upd72001_write_ctrl(siopcb->siopinib->ctrl, UPD72001_CR1, siopcb->cr1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
upd72001_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	UB	cr1_bit = 0;

	switch (cbrtn) {
	case SIO_ERDY_SND:
		cr1_bit = CR1_SEND;
		break;
	case SIO_ERDY_RCV:
		cr1_bit = CR1_RECV;
		break;
	}
	siopcb->cr1 &= ~cr1_bit;
	upd72001_write_ctrl(siopcb->siopinib->ctrl, UPD72001_CR1, siopcb->cr1);
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
upd72001_isr_siop(SIOPCB *siopcb)
{
	if ((siopcb->cr1 & CR1_RECV) != 0 && upd72001_getready(siopcb)) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		upd72001_ierdy_rcv(siopcb->exinf);
	}
	if ((siopcb->cr1 & CR1_SEND) != 0 && upd72001_putready(siopcb)) {
		/*
		 *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
		 */
		upd72001_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
upd72001_isr()
{
	if (siopcb_table[0].openflag) {
		upd72001_isr_siop(&(siopcb_table[0]));
	}
#if TNUM_SIOP >= 2
	if (siopcb_table[1].openflag) {
		upd72001_isr_siop(&(siopcb_table[1]));
	}
#endif /* TNUM_SIOP >= 2 */
	upd72001_eoi();
}
