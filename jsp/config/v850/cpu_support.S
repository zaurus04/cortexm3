/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005 by Freelines CO.,Ltd
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
 *  @(#) $Id: cpu_support.S,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[�� �A�Z���u�����ꕔ�iV850ES�p�j
 */

#define	_MACRO_ONLY
#include "v850asm.inc"
#include "jsp_kernel.h"
#include "offset.h"

/*
 *  �^�X�N�f�B�X�p�b�`��
 */
Function	__kernel_dispatch

	/*
	 * �R���e�L�X�g�̑ޔ� 
	 */
	Push	ep
	addi	-120, sp, sp
	mov	sp, ep
	sst.w	r1, 116[ep]
	sst.w	r2, 112[ep]
	sst.w	r3, 108[ep]
	sst.w	r4, 104[ep]
	sst.w	r5, 100[ep]
	sst.w	r6,  96[ep]
	sst.w	r7,  92[ep]
	sst.w	r8,  88[ep]
	sst.w	r9,  84[ep]
	sst.w	r10, 80[ep]
	sst.w	r11, 76[ep]
	sst.w	r12, 72[ep]
	sst.w	r13, 68[ep]
	sst.w	r14, 64[ep]
	sst.w	r15, 60[ep]
	sst.w	r16, 56[ep]
	sst.w	r17, 52[ep]
	sst.w	r18, 48[ep]
	sst.w	r19, 44[ep]
	sst.w	r20, 40[ep]
	sst.w	r21, 36[ep]
	sst.w	r22, 32[ep]
	sst.w	r23, 28[ep]
	sst.w	r24, 24[ep]
	sst.w	r25, 20[ep]
	sst.w	r26, 16[ep]
	sst.w	r27, 12[ep]
	sst.w	r28,  8[ep]
	sst.w	r29,  4[ep]
	sst.w	r31,  0[ep]

	/* �X�^�b�N�Ǝ��̋N���Ԓn��ۑ� */
	Lea	__kernel_runtsk, ep
	sld.w	0[ep], ep
	sst.w	sp, TCB_sp[ep]
	Lea	dispatch_r, r10
	sst.w	r10, TCB_pc[ep]
	stsr	psw, r10
	sst.w	r10, TCB_psw[ep]

	/*
	 * ���̃^�X�N�̏��� __kernel_dispatch_1
	 *  �����͊��荞�݋֎~��Ԃŗ���K�v������B
	 */
Label	__kernel_dispatch_1
	/* runtsk = schedtsk */
	Lea	__kernel_schedtsk, r10
	ld.w	0[r10], r10
	Lea	__kernel_runtsk, r11
	st.w	r10, 0[r11]
	cmp	r10,r0
	bne	1f

	/*
	 * �N�����ׂ��^�X�N�͂Ȃ�...�A�C�h�����[�v
	 */

	/* ���荞�݃X�^�b�N�ɐ؂�ւ� */
	Lea	STACKTOP, sp
	/* intnest���P�ɂ��� */
	mov	r0, r10
	add	1, r10
	Lea	_intnest, r11
	st.w	r10, 0[r11]

	/* ���荞�ݑ҂� */
	ei
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	di

	/* intnest���N���A���� */
	Lea	_intnest, r10
	st.w	r0, 0[r10]

	br	__kernel_dispatch_1

1:
	/* �X�^�b�N�Ǝ��̋N���Ԓn�𕜋A */
	mov	r10, ep
	sld.w	TCB_pc[ep], r31
	sld.w	TCB_sp[ep], sp
	sld.w	TCB_psw[ep], r10
	ldsr	r10, psw
	jmp	r31

	/* �f�B�X�p�b�`���̕��A���[�`�� */
Label	dispatch_r
	Lea	__kernel_runtsk, r10
	ld.w	0[r10], r10
	ld.w	TCB_enatex[r10], r11
	tst1	TCB_enatex_bit, 0[r11]
	be	1f
	ld.w	TCB_texptn[r10], r11
	cmp	r0, r11
	be	1f

	/* �^�X�N��O */
	jarl	__kernel_calltex, r31
1:
	mov	sp, ep
	sld.w	116[ep], r1
	sld.w	112[ep], r2
	sld.w	108[ep], r3
	sld.w	104[ep], r4
	sld.w	100[ep], r5
	sld.w	 96[ep], r6
	sld.w	 92[ep], r7
	sld.w	 88[ep], r8
	sld.w	 84[ep], r9
	sld.w	 80[ep], r10
	sld.w	 76[ep], r11
	sld.w	 72[ep], r12
	sld.w	 68[ep], r13
	sld.w	 64[ep], r14
	sld.w	 60[ep], r15
	sld.w	 56[ep], r16
	sld.w	 52[ep], r17
	sld.w	 48[ep], r18
	sld.w	 44[ep], r19
	sld.w	 40[ep], r20
	sld.w	 36[ep], r21
	sld.w	 32[ep], r22
	sld.w	 28[ep], r23
	sld.w	 24[ep], r24
	sld.w	 20[ep], r25
	sld.w	 16[ep], r26
	sld.w	 12[ep], r27
	sld.w	  8[ep], r28
	sld.w	  4[ep], r29
	sld.w	  0[ep], r31
	addi	120, ep, sp
	Pop     ep
	jmp	r31

/*
 *  �^�X�N�N��������
 */
Function	__kernel_activate_r

	Lea	__kernel_runtsk, ep
	ld.w	0[ep], ep
	ld.w	TCB_tinib[ep], ep
	ld.w	TINIB_exinf[ep], r6
	ld.w	TINIB_task[ep], r10
	Lea	_ext_tsk, r31
	
	ei

	jmp	r10

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`
 *    CPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ�
 */
Function	__kernel_exit_and_dispatch
	di
	Lea	_intnest, r10
	st.w	r0, 0[r10]
	br	__kernel_dispatch_1


.extern _InterruptHandlerEntry
.extern __kernel_runtsk
.extern __kernel_calltex

/*
 * �����݃n���h��
 */
Function	vector_handler

	/* ��Ɨ̈�̍쐬 */
	addi	-16,  sp, sp
	st.w	 ep, 12[sp]
	st.w	r10,  8[sp]
	st.w	r11,  4[sp]
	st.w	r12,  0[sp]

	/*
	 * �n���h���N���Ԓn�̓ǂݏo��
	 *    R10 : �n���h���̔Ԓn
	 */
	stsr	ecr, r10
	shr	2, r10
	add	-4, r10
	Lea	_InterruptHandlerEntry, r11
	add	r10, r11
	ld.w	0[r11], r10

	/* �n���h����������Α��I�� */
	cmp	r0,r10
	bne	1f

	/* ���荞�݃n���h�����o�^����Ă��Ȃ��ꍇ�F
	   ������r6��j�󂵂āA�b�̊֐����Ă�ł��邩�瑼�̃��W�X�^���j��
	   �����\�����������A�����Ă��Acpu_experr()�̒���halt������
	   ���邩�������[�v���Ă���̂ł��̊֐�����͖߂��Ă��Ȃ��B�߂���
	   ����悤�ɂ������Ȃ瑼�̃��W�X�^���ۑ������ق����悢 */
	stsr	ecr, r6
	jarl	_cpu_experr, r31
	br	end_handler

1:
	/*
	 * �c��̃��W�X�^�ޔ� 
	 */
	addi	-116, sp, ep
	mov	ep, sp			/* �X�^�b�N�ɔ��f */
	sst.w	r1, 112[ep]
	sst.w	r2, 108[ep]
	sst.w	r3, 104[ep]
	sst.w	r4, 100[ep]
	sst.w	r5,  96[ep]
	sst.w	r6,  92[ep]
	sst.w	r7,  88[ep]
	sst.w	r8,  84[ep]
	sst.w	r9,  80[ep]
	sst.w	r13, 76[ep]
	sst.w	r14, 72[ep]
	sst.w	r15, 68[ep]
	sst.w	r16, 64[ep]
	sst.w	r17, 60[ep]
	sst.w	r18, 56[ep]
	sst.w	r19, 52[ep]
	sst.w	r20, 48[ep]
	sst.w	r21, 44[ep]
	sst.w	r22, 40[ep]
	sst.w	r23, 36[ep]
	sst.w	r24, 32[ep]
	sst.w	r25, 28[ep]
	sst.w	r26, 24[ep]
	sst.w	r27, 20[ep]
	sst.w	r28, 16[ep]
	sst.w	r29, 12[ep]
	sst.w	r31,  8[ep]
	stsr	eipc,   r6		/* ���d�����ݑ΍� */
	sst.w	r6 ,  4[ep]
	stsr	eipsw,  r6
	sst.w	r6 ,  0[ep]

	/* ���d���荞�݃`�F�b�N�ƃl�X�g�J�E���^���C���N�������g */
	Lea	_intnest, r11
	ld.w	0[r11], r6
	add	1, r6
	st.w	r6, 0[r11]
	cmp	1, r6
	ble	1f

	/* ���d������...���łɊ��荞�݃X�^�b�N�ɂȂ��Ă��� */
	jr	2f
1:
	/* ���d�����݂łȂ� */
	/* �X�^�b�N�؂�ւ� */
	mov	sp, r11
	Lea	STACKTOP, sp
	Push	r11

	Lea	end_int, r31
	/* ���荞�݋��� */
	ei
	/* �n���h���N�� */
	jmp	r10

	/*
	 * ���荞�݂���̕��A����
	 */
Label	end_int
	/* ���荞�݋֎~ */
	di

	/* �X�^�b�N�̕��A */
	ld.w	0[sp], sp

	/* intnest���f�B�N�������g */
	Lea	_intnest, r11
	ld.w	0[r11], r10
	mov	1, r11
	sub	r11, r10
	Lea	_intnest, r11
	st.w	r10, 0[r11]

	/* 
	 * �^�X�N�f�B�X�p�b�`���v�������邩�H
	 */
	Lea	__kernel_reqflg, r10
	ld.w	0[r10], r11
	cmp	r0, r11
	bz	recover_from_int
	st.w	r0, 0[r10]
	jr	ret_int

2:
	Lea	end_int_nest, r31
	/* ���荞�݋��� */
	ei
	/* �n���h���N�� */
	jmp	r10

	/*
	 * ���荞�݂���̕��A����
	 */
Label	end_int_nest
	/* ���荞�݋֎~ */
	di

	/* intnest���f�B�N�������g */
	Lea	_intnest, r11
	ld.w	0[r11], r10
	mov	1, r11
	sub	r11, r10
	Lea	_intnest, r11
	st.w	r10, 0[r11]

recover_from_int:
	/*
	 * ���W�X�^���A 
	 */
	mov	sp, ep

	sld.w	112[ep], r1
	sld.w	108[ep], r2
	sld.w	104[ep], r3
	sld.w	100[ep], r4
	sld.w	 96[ep], r5
	sld.w	 92[ep], r6
	sld.w	 88[ep], r7
	sld.w	 84[ep], r8
	sld.w	 80[ep], r9
	sld.w	 76[ep], r13
	sld.w	 72[ep], r14
	sld.w	 68[ep], r15
	sld.w	 64[ep], r16
	sld.w	 60[ep], r17
	sld.w	 56[ep], r18
	sld.w	 52[ep], r19
	sld.w	 48[ep], r20
	sld.w	 44[ep], r21
	sld.w	 40[ep], r22
	sld.w	 36[ep], r23
	sld.w	 32[ep], r24
	sld.w	 28[ep], r25
	sld.w	 24[ep], r26
	sld.w	 20[ep], r27
	sld.w	 16[ep], r28
	sld.w	 12[ep], r29
	sld.w	  8[ep], r31
	sld.w	  4[ep], r10
	ldsr	    r10, eipc
	sld.w	  0[ep], r10
	ldsr	    r10, eipsw

	addi	116, ep, sp


end_handler:
	/*
	 * ��Ɨ̈�̕��A
	 */
	addi	 16, sp, sp
	ld.w	 -4[sp], ep
	ld.w	 -8[sp], r10
	ld.w	-12[sp], r11
	ld.w	-16[sp], r12
	reti


/*
 * ���荞�݂ɂƂ��Ȃ��^�X�N�f�B�X�p�b�`�̔���
 */
ret_int:
	/* �f�B�X�p�b�`�֎~�H */
	Lea	__kernel_enadsp, r10
	ld.w	0[r10], r10
	cmp	r0, r10
	be	ret_int_r

	/* �^�X�N�؂�ւ��̕K�v�����邩�H */
	Lea	__kernel_schedtsk, r10
	ld.w	0[r10], r10
	Lea	__kernel_runtsk, r11
	ld.w	0[r11], r11
	cmp	r10,r11
	be	ret_int_r

	/* TCB�̒��g���C�����ĕ��A����ݒ� */
	mov	ep, r11
	Lea	__kernel_runtsk, ep
	sld.w	0[ep], ep			/* ep = _kernel_runtsk */

	sst.w	sp, TCB_sp[ep]
	Lea	ret_int_r, r10
	sst.w	r10, TCB_pc[ep]
	stsr	psw, r10
	sst.w	r10, TCB_psw[ep]
	mov	r11, ep

	/* �^�X�N�f�B�X�p�b�`���� */
	stsr	eipsw, r10
	ori	0x20, r10, r10
	ldsr	r10, eipsw
	Lea	__kernel_dispatch_1, r10
	ldsr	r10, eipc
	reti

ret_int_r:
	di

	Lea	__kernel_runtsk, r10
	ld.w	0[r10], r10
	ld.w	TCB_enatex[r10], r11
	tst1	TCB_enatex_bit, 0[r11]
	be	1f
	ld.w	TCB_texptn[r10], r11
	cmp	r0, r11
	be	1f

	/* �^�X�N��O */
	jarl	__kernel_calltex, r31
1:
	/* �������Ƃ̕��A�����֔�΂� */
	jr	recover_from_int

/*
 * CPU���b�N��Ԃ̎擾
 *
 *   �����݋֎~�Ȃ�CPU���b�N���
 */
Function	_sense_lock
	stsr	psw, r10
	shr	5, r10
	andi	1, r10, r10
	jmp	r31

