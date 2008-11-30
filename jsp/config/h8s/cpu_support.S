/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

#define _MACRO_ONLY

#include "jsp_kernel.h"
#include "offset.h"

	.h8300s
	.text
	.align 2

/*
 *  �^�X�N�f�B�X�p�b�`��
 *  �Edispatch �́A�����݃l�X�g�J�E���^ = 0�ACPU���b�N��ԁi�����݋֎~��ԁj��
 *    �Ăяo���Ȃ���΂Ȃ�Ȃ��B
 *  �Eexit_and_dispatch �́C�����݃l�X�g�J�E���^ = 0�ACPU���b�N��ԁi�����݋֎~
 *    ��ԁj�ŌĂяo���̂������ł���B�������A�J�[�l���N�����ɑΉ����邽�߁C
 *    �����݃l�X�g�J�E���^ = 1 �ŌĂяo�����ꍇ�ɂ��Ή����Ă���B
 */

	.global _dispatch
	.global	_exit_and_dispatch

/* �^�X�N�f�B�X�p�b�`���𖾎��I�ɌĂяo���� */
_dispatch:
	push.l	er2			/* er2�`6 ��ۑ� */
	push.l	er3
	push.l	er4
	push.l	er5
	push.l	er6

	mov.l	@_runtsk, er0		/* er0 = runtsk */
	mov.l	sp, @(TCB_sp, er0)	/* runtsk->sp = sp
					   (�^�X�N�X�^�b�N�|�C���^��ۑ�) */
	mov.l	#dispatch_r, er1
	mov.l	er1, @(TCB_pc, er0)	/* runtsk->pc = dispatch_r
					   (�^�X�N�̎��s�ĊJ�Ԓn��ۑ�) */

	bra     dispatcher_1

/* ���ݎ��s���̃R���e�L�X�g���̂ĂāA�^�X�N�f�B�X�p�b�`�����Ăяo���� */
_exit_and_dispatch:
	sub.l	er0, er0
	mov.l	er0, @_intnest		/* �����݃l�X�g�J�E���^ = 0 */

dispatcher_1:
	/* �����ɂ� CPU���b�N�i���荞�݋֎~�j�ŗ��邱�� */
	mov.l	@_schedtsk, er0		/* er0 = schedtsk */
	or.l	er0, er0		/* ���蕔�� (���s�\�^�X�N�̗L��) */
	beq	dispatcher_2		/* schedtsk �������Ȃ�A�����ݑ҂��� */

	mov.l	er0, @_runtsk		/* runtsk = er0 (= schedtsk)
					   (�^�X�N�X�C�b�`�̎��s) */
	mov.l	@(TCB_sp, er0), sp	/* sp = runtsk->sp
					   (�^�X�N�X�^�b�N�|�C���^����) */
	mov.l	@(TCB_pc, er0), er0	/* er0 = runtsk->pc
					   (�^�X�N�̎��s�ĊJ�Ԓn�̎擾) */
					/* ���s�ĊJ�Ԓn�͈ȉ���3�ʂ�
					   �E�f�B�X�p�b�`���̏o��  dispatch_r
					   �E�����݁^��O�̏o��    ret_int_r
					   �E�^�X�N�N������        activate_r
					 */

	jmp	@er0			/* �^�X�N�̎��s�ĊJ�Ԓn�փW�����v */

	/*
	 *  ���s���ׂ��^�X�N�������܂ő҂���
	 *    �����ŃR���e�L�X�g��؂芷����̂́C
	 *      �E�����Ŕ������銄���ݏ����ɂǂ̃X�^�b�N���g�����Ƃ������̉���
	 *      �E�����݃n���h�����ł̃^�X�N�f�B�X�p�b�`�̖h�~
	 *    �Ƃ�����̈Ӗ�������D
	 */ 
dispatcher_2:
	sub.l	er0, er0
	mov.l	er0, @_runtsk		/* runtsk = NULL */

	mov.l	#STACKTOP, sp		/* �����݃X�^�b�N�ɐؑ� */

	sub.l	er0, er0
	inc.l	#1, er0
	mov.l	er0, @_intnest		/* �����݃l�X�g�J�E���^ = 1 */

dispatcher_2_enable_interrupt:
#ifdef SUPPORT_CHG_IPM
	ldc.b	@_task_intmask, exr	/* unlock_cpu����(�����݋���) */
#else /* SUPPORT_CHG_IPM */
	ldc.b	#0, exr			/* unlock_cpu����(�����݋���) */
#endif /* SUPPORT_CHG_IPM */
	sleep				/* �����ݑ҂� */
	ldc.b	#MAX_IPM, exr		/* lock_cpu ���� (�����݋֎~) */

	mov.l	@_reqflg, er0		/* er0 = reqflg  */
	or.l	er0, er0		/* ���蕔�� (�f�B�X�p�b�`�v��) */
	beq	dispatcher_2_enable_interrupt
					/* �f�B�X�p�b�`�v�����������A
					   ���[�v�̐擪�փW�����v */

	sub.l	er0, er0		/* er0 = 0 (= NULL) */
	mov.l	er0, @_reqflg		/* reqflg = NULL (reqflg���N���A) */
	mov.l	er0, @_intnest		/* �����݃l�X�g�J�E���^ = 0 */

	bra	dispatcher_1		/* �f�B�X�p�b�`�����փW�����v */

/*
 *  �^�X�N�R���e�L�X�g�ւ̕��A�����i�f�B�X�p�b�`���o�������j
 */
dispatch_r:
	pop.l	er6			/* er2�`6 �𕜌� */
	pop.l	er5
	pop.l	er4
	pop.l	er3
	pop.l	er2

	/* �^�X�N��O�����v���̃`�F�b�N */
	mov.l	@_runtsk, er0		/* er0 = runtsk */

	mov.b	@(TCB_enatex, er0), r1l	/* r1l = runtsk->enatex */
	btst	#TCB_enatex_bit, r1l	/* TCB_enatex == 1 ���H */
	beq	dispatch_r_1		/* �^�X�N��O�����֎~�̎��A�W�����v */

	mov.l	@(TCB_texptn, er0), er1	/* er1 = runtsk->texptn */
	beq	dispatch_r_1		/* �^�X�N��O�v�����������A�W�����v */

	jmp	@_call_texrtn		/* �^�X�N��O�������[�`���̌ďo */

dispatch_r_1:
        rts				/* dispatch �Ăяo�����֖߂� */

/*============================================================================*/

/*
 *  �����݃n���h���o��������
 *    �����ɗ���Ƃ��́ACPU ���b�N��ԂŁA
 *      er0(r0l) : �����ݗv����̊��荞�݃��x���̒l
 *      er1      : �����݃n���h���̃A�h���X
 *    ���������Ă���B�ier0, er1 �̓X�^�b�N�ɕۑ��ς݁j
 */

	.global ret_main
	.global	_ret_int_r	/* monitor ���� */

ret_main:
	push.l	er2			/* �c��̃��W�X�^��ۑ� */
	push.l  er3
	push.l	er4
	push.l	er5
	push.l	er6
		/* ����������ƁAH8S/2600 �ɂ����� macl, mach ���W�X�^�̕ۑ���
		   �����ōs���K�v�����邩���m��܂���B�i���A�������l�B�j
		   �J�����̐����ɂ��A�m�F�ł��Ă��܂���B */

	mov.l	@_intnest, er2		/* er2 = intnest */
	mov.l	er2, er3		/* er3(= er2)�́A���̏����ŗ��p����B */
	inc.l	#1, er2			/* �����݃l�X�g�J�E���^ += 1 */
	mov.l	er2, @_intnest

	or.l	er3, er3		/* ���蕔��
					   (�����ݔ������̃R���e�L�X�g) */
	beq	first_exception		/* ���i�̊����݂̎��A�W�����v */

/* ���d�����݂̏��� */
multipul_exception:
	ldc.b	r0l, exr		/* (���݂̊����݃��x���ȏ�)�����݋��� */

	jsr	@er1			/* �����݃n���h���ďo */

	ldc.b	#MAX_IPM, exr		/* lock_cpu ���� (�����݋֎~) */

	mov.l	@_intnest, er0		/* er0 = intnest */
	dec.l	#1, er0			/* �����݃l�X�g�J�E���^ -= 1 */
	mov.l	er0, @_intnest

	jmp	ret_to_task_int

/* ���i�̊����݂̏ꍇ */
first_exception:

	mov.l	sp, er2			/* er2 = �^�X�N�X�^�b�N�|�C���^ */
	mov.l	#STACKTOP, sp		/* �����݃X�^�b�N�ɐؑ� */
	push.l	er2			/* �^�X�N�X�^�b�N�|�C���^��
					   �����݃X�^�b�N�ɑޔ� */

	ldc.b	r0l, exr		/* (���݂̊����݃��x���ȏ�)�����݋��� */

	jsr	@er1			/* �����݃n���h���ďo */

	ldc.b	#MAX_IPM, exr		/* lock_cpu ���� (�����݋֎~) */

	mov.l	@sp, sp			/* �^�X�N�X�^�b�N�ɐؑ� */

	mov.l	@_intnest, er0		/* er0 = intnest */
	dec.l	#1, er0			/* �����݃l�X�g�J�E���^ -= 1 */
	mov.l	er0, @_intnest

	/* �f�B�X�p�b�`�v��/�^�X�N��O�����v��(reqflg)�̔��� */
	mov.l	@_reqflg, er0		/* er0 = reqflg */
	or.l	er0, er0		/* ���蕔�� */
	bne	occur_dispatch_or_tsk_exception
					/* reqflg = TRUE �̎��A�W�����v */
					/* ���L�̏������AOR �Ő����̎�
					   �E�x���f�B�X�p�b�`������
					   �E�^�X�N��O�����v�������� */

	/* ���W�X�^�̕��� */
ret_to_task_int:
	pop.l	er6			/*  +0:er6 */
	pop.l	er5			/*  +4:er5 */
	pop.l	er4			/*  +8:er4 */
	pop.l	er3			/* +12:er3 */
	pop.l	er2			/* +16:er2 */
	pop.l	er1			/* +20:er1 */
	pop.l	er0			/* +24:er0 */
					/* +28:EXR -> EXR_offset = 28 */
	rte				/* �����ݔ����ꏊ�ɖ߂� */
			/* EXR �̕���(unlock_cpu ����)�̓n�[�h�E�F�A���s���B */

/*
 *  �����ݏo���������ɂ�����x���f�B�X�p�b�`/�^�X�N��O�Ɋւ��鏈��
 */
occur_dispatch_or_tsk_exception:

/* �����ݔ������̔��� */
	mov.b	@(EXR_offset, sp), r0l	/* r01 = �X�^�b�N���EXR */
	and.b	#EXR_I_MASK, r0l	/* r01 = �X�^�b�N��̊��荞�݃}�X�N */

#ifdef SUPPORT_CHG_IPM			/* r1l = �^�X�N�R���e�L�X�g��
					         �����݃}�X�N */
	mov.b	@_task_intmask, r1l
#else /* SUPPORT_CHG_IPM */
	mov.b	#0, r1l
#endif /* SUPPORT_CHG_IPM */

	cmp.b	r0l, r1l		/* ���蕔�� (�����ݔ�����) */

	bne	ret_to_task_int		/* �����ݔ����ꏊ���A�^�X�N�R���e�L�X�g
					   �łȂ����A�W�����v */
		/* �_���I�ȕ����́Ato_int_routine �ɂ����� SUPPORT_CHG_IPM
		   �}�N���ň͂܂ꂽ���̒���ł���B�R�X�g�̖�肩��A�{���I
		   �ɓ����Ȃ̂ŁAret_to_task_int �ƋL�q�����B */

	sub.l	er0, er0		/* er0 = NULL (= 0) */
	mov.l	er0, @_reqflg		/* reqflg = NULL (reqflg���N���A) */

/* �x���f�B�X�p�b�`�Ɋւ��锻�� */
	/* �f�B�X�p�b�`�֎~/���̔��� */
	mov.l	@_enadsp, er0		/* er0 = enadsp */
	or.l	er0, er0		/* ���蕔�� */
	beq	to_tsk_exc		/* �f�B�X�p�b�`�֎~�Ȃ�W�����v */

	/* �X�P�W���[�����O���ʂ̔��� */
	mov.l	@_runtsk, er0		/* er0 = runtsk	*/
	mov.l	@_schedtsk, er1		/* er1 = schedtsk */
	cmp.l	er0, er1		/* ���蕔�� */
	beq	to_tsk_exc		/* runtsk == schedtsk �Ȃ�W�����v */

/* �x���f�B�X�p�b�`�����������ꍇ */
occur_dispatch:
#ifdef H8S_2600				/* H8S_2600�̓R���p�C���I�v�V������` */
	/* �Ϙa���W�X�^�̑ޔ� */
	/* er0 �͉��L�ɂė��p����̂Ŕj��ł��Ȃ� */
	stmac	mach, er1
	push.l	er1
	stmac	macl, er1
	push.l	er1
#endif /* H8S_2600 */

	mov.l	sp, @(TCB_sp, er0)	/* runtsk->sp = sp
					   (�^�X�N�X�^�b�N�|�C���^��ۑ�) */

	mov.l	#ret_int_r, er1
	mov.l	er1, @(TCB_pc, er0)	/* runtsk->pc = ret_int_r
					   (�^�X�N�̎��s�ĊJ�Ԓn��ۑ�) */

	jmp	dispatcher_1		/* �f�B�X�p�b�e���ďo */

/* �x���f�B�X�p�b�`�ɂ���ăf�B�X�p�b�`�����^�X�N�R���e�L�X�g�̊J�n�n�_ */
_ret_int_r:	/* monitor ���� */
ret_int_r:

#ifdef H8S_2600				/* H8S_2600�̓R���p�C���I�v�V������` */
	/* �Ϙa���W�X�^�̕��� */
	pop.l	er0
	ldmac	er0, macl
	pop.l	er0
	ldmac	er0, mach
#endif /* H8S_2600 */

/* �x���f�B�X�p�b�`���������Ȃ������ꍇ�̊J�n�n�_ */

/* �^�X�N��O�����Ɋւ��锻�� */
to_tsk_exc:
	mov.l	@_runtsk, er0		/* er0 = runtsk */

	/* �^�X�N��O�����֎~/���̔��� */
	mov.b	@(TCB_enatex, er0), r1l	/* r1l = runtsk->enatex */
	btst	#TCB_enatex_bit, r1l	/* TCB_enatex == 1 ���H */
	beq	to_int_routine		/* �^�X�N��O�����֎~�̎��A�W�����v */

	/* �^�X�N��O�v���̗L���̔��� */
	mov.l	@(TCB_texptn, er0), er1	/* er1 = runtsk->texptn */
	beq	to_int_routine		/* �^�X�N��O�v�����������A�W�����v */

	jsr	@_call_texrtn		/* �^�X�N��O�������[�`���̌ďo */

to_int_routine:

/* chg_ipm �̘b�́A�x���f�B�X�p�b�`��̃^�X�N�̖��Ȃ̂ŁA�����ɋL�q����B */
#ifdef SUPPORT_CHG_IPM
	/* ���荞�݃n���h���I�����ɕʂ̃^�X�N�փX�C�b�`�����Ƃ��ɁA
	   ���荞�݃}�X�N�𐮍������鏈�� */
	/* ��F�f�B�X�p�b�`�����F
		�^�X�N�`->���荞�݃n���h��->�^�X�N�a->�^�X�N�`
	       ����F
		���̎��Ƀ^�X�N�a���ŁA�����݃}�X�N�̕ύX���s��ꂽ�ꍇ�ɁA
		���̊����݃}�X�N�Ɋւ�������A�^�X�N�a����^�X�N�`�ւ�
		�����p�����߂ɕK�v�B*/
	mov.b	@_task_intmask, r1l	/* r1l = task_intmask */
		/* task_intmask�FCHG_IPM �ɂ��ύX���ꂽ�\���̂���
				 �����݃}�X�N */
	mov.b	r1l, @(EXR_offset, sp)
		/* �X�^�b�N��� EXR �ɏ㏑��������B */
		/* ���������FEXR �̃g���[�X�r�b�g T �͕ۑ�����Ȃ��B */
#endif /* SUPPORT_CHG_IPM */

	jmp	ret_to_task_int		/* �^�X�N�R���e�L�X�g�ւ̕��A */

/*============================================================================*/

/*
 *  �^�X�N�N������
 */

	.global _activate_r

_activate_r:
	/* �����ɗ���Ƃ��́ACPU���b�N�ɂȂ��Ă���B */

	mov.l	#_ext_tsk, er0
	push.l	er0				/* �^�X�N����̖߂�Ԓn��ݒ� */

	/* �^�X�N�֌W�̐ݒ菀�� */
	mov.l	@_runtsk, er2			/* er2 = runtsk */
	mov.l	@(TCB_tinib, er2), er2		/* er2 = runtsk->tinib */

	/* �^�X�N�N���Ԓn�̐ݒ� */
	mov.l	@(TINIB_task, er2), er1		/* er1 = runtsk->tinib->task */

	/* �^�X�N�ւ̈����i�g�����j�ݒ� */
	mov.l	@(TINIB_exinf, er2), er0	/* er0 = runtsk->tinib->exinf */

#ifdef SUPPORT_CHG_IPM
	ldc.b	@_task_intmask, exr		/* unlock_cpu����(�����݋���) */
#else /* SUPPORT_CHG_IPM */
	ldc.b	#0, exr				/* unlock_cpu����(�����݋���) */
#endif /* SUPPORT_CHG_IPM */

	jmp	@er1				/* �^�X�N�N�� */

/*============================================================================*/
/*  ���ʃh�L�������g�ɂ͂Ȃ��A�Ǝ��̕���  */

/*
 *  no_reg_exception()
 *    CPU��O�Ƃ��ēo�^����Ă��Ȃ���O����������ƌĂяo�����B
 *    ��O�������������_�� PC�Aer0�`7 ���o�͂��ăJ�[�l�����~����B
 */
	.global no_reg_exception

no_reg_exception:

	push.l	er0			/* er0�`6��ۑ�	*/
	push.l	er1
	push.l	er2
	push.l	er3
	push.l	er4
	push.l	er5
	push.l	er6

	mov.l	sp, er0			/* �����ɃX�^�b�N�|�C���^��ݒ�	*/
	/* CPU��O�������_�� SP �́A
	   34(= 4*7(er) + 1(exr) + 1(�\��) + 1(ccr) + 3(pc) ) ������ */

	jsr	@_cpu_experr		/* cpu_experr()�̌Ăяo�� */
