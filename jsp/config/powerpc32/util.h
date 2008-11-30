/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2004 by Industrial Technology Institute,
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
 *   �r�b�g�ԍ��̒�`
 *   �@���ӁFPowerPC�̃r�b�g�ԍ��͒ʏ�Ƌt�ɂȂ��Ă���
 *   �@�@�@�@�܂��A32�r�b�g���W�X�^��16�r�b�g���W�X�^�ł�
 *   �@�@�@�@�ŉ��ʃr�b�g�̃r�b�g�ԍ����قȂ�_�ɂ�����
 */   

/*  32�r�b�g���W�X�^�p  */
#define BIT0_32    0x80000000
#define BIT1_32    0x40000000
#define BIT2_32    0x20000000
#define BIT3_32    0x10000000
#define BIT4_32     0x8000000
#define BIT5_32     0x4000000
#define BIT6_32     0x2000000
#define BIT7_32     0x1000000
#define BIT8_32      0x800000
#define BIT9_32      0x400000
#define BIT10_32     0x200000
#define BIT11_32     0x100000
#define BIT12_32      0x80000
#define BIT13_32      0x40000
#define BIT14_32      0x20000
#define BIT15_32      0x10000
#define BIT16_32       0x8000
#define BIT17_32       0x4000
#define BIT18_32       0x2000
#define BIT19_32       0x1000
#define BIT20_32        0x800
#define BIT21_32        0x400
#define BIT22_32        0x200
#define BIT23_32        0x100
#define BIT24_32         0x80
#define BIT25_32         0x40
#define BIT26_32         0x20
#define BIT27_32         0x10
#define BIT28_32          0x8
#define BIT29_32          0x4
#define BIT30_32          0x2
#define BIT31_32          0x1

/*  16�r�b�g���W�X�^�p  */
#define BIT0_16        0x8000
#define BIT1_16        0x4000
#define BIT2_16        0x2000
#define BIT3_16        0x1000
#define BIT4_16         0x800
#define BIT5_16         0x400
#define BIT6_16         0x200
#define BIT7_16         0x100
#define BIT8_16          0x80
#define BIT9_16          0x40
#define BIT10_16         0x20
#define BIT11_16         0x10
#define BIT12_16          0x8
#define BIT13_16          0x4
#define BIT14_16          0x2
#define BIT15_16          0x1

/*  8�r�b�g���W�X�^�p  */
#define BIT0_8           0x80
#define BIT1_8           0x40
#define BIT2_8           0x20
#define BIT3_8           0x10
#define BIT4_8            0x8
#define BIT5_8            0x4
#define BIT6_8            0x2
#define BIT7_8            0x1

/*  �V���{�����̕�����  */
#define _TO_STRING(arg)	#arg
#define TO_STRING(arg)	_TO_STRING(arg)

#endif /* _UTIL_H_ */
/*  end of file  */
