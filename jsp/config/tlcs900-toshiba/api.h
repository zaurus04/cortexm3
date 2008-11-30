/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *  @(#) $Id: api.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

#ifndef API_H
#define API_H

#define __cycini
#define __cycenq
#define __sta_cyc
#define __stp_cyc
#define __cyccal
#define __dtqini
#define __dtqenq
#define __dtqfenq
#define __dtqdeq
#define __dtqsnd
#define __dtqrcv
#define __snd_dtq
#define __psnd_dtq
#define __ipsnd_dtq
#define __tsnd_dtq
#define __fsnd_dtq
#define __ifsnd_dtq
#define __rcv_dtq
#define __prcv_dtq
#define __trcv_dtq
#define __flgini
#define __flgcnd
#define __set_flg
#define __iset_flg
#define __clr_flg
#define __wai_flg
#define __pol_flg
#define __twai_flg
#define __excini
#define __vxsns_ctx
#define __vxsns_loc
#define __vxsns_dsp
#define __vxsns_dpn
#define __vxsns_tex
#define __inhini
#define __mbxini
#define __snd_mbx
#define __rcv_mbx
#define __prcv_mbx
#define __trcv_mbx
#define __mpfini
#define __mpfget
#define __get_mpf
#define __pget_mpf
#define __tget_mpf
#define __rel_mpf
#define __semini
#define __sig_sem
#define __isig_sem
#define __wai_sem
#define __pol_sem
#define __twai_sem
#define __rot_rdq
#define __irot_rdq
#define __get_tid
#define __iget_tid
#define __loc_cpu
#define __iloc_cpu
#define __unl_cpu
#define __iunl_cpu
#define __dis_dsp
#define __ena_dsp
#define __sns_ctx
#define __sns_loc
#define __sns_dsp
#define __sns_dpn
#define __logini
#define __vwri_log
#define __vrea_log
#define __vmsk_log
#define __logter
#define __tskini
#define __tsksched
#define __tskrun
#define __tsknrun
#define __tskdmt
#define __tskact
#define __tskext
#define __tskpri
#define __tskrot
#define __tsktex
#define __ras_tex
#define __iras_tex
#define __dis_tex
#define __ena_tex
#define __sns_tex
#define __act_tsk
#define __iact_tsk
#define __can_act
#define __ext_tsk
#define __ter_tsk
#define __chg_pri
#define __get_pri
#define __slp_tsk
#define __tslp_tsk
#define __wup_tsk
#define __iwup_tsk
#define __can_wup
#define __rel_wai
#define __irel_wai
#define __sus_tsk
#define __rsm_tsk
#define __frsm_tsk
#define __dly_tsk
#define __tmeini
#define __tmeup
#define __tmedown
#define __tmeins
#define __tmedel
#define __isig_tim
#define __set_tim
#define __get_tim
#define __vxget_tim
#define __waimake
#define __waicmp
#define __waitmo
#define __waitmook
#define __waican
#define __wairel
#define __wobjwai
#define __wobjwaitmo
#define __wobjpri


#endif

