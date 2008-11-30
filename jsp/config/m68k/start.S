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
 *  @(#) $Id: start.S,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�J�[�l���p�̃X�^�[�g�A�b�v���W���[���iM68040�p�j
 */

#define	_MACRO_ONLY
#include <t_config.h>

	.text
	.globl start
start:
	/*
	 *  �v���Z�b�T���[�h�ƃX�^�b�N�|�C���^�̏�����
	 */
	cinva %bc			/* ���ׂẴL���b�V���𖳌��� */
	move.l #0x80008000, %d0		/* �����̃L���b�V���� ON */
	movec.l %d0, %cacr

	move.w %sr, %d0
	or.w #0x2700, %d0		/* �X�[�p�o�C�U���[�h�CIPM=7�ɐݒ� */
	and.w #0xefff ,%d0		/* �����݃��[�h�ɐݒ� */
	move.w %d0, %sr

	movea.l #STACKTOP, %sp		/* �X�^�b�N�|�C���^�iSPI�j�̏����� */
	movea.l #0, %fp			/* �t���[���|�C���^�̏����� */

	/*
	 *  hardware_init_hook �̌ďo���i0 �łȂ��ꍇ�j
	 *
	 *  �^�[�Q�b�g�n�[�h�E�F�A�Ɉˑ����ĕK�v�ȏ���������������ꍇ
	 *  �́Chardware_init_hook �Ƃ����֐���p�ӂ���D
	 */
	move.l #hardware_init_hook, %a0
	cmp.l #0, %a0
	jbeq start_1
	jsr (%a0)

	/*
	 *  bss�Z�N�V�����̃N���A
	 */
start_1:
	move.l #__bss_start, %a0
	move.l #_end, %d0
	sub.l %a0, %d0
	jbeq start_3
start_2:
	clr.b (%a0)+
	dbra %d0, start_2
	clr.w %d0
	subq.l #1, %d0
	jbcc start_2

	/*
	 *  data�Z�N�V�����̏������iROM���Ή��j
	 *
	 *  __idata_start ���� __idata_end �܂ł��C__data_start �ȍ~��
	 *  �R�s�[����D
	 */
start_3:
	move.l #__idata_end, %d0
	sub.l #__idata_start, %d0
	jbls start_5
	move.l #__idata_start, %a0
	move.l #__data_start, %a1
start_4:
	move.b (%a0)+, (%a1)+
	dbra %d0, start_4
	clr.w %d0
	subq.l #1, %d0
	jbcc start_4

	/*
	 *  software_init_hook ���ďo���i0 �łȂ��ꍇ�j
	 *
	 *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�������
	 *  ��������ꍇ�́Csoftware_init_hook �Ƃ����֐���p�ӂ����
	 *  �悢�D
	 */
start_5:
	move.l #software_init_hook, %a0
	cmp.l #0, %a0
	jbeq start_6
	jsr (%a0)

	/*
	 *  �J�[�l�����N������D
	 */
start_6:
	jmp kernel_start