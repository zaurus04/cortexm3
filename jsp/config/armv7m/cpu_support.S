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
 *  @(#) $Id: cpu_support.S,v 1.17 2008/08/02 07:52:58 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[�� �A�Z���u�����ꕔ�iCORTEX-M3�p�j
 */

#define	_MACRO_ONLY
#include "jsp_kernel.h"
#include "offset.h"

/*
 *  �^�X�N�f�B�X�p�b�`��
 *
 *  dispatch �́C�X���b�h���[�h�E�����݋֎~��ԂŌĂяo���Ȃ���΂Ȃ��
 *  ���D
 *  runtsk, schedtsk�� jsp/kernel/task.h�Ŏ��̂悤�ɐ錾����Ă���
 *
 *  extern TCB * runtsk;
 *  extern TCB * schedtsk;
 */
 	.syntax unified
	.text
	.globl dispatch
	.globl exit_and_dispatch
dispatch:
	push.w {r4 - r11, lr}	/* ���W�X�^��ۑ� */
	ldr r0, =runtsk			/* r0 �� &runtsk �� */
	ldr r1, [r0]			/* r1 �� runtsk �� */
	str sp, [r1, #TCB_sp]	/* runtsk->sp�Ƀ^�X�N�X�^�b�N��ۑ� */
	ldr r2, =dispatch_r+1	/*�@���s�ĊJ�Ԓn���擾 */
	str r2, [r1, #TCB_pc]	/* runtsk->pc�Ɏ��s�ĊJ�Ԓn��ۑ� */

exit_and_dispatch:
dispatcher:
	/*
	 *  �����ł̓X���b�h���[�h�E�����݋֎~��ԂłȂ���΂Ȃ�Ȃ��D
	 */
	ldr r0, =runtsk			/* r0 �� &runtsk �� */
	ldr r2, =schedtsk
	ldr r1,[r2]				/* schedtsk �����o�� */
	str r1,[r0]				/* *runtsk = *schedtsk */
	tst r1,r1				
	beq dispatcher_1		/* runtsk �����邩�H */
	ldr	sp,[r0,#TCB_sp]		/* runtsk->sp����^�X�N�X�^�b�N�𕜋A */
	ldr pc,[r0,#TCB_pc]		/* runtsk->����������s�ĊJ�Ԓn�𕜋A */
	
dispatcher_1:
				/* �X�^�b�N�� MSP �ɐ؂�ւ��� */
	mrs		r3,control
	bic		r3,#02			/* CONTROL[1]��Thread Mode����MSP���g���悤�ɂ���B */
	msr		control,r3
	isb						/* control�̏������ݏI���҂��@*/
	
	wfi						/* ���荞�ݑ҂� */
	/*
	 *  ������MSP�ɐ؂芷����̂́C�����Ŕ������銄���ݏ���
	 *  �ɂǂ̃X�^�b�N���g�����Ƃ������̉����ƁC�����݃n���h������
	 *  �̃^�X�N�f�B�X�p�b�`�̖h�~�Ƃ���2�̈Ӗ�������D
	 *
	 *  �v���Z�b�T��҂����[�h�Ɉڍs�����鏈���ƁC�����݋��Ƃ́C
	 *  �s���ɍs�Ȃ��K�v������iCORTEX-M3 �ł� WFI���߂�
	 *  ���荞�݋֎~���ł����荞�ݓ��͂�SLEEP���甲���o���̂�
	 *  �̂Ŗ��Ȃ��j�D�����s���ɍs�Ȃ�Ȃ��ꍇ�C�����݂�����
	 *  ��������Ɋ����݂�����C���̒��Ń^�X�N�����s�\��ԂɂȂ�
	 *  �ƁC���s���ׂ��^�X�N������ɂ�������炸�v���Z�b�T���҂����[
	 *  �h�ɂȂ��Ă��܂��D
	 *
	 *  �����݂�҂Ԃ́Cruntsk �� NULL�i=0�j�ɐݒ肵�Ȃ���΂Ȃ�
	 *  �Ȃ��D���̂悤�ɐݒ肵�Ȃ��ƁC�����݃n���h������ iget_tid 
	 *  ���Ăяo�����ۂ̓��삪�d�l�ɍ��v���Ȃ��Ȃ�D
	 */
	 			/* WFI �𒆒f���������荞�݂̎󂯕t�� */
	cpsie i				/* ���荞�݋��� */
	nop					/*�@�����Ŋ��荞�݂��������� */
	cpsid i				/* ���荞�݋֎~ */
	 
	orr r3,#02				/* CONTROL[1]��Thread Mode����PSP���g���悤�ɂ���B */
	msr	control,r3
	isb						/* control�̏������ݏI���҂��@*/
	 
	ldr r1, =reqflg
	ldr r2, [r1]			/* reqflg �����[�h�@*/
	tst r2,r2				/* 0? */
	beq dispatcher_1		/* ���N�G�X�g���Ȃ��Ȃ犄�荞�݂�҂� */
	mov r2,#0
	str r2, [r1]			/* reqflg �� FALSE �� */
	b dispatcher
	
dispatch_r:
			/* r0 �ɂ� &runtsk�������Ă��� */
			/* r1 �ɂ� runtsk�������Ă��� */
	pop.w {r4 - r11}				/* ���W�X�^�𕜋A. lr�͍Ō�ɕ��A���� */
	ldrb r2, [r1,#TCB_enatex]		/* runtsk->enatex ����^�X�N��O��Ԃ��擾 */
	tst	r2, #(1<<TCB_enatex_bit)	/* enatex�̓Z�b�g����Ă��邩 */
	beq dispatch_r_1				/* enatex �� FALSE �Ȃ烊�^�[�� */
	ldr r2, [r1,#TCB_texptn]		/* runtsk->texptn */
	tst r2,r2						/* texptn �� 0 ��  */
	beq dispatch_r_1				/* texptn �� 0 �Ȃ烊�^�[�� */
	ldr r1, =call_texrtn +1
	blx r1							/*   �^�X�N��O�������[�`���̌ďo�� */
dispatch_r_1:
	pop {pc }						/* lr�𕜋A���āA���̔Ԓn�idispatch���Ăяo�����Ԓn�j�ɖ߂� */


	
	
/*
 *  �^�X�N�N��������
 */
	.text
	.globl activate_r
activate_r:
	/*
	 *  �^�X�N�N������̓^�X�N��O�������֎~����Ă��邽�߁C�����Ń^
	 *  �X�N��O�������[�`�����Ăяo�������͐��藧���Ȃ��D
	 *
	 *  ���̃R�[�h�́A�^�X�N�X�^�b�N����K�v�ȏ������o���B�X�^�b�N��
	 *  ���𖄂ߍ��ނ̂́Acpu_context.h�� activate_context()�ł���B
	 */
	 pop {r0,lr}				/* extinf�Ɩ߂�Ԓn ( ext_tsk )��ݒ� */ 
	 cpsie i					/* �^�X�N�͋N�������CPU�A�����b�N��ԂɂȂ� */
	 pop {pc}					/* �^�X�N�̊J�n */

/*
 *  �����݃n���h���^CPU��O�n���h���o������
 *
 *  ret_int �ւ́A�n���h�����[�h�AMSP�A���荞�݋���Ԃœ����Ă���B���̂Ƃ��́A�X�^�b�N�̗l�q��
 *  �ȉ��̂Ƃ���
 *  [��] <- MSP (R13)
 *  
 *  [xPSR]    +28
 *  [ PC ]    +24
 *  [ LR ]    +20
 *  [ R12]    +16
 *  [ R3 ]    +12
 *  [ R2 ]    + 8
 *  [ R1 ]    + 4
 *  [ R0 ] <- PSP
 */
	.text
 	.syntax unified
	.globl ret_int
ret_int:
	cpsid i					/* CPU���b�N (���荞�݋֎~) */
	mrs r12,psp				/* PSP�̒l���擾 */
	ldr r3,[R12,#28]		/* xPSR�̒l���擾 */
	ldr r2,=ret_int_0+1		/* �^�X�N���[�h�ɑJ�ڂ��邽�߂̍ē˓��_��ݒ� */
	stmdb r12!,{r0-r3}		/* �U�� R12,LR,PC,xPSR��ۑ��BPC��xPSR�ȊO�͂ł���߂ł��� */
	stmdb r12!,{r0-r3}		/* �U�� r0,1,2,3,��ۑ��B�S���ł���߂ł��� */
	msr psp,r12				/* PSP�ɐV�����l��ݒ� */

/*
�@* �����ł̃X�^�b�N�\���͈ȉ��̂Ƃ���
�@*
 *  [��] <- PSP (R13)
 *  
 *  [xPSR]    +60
 *  [ PC ]    +56
 *  [ LR ]    +52
 *  [ R12]    +48
 *  [ R3 ]    +44
 *  [ R2 ]    +40
 *  [ R1 ]    +36
 *  [ R0 ] <- �Â�PSP
 *  [xPSR]    +28
 *  [ PC ]    +24 : ret_int_0
 *  [ LR ]    +20
 *  [ R12]    +16
 *  [ R3 ]    +12
 *  [ R2 ]    + 8
 *  [ R1 ]    + 4
 *  [ R0 ] <- �V����PSP
 *  
 * �Â�PSP��艺�̗̈�́A�^�X�N���[�h�ɑJ�ڂ��邽�߂̋U�f�[�^�ł���B
 */
	bx lr					/* ���荞�݂���̕��A�B���͎��̔Ԓn�ɐi�ނ���*/
ret_int_0:					/* Thread mode ���荞�݋֎~�B PSP */
/*
�@* �����ł̃X�^�b�N�\���͈ȉ��̂Ƃ���
�@*
 *  [xPSR]    +28
 *  [ PC ]    +24
 *  [ LR ]    +20
 *  [ R12]    +16
 *  [ R3 ]    +12
 *  [ R2 ]    +8
 *  [ R1 ]    +4
 *  [ R0 ] <- PSP(R13)
 */
	ldr r0,=reqflg			/* &reqflg */
	ldr r1,[r0]				/* reqflg���擾 */
	tst r1,r1				/* reqflg == FLASE? */
	beq ret_int_2			/* FALSE->���荞�݂���A�� */
	mov r1,#0				/* TRUE������ */
	str r1,[r0]				/* reqflg = FLALSE */
	ldr r0,=runtsk			/* &runtsk */
	ldr r1,[r0]				/* r0 <- runtsk */
	ldr r2,=enadsp
	ldr r3,[r2]				/* enadsp���擾 */
	tst r3,r3				/* enadsp�@== FALSE? */
	beq	ret_int_1			/*     then ret_int_1 */
	ldr r2,=schedtsk
	ldr r3,[r2]				/* schedtsk */
	cmp r1,r3				/* runtsk == schedtsk ? */
	beq	ret_int_1			/*     then ret_int_1 */
							/* enadsp��TRUE�ŁAruntsk != schedtsk ������ */
	ldr r0,=dispatch+1
	blx r0					/* dispatch() */
    b ret_int_2				/* ���荞�݂���߂� */
ret_int_1:					/* tex�̏��� */
	ldr r0,=runtsk					/* &runtsk */
	ldr r1,[r0]						/* runtsk */
	ldrb r2, [r1,#TCB_enatex]		/* runtsk->enatex ����^�X�N��O��Ԃ��擾 */
	tst	r2, #(1<<TCB_enatex_bit)	/* enatex�̓Z�b�g����Ă��邩 */
	beq ret_int_2					/* enatex �� FALSE �Ȃ烊�^�[�� */
	ldr r2, [r1,#TCB_texptn]		/* runtsk->texptn */
	tst r2,r2						/* texptn �� 0 ��  */
	beq ret_int_2					/* texptn �� 0 �Ȃ烊�^�[�� */
	ldr r1, =call_texrtn +1
	blx r1							/* call_texrtn() */

ret_int_2:					/* ���荞�݂���߂�B�������A����Thread Mode�Ȃ̂ŁAEXC_RETRUN�͎g��Ȃ� */
	ldr r1,[sp,#28]			/* xPSR */
	ldr r2,[sp,#24]			/* PC */
	ldr r3,[sp,#20]			/* LR */
	
	str r2,[sp,#28]         /* PC */
	str r3,[sp,#24]			/* LR */
	str r1,[sp,#20]			/* xPSR */
/*
�@* �����ł̃X�^�b�N�\���͈ȉ��̂Ƃ���
�@*
 *  [ PC ]    +28
 *  [ LR ]    +24
 *  [xPSR]    +20
 *  [ R12]    +16
 *  [ R3 ]    +12
 *  [ R2 ]    +8
 *  [ R1 ]    +4
 *  [ R0 ] <- PSP (R13)
 */
	
	pop.w {r0-r3,r12,lr}	/* LR�ɂ͋�xPSR���������� */
	msr xpsr,lr				/* ��xPSR�𕜋A */
	pop {lr}				/* LR�𕜋A */
	cpsie	i				/* CPU�A�����b�N (���荞�݋���) */
	pop {pc}				/* �߂�Ԓn�ɔ�� */

/*
 *  �������ԑ҂�
 */
	.globl _sil_dly_nse
_sil_dly_nse:
	subs r0, #SIL_DLY_TIM1	/* D0 ���� SIL_DLY_TIM1 ������ */
	bgt _sil_dly_nse_1		/* ���ʂ� 0 �ȉ��Ȃ烊�^�[�� */
	bx lr
_sil_dly_nse_1:
	subs r0, #SIL_DLY_TIM2	/* D0 ���� SIL_DLY_TIM2 ������ */
	bgt _sil_dly_nse_1		/* ���ʂ� 0 ���傫����΃��[�v */
	bx lr