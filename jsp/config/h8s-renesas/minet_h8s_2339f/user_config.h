/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: user_config.h,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */

#ifndef _USER_CONFIG_H_
#define _USER_CONFIG_H_

/*
 *  ���[�U�[�E�R���t�B�M�����[�V�������̒�`
 */

/*
 *  chg_ipm���T�|�[�g���邩�ǂ����̒�`
 *�@�@�A�Z���u���p��user_config.inc�ɂ����l�̒�`���K�v�Ȃ̂Œ���
 */
#define SUPPORT_CHG_IPM

/*
 *  vxget_tim���T�|�[�g���邩�ǂ����̒�`
 */
#define SUPPORT_VXGET_TIM

/*
 *  �J�[�l�����Ǘ����銄���݂̍ō��D�惌�x��
 *�@�@�J�[�l���Ǘ����̊����� �� �����݃��x����MAX_IPM �ȉ��̊�����
 *�@�@�J�[�l���Ǘ��O�̊����� �� �v���C�I���e�B���x��(MAX_IPM+1)
 *�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�ȏ�̊����݂�NMI
 *
 *�@�@�@user_config.inc�ɂ����l�̒�`���K�v�Ȃ̂Œ���
 */
#define MAX_IPM                 0x7u

/*
 *  �V���A���|�[�g�̐ݒ�
 */

/*
 *  �V���A���|�[�g���̒�`
 * 
 *�@�����̊g�����̂��߁A�ȉ��̂悤�ɒ�`���Ă��邪�A���݂̎����ł͎����I��
 *�@�Ⴂ�͂Ȃ��B
 *
 * TNUM_PORT : �V���A���h���C�o�iserial.c�j�A�܂� GDIC���x���ŃT�|�[�g����
 * �@�@�@�@�@�@�V���A���|�[�g�̐� 
 * TNUM_SIOP : PDIC���x���i�v���Z�b�T����SIO�j�ŃT�|�[�g����V���A��I/O�|�[�g
 *�@�@�@�@�@�@ �̐��i���݂̎����ł͍ő�3�j
 */

#define TNUM_PORT	3u
#define	TNUM_SIOP	3u	/*  ���݂̎����ł͍ő�3  */

/*
 *  �V�X�e���^�X�N�Ɋւ����`
 */
#define	LOGTASK_PORTID	2	/* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ� */

/*
 *  �჌�x���o�́i�|�[�����O�o�́j�ɗp����V���A���|�[�g�ԍ�
 */
#define	POL_PORTID	3

/*
 *  �V���A���R���g���[���̃{�[���[�g�̐ݒ� [bps]
 */
#define BAUD_RATE0	38400	/*  SCI0  */
#define BAUD_RATE1	38400	/*  SCI1  */
#define BAUD_RATE2	38400	/*  SCI2  */
#if 0
#define BAUD_RATE0	 9600
#define BAUD_RATE1	 9600
#define BAUD_RATE2	 9600
#define BAUD_RATE0	19200
#define BAUD_RATE1	19200
#define BAUD_RATE2	19200
#endif

/*
 *  �^�C�}�̐ݒ�
 */

/*
 *  �^�C���e�B�b�N�̒�`
 */

#define TIC_NUME        1u               /* �^�C���e�B�b�N�̎����̕��q */
#define TIC_DENO        1u               /* �^�C���e�B�b�N�̎����̕��� */


/*
 *  �����݃��x����`
 */
#define SCI0_INT_LVL	3u		/* SCI�`���l��0�̊��荞�݃��x�� */
#define SCI1_INT_LVL	3u		/* SCI�`���l��1�̊��荞�݃��x�� */
#define SCI2_INT_LVL	3u		/* SCI�`���l��2�̊��荞�݃��x�� */
#define TPU0_INT_LVL	5u		/* TPU�`���l��0�̊��荞�݃��x�� */

#endif /* _USER_CONFIG_H_ */
