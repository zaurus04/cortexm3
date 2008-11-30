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
 *  @(#) $Id: cpu_defs.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#define _WIN32_WINNT 0x400

#include <s_services.h>
#include <hal_msg.h>

/*
 * m68k���ۂ������݃G�~�����[�^ (Windows HAL)
 */

	/* ���݂̊����݃}�X�N���x�� */
unsigned int CurrentInterruptLevel;

	/* �����݊Ǘ��e�[�u�� */
static struct tagInterruptLevel InterruptLevel[INT_NUMINTERRUPTS];

	/* �����݃}�X�N���x���̗L���͈̓`�F�b�N */
#define CHECK_IMS(x) ( (x) != 0 && (x) <= INT_NUMINTERRUPTS )

	/* ��O�Ǘ��e�[�u�� */
struct tagExceptionLevel ExceptionLevel[EXC_MAXITEMS];

	/* �����̑O�ɓo�^����Ă����\������O�n���h���̃A�h���X */
static LPTOP_LEVEL_EXCEPTION_FILTER AnotherExceptionFilter;

/*
 *   �V�X�e���S�̂̃N���e�B�J���Z�N�V�����������[�`��
 *     �E�ǂ�����CRITICAL_SECTION���g���̂���߂��̂�
 *        -> Windows�̃N���e�B�J���Z�N�V�����́AITRON�Ō����Ƃ���̃f�B�X�p�b�`�֎~�Ŏ������Ă���炵���A
 *           �O���C�x���g�ŋN�����Ă��܂����X���b�h���N���e�B�J���Z�N�V�������ɂ���X���b�h�̓����
 *           ��~�����Ă��܂����Ƃ��ł���炵���B�Ȃ̂�CPU���b�N�̂���ŃN���e�B�J���Z�N�V�������g���Ă���ƁA
 *           ���͂����̃f�B�X�p�b�`�֎~�Ȃ̂Ńn���h�����N�����Ă��܂��APrimaryThread��SuspendThread�𔭍s���ăf�b�h���b�N���Ă��܂��B
 *           ���̖��͎��X����������ɖ��Ȗ�肾�������A�܂�������Ȃ��Ƃ��������Ƃ͎v�������Ȃ������B
 *           WinProg�n��ML�ł��u�����s���̕s���������C���Ȃ�N���e�B�J���Z�N�V�����͎g��Ȃ��ق����悢�v�Ƃ����Ă���B
 */

static HANDLE SystemMutex = NULL;		                //�V�X�e�����b�N�p�̃~���[�e�b�N�X�I�u�W�F�N�g
static DWORD  SystemMutexOwnerThreadID = 0;				//�V�X�e�����b�N���擾�����X���b�h��ID
static DWORD  SystemMutexLastOwnerThreadID = 0;			//�Ō�ɃV�X�e�����b�N���擾���Ă����X���b�h��ID (�f�o�b�O�p)

	/*
	 *   enter_system_critical_section : �V�X�e���̃��b�N�����l������
	 *     BOOL * lock : �N�b�L�[(�������n�߂ă��b�N�����l�������TRUE���Ԃ�)
	 */
void enter_system_critical_section(BOOL * lock)
{
	if(SystemMutex != NULL && SystemMutexOwnerThreadID != GetCurrentThreadId())
	{
		WaitForSingleObject(SystemMutex, INFINITE);	
		if(lock != NULL)
			*lock = TRUE;
		SystemMutexOwnerThreadID = GetCurrentThreadId();
	}else
	{
		if(lock != NULL)
			*lock = FALSE;
	}
}

	/*
	 *   leave_system_critical_section : �V�X�e���̃��b�N�����J������
	 *		BOOL * lock : enter_system_critical_section�Ŏg�p�����N�b�L�[
	 */
void leave_system_critiacl_section(BOOL * lock)
{
	assert(lock != NULL);

	if(*lock == TRUE)
	{
		SystemMutexLastOwnerThreadID = SystemMutexOwnerThreadID;
		SystemMutexOwnerThreadID = 0;
		if(SystemMutex != NULL)
			ReleaseMutex(SystemMutex);	
	}
}

	/*
	 *   wait_for_thread_suspension_completion : �X���b�h�����b�N���J����ԂŒ�~������ 
	 */
ER wait_for_thread_suspension_completion(HANDLE thread)
{
	BOOL lock;

	if(thread == 0 || thread == NULL)
		return E_PAR;

	enter_system_critical_section(&lock);
	SuspendThread(thread);
	leave_system_critiacl_section(&lock);

	return 0;
}



/*
 *  ���Ɏ��s���ׂ������݃n���h���̂��郌�x�����擾����
 *      ipl : �����݃}�X�N���x��
 *
 *    ���荞�݃��x���}�X�N��ipl�܂ŉ��������Ƃ��ɁA���ɓ������ׂ������݂�I������B
 *    �}�X�N���x��������ʂ̊����݂̏ꍇ�A�y���f�B���O���ꂽ�v�� or ���Ɏ��s��
 *    �n�܂��Ă���n���h�� �����s����B�}�X�N���x���ȉ��̏ꍇ�A���ɓ����Ă���
 *    �n���h��������ꍇ�̂ݎ��s����B�����Ȃ��ꍇ��0��Ԃ��B
 */
static unsigned int
isns_int( unsigned int ipl )
{
	unsigned int result = INT_NUMINTERRUPTS;
	
	if((CPUStatus & CPU_STAT_LOCK) != 0)
		return 0;

	while(result > ipl)
	{
		result --;
		if( (InterruptLevel[result].Flags & (INT_STAT_PENDING|INT_STAT_RUNNING)) != 0)
			return result+1;
	}
	while(result > 0)
	{
		result --;
		if( (InterruptLevel[result].Flags & INT_STAT_RUNNING) != 0)
			return result+1;
	}
	return 0;
}

static DWORD WINAPI
InterruptHandlerWrapper(LPVOID param)
{
	unsigned int   i;
	unsigned int   PrevLevel;
	BOOL           systemLock;

	struct tagInterruptLevel * intlv = (struct tagInterruptLevel *)param;

	TlsAlloc();

    kprintf(("InterruptHandlerWrapper (%d) : start\n", (intlv - InterruptLevel) + 1 ));

	while(1==1)
	{
			/* �����ݑO���� */

		set_logcontrol((intlv->Flags & INT_MOD_LOGMASK) != 0);
		LOG_INH_ENTER((intlv - InterruptLevel)+1);

        assert((CPUStatus & CPU_STAT_LOCK) == 0);
        enter_system_critical_section(&systemLock);
        PrevLevel = CurrentInterruptLevel;
		CurrentInterruptLevel = (unsigned int)(intlv - InterruptLevel)+1;
		intlv->Flags &= ~INT_STAT_PENDING;
		intlv->Flags |=  INT_STAT_RUNNING;
		leave_system_critiacl_section(&systemLock);

        ( (void (*)(void) )(intlv->Routine))();
        
			/* �����݌㏈�� 
             *    �����ň�C��PrevLevel�܂ŗ��Ƃ��Ă͂����Ȃ�.
             *    ���荞�݂̓�����ɂ���ẮA�D��x�̒Ⴂ�����݂̒E�o�������D��x�̍������荞�݂̐i�������̒���Ɏ��s����A
             *    �^�������ƗD��x�̍��������݂�CurrentInterruptLevel = 0�̏�Ԃő����Ă��܂����ƂɂȂ�B
             */
		enter_system_critical_section(&systemLock);
		intlv->Flags &= ~INT_STAT_RUNNING;
		i = isns_int(PrevLevel);
		if(i > PrevLevel)
			CurrentInterruptLevel = i - 1;
		else
			CurrentInterruptLevel = PrevLevel;
		leave_system_critiacl_section(&systemLock);

		LOG_INH_LEAVE((intlv - InterruptLevel)+1);

            /* ���̊����݂���������悤�ɒʒm */
	    HALInterruptRequestAndWait();
	}

    kprintf(("InterruptHandlerWrapper (%d) : exit\n", (intlv - InterruptLevel) + 1 ));

    ExitThread(0);
	return 0;
}

BOOL
def_int(unsigned int ims, void * rtn)
{
	BOOL lock;

	if(!CHECK_IMS(ims) || rtn == NULL)
		return FALSE;

    kprintf(("def_int : [ims:%d]\n", ims));

	ims--;

	enter_system_critical_section(&lock);
	if(InterruptLevel[ims].ThreadHandle != NULL)
	{
		TerminateThread(InterruptLevel[ims].ThreadHandle,0);
		CloseHandle(InterruptLevel[ims].ThreadHandle);
	}
	InterruptLevel[ims].Routine = rtn;
	InterruptLevel[ims].ThreadHandle = CreateThread(NULL,0,InterruptHandlerWrapper,(LPVOID)&InterruptLevel[ims],CREATE_SUSPENDED,&InterruptLevel[ims].ThreadID);
	leave_system_critiacl_section(&lock);

	return TRUE;
}

BOOL
ini_int(void)
{
	int i;

    kprintf(("ini_int : [Start]\n"));

    SystemMutex = CreateMutex(NULL,TRUE,NULL);

	for(i=0;i<INT_NUMINTERRUPTS;i++)
	{
		InterruptLevel[i].Routine      = (void *)0l;
		InterruptLevel[i].ThreadHandle = NULL;
		InterruptLevel[i].ThreadID     = 0;
		InterruptLevel[i].Flags        = INT_MOD_LOGMASK;
	}

		/* �����N����CPU���b�N��Ԃֈڍs������ */
	CurrentInterruptLevel = 0;	//�����݃}�X�N�͑S����
	CPUStatus |= CPU_STAT_LOCK;	//CPU�Ŋ����݋֎~��

	ReleaseMutex(SystemMutex);

    kprintf(("ini_int : [Exit]\n"));

	return TRUE;
}

void
fin_int(void)
{
	int    i;
	HANDLE work;

    kprintf(("fin_int : [Start]\n"));

	enter_system_critical_section(NULL);

	for(i=0;i<INT_NUMINTERRUPTS;i++)
	{
		if(InterruptLevel[i].ThreadHandle != NULL)
		{
			TerminateThread(InterruptLevel[i].ThreadHandle,0);
			CloseHandle(InterruptLevel[i].ThreadHandle);
		}
		InterruptLevel[i].Routine = (void *)0l;
		InterruptLevel[i].ThreadHandle = NULL;
		InterruptLevel[i].ThreadID = 0;
		InterruptLevel[i].Flags    = 0;
	}
	CurrentInterruptLevel = 0;

        /* CloseHandle(SystemMutex), SystemMutex = INVALID_HANDLE; �����S�ɂ�� */
	work = SystemMutex;
	SystemMutex = NULL;
	CloseHandle(work);

		//����ȍ~��CPU���b�N��Ԃ��Ǝv������
	CPUStatus |= CPU_STAT_LOCK;

    kprintf(("fin_int : [Exit]\n"));
}

BOOL
ras_int(unsigned int ims)
{
	BOOL lock;
	BOOL result = TRUE;

	if(!CHECK_IMS(ims))
		return FALSE;

	ims --;

	enter_system_critical_section(&lock);
	if(InterruptLevel[ims].ThreadHandle == NULL)
	{
		result = FALSE;
	}else
		InterruptLevel[ims].Flags |= INT_STAT_PENDING;
	leave_system_critiacl_section(&lock);
	return result;
}

unsigned int
sns_int( void )
{
	BOOL lock;
	int  result;

	if(sense_lock() == TRUE)
		return 0;

	enter_system_critical_section(&lock);
	result = isns_int(CurrentInterruptLevel);
	leave_system_critiacl_section(&lock);
	return result;
}

HANDLE
sch_int( void )
{
	BOOL   lock;
	HANDLE result;
	unsigned int level;

	if(sense_lock() == TRUE)
		return NULL;

	enter_system_critical_section(&lock);
	level = isns_int(CurrentInterruptLevel);
	if(level != 0)
	{
		result = InterruptLevel[level-1].ThreadHandle;
	}else
		result = NULL;
	leave_system_critiacl_section(&lock);

	return result;
}

DWORD LockerThreadID = 0;

ER
ena_int(unsigned int ims)
{
	BOOL lock;
	int  i;

	enter_system_critical_section(&lock);
	i = isns_int(CurrentInterruptLevel);
	CPUStatus &= ~CPU_STAT_LOCK;
	LockerThreadID = 0;
	leave_system_critiacl_section(&lock);

	if(i != 0)
		HALInterruptRequest(0);

	return 0 /*E_OK*/;
}

ER
dis_int(unsigned int ims)
{
	BOOL lock;

	enter_system_critical_section(&lock);
	CPUStatus |= CPU_STAT_LOCK;
	if(LockerThreadID == 0)
	{
		LockerThreadID = GetCurrentThreadId();
	}else
	{
		DWORD newThreadID = GetCurrentThreadId();
		LockerThreadID = GetCurrentThreadId();	//�u���[�N�u����
	}
	leave_system_critiacl_section(&lock);

	return 0;
}

ER
chg_ims(unsigned int ims)
{
	BOOL lock;
	int  i;

		//chg_ims �� ims==0 ������
	if(ims != 0 && !CHECK_IMS(ims))
		return -17 /*E_PAR*/;

	enter_system_critical_section(&lock);
	CurrentInterruptLevel = ims;
	if(CurrentInterruptLevel == INT_NUMINTERRUPTS)
		CPUStatus |= CPU_STAT_LOCK;
	else
		CPUStatus &= ~CPU_STAT_LOCK;
	i = isns_int(ims);
	leave_system_critiacl_section(&lock);

	if(i != 0)
		HALInterruptRequest(0);

	return 0 /*E_OK*/;
}

ER
get_ims(unsigned int *p_ims)
{
	BOOL lock;

	if(p_ims == (void *)0l)
		return -17 /*E_PAR*/;

	enter_system_critical_section(&lock);
	if((CPUStatus & CPU_STAT_LOCK) != 0)
		*p_ims = INT_NUMINTERRUPTS;
	else
		*p_ims = CurrentInterruptLevel;
	leave_system_critiacl_section(&lock);
	return 0 /*E_OK*/;
}

ER
vget_ims(unsigned int *p_ims)
{
	BOOL lock;

	if(p_ims == (void *)0l)
		return -17 /*E_PAR*/;

	enter_system_critical_section(&lock);
	*p_ims = CurrentInterruptLevel;
	leave_system_critiacl_section(&lock);
	return 0 /*E_OK*/;
}

/*
 * �ŏ�ʃ��x��Windows�\������O�n���h��
 */

LONG WINAPI
HALExceptionHandler( EXCEPTION_POINTERS * exc )
{
	int i;
	int result;

	if((CPUStatus & CPU_STAT_EXC) == 0)
		CPUStatus |= CPU_STAT_DOUBLEFAULT;

        /* �n���T�[�` (��Ԃ����܂�����...) */
	CPUStatus |= CPU_STAT_EXC;
	for(i=0;i<EXC_MAXITEMS;i++)
	{
		if(ExceptionLevel[i].ExceptionCode == exc->ExceptionRecord->ExceptionCode)
		{
			result = EXCEPTION_CONTINUE_SEARCH;
	
			LOG_EXC_ENTER(i);
			( * ((void (*)(void *,int *))ExceptionLevel[i].Routine)) (exc,&i);
			LOG_EXC_LEAVE(i);

			CPUStatus &= ~CPU_STAT_EXC;
			return result;
		}
	}
	CPUStatus &= ~CPU_STAT_EXC;
	return EXCEPTION_CONTINUE_SEARCH;
}

BOOL
ini_exc(void)
{
	int i;

	for(i=0;i<EXC_MAXITEMS;i++)
	{
		ExceptionLevel[i].ExceptionCode = 0;
		ExceptionLevel[i].Routine = 0l;
	}

	AnotherExceptionFilter = SetUnhandledExceptionFilter(HALExceptionHandler);
	
	return TRUE;
}

void
fin_exc(void)
{
    SetUnhandledExceptionFilter(AnotherExceptionFilter);
}

BOOL
def_exc(DWORD exc, void * routine)
{
	int j;
	int i;

        /* �������[�`�� */
	if(routine == 0l)
	{
        kprintf(("def_exc : [UNREG] 0x%08x\n", exc));

		for(i=0;i<EXC_MAXITEMS;i++)
			if(ExceptionLevel[i].ExceptionCode == exc)
			{
				ExceptionLevel[i].ExceptionCode = 0;
				ExceptionLevel[i].Routine = 0;
				return TRUE;
			}
		return FALSE;
	}

    /* �o�^���[�`�� */

    kprintf(("def_exc : [REG] 0x%08x\n", exc));

	j = EXC_MAXITEMS;
	for(i=0;i<EXC_MAXITEMS;i++)
	{
		if(ExceptionLevel[i].ExceptionCode != 0)
		{
				/* �o�^���悤�Ƃ��Ă���ԍ������ɓo�^����Ă��Ȃ����ǂ������ׂ� */
			if(ExceptionLevel[i].ExceptionCode == exc)
				return FALSE;
		}else
		{
				/* �󂫔ԍ��̍ŏ����o���� */
			if(j > i)
				j = i;

            /* ���o�^�`�F�b�N������̂ŁA������break���Ă̓_�� */
		}
	}

	FatalAssertion(i == EXC_MAXITEMS, "No available exception slots left.");

		//This sequence will never change
	ExceptionLevel[j].Routine       = routine;
	ExceptionLevel[j].ExceptionCode = exc;

	return TRUE;
}

ER set_intlogmask( unsigned int ims, BOOL mask )
{
	BOOL lock;

	if( !CHECK_IMS(ims) )
		return FALSE;

	-- ims;

	enter_system_critical_section(&lock);
	if(mask == TRUE)
		InterruptLevel[ims].Flags |= INT_MOD_LOGMASK;
	else
		InterruptLevel[ims].Flags &= ~INT_MOD_LOGMASK;
	leave_system_critiacl_section(&lock);

	return TRUE;
}

unsigned int current_timer_clock_unit = TIMER_CLOCK_WINDOWS;

ER set_clk(unsigned int clk)
{
    BOOL lock;

    if(clk == 0)
        clk = TIMER_CLOCK_WINDOWS;

    hw_timer_terminate();
    enter_system_critical_section(&lock);
    current_timer_clock_unit = clk;
    leave_system_critiacl_section(&lock);
    hw_timer_initialize();

    return E_OK;
}
