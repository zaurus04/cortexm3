/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */

/*
 *  �v���Z�b�T�Ɉˑ������`(S1C33�p)
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define S1C33

/*
 *  CPU �̃o�C�g���Ɋւ����`
 */

#define SIL_ENDIAN		SIL_ENDIAN_LITTLE

#ifndef _MACRO_ONLY

typedef UINT	INHNO;		/* �����݃n���h���ԍ�	*/
typedef UINT	EXCNO;		/* CPU��O�n���h���ԍ�	*/
typedef UINT	ILEVNO;		/* �����݃��x��		*/

/*
 *  �����݃��x���ύX�^�擾����
 */
extern	ER	chg_ilv(ILEVNO ilevno);
extern	ER	get_ilv(ILEVNO *p_ilevno);

/*
 *  �����݋��^�֎~����
 */
typedef UINT	INTNO;		/* �����ݔԍ�		*/

/*
 *  �ˑ��֌W�ɂ�肱���Ń��l�[��
 */
#define ena_int		_kernel_ena_int
#define dis_int		_kernel_dis_int

#ifdef LABEL_ASM
#define _ena_int	__kernel_ena_int
#define _dis_int	__kernel_dis_int
#endif /* LABEL_ASM */

extern	ER	ena_int(INTNO intno);
extern	ER	dis_int(INTNO intno);

/*
 *  ���݂̊����݋��t���O�̓Ǐo��
 */
Inline UW
_current_intflag_(void)
{
	UW	psr;

	Asm("ld.w %0, %%psr" : "=r"(psr));
	return(psr & 0x00000010);
}

/*
 *  NMI���������ׂĂ̊����݂��֎~
 */
Inline void
_disint_(void)
{
	UW	psr;

	Asm("ld.w %0, %%psr" : "=r"(psr));
	psr &= 0xffffffef;
	Asm("ld.w %%psr, %0" : : "r"(psr));
}

/*
 *  �����݋��t���O�̕���
 */
Inline void
_enaint_(UW intmask)
{
	UW	psr;

	Asm("ld.w %0, %%psr" : "=r"(psr));
	psr |= intmask;
	Asm("ld.w %%psr, %0" : : "r"(psr));
}

/*
 *  �����݃��b�N��Ԃ̐���
 */
#define SIL_PRE_LOC	UW _intmask_ = _current_intflag_()
#define SIL_LOC_INT()	_disint_()
#define SIL_UNL_INT()	_enaint_(_intmask_)

#define OMIT_VGET_TIM

typedef	UW  SYSUTIM;		/* ���\�]���p�V�X�e������ */

extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

/*
 *  �V�X�e���̒��f����
 */

Inline void
kernel_abort (void)
{
	while (1){
		;
	}
}

#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
