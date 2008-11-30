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
 *  @(#) $Id: debugout.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#include <debugout.h>
#include <hal_msg.h>
#include <resource.h>

#ifdef DEBUG_ENABLE

#define DBG_SIZE_STRINGBUFFER 512

static HANDLE DebugConsole;     //�f�o�b�O�������\������e�L�X�g�{�b�N�X
static HWND   DialogHandle;     //�f�o�b�O�o�̓_�C�A���O

extern void FatalAssertion(int exp, LPCSTR format, ... );

/*
 * �f�o�b�O�p�_�C�A���O�̃��b�Z�[�W�n���h��
 */
static LRESULT CALLBACK DebugOutDialogProc(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
	case WM_INITDIALOG:
		DebugConsole = GetDlgItem(hDlg,IDC_DEBUGOUT);       //�o�͐�e�L�X�g�{�b�N�X
		ShowWindow(hDlg,SW_SHOW);

	case WM_SIZE:
		{
			RECT client;
			GetClientRect(hDlg,&client);
			MoveWindow(DebugConsole,0,0,client.right,client.bottom,TRUE);
			break;
		}

	case WM_CLOSE:
			/* Never let this dialog close by pressing of the close button. */
		break;

	case WM_DESTROY:
		DialogHandle = 0;
		break;

	case WM_QUIT:
		DestroyWindow(hDlg);
		break;
	
	default:
		return FALSE;
	}
	return TRUE;
}

    /* ����2�֐�����������肷�邽�߂̍\���� */
struct tagInitializeDebugServicesParam {
    HINSTANCE hInstance;
    HWND      hDlg;
};

    /* �f�o�b�O���[�`�����Ƃ߂� */
void FinalizeDebugServices(void)
{
    if(DialogHandle != 0l) {
		DestroyWindow(DialogHandle);
    }
}

    /* �Ǘ��X���b�h�����s����E�B���h�E�쐬���[�`�� */
static void _initializeDebugServices(void * _param)
{
    struct tagInitializeDebugServicesParam * param = (struct tagInitializeDebugServicesParam *)_param;
    DialogHandle = CreateDialog(param->hInstance, MAKEINTRESOURCE(DEBUGOUTDIALOG), param->hDlg, DebugOutDialogProc);
    FatalAssertion(DialogHandle != NULL, "DebugService could not create its own dialog.");     
}

    /* �f�o�b�O���[�`���̏����� �i�Ǘ��X���b�h�Ƀ_�C�A���O������Ă��炤) */
void InitializeDebugServices(HINSTANCE hinst,HWND dlg)
{
    struct tagInitializeDebugServicesParam param;
    param.hInstance = hinst;
    param.hDlg      = dlg;

    HALExecuteProcedure(_initializeDebugServices, (void *)&param);      //�����˗�
    HALAddDestructionProcedure(FinalizeDebugServices, 0);               //�j�����[�`���̓o�^
}

    /* �f�o�b�O���pprintf */
int _debugOut(const char * format, ... )
{
	int result;
	int i;
	char buffer[DBG_SIZE_STRINGBUFFER*2];
	char * scope;
	const char * work;
	va_list vl;

	if(format == 0l)
		return 0;

	va_start(vl, format);

		/* format�Ɋ܂܂�� '\n' �� '\r\n' �ɒu������ */
	scope = buffer;
	work  = format;

	while(*format != '\0')
	{
		if(*format == '\n')
		{
			i = format - work;
			lstrcpyn(scope, work, i);
			
			scope += i;
			work = format;

			*(scope++) = '\r';
		}
		format ++;
	}

	i = format - work + 1;
	lstrcpyn(scope, work, i);		//+1����'\x0'���R�s�[
	scope += i;

	if((result = wvsprintf(scope, buffer, vl)) > 0)
	{
			//�o�͂��������班���J�b�g
		i = GetWindowTextLength(DebugConsole);
		if(i > DEBUG_LIMITTERUPPERBOUND)
		{
			SendMessage(DebugConsole, EM_SETSEL, 0, i - DEBUG_LIMITTERUPPERBOUND);
			SendMessage(DebugConsole, EM_REPLACESEL, (WPARAM)FALSE, (LPARAM)"");
		}

		SendMessage(DebugConsole,EM_SETSEL,i,i);
		SendMessage(DebugConsole,EM_REPLACESEL,(WPARAM)FALSE,(LPARAM)scope);
	}

	return result;
}

#endif


