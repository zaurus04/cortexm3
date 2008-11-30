/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                2003      by Advanced Data Controls, Corp
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
 *  @(#) $Id: ghs_hook.c,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */
#ifdef GHS_HOOK
#include "jsp_kernel.h"
#include "kernel.h"
#include "time_event.h"
#include "task.h"
#include "ghs_hook.h"


#define	THG_ALL	THG_SYS|THG_RET|THG_DSP|THG_STS|THG_INT
#define	THF_ALL	THF_TSK|THF_TSKS|THF_TEX|THF_SEM|THF_FLG|THF_DTQ|THF_MBX|THF_MPF|THF_TIM
#ifndef GRP
#define	GRP	THG_ALL
#endif
#ifndef SEV
#define	SEV	THF_ALL  
#endif
#ifndef TSK
#define	TSK	TRACE_TNUM_TSKID
#endif


#define MAX_TSK  256

T_ROS Ros_buf;

struct GHS_TASKS {
	B	sts;			
	B	pri;			
} ghs_tasks[MAX_TSK];

ghs_tasks_initialize()
{
	INT	i;
	TCB	*tcb;

	for (tcb = tcb_table, i = 0; i < tmax_tskid; tcb++, i++) {
		if(i > sizeof(ghs_tasks) / sizeof(ghs_tasks[0]))
			return;
		if(TSTAT_RUNNABLE(tcb->tstat)) ghs_tasks[i].sts = TTS_RDY;
		else ghs_tasks[i].sts = TTS_DMT;
		ghs_tasks[i].pri = EXT_TSKPRI(tcb->priority);
	}
}

int SetEndian()
{
    union testme {
        char    a[2];
        short   b;
    	} testme;

    testme.b    = 0;
    testme.a[0] = 1;
    if (testme.b== 1)
        return(0);
    else
        return(1);
}

void vinit_hook(void)
{
    int i;

    Ros_buf.trace.bigendian = SetEndian();
    Ros_buf.trace.dummy = 0;
    Ros_buf.trace.size = BUFF_SIZE-1;
    Ros_buf.trace.putp = 0;
    Ros_buf.trace.getp = 0;
    for(i = 0; i < TRACE_TNUM_TSKID-1; i++)
        Ros_buf.hook.task_id[i] = 0;
    for(i = 0; i < TRACE_TNUM_EVT-1; i++)
        Ros_buf.hook.evtcode[i] = 0;
    Ros_buf.hook.max_tid = tmax_tskid;
    Ros_buf.hook.tnum_tskid = TRACE_TNUM_TSKID;
    Ros_buf.hook.tnum_evt = TRACE_TNUM_EVT;

    Ros_buf.hook.trc_grp = GRP;
    Ros_buf.hook.sys_grp = SEV;
    for(i = 0; i < TSK; i++)
        Ros_buf.hook.task_id[i] = 1;    
    
}

void ghs_hook4(int sts, int p1, int p2)
{
    int putp;

        while(BUFF_SIZE-(Ros_buf.trace.putp-Ros_buf.trace.getp) < 4)
        {
	    Ros_buf.trace.getp += Ros_buf.syscall[Ros_buf.trace.getp & Ros_buf.trace.size] & 0x0F;
        }
        putp = Ros_buf.trace.putp;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = (sts << 4) | 4;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = current_time;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p1;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p2;
        Ros_buf.trace.putp = putp;
}

void ghs_hook5(int sts, int p1, int p2, int p3)
{
    int putp;

        while(BUFF_SIZE-(Ros_buf.trace.putp-Ros_buf.trace.getp) < 5)
        {   Ros_buf.trace.getp += Ros_buf.syscall[Ros_buf.trace.getp & Ros_buf.trace.size] & 0x0F;
        }
	putp = Ros_buf.trace.putp;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = (sts << 4) | 5;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = current_time;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p1;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p2;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p3;
        Ros_buf.trace.putp = putp;
}

void ghs_hook6(int sts, int p1, int p2, int p3, int p4)
{
    int putp;

        while(BUFF_SIZE-(Ros_buf.trace.putp-Ros_buf.trace.getp) < 6)
        {   Ros_buf.trace.getp += Ros_buf.syscall[Ros_buf.trace.getp & Ros_buf.trace.size] & 0x0F;
        }

        putp = Ros_buf.trace.putp;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = (sts << 4) | 6;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = current_time;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p1;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p2;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p3;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p4;
        Ros_buf.trace.putp = putp;
}

void ghs_hook7(int sts, int p1, int p2, int p3, int p4, int p5)
{
    int putp;

        while(BUFF_SIZE-(Ros_buf.trace.putp-Ros_buf.trace.getp) < 7)
        {   Ros_buf.trace.getp += Ros_buf.syscall[Ros_buf.trace.getp & Ros_buf.trace.size] & 0x0F;
        }

        putp = Ros_buf.trace.putp;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = (sts << 4) | 7;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = current_time;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p1;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p2;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p3;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p4;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p5;
        Ros_buf.trace.putp = putp;
}

void ghs_hook8(int sts, int p1, int p2, int p3, int p4, int p5, int p6)
{
    int putp;

        while(BUFF_SIZE-(Ros_buf.trace.putp-Ros_buf.trace.getp) < 8)
        {   Ros_buf.trace.getp += Ros_buf.syscall[Ros_buf.trace.getp & Ros_buf.trace.size] & 0x0F;
        }
        putp = Ros_buf.trace.putp;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = (sts << 4) | 8;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = current_time;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p1;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p2;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p3;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p4;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p5;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p6;
        Ros_buf.trace.putp = putp;
}

void ghs_hook9(int sts, int p1, int p2, int p3, int p4, int p5, int p6, int p7)
{
    int putp;

        while(BUFF_SIZE-(Ros_buf.trace.putp-Ros_buf.trace.getp) < 9)
        {   Ros_buf.trace.getp += Ros_buf.syscall[Ros_buf.trace.getp & Ros_buf.trace.size] & 0x0F;
        }

        putp = Ros_buf.trace.putp;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = (sts << 4) | 9;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = current_time;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p1;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p2;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p3;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p4;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p5;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p6;
        Ros_buf.syscall[putp++ & Ros_buf.trace.size] = p7;
        Ros_buf.trace.putp = putp;
}

#endif

