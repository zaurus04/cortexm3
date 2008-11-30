/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006 by Monami Software Limited Partnership, JAPAN	
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: cpu_support.S,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[�� �A�Z���u�����ꕔ�iM32R�p�j
 */

#define	_MACRO_ONLY

#include <cpu_rename.h>

#include <m32rasm.inc>
#include <s_services.h>

#include "offset.h"

#define _trap_handler_0 _kernel__trap_handler_0
#define _trap_handler_1 _kernel__trap_handler_1
#define _trap_handler_2 _kernel__trap_handler_2
#define _trap_handler_3 _kernel__trap_handler_3
#define _trap_handler_4 _kernel__trap_handler_4
#define _trap_handler_5 _kernel__trap_handler_5
#define _trap_handler_6 _kernel__trap_handler_6
#define _trap_handler_7 _kernel__trap_handler_7
#define _trap_handler_8 _kernel__trap_handler_8
#define _trap_handler_9 _kernel__trap_handler_9
#define _trap_handler_10 _kernel__trap_handler_10
#define _trap_handler_11 _kernel__trap_handler_11
#define _trap_handler_12 _kernel__trap_handler_12
#define _trap_handler_13 _kernel__trap_handler_13
#define _trap_handler_14 _kernel__trap_handler_14
#define _trap_handler_15 _kernel__trap_handler_15

	.extern	_kernel_runtsk
	.extern	_kernel_schedtsk
	.extern	_kernel_reqflg
	.extern _kernel_enaflg
	.extern	InterruptHandlerEntry
	.extern	ExceptionHandlerEntry
	.extern	ext_tsk
		
/*
 *  EIT�x�N�^�G���g���̒�`
 */
	.section ".vector","ax"
	.global	  reset
	.extern   start

	.balign 0x10
reset:
	bra		start

	.balign 0x10
vector_entry_SBI:
    /* 
	 *  �V�X�e���u���[�N������
	 */
	bra 	vector_entry_SBI

	.balign 0x10
vector_entry_RIE:
    /* 
	 *  �\�񖽗ߗ�O�iReserved Instruction Exception�j
	 */
	stmdb	"r0,r1"
	ldi		r1, #(EXC_RIE*4-4)
	bra		_exception_handler

	.balign 0x10
vector_entry_AE:
    /* 
	 *  �A�h���X��O�iAddress Exception�j
	 */
	stmdb	"r0,r1"
	ldi		r1, #(EXC_AE*4-4)
	bra		_exception_handler

	.balign 0x10
vector_entry_trap:
    /*
	 *  �g���b�v�x�N�^�G���g��
	 */
	bra		_trap_handler_0
	bra		_trap_handler_1
	bra		_trap_handler_2
	bra		_trap_handler_3
	bra		_trap_handler_4
	bra		_trap_handler_5
	bra		_trap_handler_6
	bra		_trap_handler_7
	bra		_trap_handler_8
	bra		_trap_handler_9
	bra		_trap_handler_10
	bra		_trap_handler_11
	bra		_trap_handler_12
	bra		_trap_handler_13
	bra		_trap_handler_14
	bra		_trap_handler_15

/*
 *  �����݃x�N�^�G���g���Ɗ����݃n���h���N���^���A������
 *
 *  �����ݔ������̃n�[�h�E�G�A�̓���
 *
 *  psw���W�X�^����sm�Cie�Cpm�Cc�r�b�g��bsm�Cbie�Cbpm�Cbc�r�b�g�ɑޔ�
 *  ����Dbpc�ɂ͊����ݔ�������pc�l������D
 *
 *	bsm <- sm
 *  bie <- ie
 *  bpm <- pm
 *  bc <- c
 *  bpc <- �����ݔ�������pc�l
 *
 *	psw���W�X�^����sm�Cie�Cpm�Cc�r�b�g���ȉ��̂悤�ɍX�V����D
 *
 *	sm <- 0
 *  ie <- 0
 *  pm <- 0
 *  c <- 0
 *
 *�@���W�X�^�̐ςݕ�
 *  r0-r1�i��Ɨ̈�j
 *  r0-r7�Cr14�Cacc(hi/lo)�Cbpc�Cpsw�CICUISTS�Cpsw�i�����݃n���h���ďo�O�j
 *  
 *  ��ڂ�psw�ȊO�́C�����ݔ������̃R���e�L�X�g�ɑΉ������X�^�b�N��
 *  �ޔ�����D2�ڂ�psw�́C�����݃n���h���̎��s����ɕ��A���邽�߂ɁC
 *  �K�������݃X�^�b�N�ɑޔ�����D�x���f�B�X�p�b�`����ꍇ�ɂ́C��L��
 *  ���W�X�^�ȊO�ɂ��Cr8-r13��ޔ����ăf�B�X�p�b�`�����Ăяo���D
 */
	.balign 0x10
interrupt_handler:

	/* 
	 *  ��Ɨp���W�X�^�̑ޔ� 
	 *
	 *  �ŏ��ɍ�Ɨp���W�X�^���X�^�b�N�ɑޔ�����D�����ݔ�������́C�K
	 *  �������݃X�^�b�N�ɂȂ�̂ŁC�����őޔ������Ɨp���W�X�^�͊���
	 *  �݃X�^�b�N�ɐς܂��D
	 */
	stmdb	"r0,r1"

	/* 
	 *  �����ݔ������̃R���e�L�X�g����
	 *
	 *  psw��bsm�r�b�g���犄���ݔ������Ɏg�p���Ă����X�^�b�N�����擾
	 *  ����Dbsm��0�̏ꍇ�́C�����݃X�^�b�N���g�p���Ă������ƂɂȂ��
	 *  �ŁC�����݃R���e�L�X�g�Ŋ����݂����������Ɣ��f����Dbsm��1�̏�
	 *  ���́C���[�U�X�^�b�N���g�p���Ă������ƂɂȂ�̂ŁC�^�X�N�R���e
	 *  �L�X�g�Ŋ����݂����������Ɣ��f����D��҂̏ꍇ�́C��Ɨ̈�ir0
	 *  ��r1�j�̐ςݒ����͕K�v�Ȃ��D
	 */
	mvfc	r0, psw
	and3	r1, r0, 0x8000
	beqz	r1, L1

	/* 
	 *  �ޔ����W�X�^�̃��[�U�X�^�b�N�ւ̐ςݒ���  
	 *
	 *  �^�X�N�R���e�L�X�g�Ŋ����݂����������ꍇ�́C�����݃X�^�b�N�ɑ�
	 *  ��������Ɨp���W�X�^r0��r1�����[�U�X�^�b�N�ɐςݒ����K�v������D
	 */

	or3		r0, r0, 0x80		
	mvtc	r0, psw				/* ���[�U�X�^�b�N�ɐؑցisp = spu�j */

	mvfc	r1, spi
	ld		r0, @(4, r1)		/* �ޔ�����r0�������݃X�^�b�N������o�� */
	st		r0, @-sp			/* r0�����[�U�X�^�b�N�ɐς� */
	ld		r0, @r1				/* �ޔ�����r1�������݃X�^�b�N������o�� */
	st		r0, @-sp			/* r1�����[�U�X�^�b�N�ɐς� */
	addi	r1, 8				/* �����݃X�^�b�N����ƃX�^�b�N�ޔ�O�ɖ߂� */
	mvtc	r1, spi				/* �����݃X�^�b�N�ʒu��spi�ɕۑ� */
	mvfc	r0, psw

L1:
	/* 
	 *  �R���e�L�X�g�̑ޔ�
	 * 
	 *  r2-r7, r14, acch, accl, bpc, psw, �����݃}�X�N�iICUISTS�j,psw
	 *  �̏��ɃX�^�b�N�ɑޔ�����D�����ł́C�K��psw��r0�ɕۑ�����Ă�
	 *  ��D
	 */
	stmdb	"r2,r3,r4,r5,r6,r7,r14"
	mvfachi	r1
	st		r1, @-sp			/* acch��ޔ� */
	mvfaclo	r1
	st		r1, @-sp			/* accl��ޔ� */
	mvfc	r1, bpc
	st		r1, @-sp			/* bpc��ޔ� */
	st 		r0, @-sp			/* psw��ޔ� */

	ld24	r1, ICUISTS
	ld		r0, @r1				/* �����݃}�X�N�ǂݍ��݁i�����ݗv���̓N���A�����j*/
	st		r0, @-sp			/* �����݃}�X�N��ޔ� */

	lea		r1, InterruptHandlerEntry /* �����݃n���h���e�[�u���̐擪�A�h���X�����o�� */
	srli	r0, 22				/* �����ݗv���ԍ����擾 */
	addi	r0, -1				/* �����݃n���h���e�[�u���̃C���f�b�N�X���v�Z */
	slli	r0, 2				/* �����݃n���h���e�[�u���̃I�t�Z�b�g���v�Z */
	add		r1, r0				/* �����݃n���h���e�[�u�����̊����݃n���h���̃A�h���X�v�Z */
	ld		r1, @r1				/* �����݃n���h���̋N���Ԓn�����o�� */

L2:
	/*
	 *  �����݃n���h���̌ďo��
	 *
	 *  psw��ޔ����C�����݃X�^�b�N, �����݋��ɂ��Ċ����݃n���h����
	 *  �Ăяo���D�����݃n���h������̖߂�Ԓn��eit_handler_r�Ƃ���D
	 *  �����ŁC�ēxpsw��ޔ�����̂́Ceit_handler_r�̍ŏ��ŁC�g�p����
	 *  �X�^�b�N��߂��K�v�����邽�߂ŁC�K�������݃X�^�b�N�ɑޔ����Ă�
	 *  ���D
	 */
	mvfc	r2, psw						
	and3	r3, r2, 0xff7f				
	mvtc	r3, psw						/* �����݃X�^�b�N */
	st		r2, @-sp					/* psw�������݃X�^�b�N�ɑޔ� */
	lea		r14, eit_handler_r 			/* �߂�Ԓn��ݒ� */
	or3		r3, r3, 0x40				
	mvtc	r3, psw						/* �����݋��� */
	jmp		r1							/* �n���h���N�� */

	.text
	.align 4
eit_handler_r:
	/*
	 *  EIT�n���h������̕��A����
	 *
	 *  EIT�n���h���̎��s���I������ƌĂяo�����D�����ݔ������̃R��
	 *  �e�L�X�g�C�����ݗv���̗L���C�f�B�X�p�b�`���^�֎~��Ԃ���C�K
	 *  �؂ȕ��A�������s�Ȃ��D
	 */
	ld		r0, @sp+
	mvtc	r0, psw			/* �����݃X�^�b�N����psw�𕜋A�iEIT������
							   �̃R���e�L�X�g�ɖ߂�D�����݂͋֎~��ԁj
							    */

	ld24 	r1, ICUIMASK
	ld 		r2, @sp+
	st 		r2, @r1			/* �����݃}�X�N�̕��A */

	and3	r0, r0, 0x8000
	beqz	r0, recover_int	/* EIT�������̃R���e�L�X�g�������݃R���e�L
							   �X�g�ł���΁C���d�����݂ł���Ɣ��f���C
							   �����ɋ��ʕ��A������ */

	/* 
	 *  �^�X�N�R���e�L�X�g�ւ̕��A���[�`��
	 *
	 *  �f�B�X�p�b�`�^�^�X�N��O�N���v�����Ȃ��ꍇ�́C�����ɋ��ʕ��A���[
	 *  �`���ɔ�ԁD�x���f�B�X�p�b�`�������s�Ȃ��D�f�B�X�p�b�`�v������
	 *  ����΋��ʂ̕��A�����irecover_int�j���s�Ȃ��D
	 */
	lea		r0, _kernel_reqflg
	ld		r1, @r0
	beqz	r1, recover_int		/* ���ʕ��A���[�`���� */

	/* 
	 *  �f�B�X�p�b�`�^�^�X�N��O�N���v��������ꍇ�̏���
	 *
	 *  �܂��C�f�B�X�p�b�`�v���t���O�ireqflg�j���N���A����D�����āC�f�B
	 *  �X�p�b�`���t���O�ienadsp�j��FALSE�̏ꍇ�ƁCruntsk��schedtsk 
	 *  �������ꍇ�ɂ́C�f�B�X�p�b�`�����ɁC�^�X�N��O�N���������[�`��
	 *  �֔�ԁD�f�B�X�p�b�`��������Ă���Cruntsk��schedtsk���قȂ�
	 *  �ꍇ�ɂ́C�x���f�B�X�p�b�`�������s���D
	 */
	ldi		r1, #0
	st		r1, @r0				/* reqflg���N���A */

	lea 	r0,  _kernel_enadsp
	ld 		r0, @r0
	beqz 	r0, recover_task 	/* enaflg�̃`�F�b�N */

	lea		r0, _kernel_runtsk
	lea		r1, _kernel_schedtsk
	ld		r0, @r0	
    ld		r1, @r1
    beq		r0, r1, recover_task	/* runtsk��schedtsk�������ꍇ�̓^
								       �X�N��O�N�������� */

	/*
	 *  ��O�^�����ݏo���ł̒x���f�B�X�p�b�`����
	 *
	 *  �ޔ����Ă��Ȃ��c��̃��W�X�^��ޔ����C���s��ԃ^�X�N��pc��sp��
	 *  �ޔ����Ă���f�B�X�p�b�`�����Ăяo���D
	 */
	stmdb	"r8,r9,r10,r11,r12,r13"

	lea		r0, _kernel_runtsk
	ld		r0, @r0

	lea		r1, recover_task_r
	st		r1, @(TCB_pc, r0)
	st		sp, @(TCB_sp, r0)
	bra		_kernel_exit_and_dispatch

	.align 4
recover_task_r:
	ldmia	"r13,r12,r11,r10,r9,r8"

recover_task:
	/* 
	 *  �^�X�N��O�N������
	 *
	 *  �����ŁCenatex��TRUE�ŁCtexptn��0�łȂ���΁C�^�X�N��O�������[
	 *  �`�����Ăяo���Dcalltex�̏������e�iruntsk->enatex��TRUE�ŁC
	 *  runtsk->texptn��0�łȂ��ꍇ�ɁCcall_texrtn���Ăԁj�������ɃC��
	 *  ���C���W�J���������������ǂ����C�����̊ȈՉ��̂��߂�calltex ��
	 *  �Ăяo���D
	 */
	bl		_kernel_calltex

recover_int:
	/* 
	 *  EIT���ʕ��A�����i��D��x�����݂ւ̕��A�܂ށj
	 *
	 *  �ޔ��������ԁir2-r7, r14, acch, accl, bpc, psw�j�̋t���ŃX�^�b
	 *  �N������o���ĕ��A����D�܂��C��Ɨp���W�X�^�ir0�Cr1�j�����A
	 *  ����D
	 */
	ld 		r0, @sp+
	mvtc 	r0, psw						/* psw�𕜋A */
	ld		r0, @sp+			
	mvtc	r0, bpc						/* bpc�𕜋A */
	ld		r0, @sp+	
	mvtaclo	r0							/* accl�𕜋A */
	ld		r0, @sp+
	mvtachi	r0							/* acchl�𕜋A */
	ldmia	"r14,r7,r6,r5,r4,r3,r2"		/* ���̑��̃��W�X�^�𕜋A */
	ldmia	"r1,r0"						/* ��Ɨp���W�X�^�̕��A */
	rte									/* �����ݏ������畜�A */

	.section ".vector","ax"
	/*
	 *  �g���b�v�̃G���g���� : �g���b�v�ԍ��̊i�[
	 */
	.irp num,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
		.align	4

	_kernel__trap_handler_\num:
		stmdb	"r0,r1"
		ldi		r1, #((\num + EXC_TRAP00 - 1) * 4)
		bra		_exception_handler
	.endr
		
/*
 *  ��O�^�g���b�v�n���h����������
 *
 *  ��O�����������ꍇ�ɂ́C�X�N���b�`���W�X�^��ޔ����ė�O�v���ir1��
 *  �����Ă���j�ɑΉ������O�n���h�����Ăяo���D��O�n���h������̕�
 *  �A�����́C�����݃n���h������̕��A�����Ƌ��ʁieit_handler_r�j�ł���D
 *
 *  ��O�������̃n�[�h�E�G�A�̓���
 *
 *  psw���W�X�^����sm�Cie�Cpm�Cc�r�b�g��bsm�Cbie�Cbpm�Cbc�r�b�g�ɑޔ�
 *  ����Dbpc�ɂ͗�O���N���������߂�pc�l������D
 *
 *	bsm <- sm
 *  bie <- ie
 *  bpm <- pm
 *  bc <- c
 *  bpc <- ��O���N���������߂̃A�h���X
 *
 *	psw���W�X�^����sm�Cie�Cpm�Cc�r�b�g���ȉ��̂悤�ɍX�V����D
 *
 *	sm <- �s��
 *  ie <- 0
 *  pm <- 0
 *  c <- 0
 *
 *  ���W�X�^�̐ςݕ�
 *
 *  r0-r1�i��Ɨ̈�C�x�N�^�̍ŏ��őޔ��j
 *  r2-r7�Cr14�Cacc(hi/lo)�Cbpc�Cpsw�CICUIMASK�i��O�n���h���ďo�O�j
 *
 *  �����ŁCICUISTS�ł͂Ȃ�ICUIMASK��ޔ�����̂́C��O�������ɊO����
 *  ���݂����������ꍇ�ɁCICUISTS�̓Ǎ��݂ɂ�芄���ݗv�����N���A����
 *  �Ă��܂��̂�h�����߂ł���D
 */
_exception_handler:

	stmdb 	"r2,r3,r4,r5,r6,r7,r14"
	mvfachi r0
	st 		r0, @-sp
	mvfaclo r0
	st 		r0, @-sp
	mvfc 	r0, bpc
	st 		r0, @-sp
	mvfc 	r2, psw
	st 		r2, @-sp
	ld24 	r0, ICUIMASK
	ld 		r0, @r0
	st 		r0, @-sp

	lea		r0, ExceptionHandlerEntry
	add		r0, r1
	ld		r1, @r0				/* ��O�n���h���̃A�h���X���擾 */

	mv 		r0, sp				/* �X�^�b�N�̈ʒu���O�n���h���̈���
								   �ɐݒ� */
	and3 	r3, r2, 0x7f00
	srli 	r3, 8
	mvtc 	r3, psw 			/* �����݃X�^�b�N�C�����݋���Ԃ� */
	st 		r2, @-sp			/* ��O���������psw�������݃X�^�b�N�ɑޔ� */
	lea 	r14, eit_handler_r 
	jmp 	r1
				
Function _kernel_dispatch
	/*
	 *  �^�X�N�ؑւ��̂��߂̑ޔ�����
	 *
	 *  ���̃��[�`���́C�^�X�N�R���e�L�X�g�CCPU���b�N��ԁC�f�B�X�p�b
	 *  �`����ԂŌĂяo�����D�ďo���ł͕ۑ�����Ȃ����W�X�^���X�^�b
	 *  �N�ɑޔ����Cpc��sp��TCB�ɑޔ�����Dpc�̓f�B�X�p�b�`���o������
	 *  �idispatch_r�j�ɐݒ肷��D
	 */
	stmdb	"r8,r9,r10,r11,r12,r13,r14"

	lea 	r0, _kernel_runtsk
	lea		r1, dispatch_r
	ld		r0, @r0
	st		r1, @(TCB_pc, r0)		/* ���A���鎞��dispatch_r�ɋA���Ă��� */
	st		sp, @(TCB_sp, r0)		/* �X�^�b�N�|�C���^��ޔ� */

Function _kernel_exit_and_dispatch
	/*
	 *  �^�X�N�ؑւ��̑O����
	 *
	 *  schedtsk����łȂ������`�F�b�N����Dschedtsk����łȂ��ꍇ�́C
	 *  �^�X�N�ؑւ������Ɉڂ�D��̏ꍇ�́C�����݂������ă��[�v����
	 *  �����Ɉڂ�D
	 */	
	xor		r0, r0
	mvtc	r0, psw						/* �����݋֎~�C�����݃X�^�b�N */
	
	lea		r1,  _kernel_schedtsk
L6:	ld		r0, @r1
	bnez	r0, L7						/* schedtsk�̗L�����`�F�b�N */

	/* 
	 *  �N�����ׂ��^�X�N���Ȃ��ꍇ�̏���
	 *
	 *  �N�����ׂ��^�X�N���Ȃ��ꍇ�́C�����݂������ă��[�v����D���[
	 *  �v�̓r���Ŋ����݂������C���s�\�^�X�N��҂D
	 */
	ldi		r0, 0x40
	mvtc	r0, psw						/* �����݋��� */
	xor		r0, r0
	mvtc	r0, psw						/* �����݋֎~ */

	lea 	r0, _kernel_reqflg
	xor 	r2, r2
	st 		r2, @r0 					/* reqflg = 0 */
	bl 		L6

L7:
    /* 
	 *  �^�X�N�ؑւ�����
	 *
	 *  ���s���^�X�N�iruntsk�j�ɍō��D�揇�ʃ^�X�N�ischedtsk�j��ݒ肵�C
	 *  �X�^�b�N�����[�U�X�^�b�N�ɐؑւ���Druntsk��TCB��sp��pc�𕜋A
	 *  ����D�����ł́Cr0 = schedtsk�ł���D
	 */
	lea		r2, _kernel_runtsk
	st		r0, @r2 					/* runtsk = schedtsk */

	ldi 	r1, 0x80
	mvtc 	r1, psw 					/* ���[�U�X�^�b�N�C�����݋֎~ */

	ld		sp, @(TCB_sp, r0)			/* �X�^�b�N�|�C���^�𕜋A */
	ld		r0, @(TCB_pc, r0)			/* �v���O�����J�E���^�𕜋A */
	jmp		r0

	.align 4
Label dispatch_r
	/* 
	 *  �f�B�X�p�b�`���̏o������
	 * 
	 *  dispatch�őޔ��������W�X�^�𕜋A���C�^�X�N��O�������[�`������
	 *  �яo���D
	 */
	bl 		_kernel_calltex 
    ldmia 	"r14,r13,r12,r11,r10,r9,r8" 
	rts

Function _kernel_activate_r
	/*
	 *  �^�X�N�̋N�����[�`��
	 *
	 *  runtsk�̃^�X�N�������u���b�N����^�X�N�֐��Ɗg���������o��
	 *  �āC�g�������������W�X�^�ir0�j�ɐݒ肷��Dext_tsk���Ăяo��
	 *  ���Ƀ^�X�N���I������ꍇ�����邽�߁C�^�X�N�֐��̖߂�Ԓn��
	 *  ext_tsk�ɐݒ肷��D�N���������S�Ċ������Ă���C�����݂�����
	 *  �ă^�X�N�֐��ɔ�ԁD
	 */
	lea		r2, _kernel_runtsk
	ld		r2, @r2
	ld		r2, @(TCB_tinib, r2)		/* r2 = runtsk->tinib */
	ld		r0, @(TINIB_exinf, r2)
	ld		r1, @(TINIB_task,  r2)

	lea		r14, ext_tsk				/* �^�X�N�̖߂�Ԓn��ext_tsk�� */

	ldi 	r2, 0xc0
	mvtc 	r2, psw						/* ���[�U�X�^�b�N�C�����݋��� */
	jmp		r1							/* �^�X�N�֐��� */