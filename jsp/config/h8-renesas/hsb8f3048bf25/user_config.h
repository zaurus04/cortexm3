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
 *  @(#) $Id: user_config.h,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

#ifndef _USER_CONFIG_H_
#define _USER_CONFIG_H_

/*
 *  ���[�U�[�E�R���t�B�M�����[�V�������̒�`
 */

/*
 *  chg_ipm���T�|�[�g���邩�ǂ����̒�`
 *�@�@�A�Z���u���p��user_config_asm.inc�ɂ����l�̒�`���K�v�Ȃ̂Œ���
 */
#define SUPPORT_CHG_IPM

/*
 *  vxget_tim���T�|�[�g���邩�ǂ����̒�`
 */
#define SUPPORT_VXGET_TIM

/*
 *  �N���b�N���g�� [Hz]
 *�@�@�@user_config_asm.inc�ɂ����l�̒�`���K�v�Ȃ̂Œ���
 */
#define CPU_CLOCK               24576000ul


/*
 *  �V���A���|�[�g�̐ݒ�
 */

/*
 *  �T�|�[�g����V���A���f�o�C�X�̐��i�ő� 2�j
 *�@�@user_config_asm.inc�ɂ����l�̒�`���K�v�Ȃ̂Œ���
 */
#define TNUM_PORT               1u

/*
 *  �|�[�g�ԍ�
 *
 *  �@�{����hw_serial.h�Œ�`���ׂ������A�T���v���v���O��������
 *  �@�Q�Ƃ��邽�߁A�����Œ�`����B
 */
#define SCI_PORTID1				1		/*  �ύX�֎~  */
#define SCI_PORTID2				2		/*  ����  */

/*
 *  �|�[�g�ԍ��̊��蓖��
 *
 *  �@E10T-USB�Ńf�o�b�O���s���ۂɂ́ASCI1����L����邽�߁A
 *  �@���[�U�[�v���O������SCI0�݂̂��g�p����B
 *
 *�@�@�|�[�g���P�̂Ƃ�
 *�@�@�@�@�{�[�g�P(SCI0)�F�V�X�e���|�[�g�i�Œ�j
 *�@�@�|�[�g���Q�̂Ƃ�
 *�@�@�@�@�{�[�g�P(SCI0)�F�V�X�e���|�[�g�^���[�U�[�|�[�g�I���\
 *�@�@�@�@�{�[�g�Q(SCI1)�F����
 */
#if TNUM_PORT == 1u

#define SYSTEM_PORTID           SCI_PORTID1		/*  �Œ�  */

#elif TNUM_PORT == 2u    /* of #if TNUM_PORT == 1u */

#define SYSTEM_PORTID           SCI_PORTID1		/*  �����\  */
#define USER_PORTID             SCI_PORTID2

#else   /* of #if TNUM_PORT == 1u || TNUM_PORT == 2u */

#error TNUM_PORT <= 2u

#endif  /* of #if TNUM_PORT == 1u */

/*
 *  �჌�x���o�͂ɗp����V���A���|�[�g�̃|�[�g�ԍ�
 */
#define SCI_LOW_PORTID			SYSTEM_PORTID

/*  �{�[���[�g�ƃv���C�I���e�B�E���x��  */
#define SCI_PORT1_BAUD_RATE     38400ul		/* �{�[���[�g [bps]     */
#define SCI_PORT1_IPM           IPM_LEVEL0	/* �v���C�I���e�B���x��  */

#if TNUM_PORT == 2u

#define SCI_PORT2_BAUD_RATE     38400ul		/* �{�[���[�g [bps]     */
#define SCI_PORT2_IPM           IPM_LEVEL0	/* �v���C�I���e�B���x��  */

#endif  /* of #if TNUM_PORT == 2u */


/*
 * �G���[���荞�݂��A���͊��荞�݂ƕʂɑ��삷��ꍇ�̓R�����g���O���B
 *�@�@user_config_asm.inc�ɂ����l�̒�`���K�v�Ȃ̂Œ���
 */
#if 0
#define H8_CFG_SCI_ERR_HANDLER
#endif


/*
 *  �^�C�}�̐ݒ�
 */

/*
 *  �^�C���e�B�b�N�̒�`
 */

#define TIC_NUME        1u               /* �^�C���e�B�b�N�̎����̕��q */
#define TIC_DENO        1u               /* �^�C���e�B�b�N�̎����̕��� */

/*  �^�C�}�ɋ��������N���b�N���g�� [kHz]  */
#define TIMER_CLOCK     ((CPU_CLOCK)/8000ul)     /* 8���� */

/*  �v���C�I���e�B���x��  */
#define SYSTEM_TIMER_IPM                IPM_LEVEL1


#endif /* _USER_CONFIG_H_ */
