#include "jsp_kernel.h"
#include "logtask.h"
#include "timer.h"

#define OBJECT(x,y) __asm("d" #x "," #y "@");
#define MEMBER(x,y) __asm("s" #x "::" #y ",(%0),(%1)@" ::\
     "i"(sizeof(((struct x *)0)->y)), "i"(&((struct x *)0)->y));
#define VAR(x) __asm("s" #x ",(%0),(0)@" :: "i"(sizeof(x)));
#define EVAR(x,y) __asm("s" #y ",(%0),(0)@" :: "i"(sizeof(x)));
#define SVAR(x) __asm("s" #x ",(%0),(0)@" :: "i"(sizeof(x[0])));
#define DEFS(x) __asm("s" #x ",(%0),(0)@" :: "i"((unsigned long)x));

#include "queue.h"

#include "task.h"
#include "semaphore.h"
#include "eventflag.h"
#include "dataqueue.h"
#include "mailbox.h"
#include "mempfix.h"
#include "cyclic.h"
#include "../kernel/exception.h"
#include "interrupt.h"
#include "wait.h"

void checker_function(void)
{
	DEFS(TMAX_TPRI);
	DEFS(TMIN_TPRI);

	DEFS(TMAX_MPRI);
	DEFS(TMIN_MPRI);

	DEFS(TMAX_RELTIM);

	MEMBER(queue,next);
	MEMBER(queue,prev);


		/* task */

	OBJECT(task_5,LOGTASK);
	OBJECT(task_4,MAIN_TASK);
	OBJECT(task_1,TASK1);
	OBJECT(task_2,TASK2);
	OBJECT(task_3,TASK3);
	EVAR(ID,_kernel_tmax_tskid);
	EVAR(TINIB,_kernel_tinib_table);
	MEMBER(task_initialization_block,tskatr);
	MEMBER(task_initialization_block,exinf);
	MEMBER(task_initialization_block,task);
	MEMBER(task_initialization_block,ipriority);
	MEMBER(task_initialization_block,stksz);
	MEMBER(task_initialization_block,stk);
	MEMBER(task_initialization_block,texatr);
	MEMBER(task_initialization_block,texrtn);


		/* semaphore */

	OBJECT(semaphore_1,SERIAL_RCV_SEM1);
	OBJECT(semaphore_2,SERIAL_SND_SEM1);
	EVAR(ID,_kernel_tmax_semid);
	EVAR(SEMINIB,_kernel_seminib_table);
	MEMBER(semaphore_initialization_block,sematr);
	MEMBER(semaphore_initialization_block,isemcnt);
	MEMBER(semaphore_initialization_block,maxsem);


		/* eventflag */

	EVAR(ID,_kernel_tmax_flgid);
	EVAR(FLGINIB,_kernel_flginib_table);
	MEMBER(eventflag_initialization_block,flgatr);
	MEMBER(eventflag_initialization_block,iflgptn);


		/* dataqueue */

	EVAR(ID,_kernel_tmax_dtqid);
	EVAR(DTQINIB,_kernel_dtqinib_table);
	MEMBER(dataqueue_initialization_block,dtqatr);
	MEMBER(dataqueue_initialization_block,dtqcnt);
	MEMBER(dataqueue_initialization_block,dtq);


		/* mailbox */

	EVAR(ID,_kernel_tmax_mbxid);
	EVAR(MBXINIB,_kernel_mbxinib_table);
	MEMBER(mailbox_initialization_block,mbxatr);
	MEMBER(mailbox_initialization_block,maxmpri);


		/* mempfix */

	EVAR(ID,_kernel_tmax_mpfid);
	EVAR(MPFINIB,_kernel_mpfinib_table);
	MEMBER(fixed_memorypool_initialization_block,mpfatr);
	MEMBER(fixed_memorypool_initialization_block,blksz);
	MEMBER(fixed_memorypool_initialization_block,mpf);
	MEMBER(fixed_memorypool_initialization_block,limit);


		/* cyclic */

	OBJECT(cyclic_1,CYCHDR1);
	EVAR(ID,_kernel_tmax_cycid);
	EVAR(CYCINIB,_kernel_cycinib_table);
	MEMBER(cyclic_handler_initialization_block,cycatr);
	MEMBER(cyclic_handler_initialization_block,exinf);
	MEMBER(cyclic_handler_initialization_block,cychdr);
	MEMBER(cyclic_handler_initialization_block,cyctim);
	MEMBER(cyclic_handler_initialization_block,cycphs);


		/* interrupt */

	OBJECT(interrupt_0,0);
	OBJECT(interrupt_1,1);
	EVAR(ID,_kernel_tnum_inhno);
	EVAR(INHINIB,_kernel_inhinib_table);
	MEMBER(interrupt_handler_initialization_block,inhno);
	MEMBER(interrupt_handler_initialization_block,inhatr);
	MEMBER(interrupt_handler_initialization_block,inthdr);


		/* exception */

	EVAR(ID,_kernel_tnum_excno);
	EVAR(EXCINIB,_kernel_excinib_table);
	MEMBER(cpu_exception_handler_initialization_block,excno);
	MEMBER(cpu_exception_handler_initialization_block,excatr);
	MEMBER(cpu_exception_handler_initialization_block,exchdr);

}
