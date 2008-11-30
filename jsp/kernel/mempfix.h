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
 *  @(#) $Id: mempfix.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�Œ蒷�������v�[���@�\
 */

#ifndef _MEMPFIX_H_
#define _MEMPFIX_H_

#include "queue.h"

/*
 *  �Œ蒷�������v�[���������u���b�N
 */
typedef struct fixed_memorypool_initialization_block {
	ATR	mpfatr;		/* �Œ蒷�������v�[������ */
	UINT	blksz;		/* �������u���b�N�̃T�C�Y�i�ۂ߂��l�j */
	VP	mpf;		/* �Œ蒷�������v�[���̈�̐擪�Ԓn */
	VP	limit;		/* �Œ蒷�������v�[���̈�̏���Ԓn */
} MPFINIB;

/*
 *  ��u���b�N���X�g�̒�`
 */
typedef struct free_list {
	struct free_list *next;
} FREEL;

/*
 *  �Œ蒷�������v�[���Ǘ��u���b�N
 */
typedef struct fixed_memorypool_control_block {
	QUEUE	wait_queue;	/* �Œ蒷�������v�[���҂��L���[ */
	const MPFINIB *mpfinib;	/* �Œ蒷�������v�[���������u���b�N */
	VP	unused;		/* ���g�p�̈�̐擪�Ԓn */
	FREEL	*freelist;	/* �󂫃u���b�N�̃��X�g */
} MPFCB;

/*
 *  �Œ蒷�������v�[���@�\�̏�����
 */
extern void	mempfix_initialize(void);

/*
 *  �Œ蒷�������v�[������u���b�N���l��
 */
extern BOOL	mempfix_get_block(MPFCB *mpfcb, VP *p_blk);

#endif /* _MEMPFIX_H_ */
