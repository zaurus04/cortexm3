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
 *  @(#) $Id: eventlog.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


#include <s_services.h>

#ifdef EVENTLOG_ENABLE

#include "jsp_kernel.h"
#include "task.h"
#include "semaphore.h"
#include "dataqueue.h"
#include "eventflag.h"
#include "mempfix.h"
#include "mailbox.h"

//#include <kernel_debug.h>

extern SEMCB 	semcb_table[1];
extern UINT		tmax_semid;
extern FLGCB	flgcb_table[1];
extern UINT		tmax_flgid;
extern DTQCB 	dtqcb_table[1];
extern UINT		tmax_dtqid;
extern MBXCB 	mbxcb_table[1];
extern UINT		tmax_mbxid;
extern MPFCB 	mpfcb_table[1];
extern UINT		tmax_mpfid;

/*
 *  �C�x���g���O�o�͗p �^�X�N��Ԏ擾�֐�
 *    (com_support.c��C++�ɂȂ�̂ŁA�����ɒu��)
 */

Inline BOOL is_inside_of(void * src, void * min, void * sup)
{	return ((long)src >= (long)min) && ((long)src <  (long)sup);	}

static void decode_waitstatus(TCB * tcb, unsigned int * objtype, int * objid)
{
	QUEUE * queue;

	if((tcb->tstat & TS_WAIT_SLEEP) != 0)
	{
		*objtype = TTW_SLP;
	}else
	{
		if((tcb->tstat & TS_WAIT_WOBJCB) != 0)
		{
			do {
				queue = tcb->task_queue.next;
			} while( queue != &tcb->task_queue && is_inside_of(queue, tcb_table, &tcb_table[TNUM_TSK]) );

			if(queue == &tcb->task_queue)
				*objtype = 0;

				/* �Z�}�t�H */
			else if(is_inside_of(queue, semcb_table, &semcb_table[tmax_semid-1]))
			{
				*objtype = TTW_SEM;
				*objid   = ((long)queue - (long)semcb_table) / sizeof(SEMCB) + 1;
			}
				/* �C�x���g�t���O */
			else if(is_inside_of(queue, flgcb_table, &flgcb_table[tmax_flgid-1]))
			{
				*objtype = TTW_FLG;
				*objid   = ((long)queue - (long)flgcb_table) / sizeof(FLGCB) + 1;
			}
				/* �f�[�^�L���[ */
			else if(is_inside_of(queue, dtqcb_table, &dtqcb_table[tmax_dtqid-1]))
			{
				if(((long)queue % sizeof(DTQCB)) == (long)(&((DTQCB *)0)->rwait_queue))
					*objtype = TTW_RDTQ;
				else
					*objtype = TTW_SDTQ;
				*objid   = ((long)queue - (long)dtqcb_table) / sizeof(DTQCB) + 1;
			}
				/* ���[���{�b�N�X */
			else if(is_inside_of(queue, mbxcb_table, &mbxcb_table[tmax_mbxid-1]))
			{
				*objtype = TTW_MBX;
				*objid   = ((long)queue - (long)mbxcb_table) / sizeof(MBXCB) + 1;
			}
				/* �Œ蒷�������v�[�� */
			else if(is_inside_of(queue, mpfcb_table, &mpfcb_table[tmax_mpfid-1]))
			{
				*objtype = TTW_MPL;
				*objid   = ((long)queue - (long)mpfcb_table) / sizeof(MPFCB) + 1;
			}
		}else
		{
				/* slp_tsk�ł͂Ȃ��A�I�u�W�F�N�g�҂��L���[�ɂȂ���Ă��Ȃ��^�C���A�E�g�t���̑҂� -> dly_tsk */
			if(tcb->winfo->tmevtb != NULL)
				*objtype = TTW_DLY;
		}
	}
}

void decode_taskstatus(TCB * tcb, int * tskid, unsigned int * tskstat, unsigned int * objtype, int * objid)
{
	int stat = tcb->tstat;

		/* �^�X�NID */
	*tskid = TSKID(tcb);

		/* �^�X�N��� */
	*tskstat = TTS_DMT;
	if((stat & TS_RUNNABLE) != 0)
	{
		*tskstat = TTS_RDY;
	}else
	{
		if((stat & TS_WAITING) != 0)
		{
				/* �҂����̃f�R�[�h */
			decode_waitstatus((TCB *)tcb, objtype, objid);

			if((stat & TS_SUSPENDED) != 0)
				*tskstat = TTS_WAS;
			else
				*tskstat = TTS_WAI;
		}else
		{
			if((stat & TS_SUSPENDED) != 0)
				*tskstat = TTS_SUS;
		}
	}
}

#endif

