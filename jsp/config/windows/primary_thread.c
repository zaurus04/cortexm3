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
 *  @(#) $Id: primary_thread.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#include <vwindows.h>
#include <hal_msg.h>
#include <hw_timer.h>

#include <objbase.h>
#include <shellapi.h>
#include <resource.h>

#include "jsp_kernel.h"
#include "task.h"
#include <eventlog.h>
#include <cpu_rename.h>

    /* �I�����ɔj�����s���֐��̃L���[ */
struct tagDestructionProcedureQueue
{
	struct tagDestructionProcedureQueue * Next;
	void (*DestructionProcedure)(void *);
	void * Parameter;
};

 /*
  *   �v���g�^�C�v�錾
  */
extern void kernel_start();
extern void kernel_exit();

 /*
  *   ���ϐ�
  */
HINSTANCE ProcessInstance;
HANDLE    PrimaryThreadHandle;
HWND      PrimaryDialogHandle;
HANDLE    CurrentRunningThreadHandle;
BOOL      ShutdownPostponementRequest;

static HANDLE WorkerThreadHandle = NULL;
static struct tagDestructionProcedureQueue * DestructionProcedureQueue;


 /*
  *  ���ݎ��s���̃X���b�h���w�肳�ꂽ�^�X�N�ł��邩�ǂ����̃`�F�b�N
  */
Inline 
int isTaskThreadRunning(TCB * tcb)
{   return (tcb != 0) && (tcb->tskctxb.ThreadHandle == CurrentRunningThreadHandle);   }


 /*
  * �J�[�l���X�^�[�^
  *   kernel_start�͍Ō��exit_and_dispatch���ĂԂ̂ŁA�R���e�L�X�g�j����
  *   �����ĐV�����X���b�h�𐶐�����B
  */

static DWORD WINAPI
KernelStarter(LPVOID param)
{
    TlsAlloc();
	TlsSetValue(TLS_LOGMASK, (LPVOID)1);
	TlsSetValue(TLS_THREADHANDLE, (LPVOID)CurrentRunningThreadHandle);

    kprintf(("KernelStarter begins performing kernel initialization.\n"));

    kernel_start();

    /* �v���O�����͂����ɂ͗��Ȃ� */

	return 0;
}

 /*
  *  �^�X�N��O�N�����[�`�� 
  *     Visual C++   -> cpu_config.c �Ɉړ����܂���
  *     mingw/cygwin -> cpu_insn.S   �Ɉړ����܂���
  */
extern void TaskExceptionPerformer(void);

 /*
  * �����Ւf���[�`��
  *   ������Ԃ��Ȃ��I�u�W�F�N�g�j���v���V�W���΍�
  */
DWORD WINAPI
ForceShutdownHandler(LPVOID param)
{
	do {
		ShutdownPostponementRequest = FALSE;
		Sleep(5000);
	} while(ShutdownPostponementRequest == TRUE);
	ExitProcess(0);
	return 0;
}

 /*
  * �f�o�b�O���p�_�C�A���O�̃��b�Z�[�W�n���h��
  */
Inline LRESULT CALLBACK
PrimaryDialogCommandHandler(WPARAM wParam, LPARAM lParam)
{
	static BOOL lock_flag;

	switch(wParam)
	{
			/* �u�N���b�N�̋������~����v�{�^�� */
		case IDC_CLOCKSUPPLY:
		{
			int state;

			state = SendDlgItemMessage(PrimaryDialogHandle, IDC_CLOCKSUPPLY,BM_GETCHECK,0,0);
			switch(state)
			{
					/* �N���b�N��~ -> �N���b�N���~�߂� and �������Ă���X���b�h��������~ */
			case BST_CHECKED:
				if((lock_flag = sense_lock()) != TRUE)
					dis_int(0);
				hw_timer_terminate();
				if(CurrentRunningThreadHandle != NULL)
					SuspendThread(CurrentRunningThreadHandle);
				break;

					/* �N���b�N�����ĊJ -> �Ō�Ɏ~�߂��X���b�h�̍ĊJ and �N���b�N�����ĊJ */
			case BST_UNCHECKED:
				if(CurrentRunningThreadHandle != NULL)
					ResumeThread(CurrentRunningThreadHandle);
				hw_timer_initialize();
				if(lock_flag != TRUE)
					ena_int(0);
				break;
			}
			break;
		}

	default:
		return FALSE;
	}

	return TRUE;
}

    /*
     *  TOPPERS/JSP �X���b�h���f�� �^�X�N�f�B�X�p�b�`�� 
     */
static void task_dispatcher(int is_taskschedule_required)
{
		/* ���ܓ����Ă���X���b�h(=������+�^�X�N)������΁A������~�߂� */
	if(CurrentRunningThreadHandle != NULL)
	{
		wait_for_thread_suspension_completion(CurrentRunningThreadHandle);

            //�����Ă����̂��^�X�N�ł���΁A�����݃}�X�N���x����ۑ�����
        if(isTaskThreadRunning(runtsk))
			vget_ims(&runtsk->tskctxb.InterruptLevel);
	}

		/* �^�X�N�ؑ� */

        //�f�B�X�p�b�`����K�v������
    if(is_taskschedule_required != 0 && enadsp && runtsk != schedtsk)
        runtsk = schedtsk;

        //�؊���^�X�N�����݂���Ȃ�A���̃^�X�N���N������
	if(runtsk != 0l)
	{
		CurrentRunningThreadHandle = runtsk->tskctxb.ThreadHandle;

			/* �^�X�N��O������������ */
		if (runtsk->enatex && runtsk->texptn != 0) 
		{
				/* �^�X�N��O�N�����[�`���ւƍ����ւ��� */
			CONTEXT context;
			context.ContextFlags = CONTEXT_FULL;
			GetThreadContext(CurrentRunningThreadHandle,&context);
			*(DWORD *)(context.Esp -= 4) = context.Eip;
			context.Eip = (DWORD)TaskExceptionPerformer;
			SetThreadContext(CurrentRunningThreadHandle,&context);
		}else
			chg_ims(runtsk->tskctxb.InterruptLevel);
		
		LOG_DSP_LEAVE(runtsk);
		ResumeThread(runtsk->tskctxb.ThreadHandle);
	}else
	{
			/* ���������̂��Ȃ��Ȃ�A���荞�݂������đ҂� */
		CurrentRunningThreadHandle = NULL;
		ena_int(0);
	}
}



	/*
	 * TOPPERS/JSP �X���b�h���f�� �J�[�l�����b�Z�[�W�n���h��
	 */
Inline LRESULT CALLBACK
HALMessageHandler(WPARAM wParam,LPARAM lParam)
{
	switch(wParam)
	{
			/*
			 *�u�^�X�N��j�����Ă��������v���b�Z�[�W 
			 *  lParam : �j���Ώۃ^�X�N��TCB�̃A�h���X
			 */
	case HALMSG_DESTROY:
        {
            TCB * tcb = (TCB *)lParam;

				    /* tcb == 0 ����������̂́AKernelStarter��exit_and_dispatch�����Ƃ��̂� */
            if(tcb == 0 || isTaskThreadRunning(tcb)){
                CurrentRunningThreadHandle = NULL;

                    /* �^�X�N�����̋N���v�����o����ext_tsk����ƁA���̎��_�ł��łɐV�����X���b�h�̃n���h���������Ă���̂ŏ����Ă͂����Ȃ� */

                if(tcb == runtsk)
                    runtsk = 0;
            }
        }

			/*
			 *�u�^�X�N��؂�ւ��Ă��������v���b�Z�[�W
			 */
	case HALMSG_DISPATCH:
        task_dispatcher(1);
        break;

		/*
		 *�u���荞�݂𔭐������Ă��������v���b�Z�[�W
		 * lParam : �����ݔԍ� (>0)
		 */
	case HALMSG_INTERRUPT:
        if(lParam == 0 || iniflg == FALSE || ras_int((unsigned int)lParam) == FALSE)
            break;

            /* �����ݎ�t���� : ���̂܂܎��� */

        /*
         * �u���Ɏ��s���ׂ����荞�݂�T���āA�����ݏ������J�n���Ă��������v���b�Z�[�W
         */
    case HALMSG_INTERRUPT_FINISH:
        {
			    /* ���ݎ��s���Ă���X���b�h���~ */
		    wait_for_thread_suspension_completion(CurrentRunningThreadHandle);

				/* �����݃X���b�h���� and �f�B�X�p�b�` */
			if((CurrentRunningThreadHandle = sch_int()) != NULL)
			{
                    //����܂œ������Ă����^�X�N�̊����݃}�X�N���x����ޔ�
				if(isTaskThreadRunning(runtsk))
					vget_ims(&runtsk->tskctxb.InterruptLevel);

                ResumeThread(CurrentRunningThreadHandle);   //�����݃X���b�h�N��
			}
            else {
                    // �^�X�N�ւƖ߂�
                task_dispatcher(reqflg);
                reqflg = 0;
            }

			break;
		}

		/*
		 *�u�Ǘ��X���b�h�̌����ł����Ċ֐������s���Ă��������v���b�Z�[�W
		 *  lParam : �p�����[�^���i�[����\���̂ւ̃|�C���^
		 *    �p�����[�^�\���̓���
		 *      func  : ���s�������֐�
		 *      param : �p�����[�^�Ƃ��ēn�����ł��A��("void *")�Ȓl
		 *
		 * ��) �^�X�N�ŃE�B���h�E�Ƃ������ƁA�^�X�N�j���ŃE�B���h�E�������Ă��܂���
		 */
	case HALMSG_EXECUTEPROCEDURE:
		{
			void ** work = (void **)lParam;
			((void (*)(void *))(*work))(*(work+1));
			break;
		}

		/*
		 *�u�Ō�̍Ō�ɂ��̏����𓮂����Ă�������(onExit�n���h��)�v���b�Z�[�W
		 * lParam : �֐����s���b�Z�[�W�Ƃ������� ( func,param�ւ̃|�C���^ )
		 */
	case HALMSG_ADDDESTRUCTIONPROCEDURE:
		{
			struct tagDestructionProcedureQueue * scope;
			void ** work = (void **)lParam;

			scope = DestructionProcedureQueue;

			if((DestructionProcedureQueue = GlobalAlloc(GMEM_FIXED, sizeof(struct tagDestructionProcedureQueue))) != NULL)
			{
				DestructionProcedureQueue->DestructionProcedure = *(work);
				DestructionProcedureQueue->Parameter = *(work+1);
				DestructionProcedureQueue->Next = scope;
			}else
				FatalAssertion(TRUE, "GlobalAlloc could not acquire a memory block at " __FILE__);

			break;
		}

		/*
		 *�u�v���O�������~�߂Ă��������v���b�Z�[�W
		 */
	case HALMSG_QUITREQUEST:
		{
			struct tagDestructionProcedureQueue * destqueue;
			void * destarea;

			dis_int(0);		// �����ݎ�t�����̃X���b�h�����̂ŁA�ʂɋ֎~���Ȃ��Ă����v

//			WorkerThreadHandle = CreateThread(NULL, 0, ForceShutdownHandler, 0, NULL, NULL);

			hw_timer_terminate();

			if(CurrentRunningThreadHandle != NULL)
				wait_for_thread_suspension_completion(CurrentRunningThreadHandle);

			destqueue = DestructionProcedureQueue;
			while(destqueue != NULL)
			{
				(*destqueue->DestructionProcedure)(destqueue->Parameter);
				destarea = destqueue;
				destqueue = destqueue->Next;
				GlobalFree((HGLOBAL)destarea);
			}

			DestroyWindow(PrimaryDialogHandle);
			break;
		}

	default:
		return FALSE;
	}
	return TRUE;
}

/*
 * �J�[�l���V�~�����[�^�̒��j�ƂȂ�X���b�h�̃��b�Z�[�W�n���h��
 */
LRESULT CALLBACK PrimaryDialogProc(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
		/* �^�X�N�g���C�A�C�R���ŉE�N���b�N */
	case HALMSG_MESSAGE+1:
		if(lParam == WM_RBUTTONUP)
			kernel_exit();

		break;

		/* �J�[�l�����b�Z�[�W */
	case HALMSG_MESSAGE:
		return HALMessageHandler(wParam,lParam);

		/* �f�o�b�O�p�_�C�A���O��̃A�C�e���̃��b�Z�[�W */
	case WM_COMMAND:
		return PrimaryDialogCommandHandler(wParam,lParam);
	
		/* �_�C�A���O����(���b�Z�[�W�n���h�����O�p) */
	case WM_INITDIALOG:
		{
			DWORD ThreadID;
			NOTIFYICONDATA nid;

			PrimaryDialogHandle = hDlg;	//�ꎞ�I

				/* �^�X�N�g���C�ɃA�C�R����o�^ */
			nid.cbSize = sizeof(NOTIFYICONDATA);
			nid.uFlags = NIF_ICON|NIF_TIP|NIF_MESSAGE;
			nid.uID = ID_NOTIFYICON;
			lstrcpy(nid.szTip,"TOPPERS/JSP");
			nid.hWnd = hDlg;
			nid.uCallbackMessage = HALMSG_MESSAGE+1;
			nid.hIcon = LoadIcon(ProcessInstance,MAKEINTRESOURCE(IDI_ERTLICON));

			Shell_NotifyIcon(NIM_ADD,&nid);

				/* �J�[�l����ʃX���b�h�ŋN������ */
			PrimaryThreadHandle = (HANDLE)hDlg;
			CurrentRunningThreadHandle = CreateThread(NULL,0,KernelStarter,NULL,CREATE_SUSPENDED,&ThreadID);
            ResumeThread(CurrentRunningThreadHandle);

			FatalAssertion(CurrentRunningThreadHandle != NULL, "CreateThread at " __FILE__);

			break;
		}

		/* �_�C�A���O����悤�Ƃ��Ă��܂� */
	case WM_CLOSE:
			HALQuitRequest();
			break;

		/* �_�C�A���O���j������܂��� */
	case WM_DESTROY:
		{
				/* �^�X�N�g���C�n�� */
			NOTIFYICONDATA nid;

			nid.cbSize = sizeof(NOTIFYICONDATA);
			nid.uFlags = 0;
			nid.hWnd = hDlg;
			nid.uID = ID_NOTIFYICON;
			Shell_NotifyIcon(NIM_DELETE,&nid);

			PrimaryThreadHandle = NULL;
			PostQuitMessage(0);
			break;
		}

		/* �^�C�}���� */
	case WM_TIMER:
			/* ���16�r�b�g���S��1 -> �J�[�l���̃^�C�} */
		if((wParam & 0xffff0000) == 0xffff0000)
		{
				/* ����16�r�b�g�͊����ݔԍ� */
			return HALMessageHandler(HALMSG_INTERRUPT,(wParam & 0x0000ffff));
		}
	default:
		return FALSE;
	}
	return TRUE;
}


    /* �}���`�v���Z�b�T�ł����肷��悤�A�킴�ƒP��̃v���Z�b�T�݂̂ŏ���������悤�ɂ��� */
void setAffinityMask(void)
{
    DWORD process;
    DWORD system;
    DWORD newaffinitymask;

    if(GetProcessAffinityMask(GetCurrentProcess(), &process, &system) != 0) {
        newaffinitymask = 1;
        while((process & newaffinitymask) == 0)
            newaffinitymask <<= 1;
        SetProcessAffinityMask(GetCurrentProcess(), newaffinitymask);
    }

    kprintf(("setAffinityMask : 0x%08x\n", newaffinitymask));
}

static void initialize(HANDLE hInstance)
{
	ProcessInstance            = hInstance;
	DestructionProcedureQueue  = NULL;
	PrimaryThreadHandle        = NULL;
	CurrentRunningThreadHandle = NULL;

#ifdef KERNEL_DEBUG_MODE
    AllocConsole();
#endif
        /* �v���Z�b�T������t���� */
    setAffinityMask();

}

static void finalRelease(void)
{
	int i;

    kprintf(("finalRelease()\n"));

	/* �j������ĂȂ��^�X�N�̌�n�� */
	for(i=0;i<_kernel_tmax_tskid;i++)
	{
		if(_kernel_tcb_table[i].tskctxb.ThreadHandle != NULL)
		{
			if(TerminateThread(_kernel_tcb_table[i].tskctxb.ThreadHandle,0) != 0)
    			CloseHandle(_kernel_tcb_table[i].tskctxb.ThreadHandle);
			_kernel_tcb_table[i].tskctxb.ThreadHandle = NULL;
		}
	}

    /* COM�ʐM�����Ă���X���b�h��������~ */
	if(WorkerThreadHandle  != NULL)
	{
		TerminateThread(WorkerThreadHandle ,0);
		CloseHandle(WorkerThreadHandle);
        WorkerThreadHandle = NULL;
	}

#ifdef KERNEL_DEBUG_MODE
    MessageBox(NULL, "The kernel will be shut down.", "TOPPERS/JSP", MB_OK);
    FreeConsole();
#endif

}


/*
 * ���C���֐�
 */
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShow)
{
	MSG msg;
	HANDLE hDlg;

    TlsAlloc();

    initialize(hInstance);

	TlsSetValue(TLS_LOGMASK, 0);
    hDlg = CreateDialog(hInstance,"PrimaryDialog",NULL,PrimaryDialogProc);
	if(hDlg != NULL)
	{		
		ShowWindow(PrimaryDialogHandle,SW_HIDE);

		OnDebug(ShowWindow(PrimaryDialogHandle,SW_SHOW));

		while(GetMessage(&msg,NULL,0,0) != 0)
		{
			if(msg.message == WM_QUIT)
				msg.message = 0;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	else
		FatalAssertion(hDlg != NULL, "CreateDialog at " __FILE__ "("  ")");

    finalRelease();

    ExitProcess(msg.wParam);
	return msg.wParam;
}

