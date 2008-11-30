/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: cpu_unrename.h,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

#ifdef _CPU_RENAME_H_
#undef _CPU_RENAME_H_

#ifndef OMIT_RENAME

#undef _reset
#undef vector_entry_SBI
#undef vector_entry_RIE
#undef vector_entry_AE
#undef vector_entry_trap
#undef _trap_handler_0
#undef _trap_handler_1
#undef _trap_handler_2
#undef _trap_handler_3
#undef _trap_handler_4
#undef _trap_handler_5
#undef _trap_handler_6
#undef _trap_handler_7
#undef _trap_handler_8
#undef _trap_handler_9
#undef _trap_handler_10
#undef _trap_handler_11
#undef _trap_handler_12
#undef _trap_handler_13
#undef _trap_handler_14
#undef _trap_handler_15
#undef interrupt_handler
#undef InterruptHandlerEntry
#undef interrupt_handler_r
#undef recover_task_r
#undef recover_task
#undef recover_int
#undef exit_interrupt_handler
#undef _exception_handler
#undef ExceptionHandlerEntry
#undef _unhandled_interrupt_handler
#undef exit_exception_handler
#undef exception_handler_r
#undef recover_exception_exc_task_r
#undef dispatch
#undef reqflg
#undef calltex
#undef runtsk
#undef dispatch_r
#undef exit_and_dispatch
#undef schedtsk
#undef activate_r

#ifdef LABEL_ASM

#undef __reset
#undef _vector_entry_SBI
#undef _vector_entry_RIE
#undef _vector_entry_AE
#undef _vector_entry_trap
#undef __trap_handler_0
#undef __trap_handler_1
#undef __trap_handler_2
#undef __trap_handler_3
#undef __trap_handler_4
#undef __trap_handler_5
#undef __trap_handler_6
#undef __trap_handler_7
#undef __trap_handler_8
#undef __trap_handler_9
#undef __trap_handler_10
#undef __trap_handler_11
#undef __trap_handler_12
#undef __trap_handler_13
#undef __trap_handler_14
#undef __trap_handler_15
#undef _interrupt_handler
#undef _InterruptHandlerEntry
#undef _interrupt_handler_r
#undef _recover_task_r
#undef _recover_task
#undef _recover_int
#undef _exit_interrupt_handler
#undef __exception_handler
#undef _ExceptionHandlerEntry
#undef __unhandled_interrupt_handler
#undef _exit_exception_handler
#undef _exception_handler_r
#undef _recover_exception_exc_task_r
#undef _dispatch
#undef _reqflg
#undef _calltex
#undef _runtsk
#undef _dispatch_r
#undef _exit_and_dispatch
#undef _schedtsk
#undef _activate_r

#endif /* LABEL_ASM */
#endif /* OMIT_RENAME */
#endif /* _CPU_RENAME_H_ */
