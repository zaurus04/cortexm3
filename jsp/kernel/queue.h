/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: queue.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�L���[���색�C�u����
 *
 *  ���̃L���[���색�C�u�����ł́C�L���[�w�b�_���܂ރ����O�\���̃_�u��
 *  �����N�L���[�������D��̓I�ɂ́C�L���[�w�b�_�̎��G���g���̓L���[��
 *  �擪�̃G���g���C�O�G���g���̓L���[�̖����̃G���g���Ƃ���D�܂��C�L
 *  ���[�̐擪�̃G���g���̑O�G���g���ƁC�L���[�̖����̃G���g���̎��G��
 *  �g���́C�L���[�w�b�_�Ƃ���D��̃L���[�́C���G���g���C�O�G���g����
 *  ���������g���w���L���[�w�b�_�ł���킷�D
 */

#ifndef	_QUEUE_H_
#define	_QUEUE_H_

/*
 *  �L���[�̃f�[�^�\���̒�`
 */
typedef struct queue {
	struct queue *next;		/* ���G���g���ւ̃|�C���^ */
	struct queue *prev;		/* �O�G���g���ւ̃|�C���^ */
} QUEUE;

/*
 *  �L���[�̏�����
 *
 *  queue �ɂ̓L���[�w�b�_���w�肷��D
 */
Inline void
queue_initialize(QUEUE *queue)
{
	queue->prev = queue->next = queue;
}

/*
 *  �L���[�̑O�G���g���ւ̑}��
 *
 *  queue �̑O�� entry ��}������Dqueue �ɃL���[�w�b�_���w�肵���ꍇ
 *  �ɂ́C�L���[�̖����� entry ��}�����邱�ƂɂȂ�D
 */
Inline void
queue_insert_prev(QUEUE *queue, QUEUE *entry)
{
	entry->prev = queue->prev;
	entry->next = queue;
	queue->prev->next = entry;
	queue->prev = entry;
}

/*
 *  �G���g���̍폜
 *
 *  entry ���L���[����폜����D
 */
Inline void
queue_delete(QUEUE *entry)
{
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;
}

/*
 *  �L���[�̎��G���g���̎�o��
 *
 *  queue �̎��G���g�����L���[����폜���C�폜�����G���g����Ԃ��Dqueue
 *  �ɃL���[�w�b�_���w�肵���ꍇ�ɂ́C�L���[�̐擪�̃G���g�������o��
 *  ���ƂɂȂ�Dqueue �ɋ�̃L���[���w�肵�ČĂяo���Ă͂Ȃ�Ȃ��D
 */
Inline QUEUE *
queue_delete_next(QUEUE *queue)
{
	QUEUE	*entry;

	assert(queue->next != queue);
	entry = queue->next;
	queue->next = entry->next;
	entry->next->prev = queue;
	return(entry);
}

/*
 *  �L���[���󂩂ǂ����̃`�F�b�N
 *
 *  queue �ɂ̓L���[�w�b�_���w�肷��D
 */
Inline BOOL
queue_empty(QUEUE *queue)
{
	if (queue->next == queue) {
		assert(queue->prev == queue);
		return(TRUE);
	}
	return(FALSE);
}

#endif /* _QUEUE_H_ */
