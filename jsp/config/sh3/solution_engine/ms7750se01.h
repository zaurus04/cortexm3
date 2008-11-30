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
 *  @(#) $Id: ms7750se01.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *   MS7729RSE01�p�̒�`
 *   sys_defs.h ����C���N���[�h����
 */

#ifndef _MS7729RSE01_H_
#define _MS7729RSE01_H_

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define SIL_ENDIAN  SIL_ENDIAN_BIG  /* �r�b�N�G���f�B�A�� */

/*
 * �v���Z�b�T�̎��(DSP�ɂ͑Ή����Ă��Ȃ�)
 */
#define SH4
#define SH7750

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g��
 */
#define	TARGET_NAME	"MS7750SE01(CPU:SH7750 Solution Engine)"

/*
 *  �L���b�V�����[�h�̐ݒ�
 *  P0,U0,P1���C�g�X���[���[�h
 */
#define CCR_MODE      0x0000898d

/*
 *  SCIF,SCI,TMU�̐ݒ�l
 *
 */

/*
 * �J�[�l���ł�CPG�̐ݒ�͍s��Ȃ�
 * GDB_STUB��������ICE�ɂ��
 * �N���b�N���[�h0 
 * OSC1 33MHz : I:B:P = 4:1:1
 * �ݒ肷�邱��
 * 
 */

/*
 *  �^�C�}�l�̓����\���� msec �P�ʂƂ̕ϊ�
 *  P�N���b�N�� 33.2MHz
 *  ������ /4,/16,/64/256 �̂����ꂩ��I��
 *  /4:  8.3Mhz   tick 8300   0.12 ��sec
 *  /16: 2.075Mhz tick 2075   0.48 ��sec 
 *  /64: 0.518Mhz tick 518    1.93 ��sec
 *  /256:0.129Mhz tick 129    7.73 ��sec
 *
 */
#define TCR0_TPSC  0x0001


/*
 *  �^�C�}�l�̓����\���ƃ~���b�P�ʂƂ̕ϊ�
 */
#define TIMER_CLOCK		2075

/*
 *  �X�[�p�[I/O(FDC37C935A)�̃x�[�X�A�h���X
 */
#define SMSC_BASE_ADDR 0xB0400000

/*
 *  �X�[�p�[I/O(FDC37C935A)���SCI0�̃{�[���[�g�̐ݒ�l
 *  19200bps
 */
#define SMSC_SCI0_BPS 0x0006

/*
 *  �������ԑ҂��̂��߂̒�`
 */
#define	SIL_DLY_TIM1	 90
#define	SIL_DLY_TIM2	 50

#endif  /* _MS7729RSE01_H_ */

