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

#ifndef _RTE_VR5500_CB_
#define _RTE_VR5500_CB_

#define RTE_VR5500_CB

/*
 *  �f�o�C�X�̊��蓖�ăx�[�X�A�h���X
 */

/* �V���A���R���g���[�� (TL16PIR552) */
#define UART_CH01	0xb9001000
#define UART_CH02	0xb9002000
#define PRINTER_PPCS	0xb9003000
#define PRINTER_ECPCS	0xb9004000

/* �^�C�} (uPD71054) */
#define TIMER_BASE_ADDR	0xb9005000

/* �����݃R���g���[��(PIC) */
#define ICU_BASE_ADDR	0xb9000000

/*
 *  �f�o�C�X�ɋ��������N���b�N
 */
/* �V���A���ɋ��������N���b�N���g�� [Hz]�i�{�[���[�g�ݒ�Ŏg�p�j
 * �i16MHz = 16000000 Hz ; �{�[�h�̃}�j���A��p21�Q�Ɓj */
#define XIN_CLOCK	16000000u

/* �^�C�}�ɋ��������N���b�N���g�� [kHz]
 *�iTO_CLOCK ��1�~���b����(1kHz)�𔭐������邽�߂Ɏg�p�j
 * (2MHz = 2000kHz ; �{�[�h�̃}�j���A��p22�Q��) */
#define TIMER_CLOCK	2000u

/*
 *  �f�o�C�X�̊����݃}�X�N�̒�`
 *
 *  �D��x : (��) �V���A���P -> �V���A���O -> �^�C�}�O (��)
 */

/*
 *  �V���A���O�����݂̊����݃}�X�N�i����M���p�j
 *  �E�����݃��x���͑��M����M���������x���ɐݒ肵�Ă���
 */
#define CORE_IPM_SCC		INIT_CORE_IPM	/* MIPS3�R�A(SR)�p�f�[�^ */

#define ICU_IPM_INT0_SCC0	TIMER0		/* �����݃R���g���[���p�f�[�^ */
#define ICU_IPM_INT1_SCC0	0u

/*  �ݒ肷�銄���݃}�X�N�iIPM�^�ŋL�q����j */
#define IPM_SCC0	{ CORE_IPM_SCC, {ICU_IPM_INT0_SCC0, ICU_IPM_INT1_SCC0} }

/*
 *  �V���A���P�����݂̊����݃}�X�N�i����M���p�j
 *  �E�����݃��x���͑��M����M���������x���ɐݒ肵�Ă���
 *  �EMIPS3�R�A�p�̃f�[�^�́ASCC0�Ƌ���
 */
#define ICU_IPM_INT0_SCC1	(TIMER0 | SERIAL0) /* �����݃R���g���[���p�f�[�^ */
#define ICU_IPM_INT1_SCC1	0u

/*  �ݒ肷�銄���݃}�X�N�iIPM�^�ŋL�q����j */
#define IPM_SCC1	{ CORE_IPM_SCC, {ICU_IPM_INT0_SCC1, ICU_IPM_INT1_SCC1} }

/*
 *  �^�C�}�O�����݂̊����݃}�X�N
 *  �{�����ł́A�^�C�}�����݂��������Ƃ��́A�S�Ă̊O�������݂��֎~���Ă���B
 */
#define CORE_IPM_TIMER		INIT_CORE_IPM	/* MIPS3�R�A(SR)�p�f�[�^ */

#define ICU_IPM_INT0_TIMER0	0u		/* �����݃R���g���[���p�f�[�^ */
#define ICU_IPM_INT1_TIMER0	0u

/*  �ݒ肷�銄���݃}�X�N�iIPM�^�ŋL�q����j */
#define IPM_TIMER0	{ CORE_IPM_TIMER, {ICU_IPM_INT0_TIMER0, ICU_IPM_INT1_TIMER0} }

#endif /* _PIC_ICU_H_ */
