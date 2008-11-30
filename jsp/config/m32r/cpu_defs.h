/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2006 by Monami Software Limited Partnership, JAPAN	
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
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
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g�� *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: cpu_defs.h,v 1.1 2008/06/17 00:04:58 suikan Exp $
 */

/*
 *	�v���Z�b�T�Ɉˑ������`�iM32R�p�j
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define M32R

/* ��O�v���ԍ� */
#define NUM_EXCEPTION	20

#define EXC_RESET	0
#define EXC_SBI		1
#define EXC_RIE		2
#define EXC_AE		3
#define EXC_TRAP00	4
#define EXC_TRAP01	5
#define EXC_TRAP02	6
#define EXC_TRAP03	7
#define EXC_TRAP04	8
#define EXC_TRAP05	9
#define EXC_TRAP06	10
#define EXC_TRAP07	11
#define EXC_TRAP08	12
#define EXC_TRAP09	13
#define EXC_TRAP10	14
#define EXC_TRAP11	15
#define EXC_TRAP12	16
#define EXC_TRAP13	17
#define EXC_TRAP14	18
#define EXC_TRAP15	19

/* �����ݗv���ԍ� */
#define INT_INT0	1
#define INT_INT1	2
#define INT_INT2	3
#define INT_INT3	4
#define INT_INT4	5
#define INT_INT5	6
#define INT_INT6	7
#define INT_MFT0	16
#define INT_MFT1	17
#define INT_MFT2	18
#define INT_MFT3	19
#define INT_MFT4	20
#define INT_MFT5	21
#define INT_DMA0	32
#define INT_SIO0RCV	48
#define INT_SIO0XMT	49
#define INT_SIO1RCV	50
#define INT_SIO1XMT	51
#define INT_SIO2RCV	52
#define INT_SIO2XMT	53
#define INT_SIO3RCV	54
#define INT_SIO3XMT	55
#define INT_SIO4RCV	56
#define INT_SIO4XMT	57


#ifndef _MACRO_ONLY

typedef unsigned int   INHNO;		/* �����݃n���h���ԍ�  */
typedef unsigned char  IPR;			/* �����ݗD��x        */
typedef unsigned int   EXCNO;		/* CPU��O�n���h���ԍ� */

/* �J�[�l���N�����̃��b�Z�[�W */
#define COPYRIGHT_CPU \
"Copyright (C) 2006 by Monami Software Limited Partnership, JAPAN\n" \
"Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory\n" \
"            Graduate School of Information Science, Nagoya Univ., JAPAN\n"

#endif /* _MACRO_ONLY */
#endif /* _CPU_DEFS_H_ */
