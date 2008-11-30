/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 * 
 *  @(#) $Id: cpu_defs.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *	�v���Z�b�T�Ɉˑ������`�iPowerPC�p�j
 *�@�@�@�@�@�A�v���P�[�V�������K�v�Ƃ����`
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define POWERPC32			/* �v���Z�b�T���� */

/* �J�[�l���N�����̃��b�Z�[�W   */
#define COPYRIGHT_CPU \
"Copyright (C) 2001-2004 by Industrial Technology Institute,\n" \
"                            Miyagi Prefectural Government, JAPAN\n"

#ifndef _MACRO_ONLY

/*
 *  �����݁^CPU��O�n���h���ԍ��̌^
 */
typedef	UINT	INHNO;		/* �����݃n���h���ԍ� */
typedef	UINT	EXCNO;		/* CPU��O�n���h���ԍ� */


/*
 *  �����݃}�X�N�̌^�Ɗ����݃}�X�N�̕ύX�^�Q��
 *�@�@�@IPM��sys_defs.h�Œ�`���Ă���
 */
extern ER	chg_ipm(IPM ipm) throw();
extern ER	get_ipm(IPM *p_ipm) throw();

#endif /* _MACRO_ONLY */

/*
 *  SIL�֘A�̒�`
 */

/*
 *  �����݃��b�N��Ԃ̐���
 *  �@�@sil.h�ŗp�ӂ��Ă���f�t�H���g�̏����ł̓R���e�L�X�g�̔��ʂ��s��
 *  �@�@�Ă���BPowerPC�̊����݃��b�N�̎����ł̓R���e�L�X�g�̔��ʂ��K�v
 *  �@�@�Ȃ��̂ŁA�@��ˑ����Œ�`���Ă���B
 */
#define	SIL_PRE_LOC	UW _msr_ = current_msr()
#define	SIL_LOC_INT()	disint()
#define	SIL_UNL_INT()	set_msr(_msr_)


#endif /* _CPU_DEFS_H_ */
/*  end of file  */
