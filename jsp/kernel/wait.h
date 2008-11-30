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
 *  @(#) $Id: wait.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�҂���ԊǗ����W���[��
 */

#ifndef _WAIT_H_
#define _WAIT_H_

#include "task.h"
#include "time_event.h"

/*
 *  �҂���Ԃւ̈ڍs
 *
 *  ���s���̃^�X�N��҂���ԂɈڍs������D��̓I�ɂ́C���s���̃^�X�N��
 *  ���f�B�L���[����폜���CTCB �� winfo�t�B�[���h�CWINFO �� tmevtb�t
 *  �B�[���h��ݒ肷��D
 */
Inline void
make_wait(WINFO *winfo)
{
	make_non_runnable(runtsk);
	runtsk->winfo = winfo;
	winfo->tmevtb = NULL;
}

/*
 *  �҂���Ԃւ̈ڍs�i�^�C���A�E�g�w��j
 *
 *  ���s���̃^�X�N���C�^�C���A�E�g�w��t���ő҂���ԂɈڍs������D���
 *  �I�ɂ́C���s���̃^�X�N�����f�B�L���[����폜���CTCB �� winfo�t�B�[
 *  ���h�CWINFO �� tmevtb�t�B�[���h��ݒ肷��D�܂��C�^�C���C�x���g�u
 *  ���b�N��o�^����D
 */
extern void	make_wait_tmout(WINFO *winfo, TMEVTB *tmevtb, TMO tmout);

/*
 *  �҂�����
 *
 *  tcb �Ŏw�肳���^�X�N�̑҂���Ԃ���������D��̓I�ɂ́C�^�C���C�x
 *  ���g�u���b�N���o�^����Ă���΁C�����o�^��������D�܂��C�^�X�N��
 *  �Ԃ��X�V���C�҂����������^�X�N����̕Ԓl�� E_OK �Ƃ���D�҂��L���[
 *  ����̍폜�͍s��Ȃ��D�҂����������^�X�N�ւ̃f�B�X�p�b�`���K�v�ȏ�
 *  ���ɂ� TRUE ��Ԃ��D
 */
extern BOOL	wait_complete(TCB *tcb);

/*
 *  �^�C���A�E�g�ɔ����҂�����
 *
 *  tcb �Ŏw�肳���^�X�N���C�҂��L���[�ɂȂ���Ă���Α҂��L���[��
 *  ��폜���C�^�X�N��Ԃ��X�V����D�܂��C�҂����������^�X�N����̕Ԓl
 *  ���Cwait_tmout�ł� E_TMOUT�Cwait_tmout_ok �ł� E_OK �Ƃ���D�҂���
 *  �������^�X�N�ւ̃f�B�X�p�b�`���K�v�Ȏ��́Creqflg �� TRUE �ɂ���D
 *  wait_tmout_ok �́Cdly_tsk �Ŏg�����߂̂��̂ŁC�҂��L���[����폜��
 *  �鏈�����s��Ȃ��D
 *  ������̊֐����C�^�C���C�x���g�̃R�[���o�b�N�֐��Ƃ��ėp���邽�߂�
 *  ���̂ŁC�����݃n���h������Ăяo����邱�Ƃ�z�肵�Ă���D
 */
extern void	wait_tmout(TCB *tcb);
extern void	wait_tmout_ok(TCB *tcb);

/*
 *  �҂���Ԃ̋�������
 *
 *  tcb �Ŏw�肳���^�X�N�̑҂���Ԃ������I�ɉ�������D��̓I�ɂ́C�^
 *  �X�N���҂��L���[�ɂȂ���Ă���Α҂��L���[����폜���C�^�C���C�x
 *  ���g�u���b�N���o�^����Ă���΂����o�^��������D
 *  wait_cancel �́C�^�X�N�̏�Ԃ͍X�V���Ȃ��D
 *  wait_release �́C�^�X�N�̏�Ԃ��X�V���C�҂����������^�X�N����̕�
 *  �l�� E_RLWAI �Ƃ���D�܂��C�҂����������^�X�N�ւ̃f�B�X�p�b�`���K
 *  �v�ȏꍇ�ɂ� TRUE ��Ԃ��D
 */
extern void	wait_cancel(TCB *tcb);
extern BOOL	wait_release(TCB *tcb);

/*
 *  �����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ������샋�[�`��
 *
 *  �����E�ʐM�I�u�W�F�N�g�̏������u���b�N�ƊǗ��u���b�N�̐擪�����͋�
 *  �ʂɂȂ��Ă���D�ȉ��́C���̋��ʕ������������߂̌^����у��[�`���Q
 *  �ł���D
 *  �����̑҂��L���[���������E�ʐM�I�u�W�F�N�g�̏ꍇ�C�擪�ȊO�̑҂�
 *  �L���[�𑀍삷��ꍇ�ɂ́C�����̃��[�`���͎g���Ȃ��D�܂��C�I�u�W�F
 *  �N�g������ TA_TPRI �r�b�g���Q�Ƃ���̂ŁC���̃r�b�g�𑼂̖ړI�Ɏg��
 *  �Ă���ꍇ���C�����̃��[�`���͎g���Ȃ��D
 */

/*
 *  �����E�ʐM�I�u�W�F�N�g�̏������u���b�N�̋��ʕ���
 */
typedef struct wait_object_initialization_block {
	ATR	wobjatr;	/* �I�u�W�F�N�g���� */
} WOBJINIB;

/*
 *  �����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�̋��ʕ���
 */
typedef struct wait_object_control_block {
	QUEUE		wait_queue;	/* �҂��L���[ */
	const WOBJINIB	*wobjinib;	/* �������u���b�N�ւ̃|�C���^ */
} WOBJCB;

/*
 *  �����E�ʐM�I�u�W�F�N�g�҂����u���b�N�̒�`
 */
typedef struct wait_object_waiting_information {
	WINFO	winfo;		/* �W���̑҂����u���b�N */
	WOBJCB	*wobjcb;	/* �҂��I�u�W�F�N�g�̊Ǘ��u���b�N */
} WINFO_WOBJ;

/*
 *  �����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���Ԃւ̈ڍs
 *  
 *  ���s���̃^�X�N��҂���ԂɈڍs�����C�����E�ʐM�I�u�W�F�N�g�̑҂��L���[
 *  �ɂȂ��D�܂��C�҂����u���b�N�iWINFO�j�� wobjcb ��ݒ肷��D
 *  wobj_make_wait_tmout �́C�^�C���C�x���g�u���b�N�̓o�^���s���D
 */
extern void	wobj_make_wait(WOBJCB *wobjcb, WINFO_WOBJ *winfo);
extern void	wobj_make_wait_tmout(WOBJCB *wobjcb, WINFO_WOBJ *winfo,
					TMEVTB *tmevtb, TMO tmout);

/*
 *  �^�X�N�D��x�ύX���̏���
 *
 *  �����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���Ԃɂ���^�X�N�̗D��x���ύX��
 *  �ꂽ�ꍇ�ɁC�҂��L���[�̒��ł̃^�X�N�̈ʒu���C������D
 */
extern void	wobj_change_priority(WOBJCB *wobjcb, TCB *tcb);

#endif /* _WAIT_H_ */
