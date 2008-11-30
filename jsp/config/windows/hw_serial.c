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
 *  @(#) $Id: hw_serial.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */



#include <hw_serial.h>
#include <hal_msg.h>
#include <t_services.h>

#include <resource.h>
#include <debugout.h>

#define BUFSZ_UPPERBOUND	24*1024	/* �R���\�[���o�b�t�@�̊��߂���T�C�Y (����𒴂���Ɗ����߂�)  (�ǂ����30000�𒴂����Ȃ��炵��)*/
#define BUFSZ_LOWERBOUND	 8*1024	/* �����߂����Ƃ��ɂǂ̂��炢�����߂��� (UPPERBOUND������������)*/

#define ID_PORT(x)		((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])

#define BITTEST(x,y)	( ( (x) & (y) )	!= 0)
#define BITSET(x,y)		InterlockedExchange( &(x), (x) | (y)  )
#define BITCLEAR(x,y)	InterlockedExchange( &(x), (x) & ~(y) )

extern HINSTANCE	ProcessInstance;
extern HANDLE		PrimaryThreadHandle;

	/* �V���A������u���b�N */
SIOPCB siopcb_table[TNUM_PORT];


	/* �v���I�ȃG���[�������p�A�T�[�g */
extern void FatalAssertion(int exp, LPCSTR format, ... );


/*
 *  �V���A��I/O���ʕ��C���^�t�F�[�X
 */

/*===========================================================================*/

/*
 * �R���\�[���^�V���A��
 */

#define MAX_CONSOLE_BUFSZ	2048
#define SERMSG_CREATE		WM_APP
#define SERMSG_UPDATE		(WM_APP+1)

struct tagSerialConsoleParameters
{
	CRITICAL_SECTION cs;
	unsigned int     position;
	char             buffer[MAX_CONSOLE_BUFSZ];
};


static LRESULT CALLBACK KeyEventTrapper(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	SIOPCB * scope;
	
		/* WM_CHAR���t�b�N���� */
	if(Msg == WM_CHAR)
	{
		scope = (SIOPCB *)GetWindowLong(GetParent(hWnd),GWL_USERDATA);
		PostMessage(scope->Handle,WM_CHAR,wParam,lParam);
		return TRUE;
	}

		/* ���Ƃ��Ƃ�WndProc���ĂтȂ��� */
	return CallWindowProc((void *)GetWindowLong(hWnd,GWL_USERDATA),hWnd,Msg,wParam,lParam);
}

static void SelectConsoleFont(HWND console, UINT pixel)
{
	HANDLE  oldfont;
	HANDLE  newfont;
	LOGFONT logfont;
	HDC     hDC;

		/* DC�擾 */
	hDC = GetDC(console);

		/* ���̃t�H���g�����擾���� */
	oldfont = (HANDLE) SendMessage(console, WM_GETFONT, 0, 0);
	GetObject(oldfont, sizeof(LOGFONT), &logfont);
	
		/* �|�C���g��ύX */
	logfont.lfHeight = -MulDiv(pixel, GetDeviceCaps(hDC, LOGPIXELSY), 72);

		/* �X�V�����t�H���g�������ɁA�V�����t�H���g�𐶐����đI�� */
	newfont = CreateFontIndirect(&logfont);
	SendMessage(console, WM_SETFONT, (WPARAM)newfont, MAKELPARAM(TRUE,0));

		/* �O�̃t�H���g��j�� */
	DeleteObject(oldfont);

		/* DC��� */
	ReleaseDC(console, hDC);
}

static LRESULT ConsoleCommandHandler(HWND hDlg, UINT wID, UINT wNotifyCode, LPARAM lParam)
{
	BOOL     result;
	HANDLE   console;

	result  = TRUE;
	console = GetDlgItem(hDlg, IDC_CONSOLE);

	switch(wID)
	{
		/*
		 * �t�H���g�̑傫����ύX���� 
		 */
	case ID_FONT_BIG:
		SelectConsoleFont(console, 16);
		break;
	case ID_FONT_NORMAL:
		SelectConsoleFont(console, 9);
		break;
	case ID_FONT_SMALL:
		SelectConsoleFont(console, 4);
		break;

	default:
		result = FALSE;
	}

	return result;
}

static BOOL CALLBACK ConsoleProc(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
	case SERMSG_CREATE:
		{
			SIOPCB * work;
			void   * DefWndProc;
			HWND     hConsole;

			hConsole = GetDlgItem(hDlg, IDC_CONSOLE);

				/* �e�L�X�g�{�b�N�X��WndProc�Ƀt�b�N�������� */
			DefWndProc = (void *)GetWindowLong(hConsole,GWL_WNDPROC);
			SetWindowLong(hConsole, GWL_USERDATA, (LONG) DefWndProc);

			work = (SIOPCB *)lParam;
			SetWindowLong(hDlg,GWL_USERDATA,lParam);
			SetWindowLong(hConsole, GWL_WNDPROC, (long)KeyEventTrapper);

			SetTimer(hDlg, 100, 300, NULL);

			ShowWindow(hDlg,SW_SHOWNA);
			break;
		}

	case WM_DESTROY:
		{
			SIOPCB * scope;
			KillTimer(hDlg, 100);
			scope = (SIOPCB *)GetWindowLong(hDlg,GWL_USERDATA);
			if(scope != 0)
				scope->Handle = NULL;
			break;
		}

	case WM_CLOSE:	/* ���[�U�ɂ��E�B���h�E�N���[�Y��}�~ */
		break;

	case WM_CHAR:
		{
			SIOPCB * scope;
			scope = (SIOPCB *)GetWindowLong(hDlg,GWL_USERDATA);
			if(scope != 0)
			{
				scope->ReceiveBuffer = (char)wParam;
				BITSET(scope->Flag, SIO_STA_INTRCV);
				HALInterruptRequest(INHNO_SERIAL);
			}
			break;
		}

	case WM_SETFONT:
		return TRUE;

	case WM_INITDIALOG:
    case WM_SIZE:
		{
			RECT client;
			GetClientRect(hDlg,&client);
			MoveWindow(GetDlgItem(hDlg,IDC_CONSOLE),0,0,client.right,client.bottom,TRUE);
			break;
		}

	case WM_COMMAND:
		return ConsoleCommandHandler(hDlg, LOWORD(wParam), HIWORD(wParam), lParam);

		//��莞�Ԃ���������s�����Ȃ��Ă��o�͂���
	case WM_TIMER:
		if(wParam == 100)
		{
			SIOPCB * scope;
			struct tagSerialConsoleParameters * param;

			scope = (SIOPCB *)GetWindowLong(hDlg, GWL_USERDATA);
            if(scope != 0) {
			    param = (struct tagSerialConsoleParameters *)scope->versatile;
			    if(param->position == 0)
				    break;

			    lParam = TRUE;
            }
            else
                break;  //�܂����������I����ĂȂ��̂ŉ������Ȃ�
		}

		//lParam : ���M���I�������Ɋ����݂������邩�ǂ��� (FALSE:�����Ȃ� TRUE:������)
	case SERMSG_UPDATE:
		{
			LRESULT  result;
			int		 textlength;
			HANDLE	 console;
			SIOPCB * scope;
			struct tagSerialConsoleParameters * param;

			scope = (SIOPCB *)GetWindowLong(hDlg, GWL_USERDATA);
            if(scope != 0) {
			    param = (struct tagSerialConsoleParameters *)scope->versatile;

                console = GetDlgItem(hDlg, IDC_CONSOLE);

			    textlength = GetWindowTextLength(console);
			    if(textlength > BUFSZ_UPPERBOUND)
			    {
					    /* �Â��������� */
				    SendMessage(console,EM_SETSEL,0,textlength - BUFSZ_LOWERBOUND);
				    SendMessage(console,EM_REPLACESEL,(WPARAM)FALSE,(LPARAM)"");
				    textlength = GetWindowTextLength(console);
			    }
				    /* �����ɕ�����u�� */
			    result = SendMessage(console,EM_SETSEL,textlength,textlength);

			    EnterCriticalSection(&param->cs);
			    param->buffer[param->position] = '\x0';
			    result = SendMessage(console,EM_REPLACESEL,(WPARAM)FALSE,(LPARAM)param->buffer);
			    param->position = 0;
			    LeaveCriticalSection(&param->cs);

			    if(lParam == TRUE)
			    {
				    BITSET(scope->Flag, SIO_STA_INTSND);
				    HALInterruptRequest(INHNO_SERIAL);
			    }
            }
            else
                PostMessage(hDlg, Msg, wParam, lParam);     //�܂����������I����ĂȂ��̂Ŗ����ɂ��Ȃ���

			break;
		}

	default:
		return FALSE;
	}

	return TRUE;
}

static void SerialConsole_FinalRelease(void * param)
{
	SIOPCB * cb = (SIOPCB *)param;
	struct tagSerialConsoleParameters * versatile;

	if(cb->Handle != 0l && cb->Handle != NULL)
		DestroyWindow(cb->Handle);
	cb->Handle = NULL;

	versatile = cb->versatile;
	DeleteCriticalSection(&versatile->cs);
	GlobalFree((HGLOBAL)versatile);
}

static void CreateSerialConsole(SIOPCB * cb)
{
	struct tagSerialConsoleParameters * param;

	param = GlobalAlloc(GMEM_FIXED, sizeof(struct tagSerialConsoleParameters));
	FatalAssertion(param != NULL, "CreateSerialConsole: GlobalAlloc reported NULL.");
	param->position = 0;
	InitializeCriticalSection(&param->cs);
	cb->versatile = param;

	cb->Handle = CreateDialog(ProcessInstance, MAKEINTRESOURCE(CONSOLEDIALOG), 0, ConsoleProc);
	FatalAssertion(cb->Handle != 0, "CreateSerialConsole could not create its dialog.");
	PostMessage(cb->Handle,SERMSG_CREATE,0,(LPARAM)cb);
	UpdateWindow(cb->Handle);
	HALAddDestructionProcedure(SerialConsole_FinalRelease,cb);
}

static BOOL SerialConsole_PutChar(SIOPCB * cb, INT chr, BOOL rasint)
{
	char	buffer[2];
	int		textlength;
	HANDLE	console;

	assert(cb != NULL);
	assert(BITTEST(cb->Flag, SIO_TYP_CONSOLE));
	assert(cb->Handle != NULL);

	console = GetDlgItem(cb->Handle, IDC_CONSOLE);
	buffer[0] = (char) chr;
	buffer[1] = '\x0';

	textlength = GetWindowTextLength(console);
	if(textlength > BUFSZ_UPPERBOUND)
	{
			/* �Â��������� */
		SendMessage(console,EM_SETSEL,0,textlength - BUFSZ_LOWERBOUND);
		SendMessage(console,EM_REPLACESEL,(WPARAM)FALSE,(LPARAM)"");
		textlength = GetWindowTextLength(console);
	}
		/* �����ɕ�����u�� */
	SendMessage(console,EM_SETSEL,textlength,textlength);
	SendMessage(console,EM_REPLACESEL,(WPARAM)FALSE,(LPARAM)buffer);

	if(rasint == TRUE)
	{
		BITSET(cb->Flag, SIO_STA_INTSND);
		HALInterruptRequest(INHNO_SERIAL);
	}

	return TRUE;
}

static BOOL SerialConsole_PushChar(SIOPCB * cb, INT chr)
{
	BOOL success;
	BOOL update;
	struct tagSerialConsoleParameters * param;

	param = (struct tagSerialConsoleParameters *)cb->versatile;

	do {
		success = FALSE;
		update  = FALSE;

		EnterCriticalSection(&param->cs);

		if(param->position < MAX_CONSOLE_BUFSZ)
		{
			param->buffer[param->position] = (char)chr;
			param->position ++;

			if(chr == '\n')
				update = TRUE;
		}else
			update = TRUE;

		LeaveCriticalSection(&param->cs);

		if(update == TRUE)
			SendMessage(cb->Handle, SERMSG_UPDATE, 0, 1);
	} while(success == TRUE);

	return TRUE;
}

/*===========================================================================*/

/*
 *   Windows�̃R���\�[�����g�p�����V���A�����o��
 */

static DWORD WINAPI WinConsole_ReceiverThread(LPVOID param)
{
	SIOPCB *		cb = (SIOPCB *)param;
	DWORD			work;
	HANDLE			stdin;
	INPUT_RECORD	input_record;

	assert(cb != NULL);
	assert(cb->Handle != NULL && cb->Handle != 0);

	stdin = GetStdHandle(STD_INPUT_HANDLE);
	FatalAssertion(stdin != 0, "WinConsole_ReceiverThread failed to acquire the handle of standard input.");

	while((work = WaitForSingleObject(cb->Handle, INFINITE)) != WAIT_FAILED)
	{
		assert(work == WAIT_OBJECT_0);	/* �I�u�W�F�N�g�̓V�O�i����ԂɂȂ��� */

		ReadConsoleInput(stdin, &input_record, 1, &work);

		if(input_record.EventType == KEY_EVENT && input_record.Event.KeyEvent.bKeyDown == TRUE)
		{
			cb->ReceiveBuffer = (char)input_record.Event.KeyEvent.uChar.AsciiChar;

			BITSET(cb->Flag, SIO_STA_INTRCV);
			HALInterruptRequest(INHNO_SERIAL);
		}
	}

	return 0;
}

static void WinConsole_CreatePort(SIOPCB * cb)
{
	BOOL result;
	result = AllocConsole();
	FatalAssertion(result != 0, "WinConsole_CreatePort failed to allocate its own console.");
	cb->Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle("TOPPERS/JSP SerialConsole");

		/* ��M�o�b�t�@�Ď��p�X���b�h���쐬 */
	CreateThread(NULL,0,WinConsole_ReceiverThread,(LPVOID)cb,0,NULL);
}

static BOOL WinConsole_PutChar(SIOPCB * cb, INT chr, BOOL rasint)
{
	BOOL  result;
	DWORD written;
	char  word;

	assert(cb != NULL);
	assert(BITTEST(cb->Flag, SIO_TYP_TTY));
	assert(cb->Handle != NULL && cb->Handle != 0);

		/* �W���o�͂Ɉꕶ�����M */
	word   = (char)chr;
	result = WriteFile(cb->Handle, &word, 1, &written, NULL);

		/* �����ݔ����t���O�������Ă�����A���M���������ݗv�����N���� */
	if(result != 0 && rasint == TRUE)
	{
		BITSET(cb->Flag, SIO_STA_INTSND);
		HALInterruptRequest(INHNO_SERIAL);
	}

	return result != 0 ? TRUE : FALSE;
}

static void WinConsole_ClosePort(SIOPCB * cb)
{
	assert(cb != NULL);
	assert(BITTEST(cb->Flag, SIO_TYP_TTY));

	if(cb->Handle != NULL && cb->Handle != 0)
	{
		FreeConsole();
		cb->Handle = NULL;
	}
}

/*===========================================================================*/

/*
 *   Windows�̃R���\�[�����g�p�����V���A�����o��
 */

/* �� : CreateConsoleScreenBuffer�͎��s����INVALID_HANDLE_VALUE��Ԃ����A
          ���̃V���A�����o�͕��Ƌ��ʂ����邽�߂�NULL��p����B */

static DWORD WINAPI ScreenBuffer_ReceiverThread(LPVOID param)
{
	SIOPCB *		cb = (SIOPCB *)param;
	DWORD			work;
	INPUT_RECORD	input_record;

	assert(cb != NULL);
	assert(cb->Handle != NULL && cb->Handle != 0);

	while((work = WaitForSingleObject(cb->Handle, INFINITE)) != WAIT_FAILED)
	{
		assert(work == WAIT_OBJECT_0);	/* �I�u�W�F�N�g�̓V�O�i����ԂɂȂ��� */

		ReadConsoleInput(cb->Handle, &input_record, 1, &work);

		if(input_record.EventType == KEY_EVENT && input_record.Event.KeyEvent.bKeyDown == TRUE)
		{
			cb->ReceiveBuffer = (char)input_record.Event.KeyEvent.uChar.AsciiChar;

			BITSET(cb->Flag, SIO_STA_INTRCV);
			HALInterruptRequest(INHNO_SERIAL);
		}
	}

	return 0;
}

static void ScreenBuffer_CreatePort(SIOPCB * cb)
{
	cb->Handle = CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

        /* cb->Handle should not be compared with NULL because CreateConsoleScreenBuffer returns INVALID_HANDLE_VALUE if it failed */
    FatalAssertion(cb->Handle != INVALID_HANDLE_VALUE && cb->Handle != NULL,
        "ScreenBuffer_CreatePort failed to allocate its own console.");

	SetConsoleActiveScreenBuffer(cb->Handle);
	SetConsoleTitle("TOPPERS/JSP SerialConsole");

		/* ��M�o�b�t�@�Ď��p�X���b�h���쐬 */
	CreateThread(NULL,0,ScreenBuffer_ReceiverThread,(LPVOID)cb,0,NULL);
}

static BOOL ScreenBuffer_PutChar(SIOPCB * cb, INT chr, BOOL rasint)
{
	BOOL  result;
	DWORD written;
	char  word;

	assert(cb != NULL);
	assert(BITTEST(cb->Flag, SIO_TYP_SCRBUF));
	assert(cb->Handle != NULL && cb->Handle != 0);

		/* �W���o�͂Ɉꕶ�����M */
	word   = (char)chr;
	result = WriteFile(cb->Handle, &word, 1, &written, NULL);

		/* �����ݔ����t���O�������Ă�����A���M���������ݗv�����N���� */
	if(result != 0 && rasint == TRUE)
	{
		BITSET(cb->Flag, SIO_STA_INTSND);
		HALInterruptRequest(INHNO_SERIAL);
	}

	return result != 0 ? TRUE : FALSE;
}

static void ScreenBuffer_ClosePort(SIOPCB * cb)
{
	assert(cb != NULL);
	assert(BITTEST(cb->Flag, SIO_TYP_SCRBUF));

	if(cb->Handle != NULL && cb->Handle != 0)
	{
		CloseHandle(cb->Handle);
		cb->Handle = NULL;
	}
}

/*===========================================================================*/

/*
 *   �ق�ƂɃV���A���o��
 */

static DWORD WINAPI RawSerial_ReceiverThread(LPVOID param)
{
	SIOPCB *	cb = (SIOPCB *)param;
	DWORD		work;
	char	    buffer;

	assert(cb != NULL);
	assert(cb->Handle != NULL && cb->Handle != 0);

	while((work = WaitForSingleObject(cb->Handle, INFINITE)) != WAIT_FAILED)
	{
		assert(work == WAIT_OBJECT_0);	/* �I�u�W�F�N�g�̓V�O�i����ԂɂȂ��� */

		ReadFile(cb->Handle, &buffer, 1, &work, NULL);

		cb->ReceiveBuffer = (char)buffer;
		BITSET(cb->Flag, SIO_STA_INTRCV);
		HALInterruptRequest(INHNO_SERIAL);
	}

	return 0;
}

static void RawSerial_CreatePort(SIOPCB * cb)
{
    cb->Handle = CreateFile("COM1", GENERIC_READ|GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
	FatalAssertion( cb->Handle != INVALID_HANDLE_VALUE && cb->Handle != NULL, 
                    "RawSerial_CreatePort failed to open the port 'COM1'.");

		/* ��M�o�b�t�@�Ď��p�X���b�h���쐬 */
	CreateThread(NULL, 0, RawSerial_ReceiverThread, (LPVOID)cb, 0, NULL);
}

static BOOL RawSerial_PutChar(SIOPCB * cb, INT chr, BOOL rasint)
{
	BOOL  result;
	DWORD written;
	char  word;

	assert(cb != NULL);
	assert(BITTEST(cb->Flag, SIO_TYP_RAWSIO));
	assert(cb->Handle != NULL && cb->Handle != 0);

		/* �W���o�͂Ɉꕶ�����M */
	word   = (char)chr;
	result = WriteFile(cb->Handle, &word, 1, &written, NULL);

		/* �����ݔ����t���O�������Ă�����A���M���������ݗv�����N���� */
	if(result != 0 && rasint == TRUE)
	{
		BITSET(cb->Flag, SIO_STA_INTSND);
		HALInterruptRequest(INHNO_SERIAL);
	}

	return result != 0 ? TRUE : FALSE;
}

static void RawSerial_ClosePort(SIOPCB * cb)
{
	assert(cb != NULL);
	assert(BITTEST(cb->Flag, SIO_TYP_RAWSIO));

	if(cb->Handle != NULL && cb->Handle != 0)
	{
		CloseHandle(cb->Handle);
		cb->Handle = NULL;
	}
}


/*
 *  SIO�h���C�o�̏��������[�`��
 */
void sio_initialize(void)
{
	int i;

	for(i=0; i<TNUM_PORT; ++i)
	{
		siopcb_table[i].Flag = SIO_TYP_CONSOLE;
		siopcb_table[i].Handle = NULL;
		siopcb_table[i].ReceiveBuffer = -1;
		siopcb_table[i].versatile = NULL;
	}
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB * sio_opn_por(ID siopid, VP_INT exinf)
{
	BOOL     success;
	SIOPCB * siopcb = GET_SIOPCB(siopid);

	assert(siopcb != NULL);

	siopcb->exinf = exinf;

	success = TRUE;
	switch(SIO_TYP(siopcb->Flag))
	{
	case SIO_TYP_CONSOLE:
		HALExecuteProcedure(CreateSerialConsole,siopcb);
		break;
	case SIO_TYP_TTY:
		WinConsole_CreatePort(siopcb);
		break;
	case SIO_TYP_SCRBUF:
		HALExecuteProcedure(ScreenBuffer_CreatePort,siopcb);
		break;
	case SIO_TYP_RAWSIO:
		HALExecuteProcedure(RawSerial_CreatePort,siopcb);
		break;
	default:
		success = FALSE;
	}

	if(success == TRUE)
		BITSET(siopcb->Flag, SIO_STA_OPEN);

	return siopcb;
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void sio_cls_por(SIOPCB *siopcb)
{
	assert(siopcb != NULL);

	switch(SIO_TYP(siopcb->Flag))
	{
	case SIO_TYP_CONSOLE:
		HALExecuteProcedure(SerialConsole_FinalRelease,siopcb);
		break;
	case SIO_TYP_TTY:
		WinConsole_ClosePort(siopcb);
		break;
	case SIO_TYP_SCRBUF:
		HALExecuteProcedure(ScreenBuffer_ClosePort,siopcb);
		break;
	case SIO_TYP_RAWSIO:
		HALExecuteProcedure(RawSerial_ClosePort,siopcb);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL sio_snd_chr(SIOPCB *siopcb, INT chr)
{
	BOOL result;

	assert(siopcb != NULL);

	switch(SIO_TYP(siopcb->Flag))
	{
	case SIO_TYP_CONSOLE:
		result = SerialConsole_PushChar(siopcb, chr);
		break;
	case SIO_TYP_TTY:
		result = WinConsole_PutChar(siopcb, chr, TRUE);
		break;
	case SIO_TYP_SCRBUF:
		result = ScreenBuffer_PutChar(siopcb, chr, TRUE);
		break;
	case SIO_TYP_RAWSIO:
		result = RawSerial_PutChar(siopcb, chr, TRUE);
		break;
	}
	
	return result;
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT sio_rcv_chr(SIOPCB * siopcb)
{
	INT result;

	result = siopcb->ReceiveBuffer;
	siopcb->ReceiveBuffer = -1;

	return result;
}


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N����
 */
void sio_ena_cbr(SIOPCB * siopcb, UINT cbrtn)
{}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�֎~
 */
void sio_dis_cbr(SIOPCB * siopcb, UINT cbrtn)
{}


/*
 *  �V���A��I/O�|�[�g�����݃n���h��
 */
void sio_handler(void)
{
	int port;

	for(port = 0; port < TNUM_PORT; ++ port)
	{
		if(BITTEST(siopcb_table[port].Flag, SIO_STA_OPEN))
		{
				/* ��M���������� */
			if(BITTEST(siopcb_table[port].Flag, SIO_STA_INTRCV))
			{
					/* ��M�������������o�� */
				BITCLEAR(siopcb_table[port].Flag, SIO_STA_INTRCV);
				sio_ierdy_rcv(GET_SIOPCB(ID_PORT(port))->exinf);

			}

				/* ���M���������� */
			if(BITTEST(siopcb_table[port].Flag, SIO_STA_INTSND))
			{
				BITCLEAR(siopcb_table[port].Flag, SIO_STA_INTSND);
				sio_ierdy_snd(GET_SIOPCB(ID_PORT(port))->exinf);
			}
		}
	}
}

/*
 *  �R���\�[���|�[�g�ւ̋����ꕶ���o�� (�����݂Ȃ�)
 */
void SerialRawPutc(INT chr)
{
	SIOPCB * siopcb = &siopcb_table[CONSOLE_PORTID - 1];

	assert(siopcb != NULL);

	if(!BITTEST(siopcb->Flag, SIO_STA_OPEN))
		return;

	switch(SIO_TYP(siopcb->Flag))
	{
	case SIO_TYP_CONSOLE:
		SerialConsole_PutChar(siopcb, chr, FALSE);
		break;
	case SIO_TYP_TTY:
		WinConsole_PutChar(siopcb, chr, FALSE);
		break;
	case SIO_TYP_SCRBUF:
		ScreenBuffer_PutChar(siopcb, chr, FALSE);
		break;
	case SIO_TYP_RAWSIO:
		RawSerial_PutChar(siopcb, chr, FALSE);
		break;
	}
}
