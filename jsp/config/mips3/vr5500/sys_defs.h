/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

/*
 *  �v���Z�b�T�^�C�v
 */
#define VR5500

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�{�[�h��
 */
#define	TARGET_NAME	"RTE-VR5500-CB(64)"

/*
 *  INTNO�^�Ɗ����݂̋֎~/����
 */
#ifndef _MACRO_ONLY

typedef	UINT	INTNO;			/* �����ݔԍ��iicu_set_ilv�ŗ��p�j */

#if 0		/*  MIPS3�łł̓T�|�[�g���Ă��Ȃ�  */
extern ER	dis_int(INTNO intno) throw();
extern ER	ena_int(INTNO intno) throw();
#endif

#endif /* _MACRO_ONLY */

/*
 *  �^�C���e�B�b�N�̒�`
 */
#define	TIC_NUME	1		/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1		/* �^�C���e�B�b�N�̎����̕��� */

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̃T�[�r�X�R�[��
 */
#ifndef _MACRO_ONLY

typedef	UD 	SYSUTIM;		/* ���\�]���p�V�X�e������ */
extern	ER	vxget_tim(SYSUTIM *pk_sysutim) throw();

#endif /* _MACRO_ONLY */

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define	SIL_ENDIAN	SIL_ENDIAN_LITTLE	/* ���g���G���f�B�A�� */

#ifndef _MACRO_ONLY

/*  �����݃R���g���[���̊����݃}�X�N�̌^��`  */
typedef struct{
	UB	int0m;			/*  �}�X�N���W�X�^1  */
	UB	int1m;			/*  �}�X�N���W�X�^2  */
} ICU_IPM;

/*
 *  �V�X�e���̒�~����
 */
Inline void
kernel_abort()
{
	Asm("break");
}

#endif /* _MACRO_ONLY */

#endif /* _SYS_DEFS_H_ */
