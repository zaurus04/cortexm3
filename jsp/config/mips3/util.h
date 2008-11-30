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

#ifndef _UTIL_H_
#define _UTIL_H_

/*
 *  �r�b�g�ԍ��̒�`
 */
#define BIT0              0x1
#define BIT1              0x2
#define BIT2              0x4
#define BIT3              0x8
#define BIT4             0x10
#define BIT5             0x20
#define BIT6             0x40
#define BIT7             0x80
#define BIT8            0x100
#define BIT9            0x200
#define BIT10           0x400
#define BIT11           0x800
#define BIT12          0x1000
#define BIT13          0x2000
#define BIT14          0x4000
#define BIT15          0x8000
#define BIT16         0x10000
#define BIT17         0x20000
#define BIT18         0x40000
#define BIT19         0x80000
#define BIT20        0x100000
#define BIT21        0x200000
#define BIT22        0x400000
#define BIT23        0x800000
#define BIT24       0x1000000
#define BIT25       0x2000000
#define BIT26       0x4000000
#define BIT27       0x8000000
#define BIT28      0x10000000
#define BIT29      0x20000000
#define BIT30      0x40000000
#define BIT31      0x80000000

/*
 *  �o�C�g�f�[�^����p�}�N��
 */
/* �ȉ��ɂ����āAx�F�s�� */

/* �ȉ��̂悤�ȏ������ƁA�ǂ������ǂ����H
     (UH) (((UW) (c)) & 0x0000ffff)
     (UH) (((UW) (c)) & 0xffff0000) >> 16
*/

/* (UH) xxaa -> (UB) aa */
#define LO8(c)		(UB)( (UH)(c) & 0xff )	/*  ����1�o�C�g���o��  */
/* (UH) aaxx -> (UB) aa */
#define HI8(c)		LO8( (UH)(c) >>  8 )	/*  ���1�o�C�g���o��  */

/* (UW) xxxxaaaa -> (UH) aaaa */
#define LO16(c)		(UH)( (UW)(c) & 0xffff )/*  ����2�o�C�g���o��  */
/* (UW) aaaaxxxx -> (UH) aaaa */
#define HI16(c)		LO16( (UW)(c) >> 16 )	/*  ���2�o�C�g���o��  */

/* (UH) aaaa, (UH) bbbb -> (UW) aaaabbbb */
#define JOIN16(hi, lo)	(UW)( ((UW)(hi) << 16) | (lo) )	/*  2�o�C�g�f�[�^�̌���  */
/* (UB) aa, (UB) bb -> (UH) aabb */
#define JOIN8(hi, lo)	(UH)( ((UH)(hi) <<  8) | (lo) )	/*  1�o�C�g�f�[�^�̌���  */

/* (UB) xxxxaaaa�i�Q�i���j -> (UB) ooooaaaa�i�Q�i���j */
#define TO_LO4(c)	( (UB)(c) & 0xf )		/*  0-3�r�b�g�ɔz�u  */
/* �i�Q�i���jxxxxaaaa -> �i�Q�i���jaaaaoooo */
#define TO_HI4(c)	(((UB)(c) << 4) & 0xf0)		/*  4-7�r�b�g�ɔz�u  */

/*
 *  ���l�f�[�^�����񉻗p�}�N��
 */
#define _TO_STRING(arg)	#arg
#define TO_STRING(arg)	_TO_STRING(arg)

#endif /* _UTIL_H_ */
