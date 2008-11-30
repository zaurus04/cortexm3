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
 *  @(#) $Id: cpu_insn.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

#ifndef _CPU_INSN_H_
#define _CPU_INSN_H_

/*
 *      �v���Z�b�T�̓��ꖽ�߂̊֐���`�iH8�p�j
 */

#include <machine.h>	/*  �����n�̑g�ݍ��݊֐�  */

/*
 *  �R���f�V�����R�[�h���W�X�^�iCCR�j�̌��ݒl�̓Ǐo��
 *�@�@UB current_ccr(void);
 *�@�@�@���@unsigned char get_ccr(void);
 */
#define current_ccr	get_ccr

/*
 *  �R���f�V�����R�[�h���W�X�^�iCCR�j�̌��ݒl�̕ύX
 *�@�@�g�ݍ��݊֐���set_ccr()�����̂܂܎g���B
 *�@�@void set_ccr(unsigned char ccr);
 */

/*
 *  NMI���������ׂĂ̊����݂��֎~
 */
#define disint()	or_ccr(CCR_DISINT_ALL)

/*
 *  ���ׂĂ̊����݂�����
 */
#define enaint()	and_ccr(CCR_ENAINT_ALL)

/*
 * �r�b�g�Z�b�g�ƃr�b�g�N���A
 */

/*
 * �r�b�g�p�^�[���ƃ}�X�N�p�^�[��
 */
#define H8BIT2PATTERN(bit)	(0x1u << (UINT)(bit))
#define H8BIT2MASK(bit)		((~H8BIT2PATTERN(bit)) & 0xffu)

/*
 * �r�b�g���Z�b�g
 */
#define bitset(p, bit)	((*(volatile UB *)(p)) |= (UB)H8BIT2PATTERN(bit))

/*
 * �r�b�g���N���A
 */
#define bitclr(p, bit)	((*(volatile UB *)(p)) &= (UB)H8BIT2MASK(bit))


#endif /* _CPU_INSN_H_ */
