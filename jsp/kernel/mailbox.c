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
 *  @(#) $Id: mailbox.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	���[���{�b�N�X�@�\
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "mailbox.h"

/*
 *  ���[���{�b�N�XID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_mbxid;

/*
 *  ���[���{�b�N�X�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const MBXINIB	mbxinib_table[];

/*
 *  ���[���{�b�N�X�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern MBXCB	mbxcb_table[];

/*
 *  ���[���{�b�N�X�̐�
 */
#define TNUM_MBX	((UINT)(tmax_mbxid - TMIN_MBXID + 1))

/*
 *  ���[���{�b�N�XID���烁�[���{�b�N�X�Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_MBX(mbxid)	((UINT)((mbxid) - TMIN_MBXID))
#define get_mbxcb(mbxid)	(&(mbxcb_table[INDEX_MBX(mbxid)]))

/*
 *  ���[���{�b�N�X�҂����u���b�N�̒�`
 */
typedef struct mailbox_waiting_information {
	WINFO	winfo;		/* �W���̑҂����u���b�N */
	WOBJCB	*wobjcb;	/* �҂��I�u�W�F�N�g�̊Ǘ��u���b�N */
	T_MSG	*pk_msg;	/* ��M�������b�Z�[�W */
} WINFO_MBX;

/* 
 *  ���[���{�b�N�X�@�\�̏�����
 */
#ifdef __mbxini

void
mailbox_initialize()
{
	UINT	i;
	MBXCB	*mbxcb;

	for (mbxcb = mbxcb_table, i = 0; i < TNUM_MBX; mbxcb++, i++) {
		queue_initialize(&(mbxcb->wait_queue));
		mbxcb->mbxinib = &(mbxinib_table[i]);
		mbxcb->head = NULL;
	}
}

#endif /* __mbxini */

/*
 *  ���b�Z�[�W�D��x�̎�o��
 */
#define	MSGPRI(pk_msg)	(((T_MSG_PRI *) pk_msg)->msgpri)

/*
 *  �D��x�����b�Z�[�W�L���[�ւ̑}��
 */
Inline void
enqueue_msg_pri(T_MSG **p_prevmsg_next, T_MSG *pk_msg)
{
	T_MSG	*pk_nextmsg;

	while ((pk_nextmsg = *p_prevmsg_next) != NULL) {
		if (MSGPRI(pk_nextmsg) > MSGPRI(pk_msg)) {
			break;
		}
		p_prevmsg_next = &(pk_nextmsg->next);
	}
	pk_msg->next = pk_nextmsg;
	*p_prevmsg_next = pk_msg;
}

/*
 *  ���[���{�b�N�X�ւ̑��M
 */
#ifdef __snd_mbx

SYSCALL ER
snd_mbx(ID mbxid, T_MSG *pk_msg)
{
	MBXCB	*mbxcb;
	TCB	*tcb;
	ER	ercd;
    
	LOG_SND_MBX_ENTER(mbxid, pk_msg);
	CHECK_TSKCTX_UNL();
	CHECK_MBXID(mbxid);
	mbxcb = get_mbxcb(mbxid);
	CHECK_PAR((mbxcb->mbxinib->mbxatr & TA_MPRI) == 0
		|| (TMIN_MPRI <= MSGPRI(pk_msg)
			&& MSGPRI(pk_msg) <= mbxcb->mbxinib->maxmpri));

	t_lock_cpu();
	if (!(queue_empty(&(mbxcb->wait_queue)))) {
		tcb = (TCB *) queue_delete_next(&(mbxcb->wait_queue));
		((WINFO_MBX *)(tcb->winfo))->pk_msg = pk_msg;
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else if ((mbxcb->mbxinib->mbxatr & TA_MPRI) != 0) {
		enqueue_msg_pri(&(mbxcb->head), pk_msg);
		ercd = E_OK;
	}
	else {
		pk_msg->next = NULL;
		if (mbxcb->head != NULL) {
			mbxcb->last->next = pk_msg;
		}
		else {
			mbxcb->head = pk_msg;
		}
		mbxcb->last = pk_msg;
		ercd = E_OK;
	}
	t_unlock_cpu();

    exit:
	LOG_SND_MBX_LEAVE(ercd);
	return(ercd);
}

#endif /* __snd_mbx */

/*
 *  ���[���{�b�N�X����̎�M
 */
#ifdef __rcv_mbx

SYSCALL ER
rcv_mbx(ID mbxid, T_MSG **ppk_msg)
{
	MBXCB	*mbxcb;
	WINFO_MBX winfo;
	ER	ercd;
    
	LOG_RCV_MBX_ENTER(mbxid, ppk_msg);
	CHECK_DISPATCH();
	CHECK_MBXID(mbxid);
	mbxcb = get_mbxcb(mbxid);
    
	t_lock_cpu();
	if (mbxcb->head != NULL) {
		*ppk_msg = mbxcb->head;
		mbxcb->head = (*ppk_msg)->next;
		ercd = E_OK;
	}
	else {
		wobj_make_wait((WOBJCB *) mbxcb, (WINFO_WOBJ *) &winfo);
		dispatch();
		ercd = winfo.winfo.wercd;
		if (ercd == E_OK) {
			*ppk_msg = winfo.pk_msg;
		}
	}
	t_unlock_cpu();

    exit:
	LOG_RCV_MBX_LEAVE(ercd, *ppk_msg);
	return(ercd);
}

#endif /* __rcv_mbx */

/*
 *  ���[���{�b�N�X����̎�M�i�|�[�����O�j
 */
#ifdef __prcv_mbx

SYSCALL ER
prcv_mbx(ID mbxid, T_MSG **ppk_msg)
{
	MBXCB	*mbxcb;
	ER	ercd;
    
	LOG_PRCV_MBX_ENTER(mbxid, ppk_msg);
	CHECK_TSKCTX_UNL();
	CHECK_MBXID(mbxid);
	mbxcb = get_mbxcb(mbxid);
    
	t_lock_cpu();
	if (mbxcb->head != NULL) {
		*ppk_msg = mbxcb->head;
		mbxcb->head = (*ppk_msg)->next;
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

    exit:
	LOG_PRCV_MBX_LEAVE(ercd, *ppk_msg);
	return(ercd);
}

#endif /* __prcv_mbx */

/*
 *  ���[���{�b�N�X����̎�M�i�^�C���A�E�g����j
 */
#ifdef __trcv_mbx

SYSCALL ER
trcv_mbx(ID mbxid, T_MSG **ppk_msg, TMO tmout)
{
	MBXCB	*mbxcb;
	WINFO_MBX winfo;
	TMEVTB	tmevtb;
	ER	ercd;
    
	LOG_TRCV_MBX_ENTER(mbxid, ppk_msg, tmout);
	CHECK_DISPATCH();
	CHECK_MBXID(mbxid);
	CHECK_TMOUT(tmout);
	mbxcb = get_mbxcb(mbxid);
    
	t_lock_cpu();
	if (mbxcb->head != NULL) {
		*ppk_msg = mbxcb->head;
		mbxcb->head = (*ppk_msg)->next;
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		wobj_make_wait_tmout((WOBJCB *) mbxcb, (WINFO_WOBJ *) &winfo,
						&tmevtb, tmout);
		dispatch();
		ercd = winfo.winfo.wercd;
		if (ercd == E_OK) {
			*ppk_msg = winfo.pk_msg;
		}
	}
	t_unlock_cpu();

    exit:
	LOG_TRCV_MBX_LEAVE(ercd, *ppk_msg);
	return(ercd);
}

#endif /* __trcv_mbx */
