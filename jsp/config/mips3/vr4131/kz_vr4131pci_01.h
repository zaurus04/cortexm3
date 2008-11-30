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

#ifndef _KZ_VR4131PCI_01_
#define _KZ_VR4131PCI_01_

#define KZ_VR4131PCI_01

/*
 *  �f�o�C�X�̊��蓖�ăx�[�X�A�h���X
 */

#define VR4131_BASE_ADDR	0xa0000000

/*
 *  �f�o�C�X�ɋ��������N���b�N
 */
/*
 *  VR4131 �͋N������ CLKSEL(2:0) �[�q�����āA�p�C�v���C���N���b�NPClock��
 *  ���肷��B����̃^�[�Q�b�g�{�[�h�̃f�t�H���g�́A
 *        CLKSEL(2:0) = 110
 *  �p���[�}�l�W�����g���j�b�g�́APMUTCLKDIVREG�ɕύX�͉����Ȃ����߉��L�ƂȂ�B
 *        PClock 199.1[MHz], VTClock 33.2[MHz], TClock 16.6[MHz]
 */
/* �V���A���ɋ��������N���b�N���g�� [Hz]�i�{�[���[�g�ݒ�Ŏg�p�j
 * �i18.432MHz = 18432000 Hz ; �n�[�h�E�F�A��p193�Q�Ɓj */
#define XIN_CLOCK	18432000u	/* [Hz] */

/* �^�C�}�ɋ��������N���b�N���g�� [kHz]�iTO_CLOCK�Ŏg�p�j
 * �iTO_CLOCK ��1�~���b����(1kHz)�𔭐������邽�߂Ɏg�p�j
 * �iVTClock=33.2MHz = 33200kHz ; �n�[�h�E�F�A��p22�Q�Ɓj */
#define TIMER_CLOCK	33200u	/* [kHz] */

/*
 *  �f�o�C�X�̊����݃}�X�N�̒�`
 *
 *  �D��x : (��) DSIU -> TClock�J�E���^ -> �o�b�e���c�ʕs�����m (��)
 */
/* MSYSINT1 �� BATINTR �̐ݒ�ɂ��ẮA�n�[�h�E�F�A��p224�Q��  */

/*
 *  DSIU �����݂̊����݃}�X�N�i����M���p�j
 *  �E�����݃��x���͑��M����M���������x���ɐݒ肵�Ă���
 */
#define CORE_IPM_DSIU		INIT_CORE_IPM	/* MIPS3�R�A(SR)�p�f�[�^ */

/* BATINTR�ATCLKINTR �����݂݂̂�������B */
#define ICU_IPM_SYSINT1_DSIU	BATINTR		/* �����݃R���g���[���p�f�[�^ */
#define ICU_IPM_SYSINT2_DSIU	TCLKINTR

/*  �ݒ肷�銄���݃}�X�N�iIPM�^�ŋL�q����j */
#define IPM_DSIU	{ CORE_IPM_DSIU, {ICU_IPM_SYSINT1_DSIU, ICU_IPM_SYSINT2_DSIU} }

/*
 *  RTC �֘A�̊����݃}�X�N
 */
#define CORE_IPM_TIMER		INIT_CORE_IPM	/* MIPS3�R�A(SR)�p�f�[�^ */

/* BATINTR �����݂݂̂�������B */
#define ICU_IPM_SYSINT1_TCLK	BATINTR		/* �����݃R���g���[���p�f�[�^ */
#define ICU_IPM_SYSINT2_TCLK	0u

/*  �ݒ肷�銄���݃}�X�N�iIPM�^�ŋL�q����j */
#define IPM_TIMER	{ CORE_IPM_TIMER, {ICU_IPM_SYSINT1_TCLK, ICU_IPM_SYSINT2_TCLK} }

#endif /* _KZ_VR4131PCI_01_ */
