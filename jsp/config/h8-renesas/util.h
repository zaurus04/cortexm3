/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2007 by Industrial Technology Institute,
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
#define BIT0              0x1u
#define BIT1              0x2u
#define BIT2              0x4u
#define BIT3              0x8u
#define BIT4             0x10u
#define BIT5             0x20u
#define BIT6             0x40u
#define BIT7             0x80u
#define BIT8            0x100u
#define BIT9            0x200u
#define BIT10           0x400u
#define BIT11           0x800u
#define BIT12          0x1000u
#define BIT13          0x2000u
#define BIT14          0x4000u
#define BIT15          0x8000u
#define BIT16         0x10000ul
#define BIT17         0x20000ul
#define BIT18         0x40000ul
#define BIT19         0x80000ul
#define BIT20        0x100000ul
#define BIT21        0x200000ul
#define BIT22        0x400000ul
#define BIT23        0x800000ul
#define BIT24       0x1000000ul
#define BIT25       0x2000000ul
#define BIT26       0x4000000ul
#define BIT27       0x8000000ul
#define BIT28      0x10000000ul
#define BIT29      0x20000000ul
#define BIT30      0x40000000ul
#define BIT31      0x80000000ul


/*
 *  �V���{�����̌���
 */
#define JOINT(a,b)      _JOINT(a,b)
#define _JOINT(a,b)     a##b

#define JOINT3(a,b,c)   _JOINT3(a,b,c)
#define _JOINT3(a,b,c)  JOINT(a,JOINT(b,c))

#define JOINT4(a,b,c,d)   _JOINT4(a,b,c,d)
#define _JOINT4(a,b,c,d)  JOINT(a,JOINT3(b,c,d))

#define HI2(data)	(UH)(data >> 16)
#define LO2(data)	(UH)(data)

#endif /* _UTIL_H_ */
