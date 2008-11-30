/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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
 *  @(#) $Id: start.S,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *	�J�[�l���p�̃X�^�[�g�A�b�v���W���[���iSH1/2�p�j
 */

#define	_MACRO_ONLY
#include <t_config.h>

/*
 *�@�@��O�x�N�^�̒�`�iSH1/2�p�j
 *�@�@�@�����ł̓��Z�b�g���ɕK�v�ȍŒ���̃x�N�^�����p�ӂ��Ȃ�
 *�@�@�@cpu_initialize()�ŗ�O�x�N�^�̈ړ��iVBR�̏��������j���s��
 */
#ifdef KERNEL_HAS_A_VECTOR_TABLE

/*
 *   �ȉ��̗�O�v���Ńf�t�H���g�Ƃ͈قȂ��O�x�N�^���`
 *   ����ꍇ�́Asys_config.h�ŊY������}�N�����`����B
 */
	.section ".vector","ax"
	.align 2
	.long   TO_ASM(RESET_VECTOR)	/*   0:�p���[�I�����Z�b�g  */
	.long   INIT_STACK		/*       SP�̏����l        */
	.long   TO_ASM(RESET_VECTOR)	/*   2:�}�j���A�����Z�b�g  */
	.long   INIT_STACK		/*       SP�̏����l        */
	.long   TO_ASM(GII_VECTOR)	/*   4:��ʕs������        */
	.long   TO_ASM(RESERVED_VECTOR)	/*   5:�V�X�e���\��        */
	.long   TO_ASM(SII_VECTOR)	/*   6:�X���b�g�s������    */
	.long   TO_ASM(RESERVED_VECTOR)	/*   7:�V�X�e���\��        */
	.long   TO_ASM(RESERVED_VECTOR)	/*   8:�V�X�e���\��        */
	.long   TO_ASM(CAE_VECTOR)	/*   9:CPU�A�h���X�G���[   */
	.long   TO_ASM(DAE_VECTOR)	/*  10:DMA�A�h���X�G���[   */
	.long   TO_ASM(NMI_VECTOR)	/*  11:MNI                 */
#endif /* KERNEL_HAS_A_VECTOR_TABLE */

/*
 *   SH1/2�p�X�^�[�g�A�b�v���W���[��
 */
	.global	_start
	.section .text
	.align 2
_start:
	/*
	 *  SR������������B�i�����݋֎~�j
	 *  IPM=0xe
	 *  stub���s���̂�IPM=0xf�ƂȂ�B
	 */
	mov.l _init_sr,r0
	ldc   r0,sr
	/*
	 * ��^�X�N�R���e�X�g�̃X�^�b�N��STACKTOP�ɏ���������
	 * STACKTOP�́Auser_config.h�Œ�`
	 */
	mov.l  _stack_k, r15

	/*
	 *  _hardware_init_hook ���Ăяo���B(0�łȂ��ꍇ)
	 *
	 *  �n�[�h�E�F�A�ˑ��ɕK�v�ȏ���������������ꍇ�́C
	 *  hardware_init_hook �Ƃ����֐���p�ӂ���΂悢�D
	 *  ��̓I�ɂ�ROM���̍ہARAM���g�p�\�ɂ��邽�߂�
	 *  �o�X�R���g���[���̏����������s���B
	 *  sys_support.S ���� hardware_init_hook ���`���Ă�
	 *  ��D
	 */
start_0:
	/*
	 *  �v���Z�b�T����RAM�����p�ł���ꍇ�͂��̃A�h���X��
	 *  INNER_RAM_ADDRESS�}�N���Ƃ���user_config.h�܂���
	 *  �R���p�C���E�I�v�V�����Œ�`����B
	 *�@�i����RAM�̐擪�A�h���X�ł͂Ȃ��A�X�^�b�N�̒��
	 *�@�@����_�ɒ��Ӂj
	 *
	 *  ���̏ꍇ�Ahardware_init_hook()�֐���C�����
	 *  �L�q���Ă悢�B
	 *  ��ʂ�C����̊֐��Ăяo���̓X�^�b�N���g�p����̂�
	 *  �o�X�R���g���[���̏������O�ɂł��Ȃ��B
	 */
#ifdef INNER_RAM_ADDRESS
	mov.l  _inner_ram_address_k, r15
#endif /* INNER_RAM_ADDRESS */
	mov.l   _hardware_init_k, r0
	tst    r0,r0
	bt     start_1
	jsr    @r0
        nop


	/*
         * bss�Z�N�V�������N���A
	 */
start_1:
	/*
         * �X�^�b�N�|�C���^���O��RAM�ɍĐݒ肷��B�i��L�Q�Ɓj
	 */
#ifdef INNER_RAM_ADDRESS
	mov.l  _stack_k, r15
#endif /* INNER_RAM_ADDRESS */

	mov.l	_bss_start_k,r0
	mov.l	_end_k,r1
	cmp/eq  r0,r1
	bt      start_3
	mov	#0,r2
start_2:
	/*
	 *  r0�̃C���N�������g���璷�Ɍ����邪
	 *  mov.l r4,@r0+���߂͂Ȃ�
	 *	�f�B�X�e�B�l�[�V�����̃A�h���X�̓f�B�N�������g�̂�
	 */
        mov.l	r2,@r0
	add	#4,r0
 	cmp/hi	r0,r1
	bt	start_2

	/*
	 *  data�Z�N�V����������������iROM���Ή��j�D
	 *
	 *  __idata_start ���� __idata_end �܂ł��C__data_start �ȍ~��
	 *  �R�s�[����D
	 *
	 *�@�f�o�b�O���ɂ���Ă�data�Z�N�V�����̔F���ɕs�������A
	 *�@__idata_start�Ԓn�Ƀ_�E�����[�h���ׂ��f�[�^��__data_start
	 *�@�Ԓn�Ƀ_�E�����[�h���Ă��܂����̂�����B���̏ꍇ��
	 *�@OMIT_DATA_SECTION_COPY�}�N�����`���Ă�邱�Ƃł��̃R�s�[
	 *�@��Ƃ��ȗ�����B
	 */
start_3:
#ifndef OMIT_DATA_SECTION_COPY	/*  data�Z�N�V�����̃R�s�[���s���ꍇ  */
	mov.l   __idata_start_k,r1
	mov.l   __idata_end_k,r2
	cmp/eq  r1,r2
	bt      start_5
	mov.l   __data_start_k,r0
start_4:
	mov.l   @r1+,r4
	mov.l   r4,@r0
	cmp/hi  r1,r2
	add     #4,r0
	bt      start_4
#endif 	/* OMIT_DATA_SECTION_COPY */

	/*
	 *  software_init_hook ���Ăяo���i0 �łȂ��ꍇ�j�D
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
	nop


start_6:
	/*
         *  �J�[�l�����N������
	 */
	! call the mainline
	mov.l	_kernel_start_k,r0
	jsr	@r0
	nop


	.align 2
_intnest_k:
	.long	_intnest
_init_sr:
	.long	MAX_IPM << 4
_stack_k:
	.long   STACKTOP


#ifdef INNER_RAM_ADDRESS
_inner_ram_address_k:
	.long   INNER_RAM_ADDRESS
#endif /* INNER_RAM_ADDRESS */

_bss_start_k:
	.long   __bss_start

#ifdef FILL_STACK_WITH_0  /*  �f�o�b�K�ŃX�^�b�N�̈���ώ@���Ղ�  */
			  /*  ���邽�߁A��^�X�N�R���e�L�X�g��    */
			  /*  �X�^�b�N�̈������������            */
_end_k:
	.long   STACKTOP
#else			/*  �X�^�b�N�̈�����������Ȃ��ꍇ  */
_end_k:			/*  �@bss�Z�N�V������������������  */
	.long  	_end
#endif	/* FILL_STACK_WITH_0  */


#ifndef OMIT_DATA_SECTION_COPY	/*  data�Z�N�V�����̃R�s�[���s���ꍇ  */
__idata_start_k:
	.long 	__idata_start
__idata_end_k:
	.long   __idata_end
__data_start_k:
	.long  	__data_start
#endif 	/* OMIT_DATA_SECTION_COPY */

_kernel_start_k:
	.long	_kernel_start
_hardware_init_k:
	.long   _hardware_init_hook
_software_init_hook_k:
	.long   _software_init_hook
