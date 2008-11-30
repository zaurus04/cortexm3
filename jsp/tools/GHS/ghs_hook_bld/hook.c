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
 *  @(#) $Id: hook.c,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

#ifdef GHS_HOOK
#include "jsp_kernel.h"
#include "kernel.h"
#include "task.h"
#include "ghs_hook.h"

void sys_hook0(int grp, int code)
{
    ID tskid=TSKID(runtsk);
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (tskid > TRACE_TNUM_TSKID || !(Ros_buf.hook.task_id[tskid]))
        return;
#endif
    t_lock_cpu();
    ghs_hook4(THG_SYS, tskid, code);
    t_unlock_cpu();
}

void sys_hook0_i(int grp, int code)
{
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (!(Ros_buf.hook.task_id[0]))
        return;
#endif
    t_lock_cpu();
    ghs_hook4(THG_SYS, 0, code);
    t_unlock_cpu();
}

void sys_hook1(int grp, int code, int p1)
{
    ID tskid = TSKID(runtsk);
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (tskid > TRACE_TNUM_TSKID || !(Ros_buf.hook.task_id[tskid]))
	return;
#endif
    t_lock_cpu();
    ghs_hook5(THG_SYS, tskid, code, p1);
    t_unlock_cpu();
}

void sys_hook1_i(int grp, int code, int p1)
{
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (!(Ros_buf.hook.task_id[0]))
        return;
#endif
    t_lock_cpu();
    ghs_hook5(THG_SYS, 0, code, p1);
    t_unlock_cpu();
}

void sys_hook2(int grp, int code, int p1, int p2)
{
    ID tskid = TSKID(runtsk);
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (tskid > TRACE_TNUM_TSKID || !(Ros_buf.hook.task_id[tskid]))
        return;
#endif
    t_lock_cpu();
    ghs_hook6(THG_SYS, tskid, code, p1, p2);
    t_unlock_cpu();
}

void sys_hook2_i(int grp, int code, int p1, int p2)
{
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (!(Ros_buf.hook.task_id[0]))
        return;
#endif
    t_lock_cpu();
    ghs_hook6(THG_SYS, 0, code, p1, p2);
    t_unlock_cpu();
}

void sys_hook3(int grp, int code, int p1, int p2, int p3)
{
    ID tskid = TSKID(runtsk);
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (!(Ros_buf.hook.task_id[tskid & (TRACE_TNUM_TSKID-1)]))
        return;
#endif
    t_lock_cpu();
    ghs_hook7(THG_SYS, tskid, code, p1, p2, p3);
    t_unlock_cpu();
}

void sys_hook4(int grp, int code, int p1, int p2, int p3, int p4)
{
    ID tskid = TSKID(runtsk);
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (tskid > TRACE_TNUM_TSKID || !(Ros_buf.hook.task_id[tskid]))
        return;
#endif
    t_lock_cpu();
    ghs_hook8(THG_SYS, tskid, code, p1, p2, p3, p4);
    t_unlock_cpu();
}


void trc_rtn_hook(int grp, int code, int ercd)
{
    ID	tskid = TSKID(runtsk);
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_RET))
        return;
    if (!(Ros_buf.hook.trc_grp & THG_SYS) || !(Ros_buf.hook.sys_grp & grp))
        return;
    if (tskid > TRACE_TNUM_TSKID || !(Ros_buf.hook.task_id[tskid]))
	return;
#endif
    t_lock_cpu();
    ghs_hook5(THG_RET, tskid, code, ercd);
    t_unlock_cpu();
}

/*CPU���b�N��ԂŌĂ΂�邽�߁ACPU�����b�N����K�v�͂Ȃ�*/
void sts_hook(ID tskid)
{
	TCB	*tcb;
	int tstat;
#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_STS))
        return;
    if (tskid > TRACE_TNUM_TSKID || !(Ros_buf.hook.task_id[tskid]))
        return;
#endif
    tcb = get_tcb(tskid);
	tstat = (int)(tcb->tstat);
	if(TSTAT_DORMANT(tstat)) tstat = 0x1;	/* 0x1:Dormant */
	else if(TSTAT_RUNNABLE(tstat)) tstat = 0x0;	/* 0x0:Ready */
	else if(TSTAT_WAITING(tstat)) {
		if((tstat & (TS_WAIT_SLEEP | TS_WAIT_WOBJ)) == 0) tstat = 0x09;  /* 0x9:Delay */
		else {
			if((tstat & TS_WAIT_SLEEP) != 0) tstat = 0x08;  /* 0x8:Sleep */
			else tstat = 0x0a;  /* 0xa:Waiting */
		}
	if(TSTAT_SUSPENDED(tstat)) tstat |= 0x10;
	}
	else if(TSTAT_SUSPENDED(tstat)) tstat = 0x10;
	ghs_hook4(THG_STS, tskid, tstat);
}

void dispatch_hook(TCB	*tcb)
{
    ID tskid;

#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_DSP))
        return;
#endif
    tskid = runtsk == NULL ? 0 : TSKID(runtsk);
    t_lock_cpu();
    ghs_hook4(THG_DSP, tskid, TSKID(tcb));
}

void exception_hook(int code, int addr)
{
    int i;
    ID tskid;

#if(GHS_HOOK != 1)
    if (!(Ros_buf.hook.trc_grp & THG_INT))
        return;
#endif
    for(i = 0; i < TRACE_TNUM_EVT; i++){
        if(Ros_buf.hook.evtcode[i] == 0) return;
        if(Ros_buf.hook.evtcode[i] == code){
            tskid = runtsk == NULL ? 0 : TSKID(runtsk);
            ghs_hook5(THG_INT, tskid, code, addr);
            return;
        }
    }
}
#endif

