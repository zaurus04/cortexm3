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
 *  @(#) $Id: sys_defs.h,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

/*
 *  �^�[�Q�b�g�V�X�e���Ɉˑ������`�im3a_za36/10MHz�j
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

#define m3a_za36

/*
 *  �������}�b�v�h���W�X�^
 */

/* �����݊֘A�̃��W�X�^ */
#define ICUISTS		0xeff004
#define ICUIREQ0	0xeff008
#define ICUIREQ1	0xeff00c
#define ICUSBICR	0xeff018
#define ICUIMASK	0xeff01c

#define __ICUCR(x)	ICUCR_##x
#define _ICUCR(x)	__ICUCR(x)
#define ICUCR_INT	0xeff200
#define ICUCR_MFT	0xeff23c
#define ICUCR_SIO	0xeff2bc
#define ICUCR(x,y)	(_ICUCR(x) + (0x4*y))

/* �^�C�}�֘A���W�X�^ */
#define MFTCR			0xefc000
#define MFTRPR			0xefc004
#define MFTMOD(x)		(0xefc100 + ((x) * 0x100))
#define MFTBOS(x)		(0xefc104 + ((x) * 0x100))
#define MFTCUT(x)		(0xefc108 + ((x) * 0x100))
#define MFTRLD(x)		(0xefc10c + ((x) * 0x100))
#define MFTMCMPRLD(x)	(0xefc110 + ((x) * 0x100))

/* �V���A���֘A���W�X�^ */
#define SIOCR(x)	(0xefd000 + ((x) * 0x100))
#define SIOMOD0(x)	(0xefd004 + ((x) * 0x100))
#define SIOMOD1(x)	(0xefd008 + ((x) * 0x100))
#define SIOSTS(x)	(0xefd00c + ((x) * 0x100))
#define SIOTRCR(x)	(0xefd010 + ((x) * 0x100))
#define SIOBAUR(x)	(0xefd014 + ((x) * 0x100))
#define SIORBAUR(x)	(0xefd018 + ((x) * 0x100))
#define SIOTXB(x)	(0xefd01c + ((x) * 0x100))
#define SIORXB(x)	(0xefd020 + ((x) * 0x100))

/* �v���O���}�u��I/O�|�[�g�֘A���W�X�^ */
#define PIEN		0xef1000
#define PDATA(x)	(0xef1020+(x))
#define PDIR(x)		(0xef1040+(x))
#define PMOD(x)		(0xef1060+((x)*2))
#define PODCR(x)	(0xef1080+((x)*2))

/* �O���o�X�R���g���[�� */
#define BSELCR(x)	(0xef5000 + ((x)*4))

/* SDRAM�R���g���[�� */
#define SDRF0		0xef6000
#define SDRF1		0xef6004
#define SDIR0		0xef6008
#define SDIR1		0xef600c
#define SDBR		(0xef6010)
#define SDADR(x)	(0xef6020 + ((x)*32))
#define SDER(x)		(0xef6024 + ((x)*32))
#define SDTR(x)		(0xef6028 + ((x)*32))
#define SDMOD(x)	(0xef602c + ((x)*32))

/* CPU���샂�[�h�֘A�̃��W�X�^ */
#define CPUCLKCR	0xef4000
#define CLKMOD		0xef4004
#define PLLCR		0xef4008

#ifndef _MACRO_ONLY

/*
 *  INTNO�^�Ɗ����݂̋֎~/����
 */
typedef	unsigned char INTNO;		/* �����ݔԍ� */

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̃T�[�r�X�R�[��
 */
typedef	unsigned long SYSUTIM;	/* ���\�]���p�V�X�e������ */

Inline void kernel_abort(void)
{
    extern void _kernel_sys_exit(void);
    _kernel_sys_exit();
}

extern ER	vxget_tim(SYSUTIM *pk_sysutim);

#endif /* _MACRO_ONLY */

/*
 *  �^�C���e�B�b�N�̒�`
 */
#define	TIC_NUME	1		/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1		/* �^�C���e�B�b�N�̎����̕��� */

#endif /* _SYS_DEFS_H_ */
