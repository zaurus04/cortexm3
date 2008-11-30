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
 *  @(#) $Id: sys_config.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iMPC860T TB6102S�p�j
 *�@�@�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@�@�@�f�[�^�^�A�}�N���A�֐��̃v���g�^�C�v�錾
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _SYS_CONFIG_H_
#define _SYS_CONFIG_H_

/*
 *  ���[�U�[��`���
 */
#include <user_config.h>

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <sys_rename.h>

/*
 *  �^�[�Q�b�g�V�X�e���̃n�[�h�E�F�A�����̒�`
 */
#include <tb6102s.h>
#include <mpc860t.h>


/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define	TARGET_NAME	"TANBAC TB6102S CompactPCI CPU Board"

/*
 *  �������ԑ҂��̂��߂̒�`
 */
#ifdef DOWNLOAD_TO_RAM      /*  �f�o�b�O�p  */

#define	SIL_DLY_TIM1	1425
#define	SIL_DLY_TIM2	 350

#else /* DOWNLOAD_TO_RAM */ /*  ROM��  */

#define	SIL_DLY_TIM1	3445
#define	SIL_DLY_TIM2	 867

#endif /* DOWNLOAD_TO_RAM */

#ifndef _MACRO_ONLY

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void	sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���D
 *�@�@ROM���j�^�^GDB STUB�ďo���͖�����
 */
extern void	sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���D
 *�@�@ROM���j�^�^GDB STUB�ďo���͖�����
 */
extern void	sys_putc(char c) throw();

#endif /* _MACRO_ONLY */

/*
 * �@CPM�ւ̊����ݗv���̃N���A
 * �@�@CPM�����݃C���T�[�r�X���W�X�^CISR�̊Y���r�b�g�ɂP���Z�b�g�����
 * �@�@�N���A�����B
 */
#define CLEAR_IRQ_TO_ICU(device)		\
	mpc860_wrw_mem(CISR, CISR_BIT(device))	


/*
 * �@�o�^����Ă��Ȃ�SIU�����݂ɂ���������ݒ�
 * �@�@���i�̊����݂Ƒ��d�����݂ŁAsp�̎��o�������قȂ�
 */
#define SET_NO_REG_SIU_INTERRUPT_ARG_FROM_TASK	\
	lwz	r4, 0(sp)	/*  �����݃X�^�b�N����sp�𕜌�  */

#define SET_NO_REG_SIU_INTERRUPT_ARG_FROM_INT	\
	addi	r4, sp, 8	/*  sp+8  */

/*
 * �@�o�^����Ă��Ȃ�CPM�����݂ɂ���������ݒ�
 * �@�@���i�̊����݂Ƒ��d�����݂ŁAsp�̎��o�������قȂ�
 */
#define SET_NO_REG_CPM_INTERRUPT_ARG_FROM_TASK	\
	lwz	r4, 8(sp)	/*  �����݃X�^�b�N����sp�𕜌�  */

#define SET_NO_REG_CPM_INTERRUPT_ARG_FROM_INT	\
	addi	r4, sp, 16	/*  sp+16  */


#ifndef _MACRO_ONLY
/*
 * �o�^����Ă��Ȃ������ݔ������̃��O�o��
 * �@�@�}�N��PROC_ICU�̒��ŌĂяo�����B
 *     �֐���������̌^�̓v���Z�b�T���Ɍ��߂ėǂ��B
 *
 *     MPC860�ł͊����݃R���g���[�����J�X�P�[�h�ڑ�����Ă��邽�߁A
 *�@�@ �e�����݃R���g���[���ɐ�p�̊֐���p�ӂ����B
 *
 */

/*  SIU�����݁iCPM�����݈ȊO�j  */
extern void     no_reg_SIU_interrupt(INHNO intno, UW *sp);

/*  CPM������  */
extern void     no_reg_CPM_interrupt(INHNO intno, UW *sp);

#endif /* _MACRO_ONLY */

#define EXCEPTION_VECTOR_START_SRC	0x10000100
#define EXCEPTION_VECTOR_END_SRC	0x10002000
#define EXCEPTION_VECTOR_START_DST	0x100



/*  --------------------------------------------------------------  */
/*
 * PowerPC���ʕ��Ƃ̃C���^�[�t�F�[�X�̒�`
 */

/*
 *   MSR�̏����l
 */
#define INIT_MSR    	0

/*
 *  �����ݏ�����ICU�ˑ�����
 *  �@�������e
 *  �@�@�E�����ݗv���̔���
 *  �@�@�E�����݃}�X�N�̐ݒ�
 *  �@�@�E�����݋���
 *  �@�@�EC���ꃋ�[�`���Ăяo��
 *  �@�@�E�����݋֎~
 *  �@�@�E�i�K�v�ł���΁j���荞�ݗv���t���O�̃N���A
 *  �@
 *  �@����
 *  �@  label�F���x�����ʗp������
 *  �@  �@�@�@�@�i�����ӏ��ł��̃}�N�����g�p�ł���悤�ɂ��邽�߁j
 *  �@
 *
 *  �@MPC860�̊����݃A�[�L�e�N�`����
 *  �@�@�E�V�X�e���E�C���^�[�t�F�[�X�E���j�b�gSIU
 *  �@�@�E�ʐM�v���Z�b�T���W���[��CPM
 *  �@��2�K�w�ɂȂ��Ă���
 *  �@
 *  �@�@MPC860�ł̓V�X�e���C���^�[�t�F�[�X���j�b�gSIU�̊����݃}�X�N
 *  �@�@�iSIU�����݃}�X�N���W�X�^SIMASK�j�݂̂��J�[�l���ŊǗ�����B
 *  �@�@�ʐM�v���Z�b�T���W���[��CPM�̊����݃}�X�N�̊Ǘ��͂��ׂ�
 *  �@�@�n�[�h�E�F�A���s���Ă���B
 *  �@
 *  �@CPM�����݃R���g���[���i�n�[�h�E�F�A�j�̓���
 *  �@  �@�����݂����������
 *  �@  �@�@�E�����ݕۗ����W�X�^CIPR�̊Y���r�b�g�̊Y���r�b�g���Z�b�g
 *  �@  �@�@�E�������������݂̗D��x��
 *  �@  �@�@�@�@�E�����݃}�X�N���W�X�^CIMR
 *  �@  �@�@�@�@�E�C���T�[�r�X���W�X�^CISR
 *  �@  �@�@�@�@�Ɣ�r���Ă���SIU�ɒʒm
 *  �@  �@�R�A���x�N�^���W�X�^CIVR��IACK�r�b�g���Z�b�g�����
 *  �@  �@�@�ESIU�ւ̊����ݗv�����N���A
 *  �@  �@�@�E�x�N�^���W�X�^CIVR�Ƀx�N�^�ԍ����Z�b�g
 *  �@  �@�@�E�x�N�^���W�X�^CIVR��IACK�r�b�g���N���A
 *  �@  �@�@�E�����ݕۗ����W�X�^CIPR�̊Y���r�b�g���N���A
 *  �@  �@�@�E�C���T�[�r�X���W�X�^CISR�̊Y���r�b�g���Z�b�g
 *  �@  �@�@�@�@�Ȍ�A�����艺�ʂ̊����݂��}�X�N����
 *  �@  �@�@�@�@�@�@��CPM�ɂ��Ă̓\�t�g�E�F�A�ɂ��}�X�N����̕K�v�Ȃ�
 *  �@  �@�@
 *  �@CPM�����݂Ɋւ��ẮASIU��IPM�Ɉꊇ���ē����l��ݒ肷��
 *  �@  �@�@
 *  �@
 *  �@���W�X�^���蓖�āF
 *  �@  SPRG1:�[���x�N�^�e�[�u���̐擪�A�h���Xint_table
 *  �@  SPRG3:IPM�e�[�u���̐擪�A�h���Xipm_table
 *  �@  r0�F�l�O
 *  �@  r3�F�������W�X�^�̈�̐擪�A�h���X
 *  �@  r4�F�����݃x�N�^�ԍ��~�S
 *  �@
 */
#define _PROC_ICU(label)                                                \
    /*  SIU�̊����ݗv������  */                                         \
    lis     r3, IMMR_UPPER_2BYTE; /* �������W�X�^�̈�̐擪�A�h���X */  \
        /*  �x�N�^�ԍ��̓ǂݏo��  */                                    \
        /*  SIVEC���W�X�^�ɂ�"�x�N�^�ԍ��~4"���i�[����Ă���  */        \
    lbz     r4, TADR_SIU_SIVEC(r3); /*  r4���x�N�^�ԍ��~4  */           \
                                                                        \
    /*  �����݃}�X�N�̐ݒ�  */                                          \
    /*  �@SIU�����݁F�����ݗv�����̒l��IPM�ɐݒ肷��  */      		\
    /*  �@CPM�����݁F�ꊇ���ē����l��SIU��IPM�ɐݒ肷��  */   		\
    mfspr   r5, SPRG3;      /*  r5��ipm_table  */                       \
    srwi    r6, r4, 1;      /*  r6��r4>>1�i�����ݔԍ��~2�{�j  */        \
    lhzx    r7, r5, r6;     /*  r7�F�����݃}�X�N  */                    \
    	/*  ���݂̊����݃}�X�N���m�F���āA  */				\
    	/*  ���X�A������Ă��Ȃ������݂͋����Ȃ��悤�ɂ���  */	\
    lhz     r8, TADR_SIU_SIMASK(r3);					\
    and     r9, r8, r7;							\
    sth     r9, TADR_SIU_SIMASK(r3);/*  �����݃}�X�N�ݒ�  */            \
                                                                        \
    /*  CPM�����݂Ȃ�Ε���  */                                         \
    cmpwi   crf0, r4, INHNO_CPM*4;                                      \
    beq     label##_CPM_INTERRUPT;                                      \
                                                                        \
    /*  SIU�����݁iCPM�����݈ȊO�j�̏ꍇ  */                            \
    /*  �iSIU�ɒ��ځA�ڑ�����Ă���f�o�C�X����̊����݂̏ꍇ�j  */     \
    mfspr   r8, SPRG1;  /*  r8��SPRG1�Fint_table  */                    \
                        /*  r4�F�����ݔԍ��~4  */                       \
    lwzx    r9, r8, r4; /*  r9�FC���ꃋ�[�`���̐擪�A�h���X  */         \
    mtctr   r9;         /*  CTR��r9  */                                 \
    mfmsr   r10;                                                        \
    ori     r11, r10, MSR_EE;   /*  EE�r�b�g���Z�b�g  */                \
    mtmsr   r11;                /*  �����݋���  */                      \
    cmpwi   crf0, r9, 0;	/*  �����݃n���h�����o�^����Ă��邩 */ \
    beq     label##_call_no_reg_SIU_interrupt; /*  �`�F�b�N  */         \
    bctrl;                      /*  C���ꃋ�[�`���Ăяo��  */           \
    mfmsr   r10;                                                        \
    xori    r11, r10, MSR_EE;   /*  EE�r�b�g���N���A  */                \
    mtmsr   r11;        /*  �����݋֎~  */                              \
    b       label##_exit;/*  PROC_ICU�}�N���̏o���փW�����v  */         \
                                                                        \
    /*                                                                  \
�@�@ *�@�@SIU�����݁iCPM�����݈ȊO�j�Ŋ����݃n���h����                  \
�@�@ *�@�@�o�^����Ă��Ȃ��ꍇ                                          \
�@�@ */                                                                 \
label##_call_no_reg_SIU_interrupt:;                                     \
    srwi    r3, r4, 2;          /*  r3�������ݔԍ�  */                  \
    SET_NO_REG_SIU_INTERRUPT_ARG_##label;                               \
    LI32(r9, no_reg_SIU_interrupt);                                     \
    mtctr   r9;         /*  CTR��r9  */                                 \
    bctr;                                                               \
    /*  �����ɂ͖߂��Ă��Ȃ�  */                                        \
                                                                        \
    /*                                                                  \
�@�@ *�@�@CPM�����݂Ŋ����݃n���h����                                   \
�@�@ *�@�@�o�^����Ă��Ȃ��ꍇ                                          \
�@�@ */                                                                 \
label##_call_no_reg_CPM_interrupt:;                                     \
    srwi    r3, r4, 2;          /*  r3�������ݔԍ�  */                  \
    SET_NO_REG_CPM_INTERRUPT_ARG_##label;                               \
    LI32(r9, no_reg_CPM_interrupt);                                     \
    mtctr   r9;         /*  CTR��r9  */                                 \
    bctr;                                                               \
    /*  �����ɂ͖߂��Ă��Ȃ�  */                                        \
                                                                        \
                                                                        \
    /*  CPM�����݂̏ꍇ  */                                             \
    /*  �@�@SIU��IPM�͐ݒ�ς�  */                                      \
    /*  �@�@CPM��IPM�ݒ�̓n�[�h�E�F�A���s��  */                        \
label##_CPM_INTERRUPT:;                                                 \
    /*  CIVR���W�X�^��IACK�r�b�g���Z�b�g  */                            \
    li      r5, TA_CPM_CIVR_IACK;                                       \
    sth     r5, TADR_CPM_CIVR(r3);                                      \
    /*  CPM�����݃x�N�^�ԍ��ǂݏo��  */                                 \
            /*  �����݃x�N�^���W�X�^CIVR�ɂ̓x�N�^�ԍ���  */            \
            /*  11�r�b�g���V�t�g���ꂽ��ԂŊi�[����Ă���  */          \
    lhz     r6, TADR_CPM_CIVR(r3);  /*  r6���x�N�^�ԍ�<<11  */          \
    srwi    r4, r6, 9;  /*  r4��r6>>9�i�����ݔԍ��~4�{�j  */            \
    stwu    r4, -STACK_MARGIN(sp); /*  �x�N�^�ԍ���ۑ�  */             \
    		/*  sp��8�o�C�g���炷�̂́AC���ꃋ�[�`����  */		\
    		/*  sp+4�Ԓn�ɏ������݂��s������  */			\
        /*  CPM���[�J���̃x�N�^�ԍ���SIU�S�̂̃x�N�^�ԍ��ɕϊ�  */      \
    addi    r5, r4, TMAX_SIU_INTNO*4;                                   \
    mfspr   r8, SPRG1;  /*  r8��SPRG1�Fint_table  */                    \
                        /*  r4�F�����ݔԍ��~4  */                       \
    lwzx    r9, r8, r5; /*  r9�FC���ꃋ�[�`���̐擪�A�h���X  */         \
    mtctr   r9;         /*  CTR��r9  */                                 \
    mfmsr   r10;                                                        \
    ori     r11, r10, MSR_EE;   /*  EE�r�b�g���Z�b�g  */                \
    mtmsr   r11;                /*  �����݋���  */                      \
    cmpwi   crf0, r9, 0;	/*  �����݃n���h�����o�^����Ă��邩 */ \
    beq     label##_call_no_reg_CPM_interrupt; /*  �`�F�b�N  */         \
    bctrl;                      /*  C���ꃋ�[�`���Ăяo��  */           \
    mfmsr   r10;                                                        \
    xori    r11, r10, MSR_EE;   /*  EE�r�b�g���N���A  */                \
    mtmsr   r11;        /*  �����݋֎~  */                              \
    /*  �C���T�[�r�X���W�X�^CISR�̊Y���r�b�g���N���A  */                \
    /*      �i�P���������ނƃN���A�����j  */                          \
    lwz     r4, 0(sp);  /*  �x�N�^�ԍ��~4��ǂݏo��  */                 \
    addi    sp, sp, STACK_MARGIN;                                       \
    srwi    r5, r4, 2;  /*  r5��r4>>2�i�����ݔԍ��j  */                 \
    li      r6, 1;                                                      \
    slw     r7, r6, r5; /*  r7��1<<(�����ݔԍ�)  */                     \
    lis     r3, IMMR_UPPER_2BYTE; /* �������W�X�^�̈�̐擪�A�h���X */  \
    stw     r7, TADR_CPM_CISR(r3);                                      \
label##_exit:    /*  PROC_ICU�̏o�����x��  */

/* �}�N������label���m���ɓW�J���邽�߁A�}�N����2�d�ɂ��Ă��� */
#define PROC_ICU(label) _PROC_ICU(label)


/*
 * ���荞�݃R���g���[���̃}�X�NIPM�֘A�̒�`
 *  �@�@MPC860�ł̓V�X�e���C���^�[�t�F�[�X���j�b�gSIU�̊����݃}�X�N
 *  �@�@�iSIU�����݃}�X�N���W�X�^SIMASK�j�̂݃J�[�l���ŊǗ�����B
 *  �@�@�ʐM�v���Z�b�T���W���[��CPM�̊����݃}�X�N�̊Ǘ��͂��ׂăn�[�h
 *  �@�@�E�F�A���s���Ă���B
 */

/*  IPM�̑Ҕ�  */
#define PUSH_ICU_IPM                	\
    lis     r4, IMMR_UPPER_2BYTE;      	\
    lhz     r5, TADR_SIU_SIMASK(r4);    \
    sthu    r5, -4(sp)
    /*  �X�g�A��sp�̍X�V��1���߂Ŏ��s�����  */
    /*  �ۑ�����f�[�^��2�o�C�g�ł��邪�A  */
    /*  sp��4�o�C�g���E�Ɉێ����邽�߁A�I�t�Z�b�g��-4�Ƃ��Ă���  */

/*  IPM�̕���  */
#define POP_ICU_IPM                 			\
    lhz     r4, 0(sp);              			\
    lis     r5, IMMR_UPPER_2BYTE;   			\
    addi    sp, sp, 4;           /*  ��L�Q��  */	\
    sth     r4, TADR_SIU_SIMASK(r5) 


#ifdef SUPPORT_CHG_IPM
/*
 * ICU�ɐݒ肷��IPM�p�����[�^�̃`�F�b�N
 *
 *�@C�����
 *  �@if (ipm�̒l���s��) {
 *	ercd = E_PAR;
 *	goto exit;
 *    }
 *�@�Ɠ����̏������s���}�N��
 */
#define CHECK_IPM(ipm)
	/*  MPC860�ł͉����`�F�b�N���Ȃ�  */

/*
 * ���荞�݃R���g���[���̃}�X�N�擾
 */
#define GET_IPM(p_ipm)	*(p_ipm) = sil_reh_mem((VP)SIMASK)

/*
 * ���荞�݃R���g���[���̃}�X�N�ݒ�
 */
#define CHG_IPM(ipm)	sil_wrh_mem((VP)SIMASK, ipm)

#endif	/*  SUPPORT_CHG_IPM  */


#ifndef _MACRO_ONLY

/*
 *  �����݃}�X�N�p�[���x�N�^�e�[�u��
 *	ipm_table���̂�$(CPU)�Ƃ̃C���^�[�t�F�[�X�Ɋ܂܂�Ȃ�
 *�@�@�@�idefine_ipm�ɂ��A�B������Ă���j
 */
extern IPM ipm_table[];

/*
 *  ���荞�݃��x���̐ݒ�
 *	�����ݔԍ�inhno�̊����݂��󂯕t�����Ƃ��Ɋ����݃R���g���[����
 *	IPM�ɐݒ肷��l���`����B
 *	�f�o�C�X�h���C�o�̏����������Ŏg�p����邱�Ƃ�z�肵�Ă���B
 *
 *�@�@�@����
 *�@�@�@�@inhno�F�����݃n���h���ԍ�
 *�@�@�@�@ipm�F�����݃}�X�N
 *
 */
Inline void
define_ipm(INHNO inhno, IPM ipm)
{
	ipm_table[inhno] = ipm;
}

#endif /* _MACRO_ONLY */

/*  
 *  �ȓd�̓��[�h�ւ̈ڍs�Ɗ����݋���
 *  �@���s���ׂ��^�X�N���Ȃ��Ċ����ݑ҂��ɂȂ�Ƃ���
 *  �@�f�B�X�p�b�`���̒��Ŏg�p�����B
 *
 *  �@�E�����݂���߂��Ă�����Ɋ����݋֎~���s��
 *  �@�Er0�`r4�̓��e��j�󂵂Ă͂Ȃ�Ȃ�
 *  �@
 *  �@MCP860�ł̓h�[�Y�E���[�E���[�h��p����
 *  �@
 *  �@���W�X�^���蓖��
 *  �@�@r0�F�l�O
 *  �@�@r5�F�������W�X�^�̐擪�A�h���X
 *  �@�@r6�F���b�N�E�L�[���[�h0x55ccaa33
 */ 
#define SAVE_POWPER                                                 \
    lis     r5, IMMR_UPPER_2BYTE;                                   \
    LI32(r6, UNLOCK_KEY);                                           \
    stw     r6, TADR_SCCRK(r5);   /* SCCR�A�����b�N */              \
                                                                    \
    /* CRQEN=1�FCP�����삷��Ƃ��A�h�[�Y�E�n�C�E���[�h��    */      \
    /* PRQEN=1�F�����ݗv���Ńm�[�}���E�n�C�E���[�h��        */      \
    lwz     r7, TADR_SCCR(r5);                                      \
    oris    r7, r7, (SCCR_CRQEN | SCCR_PRQEN)>>16;                  \
    stw     r7, TADR_SCCR(r5);                                      \
                                                                    \
    stw     r0, TADR_SCCRK(r5);     /* SCCR���b�N */                \
                                                                    \
    stw     r6, TADR_PLPRCRK(r5);   /* PLPRC�A�����b�N */           \
                                                                    \
    /* PLPRCR                                   */                  \
    /*    TMIST=0�F�����݃\�[�X���N���A���Ă�   */                  \
    /*           �h�[�Y�E���[�E���[�h�ɖ߂�Ȃ� */                  \
    lwz     r8, TADR_PLPRCR(r5);                                    \
    ori     r8, r8, PLPRCR_TIMIST;                                  \
    xori    r8, r8, PLPRCR_TIMIST;                                  \
    stw     r8, TADR_PLPRCR(r5);                                    \
                                                                    \
    /* �h�[�Y�E���[�E���[�h�ɑJ�ڂ��邽�߂̒l�ݒ�   */              \
    /*      CSRC=1�F                                */              \
    /*      LPM=01�F                                */              \
    ori     r8, r8, (PLPRCR_CSRC | PLPRCR_LPM);                     \
    xori    r8, r8, PLPRCR_LPM10;                                   \
    stw     r8, TADR_PLPRCR(r5);                                    \
                                                                    \
    stw     r0, TADR_PLPRCRK(r5);   /* PLPRC���b�N */               \
                                                                    \
    /* �����݋��ƃh�[�Y�E���[�E���[�h�ւ̈ڍs */                  \
    mfmsr   r9;                                                     \
    ori     r9, r9, MSR_EE;         /*  EE�r�b�g�Z�b�g  */          \
    oris    r9, r9, MSR_POW>>16;    /*  POW�r�b�g�Z�b�g  */         \
    mtmsr   r9;                                                     \
    /*  �����Ŋ����݂�����i�h�[�Y�E���[�E���[�h�ő҂j  */        \
    /*  �@�����݂���߂����Ƃ���r9�����̒l�ɂȂ��Ă���  */          \
                                                                    \
    /*  �����݋֎~  */                                              \
    xori    r9, r9, MSR_EE;         /*  EE�r�b�g�N���A  */          \
    xoris   r9, r9, MSR_POW>>16;    /*  POW�r�b�g�N���A  */         \
    mtmsr   r9


/*
 * �C���v�������e�[�V�����ŗL�̗�O0x01000�̏������e���`�����}�N��
 * �@
 * �}�N��IMPLEMENT_EXCEPTION_01000����`����Ă���ꍇ�̂ݗL���ƂȂ�B
 * �������e�̓v���Z�b�T�̃C���v�������e�[�V�����ŗL�̂��̂Ȃ̂ŁA
 * �J�[�l���ɂ��o���������͑}�����ꂸ�A���̃}�N���Œ�`�����������e��
 * ���ڌĂяo�����B�i�܂�A�J�[�l���̊Ǘ��O�����j
 * ���̂��߁A���̏������ŃJ�[�l���̋@�\���Ăяo�����ꍇ�̓���͖���`��
 * ����B
 * �@
 * �I�t�Z�b�g0x01000�ȍ~�ɔz�u������O�v���͂P�Ƃ͌���Ȃ��B2�ȏ�
 * �̗�O�x�N�^���z�u�����ꍇ�A�I�t�Z�b�g�̎w����@�ɒ��ӂ��邱�ƁB
 * �@��̓I�ɂ�
 *     .org �I�t�Z�b�g - EXCEPTION_VECTOR_BASE
 * �̂悤�Ɏw�肷��B�ڂ�����cpu_support.S�̊Y�������Q�ƁB
 * �@
 */
#define MAKE_EXCEPTION_VECTOR(offset, name)	\
    .org offset - EXCEPTION_VECTOR_BASE;	\
name:;						\
  MAKE_EXCEPTION_ENTRY(offset)


#define IMPLEMENT_EXCEPTION_01000_PROC				\
software_emulation:;						\
  MAKE_EXCEPTION_ENTRY(0x1000);					\
								\
MAKE_EXCEPTION_VECTOR(0x1100, instruction_TLB_miss);		\
MAKE_EXCEPTION_VECTOR(0x1200, data_TLB_miss);			\
MAKE_EXCEPTION_VECTOR(0x1300, instruction_TLB_error);		\
MAKE_EXCEPTION_VECTOR(0x1400, data_TLB_error);			\
MAKE_EXCEPTION_VECTOR(0x1c00, data_break_point);		\
MAKE_EXCEPTION_VECTOR(0x1d00, instruction_break_point);		\
MAKE_EXCEPTION_VECTOR(0x1e00, peripheral_break_point);		\
MAKE_EXCEPTION_VECTOR(0x1f00, non_maskable_developement_port)


#endif /* _SYS_CONFIG_H_ */

/*  end of file  */
