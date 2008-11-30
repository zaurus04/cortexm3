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
 *  @(#) $Id: time_event.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�^�C���C�x���g�Ǘ����W���[��
 */

#ifndef _TIME_EVENT_H_
#define _TIME_EVENT_H_

/*
 *  �C�x���g���������̃f�[�^�^�̒�`
 *
 *  EVTTIM �́CRELTIM �Ƃ��Ďw��ł���͈͂����L���͈͂�\���ł���K
 *  �v������D�X�^���_�[�h�v���t�@�C���ł́CRELTIM �� 16bit �ȏ�łȂ�
 *  ��΂Ȃ�Ȃ����߁CEVTTIM �� 17bit �ȏ�ł��邱�Ƃ��K�v�ł���D����
 *  ���߁C16bit �̏ꍇ������ UINT �ł͂Ȃ��CUW �ɒ�`���Ă���D
 */
typedef UW	EVTTIM;

/*
 *  ���Ύ��ԁiRELTIM�j�Ɏw��ł���ő�l
 */
#define	TMAX_RELTIM	((((EVTTIM) 1) << (sizeof(EVTTIM) * CHAR_BIT - 1)) - 1)

/* 
 *  �^�C���C�x���g�u���b�N�̃f�[�^�^�̒�`
 */
typedef void	(*CBACK)(VP);	/* �R�[���o�b�N�֐��̌^ */

typedef struct time_event_block {
	UINT	index;		/* �^�C���C�x���g�q�[�v���ł̈ʒu */
	CBACK	callback;	/* �R�[���o�b�N�֐� */
	VP	arg;		/* �R�[���o�b�N�֐��֓n������ */
} TMEVTB;

/*
 *  �^�C���C�x���g�q�[�v���̃m�[�h�̃f�[�^�^�̒�`
 */
typedef struct time_event_node {
	EVTTIM	time;		/* �C�x���g�������� */
	TMEVTB	*tmevtb;	/* �Ή�����^�C���C�x���g�u���b�N */
} TMEVTN;

/*
 *  �^�C���C�x���g�q�[�v�ikernel_cfg.c�j
 */
extern TMEVTN	tmevt_heap[];

/*
 *  �V�X�e�������̃I�t�Z�b�g
 */
extern SYSTIM	systim_offset;

/*
 *  ���݂̃V�X�e�������i�P��: �~���b�j
 *
 *  �V�X�e���N������ 0 �ɏ���������C�ȍ~�Cisig_tim ���Ă΂��x�ɒP��
 *  �ɑ�������Dset_tim �ɂ���ĕύX����Ȃ��D
 */
extern SYSTIM	current_time;

/*
 *  ���̃^�C���e�B�b�N�̃V�X�e�������i�P��: 1�~���b�j
 */
extern SYSTIM	next_time;

/*
 *  �V�X�e�������ώZ�p�ϐ��i�P��: 1/TIM_DENO�~���b�j
 *
 *  ���̃^�C���e�B�b�N�̃V�X�e�������̉��ʌ��������i��ʌ��� next_time�j�D
 *  TIC_DENO �� 1 �̎��́C���ʌ��͏�� 0 �ł��邽�߁C���̕ϐ��͕K�v�Ȃ��D
 */
#if TIC_DENO != 1
extern UINT	next_subtime;
#endif /* TIC_DENO != 1 */

/*
 *  ���Ύ��Ԃ̃x�[�X�����i�P��: 1�~���b�j
 *
 *  ���̃^�C���e�B�b�N�̃V�X�e��������؂�グ�������DTIC_DENO �� 1 ��
 *  ���́Cnext_time �� EVTTIM �ɕϊ��������̂Ɉ�v����D
 */
#if TIC_DENO == 1
#define	base_time	((EVTTIM) next_time)
#else /* TIC_DENO == 1 */
#define	base_time	((EVTTIM)(next_time + (next_subtime > 0 ? 1 : 0)))
#endif /* TIC_DENO == 1 */

/*
 *  �^�C���C�x���g�q�[�v�̍Ō�̎g�p�̈�̃C���f�b�N�X
 *
 *  �^�C���C�x���g�q�[�v�ɓo�^����Ă���^�C���C�x���g�̐��Ɉ�v����D
 */
extern UINT	last_index;

/*
 *  �^�C���C�x���g�Ǘ����W���[���̏�����
 */
extern void	tmevt_initialize(void);

/*
 *  �^�C���C�x���g�̑}���ʒu�̒T��
 */
extern UINT	tmevt_up(UINT index, EVTTIM time);
extern UINT	tmevt_down(UINT index, EVTTIM time);

/*
 *  �^�C���C�x���g�q�[�v�ւ̓o�^�ƍ폜
 */
extern void	tmevtb_insert(TMEVTB *tmevtb, EVTTIM time);
extern void	tmevtb_delete(TMEVTB *tmevtb);

/*
 *  �^�C���C�x���g�u���b�N�̓o�^�i���Ύ��Ԏw��j
 *
 *  time �Ŏw�肵�����Ύ��Ԃ��o�ߌ�ɁCarg �������Ƃ��� callback ����
 *  �яo�����悤�ɁC�^�C���C�x���g�u���b�N tmevtb ��o�^����D
 */
Inline void
tmevtb_enqueue(TMEVTB *tmevtb, RELTIM time, CBACK callback, VP arg)
{
	assert(time <= TMAX_RELTIM);

	tmevtb->callback = callback;
	tmevtb->arg = arg;
	tmevtb_insert(tmevtb, base_time + time);
}

/*
 *  �^�C���C�x���g�u���b�N�̓o�^�i�C�x���g���������w��j
 *
 *  time �Ŏw�肵���C�x���g���������ɁCarg �������Ƃ��� callback ����
 *  �яo�����悤�ɁC�^�C���C�x���g�u���b�N tmevtb ��o�^����D
 */
Inline void
tmevtb_enqueue_evttim(TMEVTB *tmevtb, EVTTIM time, CBACK callback, VP arg)
{
	tmevtb->callback = callback;
	tmevtb->arg = arg;
	tmevtb_insert(tmevtb, time);
}

/*
 *  �^�C���C�x���g�u���b�N�̓o�^����
 */
Inline void
tmevtb_dequeue(TMEVTB *tmevtb)
{
	tmevtb_delete(tmevtb);
}

#endif /* _TIME_EVENT_H_ */
