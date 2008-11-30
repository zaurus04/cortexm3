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

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/* ���L�ɂė��p���Ă���AMAX_IPM �� cpu_config.h �Œ�` */

#ifndef _MACRO_ONLY

/*
 *  ���䃌�W�X�^�̑���֐�
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
 *  �G�N�X�e���h���W�X�^�iEXR�j�̌��ݒl�̓Ǐo��
 *�@�@UB current_exr(void);
 *�@�@�@���@unsigned char get_exr(void);
 */
#define current_exr	get_exr

/*
 *  �G�N�X�e���h���W�X�^�iEXR�j�̌��ݒl�̕ύX
 *�@�@�g�ݍ��݊֐���set_exr()�����̂܂܎g���B
 *�@�@void set_exr(unsigned char exr);
 */

/*
 *  �����݃}�X�N���색�C�u���� (�����݃��[�h�Q�p)
 */

/*
 *  �����݃}�X�N�̌��ݒl�̓Ǐo��
 *�@�@IPM current_intmask(void);
 *�@�@�@���@unsigned char get_imask_exr(void);
 */
#define current_intmask		(IPM)get_imask_exr

/*
 *  �����݃}�X�N�̐ݒ�
 *�@�@�@�E����intmask�͈̔̓`�F�b�N�͏ȗ����Ă���B
 */
#define set_intmask(intmask)	set_imask_exr(intmask)

/* �p���`
 *�@�@�J�[�l���Ǘ����̊����� �� �����݃��x����MAX_IPM �ȉ��̊�����
 *�@�@�J�[�l���Ǘ��O�̊����� �� �v���C�I���e�B���x��(MAX_IPM+1)
 *�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�ȏ�̊����݂�NMI
 */

/*
 *  �J�[�l���Ǘ����̊����݂��֎~
 *�@�@�@�EEXR���W�X�^�̃g���[�X�r�b�gT�̕ۑ��͏ȗ����Ă���B
 */
#define disint()	set_intmask( (UB)MAX_IPM )

/*
 *  �J�[�l���Ǘ����̊����݂�����
 *�@�@�@�EEXR���W�X�^�̃g���[�X�r�b�gT�̕ۑ��͏ȗ����Ă���B
 *�@�@�@�E���̏����́A������A�J�[�l���Ǘ����̗L�����킸�A
 *�@�@�@�@���ׂĂ̊����݂������邱�ƂɂȂ��Ă���B
 */
#define enaint()	set_intmask( (UB)0 )

/*
 *  �����݃��b�N��Ԃ̐���p�֐�
 */

/*
 *  �J�[�l���Ǘ��O���܂߂Ă��ׂĂ̊����݂��֎~ (NMI������)
 *�@�@�@�EEXR���W�X�^�̃g���[�X�r�b�gT�̕ۑ��͏ȗ����Ă���B
 */
#define _disint_()	set_exr( EXR_I_MASK )


#endif /* _MACRO_ONLY */

#endif /* _CPU_INSN_H_ */
