;
;   TOPPERS/JSP Kernel
;       Toyohashi Open Platform for Embedded Real-Time Systems/
;       Just Standard Profile Kernel
;
;   Copyright (C) 2006 by Witz Corporation, JAPAN
;
;   ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
;   �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
;   �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
;   �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
;   ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
;   (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
;       ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
;       �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
;   (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
;       �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
;       �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
;       �̖��ۏ؋K����f�ڂ��邱�ƁD
;   (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
;       �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
;       �ƁD
;     (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
;         �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
;     (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
;         �񍐂��邱�ƁD
;   (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
;       �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
;
;   �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
;   ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
;   �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
;   �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
;
;   @(#) $Id: cpu_support.app,v 1.1 2006/04/10 08:19:25 honda Exp $
;

	$MAXIMUM
	module cpu_support_app

;
;	�v���Z�b�T�ˑ����W���[�� �A�Z���u�����ꕔ�iTLCS-900L1�p�j
;

#define	SUPPORT_CHG_IPM
#include "jsp_rename.h"
#include "cpu_rename.h"
#include "sys_rename.h"
#include "offset.inc"

; �O���Q�ƃV���{����`
	extern large	__StackTop
	extern large	_reqflg
	extern large	_enadsp
	extern large	_intcnt
	extern large	_runtsk
	extern large	_schedtsk
	extern large	_call_texrtn
	extern large	_task_intmask


f_code section code large align=1,1

;
;	�^�X�N�f�B�X�p�b�`��
;
;   dispatch �́C�^�X�N�R���e�L�X�g��ԁE�����݋֎~��ԂŌĂяo���Ȃ�
;   ��΂Ȃ�Ȃ��Dexit_and_dispatch ���C�^�X�N�R���e�L�X�g��ԁE����
;   �݋֎~��ԂŌĂяo���̂������ł��邪�C�J�[�l���N�����ɑΉ����邽�߁C
;   �����݃R���e�L�X�g��ԂŌĂяo�����ꍇ�ɂ��Ή����Ă���D
;	�Ăяo������: SR��IFF=7 (�����݋֎~���),
;				  intcnt = 0(�^�X�N�R���e�L�X�g), �^�X�N�X�^�b�N
;
	public _dispatch

_dispatch:
	push	xiz			; �֐��ďo�ŕی삪�K�v�ȃ��W�X�^�̕ۑ�
	ld		xwa, (_runtsk)	; ���쒆�^�X�N��TCB���擾
	ld		(xwa+TCB_sp), xsp	;
	lda		xhl, dispatch_r	;
	ld		(xwa+TCB_pc), xhl	;
	jr		dispatcher	;

;
;	�Ăяo������: SR��IFF=7 (�����݋֎~���),
;				  intcnt = 0(�^�X�N�R���e�L�X�g), �^�X�N�X�^�b�N
;
;	xwa �ɂ�runtsk �̃A�h���X���i�[����Ă���
;
dispatch_r:
	pop		xiz		;
	ld		bc, (xwa+TCB_enatex)	;
	bit		TCB_enatex_bit, bc	;
	jr		z, dispatch_r_1	; enatex �� FALSE �Ȃ烊�^�[��
	cpw		(xwa+TCB_texptn), 0	; �^�X�N��O�v��������ꍇ
	jp		nz, _call_texrtn	;
	; call_texrtn���璼��dispatch �Ăяo�����֖߂�.
dispatch_r_1:				; �^�X�N��O�����s���Ȃ��ꍇ
	ret				; dispatch �Ăяo�����֖߂�.

;
;	�^�X�N�N��������
;
;	�����ł�, CPU���b�N������Ԃɂ�, �^�X�N���N������.
;
;	�Ăяo������: SR��IFF=7 (�����݋֎~���),
;				  intcnt = 0(�^�X�N�R���e�L�X�g), �^�X�N�X�^�b�N
;
	public _activate_r

_activate_r:
	pop		xhl		; �^�X�N�̋N���Ԓn��whl �ɐݒ�
#ifdef SUPPORT_CHG_IPM			/* t_unlock_cpu �����̏��� */
	push	sr			; �����݃}�X�N�� task_intmask ��ݒ�
	ld		wa, (_task_intmask)	;
	andw	(xsp), ~0x7000	;
	or		(xsp), wa	;
	pop		sr			;
#else /* SUPPORT_CHG_IPM */
	ei		0		; �����݋���
#endif /* SUPPORT_CHG_IPM */
	jp		xhl

;
;	dispatcher�Ăяo������:
;		�E���ׂẴ^�X�N�̃R���e�L�X�g�͕ۑ�����Ă���.
;		�ESR��IFF=7 (�����݋֎~���)
;		�E�R���e�L�X�g�̓^�X�N�R���e�L�X�g(intcnt=0)
;	dispatcher �ďo���̃X�^�b�N:
;		dispatch ���炫���ꍇ: �^�X�N�X�^�b�N
;		exit_and_dispatch ���炫���ꍇ: 
;			exit_task ���炫���ꍇ�̓^�X�N�X�^�b�N
;			�J�[�l���N�����͊����݃X�^�b�N
;		ret_int ���炫���ꍇ: �^�X�N�X�^�b�N
;		dispatcher_2 �ł̊����ݑ҂����炫���ꍇ: �����݃X�^�b�N
;
	public _exit_and_dispatch

_exit_and_dispatch:
	ldw		(_intcnt), 0	; �l�X�g�J�E���^�N���A(�^�X�N�R���e�L�X�g)
dispatcher:
	ld		xwa, (_schedtsk)	; schedtsk �� runtsk �ɐݒ�
	ld		(_runtsk), xwa	;
	or		xwa, xwa		; ���s����^�X�N��������΃A�C�h�����[�v��
	jr		z, pre_idle_loop	;
	ld		xsp, (xwa+TCB_sp)	; �^�X�N�X�^�b�N�|�C���^�𕜋A
	ld		xhl, (xwa+TCB_pc)	;
	jp		xhl			; ���s�ĊJ�Ԓn�փW�����v
;
;	���s���ׂ��^�X�N�������܂ő҂���
;
pre_idle_loop:
	ld		xsp, __StackTop ; �����ݗp�̃X�^�b�N�֐ؑւ�
	incw	1, (_intcnt)	; ��^�X�N�R���e�L�X�g
;
;	�����Ŕ�^�X�N�R���e�L�X�g,�����݃X�^�b�N�ɐ؂芷�����̂�,
;	�����Ŕ������銄���ݏ����ɂǂ̃X�^�b�N���g�����Ƃ������̉�����,
;	�����݃n���h�����ł̃f�B�X�p�b�`�h�~�Ƃ���2�̈Ӗ�������D
;
idle_loop:
#ifdef SUPPORT_CHG_IPM			/* t_unlock_cpu �����̏��� */
	push	sr			; �����݃}�X�N�� task_intmask ��ݒ�
	ld		wa, (_task_intmask)	;
	andw	(xsp), ~0x7000	;
	or		(xsp), wa	;
	pop		sr			;
#else /* SUPPORT_CHG_IPM */
	ei		0		; �����݋���
#endif /* SUPPORT_CHG_IPM */

	halt 		; IDLE2��Ԃ֑J��
	nop			; ��Lhalt���R�����g(nop�̂�)�ɂ����
	nop			; ��������s��Ȃ��A�C�h�����[�v�ƂȂ�.
	nop			; 
	nop			; 
	ei		7			; �����݋֎~
	cpw		(_reqflg), 0	; reqflg �� FALSE �ł����
	jr		z, idle_loop	;         idle_loop ��
	ldw		(_reqflg), 0	; reqflg <--- FALSE
	decw		1, (_intcnt)	; �^�X�N�R���e�L�X�g�ɖ߂�
	jr		dispatcher		; dispatcher �֖߂�

;
;  �x���f�B�X�p�b�`����
;
;	�Ăяo������: SR��IFF=7 (�����݋֎~���),
;				  intcnt = 0(�^�X�N�R���e�L�X�g), �^�X�N�X�^�b�N
;				  reqflg = TRUE
;				  INTNEST���W�X�^ = 1
;
ret_int:
	ldw		(_reqflg), 0	; reqflg <--- FALSE
	ld		de, 0	;
	ldc		intnest, de	; �f�B�X�p�b�`������intnest ��0
	push	xiz			; �֐��ďo�ŕی삪�K�v�ȃ��W�X�^�̕ۑ�
	ld		xwa, (_runtsk)	; runtsk ���擾
	cpw		(_enadsp), 0	; enadsp �� FALSE �Ȃ�
	jr		z, ret_int_r	; ret_int_r ��
	cp		xwa, (_schedtsk)	; runtsk ��schedtsk �������Ȃ�
	jr		z, ret_int_r	; ret_int_r ��
	or		xwa, xwa	; runtsk = NULL �Ȃ�
	jr		z, dispatcher	; �ۑ�����dispather ��
	ld		(xwa+TCB_sp), xsp	;
	lda		xhl, ret_int_r	;
	ld		(xwa+TCB_pc), xhl	;
	jr		dispatcher	;

;
;	�Ăяo������: SR��IFF=7 (�����݋֎~���),
;				  intcnt = 0(�^�X�N�R���e�L�X�g), �^�X�N�X�^�b�N
;				  INTNEST���W�X�^ = 0
;
;	xwa �ɂ�runtsk �̃A�h���X���i�[����Ă���
;
ret_int_r:
	pop		xiz
#ifdef SUPPORT_CHG_IPM		/* �X�^�b�N�ɂ���SR ��IFF �𑀍� */
	ld		de, (_task_intmask)	;
	andw	(xsp+24), ~0x7000	;
	or		(xsp+24), de	;
#endif /* SUPPORT_CHG_IPM */
	ld		bc, (xwa+TCB_enatex)	;
	bit		TCB_enatex_bit, bc	;
	jr		z, nest_ctrl_r	; enatex �� FALSE �Ȃ烊�^�[��
	cpw		(xwa+TCB_texptn), 0	; �^�X�N��O�v��������ꍇ
	call	nz, _call_texrtn	;
nest_ctrl_r:
	ld		de, 1	;
	ldc		intnest, de	; reti�p�ɋ[���I��intnest ��1
	jr		interrupt_r

;
;	������/CPU��O�̋��ʏ���
;
;	�ďo������:
;	�ESR��IFF=7.
;	�E�X�^�b�N�͑��d���荞�݂Ȃ犄���݃X�^�b�N, �����łȂ����
;	  �^�X�N�X�^�b�N
;	�EXHL �ɂ͊�����/CPU��O�n���h���̃A�h���X���i�[����Ă���.
;	�EAW �ɂ͖{�����݂̗D��x���ݒ肳�ꂽ SR ���i�[����Ă���.
;
;	���W�X�^���X�^�b�N��ɂǂ̂悤�ɕۑ�����Ă��邩���ȉ��Ɏ���.
;	���̐}�ł͏オ���, �������ʂ̃A�h���X��, �X�^�b�N�͉�����
;	������Ɍ������Đςݏグ������̂Ƃ���.
;
;	--------------------------------------
;	|        CPU��O�n���h���̈���       |
;	|          CPU��O���(4byte)        |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XSP(4byte)             | �^�X�N�X�^�b�N�|�C���^�D
;	|             �����i�̂�             | ���i�̊����݂̂ݕێ������D
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XIY(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XIX(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XDE(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XBC(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	-------------------------------------- <-- �����ݓ���������ŏ��������D
;	|             XHL(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;	|             XAW(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	-------------------------------------- <-- �����ݔ������Ƀn�[�h�E�F�A
;	|              SR(2byte)             |     �ɂď��������D p_excinf��
;	|                                    |     �������w���悤�ɉ��Z����D
;	--------------------------------------
;	|              PC(4byte)             |
;	|                                    |
;	|                                    |
;	|                                    |
;	--------------------------------------
;
;	�n���h�����烊�^�[���������, ���d�����݂łȂ�, ���� reqflg ��
;	TRUE �ɂȂ������ɁCret_int �֕��򂷂�D
;
;	���d�����݂��ǂ����͊����݃l�X�g�J�E���^�̒l�Ŕ��肷��.
;	intcnt != 0 �Ȃ�Α��d�����݂ł���Ɣ��肷��.
;	�Ȃ��C�n�[�h�E�F�A�d�l��C�����ݔ������犄���݋֎~���s���܂ł̊Ԃ�
;	���d�����݂���������ƁC���d�����݂ł��邱�Ƃ��\�t�g�E�F�A�Ō��m��
;	���Ȃ����߁C�ŏ��ɔ������������ݏ��������s���Ȃ��܂܃^�X�N�f�B�X
;	�p�b�`����\��������D���̑��d�����݂����m���邽�߂Ƀn�[�h�E�F�A
;	INTNEST ���W�X�^�𗘗p����D
;
;	reqflg ��CPU���b�N��ԂŃ`�F�b�N����. �����łȂ��ƁC
;	reqflg �`�F�b�N��ɋN�����ꂽ�����݃n���h������
;	�f�B�X�p�b�`���v�����ꂽ�ꍇ�ɁC�f�B�X�p�b�`����Ȃ�.
;
	public _interrupt

_interrupt:
	push	xbc			; �X�N���b�`���W�X�^�̎c���ۑ�
	push	xde			;
	push	xix			;
	push	xiy			;

	ld		xbc, xsp	; CPU��O�������Ɏg�p���邽�߂����Ŏ擾
	cpw		(_intcnt), 0	;
	jr		nz, from_int	;
	ld		xsp, __StackTop ; ���i�̊����݂̏ꍇ�X�^�b�N��؂�ւ�
	push	xbc			; �^�X�NSP�̕ێ�
from_int:				;
	incw	1, (_intcnt)	; �����݃l�X�g�J�E���g���C���N�������g

	add		xbc, 24	; CPU��O����������
	push	xbc			; �����ݏ����ł͖��g�p
	push	wa			;
	pop		sr			; �{�����݂��D��x�̍��������݋���
	call	xhl			; �����݃n���h��/CPU��O�������Ăяo��
	ei		7			; �����݋֎~
	pop		xbc			; �X�^�b�N�����킹(CPU��O������)

	decw	1, (_intcnt)	; �����݃l�X�g�J�E���g���f�N�������g
	jr		nz, from_int_r	;
	pop		xbc			; ���i�̊����݂̏ꍇ�^�X�NSP�̕��A
	ld		xsp, xbc	;
	ldc		de, intnest	; �����ݔ������犄���݋֎~�܂ł̊Ԃɑ��d�����݂�
	djnz	de, from_int_r	; �������Ă���ꍇ�̓f�B�X�p�b�`���Ȃ�
	cpw		(_reqflg), 0	; reqflg �� TRUE �ł����
	jp		nz, ret_int	;              ret_int ��
from_int_r:		;
interrupt_r:	;
	pop		xiy	;�X�N���b�`���W�X�^�𕜋A
	pop		xix	;
	pop		xde	;
	pop		xbc	;
	pop		xhl	;
	pop		xwa	;
	reti	;

;
; ���g�p�����݂̏���
;
	public unused_interrupt

unused_interrupt:
	reti


	end


