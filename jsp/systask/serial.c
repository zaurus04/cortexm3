/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: serial.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�V���A���C���^�t�F�[�X�h���C�o
 */

#include <t_services.h>
#include <serial.h>
#include <hw_serial.h>
#include "kernel_id.h"

/*
 *  �o�b�t�@�T�C�Y�ƃt���[����Ɋ֘A����萔
 */

#define	SERIAL_BUFSZ	256		/* �h���C�o�̃o�b�t�@�T�C�Y */

#define	FC_STOP		'\023'		/* �R���g���[��-S */
#define	FC_START	'\021'		/* �R���g���[��-Q */

#define	BUFCNT_STOP	(SERIAL_BUFSZ - 64)	/* STOP�𑗂������� */
#define	BUFCNT_START	(SERIAL_BUFSZ - 128)	/* START�𑗂������� */

/*
 *  �N���[�Y�̍ۂɑ��M��҂ő厞�ԁimsec�P�ʁj
 */
#define	MAX_FLUSH_WAIT	1000

/*
 *  �V���A���|�[�g�������u���b�N
 */
typedef struct serial_port_initialization_block {
	ID	rcv_semid;	/* ��M�o�b�t�@�Ǘ��p�Z�}�t�H��ID */
	ID	snd_semid;	/* ���M�o�b�t�@�Ǘ��p�Z�}�t�H��ID */
} SPINIB;

static const SPINIB spinib_table[TNUM_PORT] = {
	{ SERIAL_RCV_SEM1, SERIAL_SND_SEM1 }
#if TNUM_PORT >= 2
	,{ SERIAL_RCV_SEM2, SERIAL_SND_SEM2 }
#endif
#if TNUM_PORT >= 3
	,{ SERIAL_RCV_SEM3, SERIAL_SND_SEM3 }
#endif
};

/*
 *  �V���A���|�[�g�Ǘ��u���b�N
 */
typedef struct serial_port_control_block {
	const SPINIB *spinib;	/* �V���A���|�[�g�������u���b�N */
	SIOPCB	*siopcb;	/* �V���A��I/O�|�[�g�Ǘ��u���b�N */
	BOOL	openflag;	/* �I�[�v���ς݃t���O */
	UINT	ioctl;		/* ���쐧��̐ݒ�l */

	UINT	rcv_read_ptr;	/* ��M�o�b�t�@�Ǐo���|�C���^ */
	UINT	rcv_write_ptr;	/* ��M�o�b�t�@�����݃|�C���^ */
	UINT	rcv_count;	/* ��M�o�b�t�@���̕����� */
	char	rcv_fc_chr;	/* ����ׂ� START/STOP */
	BOOL	rcv_stopped;	/* STOP �𑗂�����Ԃ��H */

	UINT	snd_read_ptr;	/* ���M�o�b�t�@�Ǐo���|�C���^ */
	UINT	snd_write_ptr;	/* ���M�o�b�t�@�����݃|�C���^ */
	UINT	snd_count;	/* ���M�o�b�t�@���̕����� */
	BOOL	snd_stopped;	/* STOP ���󂯎������Ԃ��H */

	char	rcv_buffer[SERIAL_BUFSZ];	/* ��M�o�b�t�@ */
	char	snd_buffer[SERIAL_BUFSZ];	/* ���M�o�b�t�@ */
} SPCB;

static SPCB	spcb_table[TNUM_PORT];

/*
 *  �V���A���|�[�gID����V���A���|�[�g�Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_PORT(portid)	((UINT)((portid) - 1))
#define get_spcb(portid)	(&(spcb_table[INDEX_PORT(portid)]))

/*
 *  �|�C���^�̃C���N�������g
 */
#define INC_PTR(ptr)		{ if (++ptr == SERIAL_BUFSZ) ptr = 0; }

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̏��������[�`��
 */
void
serial_initialize(VP_INT exinf)
{
	SPCB	*spcb;
	UINT	i;

	sio_initialize();
	for (spcb = spcb_table, i = 0; i < TNUM_PORT; spcb++, i++) {
		spcb->spinib = &(spinib_table[i]);
		spcb->openflag = FALSE;
	}
}

/*
 *  �V���A���|�[�g�̃I�[�v��
 */
ER
serial_opn_por(ID portid)
{
	SPCB	*spcb;
	ER	ercd;

	if (sns_ctx()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}
	spcb = get_spcb(portid);

	_syscall(loc_cpu());
	if (spcb->openflag) {		/* �I�[�v���ς݂��̃`�F�b�N */
		ercd = E_OBJ;
	}
	else {
		/*
		 *  �ϐ��̏�����
		 */
		spcb->ioctl = (IOCTL_ECHO | IOCTL_CRLF
					| IOCTL_FCSND | IOCTL_FCRCV);


		spcb->rcv_read_ptr = spcb->rcv_write_ptr = 0;
		spcb->rcv_count = 0;
		spcb->rcv_fc_chr = '\0';
		spcb->rcv_stopped = FALSE;

		spcb->snd_read_ptr = spcb->snd_write_ptr = 0;
		spcb->snd_count = 0;
		spcb->snd_stopped = FALSE;

		/*
		 *  �n�[�h�E�F�A�ˑ��̃I�[�v������
		 */
		spcb->siopcb = sio_opn_por(portid, (VP_INT) spcb);

		/*
		 *  ��M�ʒm�R�[���o�b�N��������D
		 */
		sio_ena_cbr(spcb->siopcb, SIO_ERDY_RCV);
		spcb->openflag = TRUE;
		ercd = E_OK;
	}
	_syscall(unl_cpu());
	return(ercd);
}

/*
 *  �V���A���|�[�g�̃N���[�Y
 */
ER
serial_cls_por(ID portid)
{
	SPCB	*spcb;
	ER	ercd;

	if (sns_ctx()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}
	spcb = get_spcb(portid);

	_syscall(loc_cpu());
	if (!(spcb->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		ercd = E_OBJ;
	}
	else {
		/*
		 *  �n�[�h�E�F�A�ˑ��̃N���[�Y����
		 */
		sio_cls_por(spcb->siopcb);
		spcb->openflag = FALSE;
		ercd = E_OK;
	}
	_syscall(unl_cpu());
	return(ercd);
}

/*
 *  �V���A���|�[�g�ւ̕������M
 */
Inline BOOL
serial_snd_chr(SPCB *spcb, char c)
{
	if (sio_snd_chr(spcb->siopcb, c)) {
		return(TRUE);
	}
	else {
		sio_ena_cbr(spcb->siopcb, SIO_ERDY_SND);
		return(FALSE);
	}
}

/*
 *  �V���A���|�[�g�ւ̑��M
 */
static BOOL
serial_wri_chr(SPCB *spcb, char c)
{
	BOOL	buffer_full;

	/*
	 *  LF �̑O�� CR �𑗐M����D
	 */
	if (c == '\n' && (spcb->ioctl & IOCTL_CRLF) != 0) {
		if (serial_wri_chr(spcb, '\r')) {
			_syscall(wai_sem(spcb->spinib->snd_semid));
		}
	}

	_syscall(loc_cpu());
	if (spcb->snd_count == 0 && !(spcb->snd_stopped)
				&& serial_snd_chr(spcb, c)) {
		/*
		 *  �V���A��I/O�f�o�C�X�̑��M���W�X�^�ɕ��������邱
		 *  �Ƃɐ��������ꍇ�D
		 */
		buffer_full = FALSE;
	}
	else {
		/*
		 *  ���M�o�b�t�@�ɕ���������D
		 */
		spcb->snd_buffer[spcb->snd_write_ptr] = c;
		INC_PTR(spcb->snd_write_ptr);
		spcb->snd_count++;
		buffer_full = (spcb->snd_count == SERIAL_BUFSZ);
	}
	_syscall(unl_cpu());
	return(buffer_full);
}

ER_UINT
serial_wri_dat(ID portid, char *buf, UINT len)
{
	SPCB	*spcb;
	BOOL	buffer_full;
	UINT	i;

	if (sns_dpn()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	spcb = get_spcb(portid);
	if (!(spcb->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		return(E_OBJ);
	}

	buffer_full = TRUE;		/* ���[�v��1��߂� wai_sem ���� */
	for (i = 0; i < len; i++) {
		if (buffer_full) {
			_syscall(wai_sem(spcb->spinib->snd_semid));
		}
		buffer_full = serial_wri_chr(spcb, *buf++);
	}
	if (!buffer_full) {
		_syscall(sig_sem(spcb->spinib->snd_semid));
	}
	return((ER_UINT) len);
}

/*
 *  �V���A���|�[�g����̎�M
 */
static BOOL
serial_rea_chr(SPCB *spcb, char *c)
{
	BOOL	buffer_empty;

	_syscall(loc_cpu());

	/*
	 *  ��M�o�b�t�@���當�������o���D
	 */
	*c = spcb->rcv_buffer[spcb->rcv_read_ptr];
	INC_PTR(spcb->rcv_read_ptr);
	spcb->rcv_count--;
	buffer_empty = (spcb->rcv_count == 0);

	/*
	 *  START �𑗐M����D
	 */
	if (spcb->rcv_stopped && spcb->rcv_count <= BUFCNT_START) {
		if (!serial_snd_chr(spcb, FC_START)) {
			spcb->rcv_fc_chr = FC_START;
		}
		spcb->rcv_stopped = FALSE;
	}
	_syscall(unl_cpu());

	/*
	 *  �G�R�[�o�b�N�����D
	 */
	if ((spcb->ioctl & IOCTL_ECHO) != 0) {
		_syscall(wai_sem(spcb->spinib->snd_semid));
		if (!serial_wri_chr(spcb, *c)) {
			_syscall(sig_sem(spcb->spinib->snd_semid));
		}
	}
	return(buffer_empty);
}

ER_UINT
serial_rea_dat(ID portid, char *buf, UINT len)
{
	SPCB	*spcb;
	BOOL	buffer_empty;
	UINT	i;

	if (sns_dpn()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	spcb = get_spcb(portid);
	if (!(spcb->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		return(E_OBJ);
	}

	buffer_empty = TRUE;		/* ���[�v��1��߂� wai_sem ���� */
	for (i = 0; i < len; i++) {
		if (buffer_empty) {
			_syscall(wai_sem(spcb->spinib->rcv_semid));
		}
		buffer_empty = serial_rea_chr(spcb, buf++);
	}
	if (!buffer_empty) {
		_syscall(sig_sem(spcb->spinib->rcv_semid));
	}
	return((ER_UINT) len);
}

/*
 *  �V���A���|�[�g�̐���
 */
ER
serial_ctl_por(ID portid, UINT ioctl)
{
	SPCB	*spcb;

	if (sns_ctx()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	spcb = get_spcb(portid);
	if (!(spcb->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		return(E_OBJ);
	}

	spcb->ioctl = ioctl;
	return(E_OK);
}

/*
 *  �V���A���|�[�g��Ԃ̎Q��
 */
ER
serial_ref_por(ID portid, T_SERIAL_RPOR *pk_rpor)
{
	SPCB	*spcb;

	if (sns_ctx()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_PORT)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	spcb = get_spcb(portid);
	if (!(spcb->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		return(E_OBJ);
	}

	pk_rpor->reacnt = spcb->rcv_count;
	pk_rpor->wricnt = spcb->snd_count;
	return(E_OK);
}

/*
 *  �V���A���|�[�g����̑��M�\�R�[���o�b�N
 */
void
sio_ierdy_snd(VP_INT exinf)
{
	SPCB	*spcb;

	spcb = (SPCB *) exinf;
	if (spcb->rcv_fc_chr != '\0') {
		/*
		 *  START/STOP �𑗐M����D
		 */
		(void) sio_snd_chr(spcb->siopcb, spcb->rcv_fc_chr);
		spcb->rcv_fc_chr = '\0';
	}
	else if (!(spcb->snd_stopped) && spcb->snd_count > 0) {
		/*
		 *  ���M�o�b�t�@�����當�������o���đ��M����D
		 */
		(void) sio_snd_chr(spcb->siopcb,
				spcb->snd_buffer[spcb->snd_read_ptr]);
		INC_PTR(spcb->snd_read_ptr);
		if (spcb->snd_count == SERIAL_BUFSZ) {
			_syscall(isig_sem(spcb->spinib->snd_semid));
		}
		spcb->snd_count--;
	}
	else {
		/*
		 *  ���M���ׂ��������Ȃ��ꍇ�́C���M�\�R�[���o�b�N��
		 *  �֎~����D
		 */
		sio_dis_cbr(spcb->siopcb, SIO_ERDY_SND);
	}
}

/*
 *  �V���A���|�[�g����̎�M�ʒm�R�[���o�b�N
 */
void
sio_ierdy_rcv(VP_INT exinf)
{
	SPCB	*spcb;
	char	c;

	spcb = (SPCB *) exinf;
	c = (char) sio_rcv_chr(spcb->siopcb);
	if ((spcb->ioctl & IOCTL_FCSND) != 0 && c == FC_STOP) {
		/*
		 *  ���M���ꎞ��~����D���M���̕����͂��̂܂ܑ��M����D
		 */
		spcb->snd_stopped = TRUE;
	}
	else if (spcb->snd_stopped && (c == FC_START
				|| (spcb->ioctl & IOCTL_FCANY) != 0)) {
		/*
		 *  ���M���ĊJ����D
		 */
		spcb->snd_stopped = FALSE;
		if (spcb->snd_count > 0) {
			c = spcb->snd_buffer[spcb->snd_read_ptr];
			if (serial_snd_chr(spcb, c)) {
				INC_PTR(spcb->snd_read_ptr);
				if (spcb->snd_count == SERIAL_BUFSZ) {
					_syscall(isig_sem(spcb->spinib
								->snd_semid));
				}
				spcb->snd_count--;
			}
		}
	}
	else if ((spcb->ioctl & IOCTL_FCSND) != 0 && c == FC_START) {
		/*
		 *  ���M�ɑ΂��ăt���[���䂵�Ă���ꍇ�CSTART �͎̂Ă�D
		 */
	}
	else if (spcb->rcv_count == SERIAL_BUFSZ) {
		/*
		 *  �o�b�t�@�t���̏ꍇ�C��M�����������̂Ă�D
		 */
	}
	else {
		/*
		 *  ��M������������M�o�b�t�@�ɓ����D
		 */
		spcb->rcv_buffer[spcb->rcv_write_ptr] = c;
		INC_PTR(spcb->rcv_write_ptr);
		if (spcb->rcv_count == 0) {
			_syscall(isig_sem(spcb->spinib->rcv_semid));
		}
		spcb->rcv_count++;

		/*
		 *  STOP �𑗐M����D
		 */
		if ((spcb->ioctl & IOCTL_FCRCV) != 0 && !(spcb->rcv_stopped)
					&& (spcb->rcv_count >= BUFCNT_STOP)) {
			if (!serial_snd_chr(spcb, FC_STOP)) {
				spcb->rcv_fc_chr = FC_STOP;
			}
			spcb->rcv_stopped = TRUE;
		}
	}
}
