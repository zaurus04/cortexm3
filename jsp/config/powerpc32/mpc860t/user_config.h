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
 *  @(#) $Id: user_config.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	���[�U�[��`�̐ݒ蕔
 */

#ifndef _USER_CONFIG_H_
#define _USER_CONFIG_H_

/********************************************************************
 *�@PowerPC�t�@�~�����ʂ̐ݒ�
 *�@�@(1) �����R���p�C���p�̃t���O�Ƃ��ėp����}�N��
 ********************************************************************/

/*
 *  chg_ipm/get_ipm ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_CHG_IPM

/*
 *  vxget_tim ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_VXGET_TIM

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define	SIL_ENDIAN	SIL_ENDIAN_BIG	/* �r�b�O�G���f�B�A�� */

/*
 *  ���s���ׂ��^�X�N���Ȃ��ꍇ�̊����ݑ҂��ŏȓd�̓��[�h�Ɉڍs���邩
 *�@�ǂ����̒�`�i�t��ICE�����j
 */
#define	SUPPORT_POWER_MANAGEMENT

/*
 *  ���W�X�^�̑Ҕ��^�����ɐ������[�h�^�X�g�A�E�}���`�v�����߂�
 *�@�g�p����ǂ����̒�`
 */
//#define	USE_MULTIPLE_WORD_LOAD_STORE

/*
 *  ��O�x�N�^�̔z�u�ɂ���ẮA��O�x�N�^����text�Z�N�V�����ɂ��鑱��
 *  �̏����ɕ��򂷂�ہAb���߂ɂ��PC���Ε���i�O��0x07ff,ffff�j�ł͓�
 *  ���Ȃ��ꍇ������BABSOLUTE_JUMP_EXC_ENTRY�}�N�����`����Ɛ�Δ�
 *  �n���w�肵�ĕ��򂷂�����ɐ؂�ւ��A���̖�������ł���B
 */
#define ABSOLUTE_JUMP_EXC_ENTRY


/********************************************************************
 *�@PowerPC�t�@�~�����ʂ̐ݒ�
 *�@�@(2) �l��ݒ肷��}�N��
 ********************************************************************/

/*
 *  JSP�J�[�l�����쎞�̃������}�b�v
 *      0x0000,0000 -              �f�[�^�̈�(16MB)
 *                  - 0x0100,0000  �^�X�N�Ɨ����p�X�^�b�N
 *      0x1000,0000 - 0x1040,0000  �R�[�h�̈�(4MB)  �������I��
 */

/*
 *�@��^�X�N�R���e�L�X�g�p�X�^�b�N�̏����l
 */
#define STACKTOP    	0x01000000

/*  �V�X�e���N���b�N [MHz] */
#define SYSTEM_CLOCK	50


/*
 *  �^�C�}�֘A�̐ݒ�
 *
 */

/* �^�C�}�̊��荞�݃��x�� */
/*  MPC860T�̏ꍇ��SIU�̓������x����\���B  */
#define INTLVL_TIMER	3

/*
 *  �^�C�}�֘A�̐ݒ�
 */

/*
 *  �^�C���e�B�b�N�̒�`
 */
#define	TIC_NUME	1u	/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1u	/* �^�C���e�B�b�N�̎����̕��� */


/*
 *  �V���A���֘A�̐ݒ�
 */

/* �V���A���̊��荞�݃��x�� */
/*  MPC860T�̏ꍇ��CPM����SIU�ւ̊����݃��x���ɂ���Č��肷��B  */
//#define INTLVL_SERIAL

/*  �{�[���[�g�@[bps]  */
#define BAUD_RATE	9600

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
#define TNUM_PORT 1	/* GDIC���x���ŃT�|�[�g����V���A���|�[�g�̐� */
			/*  ����ł�SMC1�̂݃T�|�[�g  */

#define	TNUM_SIOP 1	/* PDIC���x���ŃT�|�[�g����V���A���|�[�g�̐� */
			/*  ����ł�SMC1�̂݃T�|�[�g  */

#define	LOGTASK_PORTID	1  /* �V�X�e�����O�ɗp����V���A���|�[�g�ԍ� */
			/*  ����ł�SMC1�̂݃T�|�[�g  */


/********************************************************************
 *  �I���W�i����PowerPC�A�[�L�e�N�`���ŗL�̐ݒ荀��
 *�@�@(1) �����R���p�C���p�̃t���O�Ƃ��ėp����}�N��
 ********************************************************************/

/*
 *  �f�B�X�p�b�`���ŕ��������_���W�X�^�̑Ҕ��^�������s����
 *�@�ǂ����̒�`
 *�@�iMPC860T�͕��������_���W�X�^����������Ă��Ȃ��B�j
 */
//#define	SUPPORT_FLOATING_POINT_REG

/*
 *  �C���v�������e�[�V�����ŗL�̗�O0x00a00���g�p����
 *�@�ǂ����̒�`
 */
//#define	IMPLEMENT_EXCEPTION_00A00


/********************************************************************
 *  MPC860T�ŗL�̐ݒ荀��
 *�@�@(1) �����R���p�C���p�̃t���O�Ƃ��ėp����}�N��
 ********************************************************************/

/*
 *  SIL���g�p�����Ƃ��̃��O�@�\��L���ɂ��邩�ǂ����̒�`
 */
//#define	SIL_DEBUG


/********************************************************************
 *  MPC860T�ŗL�̐ݒ荀��
 *�@�@(2) �l��ݒ肷��}�N��
 ********************************************************************/

/*
 *  CPM����SIU�ւ̊����ݗv�����x��
 *  �@�V���A�������݂̃��x����`�����˂Ă���B
 */
#define CPM_INT_LEVEL	4



#endif /* _USER_CONFIG_H_ */