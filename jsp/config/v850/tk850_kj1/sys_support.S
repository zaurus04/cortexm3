/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: sys_support.S,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[�� �A�Z���u�����ꕔ�iTK-850ES/KJ1+�p�j
 */

#define	_MACRO_ONLY
#include "jsp_kernel.h"
#include "v850asm.inc"

#define Set(x,y,z) Lea x, r6; Lea y, r7; st.##z r7, 0[r6]

/*
 *  �჌�x���̃^�[�Q�b�g�V�X�e���ˑ��̏�����
 *
 *  �X�^�[�g�A�b�v���W���[���̒��ŁC�������̏������̑O�ɌĂяo�����D
 */

	.text
	.globl hardware_init_hook
hardware_init_hook:

	/* �V�X�e���E�F�C�g�R���g���[�����W�X�^�F5MHz�~4=20MHz�� */
	Set(VSWC,  0x01,   b)
	/* �ی삳�ꂽ���背�W�X�^�ւ̃A�N�Z�X
	   �v���Z�b�T�N���b�N�R���g���[�����W�X�^�F���C���N���b�N��fxx�o��(PCC=0) */
	lea	PRCMD, r6
	lea	PCC, r7
	st.b	r0, 0[r6]
	st.b	r0, 0[r7]
	nop
	nop
	nop
	nop
	nop
	Set(PLLCTL,0x03,   h)   /* PLL�R���g���[�����W�X�^�FPLL���� */
	Set(WDTM2, 0x07,   b)   /* WDTM2 stop */
#if 0
	/* �O���o�X�̐ݒ�F
	     CS0�ɊO��SRAM�𑝐݂����ꍇ�̎Q�l�B�����ł̓o�X�̓Z�p���[�g�o�X�ŁA
	     12ns�i��SRAM��0wait�œ��삷�邱�Ƃ����肵���ݒ�B
	 */
	Set(EXIMC, 0x01,   b)	/* �O���o�X�C���^�[�t�F�C�X���[�h���W�X�^�F�Z�p���[�g�o�X */
	Set(PMC9,  0xFFFF, h)	/* P9���[�h�R���g���[�����W�X�^�FA0-A15�o�� */
	Set(PMCCS, 0x01,   b)	/* PCS���[�h�R���g���[�����W�X�^�FC0�o�� */
	Set(PMCCT, 0x53,   b)	/* PCT���[�h�R���g���[�����W�X�^�FRD/WR/ASTB�o�� */
	Set(PMCDH, 0xFF,   b)	/* PDH���[�h�R���g���[�����W�X�^�FA16-A23�o�� */
	Set(PMCDL, 0xFFFF, h)	/* PDL���[�h�R���g���[�����W�X�^�FAD0-AD15�o�� */
	Set(DWC0,  0x7770, h)	/* �f�[�^�E�F�C�g���䃌�W�X�^�FCS0wait=0 */
	Set(AWC,   0xFFFC, h)	/* �A�h���X�E�F�C�g���䃌�W�X�^�FCS0wait=0 */
	Set(BCC,   0xAAA8, h)	/* �o�X�T�C�N�����䃌�W�X�^�FCS0wait=0 */
#endif

	jmp		r31



	/* �W�������ݏ����ƃX�؁[�T�[ */
	.macro StandardInterruptEntry name
	.globl \name
\name:
	jr	vector_handler
	nop;nop;nop;nop;nop;nop
	.endm

	.macro ReservedInterruptEntry
	nop;nop;nop;nop;nop;nop;nop;nop
	.endm

/*
 * �����݃n���h�������̒�`
 * 		�Ƃ肠������ӏ��ɏW�߂�B
 */

	.section	".vectors","ax"
	.align      4
	.globl      __reset
__reset:
	jr	start
	nop;nop;nop;nop;nop;nop

	StandardInterruptEntry NMI
	StandardInterruptEntry INTWDT1
	StandardInterruptEntry INTWDT2
	StandardInterruptEntry TRAP0
	StandardInterruptEntry TRAP1
	StandardInterruptEntry DBG
/*#-------------------------------------------------------------------
  #	SECURITY_ID
  #-------------------------------------------------------------------*/
/*	.section	"SECURITY_ID" */
	.word	0xffffffff	/* --0-3 byte code,Address is 0x70-0x73 */
	.word	0xffffffff	/* --4-7 byte code,Address is 0x74-0x77 */
	.hword	0xffff		/* --8-9 byte code,Address is 0x78-0x79 */
/*#-------------------------------------------------------------------
  #	OPTION_BYTES
  #-------------------------------------------------------------------*/
/*	.section	"OPTION_BYTES" */
	.hword	0x0000		/* --0-1 byte code,Address is 0x7a-0x7b */
	.hword	0x0000		/* --2-3 byte code,Address is 0x7c-0x7d */
	.hword	0x0000		/* --4-5 byte code,Address is 0x7e-0x7f */

	StandardInterruptEntry INTWDTM1
	StandardInterruptEntry INTP0
	StandardInterruptEntry INTP1
	StandardInterruptEntry INTP2
	StandardInterruptEntry INTP3
	StandardInterruptEntry INTP4
	StandardInterruptEntry INTP5
	StandardInterruptEntry INTP6
	StandardInterruptEntry INTTM000
	StandardInterruptEntry INTTM001
	StandardInterruptEntry INTTM010
	StandardInterruptEntry INTTM011
	StandardInterruptEntry INTTM50
	StandardInterruptEntry INTTM51
	StandardInterruptEntry INTCSI00
	StandardInterruptEntry INTCSI01
	StandardInterruptEntry INTSRE0
	StandardInterruptEntry INTSR0
	StandardInterruptEntry INTST0
	StandardInterruptEntry INTSRE1
	StandardInterruptEntry INTSR1
	StandardInterruptEntry INTST1
	StandardInterruptEntry INTTMH0
	StandardInterruptEntry INTTMH1
	StandardInterruptEntry INTCSIA0
	StandardInterruptEntry INTIIC0
	StandardInterruptEntry INTAD
	StandardInterruptEntry INTKR
	StandardInterruptEntry INTWTI
	StandardInterruptEntry INTWT
	StandardInterruptEntry INTBRG
	StandardInterruptEntry INTTM020
	StandardInterruptEntry INTTM021
	StandardInterruptEntry INTTM030
	StandardInterruptEntry INTTM031
	StandardInterruptEntry INTCSIA1
	StandardInterruptEntry INTTM040
	StandardInterruptEntry INTTM041
	StandardInterruptEntry INTTM050
	StandardInterruptEntry INTTM051
	StandardInterruptEntry INTCSI02
	StandardInterruptEntry INTSRE2
	StandardInterruptEntry INTSR2
	StandardInterruptEntry INTST2
	StandardInterruptEntry INTIIC1
	ReservedInterruptEntry 
	ReservedInterruptEntry 
	ReservedInterruptEntry 
	ReservedInterruptEntry 
	ReservedInterruptEntry 
	StandardInterruptEntry INTTP0OV
	StandardInterruptEntry INTTP0CC0
	StandardInterruptEntry INTTP0CC1

/*
 * �]���p�����\?�^�C�}
 *  (����͕]���p�t���[�����j���O�^�C�}����炸�ɒ��ڃ^�C�}�J�E���^���̂���)
 */
Function _vxget_tim
	Lea	TM00, r7
	ld.h	0[r7], r8
	st.w	r8, 0[r6]
	mov	r0, r10
	jmp	r31