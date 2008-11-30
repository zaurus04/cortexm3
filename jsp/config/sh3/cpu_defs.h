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
 *  @(#) $Id: cpu_defs.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  �v���Z�b�T�Ɉˑ������`�iSH3/4�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

/*
 *  �v���Z�b�T�Ɉˑ������`
 */
#ifndef _MACRO_ONLY

/*
 * ������/CPU��O�n���h���ԍ��̌^
 */
typedef	UINT		INHNO;		/* �����݃n���h���ԍ� */
typedef	UINT		EXCNO;		/* CPU��O�n���h���ԍ� */


/*
 * �����݃}�X�N�̌^�Ɗ����݃}�X�N�̕ύX/�Q��
 */
typedef	UINT		IPM;		/* �����݃}�X�N */

extern ER	chg_ipm(IPM ipm)  throw();
extern ER	get_ipm(IPM *p_ipm)  throw();


/*
 *  INTNO�^�Ɗ����݂̋֎~/����
 */
typedef	UINT		INTNO;		/* �����ݔԍ� */

extern ER	dis_int(INTNO intno)  throw();
extern ER	ena_int(INTNO intno)  throw();


/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̃T�[�r�X�R�[��
 */
typedef	UD  SYSUTIM;	       /* ���\�]���p�V�X�e������ */
extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

/*
 * ���݂̊����݃}�X�N�̓Ǐo��
 */
Inline UW
_current_intmask_()
{
    UW sr;

    Asm("stc  sr,%0" : "=r"(sr));
    return(sr & 0x000000f0);
}

/*
 *  �S�Ă̊����݂��֎~
 */
Inline void
_disint_()
{
    UW sr;

    Asm("stc  sr,%0" : "=r"(sr));
    sr |= 0x000000f0;
    Asm("ldc %0, sr" : : "r"(sr) );
}

/*
 *  �����݃}�X�N�̐ݒ�
 */
Inline void
_set_intmask_(UW intmask)
{
    UW sr;
    
    Asm("stc  sr,%0" : "=r"(sr));
    sr = (sr & ~0x000000f0) | intmask;
    Asm("ldc %0, sr" : : "r"(sr) );    
}


/*
 * �����݃��b�N��Ԃ̐���
 */
#define SIL_PRE_LOC UW _intmask_ = _current_intmask_()
#define SIL_LOC_INT()   _disint_()
#define SIL_UNL_INT()   _set_intmask_(_intmask_)


#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
