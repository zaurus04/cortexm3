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
 *  @(#) $Id: cmdwatch.cpp,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

// cmdwatch.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include <stdio.h>
#include <stdarg.h>

#include <windows.h>
#include <objbase.h>
#include <unknwn.h>
#include <ocidl.h>

#include <conio.h>

#pragma warning(disable:4200) //��W���̊g���@�\ : ����0�̔z������\����

#define TMAX_LOGINFO	8

typedef	unsigned int BITMASK;
typedef struct {
		unsigned int	logtype;
		unsigned int	logtim;
		unsigned int	valid;
		unsigned int	bufsz;
		unsigned char	buf[];
	} DBIFLOG;

#define DBIFLOG_BUFMARGIN ((unsigned int)(&((DBIFLOG *)0)->buf))

/*
 *  ���O���̏d�v�x�̒�`
 */
#define LOG_EMERG	0		/* �V���b�g�_�E���ɒl����G���[ */
#define LOG_ALERT	1
#define LOG_CRIT	2
#define LOG_ERR		3		/* �V�X�e���G���[ */
#define LOG_WARNING	4		/* �x�����b�Z�[�W */
#define LOG_NOTICE	5
#define LOG_INFO	6
#define LOG_DEBUG	7		/* �f�o�b�O�p���b�Z�[�W */

/*
 *  ���O���̏d�v�x�̃r�b�g�}�b�v����邽�߂̃}�N��
 */
#define LOG_MASK(prio)	(1 << (prio))
#define LOG_UPTO(prio)	((1 << ((prio) + 1)) - 1)

/*
 *  ���O���̎�ʂ̒�`
 */
#define LOG_TYP_INTERRUPT	0x01	/* �����݃n���h�� */
#define LOG_TYP_ISR			0x02	/* �����݃T�[�r�X�n���h�� */
#define LOG_TYP_TIMERHDR	0x03	/* �^�C���C�x���g�n���h�� */
#define LOG_TYP_CPUEXC		0x04	/* CPU��O�n���h�� */
#define LOG_TYP_TSKEXC		0x05	/* �^�X�N��O�������[�`�� */
#define LOG_TYP_TSKSTAT		0x06	/* �^�X�N��ԕω� */
#define LOG_TYP_DISPATCH	0x07	/* �f�B�X�p�b�`�� */
#define LOG_TYP_SVC			0x08	/* �T�[�r�X�R�[�� */
#define LOG_TYP_COMMENT		0x09	/* �R�����g�i������݂̂̃��O�j */
#define LOG_ENTER			0x00	/* �����^�J�n */
#define LOG_LEAVE			0x80	/* �o���^�I�� */



static FILE * destination = NULL;

static const char * apiname[] = 
{ "cre_tsk","del_tsk","act_tsk","can_act","sta_tsk","ext_tsk","exd_tsk","ter_tsk","chg_pri","get_pri","ref_tsk","ref_tst","slp_tsk","tslp_tsk","wup_tsk","can_wup","rel_wai","sus_tsk","rsm_tsk","frsm_tsk","dly_tsk","","def_tex","ras_tex","dis_tex","ena_tex","sns_tex","ref_tex","cre_sem","del_sem","sig_sem","","wai_sem","pol_sem","twai_sem","ref_sem","cre_flg","del_flg","set_flg","clr_flg","wai_flg","pol_flg","twai_flg","ref_flg","cre_dtq","del_dtq","","","snd_dtq","psnd_dtq","tsnd_dtq","fsnd_dtq","rcv_dtq","prcv_dtq","trcv_dtq","ref_dtq","cre_mbx","del_mbx","snd_mbx","","rcv_mbx","prcv_mbx","trcv_mbx","ref_mbx","cre_mpf","del_mpf","rel_mpf","","get_mpf","pget_mpf","tget_mpf","ref_mpf","set_tim","get_tim","cre_cyc","del_cyc","sta_cyc","stp_cyc","ref_cyc","","rot_rdq","get_tid","","","loc_cpu","unl_cpu","dis_dsp","ena_dsp","sns_ctx","sns_loc","sns_dsp","sns_dpn","ref_sys","","","","def_inh","cre_isr","del_isr","ref_isr","dis_int","ena_int","chg_ixx","get_ixx","def_svc","def_exc","ref_cfg","ref_ver","iact_tsk","iwup_tsk","irel_wai","iras_tex","isig_sem","iset_flg","ipsnd_dtq","ifsnd_dtq","irot_rdq","iget_tid","iloc_cpu","iunl_cpu","isig_tim","","","","cre_mtx","del_mtx","unl_mtx","","loc_mtx","ploc_mtx","tloc_mtx","ref_mtx","cre_mbf","del_mbf","","","snd_mbf","psnd_mbf","tsnd_mbf" };



void Printf(const char * format, ... )
{
	va_list vl;
	char buffer[1024];
	int i;

	va_start(vl,format);
	i = ::vsprintf(buffer, format, vl);
	if(destination != NULL)
		fwrite(buffer, i, 1, destination);
	fwrite(buffer, i, 1, stdout);
}

const char * get_apiname(int fncd)
{	return apiname[-5 - fncd];	};

void print_log(DBIFLOG * log)
{
	int i;

	Printf("%10d ms : ",log->logtim);
	switch(log->logtype)
	{
	case LOG_TYP_SVC:
		Printf("[SVC|ENT] %s (",get_apiname(*(int*)log->buf));

		for(i=0;i < *((int*)log->buf+1);i++)
		{
			if(i!=0)
				Printf(", ");
			Printf("0x%08x",*((int*)log->buf+2+i));
		}
		Printf(")\n");
		break;

	case LOG_TYP_SVC|LOG_LEAVE:
		Printf("[SVC|LEA] %s",get_apiname(*(int*)log->buf));
		if(*((int*)log->buf+1) > 0)
			Printf(" (ercd = 0x%08x)",*((int*)log->buf+2));
		Printf("\n");
		break;

	case LOG_TYP_TSKSTAT:
		Printf("[TSKSTAT] Tsk:%d ",*(int*)log->buf);
		switch(*((int*)log->buf+1))
		{
		case 0x01:
		case 0x02:
			Printf("<Ready>\n",*(int*)log->buf);
			break;
		case 0x04:
		case 0x0c:
			if(*((int*)log->buf+1) == 0x04)
				Printf("<Waiting : ");
			else
				Printf("<Wait-Suspend : ");

			switch(*((int*)log->buf+2))
			{
			case 0x1:
				Printf("Sleep>\n");
				break;
			case 0x2:
				Printf("Delay>\n");
				break;
			case 0x4:
				Printf("Semaphore (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x8:
				Printf("Eventflag (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x10:
				Printf("Dataqueue[send] (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x20:
				Printf("Dataqueue[receive] (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x40:
				Printf("Mailbox (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x80:
				Printf("Mutex (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x100:
				Printf("MessageBuffer[send] (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x200:
				Printf("MessageBuffer[receive] (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x400:
				Printf("Rendezvous[call] (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x800:
				Printf("Rendezvous[accept] (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x1000:
				Printf("Rendezvous[completion] (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x2000:
				Printf("Fixed Memorypool (id=%d)>\n",*((int*)log->buf+3));
				break;
			case 0x4000:
				Printf("Variable Memorypool (id=%d)>\n",*((int*)log->buf+3));
				break;
			default:
				Printf(" complex [%04x]>\n", *((int*)log->buf+2));
				break;
			}
			break;

		case 0x08:
			Printf("<Suspended>\n");
			break;
		case 0x10:
			Printf("<Dormant>\n");
			break;
		default:
			Printf("<Unknown : %d>",*(int*)log->buf);
			break;
		}
		break;

	case LOG_TYP_TSKEXC:
		Printf("[TEX|ENT] Tsk:%d\n",*(int*)log->buf);
		break;

	case LOG_TYP_TSKEXC | LOG_LEAVE:
		Printf("[TEX|LEA] Tsk:%d\n",*(int*)log->buf);
		break;

	case LOG_TYP_DISPATCH:
		if(*((int*)log->buf+1) == 0)
			Printf("[DSP|ENT] Tsk:%d Task-context\n",*(int*)log->buf);
		else
			Printf("[DSP|ENT] Tsk:%d Nontask-context\n",*(int*)log->buf);
		break;

	case LOG_TYP_DISPATCH | LOG_LEAVE:
		Printf("[DSP|LEA] Tsk:%d\n",*(int*)log->buf);		
		break;

	case LOG_TYP_COMMENT:
		*((char *)log->buf + log->bufsz -1) = '\x0';
		Printf("[COMMENT](%d) : <%s>\n",*(int *)log->buf,log->buf+sizeof(int));
		break;
	
	case LOG_TYP_INTERRUPT:
		Printf("[INT|ENT] %d\n",*(int*)log->buf);
		break;

	case LOG_TYP_INTERRUPT | LOG_LEAVE:
		Printf("[INT|LEA] %d\n",*(int*)log->buf);
		break;

	case LOG_TYP_CPUEXC:
		Printf("[CEX|ENT] Tsk:%d\n",*(int*)log->buf);
		break;

	case LOG_TYP_CPUEXC | LOG_LEAVE:
		Printf("[CEX|LEA] Tsk:%d\n",*(int*)log->buf);
		break;

	case LOG_TYP_TIMERHDR:
	case LOG_TYP_TIMERHDR | LOG_LEAVE:
		if((log->logtype & LOG_LEAVE) != 0)
			Printf("[INT|LEA]");
		else
			Printf("[INT|ENT]");

		if( *(int*)log->buf == 0x8d )
			Printf(" cyclic ");
		else
			Printf(" OBJ(%02x) ", *(int*)log->buf);

		Printf(" ID:%d  EXINF:0x%08x\n",*((int*)log->buf+1), *((int*)log->buf+2));
		break;

	default:
		Printf("[UNKNOWN] : 0x%x\n",log->logtype);
	};
}




const CLSID CLSID_KernelLog = {0x4BD327FC,0x9E4A,0x4A5D,{0x95,0x03,0x27,0xC9,0x79,0xA8,0xE8,0x02}};

MIDL_INTERFACE("395F900A-AC7E-4A78-9BC1-EE5EF76254FF")
IKernelLog : public IUnknown
{
public:
};


struct __declspec(uuid("35E35399-55ED-45FC-8F0B-4A1BC6CEA3F0")) _IKernelLogEvents;

class IKernelLogEvents : public IUnknown
{
public:
	STDMETHOD(QueryInterface)(REFIID, void **);
	STDMETHOD_(ULONG,AddRef)();
	STDMETHOD_(ULONG,Release)();
    virtual HRESULT STDMETHODCALLTYPE OnKernelStart(void);
    virtual HRESULT STDMETHODCALLTYPE OnKernelExit(void);
    virtual HRESULT STDMETHODCALLTYPE OnLogEvent(long sz, byte __RPC_FAR data[]);

	IKernelLogEvents(void)  { RefCount = 0; };
//	virtual ~IKernelLogEvents(void) { 	if(destination != NULL) fclose(destination); };

	LONG RefCount;
};

HRESULT IKernelLogEvents::QueryInterface(REFIID riid, void ** ppvObject)
{
	if( riid == __uuidof(_IKernelLogEvents) || riid == __uuidof(IUnknown) )
	{
		*ppvObject = this;
		::InterlockedIncrement(&RefCount);
		return S_OK;
	}

	return E_NOINTERFACE;
}

ULONG IKernelLogEvents::AddRef(void)
{	return ::InterlockedIncrement(&RefCount);	}

ULONG IKernelLogEvents::Release(void)
{
	if( ::InterlockedDecrement(&RefCount) == 0 )
	{
		delete this;
		return 0;
	}
	return RefCount;
}

HRESULT IKernelLogEvents::OnKernelExit(void)
{
	Printf("OnKernelExit at \n");

	if(destination != NULL)
	{
		fclose(destination);
		destination = 0;
	}
	return S_OK;
}

HRESULT IKernelLogEvents::OnKernelStart(void)
{
	char buffer[256];
	SYSTEMTIME systim;

	if(destination != NULL)
		fclose(destination);

	::GetLocalTime(&systim);
	::wsprintf(buffer, "kernel-log-%04d%02d%02d-%02d%02d%02d.txt", systim.wYear, systim.wMonth, systim.wDay, systim.wHour, systim.wMinute, systim.wSecond);
	destination = fopen(buffer, "wt");

	Printf("OnKernelStart\n");
	return S_OK;
}

HRESULT IKernelLogEvents::OnLogEvent(long sz, byte data [])
{
	print_log((DBIFLOG *)data);
	return S_OK;
}


	//�R�l�N�V�����|�C���g�ւ̐ڑ�
bool Advise(IUnknown * container, REFIID iid, IUnknown * sink, DWORD * cookie, IConnectionPoint ** pcp = NULL)
{
	IConnectionPointContainer * cpc;
	IConnectionPoint * cp;

	HRESULT result;

	if(pcp == NULL)
		pcp = &cp;

	container->QueryInterface(IID_IConnectionPointContainer, (void **)&cpc);
	if(cpc == 0)
		return false;

	cpc->FindConnectionPoint(iid, pcp);
	cpc->Release();
	if(*pcp == 0)
		return false;

	if(FAILED(result = (*pcp)->Advise(sink, cookie)))
		return false;

	if(pcp == &cp)
		cp->Release();
	return true;
}

DWORD tmain_threadid;

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
	switch(dwCtrlType)
	{
	case CTRL_C_EVENT:
		::PostThreadMessage(tmain_threadid,WM_QUIT,0,0);
		break;
	default:
		return FALSE;
	}

	return TRUE;
}

int main(int argc, char * argv[])
{
	IKernelLog *		pKernelLog;
	IKernelLogEvents *	psKernelLogEvents;
	IConnectionPoint *	cp;
	DWORD				cookie;
	MSG msg;

	IKernelLogEvents a;

	::CoInitialize(NULL);

	destination = 0;
	tmain_threadid = ::GetCurrentThreadId();

	if(!FAILED(::CoCreateInstance(CLSID_KernelLog, NULL, CLSCTX_ALL, __uuidof(IKernelLog), (void **)&pKernelLog)))
	{
		cp = NULL;
		psKernelLogEvents = new IKernelLogEvents;

		if(Advise(pKernelLog, __uuidof(_IKernelLogEvents), psKernelLogEvents, &cookie, &cp))
		{
			::SetConsoleCtrlHandler(HandlerRoutine, TRUE);
			while(::GetMessage(&msg, NULL, 0, 0) != 0)
			{   ::DispatchMessage(&msg);   }
			::SetConsoleCtrlHandler(HandlerRoutine, FALSE);
			
			cp->Unadvise(cookie);
		}

		delete psKernelLogEvents;

		if(pKernelLog != NULL)
			pKernelLog->Release();
	}

	if(destination != NULL)
	{
		Printf("\n\nSuspended by Ctrl-C event occursion.\n");
		fclose(destination);
	}

	::CoUninitialize();
	return 0;
}

