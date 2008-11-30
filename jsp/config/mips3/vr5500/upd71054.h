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

#ifndef _UPD71054_H_
#define _UPD71054_H_

#include <s_services.h>

/*
 *  �^�C�} uPD71054(NEC) �֘A�̒�`
 */

/* uPD71054�̃��W�X�^�̃A�h���X */
#define PCNT0		0x00
#define PCNT1		0x10
#define PCNT2		0x20
#define PCNTL		0x30

/* control word foemat */
#define BINARY			0u	/* BIT0 */
#define BCD			BIT0

#define MODE_0			0u	/* BIT1, 2, 3 */
#define MODE_1			BIT1
#define MODE_2			BIT2
#define MODE_3			(BIT2 | BIT1)
#define MODE_4			BIT3
#define MODE_5			(BIT3 | BIT1)

#define COUNT_LATCH_COMM	0u	/* BIT5, 4 */
#define LOWER_BYTE		BIT4
#define HIGH_BYTE		BIT5
#define LOW_HIGH_BYTE		(BIT5 | BIT4)

#define COUNTER_0		0u	/* BIT6, 7 */
#define COUNTER_1		BIT6
#define COUNTER_2		BIT7
#define MULT_LATCH_COMM		(BIT7 | BIT6)

/* multiple latch command format */
#define SEL_COUNTER_0		BIT1
#define SEL_COUNTER_1		BIT2
#define SEL_COUNTER_2		BIT3
#define DO_NOT_LATCH_STATUS	BIT4
#define LATCH_STATUS		0u	/* BIT4 */
#define DO_NOT_LATCH_COUNT	BIT5
#define LATCH_COUNT		0u	/* BIT5 */

/*
 *  �^�C�}�̃��W�X�^�ւ̃A�N�Z�X�֐�
 */
#define upd71054_reb( addr )		sil_reb_mem( (VP)(TIMER_BASE_ADDR + addr) )
#define upd71054_wrb( addr, val )	sil_wrb_mem( (VP)(TIMER_BASE_ADDR + addr), val )

#endif /* _UPD71054_H_ */
