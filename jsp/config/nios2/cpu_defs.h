/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN  
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
 *  �v���Z�b�T�Ɉˑ������`�iNios2�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define OMIT_SIL_ACCESS

/*
 *  �G���f�B�A���̔��]
 *  sil.h�ł���`���Ă��邪�COMIT_SIL_ACCESS�ɂ�肱�̃t�@�C����
 *  �A�N�Z�X�֐����`���Ă邽�߁C�����Œ�`���� 
 */
#ifndef SIL_REV_ENDIAN_H
#define	SIL_REV_ENDIAN_H(data) \
	((VH)((((UH)(data) & 0xff) << 8) | (((UH)(data) >> 8) & 0xff)))
#endif /* SIL_REV_ENDIAN_H */

#ifndef SIL_REV_ENDIAN_W
#define	SIL_REV_ENDIAN_W(data) \
	((VW)((((UW)(data) & 0xff) << 24) | (((UW)(data) & 0xff00) << 8) \
		| (((UW)(data)>> 8) & 0xff00) | (((UW)(data) >> 24) & 0xff)))
#endif /* SIL_REV_ENDIAN_H */


#ifndef NIOS2
#define NIOS2   /* �v���Z�b�T���� */
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
typedef	UD  SYSUTIM;	/* ���\�]���p�V�X�e������ */
extern  ER  vxget_tim(SYSUTIM *pk_sysutim) throw();


/*
 *  �����݋��r�b�g
 */
#define STATUS_PIE 0x01

/*
 *  ���ׂĂ̊����݂��֎~
 */
Inline void
_disint_()
{
    UW status;
    
    Asm("rdctl %0, status" : "=r" (status));
    status &= ~STATUS_PIE;
    Asm("wrctl status, %0" :: "r" (status));
}


/*
 *  �����݂�����
 */
Inline void
_enaint_()
{
    UW status;

    Asm("rdctl %0, status" : "=r" (status));
    status |= STATUS_PIE;
    Asm("wrctl status, %0" :: "r" (status));
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

}


#endif /* _MACRO_ONLY */

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN  SIL_ENDIAN_LITTLE 

#ifndef _MACRO_ONLY

/*
 * �������A�N�Z�X�֐�
 */

/*
 *  8�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VB
sil_reb_mem(VP mem)
{
  return(__builtin_ldbuio(mem));
}

Inline void
sil_wrb_mem(VP mem, VB data)
{
    __builtin_stbio(mem, data);
}


/*
 *  16�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VH
sil_reh_mem(VP mem)
{
	return(__builtin_ldhuio(mem));
}

Inline void
sil_wrh_mem(VP mem, VH data)
{
    __builtin_sthio(mem, data);
}


#define	sil_reh_lem(mem)	sil_reh_mem(mem)
#define	sil_wrh_lem(mem, data)	sil_wrh_mem(mem, data)

Inline VH
sil_reh_bem(VP mem)
{
	VH	data;

	data = __builtin_ldhuio(mem);
	return(SIL_REV_ENDIAN_H(data));
}

Inline void
sil_wrh_bem(VP mem, VH data)
{
    __builtin_sthio(mem, SIL_REV_ENDIAN_H(data));
}


/*
 *  32�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VW
sil_rew_mem(VP mem)
{
    return(__builtin_ldwio(mem));
}

Inline void
sil_wrw_mem(VP mem, VW data)
{
    __builtin_stwio(mem, data);
}


#define	sil_rew_lem(mem)	sil_rew_mem(mem)
#define	sil_wrw_lem(mem, data)	sil_wrw_mem(mem, data)

Inline VW
sil_rew_bem(VP mem)
{
	VW	data;

	data = __builtin_ldwio(mem);
	return(SIL_REV_ENDIAN_W(data));
}

Inline void
sil_wrw_bem(VP mem, VW data)
{
    __builtin_stwio(mem, SIL_REV_ENDIAN_W(data));
}

/*
 *  �������ԑ҂�
 */
Inline void
sil_dly_nse(UINT dlytim)
{
    
}

#endif /* _MACRO_ONLY */


#endif /* _CPU_DEFS_H_ */
