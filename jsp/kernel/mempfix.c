/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: mempfix.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�Œ蒷�������v�[���@�\
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "wait.h"
#include "mempfix.h"

/*
 *  �Œ蒷�������v�[��ID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_mpfid;

/*
 *  �Œ蒷�������v�[���������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const MPFINIB	mpfinib_table[];

/*
 *  �Œ蒷�������v�[���Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern MPFCB	mpfcb_table[];

/*
 *  �Œ蒷�������v�[���̐�
 */
#define TNUM_MPF	((UINT)(tmax_mpfid - TMIN_MPFID + 1))

/*
 *  �Œ蒷�������v�[��ID����Œ蒷�������v�[���Ǘ��u���b�N�����o����
 *  �߂̃}�N��
 */
#define INDEX_MPF(mpfid)	((UINT)((mpfid) - TMIN_MPFID))
#define get_mpfcb(mpfid)	(&(mpfcb_table[INDEX_MPF(mpfid)]))

/*
 *  �Œ蒷�������v�[���҂����u���b�N�̒�`
 */
typedef struct fixed_memorypool_waiting_information {
	WINFO	winfo;		/* �W���̑҂����u���b�N */
	WOBJCB	*wobjcb;	/* �҂��I�u�W�F�N�g�̊Ǘ��u���b�N */
	VP	blk;		/* �l�������������u���b�N */
} WINFO_MPF;

/* 
 *  �Œ蒷�������v�[���@�\�̏�����
 */
#ifdef __mpfini

void
mempfix_initialize()
{
	UINT	i;
	MPFCB	*mpfcb;

	for (mpfcb = mpfcb_table, i = 0; i < TNUM_MPF; mpfcb++, i++) {
		queue_initialize(&(mpfcb->wait_queue));
		mpfcb->mpfinib = &(mpfinib_table[i]);
		mpfcb->unused = mpfcb->mpfinib->mpf;
		mpfcb->freelist = NULL;
	}
}

#endif /* __mpfini */

/*
 *  �Œ蒷�������v�[������u���b�N���l��
 */
#ifdef __mpfget

BOOL
mempfix_get_block(MPFCB *mpfcb, VP *p_blk)
{
	FREEL	*free;

	if (mpfcb->freelist != NULL) {
		free = mpfcb->freelist;
		mpfcb->freelist = free->next;
		*p_blk = (VP) free;
		return(TRUE);
	}
	else if (mpfcb->unused < mpfcb->mpfinib->limit) {
		*p_blk = mpfcb->unused;
		mpfcb->unused = (VP)((char *)(mpfcb->unused)
						+ mpfcb->mpfinib->blksz);
		return(TRUE);
	}
	return(FALSE);
}

#endif /* __mpfget */

/*
 *  �Œ蒷�������u���b�N�̊l��
 */
#ifdef __get_mpf

SYSCALL ER
get_mpf(ID mpfid, VP *p_blk)
{
	MPFCB	*mpfcb;
	WINFO_MPF winfo;
	ER	ercd;

	LOG_GET_MPF_ENTER(mpfid, p_blk);
	CHECK_DISPATCH();
	CHECK_MPFID(mpfid);
	mpfcb = get_mpfcb(mpfid);

	t_lock_cpu();
	if (mempfix_get_block(mpfcb, p_blk)) {
		ercd = E_OK;
	}
	else {
		wobj_make_wait((WOBJCB *) mpfcb, (WINFO_WOBJ *) &winfo);
		dispatch();
		ercd = winfo.winfo.wercd;
		if (ercd == E_OK) {
			*p_blk = winfo.blk;
		}
	}
	t_unlock_cpu();

    exit:
	LOG_GET_MPF_LEAVE(ercd, *p_blk);
	return(ercd);
}

#endif /* __get_mpf */

/*
 *  �Œ蒷�������u���b�N�̊l���i�|�[�����O�j
 */
#ifdef __pget_mpf

SYSCALL ER
pget_mpf(ID mpfid, VP *p_blk)
{
	MPFCB	*mpfcb;
	ER	ercd;

	LOG_PGET_MPF_ENTER(mpfid, p_blk);
	CHECK_TSKCTX_UNL();
	CHECK_MPFID(mpfid);
	mpfcb = get_mpfcb(mpfid);

	t_lock_cpu();
	if (mempfix_get_block(mpfcb, p_blk)) {
		ercd = E_OK;
	}
	else {
		ercd = E_TMOUT;
	}
	t_unlock_cpu();

    exit:
	LOG_PGET_MPF_LEAVE(ercd, *p_blk);
	return(ercd);
}

#endif /* __pget_mpf */

/*
 *  �Œ蒷�������u���b�N�̊l���i�^�C���A�E�g����j
 */
#ifdef __tget_mpf

SYSCALL ER
tget_mpf(ID mpfid, VP *p_blk, TMO tmout)
{
	MPFCB	*mpfcb;
	WINFO_MPF winfo;
	TMEVTB	tmevtb;
	ER	ercd;

	LOG_TGET_MPF_ENTER(mpfid, p_blk, tmout);
	CHECK_DISPATCH();
	CHECK_MPFID(mpfid);
	CHECK_TMOUT(tmout);
	mpfcb = get_mpfcb(mpfid);

	t_lock_cpu();
	if (mempfix_get_block(mpfcb, p_blk)) {
		ercd = E_OK;
	}
	else if (tmout == TMO_POL) {
		ercd = E_TMOUT;
	}
	else {
		wobj_make_wait_tmout((WOBJCB *) mpfcb, (WINFO_WOBJ *) &winfo,
						&tmevtb, tmout);
		dispatch();
		ercd = winfo.winfo.wercd;
		if (ercd == E_OK) {
			*p_blk = winfo.blk;
		}
	}
	t_unlock_cpu();

    exit:
	LOG_TGET_MPF_LEAVE(ercd, *p_blk);
	return(ercd);
}

#endif /* __tget_mpf */

/*
 *  �Œ蒷�������u���b�N�̕ԋp
 */
#ifdef __rel_mpf

SYSCALL ER
rel_mpf(ID mpfid, VP blk)
{
	MPFCB	*mpfcb;
	TCB	*tcb;
	FREEL	*free;
	ER	ercd;
    
	LOG_REL_MPF_ENTER(mpfid, blk);
	CHECK_TSKCTX_UNL();
	CHECK_MPFID(mpfid);
	mpfcb = get_mpfcb(mpfid);
	CHECK_PAR(mpfcb->mpfinib->mpf <= blk
			&& blk < mpfcb->mpfinib->limit
			&& ((char *)(blk) - (char *)(mpfcb->mpfinib->mpf))
					% mpfcb->mpfinib->blksz == 0);

	t_lock_cpu();
	if (!(queue_empty(&(mpfcb->wait_queue)))) {
		tcb = (TCB *) queue_delete_next(&(mpfcb->wait_queue));
		((WINFO_MPF *)(tcb->winfo))->blk = blk;
		if (wait_complete(tcb)) {
			dispatch();
		}
		ercd = E_OK;
	}
	else {
		free = (FREEL *) blk;
		free->next = mpfcb->freelist;
		mpfcb->freelist = free;
		ercd = E_OK;
	}
	t_unlock_cpu();

    exit:
	LOG_REL_MPF_LEAVE(ercd);
	return(ercd);
}

#endif /* __rel_mpf */
