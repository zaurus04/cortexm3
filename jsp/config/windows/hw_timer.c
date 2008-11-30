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
 *  @(#) $Id: hw_timer.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�ˑ��^�C�}���W���[���iWindows�p�j
 */

#ifndef _HW_TIMER_C_
#define _HW_TIMER_C_

#include <s_services.h>
#include <hw_timer.h>
#include <hal_msg.h>

extern HANDLE PrimaryThreadHandle;

/*
 *  Windows�̕W���^�C�}
 */
#if defined(TIMER_WINDOWSTIMER)

	/* �^�C�}�̋N������ */
void hw_timer_initialize()
{
    kprintf(("hw_timer_initialize()\n"));
	SetTimer((HWND)PrimaryThreadHandle,RTC_EVENT,TIMER_CLOCK_WINDOWS,NULL);
}

	/* �^�C�}�̒�~���� */
void hw_timer_terminate()
{
    kprintf(("hw_timer_terminate()\n"));
	KillTimer((HWND)PrimaryThreadHandle,RTC_EVENT);
}


/*
 *  �}���`���f�B�A�^�C�}
 */
#elif defined(TIMER_MULTIMEDIATIMER)

#include <mmsystem.h>

static DWORD TimerID = 0;

static void CALLBACK MultiMediaTimerCallbackFunction(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1, DWORD dw2)
{	HALInterruptRequest(INHNO_TIMER);	}

	/* �^�C�}�̋N������ */
void hw_timer_initialize()
{
	MMRESULT result;
	TIMECAPS devcap;

    kprintf(("hw_timer_initialize()\n"));

    result = timeGetDevCaps(&devcap, sizeof(TIMECAPS));
	FatalAssertion(result == TIMERR_NOERROR &&  TIMER_CLOCK_WINDOWS >= devcap.wPeriodMin && TIMER_CLOCK_WINDOWS <= devcap.wPeriodMax, "�w�肳�ꂽ�N���b�N�e�B�b�N�̓}���`���f�B�A�^�C�}�Őݒ�\�Ȕ͈͂𒴂��Ă��܂��B");

	timeBeginPeriod(TIMER_CLOCK_WINDOWS);	//timeBeginPeriod(devcap.wPeriodMin); �Ǝ��s����ƁA���ׂƈ��������ɐ��x���オ��

	TimerID = timeSetEvent(TIMER_CLOCK_WINDOWS, TIMER_CLOCK_WINDOWS,  MultiMediaTimerCallbackFunction, 0, TIME_PERIODIC|TIME_CALLBACK_FUNCTION);
	FatalAssertion(TimerID != 0, "hw_tiemr_initialize failed to perform 'timeSetEvent' function.");
}

	/* �^�C�}�̒�~���� */
void hw_timer_terminate()
{
    kprintf(("hw_timer_terminate()\n"));

    if(TimerID != 0)
	{
		timeKillEvent(TimerID);
		timeEndPeriod(TIMER_CLOCK_WINDOWS);
	}
}

#elif defined(TIMER_NOTHING)

void hw_timer_initialize() {}
void hw_timer_terminate()  {}

#else

#error "�g�p����^�C�}�̎�ʂ��I������Ă��܂���"

#endif



#endif /* _HW_TIMER_H_ */

