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
 *  @(#) $Id: sys_rename.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/* This file is generated from sys_rename.def by genrename. */

#ifndef _SYS_RENAME_H_
#define _SYS_RENAME_H_

#ifndef OMIT_RENAME

#define siopcb_table		_kernel_siopcb_table
#define KeyEventTrapper		_kernel_KeyEventTrapper
#define SelectConsoleFont	_kernel_SelectConsoleFont
#define ConsoleCommandHandler	_kernel_ConsoleCommandHandler
#define ConsoleProc		_kernel_ConsoleProc
#define SerialConsole_FinalRelease	_kernel_SerialConsole_FinalRelease
#define CreateSerialConsole	_kernel_CreateSerialConsole
#define SerialConsole_PutChar	_kernel_SerialConsole_PutChar
#define SerialConsole_PushChar	_kernel_SerialConsole_PushChar
#define WinConsole_ReceiverThread	_kernel_WinConsole_ReceiverThread
#define WinConsole_CreatePort	_kernel_WinConsole_CreatePort
#define WinConsole_PutChar	_kernel_WinConsole_PutChar
#define WinConsole_ClosePort	_kernel_WinConsole_ClosePort
#define ScreenBuffer_ReceiverThread	_kernel_ScreenBuffer_ReceiverThread
#define ScreenBuffer_CreatePort	_kernel_ScreenBuffer_CreatePort
#define ScreenBuffer_PutChar	_kernel_ScreenBuffer_PutChar
#define ScreenBuffer_ClosePort	_kernel_ScreenBuffer_ClosePort
#define SerialRawPutc		_kernel_SerialRawPutc
#define MultiMediaTimerCallbackFunction	_kernel_MultiMediaTimerCallbackFunction

#ifdef LABEL_ASM

#define _siopcb_table		__kernel_siopcb_table
#define _KeyEventTrapper	__kernel_KeyEventTrapper
#define _SelectConsoleFont	__kernel_SelectConsoleFont
#define _ConsoleCommandHandler	__kernel_ConsoleCommandHandler
#define _ConsoleProc		__kernel_ConsoleProc
#define _SerialConsole_FinalRelease	__kernel_SerialConsole_FinalRelease
#define _CreateSerialConsole	__kernel_CreateSerialConsole
#define _SerialConsole_PutChar	__kernel_SerialConsole_PutChar
#define _SerialConsole_PushChar	__kernel_SerialConsole_PushChar
#define _WinConsole_ReceiverThread	__kernel_WinConsole_ReceiverThread
#define _WinConsole_CreatePort	__kernel_WinConsole_CreatePort
#define _WinConsole_PutChar	__kernel_WinConsole_PutChar
#define _WinConsole_ClosePort	__kernel_WinConsole_ClosePort
#define _ScreenBuffer_ReceiverThread	__kernel_ScreenBuffer_ReceiverThread
#define _ScreenBuffer_CreatePort	__kernel_ScreenBuffer_CreatePort
#define _ScreenBuffer_PutChar	__kernel_ScreenBuffer_PutChar
#define _ScreenBuffer_ClosePort	__kernel_ScreenBuffer_ClosePort
#define _SerialRawPutc		__kernel_SerialRawPutc
#define _MultiMediaTimerCallbackFunction	__kernel_MultiMediaTimerCallbackFunction

#endif /* LABEL_ASM */
#endif /* OMIT_RENAME */
#endif /* _SYS_RENAME_H_ */
