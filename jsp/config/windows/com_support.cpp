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
 *  @(#) $Id: com_support.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#include <vitron.h>
#include <com_support.h>
#include <eventlog.h>
#include "syslog.h"

#include <resource.h>

#include <commctrl.h>

/*
 *  �O�ɕ����ꂽ���̐���
 *     Q: C�X�^�C���R�����g��C++�X�^�C���R�����g���������Ă��܂���?
 *     A: �C�y�ɃR�����g�A�E�g�����ƍ��鏈����C�X�^�C���R�����g�ŁA�����悤�ȏ���������ꏊ�̐�����C++�X�^�C���R�����g���g���Ă��܂��B
 *
 *     Q: �ϐ��̖��Â��K�����߂��Ⴍ����ł���?
 *     A: ��{�I�ɃX�R�[�v�͈͂Ŏg�������Ă��܂��B
 *          ���[�J����������+"_", �O���[�o�����啶��������, �����o��Java���ۂ��X�^�C��
 *
 *     Q: INVALID_HANDLE_VALUE �� NULL ���ǂ��g�������Ă���̂ł���?
 *     A: CreateXxxx�����s���ɕԋp����l�ł��킹�܂����B
 *        ��̓I�ɂ́A�t�@�C����INVALID_HANDLE_VALUE(CreateFile)�ŁA����ȊO��NULL�ɂȂ��Ă܂��B
 */

#ifndef __COM_NOT_REQUIRED__


//===================================================
/*
 *   ���ʕ�
 */
extern "C" SYSTIM		_kernel_systim_offset;
extern "C" SYSTIM		_kernel_current_time;
extern "C" HINSTANCE	ProcessInstance;
extern "C" HANDLE		PrimaryDialogHandle;
extern "C" BOOL			ShutdownPostponementRequest;
extern "C" int          CPUStatus;

extern "C" void FatalAssertion(int exp, LPCSTR format, ... );

extern "C" void enter_system_critical_section(BOOL * cookie);
extern "C" void leave_system_critiacl_section(BOOL * cookie);

#ifdef KERNEL_DEBUG_MODE
   extern "C" _kernel_debugprintf(const char * format, ... );
#  define kprintf(x) _kernel_debugprintf x
#else
#  define kprintf(x)
#endif

//===================================================

	/* ���[�U��`�̃��O */
#define USERDEFINED	0x60
#define LOG_MODULENAME (0 | USERDEFINED)	/* ���W���[���̖��O   */
#define LOG_TIMESTAMP  (1 | USERDEFINED)    /* �L�^���J�n�������� (SYSTEMTIME�\���̂����̂܂܃_���v) */

#define  __HAL_MSG_MSGONLY
#include <hal_msg.h>

#include <string>

namespace
{
	/*
	 *   COM�C���^�[�t�F�[�X�֘A�̒�`
	 */

		//���X��ID�̐錾
	const IID   IID_IKernelEvents = {0x1353969D,0xE84F,0x463F,{0xB2,0x11,0x33,0x7E,0x9B,0xCF,0xB9,0x9E}};
	const IID   IID_IKernel       = {0xD3E42099,0x3FDD,0x4A78,{0xBD,0xBD,0x4E,0x57,0xD3,0x62,0xF5,0xED}};
	const CLSID CLSID_Kernel      = {0x51789667,0x9F20,0x40AF,{0xAF,0x7F,0x98,0x56,0x32,0x5D,0xFB,0x0B}};

		// IKernel�C���^�[�t�F�[�X��`
	class IKernel : public IUnknown
	{
	public:
		STDMETHOD(Read)(unsigned long address,unsigned long sz,char __RPC_FAR data[]) PURE;
		STDMETHOD(IsValid)(BOOL __RPC_FAR * valid) PURE;
		STDMETHOD(Write)(unsigned long address,unsigned long sz,char __RPC_FAR data[]) PURE;
		STDMETHOD(OnLogEvent)(long sz, unsigned char __RPC_FAR data[]) PURE;
	};

		// IKernelEvents�C���^�t�F�[�X��`
	class IKernelEvents : public IUnknown
	{
	public:
		STDMETHOD(QueryInterface)(REFIID iid, void ** unk);
		STDMETHOD_(ULONG,AddRef)();
		STDMETHOD_(ULONG,Release)();
		STDMETHOD(OnInterruptRequest)(long inhno);

		IKernelEvents(void);

		long RefCount;
	};

	/*
	 *   IKernelEvents����
	 */

	IKernelEvents::IKernelEvents(void) : RefCount(0)
	{}

    STDMETHODIMP IKernelEvents::QueryInterface(REFIID iid, void ** unk)
	{
		if( iid == IID_IKernelEvents || iid == IID_IUnknown )
		{
			*unk = this;
			::InterlockedIncrement(&RefCount);
			return S_OK;
		}

		return E_NOINTERFACE;
	}

	STDMETHODIMP_(ULONG) IKernelEvents::AddRef()
	{	return ::InterlockedIncrement(&RefCount);	}

	STDMETHODIMP_(ULONG) IKernelEvents::Release()
	{
		if( ::InterlockedDecrement(&RefCount) == 0)
			delete this;
		return RefCount;
	}

	STDMETHODIMP IKernelEvents::OnInterruptRequest(long inhno)
	{

		if(inhno < 0)
		{
			/* inhno < 0 �͓���ȈӖ������� */

			/* inhno = -1 : keep-alive */
		}else
			::PostMessage((HWND)PrimaryDialogHandle,HALMSG_MESSAGE,HALMSG_INTERRUPT,(LPARAM)inhno);
		return S_OK;
	}
}

namespace {
	/*
	 *   COM�ʐM�p��ƃX���b�h�Ɋւ����`
	 */

	HANDLE request_semaphore    = NULL;		//�v���҂��Z�}�t�H
	HANDLE worker_thread_handle = NULL;		//��ƃX���b�h�̃n���h��

	//==============================================================================

		//COM��ƃX���b�h������ɍ쓮���Ă��邩�ۂ�
	inline bool IsValid(void)
	{	return (request_semaphore != NULL) && (worker_thread_handle != NULL);	}

	//===================================================

		/*
		 *    Q: �ǂ����ăV�X�e�����b�N���K�v�Ȃ�?
		 *    A: ���O�C�x���g���L���[�C���O���邽�߂Ɋe�^�X�N/�����݃X���b�h�������������
		 *        -> VisualC++�̃}���`�X���b�h�p�������m�ۃ��C�u�����͓����ŃN���e�B�J���Z�N�V�����I�u�W�F�N�g���g���Ĕr�����䂵�Ă���
		 *        -> TOPPERS/JSP Windows�̃f�B�X�p�b�`��(�Ǘ��X���b�h)�͗v��������ƍ������Ă���X���b�h���~�߂ɂ�����
		 *        -> �������m�ۗp�̃N���e�B�J���Z�N�V�������������܂�SuspendThread����Ă��܂��A�������m�ۗv�����o�������̃X���b�h�S�Ă����b�N
		 *        -> �Ǘ��X���b�h�����O���o�����߂Ƀ��������Ƃ�ɗ���̂ŁA�Ǘ��X���b�h�����b�N
		 *        -> �Ǘ��X���b�h�����b�N�����ƁA�ŏ���SuspendThread���ꂽ���c���N�����X���b�h�����Ȃ�
		 *        -> �f�b�h���b�N
		 *    �⑫ : COM�ʐM��ƃX���b�h��R���\�[���Ǘ��X���b�h�̂悤�ɊǗ��X���b�h��SuspendThread�̑ΏۂɂȂ�Ȃ��X���b�h�̓��b�N���Ȃ��Ă�����
		 */

	//===================================================

		/* ��ƃX���b�h�ɗ^����f�[�^��ێ�����N���X */
	class Request
	{
	public:
		enum tagRequestType
		{
			Confirmation = 0x00,	/* ���[�J�X���b�h�̓���m�F (�Z�}�t�H������������) */
			
			DeviceRead   = 0x01,	/* �f�o�C�X�G�~�����[�V���� �Ǐo������ */
			DeviceWrite  = 0x02,	/* �f�o�C�X�G�~�����[�V���� �����ݑ��� */

			EventLog     = 0x03,	/* �C�x���g���O���o */

			QuitThread   = 0xff		/* ��ƃX���b�h�̏I�� */
		};

	protected:
		bool                blocking;
		bool				allocated;
		enum tagRequestType type;
		unsigned long       address;		/* �f�o�C�X : �f�o�C�X�̂���A�h���X */
		unsigned long       size;			/* ����     : storage�����f�[�^�̃T�C�Y */
		HGLOBAL             storage;		/* ����     : �f�[�^���i�[���Ă���̈�̃A�h���X(�n���h��) */
		int                 result;			/* ����     : �u���b�L���O���s���̕ԋp�n */
		HANDLE              signalobject;	/* ����     : �u���b�L���O���s���̃X���b�h�n���h�� */

		Request *           next;		/* �L���[�ɂ��邽�߂̃����N */

		static LONG      RequestCount;	//�L���[�ɂȂ����Ă��郊�N�G�X�g�̐�
		static Request * top;			//���N�G�X�g�L���[�̐擪 (�����Ƃ��Â����N�G�X�g)
		static Request * tail;			//���N�G�X�g�L���[�̖��� (�����Ƃ��V�������N�G�X�g)
		static CRITICAL_SECTION cs;		//�r���L���[����p�댯�̈�I�u�W�F�N�g

		void connect(void)
		{
				//�v�����L���[�ɂȂ�
			::EnterCriticalSection(&cs);
			next = NULL;
			if(tail != NULL)
				tail->next = this;
			tail = this;
			if(top == NULL)
				top = tail;
			::LeaveCriticalSection(&cs);

			::InterlockedIncrement(&RequestCount);
		}

	protected:
			//�R���X�g���N�^
		Request(enum tagRequestType _type, bool _block, unsigned int _size = 0, void * _storage = NULL, unsigned long _address = 0)
            :   blocking(_block), allocated(false), type(_type), address(_address), 
                size(0), storage(NULL), result(-1), signalobject(NULL), next(NULL)
		{
			size    = _size;

			if(size != 0)
			{
					//�̈悪�w�肳��ĂȂ��ꍇ�A���I�Ɋm�ۂ���
				if(_storage != NULL)
					storage = static_cast<HGLOBAL>(_storage);
				else
					allocate(size, false);
			}
		}

	public:
			//�f�X�g���N�^
		virtual ~Request(void)
		{

				//�̈悪���I�m�ۂ���Ă����ꍇ�A�j�����s��
			if(storage != NULL && allocated)
			{
				BOOL lock;

				enter_system_critical_section(&lock);
	            ::GlobalFree(storage);
				leave_system_critiacl_section(&lock);
			}
		}

		static void initialize(void)
		{
            kprintf(("Request::initialize()\n"));
			if(RequestCount == -1)
			{
				::InitializeCriticalSection(&cs);
				RequestCount = 0;
				top  = NULL;
				tail = NULL;
			}
		}

		static void finalize(void)
		{
            kprintf(("Request::finalize()\n"));
			if(RequestCount != -1)
			{
				while(top != NULL)
				{
					Request * target = top;
					top = top->next;
					delete target;
				}

				::DeleteCriticalSection(&cs);	
				RequestCount = -1;
			}
		}

			// �V�X�e�������b�N���Ȃ��Ń������J��
		inline void release(void)
		{
			if(storage != NULL && allocated)
			{
				::GlobalFree(storage);
				storage = 0;
			}
		}

		inline bool isBlockingRequest(void) const
		{	return blocking;	}

		inline enum tagRequestType getType(void) const
		{	return type;	}

		inline bool operator == (enum tagRequestType _type) const
		{	return type == _type;	}

		inline bool operator != (enum tagRequestType _type) const
		{	return !(operator ==(_type));	}

		inline void * getStorage(void)
		{	return reinterpret_cast<void *>(storage);	}

		inline unsigned long getAddress(void) const
		{	return address;   }

		inline unsigned long getSize(void) const
		{	return size;	}

		inline int getResult(void) const
		{	return result;	}

		static inline LONG getRequestCount(void)
		{	return RequestCount;	}

			//�̈�̊m��
			//	_size   : �K�v�Ƃ���̈�̃T�C�Y
			//	realloc : ���e��ێ����邩�ۂ�
		bool allocate(unsigned int _size, bool realloc = false)
		{
			unsigned long old_size;
			HGLOBAL       old_storage;
			BOOL          lock;

			FatalAssertion(type != Confirmation, "Request::allocate was performed with Confirmation Request Object.");

			old_size    = size;
			old_storage = storage;

			enter_system_critical_section(&lock);
			storage = ::GlobalAlloc(GMEM_FIXED, _size);

			FatalAssertion(storage != NULL, "Request::allocate failed to allocate a memory block.");

				//�O�̓��e�̕ێ� ����ї̈�j��
			if(old_storage != NULL)
			{
				if(realloc)
					::CopyMemory(storage, old_storage, old_size);

				if(allocated)
					::GlobalFree(old_storage);
			}
			leave_system_critiacl_section(&lock);

			allocated = true;
			size = _size;

			return true;
		}

			//���e��ێ������܂܍ăA���P�[�g
		inline bool reallocate(unsigned int _size)
		{	return allocate(_size, true);   }

			//�ێ��̈�ɑ΂��鏑����
		inline void set(void * data, unsigned int sz, unsigned int offset = 0)
		{
			if(size < sz)
				reallocate(sz + offset);

			::CopyMemory(reinterpret_cast<char *>(storage) + offset, data, sz);
		}

			//�ێ��̈�ɑ΂���Ǎ���
		inline bool get(void * data, unsigned int sz, unsigned int offset = 0)
		{
			if(size < sz + offset)
				return false;

			::CopyMemory(data, reinterpret_cast<char *>(storage) + offset, sz);
		}

			//�ێ��̈�̔C�ӂ̈ʒu�ɑ΂���|�C���^�擾
			//		offset : �擪����̃o�C�g�I�t�Z�b�g
		void * getptr(unsigned int offset = 0)
		{
			if(offset > size || storage == NULL)
				return NULL;

			return reinterpret_cast<void *>(reinterpret_cast<char *>(storage) + offset);
		}

			/*
			 *   Request�I�u�W�F�N�g�t�@�N�g��
			 *     Q: �ǂ����ăt�@�N�g�����K�v�Ȃ̂�?
			 *     A: �������m�ۂ������CPU�����b�N����K�v�����邽�� (�ڍׂ͏�LCPU���b�N���闝�R���Q��)
			 */			
		static Request * Create(enum tagRequestType _type, bool _block, unsigned int _size = 0, void * _storage = NULL, unsigned long _address = 0)
		{
			Request * request;
			BOOL      lock;

			enter_system_critical_section(&lock);
			request = new Request(_type, _block, _size, _storage, _address);
			leave_system_critiacl_section(&lock);
		
			return request;
		}

		static Request * GetRequest(void)
		{
			Request * result;

			::EnterCriticalSection(&cs);
			result = top;
			if(top != NULL)
			{
				top = top->next;
				if(top == NULL)
					tail = NULL;
			}
			::LeaveCriticalSection(&cs);

			::InterlockedDecrement(&RequestCount);

			return result;
		}

		void Finalize(bool succeeded)
		{
			if(this != 0) {
				if(isBlockingRequest())
					signal(succeeded ? getSize() : -1);
				else
				{
					BOOL lock;

					enter_system_critical_section(&lock);
					delete this;
					leave_system_critiacl_section(&lock);
				}
			}
		}

        virtual void signal(int _result = 0)
		{
			result = _result;
			if(signalobject != NULL)
				::PostThreadMessage((DWORD)signalobject, WM_QUIT, 0, 0);
		}
				
			/*
			 *   �V�����v���̔��s
			 *     (���̊֐����g���X���b�h : �Ǘ��X���b�h, �����݃X���b�h, �^�X�N�X���b�h)
			 */
		virtual int invoke(void)
		{
			int  _result;
			BOOL lock;
			MSG  msg;

			_result = 0;

			if(!IsValid())
				return -1;

			enter_system_critical_section(&lock);

			connect();

				//�v���̎��s�҂�
			if(blocking)
			{
				signalobject = (HANDLE)::GetCurrentThreadId();

					//�V�����v�������������Ƃ�ʒm
				::ReleaseSemaphore(request_semaphore,1,NULL);
				leave_system_critiacl_section(&lock);

					//WM_QUIT���b�Z�[�W���g���ē��������
				while(::GetMessage(&msg, 0, 0, 0) != 0)
					::DispatchMessage(&msg);

					//���̃I�u�W�F�N�g��j������̂Ńo�b�N�A�b�v�����
				_result = result;

					//�L���[����͂��������͍�ƃX���b�h�����
					//delete request�́A�m���u���b�L���O�Ȃ��ƃX���b�h�ӔC�A�u���b�L���O�Ȃ炱���ł��
                enter_system_critical_section(&lock);
				delete this;
                leave_system_critiacl_section(&lock);
			}else
			{
					//�V�����v�������������Ƃ�ʒm
				::ReleaseSemaphore(request_semaphore,1,NULL);
				leave_system_critiacl_section(&lock);
			}

			return _result;
		}
	};

	class EventDumpRequest : public Request
	{
	protected:
		static HANDLE FileHandle;

		EventDumpRequest(enum tagRequestType _type, bool _block, unsigned int _size = 0, void * _storage = NULL, unsigned long _address = 0) : Request(_type, _block, _size, _storage, _address) 
		{}

	public:
		static void initialize(void)
		{
			SYSTEMTIME systim;
			DWORD      written;
			char       buffer[1024];
			char *     top;
			char *     work;

			::GetLocalTime(&systim);
			::wsprintf(buffer, "kernel-log-%04d%02d%02d-%02d%02d%02d.log", systim.wYear, systim.wMonth, systim.wDay, systim.wHour, systim.wMinute, systim.wSecond);
			FileHandle = ::CreateFile(buffer, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN, NULL);

            kprintf(("EventDumpRequest : initialize (filename = '%s')\n", buffer));

			T_RGLOG_HEADER log;
			
			log.logtype = LOG_TIMESTAMP;
			log.logtim  = 0;
			log.bufsz   = sizeof(SYSTEMTIME);
			log.valid   = 1;
			::WriteFile(FileHandle, &log, sizeof(log), &written, NULL);
			::WriteFile(FileHandle, &systim, sizeof(SYSTEMTIME), &written, NULL);

				/* ���W���[���������o�� */
			::lstrcpyn(buffer, ::GetCommandLine(), 1023);
			top = buffer;
			buffer[1023] = '\x0';	//�T�[�`�p�ԕ�

			if(*top == '"')
			{
				++ top;
				for(work = top; *work != '\x0' && *work != '"'; ++work);
			}
			else
				for(work = top; *work != '\x0' && *work != ' '; ++work);

			*work = '\x0';	//�^�[�~�l�[�g����

			log.logtype = LOG_MODULENAME;
			log.logtim  = 0;
			log.bufsz   = work - top + 1;	//�^�[�~�l�[�^�̕�
			log.valid   = 1;
			::WriteFile(FileHandle, &log, sizeof(log), &written, NULL);
			::WriteFile(FileHandle, top, log.bufsz, &written, NULL);
		}

		static void finalize(void)
		{
            kprintf(("EventDumpRequest : finalize()\n"));

			if(FileHandle != INVALID_HANDLE_VALUE)      //CreateFile returns INVALID_HANDLE_VALUE if it failed
				::CloseHandle(FileHandle);
		}

		static EventDumpRequest * Create(enum tagRequestType _type, bool _block, unsigned int _size = 0, void * _storage = NULL, unsigned long _address = 0)
		{
			EventDumpRequest * request;
			BOOL      lock;

			enter_system_critical_section(&lock);
			request = new EventDumpRequest(_type, _block, _size, _storage, _address);
			leave_system_critiacl_section(&lock);
		
			return request;
		}

		virtual int invoke(void)
		{
			DWORD written;
			BOOL  lock;

			enter_system_critical_section(&lock);
			if(FileHandle != INVALID_HANDLE_VALUE)      //CreateFile return INVALID_HANDLE_VALUE, not NULL, if it failed its operatation.
				::WriteFile(FileHandle, storage, size, &written, NULL);
			delete this;
			leave_system_critiacl_section(&lock);

			return 0;
		}
	};

    class ExclusiveDeviceRequest : public Request
    {
    protected:
        static HANDLE blocker;
    public:

        static void initialize(void) throw()
        {
            kprintf(("ExclusiveDeviceRequest::initialize()\n"));

            if(blocker == NULL) {
                blocker = ::CreateEvent(NULL, FALSE, FALSE, NULL);
            }
        }

        static void finalize(void) throw()
        {
            kprintf(("ExclusiveDeviceRequest::finalize()\n"));

            if(blocker != NULL) {
                ::CloseHandle(blocker);
            }
        }

        virtual void signal(int _result = 0)
        {
            result = _result;
            ::SetEvent(blocker);
        }

        virtual int invoke(void)
        {
            int  _result = 0;
            BOOL lock;
            BOOL cpustate;

                //���荞�݂��֎~����
            if((cpustate = CPUStatus) == 0)
                dis_int(0);

            enter_system_critical_section(&lock);

                //�v�����L���[�̐擪�ɂȂ�
            ::EnterCriticalSection(&cs);
            next = top;
            top = this;
            if(tail == NULL)
                tail = this;
            ::LeaveCriticalSection(&cs);
            ::InterlockedIncrement(&RequestCount);

            ::ReleaseSemaphore(request_semaphore, 1, NULL);
            leave_system_critiacl_section(&lock);

            if(blocking) {
                ::WaitForSingleObject(blocker, INFINITE);

                _result = result;

                enter_system_critical_section(&lock);
                delete this;
                leave_system_critiacl_section(&lock);
            }

            if(cpustate == 0)
                ena_int(0);

            return _result;
        }
    };

//	typedef class EventDumpRequest EventRequest;
	typedef class Request EventRequest;		//�C�x���g���O�o�͗v���Ŏg�p����郊�N�G�X�g
//	typedef class Request DeviceRequest;	//�f�o�C�X�ʐM�v���Ŏg�p����郊�N�G�X�g
	typedef class ExclusiveDeviceRequest DeviceRequest;	//�f�o�C�X�ʐM�v���Ŏg�p����郊�N�G�X�g

	//==============================================================================

	LONG				Request::RequestCount = -1;	//�L���[�ɂȂ����Ă��郊�N�G�X�g�̐�
	Request *			Request::top  = NULL;		//���N�G�X�g�L���[�̐擪 (�����Ƃ��Â����N�G�X�g)
	Request *			Request::tail = NULL;		//���N�G�X�g�L���[�̖��� (�����Ƃ��V�������N�G�X�g)
	CRITICAL_SECTION	Request::cs;				//�r���L���[����p�댯�̈�I�u�W�F�N�g

	HANDLE              EventDumpRequest::FileHandle    = INVALID_HANDLE_VALUE;     //CreateFile uses INVALID_HANDLE_VALUE for identifying an invalid instance 
    HANDLE              ExclusiveDeviceRequest::blocker = NULL;

	//==============================================================================

		/*
		 *   ��ƃX���b�h���g�p�����Ɗ֐��̒�`
		 */

		//�R�l�N�V�����|�C���g�ւ̐ڑ�
	bool Advise(IUnknown * container, REFIID iid, IUnknown * sink, DWORD * cookie, IConnectionPoint ** p_cp = NULL)
	{
		IConnectionPointContainer * cp_container;
		IConnectionPoint * cp;

        if(container == 0 || sink == 0 || cookie == 0)
            return false;

		if(p_cp == 0)
			p_cp = &cp;

			//IUnknown�C���^�t�F�[�X����IConnectionPointContainer�փL���X�g
		container->QueryInterface(IID_IConnectionPointContainer, (void **)&cp_container);
		if(cp_container == 0)
			return false;

			//ConnectionPointContainer����v���ɍ���ConnectionPoint��T��
		cp_container->FindConnectionPoint(iid, p_cp);
		cp_container->Release();
		if(*p_cp == 0)
			return false;

			//�R�l�N�V�����|�C���g�ڑ�
		if(FAILED((*p_cp)->Advise(sink, cookie)))
			return false;

		if(p_cp == &cp)
			cp->Release();
		return true;
	}

	//==============================================================================
	
    /*
     *  PerformRequest : �v���̎��s
     *     �ԋp�l : �C�x���g�������p������(true) or ��ƃX���b�h���~������(false)
     */

    bool PerformRequest(IKernel * manager)
    {
        Request * request;
        bool succeeded;

			//�L���[���烊�N�G�X�g�𔲂����
		request = Request::GetRequest();
		FatalAssertion(request != NULL,"");

			//�I���v��
		if(request->getType() == Request::QuitThread)
		{
			if(!request->isBlockingRequest())
			{
				BOOL lock;

				enter_system_critical_section(&lock);
				delete request;
				leave_system_critiacl_section(&lock);
			}
            return false;
		}

			//�v�����̏���
		switch(request->getType())
		{
		case Request::Confirmation:
			succeeded = true;
			break;

		case Request::DeviceRead:
			succeeded = SUCCEEDED(manager->Read(request->getAddress(), request->getSize(), reinterpret_cast<char *>(request->getStorage())));
			break;

		case Request::DeviceWrite:
			succeeded = SUCCEEDED(manager->Write(request->getAddress(), request->getSize(), reinterpret_cast<char *>(request->getStorage())));
			break;

		case Request::EventLog:
			succeeded = SUCCEEDED(manager->OnLogEvent(request->getSize(), reinterpret_cast<unsigned char *>(request->getStorage())));

				//�V���b�g�_�E�����Ȃ烍�O��S���͂��I��܂ő҂��Ă��炤
			ShutdownPostponementRequest = TRUE;
			break;

		default:
			succeeded = false;
		}

        request->Finalize(succeeded);

        return true;
    }

		/*
		 *   COM�ʐM���s�����߂̍�ƃX���b�h �{��
		 */
	DWORD WINAPI WorkerThreadProcess(LPVOID _param)
	{
		IKernel * manager;
		IKernelEvents * sink;
		IConnectionPoint * cp;
		DWORD cookie;
		BOOL Success;

        kprintf(("WorkerThreadProcess : start\n"));

			/* ������ */
		::CoInitialize(NULL);

			// �f�o�C�X�}�l�[�W���Ɛڑ�
		manager = 0;
		if(FAILED(::CoCreateInstance(CLSID_Kernel, NULL, CLSCTX_ALL, IID_IKernel, (void **)&manager)))
			goto _WorkerThreadProc_Cleanup;

		cp = 0;
        sink = new(std::nothrow) IKernelEvents;
		if(!Advise(manager, IID_IKernelEvents, sink, &cookie,&cp))
		{
            if(sink != 0)
    			delete sink;
			goto _WorkerThreadProc_Cleanup;
		}

			/* ���C�����[�`�� */
		manager->IsValid(&Success);
		if(Success != 0)
		{
            MSG msg;
			DWORD work;
            bool  loop_flag = true;
			
			do {
                    /*
                     * �O������COM���������ƃ��b�Z�[�W�Ƃ��Ĕ��ł��邽�߁AWaitForSingleObject�ŃZ�}�t�H��҂ƊO������̗v�������s�ł��Ȃ��Ȃ�B
                     * ���̂��߁AMsgWaitFor...��p���A���b�Z�[�W�����ł����ꍇ�͂���ɑΏ��ł���悤�ɂ���B
                     */

                    /*
                     * cygwin������QS_ALLPOSTMESSAGE����`����Ȃ��̂ŁA����őΏ�
                     */
#ifndef QS_ALLPOSTMESSAGE
#define QS_ALLPOSTMESSAGE (0x0100)
#endif

                    //�v���҂�
                work = ::MsgWaitForMultipleObjects(1, &request_semaphore, FALSE, INFINITE, QS_ALLPOSTMESSAGE);

                switch(work) {

                    //�����v���̎��s
                case WAIT_OBJECT_0:
                        loop_flag = PerformRequest(manager);
                        break;

                    //�O������̗v�� (�����݂Ȃ�)
                case WAIT_OBJECT_0 + 1:
                        GetMessage(&msg, 0, 0, 0);
                        TranslateMessage(&msg);
                        DispatchMessage(&msg);
                        break;
                
                default:
                    loop_flag = false;
                }

			} while(loop_flag);
		}

			/*
			 * Finalize
			 */

		if(cp != 0)
		{
			cp->Unadvise(cookie);
			cp->Release();
			cp = 0;
			sink = 0;
		}

	_WorkerThreadProc_Cleanup:

        if(manager != 0)
			manager->Release();

		CloseHandle(worker_thread_handle);
		worker_thread_handle = NULL;
        manager = 0l;
		::CoUninitialize();

		/* �L���[����ɂ��� (�҂�����) */

		Request * request;
		while((request = Request::GetRequest()) != 0)
			request->Finalize(false);
		
        kprintf(("WorkerThreadProcess : exit\n"));

        return 0;
	}
}

//==============================================================================

/****************************************************
 *                                                  *
 * TOPPERS/JSP - Windows�V�~�����[�V������        *
 *   COM��p�����f�o�C�X�G�~�����[�V�����@�\        *
 *                                                  *
 ****************************************************/

#ifdef DEVICE_ENABLE

extern "C"
int _cdecl DeviceRead(unsigned long address, unsigned long size, void * storage)
{
	if(!IsValid() || storage == NULL)
		return -1;

	return DeviceRequest::Create(Request::DeviceRead, true, size, storage, address)->invoke();
}

extern "C"
int _cdecl DeviceWrite(unsigned long address, unsigned long size, void * storage)
{
	if(!IsValid() || storage == NULL)
		return -1;

	return DeviceRequest::Create(Request::DeviceWrite, true, size, storage, address)->invoke();
}

#endif


/****************************************************
 *                                                  *
 * TOPPERS/JSP - Windows�V�~�����[�V������        *
 *   COM��p�����J�[�l�����O�擾�@�\                *
 *                                                  *
 ****************************************************/

#ifdef EVENTLOG_ENABLE

	/* ���d���O�o�͖h�~�p�Z�}�t�H :  1�𑫂������ʂ�1�ł������Ƃ������A���O���o�͂ł��� */
static LONG event_write_semaphore = 0;

void event_write(unsigned int logtype, unsigned int valid, UINT bufsz, ... )
{
	EventRequest * event_request;
	DBIFLOG * log;
	va_list   vl;

	if(IsValid() && TlsGetValue(TLS_LOGMASK) == 0)
	{
			// ���N�G�X�g�̈�m��
		event_request = EventRequest::Create(EventRequest::EventLog, false, sizeof(T_RGLOG_HEADER) + bufsz);
		log     = reinterpret_cast<DBIFLOG *>(event_request->getptr());

			// �w�b�_����
		log->header.logtype = logtype;
		log->header.logtim  = _kernel_systim_offset + _kernel_current_time;
		log->header.valid   = valid;
		log->header.bufsz   = bufsz;

			// �{�̂̊i�[
		va_start(vl, bufsz);
		for(unsigned int i=0;i<bufsz/sizeof(int);i++)
			*((int *)&log->body + i) = va_arg(vl, int);

			// �v���̑��t (Non-blocking)
		event_request->invoke();
	}
}

extern "C"
void event_write_svc_enter(int fncd, unsigned int params, ... )
{
	EventRequest * event_request;
	DBIFLOG *      log;
	va_list        vl;
	unsigned int   i;

	if(IsValid() && TlsGetValue(TLS_LOGMASK) == 0)
	{
			//�̈�m�� : �m�ۂ���T�C�Y�̓p�����[�^������������� (�Ăяo�����A�h���X���i�[)
		event_request = EventRequest::Create(EventRequest::EventLog, false, sizeof(T_RGLOG_HEADER) + sizeof(T_RGLOG_SVC) + params * sizeof(VP_INT));	
		log     = reinterpret_cast<DBIFLOG *>(event_request->getptr());

			//�p�P�b�g����
		log->header.logtype = LOG_TYPE_SVC;
		log->header.logtim  = _kernel_systim_offset + _kernel_current_time;
		log->header.valid   = 0x7fffffff >> (29 - params);
		log->header.bufsz   = (params+3) * sizeof(int);

		va_start(vl, params);

		log->body.svc.fncno  = fncd;
		log->body.svc.prmcnt = params;

			/* ��񃋁[�v�������͍̂Ō�Ɍďo���A�h���X��ς�ł��邽�� */
		for(i=0;i<params+1;i++)
			log->body.svc.prmary[i] = va_arg(vl, VP_INT);

		event_request->invoke();
	}
}

extern "C"
void event_write_svc_leave(int fncd, unsigned int ercd, unsigned int retaddr)
{
	EventRequest * event_request;
	DBIFLOG * log;

	if(IsValid() && TlsGetValue(TLS_LOGMASK) == 0)
	{
			//�̈�m�� : �m�ۂ���T�C�Y�̓p�����[�^����(�ԋp�l�݂̂Ȃ̂łP��)��������� (�Ăяo�����A�h���X���i�[)
		event_request = EventRequest::Create(EventRequest::EventLog, false, sizeof(T_RGLOG_HEADER) + sizeof(T_RGLOG_SVC) + sizeof(VP_INT));
		log     = reinterpret_cast<DBIFLOG *>(event_request->getptr());

			//�w�b�_������
		log->header.logtype = LOG_TYPE_SVC|LOG_LEAVE;
		log->header.logtim  = _kernel_systim_offset + _kernel_current_time;
		log->header.valid   = 0x7;
		log->header.bufsz   = 4 * sizeof(int);

			//�{�f�B������
		log->body.svc.fncno     = fncd;
		log->body.svc.prmcnt    = 1;
		log->body.svc.prmary[0] = (VP_INT)ercd;
		log->body.svc.prmary[1] = (VP_INT)retaddr;

		event_request->invoke();
	}
}

extern "C" void decode_taskstatus(void * tcb, int * tskid, unsigned int * tskstat, unsigned int * objtype, int * objid);

extern "C" 
void event_write_tskstat(void * tcb)
{
	EventRequest * event_request;
	DBIFLOG * log;

	if(IsValid())	//����̓J�[�l������Ȃ̂�TLS_LOGMASK�����Ă͂����Ȃ�
	{
			//�̈�m��
		event_request = EventRequest::Create(EventRequest::EventLog, false, sizeof(T_RGLOG_HEADER) + sizeof(T_RGLOG_TSKSTAT));
		log     = reinterpret_cast<DBIFLOG *>(event_request->getptr());

		log->header.logtype = LOG_TYPE_TSKSTAT;
		log->header.logtim  = _kernel_systim_offset + _kernel_current_time;
		log->header.valid   = 0xf;
		log->header.bufsz   = 4 * sizeof(int);

		decode_taskstatus(tcb, &log->body.tskstat.tskid, &log->body.tskstat.tskstat, &log->body.tskstat.tskwait, &log->body.tskstat.wobjid);

		event_request->invoke();
	}
}

#endif


static BOOL CALLBACK NotifyDialogProc(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
	case WM_INITDIALOG:
		{
			LONG  count;
			HWND  hCtrl;
			
			hCtrl = ::GetDlgItem(hDlg, IDC_PROGRESS1);
			count = Request::getRequestCount();

			::SetWindowLong(hDlg, GWL_USERDATA, count);
			::SendMessage(hCtrl, PBM_SETRANGE32, 0, count);
			::SendMessage(hCtrl, PBM_SETPOS, count - Request::getRequestCount(), 0);

			::SetTimer(hDlg, 100, 200, NULL);
			break;
		}

	case WM_TIMER:
		if(wParam == 100)
		{
			LONG  count;
			HWND  hCtrl;

			hCtrl = ::GetDlgItem(hDlg, IDC_PROGRESS1);
			count = ::GetWindowLong(hDlg, GWL_USERDATA);

			::SendMessage(hCtrl, PBM_SETPOS, count - Request::getRequestCount(), 0);

			if(Request::getRequestCount() <= 0)
				::PostQuitMessage(0);
		}
		break;
	case WM_CLOSE:
		break;

	default:
		return FALSE;
	}
	return TRUE;
}

extern "C"
void _cdecl InitializeComSupportModule(void)
{
    kprintf(("InitializeComSupportModule()\n"));

	Request::initialize();
	DeviceRequest::initialize();
	EventRequest::initialize();


	request_semaphore = ::CreateSemaphore(0, 0, 65536, 0);
	FatalAssertion(request_semaphore != NULL, "Object Creation Error : request_semaphore");

	worker_thread_handle = ::CreateThread(0, 0, WorkerThreadProcess, 0, 0, 0);
	FatalAssertion(worker_thread_handle != NULL, "Object Creation Error : worker_thread");

	Request * request = Request::Create(Request::Confirmation, true);
	request->invoke();
}

extern "C"
void _cdecl FinalizeComSupportModule(void)
{
    kprintf(("FinalizeComSupportModule()\n"));

    if(IsValid())
	{
		HWND  hDlgitem;
		HWND  NotifyDialog;
		MSG   msg;

			//���O�����܂肷����ƃ��O�f���Ɏ��Ԃ�������A�v���O�������\�������悤�Ɍ�����̂�
			//�u���O��f���Ă邩��҂āv�ƌx�����o���B
		NotifyDialog = ::CreateDialog(ProcessInstance, MAKEINTRESOURCE(QUITNOTICEDIALOG), NULL, NotifyDialogProc);
		hDlgitem     = ::GetDlgItem(NotifyDialog, IDC_NOTIFYMSG);
		::SetWindowText(hDlgitem, "�� �ꐶ�����J�[�l���̃C�x���g���O���o���Ă���̂ŁA�I��܂ŏ����҂��Ă�������");
		::ShowWindow(NotifyDialog, SW_NORMAL);

		Request * request = Request::Create(Request::QuitThread, false);
		request->invoke();

			//�I���_�C�A���O�p�̃��b�Z�[�W�|���v

        if(NotifyDialog != NULL) {
            while(GetMessage(&msg, NULL, 0, 0) != 0) {
        	    TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

			//�����ƃX���b�h���I������܂őҋ@
		if(worker_thread_handle != NULL)
            ::WaitForSingleObject(worker_thread_handle, INFINITE);
		::CloseHandle(request_semaphore);
        request_semaphore = NULL;

		EventRequest::finalize();
		DeviceRequest::finalize();
		Request::finalize();

		::DestroyWindow(NotifyDialog);
	}
}


#else	// __COM_NOT_REQUIRED__

extern "C"
void _cdecl InitializeComSupportModule(void)
{}

extern "C"
void _cdecl FinalizeComSupportModule(void)
{}

#endif // __COM_NOT_REQUIRED__
