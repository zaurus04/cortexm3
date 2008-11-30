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
 *  @(#) $Id: c54x.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

#ifndef _C54X_H_
#define _C54X_H_

/******************************************
 *  �b�o�t �������E�}�b�v�h�E���W�X�^
 ******************************************/
#define IMR	0x0
#define IFR	0x1
#define ST0	0x6
#define ST1	0x7
#define AL	0x8
#define AH	0x9
#define AG	0xA
#define BL	0xB
#define BH	0xC
#define BG	0xD
#define T	0xE
#define TRN	0xF
#define AR0	0x10
#define AR1	0x11
#define AR2	0x12
#define AR3	0x13
#define AR4	0x14
#define AR5	0x15
#define AR6	0x16
#define AR7	0x17
#define SP	0x18
#define BK	0x19
#define BRC	0x1A
#define RSA	0x1B
#define REA	0x1C
#define PMST	0x1D
#define XPC	0x1E

/********************************************
 *   �y���t�F���� �������E�}�b�v�h�E���W�X�^
 *******************************************/
/*
 * �^�C�}�[���W�X�^
 */
#define TMU0_TIM	0x24
#define TMU0_PRD	0x25
#define TMU0_TCR	0x26

#define TMU1_TIM	0x30
#define TMU1_PRD	0x31
#define TMU1_TCR	0x32

#define TCR_TSS 0x0010
#define TCR_TRB 0x0020

/*
 *   ���荞�݃}�X�N���W�X�^(IMR)�r�b�g�t�B�[���h
 */
#define INT0           0
#define INT1           1
#define INT2           2
#define TINT0          3

#define RINT0          4
#define XINT0          5

#define TINT1          7

#define INT3           8
#define HPINT          9
#define RINT1         10
#define XINT1         11

#define DMAC0         6
#define DMAC1         7
#define DMAC2         10
#define DMAC3         11
#define DMAC4         12
#define DMAC5         13


/*
 *  ���荞�݃n���h���ԍ� INHNO
 */
#define RESET_VEC             0
#define NMI_VEC	              1
#define SINT17_VEC            2
#define SINT18_VEC            3
#define SINT19_VEC           4
#define SINT20_VEC        5
#define SINT21_VEC        6
#define SINT22_VEC        7
#define SINT23_VEC        8
#define SINT24_VEC        9
#define SINT25_VEC        10
#define SINT26_VEC        11
#define SINT27_VEC        12
#define SINT28_VEC        13
#define SINT29_VEC        14
#define SINT30_VEC        15
#define INT0_VEC        16
#define INT1_VEC        17
#define INT2_VEC        18
#define TINT0_VEC        19
#define RINT0_VEC        20
#define XINT0_VEC        21
#define DMAC0_VEC        22
#define TINT1_VEC        23
#define INT3_VEC        24
#define HPI_VEC            25
#define RINT1_VEC        26
#define XINT1_VEC        27
#define DMAC2_VEC        26
#define DMAC3_VEC        27
#define DMAC4_VEC        28
#define DMAC5_VEC        29

/*
 *  TRAP�ԍ�
 */
#define RS_TRAP           0
#define NMI_TRAP       1
#define INT0_TRAP       16
#define INT1_TRAP       17
#define INT2_TRAP       18
#define TINT_TRAP       19
#define RINT0_TRAP       20
#define XINT0_TRAP       21
#define DMAC0_TRAP       22
#define DMAC1_TRAP       23
#define INT3_TRAP       24
#define HPINT_TRAP       25
#define RINT1_TRAP       26
#define DMAC2_TRAP       26
#define XINT1_TRAP       27
#define DMAC3_TRAP       27
#define DMAC4_TRAP       28
#define DMAC5_TRAP       29

#define SINTR        0
#define SINT16        1
#define SINT17        2
#define SINT18        3
#define SINT19        4
#define SINT20        5
#define SINT21        6
#define SINT22        7
#define SINT23        8
#define SINT24        9
#define SINT25        10
#define SINT26        11
#define SINT27        12
#define SINT28        13
#define SINT29        14
#define SINT30        15
#define SINT0        16
#define SINT1        17
#define SINT2        18
#define SINT3        19
#define SINT4        20
#define SINT5        21
#define SINT6        22
#define SINT7        23
#define SINT8        24
#define SINT9        25
#define SINT10        26
#define SINT11        27
#define SINT12          28
#define SINT13          29

#endif /* _C54X_H_ */
