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
 *  @(#) $Id: time_event.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�^�C���C�x���g�Ǘ����W���[��
 */

#include "jsp_kernel.h"
#include "check.h"
#include "time_event.h"

/*
 *  �^�C���C�x���g�q�[�v����}�N��
 */
#define	PARENT(index)	((index) >> 1)		/* �e�m�[�h�����߂� */
#define	LCHILD(index)	((index) << 1)		/* �E�̎q�m�[�h�����߂� */
#define	TMEVT_NODE(index)	(tmevt_heap[(index) - 1])

/*
 *  �C�x���g����������r�}�N��
 *
 *  �C�x���g���������́Ccurrent_time ����̑��Βl�Ŕ�r����D���Ȃ킿�C
 *  current_time ���ŏ��l�i�ł��߂������j�Ccurrent_time - 1 ���ő�l
 *  �i�ł����������j�Ƃ݂Ȃ��Ĕ�r����D
 */
#define	EVTTIM_LT(t1, t2) (((t1) - current_time) < ((t2) - current_time))
#define	EVTTIM_LE(t1, t2) (((t1) - current_time) <= ((t2) - current_time))

#ifdef __tmeini

/*
 *  �V�X�e�������̃I�t�Z�b�g
 */
SYSTIM	systim_offset;

/*
 *  ���݂̃V�X�e�������i�P��: �~���b�j
 *
 *  �����ɂ́C�O�̃^�C���e�B�b�N�̃V�X�e�������D
 */
SYSTIM	current_time;

/*
 *  ���̃^�C���e�B�b�N�̃V�X�e�������i�P��: 1�~���b�j
 */
SYSTIM	next_time;

/*
 *  �V�X�e�������ώZ�p�ϐ��i�P��: 1/TIM_DENO�~���b�j
 */
#if TIC_DENO != 1
UINT	next_subtime;
#endif /* TIC_DENO != 1 */

/*
 *  �^�C���C�x���g�q�[�v�̍Ō�̎g�p�̈�̃C���f�b�N�X
 */
UINT	last_index;

/*
 *  �^�C�}���W���[���̏�����
 */
void
tmevt_initialize(void)
{
	systim_offset = 0;
	current_time = 0;
#if TIC_DENO == 1
	next_time = current_time + TIC_NUME;
#else /* TIC_DENO == 1 */
	next_subtime += TIC_NUME;
	next_time = current_time + next_subtime / TIC_DENO;
	next_subtime %= TIC_DENO;
#endif /* TIC_DENO == 1 */
	last_index = 0;
}

#endif /* __tmeini */

/*
 *  �^�C���C�x���g�̑}���ʒu��������ɒT��
 *
 *  ���� time �ɔ�������^�C���C�x���g��}������m�[�h���󂯂邽�߂ɁC
 *  �q�[�v�̏�Ɍ������ċ�m�[�h���ړ�������D�ړ��O�̋�m�[�h�̈ʒu�� 
 *  index �ɓn���ƁC�ړ���̋�m�[�h�̈ʒu�i���Ȃ킿�}���ʒu�j��Ԃ��D
 */
#ifdef __tmeup

UINT
tmevt_up(UINT index, EVTTIM time)
{
	UINT	parent;

	while (index > 1) {
		/*
		 *  �e�m�[�h�̃C�x���g���������̕��������i�܂��͓����j
		 *  �Ȃ�΁Cindex ���}���ʒu�Ȃ̂Ń��[�v�𔲂���D
		 */
		parent = PARENT(index);
		if (EVTTIM_LE(TMEVT_NODE(parent).time, time)) {
			break;
		}

		/*
		 *  �e�m�[�h�� index �̈ʒu�Ɉړ�������D
		 */
		TMEVT_NODE(index) = TMEVT_NODE(parent);
		TMEVT_NODE(index).tmevtb->index = index;

		/*
		 *  index ��e�m�[�h�̈ʒu�ɍX�V�D
		 */
		index = parent;
	}
	return(index);
}

#endif /* __tmeup */

/*
 *  �^�C���C�x���g�̑}���ʒu���������ɒT��
 *
 *  ���� time �ɔ�������^�C���C�x���g��}������m�[�h���󂯂邽�߂ɁC
 *  �q�[�v�̉��Ɍ������ċ�m�[�h���ړ�������D�ړ��O�̋�m�[�h�̈ʒu�� 
 *  index �ɓn���ƁC�ړ���̋�m�[�h�̈ʒu�i���Ȃ킿�}���ʒu�j��Ԃ��D
 */
#ifdef __tmedown

UINT
tmevt_down(UINT index, EVTTIM time)
{
	UINT	child;

	while ((child = LCHILD(index)) <= last_index) {
		/*
		 *  ���E�̎q�m�[�h�̃C�x���g�����������r���C��������
		 *  �q�m�[�h�̈ʒu�� child �ɐݒ肷��D�ȉ��̎q�m�[�h
		 *  �́C�����őI�΂ꂽ���̎q�m�[�h�̂��ƁD
		 */
		if (child + 1 <= last_index
			&& EVTTIM_LT(TMEVT_NODE(child + 1).time,
				  TMEVT_NODE(child).time)) {
			child = child + 1;
		}

		/*
		 *  �q�m�[�h�̃C�x���g���������̕����x���i�܂��͓����j
		 *  �Ȃ�΁Cindex ���}���ʒu�Ȃ̂Ń��[�v�𔲂���D
		 */
		if (EVTTIM_LE(time, TMEVT_NODE(child).time)) {
			break;
		}

		/*
		 *  �q�m�[�h�� index �̈ʒu�Ɉړ�������D
		 */
		TMEVT_NODE(index) = TMEVT_NODE(child);
		TMEVT_NODE(index).tmevtb->index = index;

		/*
		 *  index ���q�m�[�h�̈ʒu�ɍX�V�D
		 */
		index = child;
	}
	return(index);
}

#endif /* __tmedown */

/*
 * �^�C���C�x���g�q�[�v�ւ̓o�^
 *
 *  �^�C���C�x���g�u���b�N tmevtb ���Ctime �Ŏw�肵�����Ԃ��o�ߌ�ɃC
 *  �x���g����������悤�ɁC�^�C���C�x���g�q�[�v�ɓo�^����D
 */
#ifdef __tmeins

void
tmevtb_insert(TMEVTB *tmevtb, EVTTIM time)
{
	UINT	index;

	/*
	 *  last_index ���C���N�������g���C���������ɑ}���ʒu��T���D
	 */
	index = tmevt_up(++last_index, time);

	/*
	 *  �^�C���C�x���g�� index �̈ʒu�ɑ}������D
	 */ 
	TMEVT_NODE(index).time = time;
	TMEVT_NODE(index).tmevtb = tmevtb;
	tmevtb->index = index;
}

#endif /* __tmeins */

/*
 *  �^�C���C�x���g�q�[�v����̍폜
 */
#ifdef __tmedel

void
tmevtb_delete(TMEVTB *tmevtb)
{
	UINT	index = tmevtb->index;
	UINT	parent;
	EVTTIM	event_time = TMEVT_NODE(last_index).time;

	/*
	 *  �폜�ɂ��^�C���C�x���g�q�[�v����ɂȂ�ꍇ�͉������Ȃ��D
	 */
	if (--last_index == 0) {
		return;
	}

	/*
	 *  �폜�����m�[�h�̈ʒu�ɍŌ�̃m�[�h�ilast_index + 1 �̈ʒu
	 *  �̃m�[�h�j��}�����C�����K�؂Ȉʒu�ֈړ�������D���ۂɂ́C
	 *  �Ō�̃m�[�h�����ۂɑ}������̂ł͂Ȃ��C�폜�����m�[�h�̈�
	 *  �u����m�[�h�ɂȂ�̂ŁC�Ō�̃m�[�h��}�����ׂ��ʒu�֌���
	 *  �ċ�m�[�h���ړ�������D
	 *  �Ō�̃m�[�h�̃C�x���g�����������C�폜�����m�[�h�̐e�m�[�h
	 *  �̃C�x���g�����������O�̏ꍇ�ɂ́C��Ɍ������đ}���ʒu��
	 *  �T���D�����łȂ��ꍇ�ɂ́C���Ɍ������ĒT���D
	 */
	if (index > 1 && EVTTIM_LT(event_time,
				TMEVT_NODE(parent = PARENT(index)).time)) {
		/*
		 *  �e�m�[�h�� index �̈ʒu�Ɉړ�������D
		 */
		TMEVT_NODE(index) = TMEVT_NODE(parent);
		TMEVT_NODE(index).tmevtb->index = index;

		/*
		 *  �폜�����m�[�h�̐e�m�[�h�����Ɍ������đ}���ʒu��
		 *  �T���D
		 */
		index = tmevt_up(parent, event_time);
	}
	else {
		/*
		 *  �폜�����m�[�h���牺�Ɍ������đ}���ʒu��T���D
		 */
		index = tmevt_down(index, event_time);
	}

	/*
	 *  �Ō�̃m�[�h�� index �̈ʒu�ɑ}������D
	 */ 
	TMEVT_NODE(index) = TMEVT_NODE(last_index + 1);
	TMEVT_NODE(index).tmevtb->index = index;
}

#endif /* __tmedel */

/*
 *  �^�C���C�x���g�q�[�v�̐擪�̃m�[�h�̍폜
 */
Inline void
tmevtb_delete_top(void)
{
	UINT	index;
	EVTTIM	event_time = TMEVT_NODE(last_index).time;

	/*
	 *  �폜�ɂ��^�C���C�x���g�q�[�v����ɂȂ�ꍇ�͉������Ȃ��D
	 */
	if (--last_index == 0) {
		return;
	}

	/*
	 *  ���[�g�m�[�h�ɍŌ�̃m�[�h�ilast_index + 1 �̈ʒu�̃m�[�h�j
	 *  ��}�����C�����K�؂Ȉʒu�ֈړ�������D���ۂɂ́C�Ō�̃m�[
	 *  �h�����ۂɑ}������̂ł͂Ȃ��C���[�g�m�[�h����m�[�h�ɂȂ�
	 *  �̂ŁC�Ō�̃m�[�h��}�����ׂ��ʒu�֌����ċ�m�[�h���ړ���
	 *  ����D
	 */
	index = tmevt_down(1, event_time);

	/*
	 *  �Ō�̃m�[�h�� index �̈ʒu�ɑ}������D
	 */ 
	TMEVT_NODE(index) = TMEVT_NODE(last_index + 1);
	TMEVT_NODE(index).tmevtb->index = index;
}

/*
 *  �^�C���e�B�b�N�̋���
 *
 *  TIC_NUME < TIC_DENO �̎��́C���Z���g�킸�Ɏ����̍X�V���ł��邪�C�\�[
 *  �X�R�[�h��ǂ݂₷���ɂ��邽�߂� #if �̑��p������Ă���D
 */
#ifdef __isig_tim

SYSCALL ER
isig_tim(void)
{
	TMEVTB	*tmevtb;
	ER	ercd;

	LOG_ISIG_TIM_ENTER();
	CHECK_INTCTX_UNL();
	i_lock_cpu();

	/*
	 *  next_time ���C�x���g���������̑����i�܂��͓����j�^�C���C
	 *  �x���g���C�^�C���C�x���g�q�[�v����폜���C�R�[���o�b�N�֐�
	 *  ���Ăяo���D
	 */
	while (last_index > 0 && EVTTIM_LE(TMEVT_NODE(1).time, next_time)) {
		tmevtb = TMEVT_NODE(1).tmevtb;
		tmevtb_delete_top();
		(*(tmevtb->callback))(tmevtb->arg);

		/*
		 *  �����ŗD��x�̍��������݂��󂯕t����D
		 */
		i_unlock_cpu();
		i_lock_cpu();
	}

	/*
	 *  current_time ���X�V����D
	 */
	current_time = next_time;

	/*
	 *  next_time�Cnext_subtime ���X�V����D
	 */
#if TIC_DENO == 1
	next_time = current_time + TIC_NUME;
#else /* TIC_DENO == 1 */
	next_subtime += TIC_NUME % TIC_DENO;
	next_time = current_time + TIC_NUME / TIC_DENO;
	if (next_subtime >= TIC_DENO) {
		next_subtime -= TIC_DENO;
		next_time += 1u;
	}
#endif /* TIC_DENO == 1 */

	ercd = E_OK;
	i_unlock_cpu();

    exit:
	LOG_ISIG_TIM_LEAVE(ercd);
	return(ercd);
}

#endif /* __isig_tim */
