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
 *  @(#) $Id: exception.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	CPU��O�Ǘ��@�\
 */

#include "jsp_kernel.h"
#include "task.h"
#include "exception.h"

/*
 *  CPU��O�n���h���ԍ��̐��ikernel_cfg.c�j
 */
extern const UINT	tnum_excno;

/*
 *  CPU��O�n���h���������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const EXCINIB	excinib_table[];

/* 
 *  CPU��O�n���h���Ǘ��@�\�̏�����
 */
#ifdef __excini

void
exception_initialize()
{
	UINT		i;
	const EXCINIB	*excinib;

	for (excinib = excinib_table, i = 0; i < tnum_excno; excinib++, i++) {
		define_exc(excinib->excno, excinib->exchdr);
	}
}

#endif /* __excini */

/*
 *  CPU��O�̔��������R���e�L�X�g�̎Q��
 */
#ifdef __vxsns_ctx

SYSCALL BOOL
vxsns_ctx(VP p_excinf)
{
	BOOL	state;

	LOG_VXSNS_CTX_ENTER(p_excinf);
	state = exc_sense_context(p_excinf) ? TRUE : FALSE;
	LOG_VXSNS_CTX_LEAVE(state);
	return(state);
}

#endif /* __vxsns_ctx */

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
#ifdef __vxsns_loc

SYSCALL BOOL
vxsns_loc(VP p_excinf)
{
	BOOL	state;

	LOG_VXSNS_LOC_ENTER(p_excinf);
	state = exc_sense_lock(p_excinf) ? TRUE : FALSE;
	LOG_VXSNS_LOC_LEAVE(state);
	return(state);
}

#endif /* __vxsns_loc */

/*
 *  CPU��O�̔����������̃f�B�X�p�b�`�֎~��Ԃ̎Q��
 *
 *  sns_dsp �Ɠ���̏������e�ƂȂ�D
 */
#ifdef __vxsns_dsp

SYSCALL BOOL
vxsns_dsp(VP p_excinf)
{
	BOOL	state;

	LOG_VXSNS_DSP_ENTER(p_excinf);
	state = !(enadsp) ? TRUE : FALSE;
	LOG_VXSNS_DSP_LEAVE(state);
	return(state);
}

#endif /* __vxsns_dsp */

/*
 *  CPU��O�̔����������̃f�B�X�p�b�`�ۗ���Ԃ̎Q��
 */
#ifdef __vxsns_dpn

SYSCALL BOOL
vxsns_dpn(VP p_excinf)
{
	BOOL	state;

	LOG_VXSNS_DPN_ENTER(p_excinf);
	state = (exc_sense_context(p_excinf) || exc_sense_lock(p_excinf)
					|| !(enadsp)) ? TRUE : FALSE;
	LOG_VXSNS_DPN_LEAVE(state);
	return(state);
}

#endif /* __vxsns_dpn */

/*
 *  CPU��O�̔����������̃^�X�N��O�����֎~��Ԃ̎Q��
 *
 *  sns_tex �Ɠ���̏������e�ƂȂ�D
 */
#ifdef __vxsns_tex

SYSCALL BOOL
vxsns_tex(VP p_excinf)
{
	BOOL	state;

	LOG_VXSNS_TEX_ENTER(p_excinf);
	state = (runtsk != NULL && runtsk->enatex) ? FALSE : TRUE;
	LOG_VXSNS_TEX_LEAVE(state);
	return(state);
}

#endif /* __vxsns_tex */
