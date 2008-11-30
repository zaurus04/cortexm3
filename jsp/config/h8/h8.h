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
 *  @(#) $Id: h8.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#ifndef _H8_H_
#define _H8_H_

/*
 *  H8 �p��`
 */

/*
 *  ���l�f�[�^�����񉻗p�}�N��
 */

#define TO_STRING(arg)	#arg
#define _TO_STRING(arg)	TO_STRING(arg)

/* Condition Code Register (CCR) */

#define H8CCR_I_BIT		7
#define H8CCR_UI_BIT		6
#define H8CCR_H_BIT		5
#define H8CCR_U_BIT		4
#define H8CCR_N_BIT		3
#define H8CCR_Z_BIT		2
#define H8CCR_V_BIT		1
#define H8CCR_C_BIT		0

#define H8CCR_I			(1<<H8CCR_I_BIT)
#define H8CCR_UI		(1<<H8CCR_UI_BIT)
#define H8CCR_H			(1<<H8CCR_H_BIT)
#define H8CCR_U			(1<<H8CCR_U_BIT)
#define H8CCR_N			(1<<H8CCR_N_BIT)
#define H8CCR_Z			(1<<H8CCR_Z_BIT)
#define H8CCR_V			(1<<H8CCR_V_BIT)
#define H8CCR_C			(1<<H8CCR_C_BIT)

/* CCR �� I�r�b�g��UI�r�b�g�����荞�݃}�X�N�r�b�g�Ƃ��Ďg�p����B*/

#define H8INT_MASK_ALL		(H8CCR_I | H8CCR_UI)

#define H8INT_DIS_ALL		H8INT_MASK_ALL
#define H8INT_ENA_ALL		(0xff & ~(H8INT_MASK_ALL))

#define str_H8INT_DIS_ALL	_TO_STRING(H8INT_DIS_ALL)
#define str_H8INT_ENA_ALL	_TO_STRING(H8INT_ENA_ALL)

/*
 *  ���x���O�@���ׂĂ̊����݂��󂯕t����
 */
#define IPM_LEVEL0      0

/*
 *  ���x���P�@NMI����уv���C�I���e�B���x���P�̊����݂݂̂��󂯕t����
 */
#define IPM_LEVEL1      H8CCR_I

/*
 *  ���x���Q�@NMI�ȊO�̊����݂��󂯕t���Ȃ�
 */
#define IPM_LEVEL2      (H8CCR_I | H8CCR_UI)


#endif /* _H8_H_ */
