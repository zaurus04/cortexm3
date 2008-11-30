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
 *  @(#) $Id: cyclic.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�����n���h���@�\
 */

#include "jsp_kernel.h"
#include "check.h"
#include "cyclic.h"

/*
 *  �����n���h��ID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_cycid;

/*
 *  �����n���h���������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const CYCINIB	cycinib_table[];

/*
 *  �����n���h���Ǘ��u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern CYCCB	cyccb_table[];

/*
 *  �����n���h���̐�
 */
#define TNUM_CYC	((UINT)(tmax_cycid - TMIN_CYCID + 1))

/*
 *  �����n���h��ID��������n���h���Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_CYC(cycid)	((UINT)((cycid) - TMIN_CYCID))
#define get_cyccb(cycid)	(&(cyccb_table[INDEX_CYC(cycid)]))

/*
 *  �����܂Œ�`���������n���h���̌^
 */
typedef void	(*CYCHDR)(VP_INT exinf);

/*
 *  �����n���h���@�\�̏�����
 */
#ifdef __cycini

void
cyclic_initialize()
{
	UINT	i;
	CYCCB	*cyccb;

	for (cyccb = cyccb_table, i = 0; i < TNUM_CYC; cyccb++, i++) {
		cyccb->cycinib = &(cycinib_table[i]);
		if ((cyccb->cycinib->cycatr & TA_STA) != 0) {
			cyccb->cycsta = TRUE;
			tmevtb_enqueue_cyc(cyccb,
					(EVTTIM)(cyccb->cycinib->cycphs));
		}
		else {
			cyccb->cycsta = FALSE;
		}
	}
}

#endif /* __cycini */

/*
 *  �����n���h���N���̂��߂̃^�C���C�x���g�u���b�N�̓o�^
 */
#ifdef __cycenq

void
tmevtb_enqueue_cyc(CYCCB *cyccb, EVTTIM evttim)
{
	tmevtb_enqueue_evttim(&(cyccb->tmevtb), evttim,
				(CBACK) call_cychdr, (VP) cyccb);
	cyccb->evttim = evttim;
}

#endif /* __cycenq */

/*
 *  �����n���h���̓���J�n
 */
#ifdef __sta_cyc

SYSCALL ER
sta_cyc(ID cycid)
{
	CYCCB	*cyccb;
	ER	ercd;

	LOG_STA_CYC_ENTER(cycid);
	CHECK_TSKCTX_UNL();
	CHECK_CYCID(cycid);
	cyccb = get_cyccb(cycid);

	t_lock_cpu();
	if (cyccb->cycsta) {
		tmevtb_dequeue(&(cyccb->tmevtb));
	}
	else {
		cyccb->cycsta = TRUE;
	}
	tmevtb_enqueue_cyc(cyccb, base_time + cyccb->cycinib->cyctim);
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_STA_CYC_LEAVE(ercd);
	return(ercd);
}

#endif /* __sta_cyc */

/*
 *  �����n���h���̓����~
 */
#ifdef __stp_cyc

SYSCALL ER
stp_cyc(ID cycid)
{
	CYCCB	*cyccb;
	ER	ercd;

	LOG_STP_CYC_ENTER(cycid);
	CHECK_TSKCTX_UNL();
	CHECK_CYCID(cycid);
	cyccb = get_cyccb(cycid);

	t_lock_cpu();
	if (cyccb->cycsta) {
		cyccb->cycsta = FALSE;
		tmevtb_dequeue(&(cyccb->tmevtb));
	}
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_STP_CYC_LEAVE(ercd);
	return(ercd);
}

#endif /* __stp_cyc */

/*
 *  �����n���h���N�����[�`��
 */
#ifdef __cyccal

void
call_cychdr(CYCCB *cyccb)
{
	/*
	 *  ����̋N���̂��߂̃^�C���C�x���g�u���b�N��o�^����D
	 *
	 *  �����^�C���e�B�b�N�Ŏ����n���h�����ēx�N�����ׂ��ꍇ�ɂ́C
	 *  ���̊֐����� isig_tim �ɖ߂�����ɁC�ēx���̊֐����Ă΂��
	 *  ���ƂɂȂ�D
	 */
	tmevtb_enqueue_cyc(cyccb, cyccb->evttim + cyccb->cycinib->cyctim);

	/*
	 *  �����n���h�����CCPU���b�N������ԂŌĂяo���D
	 */
	i_unlock_cpu();
	LOG_CYC_ENTER(cyccb);
	(*((CYCHDR)(cyccb->cycinib->cychdr)))(cyccb->cycinib->exinf);
	LOG_CYC_LEAVE(cyccb);
	i_lock_cpu();
}

#endif /* __cyccal */
