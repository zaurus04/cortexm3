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
 *  @(#) $Id: tool_config.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�J�����ˑ����W���[��
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _TOOL_CONFIG_H_
#define _TOOL_CONFIG_H_

/*
 *  ���x���̕ʖ����`���邽�߂̃}�N��
 */
#define	_LABEL_ALIAS(new_label, defined_label) \
	asm(".globl " #new_label "\n" #new_label " = " #defined_label);
#define LABEL_ALIAS(x, y) _LABEL_ALIAS(x, y)

/*
 *  �J�����ˑ��̏������͎g�p���Ȃ�
 */
#define tool_initialize()

/*
 *  atexit �̏����ƃf�X�g���N�^�̎��s
 */
#ifndef _MACRO_ONLY

Inline void
call_atexit()
{
	extern void	software_term_hook(void);
	volatile FP	fp = software_term_hook;

	/*
	 *  software_term_hook�ւ̃|�C���^���C��Uvolatile FP�^��fp��
	 *  ������Ă���g���̂́C0�Ƃ̔�r���œK���ō폜����Ȃ��悤
	 *  �ɂ��邽�߂ł���D
	 */
	if (fp != 0) {
		(*fp)();
	}
} 

#endif /* _MACRO_ONLY */

/*
 *  �g���[�X���O�̐ݒ�
 */

#define	LOG_INH_ENTER(inhno)		/* �v���Z�b�T�ˑ��� */
#define	LOG_INH_LEAVE(inhno)		/* �v���Z�b�T�ˑ��� */

#define	LOG_ISR_ENTER(intno)		/* �v���Z�b�T�ˑ��� */
#define	LOG_ISR_LEAVE(intno)		/* �v���Z�b�T�ˑ��� */

#define	LOG_CYC_ENTER(cyccb)
#define	LOG_CYC_LEAVE(cyccb)

#define	LOG_EXC_ENTER(excno)		/* �v���Z�b�T�ˑ��� */
#define	LOG_EXC_LEAVE(excno)		/* �v���Z�b�T�ˑ��� */

#define	LOG_TEX_ENTER(texptn)
#define	LOG_TEX_LEAVE(texptn)

#define	LOG_TSKSTAT(tcb)

#define	LOG_DSP_ENTER(tcb)		/* �v���Z�b�T�ˑ��� */
#define	LOG_DSP_LEAVE(tcb)		/* �v���Z�b�T�ˑ��� */

#define	LOG_ACT_TSK_ENTER(tskid)
#define	LOG_ACT_TSK_LEAVE(ercd)
#define	LOG_IACT_TSK_ENTER(tskid)
#define	LOG_IACT_TSK_LEAVE(ercd)
#define	LOG_CAN_ACT_ENTER(tskid)
#define	LOG_CAN_ACT_LEAVE(ercd)
#define	LOG_EXT_TSK_ENTER()
#define	LOG_TER_TSK_ENTER(tskid)
#define	LOG_TER_TSK_LEAVE(ercd)
#define	LOG_CHG_PRI_ENTER(tskid, tskpri)
#define	LOG_CHG_PRI_LEAVE(ercd)
#define	LOG_GET_PRI_ENTER(tskid, p_tskpri)
#define	LOG_GET_PRI_LEAVE(ercd, tskpri)
#define	LOG_SLP_TSK_ENTER()
#define	LOG_SLP_TSK_LEAVE(ercd)
#define	LOG_TSLP_TSK_ENTER(tmout)
#define	LOG_TSLP_TSK_LEAVE(ercd)
#define	LOG_WUP_TSK_ENTER(tskid)
#define	LOG_WUP_TSK_LEAVE(ercd)
#define	LOG_IWUP_TSK_ENTER(tskid)
#define	LOG_IWUP_TSK_LEAVE(ercd)
#define	LOG_CAN_WUP_ENTER(tskid)
#define	LOG_CAN_WUP_LEAVE(ercd)
#define	LOG_REL_WAI_ENTER(tskid)
#define	LOG_REL_WAI_LEAVE(ercd)
#define	LOG_IREL_WAI_ENTER(tskid)
#define	LOG_IREL_WAI_LEAVE(ercd)
#define	LOG_SUS_TSK_ENTER(tskid)
#define	LOG_SUS_TSK_LEAVE(ercd)
#define	LOG_RSM_TSK_ENTER(tskid)
#define	LOG_RSM_TSK_LEAVE(ercd)
#define	LOG_FRSM_TSK_ENTER(tskid)
#define	LOG_FRSM_TSK_LEAVE(ercd)
#define	LOG_DLY_TSK_ENTER(dlytim)
#define	LOG_DLY_TSK_LEAVE(ercd)
#define	LOG_RAS_TEX_ENTER(tskid, rasptn)
#define	LOG_RAS_TEX_LEAVE(ercd)
#define	LOG_IRAS_TEX_ENTER(tskid, rasptn)
#define	LOG_IRAS_TEX_LEAVE(ercd)
#define	LOG_DIS_TEX_ENTER()
#define	LOG_DIS_TEX_LEAVE(ercd)
#define	LOG_ENA_TEX_ENTER()
#define	LOG_ENA_TEX_LEAVE(ercd)
#define	LOG_SNS_TEX_ENTER()
#define	LOG_SNS_TEX_LEAVE(state)
#define	LOG_SIG_SEM_ENTER(semid)
#define	LOG_SIG_SEM_LEAVE(ercd)
#define	LOG_ISIG_SEM_ENTER(semid)
#define	LOG_ISIG_SEM_LEAVE(ercd)
#define	LOG_WAI_SEM_ENTER(semid)
#define	LOG_WAI_SEM_LEAVE(ercd)
#define	LOG_POL_SEM_ENTER(semid)
#define	LOG_POL_SEM_LEAVE(ercd)
#define	LOG_TWAI_SEM_ENTER(semid, tmout)
#define	LOG_TWAI_SEM_LEAVE(ercd)
#define	LOG_SET_FLG_ENTER(flgid, setptn)
#define	LOG_SET_FLG_LEAVE(ercd)
#define	LOG_ISET_FLG_ENTER(flgid, setptn)
#define	LOG_ISET_FLG_LEAVE(ercd)
#define	LOG_CLR_FLG_ENTER(flgid, clrptn)
#define	LOG_CLR_FLG_LEAVE(ercd)
#define	LOG_WAI_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn)
#define	LOG_WAI_FLG_LEAVE(ercd, flgptn)
#define	LOG_POL_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn)
#define	LOG_POL_FLG_LEAVE(ercd, flgptn)
#define	LOG_TWAI_FLG_ENTER(flgid, waiptn, wfmode, p_flgptn, tmout)
#define	LOG_TWAI_FLG_LEAVE(ercd, flgptn)
#define	LOG_SND_DTQ_ENTER(dtqid, data)
#define	LOG_SND_DTQ_LEAVE(ercd)
#define	LOG_PSND_DTQ_ENTER(dtqid, data)
#define	LOG_PSND_DTQ_LEAVE(ercd)
#define	LOG_IPSND_DTQ_ENTER(dtqid, data)
#define	LOG_IPSND_DTQ_LEAVE(ercd)
#define	LOG_TSND_DTQ_ENTER(dtqid, data, tmout)
#define	LOG_TSND_DTQ_LEAVE(ercd)
#define	LOG_FSND_DTQ_ENTER(dtqid, data)
#define	LOG_FSND_DTQ_LEAVE(ercd)
#define	LOG_IFSND_DTQ_ENTER(dtqid, data)
#define	LOG_IFSND_DTQ_LEAVE(ercd)
#define	LOG_RCV_DTQ_ENTER(dtqid, p_data)
#define	LOG_RCV_DTQ_LEAVE(ercd, data)
#define	LOG_PRCV_DTQ_ENTER(dtqid, p_data)
#define	LOG_PRCV_DTQ_LEAVE(ercd, data)
#define	LOG_TRCV_DTQ_ENTER(dtqid, p_data, tmout)
#define	LOG_TRCV_DTQ_LEAVE(ercd, data)
#define	LOG_SND_MBX_ENTER(mbxid, pk_msg)
#define	LOG_SND_MBX_LEAVE(ercd)
#define	LOG_RCV_MBX_ENTER(mbxid, ppk_msg)
#define	LOG_RCV_MBX_LEAVE(ercd, pk_msg)
#define	LOG_PRCV_MBX_ENTER(mbxid, ppk_msg)
#define	LOG_PRCV_MBX_LEAVE(ercd, pk_msg)
#define	LOG_TRCV_MBX_ENTER(mbxid, ppk_msg, tmout)
#define	LOG_TRCV_MBX_LEAVE(ercd, pk_msg)
#define	LOG_GET_MPF_ENTER(mpfid, p_blk)
#define	LOG_GET_MPF_LEAVE(ercd, blk)
#define	LOG_PGET_MPF_ENTER(mpfid, p_blk)
#define	LOG_PGET_MPF_LEAVE(ercd, blk)
#define	LOG_TGET_MPF_ENTER(mpfid, p_blk, tmout)
#define	LOG_TGET_MPF_LEAVE(ercd, blk)
#define	LOG_REL_MPF_ENTER(mpfid, blk)
#define	LOG_REL_MPF_LEAVE(ercd)
#define	LOG_SET_TIM_ENTER(p_systim)
#define	LOG_SET_TIM_LEAVE(ercd)
#define	LOG_GET_TIM_ENTER(p_systim)
#define	LOG_GET_TIM_LEAVE(ercd, systim)
#define	LOG_ISIG_TIM_ENTER()
#define	LOG_ISIG_TIM_LEAVE(ercd)
#define	LOG_STA_CYC_ENTER(cycid)
#define	LOG_STA_CYC_LEAVE(ercd)
#define	LOG_STP_CYC_ENTER(cycid)
#define	LOG_STP_CYC_LEAVE(ercd)
#define	LOG_ROT_RDQ_ENTER(tskpri)
#define	LOG_ROT_RDQ_LEAVE(ercd)
#define	LOG_IROT_RDQ_ENTER(tskpri)
#define	LOG_IROT_RDQ_LEAVE(ercd)
#define	LOG_GET_TID_ENTER(p_tskid)
#define	LOG_GET_TID_LEAVE(ercd, tskid)
#define	LOG_IGET_TID_ENTER(p_tskid)
#define	LOG_IGET_TID_LEAVE(ercd, tskid)
#define	LOG_LOC_CPU_ENTER()
#define	LOG_LOC_CPU_LEAVE(ercd)
#define	LOG_ILOC_CPU_ENTER()
#define	LOG_ILOC_CPU_LEAVE(ercd)
#define	LOG_UNL_CPU_ENTER()
#define	LOG_UNL_CPU_LEAVE(ercd)
#define	LOG_IUNL_CPU_ENTER()
#define	LOG_IUNL_CPU_LEAVE(ercd)
#define	LOG_DIS_DSP_ENTER()
#define	LOG_DIS_DSP_LEAVE(ercd)
#define	LOG_ENA_DSP_ENTER()
#define	LOG_ENA_DSP_LEAVE(ercd)
#define	LOG_SNS_CTX_ENTER()
#define	LOG_SNS_CTX_LEAVE(state)
#define	LOG_SNS_LOC_ENTER()
#define	LOG_SNS_LOC_LEAVE(state)
#define	LOG_SNS_DSP_ENTER()
#define	LOG_SNS_DSP_LEAVE(state)
#define	LOG_SNS_DPN_ENTER()
#define	LOG_SNS_DPN_LEAVE(state)
#define	LOG_VSNS_INI_ENTER()
#define	LOG_VSNS_INI_LEAVE(state)
#define	LOG_VXSNS_CTX_ENTER(p_excinf)
#define	LOG_VXSNS_CTX_LEAVE(state)
#define	LOG_VXSNS_LOC_ENTER(p_excinf)
#define	LOG_VXSNS_LOC_LEAVE(state)
#define	LOG_VXSNS_DSP_ENTER(p_excinf)
#define	LOG_VXSNS_DSP_LEAVE(state)
#define	LOG_VXSNS_DPN_ENTER(p_excinf)
#define	LOG_VXSNS_DPN_LEAVE(state)
#define	LOG_VXSNS_TEX_ENTER(p_excinf)
#define	LOG_VXSNS_TEX_LEAVE(state)
#define	LOG_VXGET_TIM_ENTER(p_sysutim)
#define	LOG_VXGET_TIM_LEAVE(ercd, sysutim)

#define	LOG_CHG_IPM_ENTER(ipm)
#define	LOG_CHG_IPM_LEAVE(ercd)
#define	LOG_GET_IPM_ENTER(p_ipm)
#define	LOG_GET_IPM_LEAVE(ercd, ipm)

#endif /* _TOOL_CONFIG_H_ */
