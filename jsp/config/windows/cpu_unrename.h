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
 *  @(#) $Id: cpu_unrename.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/* This file is generated from cpu_rename.def by genrename. */

#ifdef _CPU_UNRENAME_H_
#undef _CPU_UNRENAME_H_

#ifndef OMIT_RENAME

#undef activate_r
#undef ret_int
#undef ret_exc
#undef NotifyDialogProc
#undef InitializeComSupportModule
#undef FinalizeComSupportModule
#undef idispatch
#undef FatalAssertion
#undef CurrentInterruptLevel
#undef InterruptLevel
#undef ExceptionLevel
#undef AnotherExceptionFilter
#undef SystemMutex
#undef SystemMutexOwnerThreadID
#undef SystemMutexLastOwnerThreadID
#undef enter_system_critical_section
#undef leave_system_critiacl_section
#undef wait_for_thread_suspension_completion
#undef isns_int
#undef InterruptHandlerWrapper
#undef def_int
#undef ini_int
#undef fin_int
#undef ras_int
#undef sns_int
#undef sch_int
#undef LockerThreadID
#undef HALExceptionHandler
#undef ini_exc
#undef fin_exc
#undef DebugOutDialogProc
#undef InitializeDebugServices
#undef FinalizeDebugServices
#undef decode_waitstatus
#undef decode_taskstatus
#undef ProcessInstance
#undef PrimaryThreadHandle
#undef PrimaryDialogHandle
#undef CurrentRunningThreadHandle
#undef ShutdownPostponementRequest
#undef WorkerThreadHandle
#undef DestructionProcedureQueue
#undef KernelStarter
#undef TaskExceptionPerformer
#undef ForceShutdownHandler
#undef PrimaryDialogCommandHandler
#undef HALMessageHandler
#undef PrimaryDialogProc

#ifdef LABEL_ASM

#undef _activate_r
#undef _ret_int
#undef _ret_exc
#undef _NotifyDialogProc
#undef _InitializeComSupportModule
#undef _FinalizeComSupportModule
#undef _idispatch
#undef _FatalAssertion
#undef _CurrentInterruptLevel
#undef _InterruptLevel
#undef _ExceptionLevel
#undef _AnotherExceptionFilter
#undef _SystemMutex
#undef _SystemMutexOwnerThreadID
#undef _SystemMutexLastOwnerThreadID
#undef _enter_system_critical_section
#undef _leave_system_critiacl_section
#undef _wait_for_thread_suspension_completion
#undef _isns_int
#undef _InterruptHandlerWrapper
#undef _def_int
#undef _ini_int
#undef _fin_int
#undef _ras_int
#undef _sns_int
#undef _sch_int
#undef _LockerThreadID
#undef _HALExceptionHandler
#undef _ini_exc
#undef _fin_exc
#undef _DebugOutDialogProc
#undef _InitializeDebugServices
#undef _FinalizeDebugServices
#undef _decode_waitstatus
#undef _decode_taskstatus
#undef _ProcessInstance
#undef _PrimaryThreadHandle
#undef _PrimaryDialogHandle
#undef _CurrentRunningThreadHandle
#undef _ShutdownPostponementRequest
#undef _WorkerThreadHandle
#undef _DestructionProcedureQueue
#undef _KernelStarter
#undef _TaskExceptionPerformer
#undef _ForceShutdownHandler
#undef _PrimaryDialogCommandHandler
#undef _HALMessageHandler
#undef _PrimaryDialogProc

#endif /* LABEL_ASM */
#endif /* OMIT_RENAME */
#endif /* _CPU_UNRENAME_H_ */
