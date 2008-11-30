/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RICOH COMPANY,LTD. JAPAN
 * 
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: serial_mini.c,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

/*
 *	�V���A���C���^�t�F�[�X�h���C�o
 */

#include <t_services.h>
#include <serial.h>
#include <hw_serial.h>
#include "kernel_id.h"

/*
 *  �V���A���|�[�g�Ǘ��u���b�N�̒�`
 */

#define	SERIAL_BUFSZ	9	/* �V���A���C���^�t�F�[�X�p�o�b�t�@�̃T�C�Y */

typedef struct serial_queue_block {
	BOOL openflag;				/* �I�[�v���ς݃t���O */
	UH   base;					/* hardware port base address */
	ID   rsemid;				/* receive semaphore id */
	ID   ssemid;				/* send semaphore id */
	char head;					/* queue head */
	char tail;					/* queue tail */
	char size;					/* �o�b�t�@�T�C�Y */
	char buffer[SERIAL_BUFSZ];	/* �o�b�t�@�G���A */
} SQUE;

static SQUE	in_queue[TNUM_SIOP] ={
	FALSE, TADR_SFR_UART0_BASE, SERIAL_RCV_SEM1, SERIAL_SND_SEM1, 0, 0, SERIAL_BUFSZ, "",
	FALSE, TADR_SFR_UART1_BASE, SERIAL_RCV_SEM2, SERIAL_SND_SEM2, 0, 0, SERIAL_BUFSZ, ""
};

/*
 *  �V���A���|�[�g�Ǘ��u���b�N�̒�`�Ə�����
 */

#define get_sque(portid)	(&(in_queue[portid-1]))

/*
 *  SFR UART�̏�����
 */
Inline void
SFR_uart_initialize(ID portid)
{
	SQUE  *q;
	VB *ip = (VB*)(TADR_SFR_INT_BASE+TADR_SFR_S0RIC_OFFSET);

	q = get_sque(portid);
	  			/* ����M���[�h���W�X�^�̏����� */
	sil_wrb_mem((VP)(q->base+TADR_SFR_UMR_OFFSET), MR_DEF);
				/* ���M���䃌�W�X�^�̏����� */
	sil_wrb_mem((VP)(q->base+TADR_SFR_UC0_OFFSET), C0_DEF);
				/* �]�����x���W�X�^�̏����� */
	sil_wrb_mem((VP)(q->base+TADR_SFR_UBRG_OFFSET), BRG1_DEF);
				/* �����݃��x���̐ݒ� */
	set_ic_ilvl((VP)(ip + ((INT)portid-1)*2), RB_LEVEL);
	sil_wrb_mem((VP)(q->base+TADR_SFR_UC1_OFFSET), C1R_DEF);
	sil_reb_mem((VP)(q->base+TADR_SFR_URB_OFFSET));		/* �_�~�[�f�[�^��M */
	sil_reb_mem((VP)(q->base+TADR_SFR_URB_OFFSET));		/* �_�~�[�f�[�^��M */
	q->openflag = TRUE;
}

/*
 *  SQUE�̎�M�o�b�t�@����T�C�Y�����o��
 */
Inline int
queue_size(SQUE *q)
{
	int size = q->head - q->tail;
	if(size < 0)
		size += q->size;
	return size;
}

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̋N��
 */
void
serial_initialize(VP_INT exinf)
{
	SFR_uart_initialize(LOGTASK_PORTID);
}

/*
 *  �V���A���|�[�g�̃I�[�v��
 */
ER
serial_opn_por(ID portid)
{
	SQUE  *q;
	VB    *ip=(VB*)(TADR_SFR_INT_BASE+TADR_SFR_S0RIC_OFFSET);
	ER	ercd;

	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}
	q = get_sque(portid);

	_syscall(loc_cpu());
	if (q->openflag) {		/* �I�[�v���ς݂��̃`�F�b�N */
		ercd = E_OBJ;
	}
	else {
		SFR_uart_initialize(portid);
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
	SQUE  *q;
	VB    *ip=(VB*)(TADR_SFR_INT_BASE+TADR_SFR_S0RIC_OFFSET);
	ER	ercd;

	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}
	q = get_sque(portid);

	_syscall(loc_cpu());
	if (!(q->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		ercd = E_OBJ;
	}
	else {
		set_ic_ilvl((VP)(ip + ((INT)portid-1)*2), 0);
		sil_wrb_mem((VP)(q->base+TADR_SFR_UC1_OFFSET), C1S_DEF);
		q->openflag = FALSE;
		ercd = E_OK;
	}
	_syscall(unl_cpu());
	return(ercd);
}

/*
 *  �V���A���|�[�g�ւ̑��M
 */

ER_UINT
serial_wri_dat(ID portid, char *buf, UINT len)
{
	SQUE	*q;
	unsigned int	i;
	unsigned char   c;

	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	q = get_sque(portid);
	if (!(q->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		return(E_OBJ);
	}

	wai_sem(q->ssemid);
	for (i = 0; i < len; i++) {
		while((sil_reb_mem((VP)(q->base+TADR_SFR_UC1_OFFSET)) & 0x2) == 0);
		sil_wrb_mem((VP)(q->base+TADR_SFR_UTB_OFFSET), *buf++);
	}
	sig_sem(q->ssemid);
	return(len);
}

/*
 *  �V���A���|�[�g����̎�M
 */

ER_UINT
serial_rea_dat(ID portid, char *buf, UINT len)
{
	SQUE	*q;
	UINT	i;

	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	q = get_sque(portid);
	if (!(q->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		return(E_OBJ);
	}

	for (i = 0; i < len; i++) {
		if (queue_size(q) == 0)
			wai_sem(q->rsemid);
		else
			pol_sem(q->rsemid);
		_syscall(loc_cpu());
		*buf++ = q->buffer[q->tail++];
		if (q->tail >= q->size) {
			q->tail = 0;
		}
		_syscall(unl_cpu());
	}
	return(len);
}

/*
 *  �V���A���|�[�g�̐���
 */
ER
serial_ctl_por(ID portid, UINT ioctl)
{
	return(E_OK);
}

/*
 *  �V���A���|�[�g��Ԃ̎Q��
 */
ER
serial_ref_por(ID portid, T_SERIAL_RPOR *pk_rpor)
{
	SQUE	*q;

	if (sns_ctx()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(1 <= portid && portid <= TNUM_SIOP)) {
		return(E_ID);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	q = get_sque(portid);
	if (!(q->openflag)) {	/* �I�[�v���ς݂��̃`�F�b�N */
		return(E_OBJ);
	}

	pk_rpor->reacnt = queue_size(q);
	pk_rpor->wricnt = 0;
	return(E_OK);
}

/*
 *  �V���A���|�[�g�����݃T�[�r�X���[�`��
 */

void
serial_handler_in(ID portid)
{
	SQUE	*q;
	int		rdata;				/* ��M�o�b�t�@ */

	q = get_sque(portid);
	if (queue_size(q) < q->size) {
		rdata = sil_reb_mem((VP)(q->base+TADR_SFR_URB_OFFSET));	/* �f�[�^��M */
		q->buffer[q->head++] = rdata;
		if (q->head >= q->size)
			q->head = 0;
		isig_sem(q->rsemid);
	}
}

/*
 *  �����݃n���h��
 */

void
serial_in_handler1(void)
{
	serial_handler_in(1);
}

void
serial_in_handler2(void)
{
	serial_handler_in(2);
}

