/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003, 2007 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
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
 *  @(#) $Id: makeoffset.c,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */


/*
 *	offset.inc (�������� offset.h) �ɂ���
 *
 *	  offset.inc �͍\���̂̓���̗v�f���\���̂̐擪���牽�o�C�g�ڂ�
 *	���݂��邩�Ƃ������Ƃ�, ����̃r�b�g�t�B�[���h���擪����
 *	���o�C�g��̉��r�b�g�ڂɑ��݂��邩, �Ƃ�������
 *	�A�Z���u������t�@�C���ɗ^���邽�߂ɑ��݂��Ă���.
 *
 *	  offset.inc �t�@�C���̒��g��, �P�Ȃ�V���{����`�t�@�C���ł���.
 *	�V���{���Ƃ����Ă���`����V���{���̖��̂ɂ̓p�^�[��������,
 *	�傫�������Ď���3��ނɕ��ނł���.
 *
 *	<�\���̖�>_<�v�f��>	(��) TCB_sp, TCB_pc, TCB_enatex �Ȃ�
 *	<�\���̖�>_<�v�f��>_bit	(��) TCB_enatex_bit �Ȃ�
 *	<�\���̖�>_<�v�f��>_mask (��) TCB_enatex_mask �Ȃ�
 *
 *	(��)
 *		TCB_texptn	.equ	14
 *		TCB_sp	.equ	20
 *		TCB_pc	.equ	22
 *		TCB_enatex	.equ	12
 *		TCB_enatex_bit	.equ	14
 *		TCB_enatex_mask	.equ	4000H
 *
 *	  ��Ԃ͂��߂͓���̗v�f���\���̂̐擪���牽�o�C�g��ɂ��邩
 *	�Ƃ������Ƃ��������l�ɂ��郉�x���̖���.
 *	  ��Ԗڂ͓���̃r�b�g�t�B�[���h���̃r�b�g��, ���ʂ��琔����
 *	���r�b�g�ڂɂ��邩�Ƃ������Ƃ��������l�ɂ��郉�x���̖���. 
 *	0����n�܂鐔�l�ŕ\������. �ł����ʂ̃r�b�g�͑�0�r�b�g�ł���.
 *	  �O�Ԗڂ͐�قǂ� <�\���̖�>_<�v�f��>_bit �Ƃ��֘A���邪,
 *	����̃r�b�g�t�B�[���h���̃r�b�g�̃}�X�N�l�̖���.
 *	_bit �� *_mask �̒l�̊Ԃɂ͎��̊֌W������.
 *		(*_mask) == (1 << *_bit)
 *	(��) TCB_enatex_bit �� 14 �̎�, TCB_enatex_mask �� 4000H
 *
 *	  ���Ȃ݂�M16C�ˑ����̎����ł�, ����r�b�g�̃`�F�b�N�Ȃǂ�
 *	�r�b�g���߃A�h���b�V���O���g�p���Ă���̂� *_mask �Ƃ������x����
 *	�g�p���Ă��Ȃ�.
 */

#include "jsp_kernel.h"
#include "task.h"

static const TCB	____BEGIN_OFF_TCB_texptn = {
		{ NULL, NULL }, NULL, 0, 0,
		FALSE, FALSE, FALSE,
		1, NULL, { NULL, NULL }
	};

static const TCB	____BEGIN_OFF_TCB_sp = {
		{ NULL, NULL }, NULL, 0, 0,
		FALSE, FALSE, FALSE,
		0, NULL, { (void *)1, NULL }
	};

static const TCB	____BEGIN_OFF_TCB_pc = {
		{ NULL, NULL }, NULL, 0, 0,
		FALSE, FALSE, FALSE,
		0, NULL, { NULL, (FP)1 }
	};

static const TCB	____BEGIN_BIT_TCB_enatex = {
		{ NULL, NULL }, NULL, 0, 0,
		FALSE, FALSE, TRUE,
		0, NULL, { NULL, NULL }
	};
