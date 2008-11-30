/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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
 * 
 *  @(#) $Id: user_config.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
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
#if 0
#define	SUPPORT_CPU_EXC_ENTRY_CHECK
#endif

/*
 *  ���s���ׂ��^�X�N���Ȃ��ꍇ�̊����ݑ҂��ŏȓd�̓��[�h�Ɉڍs���Ȃ���
 *�@�ǂ����̒�`�i�t��ICE�����j
 */
#if 0
#define	OMIT_POWER_CONTROL
#endif

/*
 *  �X�^�[�g�A�b�v���[�`���Ŕ�^�X�N�R���e�L�X�g�̃X�^�b�N�̈��0��
 *�@����������ǂ����̒�`
 */
#if 0
#define	FILL_STACK_WITH_0
#endif

/*
 *  �X�^�[�g�A�b�v���[�`����data�Z�N�V�����̃R�s�[���ȗ����邩
 *�@�ǂ����̒�`
 */
#if 0
#define	OMIT_DATA_SECTION_COPY
#endif

/*
 *  SRAM�����������^�C�v�����[�W�^�C�v�Ƃ��邩�ǂ����̒�`
 *�@�i�������쏊�� SH1CPU�{�[�h�ŗL�Ȃ̂ŁA�{�@��ł͖��g�p�j
 */
#if 0
#define	LARGE_TYPE
#endif


/*
 *  �l�����}�N���̒�`
 */


/*
 *  JSP�J�[�l�����쎞�̃������}�b�v
 *      0x0000,0000 - 0x0004,0000  �R�[�h�̈�(256KB)
 *      0x0a00,0000 -              �f�[�^�̈�(256KB)
 *                  - 0x0a03,ffff  �^�X�N�Ɨ����p�X�^�b�N �������I��
 */

/*
 *�@��^�X�N�R���e�L�X�g�p�X�^�b�N�̏����l
 */
#define STACKTOP    	0x0a03fffc

/*
 *  �N���b�N���g��
 *�@�@�����ꂩ�P��I������B
 *�@�@�@�E���s�}�C�N���R���s���[�^(��) KZ-SH1-01�@20MHz
 *�@�@�@�ECQ�o�� RISC�]���L�b�g SH-1�@            19.6608MHz
 *�@�@�@�E�\�t�B�A�V�X�e���Y��MultiSTAC-SH1       20MHz
 */
#define	CONFIG_20MHZ
#if 0
#define	CONFIG_19MHZ	/*  19.6608MHz  */
#define	CONFIG_16MHZ
#endif

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
#define TNUM_PORT 1	/*  �{�@��ł͂P�ɌŒ�  */

/*
 *  PDIC���x���ŃT�|�[�g����V���A���|�[�g�̐�
 *�@�i�f�o�C�X�h���C�o�E���x���̃|�[�g���j
 */
#define	TNUM_SIOP 1	/*  �{�@��ł͂P�ɌŒ�  */

/*
 *  �V�X�e�����O�ɗp����V���A���|�[�g�ԍ�
 */
#define	LOGTASK_PORTID	1  /*  �{�@��ł͂P�ɌŒ�  */

/*
 *  �V���A���ʐM�̃{�[���[�g
 *�@�@9600, 19200, 38400[bps]�̂����ꂩ�𐔒l�Œ�`����B
 */
#if 0
#define	CONFIG_BAUD	9600
#define	CONFIG_BAUD	19200
#endif

#define	CONFIG_BAUD	38400

/*
 * SCI�̊����݃��x��
 * �@�����݃n���h���͑���M�ʁX�ɓo�^�ł��邪�A�����݃��x����
 * �@���M����M���������x���ɂ����ݒ�ł��Ȃ��B
 */
#define SCI_INTLVL	6	/*  ����M���p  */

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
#if 0
#define	NUM_EXC
#endif

/*
 *  ����RAM�̍ŏI�A�h���X
 *�@�@hardware_init_hook��C����̊֐��ŋL�q���邽��
 *  �@�X�^�b�N�|�C���^�̏����l�Ƃ��Ďg�p�����B
 */
#if 0	/*  �{�@��͓���RAM�������Ȃ�  */
#define	INNER_RAM_ADDRESS
#endif


/*
 *  �ȉ��̃}�N���͂��ׂďȗ��\�ł���B
 *  �ȗ������ꍇ�̓f�t�H���g�̒l�Ƃ��āA�X�^�[�g�A�b�v���[�`����
 *�@�擪�A�h���X���ݒ肳���B
 */

/*  ��ʕs������  */
#if 0
#define GII_VECTOR
#endif

/*  �X���b�g�s������  */
#if 0
#define SII_VECTOR
#endif

/*  CPU�A�h���X�G���[  */
#if 0
#define CAE_VECTOR
#endif

/*  DMA�A�h���X�G���[  */
#if 0
#define DAE_VECTOR
#endif

/*  NMI  */
#if 0
#define NMI_VECTOR
#endif


#endif /* _USER_CONFIG_H_ */
