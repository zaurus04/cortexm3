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
 *  @(#) $Id: ghs_hook.h,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

#ifdef GHS_HOOK
#include "hook.h"

#define TRACE_TNUM_TSKID 16
#define TRACE_TNUM_EVT 16

#ifndef BUFF_SIZE
#define BUFF_SIZE   0x4000	/* 0x400 | 0x800 | 0x1000 | 0x2000 | 0x4000 */
#endif

/* tskstat */

#define S_DMT       0x00    /* DORMANT */
#define S_RDY       0x10    /* RUN,READY */
#define S_SLP       0x20    /* wait due to slp_tsk or tslp_tsk */
#define S_DLY       0x30    /* wait due to dly_tsk */
#define S_RDV       0x40    /* wait for rendezvous completion */
#define S_FLG       0x50    /* wait due to wai_flg or twai_flg */
#define S_SMB       0x60    /* wait due to snd_mbf or tsnd_mbf */
#define S_CAL       0x70    /* wait for rendezvous call */
#define S_ACP       0x80    /* wait for rendezvous accept */
#define S_SEM       0x90    /* wait due to wai_sem or twai_sem */
#define S_MBX       0xa0    /* wait due to rcv_msg or trcv_msg */
#define S_MBF       0xb0    /* wait due to rcv_mbf or trcv_mbf */
#define S_MPL       0xc0    /* wait due to get_blk or tget_blk */
#define S_MPF       0xd0    /* wait due to get_blf or tget_blf */

typedef struct
{
	short max_tid;
    unsigned short trc_grp;
    unsigned short sys_grp;
    short tnum_tskid;
    short tnum_evt;
    unsigned char task_id[TRACE_TNUM_TSKID];
    unsigned char evtcode[TRACE_TNUM_EVT];
} T_HOOK;

typedef struct
{   char bigendian;
    char dummy;
    unsigned short size;
    unsigned short putp;
    unsigned short getp;
} T_TRACE;

typedef struct
{
    T_TRACE trace;
    T_HOOK hook;
    long syscall[BUFF_SIZE];
} T_ROS;

extern T_ROS Ros_buf;

void ghs_hook4(int sts, int p1, int p2);
void ghs_hook5(int sts, int p1, int p2, int p3);
void ghs_hook6(int sts, int p1, int p2, int p3, int p4);
void ghs_hook7(int sts, int p1, int p2, int p3, int p4, int p5);
void ghs_hook8(int sts, int p1, int p2, int p3, int p4, int p5, int p6);
void ghs_hook9(int sts, int p1, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

