/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: sys_defs.h,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���Ɉˑ������`�iDVE68K/40�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

#define DVE68K			/* �V�X�e������ */

#ifndef _MACRO_ONLY

/*
 *  �����ݔԍ��̌^�Ɗ����݂̋֎~�^����
 */
#if 0 /* �����_�ł̓T�|�[�g���Ă��Ȃ� */

typedef	UINT	INTNO;		/* �����ݔԍ� */

extern ER	dis_int(INTNO intno) throw();
extern ER	ena_int(INTNO intno) throw();

#endif /* 0 */

/*
 *  ���\�]���p�V�X�e�������̎Q��
 */
typedef	UD	SYSUTIM;	/* ���\�]���p�V�X�e������ */

extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

#endif /* _MACRO_ONLY */

/*
 *  �^�C���e�B�b�N�̒�`
 */
#define	TIC_NUME	1u	/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1u	/* �^�C���e�B�b�N�̎����̕��� */

#ifndef _MACRO_ONLY

/*
 *  �V�X�e���̒�~����
 */
#ifdef GDB_STUB

Inline void
kernel_abort()
{
	Asm("trap #2");
}

#else /* GDB_STUB */

Inline void
kernel_abort()
{
	Asm("clr.l %%d0; trap #3"
	  : /* no output */
	  : /* no input */
	  : "d0", "d1", "d2", "d6", "d7");
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _SYS_DEFS_H_ */
