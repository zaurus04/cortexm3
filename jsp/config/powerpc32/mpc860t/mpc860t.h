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
 *  @(#) $Id: mpc860t.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *  MPC860�̃n�[�h�E�F�A�����̒�`
 */

#ifndef _MPC860_H_
#define _MPC860_H_

/*
 *  �����݂̖{��
 */
#define TMAX_SIU_INTNO      16  /*  �V�X�e���C���^�[�t�F�[�X���j�b�gSIU  */
#define TMAX_CPM_INTNO      32  /*  �ʐM�v���Z�b�T���W���[��CPM  */
                                /*  MPC860�S��  */
#define TMAX_INTNO          (TMAX_SIU_INTNO+TMAX_CPM_INTNO)

/*
 *  �����݊֘A�̒�`
 *  �@�����ݗv������3��ނ̒l���Ǘ����Ă���
 *  �@�P�D�����ݔԍ�
 *  �@�Q�DSIU�ւ̊����ݗv�����x��
 *  �@�@�@�������x���̐ݒ�
 *  �@�@�@CPM�����݂͑S�̂łЂƂ܂Ƃ߂̈���
 *  �@�@�@�@(1) No.�F0�`7�̐��l
 *  �@�@�@�@�@�@�@�l�Ԃɂ͕�����₷�����A�v���O�������ł�
 *  �@�@�@�@�@�@�@���ځA�g�p����Ȃ�
 *  �@�@�@�@(1-2) �����ݗv���̎���
 *  �@�@�@�@�@�@�@�[���x�N�^�e�[�u���̃C���f�b�N�X�Ƃ��ēǂݏo��
 *  �@�@�@�@�@�@�@�����Ȃ̂ŁA���l�Ƃ��ă}�N����`���Ă����K�v�͂Ȃ�
 *  �@�@�@�@�@�@�@�\��2�r�b�g�V�t�g����Ă���
 *  �@�@�@�@(2) 1�o�C�g�̃r�b�g�p�^�[�� 
 *  �@�@�@�@�@�@�@�����ݗv�����x����ݒ肷��ۂɃ��W�X�^�ɃZ�b�g����l
 *  �@�@�@�@�@�@�@�Y������1�r�b�g�������Z�b�g����
 *  �@�R�DSIU��IPM
 *  �@�@�@2�o�C�g�̃r�b�g�p�^�[��
 *  �@�@�@CPM�����݂͑S�̂łЂƂ܂Ƃ߂̈���
 *  �@�@�@�@(1) �����݃}�X�N
 *  �@�@�@�@�@�@�@SIU�����݃��W�X�^SIMASK�ɐݒ肷��l
 *  �@�@�@�@�@�@�@������背�x���̒Ⴂ�����ݗv�������ׂă}�X�N����
 *  �@�@�@�@(2) �ۗ����̊����ݗv��
 *  �@�@�@�@�@�@�@�Y������r�b�g�������Z�b�g����Ă���
 *  
 *  �@�������x��2-(1)���犄���ݔԍ��A�����݃��x���ݒ�p�r�b�g�p�^�[���A
 *  �@IPM�𐶐�������j�Ŏ���
 *  
 */

/*
 *  �����ݔԍ��̒�`
 *      �n�[�h�E�F�A�}�j���A���ɂ�SIU�����݃\�[�X��16�`31�Ԃ͗\���
 *      �݂Ƃ��邪�A�[���x�N�^�e�[�u�������ʂɑ傫���Ȃ邾���Ȃ̂ŁA
 *      CPM�����݃\�[�X�����蓖�ĂĂ���
 *      
 *      �����ݔԍ��ƗD��x�̊֌W��SIU�����݂�CPM�����݁i�f�t�H���g�j
 *      �ŋt�Ȃ̂Œ���
 *      �@SIU������
 *      �@�@�����ݔԍ��@�@0�F�ŏ��
 *      �@�@�����ݔԍ��@ 15�F�ŉ���
 *      �@CPM�����݁i�f�t�H���g�j
 *      �@�@�����ݔԍ��@ 0x0�F�ŉ���
 *      �@�@�����ݔԍ��@0x1f�F�ŏ��
 */

    /*  SIU�����݃\�[�X  */
#define INTNO_IRQ0      0x0     /*  IRQ0  */
#define INTNO_LVL0      0x1     /*  �������x��0  */
#define INTNO_IRQ1      0x2     /*  IRQ1  */
#define INTNO_LVL1      0x3     /*  �������x��1  */
#define INTNO_IRQ2      0x4     /*  IRQ2  */
#define INTNO_LVL2      0x5     /*  �������x��2  */
#define INTNO_IRQ3      0x6     /*  IRQ3  */
#define INTNO_LVL3      0x7     /*  �������x��3  */
#define INTNO_IRQ4      0x8     /*  IRQ4  */
#define INTNO_LVL4      0x9     /*  �������x��4  */
#define INTNO_IRQ5      0xa     /*  IRQ5  */
#define INTNO_LVL5      0xb     /*  �������x��5  */
#define INTNO_IRQ6      0xc     /*  IRQ6 */
#define INTNO_LVL6      0xd     /*  �������x��6  */
#define INTNO_IRQ7      0xe     /*  IRQ7  */
#define INTNO_LVL7      0xf     /*  �������x��7  */

    /*  CPM�����݃\�[�X  */
#define INTNO_ERR       0x10    /*  �G���[�F0x0  */
#define INTNO_PC4       0x11    /*  �p������I/O PC4�F0x1  */
#define INTNO_PC5       0x12    /*  �p������I/O PC5�F0x2  */
#define INTNO_SMC2      0x13    /*  SMC2/PIP�F0x3  */
#define INTNO_SMC1      0x14    /*  SMC1�F0x4  */
#define INTNO_SPI       0x15    /*  SPI�F0x5  */
#define INTNO_PC6       0x16    /*  �p������I/O PC6�F0x6  */
#define INTNO_TIMER4    0x17    /*  �^�C�}4�F0x7  */
/*  CPM�����ݔԍ�8�͗\��ς�  */
#define INTNO_PC7       0x19    /*  �p������I/O PC7�F0x9  */
#define INTNO_PC8       0x1a    /*  �p������I/O PC8�F0xa  */
#define INTNO_PC9       0x1b    /*  �p������I/O PC9�F0xb  */
#define INTNO_TIMER3    0x1c    /*  �^�C�}3�F0xc  */
/*  CPM�����ݔԍ�0xd�͗\��ς�  */
#define INTNO_PC10      0x1e    /*  �p������I/O PC10�F0xe  */
#define INTNO_PC11      0x1f    /*  �p������I/O PC11�F0xf  */
#define INTNO_I2C       0x20    /*  I2C�F0x10  */
#define INTNO_RISC      0x21    /*  RISC�^�C�}�e�[�u���F0x11  */
#define INTNO_TIMER2    0x22    /*  �^�C�}2�F0x12  */
/*  CPM�����ݔԍ�0x13�͗\��ς�  */
#define INTNO_IDMA2     0x24    /*  IDMA2�F0x14  */
#define INTNO_IDMA1     0x25    /*  IDMA1�F0x15  */
#define INTNO_SDMA      0x26    /*  SDMA�`���l���o�X�G���[�F0x16  */
#define INTNO_PC12      0x27    /*  �p������I/O PC12�F0x17  */
#define INTNO_PC13      0x28    /*  �p������I/O PC13�F0x18  */
#define INTNO_TIMER1    0x29    /*  �^�C�}1�F0x19  */
#define INTNO_PC14      0x2a    /*  �p������I/O PC14�F  */
#define INTNO_SCC4      0x2b    /*  SCC4�F0x1a  */
#define INTNO_SCC3      0x2c    /*  SCC3�F0x1c  */
#define INTNO_SCC2      0x2d    /*  SCC2�F0x1d  */
#define INTNO_SCC1      0x2e    /*  SCC1�F0x1e  */
#define INTNO_PC15      0x2f    /*  �p������I/O PC15�F0x1f  */

/*
 *  SIU��IPM�̒�`
 *    2�o�C�g�̃r�b�g�p�^�[��
 *    �n�[�h�E�F�A�̃f�t�H���g�̗D��x�ɍ��킹�Ă���
 */
#define IPM_IRQ0	0x00u			/*  IRQ0  */
#define IPM_LVL0	BIT0_16			/*  �������x��0  */
#define IPM_IRQ1	(IPM_LVL0 | BIT1_16)	/*  IRQ1  */
#define IPM_LVL1	(IPM_IRQ1 | BIT2_16)	/*  �������x��1  */
#define IPM_IRQ2	(IPM_LVL1 | BIT3_16)	/*  IRQ2  */
#define IPM_LVL2	(IPM_IRQ2 | BIT4_16)	/*  �������x��2  */
#define IPM_IRQ3	(IPM_LVL2 | BIT5_16)	/*  IRQ3  */
#define IPM_LVL3	(IPM_IRQ3 | BIT6_16)	/*  �������x��3  */
#define IPM_IRQ4	(IPM_LVL3 | BIT7_16)	/*  IRQ4  */
#define IPM_LVL4	(IPM_IRQ4 | BIT8_16)	/*  �������x��4  */
#define IPM_IRQ5	(IPM_LVL4 | BIT9_16)	/*  IRQ5  */
#define IPM_LVL5	(IPM_IRQ5 | BIT10_16)	/*  �������x��5  */
#define IPM_IRQ6	(IPM_LVL5 | BIT11_16)	/*  IRQ6  */
#define IPM_LVL6	(IPM_IRQ6 | BIT12_16)	/*  �������x��6  */
#define IPM_IRQ7	(IPM_LVL6 | BIT13_16)	/*  IRQ7  */
#define IPM_LVL7	(IPM_IRQ7 | BIT14_16)	/*  �������x��7  */


/*  �����݃��x�����犄���ݔԍ��ւ̕ϊ�  */
#define _LEVEL_TO_INHNO(level)      INTNO_LVL##level
#define  LEVEL_TO_INHNO(level)      _LEVEL_TO_INHNO(level)

/*  �����݃��x������o�^�p�r�b�g�p�^�[���ւ̕ϊ�  */
#define _LEVEL_TO_BIT_PATTERN(level)      (0x1<<(7-(level)))
#define  LEVEL_TO_BIT_PATTERN(level)      _LEVEL_TO_BIT_PATTERN(level)

/*  �����݃��x������IPM�ւ̕ϊ�  */
#define _LEVEL_TO_IPM(level)      IPM_LVL##level
#define  LEVEL_TO_IPM(level)      _LEVEL_TO_IPM(level)

/*  �����݃��x�����犄���݋��r�b�g�ւ̕ϊ�  */
#define _LEVEL_TO_ENABLE_BIT(level)  SIMASK_LVM##level
#define  LEVEL_TO_ENABLE_BIT(level)  _LEVEL_TO_ENABLE_BIT(level)


/*
 *  CPU�̓������W�X�^
 */

/*
 *   8. ���߃L���b�V���E�f�[�^�L���b�V���֘A�̒�`
 */

/*  ���䃌�W�X�^ */

/*  ���߃L���b�V���֘A */
#define IC_CST	560	/*  ���䂨��уX�e�[�^�X�E���W�X�^ */
#define IC_ADR	561	/*  �A�h���X�E���W�X�^  */
#define IC_DAT	562	/*  �f�[�^�E�|�[�g�E���W�X�^  */

/*  �f�[�^�E�L���b�V���֘A */
#define DC_CST	568	/*  ���䂨��уX�e�[�^�X�E���W�X�^ */
#define DC_ADR	569	/*  �A�h���X�E���W�X�^  */
#define DC_DAT	570	/*  �f�[�^�E�|�[�g�E���W�X�^  */

/*
 *   9. �������Ǘ����j�b�gMMU�֘A�̒�`
 */
/*  ���䃌�W�X�^  */
#define MI_CTR	784	/*  IMMU ���䃌�W�X�^  */
#define MD_CTR	792	/*  DMMU ���䃌�W�X�^  */

/*  TLB�\�[�X�E���W�X�^  */
#define MI_EPN	787	/*  IMMU �����y�[�W�ԍ����W�X�^  */
#define MD_EPN	795	/*  DMMU �����y�[�W�ԍ����W�X�^  */
#define MI_TWC	789	/*  IMMU �e�[�u���E�H�[�N���䃌�W�X�^  */
#define MD_TWC	797	/*  DMMU �e�[�u���E�H�[�N���䃌�W�X�^  */
#define MI_RPN	790	/*  IMMU ���i�����j�y�[�W�ԍ��|�[�g  */
#define MD_RPN	798	/*  DMMU ���i�����j�y�[�W�ԍ��|�[�g  */

/*  �e�[�u���E�H�[�N�E�x�[�X�E���W�X�^  */
#define M_TWD	796	/*  MMU �e�[�u���E�H�[�N�E�x�[�X�E���W�X�^  */

/*  �ی샌�W�X�^  */
#define M_CASID	793	/*  MMU �J�����g�E�A�h���X���ID ���W�X�^  */
#define MI_AP	786	/*  IMMU �A�N�Z�X�ی샌�W�X�^  */
#define MD_AP	794	/*  DMMU �A�N�Z�X�ی샌�W�X�^  */

/*  �X�N���b�`�E���W�X�^  */
#define M_TB	799	/*  MMU �e�[�u���E�H�[�N�E�X�y�V�����E���W�X�^  */

/*  �f�o�b�O�E���W�X�^  */
#define MI_CAM	816	/*  IMMU CAM �G���g���E���[�h�E���W�X�^  */
#define MI_RAM0	817	/*  IMMU RAM �G���g���E���[�h�E���W�X�^ 0  */
#define MI_RAM1	818	/*  IMMU RAM �G���g���E���[�h�E���W�X�^ 1  */
#define MD_CAM	824	/*  DMMU CAM �G���g���E���[�h�E���W�X�^  */
#define MD_RAM0	825	/*  DMMU RAM �G���g���E���[�h�E���W�X�^ 0  */
#define MD_RAM1	826	/*  DMMU RAM �G���g���E���[�h�E���W�X�^ 1  */

/*
 *  11. �V�X�e���C���^�[�t�F�[�X���j�b�gSIU�֘A�̒�`
 */


/*
 *  �����������}�b�v���W�X�^
 *  �@�@�������W�X�^�Q�̐擪�A�h���X
 *  �@�@
 *  �@�@�@���Z�b�g�����0x0000,0000�Ԓn���w���Ă��邪SDRAM��
 *  �@�@�@�Ԃ���̂ŁA�ʂ̃A�h���X�ɕς���K�v������
 */
#define IMMR        638                 /*  ���W�X�^�ԍ�  */
#define IMMR_UPPER_2BYTE  0xff00              /*  ���16�r�b�g  */
#define IMMR_BASE   (IMMR_UPPER_2BYTE << 16)  /*  �x�[�X�A�h���X  */  

#define TADR_SIU_SIUMCR  0x0    /* SIU���W���[���R���t�B�M�����[�V���� */
                                /*                     ���W�X�^SIUMCR  */

/*
 *  11.5 SIU�����݃R���g���[���֘A�̒�`
 */
#define TADR_SIU_SIPEND 0x10    /* SIU�����ݕۗ����W�X�^SIPEND */
#define TADR_SIU_SIMASK 0x14    /* SIU�����݃}�X�N���W�X�^SIMASK */

				/*  ���2�o�C�g�̂ݎg�p����  */
#define SIMASK		(VH *)(IMMR_BASE + TADR_SIU_SIMASK)
#define SIMASK_IRM0	BIT0_16		/*  IRQ0  */
#define SIMASK_LVM0	BIT1_16		/*  �������x��0  */
#define SIMASK_IRM1	BIT2_16		/*  IRQ1  */
#define SIMASK_LVM1	BIT3_16		/*  �������x��1  */
#define SIMASK_IRM2	BIT4_16		/*  IRQ2  */
#define SIMASK_LVM2	BIT5_16		/*  �������x��2  */
#define SIMASK_IRM3	BIT6_16		/*  IRQ3  */
#define SIMASK_LVM3	BIT7_16		/*  �������x��3  */
#define SIMASK_IRM4	BIT8_16		/*  IRQ4  */
#define SIMASK_LVM4	BIT9_16		/*  �������x��4  */
#define SIMASK_IRM5	BIT10_16	/*  IRQ5  */
#define SIMASK_LVM5	BIT11_16	/*  �������x��5  */
#define SIMASK_IRM6	BIT12_16	/*  IRQ6  */
#define SIMASK_LVM6	BIT13_16	/*  �������x��6  */
#define SIMASK_IRM7	BIT14_16	/*  IRQ7  */
#define SIMASK_LVM7	BIT15_16	/*  �������x��7  */

#define TADR_SIU_SIEL   0x18    /* SIU�����݃G�b�W�^���x�����W�X�^SIEL */
#define TADR_SIU_SIVEC  0x1c    /* SIU�����݃x�N�^���W�X�^SIVEC */
#define TADR_SIU_TESR   0x20    /* �]���G���[�X�e�[�^�X���W�X�^TESR */
#define TADR_SIU_SDCR   0x30    /* SDMA�R���t�B�M�����[�V�������W�X�^SDCR */

/*
 *  11.7 �\�t�g�E�F�A�E�E�H�b�`�h�b�N�^�C�}�֘A�̒�`
 */
#define TADR_SIU_SYPCR   0x4    /* �V�X�e���ی�R���g���[�����W�X�^SYPCR */
#define SYPCR_SWE 	 BIT29_32  /*  �C�l�[�u��  */
#define SYPCR_SWRI 	 BIT30_32  /*  ���Z�b�g�^�����ݑI��  */ 
#define TADR_SIU_SWSR    0xe       /* �\�t�g�E�F�A�T�[�r�X���W�X�^SWSR */
#define SWSR_CLEAR1      0x556c    /* �N���A���ɏ������ޒ萔�P */
#define SWSR_CLEAR2      0xaa39    /* �N���A���ɏ������ޒ萔�Q */

/*
 *  12 ���Z�b�g�֘A�̒�`
 */
#define TADR_SIU_RSR  0x288  /* ���Z�b�g�E�X�e�[�^�X�E���W�X�^RSR */
#define TADR_SIU_RSRK 0x388  /* ���Z�b�g�E�X�e�[�^�X�E���W�X�^�E�L�[ */
#define RSR_EHRS BIT0_32    /* �O���n�[�h�E���Z�b�g�E�X�e�[�^�X */
#define RSR_ESRS BIT1_32    /* �O���\�t�g�E���Z�b�g�E�X�e�[�^�X */
#define RSR_LLRS BIT2_32    /* ���b�N�������Z�b�g�E�X�e�[�^�X */
#define RSR_SWRS BIT3_32    /* �\�t�g�E�F�A�E�E�H�b�`�h�b�N�E���Z�b�g */
#define RSR_CSRS BIT4_32    /* �`�F�b�N�E�X�g�b�v�E���Z�b�g�E�X�e�[�^�X */
    		/* �f�o�b�O�E�|�[�g�E�n�[�h�E���Z�b�g�E�X�e�[�^�X */
#define RSR_DBHRS BIT5_32
    		/* �f�o�b�O�E�|�[�g�E�\�t�g�E���Z�b�g�E�X�e�[�^�X */
#define RSR_DBSRS BIT6_32
#define RSR_JTRS BIT4_32    /* JTAG���Z�b�g�E�X�e�[�^�X */


/*
 *  �ʐM�v���Z�b�T���W���[��CPM�֘A
 */

/*
 *  35. CPM�����݃R���g���[���֘A�̒�`
 */
#define TADR_CPM_CIVR   0x930   /* CPM�����݃x�N�^���W�X�^CIVR */
#define TADR_CPM_CICR   0x940   /* CPM�����݃R���t�B�M�����[�V���� */
                                /*                   ���W�X�^CICR  */
#define TADR_CPM_CIPR   0x944   /* CPM�����ݕۗ����W�X�^CIPR */
#define TADR_CPM_CIMR   0x948   /* CPM�����݃}�X�N���W�X�^CIMR */
#define TADR_CPM_CISR   0x94c   /* CPM�����݃C���T�[�r�X���W�X�^CISR */

/* CPM�����݃R���t�B�M�����[�V���� ���W�X�^CICR */
#define CICR            (VW *)(IMMR_BASE + TADR_CPM_CICR)
#define CICR_IEN        BIT24_32

/* CPM�����݃}�X�N���W�X�^CIMR */
#define CIMR            (VW *)(IMMR_BASE + TADR_CPM_CIMR)
#define CIMR_PC15       BIT0_32     
#define CIMR_SCC1       BIT1_32     
#define CIMR_SCC2       BIT2_32     
#define CIMR_SCC3       BIT3_32     
#define CIMR_SCC4       BIT4_32     
#define CIMR_PC14       BIT5_32     
#define CIMR_TIMER1     BIT6_32     
#define CIMR_PC13       BIT7_32     
#define CIMR_PC12       BIT8_32     
#define CIMR_SDMA       BIT9_32     
#define CIMR_IDMA1      BIT10_32        
#define CIMR_IDMA2      BIT11_32        
#define CIMR_TIMER2     BIT13_32        
#define CIMR_RTT        BIT14_32        
#define CIMR_I2C        BIT15_32        
#define CIMR_PC11       BIT16_32        
#define CIMR_PC10       BIT17_32        
#define CIMR_TIMER3     BIT19_32        
#define CIMR_PC9        BIT20_32        
#define CIMR_PC8        BIT21_32        
#define CIMR_PC7        BIT22_32        
#define CIMR_TIMER4     BIT24_32        
#define CIMR_PC6        BIT25_32        
#define CIMR_SPI        BIT26_32        
#define CIMR_SMC1       BIT27_32        
#define CIMR_SMC2       BIT28_32        
#define CIMR_PC5        BIT29_32        
#define CIMR_PC4        BIT30_32        

/* CPM�����݃C���T�[�r�X���W�X�^CISR */
#define CISR            (VW *)(IMMR_BASE + TADR_CPM_CISR)
#define CISR_BIT(device)	_CISR_BIT(device)
#define _CISR_BIT(device)	CIMR_##device

/*
 *  CPM�����ݐ���r�b�g�̒�`
 */
    /*  CPM�����݃x�N�^���W�X�^CIVR���W�X�^��IACK�r�b�g  */
#define TA_CPM_CIVR_IACK    0x1 


/*
 *  15. �N���b�N�I���Ɠd�͐���֘A�̃��W�X�^��`
 */

/*  �V�X�e���N���b�N����у��Z�b�g���䃌�W�X�^  */
#define TADR_SCCR   0x280
#define SCCR        (VW *)(IMMR_BASE + TADR_SCCR)
#define TADR_SCCRK  0x380       /*  �L�[���W�X�^  */
#define SCCRK       (VW *)(IMMR_BASE + TADR_SCCRK)

#define SCCR_RTDIV  BIT7_32     /*  ���A���^�C���N���b�N����  */
                                /*  0�F4�ŕ����A1�F512�ŕ���  */
#define SCCR_RTSEL  BIT8_32     /*  ���A���^�C���N���b�N�I��  */
                                /*  0�FOSCM�i�����I�V���[�^�j�A1�FEXTCLK  */
#define SCCR_CRQEN  BIT9_32     /*  CPM�v���C�l�[�u��  */
#define SCCR_PRQEN  BIT10_32    /*  �p���[�}�l�W�����g�v���C�l�[�u��  */
#define SCCR_EBDF   (BIT13_32 | BIT14_32)   /*  �O���o�X�����W��  */
#define SCCR_DFBRG  (BIT19_32 | BIT20_32)   /*  BRGCLK�̕����W��  */

/*  SPLL �A��d�́A����у��Z�b�g���䃌�W�X�^  */
#define TADR_PLPRCRK    0x384   /*  ���W�X�^�E�L�[  */
#define TADR_PLPRCR     0x284   
#define PLPRCR_TIMIST   BIT19_32    /*  �^�C�}�����݃X�e�[�^�X  */
#define PLPRCR_CSRC     BIT21_32    /*  �N���b�N�\�[�X  */
                                    /*  ��d�̓��[�h  */
#define PLPRCR_LPM      (BIT22_32 | BIT23_32)
#define PLPRCR_LPM10    BIT22_32


/*
 *  16. �������R���g���[���̃��W�X�^��`
 */

/*  �x�[�X���W�X�^BRx  */
#define TADR_BR0    0x100
#define TADR_BR1    0x108
#define TADR_BR2    0x110
#define TADR_BR3    0x118
#define TADR_BR4    0x120
#define TADR_BR5    0x128
#define TADR_BR6    0x130
#define TADR_BR7    0x138

/*  �I�v�V�������W�X�^ORx  */
#define TADR_OR0    0x104
#define TADR_OR1    0x10c
#define TADR_OR2    0x114
#define TADR_OR3    0x11c
#define TADR_OR4    0x124
#define TADR_OR5    0x12c
#define TADR_OR6    0x134
#define TADR_OR7    0x13c

#define TADR_MAMR   0x170   /*  �}�V��A���[�h�E���W�X�^  */
#define TADR_MBMR   0x174   /*  �}�V��B���[�h�E���W�X�^  */
#define TADR_MSTAT  0x178   /*  �������X�e�[�^�X�E���W�X�^MSTAT  */

#define TADR_MCR    0x168   /*  �������E�R�}���h�E���W�X�^MCR  */
#define TADR_MDR    0x17c   /*  �������E�f�[�^�E���W�X�^MDR  */
#define TADR_MAR    0x164   /*  �������E�A�h���X�E���W�X�^MAR  */
#define TADR_MPTPR  0x17a   /*  �����������^�C�}�E�v���X�P�[��  */
                            /*  �@�@�@�@�@�@�@�@�@�@���W�X�^MPTPR  */

/*
 *  19. �ʐM�v���Z�b�TCP�֘A�̃��W�X�^��`
 */

/*  CP�R�}���h���W�X�^  */
#define CPCR        (VH *)(IMMR_BASE + 0x9c0)
#define CPCR_RST            BIT0_16  /*  ���Z�b�g�E�t���O  */
#define CPCR_FLG            BIT15_16 /*  �R�}���h�E�Z�}�t�H�E�t���O */
#define CPCR_CH_NUM_SMC1    0x9      /*  SMC1�̃`���l���ԍ�  */

/*  CP�R�}���h�̃I�y�R�[�h  */
#define CPCR_INIT_RX_TX_PARAMETERS	0x0
#define CPCR_STOP_TX			0x4
#define CPCR_RESTART_TX			0x6



/*  �f���A���E�|�[�gRAM�̐擪�A�h���X  */
#define DUAL_PORT_RAM   (IMMR_BASE + 0x2000)


/*
 *  20. SDMA�����IDMA�G�~�����[�V����
 *  �@�@�@�@SDMA�F�V���A��DMA
 *  �@�@�@�@IDMA�F���zSDMA
 */

/*  SDMA�R���t�B�M�����[�V�����E���W�X�^  */
#define SDCR            (VW *)(IMMR_BASE + 0x30)
	/* RISC�R���g���[���iCP�j�̒���ID */
	/* SDMA ��U �o�X����D��x5�F�ʏ폈�� */
#define SDCR_RAID_RB5   0x1

/*
 *  21. �V���A���C���^�[�t�F�[�XSI�֘A�̃��W�X�^��`
 */

/*  SI���[�h�E���W�X�^  */
#define SIMODE      (VW *)(IMMR_BASE + 0xae0)
#define SIMODE_SMC1 BIT16_32    /*  SMC1�̐ڑ�  */
                                /*  �@0:NMSI���[�h  */
                                /*  �@1:���d�������[�h  */

                                /*  SMC1�N���b�N�\�[�X  */
#define SIMODE_SMC1CS   (BIT17_32 | BIT18_32 | BIT19_32)    

/*  �{�[���[�g�E�W�F�l���[�^�E�R���t�B�M�����[�V�����E���W�X�^  */
#define BRGC1       (VW *)(IMMR_BASE + 0x9f0)
#define BRGC1_RST   BIT14_32    /*  BRG���Z�b�g  */
#define BRGC1_EN    BIT15_32    /*  BRG�J�E���g�C�l�[�u��  */
#define BRGC1_EXTC  (BIT16_32 | BIT17_32)   /*  �O���N���b�N�\�[�X  */
#define BRGC1_ATB   BIT18_32    /*  �I�[�g�{�[  */
#define BRGC1_CD    0x1ffe      /*  �N���b�N�E�f�o�C�_  */
#define BRGC1_DIV16 BIT31_32    /*  16����  */


/*
 *  34. �p������I/O�֘A�̃��W�X�^��`
 */

/*  �|�[�gB�s���E�A�T�C���E���W�X�^  */
#define TADR_PBPAR  0xabc
#define PBPAR       (VW *)(IMMR_BASE + TADR_PBPAR)
#define PBPAR_DD24  BIT24_32    /*  PB24�s���F��p�y���t�F�����@�\  */
#define PBPAR_DD25  BIT25_32    /*  PB25�s���F��p�y���t�F�����@�\  */
#define PBPAR_DD27  BIT27_32    /*  PB27�s���F��p�y���t�F�����@�\  */

/*  �|�[�gB�f�[�^�E�f�B���N�V�����E���W�X�^  */
#define TADR_PBDIR  0xab8
#define PBDIR       (VW *)(IMMR_BASE + TADR_PBDIR)
#define PBDIR_DR24  BIT24_32    /*  PB24�s���F�y���t�F�����@�\1  */
#define PBDIR_DR25  BIT25_32    /*  PB25�s���F�y���t�F�����@�\1  */
#define PBDIR_DR27  BIT27_32    /*  PB25�s���F�y���t�F�����@�\1  */

/*  �|�[�gB�I�[�v���E�h���C���E���W�X�^  */
#define TADR_PBODR  0xac0
#define PBODR       (VW *)(IMMR_BASE + TADR_PBODR)
#define PBODR_OD24  BIT24_32    /*  PB24�s���F�I�[�v���E�h���C���E�h���C�u  */
#define PBODR_OD25  BIT25_32    /*  PB25�s���F�I�[�v���E�h���C���E�h���C�u  */
#define PBODR_OD27  BIT27_32    /*  PB25�s���F�I�[�v���E�h���C���E�h���C�u  */

/*  �|�[�gB�f�[�^���W�X�^  */
#define TADR_PBDAT  0xac4
#define PBDAT_D27   BIT27_32


/*  �A�����b�N�̍ۂɃL�[���W�X�^�ɏ������ޒ萔  */
#define UNLOCK_KEY  0x55ccaa33

/*
 *  �������W�X�^�ی�̃��b�N�ƃA�����b�N
 *
 *�@�@�V���A���h���C�o�ƃ^�C�}�h���C�o�̗����ŗp���邽�߁A
 *�@�@���̃t�@�C���ɓ���Ă���
 */

/*  SCCR���b�N  */
    	/*  �l��UNLOCK_KEY�ȊO�ł���Ηǂ�  */
#define lock_sccr()     mpc860_wrw_mem(SCCRK, 0)

/*  SCCR�A�����b�N  */
#define unlock_sccr()	mpc860_wrw_mem(SCCRK, UNLOCK_KEY)


#endif /* _MPC860_H_ */
/*  end of file  */
