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

#ifndef _VR4131_ICU_H_
#define _VR4131_ICU_H_

/*
 *  �����݃R���g���[��(ICU)�֌W�̒�`
 */

/*  �����ݔԍ��̒�`�i0-7�Ԃ� mips3.h �Ŏg�p�B8�Ԉȍ~���w�肷��B�j */
/*  SYSINT1REG  */
#define INTNO_BAT        8	/*  �o�b�e��������  */
#define INTNO_POWER      9	/*  �p���[�X�C�b�`������  */
#define INTNO_RTCL1     10	/*  RTCLong1������  */
#define INTNO_ETIME     11	/*  ElipsedTime�^�C�}������ */
#define INTNO_GIU       12	/*  GIU������  */
#define INTNO_SIU       13	/*  SIU������  */
#define INTNO_SOFTINT   14	/*  �\�t�g�E�F�A������  */
#define INTNO_CLKRUN    15	/*  CLKRUN������  */

/*  SYSINT2REG  */
#define INTNO_RTCL2     16	/*  RTCLong2������  */
#define INTNO_LED       17	/*  LED������  */
#define INTNO_TCLK      18	/*  TClock�J�E���^������  */
#define INTNO_FIR       19	/*  FIR������  */
#define INTNO_DSIU      20	/*  DSIU������  */
#define INTNO_PCI       21	/*  PCI������  */
#define INTNO_SCU       22	/*  SCU������  */
#define INTNO_CSI       23	/*  CSI������  */
#define INTNO_BCU       24	/*  BCU������  */

/*  �����݃R���g���[�����Ǘ����銄���݂̖{��  */
#define TMAX_ICU_INTNO	17u

/*  �����݃R���g���[���̃��W�X�^�̃A�h���X��`  */
/* �ȉ��� xxx_asm�Axxx_offset �́A�A�Z���u���ł̗��p�����B */
#define ICU_BASE_ADDR		0x0f000000
#define ICU_BASE_ADDR_asm	ASM_SIL( ICU_BASE_ADDR )

#define SYSINT1_offset		0x80
#define MSYSINT1_offset		0x8c
#define MDSIUINT_offset		0x96
#define SYSINT2_offset		0xa0
#define MSYSINT2_offset		0xa6

#define MSYSINT1REG	(ICU_BASE_ADDR + MSYSINT1_offset)
				/* �V�X�e�������݃}�X�N���W�X�^1(���x��1) */
#define MDSIUINTREG	(ICU_BASE_ADDR + MDSIUINT_offset)
				/* DSIU�����݃}�X�N���W�X�^(���x��2)  */
#define MSYSINT2REG	(ICU_BASE_ADDR + MSYSINT2_offset)
				/* �V�X�e�������݃}�X�N���W�X�^2(���x��1) */

/*  �����ݗv���r�b�g�p�^�[�� (���L�A�A�Z���u�������ł����p���Ă���B) */
/* MSYSINT1REG / SYSINT1REG �֌W */
#define CLKRUNINTR	BIT12	/* CLKRUN ������ */
#define SOFTINTR	BIT11	/* �\�t�g�E�F�A������ */
#define SIUINTR		BIT9	/* SIU ������ */
#define	GIUINTR		BIT8	/* GIU(����) ������ */
#define	ETIMERINTR	BIT3	/* ElapsedTime�^�C�} ������ */
#define RTCL1INTR	BIT2	/* RTCLong1�^�C�} ������ */
#define POWERINTR	BIT1	/* �p���[�X�C�b�`������ */
#define BATINTR		BIT0	/* �o�b�e�������� */

/* MSYSINT2REG / SYSINT2REG �֌W */
#define BCUINTR		BIT9	/* BCU ������ */
#define CSIINTR		BIT8	/* CSI ������ */
#define SCUINTR		BIT7	/* SCU ������ */
#define PCIINTR		BIT6	/* PCI ������ */
#define DSIUINTR	BIT5	/* DSIU ������ */
#define FIRINTR		BIT4	/* FIR ������ */
#define TCLKINTR	BIT3	/* VTClock�J�E���^ ������ */
#define LEDINTR		BIT1	/* LED ������ */
#define RTCL2INTR	BIT0	/* RTCLong2 ������ */

/* MDSIUINTREG �֌W */
#define INTDSIU  	BIT11	/* DSIU�̕ω������݋��� */

/*
 *  �����݃R���g���[���̊����݃}�X�N�֌W
 */

/*  �\����ICU_IPM���̃I�t�Z�b�g�����߂邽�߂̃}�N���imakeoffset.c�ŗp����j
    �Ȃ��A���̃}�N���Œ�`�����l�́A���ɗ��p���Ă��Ȃ��B*/
#define OFFSET_DEF_ICU_IPM	OFFSET_DEF(ICU_IPM, msysint2)

/*  MSYSINT1,2�ɐݒ肵�Ă͂����Ȃ��r�b�g  */
#define NG_BIT_MSYSINT1	(BIT4 | BIT5 | BIT6 | BIT7 | BIT10 | BIT13 |BIT14 | BIT15)
#define NG_BIT_MSYSINT2	(BIT2 | BIT10 | BIT11 | BIT12 | BIT13 | BIT14 | BIT15)

/*  �����݃R���g���[���ɐݒ肷�銄���݃}�X�N�̃`�F�b�N  */
#define CHECK_ICU_IPM(ipm)						\
		CHECK_PAR(!(ipm.msysint1 & NG_BIT_MSYSINT1));		\
		CHECK_PAR(!(ipm.msysint2 & NG_BIT_MSYSINT2))

#ifndef _MACRO_ONLY

/*  �����݃R���g���[���ɑ΂��銄���݃}�X�N�̋[���e�[�u��  */
extern ICU_IPM icu_intmask_table[];

/*  �����݃R���g���[����intmask�e�[�u���̐ݒ�  */
Inline void icu_set_ilv(INTNO intno, ICU_IPM *ipm) {
	/* CHECK_ICU_IPM(ipm) �́A��ʃ��[�`���Ŏ��s�ς� */
	icu_intmask_table[intno].msysint1 = ipm->msysint1;
	icu_intmask_table[intno].msysint2 = ipm->msysint2;
}

/*  ���荞�݃R���g���[���̃}�X�N�ݒ�  */
Inline void icu_set_ipm(ICU_IPM *ipm) {
	/* CHECK_ICU_IPM(ipm) �́A��ʃ��[�`���Ŏ��s�ς� */
	vr4131_wrh_mem( (VP) MSYSINT1REG, ipm->msysint1 );
	vr4131_wrh_mem( (VP) MSYSINT2REG, ipm->msysint2 );
}

/*  ���荞�݃R���g���[���̃}�X�N�擾  */
Inline void icu_get_ipm(ICU_IPM *ipm) {
	ipm->msysint1 = vr4131_reh_mem( (VP) MSYSINT1REG );
	ipm->msysint2 = vr4131_reh_mem( (VP) MSYSINT2REG );
}

#endif /* _MACRO_ONLY */

/*============================================================================*/
/*  �A�Z���u�������֌W  */

/*  �����݋��r�b�g�̑Ҕ��ƕ���  */
/*  �����݃R���g���[��ICU��IPM���X�^�b�N�ɕۑ�  */
#define PUSH_ICU_IPM						\
    li      t1, ICU_BASE_ADDR_asm;				\
    addi    sp, sp, -2*2;					\
    lh      t3, MSYSINT1_offset(t1);	/* t3 = MSYSINT1REG */	\
    lh      t4, MSYSINT2_offset(t1);	/* t4 = MSYSINT2REG */	\
    sh      t3, (sp);						\
    sh      t4, 2(sp)

/*  �����݃R���g���[��ICU��IPM���X�^�b�N���畜��  */
#define POP_ICU_IPM							      \
    li      t1, ICU_BASE_ADDR_asm;					      \
    lw      t3, (sp);			/* t3 = MSYSINT2REG:MSYSINT1REG */    \
					/* ���ӁF���g���G���f�B�A���ˑ� */    \
    sh      t3, MSYSINT1_offset(t1);	/* MSYSINT1REG = t3�̉���2�o�C�g*/    \
    srl     t4, t3, 16;							      \
    sh      t4, MSYSINT2_offset(t1);	/* MSYSINT2REG = t3�̏��2�o�C�g*/    \
    addi    sp, sp, 2*2

/*  �����݃R���g���[��ICU��IPM��ݒ�  */
/*      t0�Ɋ����ݗv���ԍ�����������ԂŌĂ΂��  */
/*      t0�̓��e���󂵂Ă͂����Ȃ�  */
/*      t1�Ɋ����ݗv���N���A�̒萔�������Ă���̂Ŕj�󂵂Ă͂Ȃ�Ȃ��B  */
#define SET_ICU_IPM							      \
    la      t4, icu_intmask_table;	/* �f�[�^�e�[�u���̐擪�A�h���X */    \
    sll     t2, t0, 2;			/* �I�t�Z�b�g�������ݗv���ԍ��~4�{ */ \
    li      t3, ICU_BASE_ADDR_asm;					      \
    add     t4, t4, t2;			/* �擪�A�h���X�{�I�t�Z�b�g */        \
    lw      t5, (t4);			/* t5 = MSYSINT2REG:MSYSINT1REG */    \
					/* ���ӁF���g���G���f�B�A���ˑ� */    \
    sh      t5, MSYSINT1_offset(t3);	/* MSYSINT1REG = t5�̉���2�o�C�g */   \
    srl     t6, t5, 16;							      \
    sh      t6, MSYSINT2_offset(t3)	/* MSYSINT2REG = t5�̏��2�o�C�g */

/*  �f�o�C�X������ʏ�����W�J����}�N��
      �����ݗv���� t0 �ɓ���� proc_END �ɔ��  */
#define MAKE_PROC(device)	\
proc_##device:			\
    li      t0, INTNO_##device;	\
    j       proc_END;		\
    nop;

/*  �����ݗv���̔���  */
/*    �����݃R���g���[����MIPS3�R�A��Int0�ɐڑ�����Ă���}�X�N�̃`�F�b�N */
#define PROC_INT0						\
/*  �^�C�}�̉��������グ�邽�߁ASYSINT2REG���璲�ׂ�  */	\
    li      t1, ICU_BASE_ADDR_asm;				\
    lh      t3, SYSINT2_offset(t1);    /* t3 = SYSINT2REG */	\
    lh      t4, MSYSINT2_offset(t1);   /* t4 = MSYSINT2REG */	\
    and     t5, t3, t4;     /*  �����ݗv���r�b�g�Ƀ}�X�N  */	\
    beq     t5, zero, proc_SYSINT1;				\
    andi    t6, t5, (BIT0 | BIT1 | BIT2 | BIT3 | BIT4 );	\
    beq     t6, zero, proc_SYSINT2_HIGH_5BIT;			\
								\
/*  SYSINT2REG (b0:4) �̏���  */				\
    andi    t7, t5, ( RTCL2INTR | LEDINTR );			\
    beq     t7, zero, proc_SYSINT2_BIT3_4;			\
    andi    t8, t5, LEDINTR;					\
    beq     t8, zero, proc_LED;					\
MAKE_PROC(RTCL2);						\
MAKE_PROC(LED);							\
								\
proc_SYSINT2_BIT3_4:						\
    andi    t1, t5, TCLKINTR;					\
    beq     t1, zero, proc_FIR;					\
MAKE_PROC(TCLK);						\
MAKE_PROC(FIR);							\
								\
/*  SYSINT2REG (b5:9) �̏���  */				\
proc_SYSINT2_HIGH_5BIT:						\
    andi    t7, t5, (DSIUINTR | PCIINTR);			\
    beq     t7, zero, proc_SYSINT2_BIT7_7;			\
    andi    t2, t5, DSIUINTR;					\
    beq     t2, zero, proc_PCI;					\
MAKE_PROC(DSIU);						\
MAKE_PROC(PCI);							\
								\
proc_SYSINT2_BIT7_7:						\
    andi    t3, t5, SCUINTR;					\
    beq     t3, zero, proc_SYSINT2_BIT8_9;			\
MAKE_PROC(SCU);							\
								\
proc_SYSINT2_BIT8_9:						\
    andi    t4, t5, CSIINTR;					\
    beq     t4, zero, proc_BCU;					\
MAKE_PROC(CSI);							\
MAKE_PROC(BCU);							\
								\
/*  SYSINT1REG�̃`�F�b�N  */					\
/*  t1��ICU_BASE_ADDR����������Ԃł����ɗ���  */		\
proc_SYSINT1:							\
    lh      t3, SYSINT1_offset(t1);	/* t3 = SYSINT1REG */	\
    lh      t4, MSYSINT1_offset(t2);	/* t4 = MSYSINT1REG */	\
    and     t5, t3, t4;     /*  �����ݗv���r�b�g�Ƀ}�X�N  */	\
    andi    t6, t5, 0xff;					\
    beq     t6, zero, proc_SYSINT1_HIGH_BYTE;			\
								\
/*  SYSINT1REG (���ʃo�C�g) �̏���  */				\
    andi    t7, t5, (BATINTR | POWERINTR);			\
    beq     t7, zero, proc_SYSINT1_BIT2_3;			\
    andi    t8, t5, BATINTR;					\
    beq     t8, zero, proc_POWER;				\
MAKE_PROC(BAT);							\
MAKE_PROC(POWER);						\
								\
proc_SYSINT1_BIT2_3:						\
    andi    t1, t5, ETIMERINTR;					\
    beq     t1, zero, proc_ETIME;				\
MAKE_PROC(RTCL1);						\
MAKE_PROC(ETIME);						\
								\
/*  SYSINT1REG (��ʃo�C�g) �̏���  */				\
proc_SYSINT1_HIGH_BYTE:						\
    andi    t8, t5, (GIUINTR | SIUINTR);			\
    beq     t8, zero, proc_SYSINT1_BIT11_12;			\
    andi    t9, t5, GIUINTR;					\
    beq     t9, zero, proc_SIU;					\
MAKE_PROC(GIU);							\
MAKE_PROC(SIU);							\
								\
proc_SYSINT1_BIT11_12:						\
    andi    t1, t5, SOFTINTR;					\
    beq     t1, zero, proc_CLKRUN;				\
MAKE_PROC(SOFTINT);						\
MAKE_PROC(CLKRUN);						\
								\
proc_END:

/*============================================================================*/

/* �����ݏ����Ɋւ���A�����ݗv���̔��f���򏈗��̃V�X�e���ˑ��� */

	/*  �Ăяo���ꂽ�Ƃ��A       */
	/*    a1�ɃX�e�[�^�X���W�X�^ */
	/*    a2�Ɍ������W�X�^       */
	/*  �̒l�������Ă���         */

#define PROC_INTERRUPT_SYS							\
	and     t2, a2, a1;          /*  �����ݗv���r�b�g�Ƀ}�X�N��������  */	\
	andi    t3, t2, Cause_IP0;   /*  IP0�r�b�g���o��  */			\
	bne     t3, zero, proc_IP0;						\
	andi    t4, t2, Cause_IP1;   /*  IP1�r�b�g���o��  */			\
	bne     t4, zero, proc_IP1;						\
	andi    t5, t2, Cause_IP2;   /*  IP2�r�b�g���o��  */			\
	bne     t5, zero, proc_IP2;						\
	andi    t6, t2, Cause_IP3;   /*  IP3�r�b�g���o��  */			\
	bne     t6, zero, proc_IP3;						\
	andi    t7, t2, Cause_IP4;   /*  IP4�r�b�g���o��  */			\
	bne     t7, zero, proc_IP4;						\
	nop;									\
	/* VR4131�̏ꍇ�ACause_IP5��Cause_IP6�͖��ڑ��Ȃ̂ŏȗ� */		\
	/*�i�n�[�h�E�F�A��p196�Q�Ɓj*/						\
										\
	/* �Ȃ�炩�̌����ŕ���ł��Ȃ��ꍇ */					\
	j       join_interrupt_and_exception;					\
	nop;									\
										\
										\
/*  MIPS3�R�A���x���ŕ��򂵂����x���ł̏���		*/			\
/*    �����ݗv���ԍ��� t0 �ɓ����			*/			\
/*    �����ݗv���N���A�̂��߂̒萔�� t1 �ɓ����	*/			\
/*    set_ICU_IPM �֔��				*/			\
proc_IP7:   /*  �����ݗv��IP7�i�^�C�}�j�̏ꍇ  */				\
	xori    t1, zero, Cause_IP7;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP7;						\
										\
proc_IP0:   /*  �����ݗv��IP0�i�\�t�g�E�F�A������0�j�̏ꍇ  */			\
	xori    t1, zero, Cause_IP0;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP0;						\
										\
proc_IP1:   /*  �����ݗv��IP1�i�\�t�g�E�F�A������1�j�̏ꍇ  */			\
	xori    t1, zero, Cause_IP1;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP1;						\
										\
proc_IP2:   /*  �����ݗv��IP2�iInt0�j�̏ꍇ  */					\
            /*  �u���ׂĂ̊����݁v���ʒm�����B*/				\
	PROC_INT0;	/* ���򏈗��� vr4131_icu.h �Ń}�N����`����Ă��� */	\
	xori    t1, zero, Cause_IP2;						\
	j       set_ICU_IPM;							\
	nop;									\
										\
proc_IP3:   /*  �����ݗv��IP3�iInt1�j�̏ꍇ  */ 				\
            /*  �urtc_long1_intr�v�i�C���^�[�o���^�C�}�j���ʒm�����B*/	\
	xori    t1, zero, Cause_IP3;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP3;						\
										\
proc_IP4:   /*  �����ݗv��IP4�iInt2�j�̏ꍇ  */ 				\
            /*  �urtc_long2_intr�v�i�C���^�[�o���^�C�}�j���ʒm�����B*/	\
	xori    t1, zero, Cause_IP4;						\
	j       set_ICU_IPM;							\
	ori     t0, zero, INTNO_IP4;						\
										\
/*  �����݃R���g���[���ˑ��̃}�X�N�ݒ�  */					\
set_ICU_IPM:									\
										\
	SET_ICU_IPM;	/* �����݃}�X�N��ݒ肷��}�N��			    */	\
			/*   �������s���Ƃ��ɂ́A���L�ɂ�t0�At1�͗��p����� */	\
			/*   �Ŕj�󂵂Ȃ��悤�ɁA���ӂ��Ȃ���΂Ȃ�Ȃ��B   */	\
										\
/*  �������W�X�^IP�r�b�g�ɕێ�����Ă���e�튄���݂̊����ݗv�����N���A����B	\
    t1�ɂ́A�����ݗv���r�b�g�𔽓]�������̂������Ă���B */			\
										\
	mfc0    t8, Cause;							\
	and     t8, t8, t1;							\
	mtc0    t8, Cause;							\
										\
/*  �X�e�[�^�X���W�X�^�̃}�X�N�ݒ��C���ꃋ�[�`���Ăяo��  */			\
/*    t0�Ɋ����ݗv���ԍ����ݒ肳�ꂽ��Ԃł����ɗ���  */			\
	la      t3, int_table;   /* �[���x�N�^�A�h���X */			\
	sll     t4, t0, 3;       /* �����ݗv���ԍ���8�{				\
				      INT_TABLE�^�́A				\
					�n���h���̃A�h���X(4�o�C�g)		\
					�{MIPS3�R�A�̊����݃}�X�N(4�o�C�g)	\
				      �́A���v8�o�C�g�B */			\
	add     t5, t3, t4;      /* �x�N�^�A�h���X���Z�o */			\
	lw      t6, INT_TABLE_intmask(t5);					\
           		    	/*  IPM(�����݋��r�b�g)�ǂݏo���B		\
				    �����݃}�X�N�ȊO�̒l�́A			\
					IE�r�b�g�̓Z�b�g			\
					EXL�r�b�g�̓��Z�b�g			\
				    ��ԂɂȂ��Ă���B*/			\
	lw      t7, (t5);        /* C���ꃋ�[�`���擪�A�h���X�ǂݏo��  */	\
										\
	jalr    ra, t7;          /* C���ꃋ�[�`���Ăяo��  */			\
	mtc0    t6, Status;      /* �����݋��G�X�e�[�^�X���W�X�^�̃}�X�N�ݒ�*/\
										\
	mfc0    t0, Status;							\
	ori     t0, t0, SR_EXL;  /* �����݋֎~�GIE�r�b�g�̒l�͕ێ����Ȃ���΂Ȃ�\
						�Ȃ��̂�EXL�r�b�g��p����B*/	\
	mtc0    t0, Status;							\
										\
	/*  CP0�n�U�[�h�̂��߂̎��ԉ҂�  */					\
	NOP_FOR_CP0_HAZARD;

#endif /* _VR4131_ICU_H_ */
