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
 *  @(#) $Id: sys_config.h,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

/*
 *�@�^�[�Q�b�g�V�X�e���ˑ����W���[���i�k�l�d�q HSB8F3048BF25�p�j
 *�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@�f�[�^�^�A�}�N���A�֐��̃v���g�^�C�v�錾
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */

#include <sys_rename.h>

/*
 *  ���[�U�[�E�R���t�B�M�����[�V�������̒�`
 */
#include <user_config.h>


/*
 *  �^�[�Q�b�g�V�X�e���̃n�[�h�E�F�A�����̒�`
 */

#include <h8_3048f.h>

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g��
 */

#define TARGET_NAME     "Hokuto Electronic H8/3048F-ONE STARTER KIT"


#ifndef _MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */

extern void     sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���DROM���j�^�ďo���Ŏ������邱�Ƃ�z�肵
 *  �Ă���D
 */

extern void     sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���DROM���j�^�ďo���Ŏ������邱
 *  �Ƃ�z�肵�Ă���D
 */
extern void     sys_putc(char c) throw();

#endif /* _MACRO_ONLY */

/*
 *  SOFTWARE_TERM_HOOK�}�N���Fatexit�̏���
 *  �@�����֐��̊O����`������΁A���̊֐�����SOFTWARE_TERM_HOOK
 *�@�@�}�N���Ƃ��Ē�`����B
 */
/*  ����͒�`�Ȃ�  */


/*
 *  (1) �V���A���|�[�g�̐ݒ�
 *  (2) �^�C�}�[�̐ݒ�
 *  (3) �O���A�h���X��Ԑ���
 */

/*
 *  SCI ���ʒ萔�A�}�N��
 */

        /* SCI ���N���[�Y����O�̑҂����Ԃ̌v�Z�Ɏg�p����B*/
#define H8_MIN_BAUD_RATE        9600ul

/*
 *  SYSTEM �p SCI �̐ݒ�l
 */
                                /* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ�     */
#define LOGTASK_PORTID          SYSTEM_PORTID   /*  user_config.h  */

/*  �ݒ背�W�X�^�̃x�[�X�A�h���X  */
#define SCI_PORT1_BASE          H8SCI0

/*  �v���C�I���e�B���x���ݒ�p�̃f�[�^  */
#define SCI_PORT1_IPR          H8IPRB
#define SCI_PORT1_IPR_BIT      H8IPR_SCI0_BIT

#define SCI_PORT1_SMR          0u
                        /* ����M�t�H�[�}�b�g                   */
                        /* ����������                           */
                        /* �L�����N�^�����O�X�F8�r�b�g          */
                        /* �p���e�B�Ȃ�                         */
                        /* �X�g�b�v�r�b�g�����O�X�F1            */
                        /* �N���b�N�Z���N�g�i������j:1         */

#define INHNO_SERIAL_IN         IRQ_RXI0
#define INHNO_SERIAL_OUT        IRQ_TXI0
#define INHNO_SERIAL_ERR        IRQ_ERI0


#if TNUM_PORT == 2

#define SCI_PORT2_BASE          H8SCI1

/*  �v���C�I���e�B���x���ݒ�p�̃f�[�^  */
#define SCI_PORT2_IPR          H8IPRB
#define SCI_PORT2_IPR_BIT      H8IPR_SCI1_BIT

#define SCI_PORT2_SMR          0u
                        /* ����M�t�H�[�}�b�g                   */
                        /* ����������                           */
                        /* �L�����N�^�����O�X�F8�r�b�g          */
                        /* �p���e�B�Ȃ�                         */
                        /* �X�g�b�v�r�b�g�����O�X�F1            */
                        /* �N���b�N�Z���N�g�i������j:1         */

#define INHNO_SERIAL2_IN        IRQ_RXI1
#define INHNO_SERIAL2_OUT       IRQ_TXI1
#define INHNO_SERIAL2_ERR       IRQ_ERI1

#endif  /* of #if TNUM_PORT == 2u */

/*
 *  �^�C�}�̐ݒ�
 */

#define SYSTEM_TIMER            H8ITU0

#define SYSTEM_TIMER_CNT        (SYSTEM_TIMER + H8TCNT)
#define SYSTEM_TIMER_TCR        (SYSTEM_TIMER + H8TCR)
#define SYSTEM_TIMER_TIOR       (SYSTEM_TIMER + H8TIOR)
#define SYSTEM_TIMER_IER        (SYSTEM_TIMER + H8TIER)
#define SYSTEM_TIMER_IFR        (SYSTEM_TIMER + H8TSR)
#define SYSTEM_TIMER_TSTR       H8ITU_TSTR
#define SYSTEM_TIMER_GR         (SYSTEM_TIMER + H8GRA)

#define SYSTEM_TIMER_STR        H8TSTR_STR0
#define SYSTEM_TIMER_STR_BIT    H8TSTR_STR0_BIT
#define SYSTEM_TIMER_IE         H8TIER_IMIEA            /* interrupt mask */
#define SYSTEM_TIMER_IE_BIT     H8TIER_IMIEA_BIT
#define SYSTEM_TIMER_IF         H8TSR_IMIFA             /* match flag */
#define SYSTEM_TIMER_IF_BIT     H8TSR_IMIFA_BIT

#define INHNO_TIMER             IRQ_IMIA0

#define SYSTEM_TIMER_TCR_BIT    (H8TCR_CCLR0 | H8TCR_TPSC1 | H8TCR_TPSC0)
#define SYSTEM_TIMER_TIOR_BIT   (0u)

/*  �v���C�I���e�B���x���ݒ�p�̃f�[�^  */
#define SYSTEM_TIMER_IPR                H8IPRA
#define SYSTEM_TIMER_IP_BIT             H8IPR_ITU0_BIT

/*
 *  I/O�|�[�g DDR�̏����l
 *      h8_sil.c��DDR�A�N�Z�X���[�`���Ŏg�p����B
 *      �|�[�g�V�͓��͐�p�̂��߁A�ȗ����Ă���B
 */
#define H8P1DDR0        0xffu	/*  �A�h���X�E�o�X  */
#define H8P2DDR0        0xffu	/*  �A�h���X�E�o�X  */
#define H8P3DDR0        0u	    /*  �f�[�^�E�o�X�@  */
#define H8P4DDR0        0u      /*  �f�[�^�E�o�X�@  */
#define H8P5DDR0        0x0fu	/*  �A�h���X�E�o�X  */
#define H8P6DDR0        0u
#define H8P8DDR0        H8P8DDR_CS1     /*  P83��CS1�ɐݒ�  */
#define H8P9DDR0        0u
#define H8PADDR0        0u
#define H8PBDDR0        0u

/*
 *  SYSCR�̏����l
 *      $SYS�f�B���N�g����SYSCR_SYS�Ƃ��Ē�`������e
 *      �@�r�b�g6-4 STS�F�X�^���o�C�E�^�C�}�E�Z���N�g
 *      �@�r�b�g2 NMIEG�FNMI�G�b�W
 */
#define SYSCR_SYS	0u


#endif /* _SYS_CONFIG_H_ */
