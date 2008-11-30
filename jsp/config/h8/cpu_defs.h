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
 *  @(#) $Id: cpu_defs.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�v���Z�b�T�Ɉˑ������`�iH8�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#include <h8.h>		/*  IPM_LEVEL0,1,2�̒�`  */
#define H8

/* �J�[�l���N�����̃��b�Z�[�W */
#define COPYRIGHT_CPU \
"Copyright (C) 2001-2007 by Industrial Technology Institute,\n" \
"                            Miyagi Prefectural Government, JAPAN\n" \
"Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering\n" \
"                 Tomakomai National College of Technology, JAPAN\n" \
"Copyright (C) 2003-2004 by Katsuhiro Amano\n"

/*
 *  �^�C���e�B�b�N�̒�`
 */

#define	TIC_NUME	1		/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1		/* �^�C���e�B�b�N�̎����̕��� */

/*
 *  CPU �̃o�C�g���Ɋւ����`
 */

#define SIL_ENDIAN		SIL_ENDIAN_BIG

#ifndef _MACRO_ONLY
typedef	UINT	INHNO;			/* �����݃n���h���ԍ� */
typedef	UINT	EXCNO;			/* CPU��O�n���h���ԍ� */
#endif /* _MACRO_ONLY */

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̃T�[�r�X�R�[��
 *
 * cpu_defs.h��sys_defs.h���C���N���[�h���鏇�Ԃ̊֌W��
 * SUPPORT_CHG_IPM�}�N����SUPPORT_VXGET_TIM�}�N���ł͈͂܂Ȃ�
 * �i_MACRO_ONLY�}�N���ň͂߂΁A�\���j
 */

/*
 *  �����݃}�X�N�̌^�Ɗ����݃}�X�N�̕ύX�^�Q��
 */
#ifndef _MACRO_ONLY
typedef UB              IPM;            /* �����݃}�X�N */

extern ER       chg_ipm(IPM ipm) throw();
extern ER       get_ipm(IPM *p_ipm) throw();


/*
 *  �v���C�I���e�B���x���ݒ�p�̃f�[�^�\��
 */
typedef struct {
        UB *ipr;        /* �ݒ肷��IPR���W�X�^�̔Ԓn */
        UB bit;         /* IPR���W�X�^�̊Y������r�b�g�ԍ� */
        IPM ipm;        /* �ݒ肷�銄���݃��x�� */
                        /* IPM_LEVEL0,IPM_LEVEL1�̂����ꂩ */
} IRC;                  /* IRC:Interrupt Request Controller */


/*
 *  ���\�]���p�V�X�e�������v���@�\
 */

/* ���\�]���p�V�X�e������ */
#ifdef _int64_		/*  64�r�b�g������������  */
typedef	UD  SYSUTIM;
#else 	/*  _int64_  */
typedef	UW  SYSUTIM;
#endif	/*  _int64_  */

extern ER   vxget_tim(SYSUTIM *pk_sysutim) throw();

/*
 *  �V�X�e���̒��f����
 */

Inline void
kernel_abort (void)
{
	while (1)
		;
}

#endif /* _MACRO_ONLY */

#endif /* _CPU_DEFS_H_ */
