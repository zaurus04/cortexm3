/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: sys_support.S,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[�� �A�Z���u�����ꕔ
 */

#define _MACRO_ONLY
#include "jsp_kernel.h"

/*
 *  �V�X�e���ˑ��̏��������[�`��
 */
	.h8300h
	.text
	.align 2

	.global	_hardware_init_hook
_hardware_init_hook:
	/*
	 *  �����[�X�ł́A�O��DRAM��L���ɂ���B
	 */
#ifdef ROM
	mov.l	#H8P1DDR, er0
	mov.b	#0xff, r1l
	mov.b	r1l, @er0	/* enable A0  - A7  */

	add.b	#(H8P2DDR - H8P1DDR), r0l
	mov.b	r1l, @er0	/* enable A8  - A15 */

	add.b	#(H8P3DDR - H8P2DDR), r0l
	mov.b	r1l, @er0	/* enable D8  - D15 */

	add.b	#(H8P5DDR - H8P3DDR), r0l
	mov.b	r1l, @er0	/* enable A16 - A19 */

#ifdef ENABLE_LOWER_DATA

	mov.l	#H8P4DDR, er0
	mov.b	r1l, @er0	/* enable D0  - D7  */

#endif	/* #if ENABLE_LOWER_DATA */

#ifdef ENABLE_P8_CS

	mov.l	#H8P8DDR, er0
	mov.b	#ENABLE_P8_CS, r1l
	mov.b	r1l, @er0	/* enable CS0 - CS3 */

#endif	/* #ifdef ENABLE_P8_CS */

#ifdef ENABLE_PA_CS

	mov.l	#H8PADDR, er0
	mov.b	#ENABLE_PA_CS, r1l
	mov.b	r1l, @er0	/* enable CS4 - CS6 */

#elif defined(ENABLE_PA_A21_A23)

	mov.l	#H8PADDR, er0
	mov.b	#ENABLE_PA_A21_A23, r1l
	mov.b	r1l, @er0	/* enable A21 - A23 */

#endif	/* #ifdef ENABLE_PA_CS */

#ifdef ENABLE_PB_CS

	mov.l	#H8PBDDR, er0
	mov.b	#ENABLE_PB_CS, r1l
	mov.b	r1l, @er0	/* enable CS7 */

#endif	/* #ifdef ENABLE_PB_CS */

#endif	/*  #ifdef ROM  */

	rts