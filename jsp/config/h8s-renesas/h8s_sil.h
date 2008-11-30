/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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

#ifndef _H8S_SIL_H_
#define _H8S_SIL_H_

#ifndef _MACRO_ONLY
#include <sil.h>
#endif /* _MACRO_ONLY */

/*
 *  H8S�������W�X�^�E�A�N�Z�X�C���^�t�F�[�X
 *�@�@�x�[�X�A�h���XH8S_BASE_ADDR��h8s.h�Œ�`���A
 *�@�@CPU���샂�[�h�ɂ��A�g��������B
 */

/*
 *  �x�[�X�A�h���X�̉��Z
 *�@�@UH�ŃL���X�g���Ă���̂́A�Q�̈Ӗ�������B
 *�@�@�@�E����16�r�b�g�����o��
 *�@�@�@�E���Z�̍ۂ̕����g����h��
 */
#define ADD_BASE_ADDR(addr)	(VP)(H8S_BASE_ADDR + (UW)(UH)(addr))

/*  ���W�X�^�ւ̃A�N�Z�X  */
#define h8s_reb_reg(addr)	sil_reb_mem(ADD_BASE_ADDR(addr) )
#define h8s_wrb_reg(addr, val)	sil_wrb_mem(ADD_BASE_ADDR(addr), (VB)(val))

#define h8s_reh_reg(addr)	sil_reh_mem(ADD_BASE_ADDR(addr) )
#define h8s_wrh_reg(addr, val)	sil_wrh_mem(ADD_BASE_ADDR(addr), (VH)(val))

/*
 *  �_�����Z
 */
#define h8s_orb_reg(addr, val)	h8s_wrb_reg(addr, h8s_reb_reg(addr) | (val))
#define h8s_andb_reg(addr, val) h8s_wrb_reg(addr, h8s_reb_reg(addr) & (val))

#define h8s_orh_reg(addr, val)	h8s_wrh_reg(addr, h8s_reh_reg(addr) | (val))
#define h8s_andh_reg(addr, val)	h8s_wrh_reg(addr, h8s_reh_reg(addr) & (val))

#endif /* _H8S_SIL_H_ */
