/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                                  Toyohashi Univ. of Technology, JAPAN
 *                     2003        by Advanced Data Controls, Corp
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
 *  @(#) $Id: start.sh,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */
        
/*
 *  �J�[�l���p�̃X�^�[�g�A�b�v���W���[��
 */               
#define _MACRO_ONLY
#include <t_config.h>
#include <sys_defs.h>

/*GHS�A�Z���u���[�����ߕϊ�*/
#define   long   data.l

/*
 *   SH3�p�X�^�[�g�A�b�v���W���[��
 *   �J�[�l���̓A�v���P�[�V�����ƃ����N���Ďg�p����
 *   �����Ȃ̂�JSP�J�[�l���̂ݎg�p����B	
 */
	.global	_start
	.global _main
	.align 2
_main:
_start:
	/*
	 *  �L���b�V���̏�����
	 */
	mov.l _ccr_addr,r1
	mov.l _ccr_disable,r2
	mov.l r2,@r1
	mov.l _ccr_mode,r2
	mov.l r2,@r1

	/*
	 *  SR������������B
	 *  MD=1, RB=0, BL=0, I3�`I0=e f��stub�̂�
	 */
	mov.l _init_sr,r0
	ldc   r0,sr
	mov   #0x01,r0
	ldc   r0,r7_bank
	/*
	 * �^�X�N�Ɨ��̃X�^�b�N��STACKTOP�ɏ���������
	 * STACKTOP�́Asys_config.h�Œ�`
	 */
	mov.l  _stack_k, r15

	/*
	 *  _hardware_init_hook ���Ăяo���B(0�łȂ��ꍇ)
	 *
	 *  �n�[�h�E�F�A�ˑ��ɕK�v�ȏ���������������ꍇ�́C
	 *  hardware_init_hook �Ƃ����֐���p�ӂ���΂悢�D
	 *  ��̓I�ɂ�ROM���̍ہARAM���g�p�\�ɂ��邽�߂�
	 *  �o�X�R���g���[���̏����������s���B
	 *  sys_support.S ���� _hardware_init_hook ���`���Ă�
	 *  ��D
	 */

start_0:
	mov.l  _hardware_init_hook_k, r0
	tst    r0,r0
	bt     start_5
	jsr    @r0
     	or      r0,r0

	/*
	 *  _software_init_hook ���Ăяo���i0 �łȂ��ꍇ�j�D
	 *
	 *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�������
	 *  ��������ꍇ�́Csoftware_init_hook �Ƃ����֐���p�ӂ����
	 *  �悢�D
	 */
start_5:	
	mov.l  _software_init_hook_k, r0
	tst    r0,r0
	bt     start_6		
	jsr    @r0
	or     r0,r0

		
start_6:
	/*�J�[�l�����N������*/

	mov.l _kernel_start_k,r0
	jsr	  @r0
	or	   r0,r0


	.align 4
_ccr_addr:	
	.long CCR
_ccr_disable:	
	.long CCR_DISABLE
_ccr_mode:	
	.long CCR_MODE
_init_sr:	
	.long  0x40000000 + MAX_IPM << 4
_stack_k:	
	.long   STACKTOP
_kernel_start_k:	
	.long	_kernel_start
	.weak _hardware_init_hook
	.weak _software_init_hook
_hardware_init_hook_k:	
	.long   _hardware_init_hook
_software_init_hook_k:	
	.long   _software_init_hook	


















