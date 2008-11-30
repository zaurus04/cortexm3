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
 *  @(#) $Id: eventflag.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�C�x���g�t���O�@�\
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "eventflag.h"

/*
 *  �C�x���g�t���OID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_flgid;

/*
 *  �C�x���g�t���O�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const FLGINIB	flginib_table[];

/*
 *  �C�x���g�t���O�Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern FLGCB	flgcb_table[];

/*
 *  �C�x���g�t���O�̐�
 */
#define TNUM_FLG	((UINT)(tmax_flgid - TMIN_FLGID + 1))

/*
 *  �C�x���g�t���OID����C�x���g�t���O�Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_FLG(flgid)	((UINT)((flgid) - TMIN_FLGID))
#define get_flgcb(flgid)	(&(flgcb_table[INDEX_FLG(flgid)]))

/*
 *  �C�x���g�t���O�҂����u���b�N�̒�`
 *
 *  flgptn �́Cwaiptn ����� wfmode �Ɠ����Ɏg�����Ƃ͂Ȃ����߁Cunion 
 *  ���g���΃�������ߖ񂷂邱�Ƃ��\�ł���D
 */
typedef struct eventflag_waiting_information {
	WINFO	winfo;		/* �W���̑҂����u���b�N */
	WOBJCB	*wobjcb;	/* �҂��I�u�W�F�N�g�̊Ǘ��u���b�N */
	FLGPTN	waiptn;		/* �҂��p�^�[�� */
	MODE	wfmode;		/* �҂����[�h */
	FLGPTN	flgptn;		/* �҂��������̃p�^�[�� */
} WINFO_FLG;

/*
 *  �C�x���g�t���O�@�\�̏�����
 */
#ifdef __flgini

void
eventflag_initialize(void)
{
	UINT	i;
	FLGCB	*flgcb;

	for (flgcb = flgcb_table, i = 0; i < TNUM_FLG; flgcb++, i++) {
		queue_initialize(&(flgcb->wait_queue));
		flgcb->flginib = &(flginib_table[i]);
		flgcb->flgptn = flgcb->flginib->iflgptn;
	}
}

#endif /* __flgini */

/*
 *  �C�x���g�t���O�҂����������̃`�F�b�N
 */
#ifdef __flgcnd

BOOL
eventflag_cond(FLGCB *flgcb, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
	if ((wfmode & TWF_ORW) != 0 ? (flgcb->flgptn & waiptn) != 0
				: (flgcb->flgptn & waiptn) == waiptn) {
		*p_flgptn = flgcb->flgptn;
		if ((flgcb->flginib->flgatr & TA_CLR) != 0) {
			flgcb->flgptn = 0;
		}
		return(TRUE);
	}
	return(FALSE);
}

#endif /* __flgcnd */

/*
 *  �C�x���g�t���O�̃Z�b�g
 */
#ifdef __set_flg

SYSCALL ER
set_flg(ID flgid, FLGPTN setptn)
{
	FLGCB	*flgcb;
	TCB	*tcb;
	WINFO_FLG *winfo;
	ER	ercd;

	LOG_SET_FLG_ENTER(flgid, setptn);
	CHECK_TSKCTX_UNL();
	CHECK_FLGID(flgid);
	flgcb = get_flgcb(flgid);

	t_lock_cpu();
	flgcb->flgptn |= setptn;
	if (!(queue_empty(&(flgcb->wait_queue)))) {
		tcb = (TCB *)(flgcb->wait_queue.next);
		winfo = (WINFO_FLG *)(tcb->winfo);
		if (eventflag_cond(flgcb, winfo->waiptn,
					winfo->wfmode, &(winfo->flgptn))) {
			queue_delete(&(tcb->task_queue));
			if (wait_complete(tcb)) {
				dispatch();
			}
		}
	}
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_SET_FLG_LEAVE(ercd);
	return(ercd);
}

#endif /* __set_flg */

/*
 *  �C�x���g�t���O�̃Z�b�g�i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef __iset_flg

SYSCALL ER
iset_flg(ID flgid, FLGPTN setptn)
{
	FLGCB	*flgcb;
	TCB	*tcb;
	WINFO_FLG *winfo;
	ER	ercd;

	LOG_ISET_FLG_ENTER(flgid, setptn);
	CHECK_INTCTX_UNL();
	CHECK_FLGID(flgid);
	flgcb = get_flgcb(flgid);

	i_lock_cpu();
	flgcb->flgptn |= setptn;
	if (!(queue_empty(&(flgcb->wait_queue)))) {
		tcb = (TCB *)(flgcb->wait_queue.next);
		winfo = (WINFO_FLG *)(tcb->winfo);
		if (eventflag_cond(flgcb, winfo->waiptn,
					winfo->wfmode, &(winfo->flgptn))) {
			queue_delete(&(tcb->task_queue));
			if (wait_complete(tcb)) {
				reqflg = TRUE;
			}
		}
	}
	ercd = E_OK;
	i_unlock_cpu();

    exit:
	LOG_ISET_FLG_LEAVE(ercd);
	return(ercd);
}

#endif /* __iset_flg */

/*
 *  �C�x���g�t���O�̃N���A
 */
#ifdef __clr_flg

SYSCALL ER
clr_flg(ID flgid, FLGPTN clrptn)
{
	FLGCB	*flgcb;
	ER	ercd;

	LOG_CLR_FLG_ENTER(flgid, clrptn);
	CHECK_TSKCTX_UNL();
	CHECK_FLGID(flgid);
	flgcb = get_flgcb(flgid);

	t_lock_cpu();
	flgcb->flgptn &= clrptn; 
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_CLR_FLG_LEAVE(ercd);
	return(ercd);
}

#endif /* __clr_flg */

/*
 *  �C�x���g�t���O�҂�
 */
#ifdef __wai_flg

SYSCALL ER
wai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
	FLGCB	*flgcb;
	WINFO_FLG winfo;
	ER	ercd;

	LOG_WAI_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn);
	CHECK_DISPATCH();
	CHECK_FLGID(flgid);
	CHECK_PAR(waiptn != 0);
	CHECK_PAR((wfmode & ~TWF_ORW) == 0);
	flgcb = get_flgcb(flgid);

	t_lock_cpu();
	if (!(queue_empty(&(flgcb->wait_queue)))) {
		ercd = E_ILUSE;
	}
	else if (eventflag_cond(flgcb, waiptn, wfmode, p_flgptn)) {
		ercd = E_OK;
	}
	else {
		winfo.waiptn = waiptn;
		winfo.wfmode = wfmode;
		wobj_make_wait((WOBJCB *) flgcb, (WINFO_WOBJ *) &winfo);
		dispatch();
		ercd = winfo.winfo.wercd;
		if (ercd == E_OK) {
			*p_flgptn = winfo.flgptn;
		}
	}
	t_unlock_cpu();

    exit:
	LOG_WAI_FLG_LEAVE(ercd, *p_flgptn);
	return(ercd);
}

#endif /* __wai_flg */

/*
 *  �C�x���g�t���O�҂��i�|�[�����O�j
 */
#ifdef __pol_flg

SYSCALL ER
pol_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn)
{
	FLGCB	*flgcb;
	ER	ercd;

	LOG_POL_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn);
	CHECK_TSKCTX_UNL();
	CHECK_FLGID(flgid);
	CHECK_PAR(waiptn != 0);
	CHECK_PAR((wfmode & ~TWF_ORW) == 0);
	flgcb = get_flgcb(flgid);

	t_lock_cpu();
	if (!(queue_empty(&(flgcb->wait_queue)))) {
		ercd = E_ILUSE;
	}
	else if (eventflag_cond(flgcb, waiptn, wfmode, p_flgptn)) {
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

    exit:
	LOG_POL_FLG_LEAVE(ercd, *p_flgptn);
	return(ercd);
}

#endif /* __pol_flg */

/*
 *  �C�x���g�t���O�҂��i�^�C���A�E�g����j
 */
#ifdef __twai_flg

SYSCALL ER
twai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn, TMO tmout)
{
	FLGCB	*flgcb;
	WINFO_FLG winfo;
	TMEVTB	tmevtb;
	ER	ercd;

	LOG_TWAI_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn, tmout);
	CHECK_DISPATCH();
	CHECK_FLGID(flgid);
	CHECK_PAR(waiptn != 0);
	CHECK_PAR((wfmode & ~TWF_ORW) == 0);
	CHECK_TMOUT(tmout);
	flgcb = get_flgcb(flgid);

	t_lock_cpu();
	if (!(queue_empty(&(flgcb->wait_queue)))) {
		ercd = E_ILUSE;
	}
	else if (eventflag_cond(flgcb, waiptn, wfmode, p_flgptn)) {
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		winfo.waiptn = waiptn;
		winfo.wfmode = wfmode;
		wobj_make_wait_tmout((WOBJCB *) flgcb, (WINFO_WOBJ *) &winfo,
						&tmevtb, tmout);
		dispatch();
		ercd = winfo.winfo.wercd;
		if (ercd == E_OK) {
			*p_flgptn = winfo.flgptn;
		}
	}
	t_unlock_cpu();

    exit:
	LOG_TWAI_FLG_LEAVE(ercd, *p_flgptn);
	return(ercd);
}

#endif /* __twai_flg */
