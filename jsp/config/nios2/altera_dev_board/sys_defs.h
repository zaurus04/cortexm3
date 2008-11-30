/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
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
 *  @(#) $Id: sys_defs.h,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */


/*
 *  �V�X�e���Ɉˑ������`�iAltera NiosII Development Board �p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */


#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

#define ALTERA_DEV


/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g��
 */
#define    TARGET_NAME    "Nios Development Board(Nios2)"

/*
 *  �R���t�B�M�����[�V�����ˑ��̒�`
 */

/*
 *   �X�^�b�N�̈�̒�`
 */                 
#define STACKTOP    0x02000000    /* �^�X�N�Ɨ����p�X�^�b�N�̏����l */


/*
 *  �^�C�}�l�̓����\���ƃ~���b�P�ʂƂ̕ϊ�
 */
#define TIMER_CLOCK     50000

/*
 *  �^�C���e�B�b�N�̒�`
 */
#define    TIC_NUME    1        /* �^�C���e�B�b�N�̎����̕��q */
#define    TIC_DENO    1        /* �^�C���e�B�b�N�̎����̕��� */


#define USE_JTAG_UART


/*
 * �y���t�F�����̃x�[�X�A�h���X
 */
#ifdef  STRATIX_II_2S180
#define PERI_BASE 0x08000000u
#else
#define PERI_BASE 0x00800000u
#endif  /* STRATIX_II_2S180 */

/*
 *  TIMER �̃x�[�X�A�h���X
 */
#define TIM_BASE (PERI_BASE + 0x00010800u)

/*
 * �J�[�l���Ŏg�p���� UART �̃x�[�X�A�h���X
 */
#ifndef USE_JTAG_UART
#define UART_BASE  (PERI_BASE + 0x00010840)
#else
#define UART_BASE  (PERI_BASE + 0x00010820)
#endif /* USE_JTAG_UART */


/*
 *  TIM �����݂̊����ݔԍ�
 */
#define TIM_INTLVL        1

/*
 * UART �����݂̊����ݔԍ�
 */
#ifndef USE_JTAG_UART
#define UART_INTLVL       3
#else
#define UART_INTLVL       2
#endif /* USE_JTAG_UART */


/*                                                                             
 *  �V���A���|�[�g�ԍ��Ɋւ����`      
 */
#define TNUM_PORT   1   /* �T�|�[�g����V���A���|�[�g�̐� */
#define TNUM_SIOP   1   /* �T�|�[�g����V���A��I/O�|�[�g�̐� */

/*
 *  �V�X�e���^�X�N�Ɋւ����`
 */
#define LOGTASK_PORTID    1    /* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ� */


/*
 *  �������ԑ҂��̂��߂̒�`
 */
#define SIL_DLY_TIM1    420
#define SIL_DLY_TIM2    90

/*
 * �L���b�V���̐ݒ�
 */ 
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE 4

/*
 * ROM���̏ꍇ�́CROM(FLASH)��RAM
 */ 
#define ROM_BASE   0x00000000
#define RAM_BASE   0x01000000

#endif /* _SYS_DEFS_H_ */
