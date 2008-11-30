/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
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
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 *  �V�X�e���T�[�r�X�̃^�[�Q�b�g�ˑ����iCQ-STARM�p�j
 *
 *  �V�X�e���T�[�r�X�̃^�[�Q�b�g�ˑ����̃C���N���[�h�t�@�C���D���̃t�@
 *  �C���̓��e�́C�R���|�[�l���g�L�q�t�@�C���ɋL�q����C���̃t�@�C����
 *  �����Ȃ錩���݁D
 */

#ifndef TOPPERS_TARGET_SYSSVC_H
#define TOPPERS_TARGET_SYSSVC_H

/*
 *  �^�[�Q�b�g�V�X�e���̃n�[�h�E�F�A�����̒�`
 */
#include "cq_starm.h"

/*
 *  �g���[�X���O�Ɋւ���ݒ�
 */
#ifdef TOPPERS_TRACE_ENABLE
#include "logtrace/trace_config.h"
#endif /* TOPPERS_TRACE_ENABLE */

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define TARGET_NAME    "CQ-STARM(STM32F103)"

/*
 *  �N�����b�Z�[�W�Ƀ^�[�Q�b�g�ˑ����̒��쌠�\����
 *  �ǉ����邽�߂̃}�N���D
 */
#ifdef PRC_COPYRIGHT
#define TARGET_COPYRIGHT	PRC_COPYRIGHT
#endif /* PRC_COPYRIGHT */

/*
 *  �V�X�e�����O�̒჌�x���o�͂̂��߂̕����o��
 *
 *  �^�[�Q�b�g�ˑ��̕��@�ŁC����c��\��/�o��/�ۑ�����D
 */
extern void	target_fput_log(char_t c);

/*
 *  �V���A���|�[�g���̒�`
 */
#define TNUM_PORT        (1)		/* �T�|�[�g����V���A���|�[�g�̐� */
#define TNUM_SIOP        (1)

#define LOGTASK_PORTID   SIO_PORTID

/*
 *  �{�[���[�g
 */
#define BPS_SETTING		(115200)

/*
 *  �V�X�e�����O�^�X�N�֘A�̒萔�̒�`
 *
 *  �f�t�H���g�l�̒ʂ�D
 */

#endif /* TOPPERS_TARGET_SYSSVC_H */
