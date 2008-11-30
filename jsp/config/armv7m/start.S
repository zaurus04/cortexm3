/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2008 by TOPPERS/JSP for CORTEX-M3 project
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
 *  @(#) $Id: start.S,v 1.14 2008/07/31 12:39:26 suikan Exp $
 */

/*
 *	�J�[�l���p�̃X�^�[�g�A�b�v���W���[���iCORTEX-M3�p�j
 */

#define	_MACRO_ONLY
#include <t_config.h>

		/*
		* CORTEX-M3 ���Z�b�g�E�x�N�g��
		*
		* �V�X�e���E�X�^�[�g���ɎQ�Ƃ����4�G���g�����̃x�N�g���B
		* CORTEX-M3 TRM 5.9.1�߂��Q��
		*/
    .section .rodata
    .align 4
    .global vector_table
vector_table:
	.long	__master_stack					/* MSP�̏����l�B */
	.long	start + 1						/* ���s�J�n�Ԓn�BThumb���[�h�ɓ���邽�߁ALSB��1�łȂ���΂Ȃ�Ȃ� */
	.long	default_nmi_handler +1			/* NMI�BThumb���[�h�ɓ���邽�߁ALSB��1�łȂ���΂Ȃ�Ȃ� */
	.long	default_hard_fault_handler + 1	/* �n�[�h�E�t�H���g�BThumb���[�h�ɓ���邽�߁ALSB��1�łȂ���΂Ȃ�Ȃ� */

	.align 2
	.thumb
	.text
	.globl start
start:
	/*
	 *  �v���Z�b�T���[�h�ƃX�^�b�N�|�C���^�̏������BCORTEX-M3�ł́A�����ɓ��B�������_��
	 *  MSP�ɐ������X�^�b�N�̈�̍ŏ�ʂ̃A�h���X���ݒ肳��Ă���B
	 */	 
	
			/* ���荞�݋֎~��ԂɕύX */
	cpsid	i					/* ���荞�݋֎~�B lock_cpu �ɑ���*/
	movw	r0,#0xFF
	msr		basepri,r0			/* BASEPRI = 0xFF : �S���x���̊��荞�݂����� */
	
			/* �X�^�b�N�|�C���^�̒l��MSP����PSP�ɃR�s�[ */
	mrs		r0,msp				/* MSP�̒l���擾 */
	msr		psp,r0				/* PSP�Ɏ擾�����l���Z�b�g */
	
			/* �X�^�b�N�� PSP �ɐ؂�ւ��� */
	mrs		r0,control
	mov		r1,#2
	orr		r0,r1				/* CONTROL[1]��Thread Mode����PSP���g���悤�ɂ���B
								 * CONTROL�̓��Z�b�g����0�ɂ���(ARMV7M AAPMRM B1-9 )�A
								 * �����Z�b�g�����Thread Mode��MSP���g���̂ŁACONTROL[1]��
								 * 1�ɂ���ƁAPSP���g����͂� */
	msr		control,r0
	isb							/* control �ւ̏������݂��Z������̂�҂� */
	 
	/*
	 *  hardware_init_hook �̌ďo���i0 �łȂ��ꍇ�j
	 *
	 *  �^�[�Q�b�g�n�[�h�E�F�A�Ɉˑ����ĕK�v�ȏ���������������ꍇ
	 *  �́Chardware_init_hook �Ƃ����֐���p�ӂ���D
	 */
	ldr r0,=hardware_init_hook +1
	cmp r0,r1					/* �A�h���X��1�� */
	beq	start_1					/* hardware_init_hook�̃A�h���X��1�Ȃ�A�Ă΂Ȃ� */
	blx	r0;

	/*
	 *  bss�Z�N�V�����̃N���A
	 */
start_1:
	ldr		r0,=__bss_start		/* �̈�̊J�n�A�h���X */
	ldr		r1,=__bss_end		/* �̈�̏I���A�h���X */
	mov		r2,#0
	cmp		r0,r1				/* �̈�I�� ? */
	beq		start_3				/* if yes, finish */
	
start_2:
	strb	r2,[r0]
	add		r0,#1
	cmp		r0,r1				/* �̈�I�� ? */
	bne		start_2				/* if no, repeat again */


	/*
	 *  data�Z�N�V�����̏������iROM���Ή��j
	 *
	 *  __idata_start ���� __idata_end �܂ł��C__data_start �ȍ~��
	 *  �R�s�[����D
	 */
start_3:
	ldr		r0,=__idata_start	/* �\�[�X�̈�̊J�n�Ԓn */
	ldr		r1,=__idata_end		/* �\�[�X�̈�̏I���Ԓn�i�̎��̔Ԓn�j */
	ldr		r2,=__data_start	/* �f�B�X�e�B�l�[�V�����̈�̊J�n�Ԓn */
	cmp		r0,r1				/* �\�[�X�̈�I��� ? */
	beq		start_5				/* if yes, finish */



start_4:
	ldrb	r3,[r0]				/* �\�[�X�f�[�^�擾 */
	strb	r3,[r2]				/* �f�B�X�e�B�l�[�V�����Ɋi�[ */
	add		r0,#1				/* �\�[�X�E�A�h���X�|�C���^�X�V */
	add		r2,#1				/* �f�B�X�e�B�l�[�V�����E�A�h���X�|�C���^�X�V */
	cmp		r0,r1				/* �̈�I�� ? */
	bne		start_4				/* if no, repeat again */

	/*
	 *  software_init_hook ���ďo���i0 �łȂ��ꍇ�j
	 *
	 *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�������
	 *  ��������ꍇ�́Csoftware_init_hook �Ƃ����֐���p�ӂ����
	 *  �悢�D
	 */
start_5:
	ldr	r0,=software_init_hook+1
	cmp r0,r1					/* �A�h���X��1�� */
	beq	start_6					/* hardware_init_hook�̃A�h���X��1�Ȃ�A�Ă΂Ȃ� */
	blx	r0;


	/*
	 *  �J�[�l�����N������D
	 */
start_6:
	ldr r0,=kernel_start+1
	bx	r0						/* kernel_start()���ĂԁB�ǂ����߂��Ă��Ȃ��̂� blx�ɂ���K�v�͂Ȃ� */