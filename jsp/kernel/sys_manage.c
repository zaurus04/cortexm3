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
 *  @(#) $Id: sys_manage.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�V�X�e����ԊǗ��@�\
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  �^�X�N�̗D�揇�ʂ̉�]
 */
#ifdef __rot_rdq

SYSCALL ER
rot_rdq(PRI tskpri)
{
	UINT	pri;
	ER	ercd;

	LOG_ROT_RDQ_ENTER(tskpri);
	CHECK_TSKCTX_UNL();
	CHECK_TPRI_SELF(tskpri);

	t_lock_cpu();
	pri = (tskpri == TPRI_SELF) ? runtsk->priority : INT_PRIORITY(tskpri);
	if (rotate_ready_queue(pri)) {
		dispatch();
	}
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_ROT_RDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* __rot_rdq */

/*
 *  �^�X�N�̗D�揇�ʂ̉�]�i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef __irot_rdq

SYSCALL ER
irot_rdq(PRI tskpri)
{
	ER	ercd;

	LOG_IROT_RDQ_ENTER(tskpri);
	CHECK_INTCTX_UNL();
	CHECK_TPRI(tskpri);

	i_lock_cpu();
	if (rotate_ready_queue(INT_PRIORITY(tskpri))) {
		reqflg = TRUE;
	}
	ercd = E_OK;
	i_unlock_cpu();

    exit:
	LOG_IROT_RDQ_LEAVE(ercd);
	return(ercd);
}

#endif /* __irot_rdq */

/*
 *  ���s��Ԃ̃^�X�NID�̎Q��
 */
#ifdef __get_tid

SYSCALL ER
get_tid(ID *p_tskid)
{
	ER	ercd;

	LOG_GET_TID_ENTER(p_tskid);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_tskid = TSKID(runtsk);
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_GET_TID_LEAVE(ercd, *p_tskid);
	return(ercd);
}

#endif /* __get_tid */

/*
 *  ���s��Ԃ̃^�X�NID�̎Q�Ɓi��^�X�N�R���e�L�X�g�p�j
 */
#ifdef __iget_tid

SYSCALL ER
iget_tid(ID *p_tskid)
{
	ER	ercd;

	LOG_IGET_TID_ENTER(p_tskid);
	CHECK_INTCTX_UNL();

	i_lock_cpu();
	*p_tskid = (runtsk == NULL) ? TSK_NONE : TSKID(runtsk);
	ercd = E_OK;
	i_unlock_cpu();

    exit:
	LOG_IGET_TID_LEAVE(ercd, *p_tskid);
	return(ercd);
}

#endif /* __iget_tid */

/*
 *  CPU���b�N��Ԃւ̈ڍs
 */
#ifdef __loc_cpu

SYSCALL ER
loc_cpu(void)
{
	ER	ercd;

	LOG_LOC_CPU_ENTER();
	CHECK_TSKCTX();

	if (!(t_sense_lock())) {
		t_lock_cpu();
	}
	ercd = E_OK;

    exit:
	LOG_LOC_CPU_LEAVE(ercd);
	return(ercd);
}

#endif /* __loc_cpu */

/*
 *  CPU���b�N��Ԃւ̈ڍs�i��^�X�N�R���e�L�X�g�p�j
 */
#ifdef __iloc_cpu

SYSCALL ER
iloc_cpu(void)
{
	ER	ercd;

	LOG_ILOC_CPU_ENTER();
	CHECK_INTCTX();

	if (!(i_sense_lock())) {
		i_lock_cpu();
	}
	ercd = E_OK;

    exit:
	LOG_ILOC_CPU_LEAVE(ercd);
	return(ercd);
}

#endif /* __iloc_cpu */

/*
 *  CPU���b�N��Ԃ̉���
 *
 *  CPU���b�N���́C�f�B�X�p�b�`���K�v�ƂȂ�T�[�r�X�R�[�����Ăяo����
 *  �Ƃ͂ł��Ȃ����߁CCPU���b�N��Ԃ̉������Ƀf�B�X�p�b�`�����N������
 *  �K�v�͂Ȃ��D
 */
#ifdef __unl_cpu

SYSCALL ER
unl_cpu(void)
{
	ER	ercd;

	LOG_UNL_CPU_ENTER();
	CHECK_TSKCTX();

	if (t_sense_lock()) {
		t_unlock_cpu();
	}
	ercd = E_OK;

    exit:
	LOG_UNL_CPU_LEAVE(ercd);
	return(ercd);
}

#endif /* __unl_cpu */

/*
 *  CPU���b�N��Ԃ̉����i��^�X�N�R���e�L�X�g�p�j
 *
 *  CPU���b�N���́C�f�B�X�p�b�`���K�v�ƂȂ�T�[�r�X�R�[�����Ăяo����
 *  �Ƃ͂ł��Ȃ����߁CCPU���b�N��Ԃ̉������Ƀf�B�X�p�b�`���̋N����v
 *  ������K�v�͂Ȃ��D
 */
#ifdef __iunl_cpu

SYSCALL ER
iunl_cpu(void)
{
	ER	ercd;

	LOG_IUNL_CPU_ENTER();
	CHECK_INTCTX();

	if (i_sense_lock()) {
		i_unlock_cpu();
	}
	ercd = E_OK;

    exit:
	LOG_IUNL_CPU_LEAVE(ercd);
	return(ercd);
}

#endif /* __iunl_cpu */

/*
 *  �f�B�X�p�b�`�̋֎~
 */
#ifdef __dis_dsp

SYSCALL ER
dis_dsp(void)
{
	ER	ercd;

	LOG_DIS_DSP_ENTER();
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	enadsp = FALSE;
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_DIS_DSP_LEAVE(ercd);
	return(ercd);
}

#endif /* __dis_dsp */

/*
 *  �f�B�X�p�b�`�̋���
 */
#ifdef __ena_dsp

SYSCALL ER
ena_dsp(void)
{
	ER	ercd;

	LOG_ENA_DSP_ENTER();
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	enadsp = TRUE;
	if (runtsk != schedtsk) {
		dispatch();
	}
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_ENA_DSP_LEAVE(ercd);
	return(ercd);
}

#endif /* __ena_dsp */

/*
 *  �R���e�L�X�g�̎Q��
 */
#ifdef __sns_ctx

SYSCALL BOOL
sns_ctx(void)
{
	BOOL	state;

	LOG_SNS_CTX_ENTER();
	state = sense_context() ? TRUE : FALSE;
	LOG_SNS_CTX_LEAVE(state);
	return(state);
}

#endif /* __sns_ctx */

/*
 *  CPU���b�N��Ԃ̎Q��
 */
#ifdef __sns_loc

SYSCALL BOOL
sns_loc(void)
{
	BOOL	state;

	LOG_SNS_LOC_ENTER();
	state = sense_lock() ? TRUE : FALSE;
	LOG_SNS_LOC_LEAVE(state);
	return(state);
}

#endif /* __sns_loc */

/*
 *  �f�B�X�p�b�`�֎~��Ԃ̎Q��
 */
#ifdef __sns_dsp

SYSCALL BOOL
sns_dsp(void)
{
	BOOL	state;

	LOG_SNS_DSP_ENTER();
	state = !(enadsp) ? TRUE : FALSE;
	LOG_SNS_DSP_LEAVE(state);
	return(state);
}

#endif /* __sns_dsp */

/*
 *  �f�B�X�p�b�`�ۗ���Ԃ̎Q��
 */
#ifdef __sns_dpn

SYSCALL BOOL
sns_dpn(void)
{
	BOOL	state;

	LOG_SNS_DPN_ENTER();
	state = (sense_context() || sense_lock() || !(enadsp)) ? TRUE : FALSE;
	LOG_SNS_DPN_LEAVE(state);
	return(state);
}

#endif /* __sns_dpn */

/*
 *  �J�[�l�������Ԃ̎Q��
 */
#ifdef __vsns_ini

SYSCALL BOOL
vsns_ini(void)
{
	BOOL	state;

	LOG_VSNS_INI_ENTER();
	state = !(iniflg) ? TRUE : FALSE;
	LOG_VSNS_INI_LEAVE(state);
	return(state);
}

#endif /* __vsns_ini */
