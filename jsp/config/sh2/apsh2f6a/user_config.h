/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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
 *  @(#) $Id: user_config.h,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *	���[�U�[��`�̐ݒ蕔
 */

#ifndef _USER_CONFIG_H_
#define _USER_CONFIG_H_

/*
 *  �����R���p�C���p�̃t���O�Ƃ��ėp����}�N����`
 */

/*
 *  chg_ipm/get_ipm ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_CHG_IPM

/*
 *  vxget_tim ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_VXGET_TIM

/*
 *  �����݂̏o�������Ŗ߂�悪CPU��O�̓��������ł��邩��
 *�@�`�F�b�N���s���ǂ����̒�`
 */
//#define	SUPPORT_CPU_EXC_ENTRY_CHECK

/*
 *  ���s���ׂ��^�X�N���Ȃ��ꍇ�̊����ݑ҂��ŏȓd�̓��[�h�Ɉڍs���Ȃ���
 *�@�ǂ����̒�`�i�t��ICE�����j
 */
//#define	OMIT_POWER_CONTROL

/*
 *  �X�^�[�g�A�b�v���[�`���Ŕ�^�X�N�R���e�L�X�g�̃X�^�b�N�̈��0��
 *�@����������ǂ����̒�`
 */
//#define	FILL_STACK_WITH_0

/*
 *  �X�^�[�g�A�b�v���[�`����data�Z�N�V�����̃R�s�[���ȗ����邩
 *�@�ǂ����̒�`
 */
//#define	OMIT_DATA_SECTION_COPY

/*
 *  SRAM�����������^�C�v�����[�W�^�C�v�Ƃ��邩�ǂ����̒�`
 *�@�i�������쏊�� SH1CPU�{�[�h�ŗL�Ȃ̂ŁA�{�@��ł͖��g�p�j
 */
//#define	LARGE_TYPE


/*
 *  �l�����}�N���̒�`
 */


/*
 *  JSP�J�[�l�����쎞�̃������}�b�v
 *      0x0000,0000 - 0x0003,ffff  �R�[�h�̈�(256KB)
 *      0x0040,0000 -              �f�[�^�̈�(2MB)
 *                  - 0x005f,ffff  �O�t���������I��
 *      0xffff,e000 -              �f�[�^�̈�(8KB)
 *                  - 0xffff,ffff  �����������I��
 */

/*
 *�@��^�X�N�R���e�L�X�g�p�X�^�b�N�̏����l
 */
#define STACKTOP    	 0x00600000


/*
 *  �V���A���|�[�g���̒�`
 *
 *  TNUM_PORT�̓V���A���h���C�o�iserial.c�j�A�܂� GDIC���x���ŃT�|�[
 *  �g���Ă���V���A���|�[�g�̐��ł���A�@��ˑ����Œ�`����悤���ʕ�
 *  �Ƃ̃C���^�[�t�F�[�X�ŋK�肳��Ă���B
 *  ����ATNUM_SIOP��PDIC���x���ŃT�|�[�g���Ă���V���A���|�[�g�̐���
 *  ����A�@��ˑ����̒��ł̂ݗp���Ă���B
 *�@
 */

/*
 *  GDIC���x���ŃT�|�[�g����V���A���|�[�g�̐�
 *�@�i�J�[�l���̊Ǘ����ɂ���|�[�g���j
 */
#define TNUM_PORT 1

/*
 *  PDIC���x���ŃT�|�[�g����V���A���|�[�g�̐�
 *�@�i�f�o�C�X�h���C�o�E���x���̃|�[�g���j
 */

/*
 *  �V�X�e�����O�ɗp����V���A���|�[�g�ԍ�
 */
#define	LOGTASK_PORTID	1

/*
 *  �V���A���ʐM�̃{�[���[�g
 *�@�@9600, 19200, 38400[bps]�̂����ꂩ�𐔒l�Œ�`����B
 */
/* shxxxxsci.c�Őݒ� */

/*
 * SCI�̊����݃��x��
 * �@�����݃n���h���͑���M�ʁX�ɓo�^�ł��邪�A�����݃��x����
 * �@���M����M���������x���ɂ����ݒ�ł��Ȃ��B
 */
/* shxxxxsci.c�Őݒ� */

/*
 *  �^�C�}�����݂̃��x��
 */
#define TIMER_INTLVL	4

/*
 *  �^�C���e�B�b�N�̒�`
 *  �@�i�^�C�}�����݂̎����F[msec]�P�ʁj
 */
#define	TIC_NUME	1u	/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1u	/* �^�C���e�B�b�N�̎����̕��� */


/*
 *  ��L�̃`�F�b�N�ΏۂƂȂ�CPU��O�̐�
 */
//#define	NUM_EXC

/*
 *  ����RAM�̍ŏI�A�h���X
 *�@�@hardware_init_hook��C����̊֐��ŋL�q���邽��
 *  �@�X�^�b�N�|�C���^�̏����l�Ƃ��Ďg�p�����B
 */
//#define	INNER_RAM_ADDRESS


/*
 *  �ȉ��̃}�N���͂��ׂďȗ��\�ł���B
 *  �ȗ������ꍇ�̓f�t�H���g�̒l�Ƃ��āA�X�^�[�g�A�b�v���[�`����
 *�@�擪�A�h���X���ݒ肳���B
 */

/*  ��ʕs������  */
//#define GII_VECTOR

/*  �X���b�g�s������  */
//#define SII_VECTOR

/*  CPU�A�h���X�G���[  */
//#define CAE_VECTOR

/*  DMA�A�h���X�G���[  */
//#define DAE_VECTOR

/*  NMI  */
//#define NMI_VECTOR


#endif /* _USER_CONFIG_H_ */
