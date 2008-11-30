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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


/*
 *	�v���Z�b�T�ˑ����W���[���iWindows�p�j
 */
#include <cpu_rename.h>

#include <s_services.h>

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

#include <hal_msg.h>

volatile char CPUStatus = CPU_STAT_LOCK;	//CPU��ԃt���O

/*
 *  �^�X�N�f�B�X�p�b�`��
 *    �f�B�X�p�b�`���{�̂�primary_thread.c�ɂ���
 *    �����ł͊Ǘ��X���b�h�Ƀf�B�X�p�b�`�˗����o������
 */
void
dispatch()
{
	LOG_DSP_ENTER_TSK(runtsk);
	HALDispatchRequest();	
}

/* �����ݗp�f�B�X�p�b�`�� (�o�͂��郍�O���݂̂��قȂ�) */
void
idispatch()
{
	LOG_DSP_ENTER_INT(runtsk);
	HALDispatchRequest();
}


/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`
 *    exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 *
 *    ���ݎ��s���̃^�X�N��TCB���w�肵�Ĕj���˗��B�j���㎩���I�Ƀf�B�X�p�b�`���ցB
 */
void
exit_and_dispatch() 
{
    HANDLE handle;

	HALDestroyRequest(runtsk);

    if((handle = (HANDLE)TlsGetValue(TLS_THREADHANDLE)) != NULL)
        CloseHandle(handle);

    TlsFree(TLS_THREADHANDLE);
    TlsFree(TLS_LOGMASK);

	ExitThread(0);
}


/*
 *  �v���Z�b�T�ˑ��̏�����
 */

void
cpu_initialize()
{
    kprintf(("cpu_initialize()\n"));

	/*
	 *  �����݃G�~�����[�^�̏�����
	 */
	ini_int();

	/*
	 * �ŏ�ʍ\������O�n���h���̐ݒ�
	 */
	ini_exc();
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{
    kprintf(("cpu_terminate()\n"));

    fin_int();  //�����݃G�~�����[�^�̒�~
	fin_exc();  //�ŏ�ʍ\������O�n���h���̉���
}


/*
 * �^�X�N�N�����[�`��
 *
 */

DWORD WINAPI
activate_r( LPVOID param)
{
	TCB * tcb = (TCB *)param;

	TlsAlloc();
	TlsSetValue(TLS_LOGMASK, 0);
    TlsSetValue(TLS_THREADHANDLE, tcb->tskctxb.ThreadHandle);

    kprintf(("Task %d : activated\n", (tcb - tcb_table) + 1));

	(*(void(*)(VP_INT))tcb->tinib->task)(tcb->tinib->exinf);
	ext_tsk();
	return 0;
}

/*
 *  atexit�œo�^���ꂽ�֐��̓Ǐo�� (Windows�͉������Ȃ� -> CRT�ɔC����)
 */
void call_atexit(void)
{}


/*
 *   �v���I�Ȏ��s�ɑ΂���Ώ����[�`��
 */
void FatalAssertion(int exp, LPCSTR format, ...)
{
	extern HANDLE PrimaryThreadHandle;
	extern HANDLE CurrentRunningThreadHandle;

	if(!exp)
	{
		va_list vl;
		char    buffer[1024];

			/* �G���[���N����������˂��~�߂� */
		wsprintf(buffer, "Critical assertion fail occured !!\nGetLastError = 0x%08x\n\n", GetLastError());

			/* �J�[�l���������o���Ă�����... */		
		if(PrimaryThreadHandle != NULL)
		{
				/* �J�[�l���̎��s���~�߂� */
			dis_int(0);
			if(CurrentRunningThreadHandle != NULL)
				SuspendThread(CurrentRunningThreadHandle);
			hw_timer_terminate();
		}

			/* �x���\�� */
		va_start(vl, format);
		wvsprintf(buffer + lstrlen(buffer), format, vl);
		MessageBox(PrimaryDialogHandle, buffer, "Assertion Failed", MB_OK|MB_ICONERROR);

			/* �J�[�l����~ */
		HALQuitRequest();
	}
}

	/*
	 *   ���O�o�͂��ǂ����邩�̐���
	 */
void set_logcontrol(BOOL enable)
{
	BOOL result;
	result = TlsSetValue(TLS_LOGMASK, (LPVOID)(enable == TRUE ? 0 : 1));
	if(result == 0)
	{
		TlsAlloc();
		TlsSetValue(TLS_LOGMASK, (LPVOID)(enable == TRUE ? 0 : 1));
	}
}

    /*
     *   �J�[�l���̃f�o�b�O�pprintf
     */
void _kernel_debugprintf(const char * format, ... )
{
    va_list vl;
    int     words;
    DWORD   count;
    char    buffer[1024];

    va_start(vl, format);
    words = wvsprintf(buffer, format, vl);

    if(words != 0)
        WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), buffer, words, &count, NULL);
}

#ifdef _MSC_VER     //cygwin�̏ꍇ��cpu_insn.S�ɋL�q

 /*
  * �^�X�N��O�N�����[�`��
  *   �R���e�L�X�g����v�����邽�߁A
  *   �^�X�N��O�𓮂������^�X�N�̃X���b�h��œ��삳���邽�߂̃��[�`��
  */
void __declspec(naked) TaskExceptionPerformer(void)
{
		/* ���W�X�^�ޔ� */
	__asm	pusha
	__asm	sub		esp, FPU_CONTEXTSIZE
	__asm	fsave	[esp]

		/* �^�X�N��O�̋N�� */
	__asm	call	call_texrtn

		/* �����݃}�X�N�߂� */
	__asm	mov		ebx, DWORD PTR runtsk
	__asm	mov		eax, [ebx]TCB.tskctxb.InterruptLevel
	__asm	push	eax
	__asm	call	chg_ims
	__asm	add		esp, 4

		/* ���W�X�^���A */
	__asm	finit
	__asm	frstor	[esp]
	__asm	add		esp, FPU_CONTEXTSIZE
	__asm	popa
	__asm	ret
}

#endif

