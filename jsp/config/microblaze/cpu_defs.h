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
 *  @(#) $Id: cpu_defs.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *  �v���Z�b�T�Ɉˑ������`�iMicroblaze�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

//#include "microblaze.h"

#ifndef MICROBLAZE
#define MICROBLAZE   /* �v���Z�b�T���� */
#endif 
/*
 *  �v���Z�b�T�Ɉˑ������`
 */
#ifndef _MACRO_ONLY

typedef	UINT		INHNO;		/* �����݃n���h���ԍ� */
typedef	UINT		IPM;		/* �����݃}�X�N */
typedef	UINT		EXCNO;		/* CPU��O�n���h���ԍ� */


/*
 *  INTNO�^�Ɗ����݂̋֎~/����
 */

typedef	UINT		INTNO;		/* �����ݔԍ� */

extern ER	dis_int(INTNO intno) throw(); 
extern ER	ena_int(INTNO intno) throw();


/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̃T�[�r�X�R�[��
 */
typedef	UW  SYSUTIM;	/* ���\�]���p�V�X�e������ */
extern  ER   vxget_tim(SYSUTIM *pk_sysutim) throw();


/*
 *  MSR�̃r�b�g
 */
#define MSR_IE 0x02
#define MSR_BE 0x01


/*
 *  ���ׂĂ̊����݂��֎~
 */
Inline void
_disint_()
{
    UW msr;
  
    Asm("mfs %0,rmsr": "=r"(msr));
    msr &= ~MSR_IE;
    Asm("mts rmsr,%0" : : "r"(msr));
}


/*
 *  �����݂�����
 */
Inline void
_enaint_()
{
    UW msr;
    
    Asm("mfs %0,rmsr": "=r"(msr));
    msr |= MSR_IE;
    Asm("mts rmsr,%0" : : "r"(msr));    
}


/*
 *  �����݃��b�N��Ԃ̐���
 */
#define SIL_PRE_LOC 
#define SIL_LOC_INT()   _disint_()
#define SIL_UNL_INT()   _enaint_()

/*
 * �V�X�e���̒��f����
 */
Inline void
kernel_abort()
{
    Asm("brki r16 0x20");
}

/*
 *  �������ԑ҂�
 */
Inline void
sil_dly_nse(UINT dlytim)
{
    Asm("add r5, r0, %0; \
         brlid r15, _sil_dly_nse; \
         nop\n"
        : 
        : "r"(dlytim)
        : "r15", "r5");
    
}


#endif /* _MACRO_ONLY */

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN  SIL_ENDIAN_BIG  /* �r�b�N�G���f�B�A�� */


#endif /* _CPU_DEFS_H_ */
