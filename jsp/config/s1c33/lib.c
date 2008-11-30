/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
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
#include	"smcvals.h"
#include	"stdio.h"
#include	"cpu_rename.h"

FILE	_iob[FOPEN_MAX + 1];		/* standard i/o stream */

FILE	*stdin; 			/* standard input */
FILE	*stdout;			/* standard output */
FILE	*stderr;			/* standard error */

int 	errno;				/* error number */

unsigned int  seed; 			/* seed of random value */

unsigned char *ucNxtAlcP;	/* next memory allocate address */
unsigned char *ucBefAlcP;	/* one previous allocated address */
unsigned char *end_alloc;	/* end memory allocate address */

#ifndef DBL_LNG_TYPE

#define DBL_LNG_TYPE

/*  the architecture of double floating point
 *
 *   0 1          11                  31 32                               63 bit
 *   -----------------------------------------------------------------------
 *  | |   exponent  |                    fraction                           |
 *   -----------------------------------------------------------------------
 *
 *  |               |                   |                                   |
 *  |     12bits          20 bits       |             32 bits               |
 *  |            lower word             |            higher word            |
 *
 *         bit    0         sign bit         (  1 bit  )
 *              1 - 11      exponent part    ( 11 bits )
 *             12 - 63      fraction part    ( 52 bits )
 *
 */

typedef union {
		struct {
#ifdef	BIG_ENDIAN
			unsigned long _LL;
			unsigned long _LH;
#else
			unsigned long _LH;
			unsigned long _LL;
#endif
		} st;
	} DBL_LNG;

#endif

DBL_LNG _HUGE;				/* HUGE VALUE */

unsigned char *_STACK_TOP;		/* address of stack top */
unsigned char *_STACK_BOTTOM;		/* address of stack bottom */

long gm_sec;

/*
 * initialize routine
 */

void init_lib()
{

  /* initialize allocate address */
  end_alloc = (unsigned char *)_STACK_TOP;
  ucNxtAlcP = (unsigned char *)(_BOUND((unsigned long)_STACK_BOTTOM));
  ucBefAlcP = (unsigned char *)NULL;

  errno = 0;				/* clear error number */

  seed = 1; 				/* initialize random seed */

  gm_sec = -1;				/* initialize time */

  _HUGE.st._LL = 0x7ff00000;		/* HUGE VALUE */
  _HUGE.st._LH = 0;

/*
 *  INITIALIZE STANDARD STREAMS
 */

  _iob[0]._flg = _UGETN;		/* initialize stdin stream */
  _iob[0]._buf = 0;
  _iob[0]._fd = 0;

  _iob[1]._flg = _UGETN;		/* initialize stdout stream */
  _iob[1]._buf = 0;
  _iob[1]._fd = 1;

  _iob[2]._flg = _UGETN;		/* initialize stderr stream */
  _iob[2]._buf = 0;
  _iob[2]._fd = 2;

  stdin = &_iob[0];
  stdout = &_iob[1];
  stderr = &_iob[2];

}

