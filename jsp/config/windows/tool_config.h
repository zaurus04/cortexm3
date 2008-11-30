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
 *  @(#) $Id: tool_config.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�J�����ˑ����W���[��
 */

#ifndef _TOOL_CONFIG_H_
#define _TOOL_CONFIG_H_

#include <s_services.h>
#include <kernel_debug.h>

/*
 *  �J�����ˑ��̏������͎g�p���Ȃ�
 */
#define tool_initialize()

/*
 *  __EMPTY_LABEL�}�N���̒�`
 */
#if defined(_MSC_VER) || defined(__BORLANDC__)
  #define __EMPTY_LABEL(x,y) _declspec(naked) void y(void){}
#endif

#ifndef _MACRO_ONLY
#ifdef EVENTLOG_ENABLE
#ifdef __cplusplus
    extern "C" void event_write(unsigned int logtype, unsigned int valid, UINT bufsz, ... );
    extern "C" void event_write_svc_enter(int fncd, unsigned int params, ... );
    extern "C" void event_write_svc_leave(int fncd, unsigned int ercd);
    extern "C" void event_write_tskstat(void * tcb);
    extern "C" void event_write_comment(const char *, ... );
#else
    extern void event_write(unsigned int logtype, unsigned int valid, UINT bufsz, ... );
    extern void event_write_svc_enter(int fncd, unsigned int params, ... );
    extern void event_write_svc_leave(int fncd, unsigned int ercd, unsigned int retaddr);
    extern void event_write_tskstat(void * tcb);
    extern void event_write_comment(const char *, ... );
#endif

        /*
         *   �߂�Ԓn�擾�}�N��
         */
#if defined(_MSC_VER)
#define GET_RETURNADDRESS(x) __asm { mov eax, dword ptr [ebp + 4] } __asm { mov dword ptr [x], eax }
#elif defined(__GNUC__)
#define GET_RETURNADDRESS(x) { x = 0; }
#elif
#define GET_RETURNADDRESS(x) { x = 0: }
#endif

#define LOG_SVC_ENTER(x)      { DWORD address; GET_RETURNADDRESS(address); event_write_svc_enter x; }
#define LOG_SVC_LEAVE(x)      { DWORD address; GET_RETURNADDRESS(address); event_write_svc_leave x; }
#define LOG_EVENT(x)          { event_write x; }
#define LOG_EVENT_TSKSTAT(x)  { event_write_tskstat x; }

#endif   /* EVENTLOGG_ENABLED */
#endif  /* _MACRO_ONLY */


	/* ���O���g�p�ł��Ȃ��ꍇ */
#ifndef LOG_EVENT
#define LOG_SVC_ENTER(x)
#define LOG_SVC_LEAVE(x)
#define LOG_EVENT(x)
#define LOG_EVENT_TSKSTAT(x)
#endif


/*
 *  �g���[�X���O�̐ݒ�
 */

#define	LOG_INH_ENTER(inhno)	    LOG_EVENT((LOG_TYPE_INH|LOG_ENTER, 0x1, sizeof(int), (int)(inhno)));
#define	LOG_INH_LEAVE(inhno)	    LOG_EVENT((LOG_TYPE_INH|LOG_LEAVE, 0x1, sizeof(int), (int)(inhno)));

#define	LOG_ISR_ENTER(intno)
#define	LOG_ISR_LEAVE(intno)

#define	LOG_CYC_ENTER(cyccb)	    LOG_EVENT((LOG_TYPE_CYC|LOG_ENTER, 0x7, sizeof(int)*3, OBJ_CYCLICHANDLER,(int)((cyccb) - cyccb_table)+1,(unsigned int)(cyccb)->cycinib->exinf));
#define	LOG_CYC_LEAVE(cyccb)	    LOG_EVENT((LOG_TYPE_CYC|LOG_LEAVE, 0x7, sizeof(int)*3, OBJ_CYCLICHANDLER,(int)((cyccb) - cyccb_table)+1,(unsigned int)(cyccb)->cycinib->exinf));

#define	LOG_EXC_ENTER(excno)	    LOG_EVENT((LOG_TYPE_EXC|LOG_ENTER, 0x1, sizeof(int), (int)(excno)));
#define	LOG_EXC_LEAVE(excno)	    LOG_EVENT((LOG_TYPE_EXC|LOG_LEAVE, 0x1, sizeof(int), (int)(excno)));

#define	LOG_TEX_ENTER(texptn)	    LOG_EVENT((LOG_TYPE_TEX|LOG_ENTER, 0x3, sizeof(int)*2, (int)TSKID(runtsk), (int)(texptn)));
#define	LOG_TEX_LEAVE(texptn)	    LOG_EVENT((LOG_TYPE_TEX|LOG_LEAVE, 0x3, sizeof(int)*2, (int)TSKID(runtsk), (int)(texptn)));

#define	LOG_TSKSTAT(tcb)	        LOG_EVENT_TSKSTAT((tcb));

#define	LOG_DSP_ENTER_INT(tcb)		LOG_EVENT((LOG_TYPE_DSP|LOG_ENTER, 0x1, sizeof(int)*2, TSKID(tcb),1));
#define	LOG_DSP_ENTER_TSK(tcb)		LOG_EVENT((LOG_TYPE_DSP|LOG_ENTER, 0x1, sizeof(int)*2, TSKID(tcb),0));
#define	LOG_DSP_LEAVE(tcb)		    LOG_EVENT((LOG_TYPE_DSP|LOG_LEAVE, 0x1, sizeof(int), TSKID(tcb)));

#define	LOG_ACT_TSK_ENTER(tskid)	LOG_SVC_ENTER((TFN_ACT_TSK, 1, tskid, address))
#define	LOG_ACT_TSK_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_ACT_TSK, ercd, address))
#define	LOG_IACT_TSK_ENTER(tskid)	LOG_SVC_ENTER((TFN_IACT_TSK, 1, tskid, address))
#define	LOG_IACT_TSK_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_IACT_TSK, ercd, address))
#define	LOG_CAN_ACT_ENTER(tskid)	LOG_SVC_ENTER((TFN_CAN_ACT, 1, tskid, address))
#define	LOG_CAN_ACT_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_CAN_ACT, ercd, address))
#define	LOG_EXT_TSK_ENTER()			LOG_SVC_ENTER((TFN_EXT_TSK, 0, address))
#define	LOG_TER_TSK_ENTER(tskid)	LOG_SVC_ENTER((TFN_TER_TSK, 1, tskid, address))
#define	LOG_TER_TSK_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_TER_TSK, ercd, address))
#define	LOG_CHG_PRI_ENTER(tskid, tskpri)	LOG_SVC_ENTER((TFN_CHG_PRI, 2, tskid, tskpri, address))
#define	LOG_CHG_PRI_LEAVE(ercd)				LOG_SVC_LEAVE((TFN_CHG_PRI, ercd, address))
#define	LOG_GET_PRI_ENTER(tskid, p_tskpri)	LOG_SVC_ENTER((TFN_GET_PRI, 2, tskid, p_tskpri, address))
#define	LOG_GET_PRI_LEAVE(ercd, tskpri)		LOG_SVC_LEAVE((TFN_GET_PRI, ercd, address))
#define	LOG_SLP_TSK_ENTER()			LOG_SVC_ENTER((TFN_SLP_TSK, 0, address))
#define	LOG_SLP_TSK_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_SLP_TSK, ercd, address))
#define	LOG_TSLP_TSK_ENTER(tmout)	LOG_SVC_ENTER((TFN_TSLP_TSK, 1, tmout, address))
#define	LOG_TSLP_TSK_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_TSLP_TSK, ercd, address))
#define	LOG_WUP_TSK_ENTER(tskid)	LOG_SVC_ENTER((TFN_WUP_TSK, 1, tskid, address))
#define	LOG_WUP_TSK_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_WUP_TSK, ercd, address))
#define	LOG_IWUP_TSK_ENTER(tskid)	LOG_SVC_ENTER((TFN_IWUP_TSK, 1, tskid, address))
#define	LOG_IWUP_TSK_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_IWUP_TSK, ercd, address))
#define	LOG_CAN_WUP_ENTER(tskid)	LOG_SVC_ENTER((TFN_CAN_WUP, 1, tskid, address))
#define	LOG_CAN_WUP_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_CAN_WUP, ercd, address))
#define	LOG_REL_WAI_ENTER(tskid)	LOG_SVC_ENTER((TFN_REL_WAI, 1, tskid, address))
#define	LOG_REL_WAI_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_REL_WAI, ercd, address))
#define	LOG_IREL_WAI_ENTER(tskid)	LOG_SVC_ENTER((TFN_IREL_WAI, 1, tskid, address))
#define	LOG_IREL_WAI_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_IREL_WAI, ercd, address))
#define	LOG_SUS_TSK_ENTER(tskid)	LOG_SVC_ENTER((TFN_SUS_TSK, 1, tskid, address))
#define	LOG_SUS_TSK_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_SUS_TSK, ercd, address))
#define	LOG_RSM_TSK_ENTER(tskid)	LOG_SVC_ENTER((TFN_RSM_TSK, 1, tskid, address))
#define	LOG_RSM_TSK_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_RSM_TSK, ercd, address))
#define	LOG_FRSM_TSK_ENTER(tskid)	LOG_SVC_ENTER((TFN_FRSM_TSK, 1, tskid, address))
#define	LOG_FRSM_TSK_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_FRSM_TSK, ercd, address))
#define	LOG_DLY_TSK_ENTER(dlytim)	LOG_SVC_ENTER((TFN_DLY_TSK, 1, dlytim, address))
#define	LOG_DLY_TSK_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_DLY_TSK, ercd, address))
#define	LOG_RAS_TEX_ENTER(tskid, rasptn)	LOG_SVC_ENTER((TFN_RAS_TEX, 2, tskid, rasptn, address))
#define	LOG_RAS_TEX_LEAVE(ercd)				LOG_SVC_LEAVE((TFN_RAS_TEX, ercd, address))
#define	LOG_IRAS_TEX_ENTER(tskid, rasptn)	LOG_SVC_ENTER((TFN_IRAS_TEX, 2, tskid, rasptn, address))
#define	LOG_IRAS_TEX_LEAVE(ercd)			LOG_SVC_LEAVE((TFN_IRAS_TEX, ercd, address))
#define	LOG_DIS_TEX_ENTER()			LOG_SVC_ENTER((TFN_DIS_TEX, 0, address))
#define	LOG_DIS_TEX_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_DIS_TEX, ercd, address))
#define	LOG_ENA_TEX_ENTER()			LOG_SVC_ENTER((TFN_ENA_TEX, 0, address))
#define	LOG_ENA_TEX_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_ENA_TEX, ercd, address))
#define	LOG_SNS_TEX_ENTER()			LOG_SVC_ENTER((TFN_SNS_TEX, 0, address))
#define	LOG_SNS_TEX_LEAVE(state)	LOG_SVC_LEAVE((TFN_SNS_TEX, state, address))
#define	LOG_SIG_SEM_ENTER(semid)	LOG_SVC_ENTER((TFN_SIG_SEM, 1, semid, address))
#define	LOG_SIG_SEM_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_SIG_SEM, ercd, address))
#define	LOG_ISIG_SEM_ENTER(semid)	LOG_SVC_ENTER((TFN_ISIG_SEM, 1, semid, address))
#define	LOG_ISIG_SEM_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_ISIG_SEM, ercd, address))
#define	LOG_WAI_SEM_ENTER(semid)	LOG_SVC_ENTER((TFN_WAI_SEM, 1, semid, address))
#define	LOG_WAI_SEM_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_WAI_SEM, ercd, address))
#define	LOG_POL_SEM_ENTER(semid)	LOG_SVC_ENTER((TFN_POL_SEM, 1, semid, address))
#define	LOG_POL_SEM_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_POL_SEM, ercd, address))
#define	LOG_TWAI_SEM_ENTER(semid, tmout)	LOG_SVC_ENTER((TFN_TWAI_SEM, 2, semid, tmout, address))
#define	LOG_TWAI_SEM_LEAVE(ercd)			LOG_SVC_LEAVE((TFN_TWAI_SEM, ercd, address))
#define	LOG_SET_FLG_ENTER(flgid, setptn)	LOG_SVC_ENTER((TFN_SET_FLG, 2, flgid, setptn, address))
#define	LOG_SET_FLG_LEAVE(ercd)				LOG_SVC_LEAVE((TFN_SET_FLG, ercd, address))
#define	LOG_ISET_FLG_ENTER(flgid, setptn)	LOG_SVC_ENTER((TFN_ISET_FLG, 2, flgid, setptn, address))
#define	LOG_ISET_FLG_LEAVE(ercd)			LOG_SVC_LEAVE((TFN_ISET_FLG, ercd, address))
#define	LOG_CLR_FLG_ENTER(flgid, clrptn)	LOG_SVC_ENTER((TFN_CLR_FLG, 2, flgid, clrptn, address))
#define	LOG_CLR_FLG_LEAVE(ercd)				LOG_SVC_LEAVE((TFN_CLR_FLG, ercd, address))
#define	LOG_WAI_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn)	LOG_SVC_ENTER((TFN_WAI_FLG, 4, flgid, waiptn, wfmode, p_flgptn, address))
#define	LOG_WAI_FLG_LEAVE(ercd, flgptn)						LOG_SVC_LEAVE((TFN_WAI_FLG, ercd, address))
#define	LOG_POL_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn)	LOG_SVC_ENTER((TFN_POL_FLG, 4, flgid, waiptn, wfmode, p_flgptn, address))
#define	LOG_POL_FLG_LEAVE(ercd, flgptn)						LOG_SVC_LEAVE((TFN_POL_FLG, ercd, address))
#define	LOG_TWAI_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn, tmout)	LOG_SVC_ENTER((TFN_TWAI_FLG, 5, flgid, waiptn, wfmode, p_flgptn, tmout, address))
#define	LOG_TWAI_FLG_LEAVE(ercd, flgptn)							LOG_SVC_LEAVE((TFN_TWAI_FLG, ercd, address))
#define	LOG_SND_DTQ_ENTER(dtqid, data)	LOG_SVC_ENTER((TFN_SND_DTQ, 2, dtqid, data, address))
#define	LOG_SND_DTQ_LEAVE(ercd)			LOG_SVC_LEAVE((TFN_SND_DTQ, ercd, address))
#define	LOG_PSND_DTQ_ENTER(dtqid, data)	LOG_SVC_ENTER((TFN_PSND_DTQ, 2, dtqid, data, address))
#define	LOG_PSND_DTQ_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_PSND_DTQ, ercd, address))
#define	LOG_IPSND_DTQ_ENTER(dtqid, data)	LOG_SVC_ENTER((TFN_IPSND_DTQ, 2, dtqid, data, address))
#define	LOG_IPSND_DTQ_LEAVE(ercd)			LOG_SVC_LEAVE((TFN_IPSND_DTQ, ercd, address))
#define	LOG_TSND_DTQ_ENTER(dtqid, data, tmout)	LOG_SVC_ENTER((TFN_TSND_DTQ, 3, dtqid, data, tmout, address))
#define	LOG_TSND_DTQ_LEAVE(ercd)				LOG_SVC_LEAVE((TFN_TSND_DTQ, ercd, address))
#define	LOG_FSND_DTQ_ENTER(dtqid, data)	LOG_SVC_ENTER((TFN_FSND_DTQ, 2, dtqid, data, address))
#define	LOG_FSND_DTQ_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_FSND_DTQ, ercd, address))
#define	LOG_IFSND_DTQ_ENTER(dtqid, data)	LOG_SVC_ENTER((TFN_IFSND_DTQ, 2, dtqid, data, address))
#define	LOG_IFSND_DTQ_LEAVE(ercd)			LOG_SVC_LEAVE((TFN_IFSND_DTQ, ercd, address))
#define	LOG_RCV_DTQ_ENTER(dtqid, p_data)	LOG_SVC_ENTER((TFN_RCV_DTQ, 2, dtqid, p_data, address))
#define	LOG_RCV_DTQ_LEAVE(ercd, data)		LOG_SVC_LEAVE((TFN_RCV_DTQ, ercd, address))
#define	LOG_PRCV_DTQ_ENTER(dtqid, p_data)	LOG_SVC_ENTER((TFN_PRCV_DTQ, 2, dtqid, p_data, address))
#define	LOG_PRCV_DTQ_LEAVE(ercd, data)		LOG_SVC_LEAVE((TFN_PRCV_DTQ, ercd, address))
#define	LOG_TRCV_DTQ_ENTER(dtqid, p_data, tmout)	LOG_SVC_ENTER((TFN_TRCV_DTQ, 3, dtqid, p_data, tmout, address))
#define	LOG_TRCV_DTQ_LEAVE(ercd, data)				LOG_SVC_LEAVE((TFN_TRCV_DTQ, ercd, address))
#define	LOG_SND_MBX_ENTER(mbxid, pk_msg)	LOG_SVC_ENTER((TFN_SND_MBX, 2, mbxid, pk_msg, address))
#define	LOG_SND_MBX_LEAVE(ercd)				LOG_SVC_LEAVE((TFN_SND_MBX, ercd, address))
#define	LOG_RCV_MBX_ENTER(mbxid, ppk_msg)	LOG_SVC_ENTER((TFN_RCV_MBX, 2, mbxid, ppk_msg, address))
#define	LOG_RCV_MBX_LEAVE(ercd, pk_msg)		LOG_SVC_LEAVE((TFN_RCV_MBX, ercd, address))
#define	LOG_PRCV_MBX_ENTER(mbxid, ppk_msg)	LOG_SVC_ENTER((TFN_PRCV_MBX, 2, mbxid, ppk_msg, address))
#define	LOG_PRCV_MBX_LEAVE(ercd, pk_msg)	LOG_SVC_LEAVE((TFN_PRCV_MBX, ercd, address))
#define	LOG_TRCV_MBX_ENTER(mbxid, ppk_msg, tmout)	LOG_SVC_ENTER((TFN_TRCV_MBX, 3, mbxid, ppk_msg, tmout, address))
#define	LOG_TRCV_MBX_LEAVE(ercd, pk_msg)			LOG_SVC_LEAVE((TFN_TRCV_MBX, ercd, address))
#define	LOG_GET_MPF_ENTER(mpfid, p_blk)	LOG_SVC_ENTER((TFN_GET_MPF, 2, mpfid, p_blk, address))
#define	LOG_GET_MPF_LEAVE(ercd, blk)	LOG_SVC_LEAVE((TFN_GET_MPF, ercd, address))
#define	LOG_PGET_MPF_ENTER(mpfid, p_blk)	LOG_SVC_ENTER((TFN_PGET_MPF, 2, mpfid, p_blk, address))
#define	LOG_PGET_MPF_LEAVE(ercd, blk)		LOG_SVC_LEAVE((TFN_PGET_MPF, ercd, address))
#define	LOG_TGET_MPF_ENTER(mpfid, p_blk, tmout)	LOG_SVC_ENTER((TFN_TGET_MPF, 3, mpfid, p_blk, tmout, address))
#define	LOG_TGET_MPF_LEAVE(ercd, blk)			LOG_SVC_LEAVE((TFN_TGET_MPF, ercd, address))
#define	LOG_REL_MPF_ENTER(mpfid, blk)	LOG_SVC_ENTER((TFN_REL_MPF, 2, mpfid, blk, address))
#define	LOG_REL_MPF_LEAVE(ercd)			LOG_SVC_LEAVE((TFN_REL_MPF, ercd, address))
#define	LOG_SET_TIM_ENTER(p_systim)	LOG_SVC_ENTER((TFN_SET_TIM, 1, p_systim, address))
#define	LOG_SET_TIM_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_SET_TIM, ercd, address))
#define	LOG_GET_TIM_ENTER(p_systim)		LOG_SVC_ENTER((TFN_GET_TIM, 1, p_systim, address))
#define	LOG_GET_TIM_LEAVE(ercd, systim)	LOG_SVC_LEAVE((TFN_GET_TIM, ercd, address))
#define	LOG_ISIG_TIM_ENTER()	LOG_SVC_ENTER((TFN_ISIG_TIM, 0, address))
#define	LOG_ISIG_TIM_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_ISIG_TIM, ercd, address))
#define	LOG_STA_CYC_ENTER(cycid)	LOG_SVC_ENTER((TFN_STA_CYC, 1, cycid, address))
#define	LOG_STA_CYC_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_STA_CYC, ercd, address))
#define	LOG_STP_CYC_ENTER(cycid)	LOG_SVC_ENTER((TFN_STP_CYC, 1, cycid, address))
#define	LOG_STP_CYC_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_STP_CYC, ercd, address))
#define	LOG_ROT_RDQ_ENTER(tskpri)	LOG_SVC_ENTER((TFN_ROT_RDQ, 1, tskpri, address))
#define	LOG_ROT_RDQ_LEAVE(ercd)		LOG_SVC_LEAVE((TFN_ROT_RDQ, ercd, address))
#define	LOG_IROT_RDQ_ENTER(tskpri)	LOG_SVC_ENTER((TFN_IROT_RDQ, 1, tskpri, address))
#define	LOG_IROT_RDQ_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_IROT_RDQ, ercd, address))
#define	LOG_GET_TID_ENTER(p_tskid)	LOG_SVC_ENTER((TFN_GET_TID, 1, p_tskid, address))
#define	LOG_GET_TID_LEAVE(ercd, tskid)	LOG_SVC_LEAVE((TFN_GET_TID, ercd, address))
#define	LOG_IGET_TID_ENTER(p_tskid)	LOG_SVC_ENTER((TFN_IGET_TID, 1, p_tskid, address))
#define	LOG_IGET_TID_LEAVE(ercd, tskid)	LOG_SVC_LEAVE((TFN_IGET_TID, ercd, address))

#define	LOG_LOC_CPU_ENTER()	        LOG_SVC_ENTER((TFN_LOC_CPU, 0, address))
#define	LOG_LOC_CPU_LEAVE(ercd)	    LOG_SVC_LEAVE((TFN_LOC_CPU, ercd, address))
#define	LOG_ILOC_CPU_ENTER()		LOG_SVC_ENTER((TFN_ILOC_CPU, 0, address))
#define	LOG_ILOC_CPU_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_ILOC_CPU, ercd, address))
#define	LOG_UNL_CPU_ENTER()		    LOG_SVC_ENTER((TFN_UNL_CPU, 0, address))
#define	LOG_UNL_CPU_LEAVE(ercd)	    LOG_SVC_LEAVE((TFN_UNL_CPU, ercd, address))
#define	LOG_IUNL_CPU_ENTER()		LOG_SVC_ENTER((TFN_IUNL_CPU, 0, address))
#define	LOG_IUNL_CPU_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_IUNL_CPU, ercd, address))

#define	LOG_DIS_DSP_ENTER()		LOG_SVC_ENTER((TFN_DIS_DSP, 0, address))
#define	LOG_DIS_DSP_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_DIS_DSP, ercd, address))
#define	LOG_ENA_DSP_ENTER()		LOG_SVC_ENTER((TFN_ENA_DSP, 0, address))
#define	LOG_ENA_DSP_LEAVE(ercd)	LOG_SVC_LEAVE((TFN_ENA_DSP, ercd, address))

#define	LOG_SNS_CTX_ENTER()			LOG_SVC_ENTER((TFN_SNS_CTX, 0, address))
#define	LOG_SNS_CTX_LEAVE(state)	LOG_SVC_LEAVE((TFN_SNS_CTX, state, address))
#define	LOG_SNS_LOC_ENTER()			LOG_SVC_ENTER((TFN_SNS_LOC, 0, address))
#define	LOG_SNS_LOC_LEAVE(state)	LOG_SVC_LEAVE((TFN_SNS_LOC, state, address))
#define	LOG_SNS_DSP_ENTER()			LOG_SVC_ENTER((TFN_SNS_DSP, 0, address))
#define	LOG_SNS_DSP_LEAVE(state)	LOG_SVC_LEAVE((TFN_SNS_DSP, state, address))
#define	LOG_SNS_DPN_ENTER()			LOG_SVC_ENTER((TFN_SNS_DPN, 0, address))
#define	LOG_SNS_DPN_LEAVE(state)	LOG_SVC_LEAVE((TFN_SNS_DPN, state, address))

#define	LOG_VSNS_INI_ENTER()        LOG_SVC_ENTER((TFN_VSNS_INI, 0, address))
#define	LOG_VSNS_INI_LEAVE(state)   LOG_SVC_LEAVE((TFN_VSNS_INI, state, address))

#define	LOG_VXSNS_CTX_ENTER(p_excinf)	    LOG_SVC_ENTER((TFN_VXSNS_CTX, 1, p_excinf, address))
#define	LOG_VXSNS_CTX_LEAVE(state)		    LOG_SVC_LEAVE((TFN_VXSNS_CTX, state, address))
#define	LOG_VXSNS_LOC_ENTER(p_excinf)	    LOG_SVC_ENTER((TFN_VXSNS_LOC, 1, p_excinf, address))
#define	LOG_VXSNS_LOC_LEAVE(state)		    LOG_SVC_LEAVE((TFN_VXSNS_LOC, state, address))
#define	LOG_VXSNS_DSP_ENTER(p_excinf)	    LOG_SVC_ENTER((TFN_VXSNS_DSP, 1, p_excinf, address))
#define	LOG_VXSNS_DSP_LEAVE(state)		    LOG_SVC_LEAVE((TFN_VXSNS_DSP, state, address))
#define	LOG_VXSNS_DPN_ENTER(p_excinf)	    LOG_SVC_ENTER((TFN_VXSNS_DPN, 1, p_excinf, address))
#define	LOG_VXSNS_DPN_LEAVE(state)		    LOG_SVC_LEAVE((TFN_VXSNS_DPN, state, address))
#define	LOG_VXSNS_TEX_ENTER(p_excinf)	    LOG_SVC_ENTER((TFN_VXSNS_TEX, 1, p_excinf, address))
#define	LOG_VXSNS_TEX_LEAVE(state)		    LOG_SVC_LEAVE((TFN_VXSNS_TEX, state, address))
#define	LOG_VXGET_TIM_ENTER(p_sysutim)		LOG_SVC_ENTER((TFN_VXGET_TIM, 1, p_sysutim, address))
#define	LOG_VXGET_TIM_LEAVE(ercd, sysutim)	LOG_SVC_LEAVE((TFN_VXGET_TIM, ercd, address))

#define	LOG_CHG_IPM_ENTER(ipm)	        LOG_SVC_ENTER((TFN_CHG_IPM, 1, ipm, address))
#define	LOG_CHG_IPM_LEAVE(ercd)	        LOG_SVC_LEAVE((TFN_CHG_IPM, ercd, address))
#define	LOG_GET_IPM_ENTER(p_ipm)		LOG_SVC_ENTER((TFN_GET_IPM, 1, p_ipm, address))
#define	LOG_GET_IPM_LEAVE(ercd, ipm)	LOG_SVC_LEAVE((TFN_GET_IPM, ercd, address))
#define	LOG_ENA_INT_ENTER()		        LOG_SVC_ENTER((TFN_ENA_INT, 0, address))
#define	LOG_ENA_INT_LEAVE(ercd)	        LOG_SVC_LEAVE((TFN_ENA_INT, ercd, address))
#define	LOG_DIS_INT_ENTER()		        LOG_SVC_ENTER((TFN_DIS_INT, 0, address))
#define	LOG_DIS_INT_LEAVE(ercd)	        LOG_SVC_LEAVE((TFN_DIS_INT, ercd, address))


#endif /* _TOOL_CONFIG_H_ */
