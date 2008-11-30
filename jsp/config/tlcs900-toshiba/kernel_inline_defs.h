/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *  @(#) $Id: kernel_inline_defs.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	TOSHIBA�J���������r���g�C��(inline)�֐��̒�`
 *
 *  ���̃C���N���[�h�t�@�C���́C�J�[�l��������c�t�@�C������C���N���[�h
 *  ����Ă���tool_defs.h ����C���N���[�h�����D���̃t�@�C������͒���
 *  �C���N���[�h���邱�Ƃ͂Ȃ��D���̃C���N���[�h�t�@�C���ɐ旧���ď�����
 *  ��邽�߁C���̃C���N���[�h�t�@�C���Ɉˑ����Ă͂Ȃ�Ȃ��D
 */

#ifndef _KERNEL_INLINE_DEFS_H_
#define _KERNEL_INLINE_DEFS_H_

/*
 *  TOSHIBA IDE�ł�#pragma inline�L�q�ɂăC�����C���֐����`����
 *  ���̂��߃J�[�l�������ɂ݈̂ȉ��̏�����K�p����D
 *  tool_defs.h �ɂăJ�[�l�����ʕ���Inline�����inline�̒�`�͑S��
 *  �����Ƃ��C���m�̃C�����C���֐��ɑ΂���#pragma inline��`�{�t�@
 *  �C���ɋL�ڂ���D
 */
/* sil.h	*/
#pragma inline sil_reb_mem
#pragma inline sil_wrb_mem
#pragma inline sil_reh_mem
#pragma inline sil_wrh_mem
#pragma inline sil_reh_lem
#pragma inline sil_wrh_lem
#pragma inline sil_reh_bem
#pragma inline sil_wrh_bem
#pragma inline sil_rew_mem
#pragma inline sil_wrw_mem
#pragma inline sil_rew_lem
#pragma inline sil_wrw_lem
#pragma inline sil_rew_bem
#pragma inline sil_wrw_bem

/* t_services.h	*/
#pragma inline _t_perror
#pragma inline _t_panic

/* t_syslog.h	*/
#pragma inline _syslog_0
#pragma inline _syslog_1
#pragma inline _syslog_2
#pragma inline _syslog_3
#pragma inline _syslog_4
#pragma inline _syslog_5
#pragma inline _syslog_6

/* mailbox.c	*/
#pragma inline enqueue_msg_pri

/* task.c	*/
#pragma inline bitmap_search

/* time_event.c	*/
#pragma inline tmevtb_delete_top

/* wait.c	*/
#pragma inline make_non_wait
#pragma inline queue_insert_tpri
#pragma inline wobj_queue_insert

/* queue.h	*/
#pragma inline queue_initialize
#pragma inline queue_insert_prev
#pragma inline queue_delete
#pragma inline queue_delete_next
#pragma inline queue_empty

/* task_event.h	*/
#pragma inline tmevtb_enqueue
#pragma inline tmevtb_enqueue_evttim
#pragma inline tmevtb_dequeue

/* wait.h	*/
#pragma inline make_wait

/* serial.c	*/
#pragma inline serial_snd_chr


#endif	/* _KERNEL_INLINE_DEFS_H_	*/
