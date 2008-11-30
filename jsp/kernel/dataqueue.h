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
 *  @(#) $Id: dataqueue.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�f�[�^�L���[�@�\
 */

#ifndef _DATAQUEUE_H_
#define _DATAQUEUE_H_

#include "queue.h"

/*
 *  �f�[�^�L���[�������u���b�N
 */
typedef struct dataqueue_initialization_block {
	ATR	dtqatr;		/* �f�[�^�L���[���� */
	UINT	dtqcnt;		/* �f�[�^�L���[�̈�̗e�� */
	VP	dtq;		/* �f�[�^�L���[�̈�̐擪�Ԓn */
} DTQINIB;

/*
 *  �f�[�^�L���[�Ǘ��u���b�N
 */
typedef struct dataqueue_control_block {
	QUEUE	swait_queue;	/* �f�[�^�L���[���M�҂��L���[ */
	const DTQINIB *dtqinib;	/* �f�[�^�L���[�������u���b�N�ւ̃|�C���^ */
	QUEUE	rwait_queue;	/* �f�[�^�L���[��M�҂��L���[ */
	UINT	count;		/* �f�[�^�L���[���̃f�[�^�̐� */
	UINT	head;		/* �ŏ��̃f�[�^�̊i�[�ꏊ */
	UINT	tail;		/* �Ō�̃f�[�^�̊i�[�ꏊ�̎� */
} DTQCB;

/*
 *  �f�[�^�L���[�@�\�̏�����
 */
extern void	dataqueue_initialize(void);

/*
 *  �f�[�^�L���[�̈�Ƀf�[�^���i�[
 */
extern BOOL	enqueue_data(DTQCB *dtqcb, VP_INT data);

/*
 *  �f�[�^�L���[�̈�Ƀf�[�^�������i�[
 */
extern void	force_enqueue_data(DTQCB *dtqcb, VP_INT data);

/*
 *  �f�[�^�L���[�̈悩��f�[�^����o��
 */
extern BOOL	dequeue_data(DTQCB *dtqcb, VP_INT *p_data);

/*
 *  ��M�҂��L���[�̐擪�^�X�N�ւ̃f�[�^���M
 */
extern TCB	*send_data_rwait(DTQCB *dtqcb, VP_INT data);

/*
 *  ���M�҂��L���[�̐擪�^�X�N����̃f�[�^��M
 */
extern TCB	*receive_data_swait(DTQCB *dtqcb, VP_INT *p_data);

#endif /* _DATAQUEUE_H_ */
