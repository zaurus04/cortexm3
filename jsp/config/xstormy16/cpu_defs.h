/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2005 by Embedded and Real-Time Systems Laboratory
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
 */

/*
 *  �v���Z�b�T�Ɉˑ������`�iXstormy16�p�j
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

/*
 *  �v���Z�b�T����
 */
#define XSTORMY16

/*
 *  �����݁^CPU��O�n���h���ԍ��̌^
 */
#ifndef _MACRO_ONLY
typedef UINT INHNO;         /* �����݃n���h���ԍ� */
typedef UINT EXCNO;         /* CPU��O�n���h���ԍ� */
#endif /* _MACRO_ONLY */

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN SIL_ENDIAN_LITTLE

/*
 *  �����݃n���h���ԍ�
 */
#define TNUM_INTERRUPT 17   /* ���荞�ݗv���� */
#define INHNO_WATCHDOG 0    /* ���b�`�h�b�O�^�C�}�[���荞�݃n���h���ԍ� */
#define INHNO_BASETIMER 1   /* �x�[�X�^�C�}�[���荞�݃n���h���ԍ� */
#define INHNO_TIMER0 2      /* �^�C�}�[0���荞�݃n���h���ԍ� */
#define INHNO_TIMER1 3      /* �^�C�}�[1���荞�݃n���h���ԍ� */
#define INHNO_UART 16       /* UART���荞�݃n���h���ԍ� */

/*
 *  CPU��O�n���h���ԍ�
 */
#define TNUM_EXCEPTION 4    /* ��O�v���� */
#define EXCNO_UDINST 0      /* ����`���ߗ�O�n���h���ԍ� */
#define EXCNO_WORDODD 1     /* ��Ԓn�ւ̃��[�h�A�N�Z�X��O�n���h���ԍ� */
#define EXCNO_OUTRANGE 2    /* �������͈͊O�A�N�Z�X��O�n���h���ԍ� */
#define EXCNO_UNKNOWN 3     /* �s����CPU��O�n���h���ԍ� */

#ifndef _MACRO_ONLY

/*
 *  �^�C���e�B�b�N�̒�`
 */
extern UINT _kernel_tic_nume ;          /* �^�C���e�B�b�N�̎����̕��q */
#define TIC_NUME    _kernel_tic_nume    /*     (global�ϐ��Ƃ��Ē�`) */
#define TIC_DENO    1u                  /* �^�C���e�B�b�N�̎����̕��� */

/*
 *  �f�o�b�O�p�u���[�N�|�C���g
 */
#define __BREAKPOINT() { __asm__( "nop" ); __asm__( ".hword 0x0007" ); }

/*
 *  stdio�p�჌�x�����o�͊֐�
 */
extern int _write ( int fd, char *buf, int nbytes ) ;
extern int _read ( int fd, char *buf, int nbytes ) ;

#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
