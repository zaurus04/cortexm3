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

#ifndef _PIC_ICU_H_
#define _PIC_ICU_H_

#ifndef _MACRO_ONLY
#include <sil.h>
#endif /* _MACRO_ONLY */

#include <rte_vr5500_cb.h>	/* ICU_BASE_ADDR */

/*
 *  �����݃R���g���[��(Programable Interrupt Controler)�֌W�̒�`
 */

/*  �����ݔԍ��̒�`�i0-7��mips3.h�Ŏg�p�B8�ȍ~���w�肷��B�j */
#define INTNO_TIMER0	 8	/*  �^�C�}�O      */
#define INTNO_SERIAL0	 9	/*  �V���A���O    */
#define INTNO_GBUS	10	/*  GBUS-INT0-    */
#define	INTNO_BUS_ERR	11	/*  BUS_ERROR     */
#define	INTNO_TIMER1	12	/*  �^�C�}�P      */
#define INTNO_SERIAL1	13	/*  �V���A���P    */
#define INTNO_PARALEL	14	/*  �p������      */
#define INTNO_DMAC	15	/*  DMAC_INTREQ-  */

/*  �����݃R���g���[�����Ǘ����銄���݂̖{��  */
#define TMAX_ICU_INTNO	8u

/*  �����݃R���g���[���̃��W�X�^�̃A�h���X��`  */
/* �ȉ���xxx_offset�́A�A�Z���u���Ŏg���B */
#define INT0M_offset	0x00
#define INT1M_offset	0x10
#define INTR_offset	0x20
#define INTEN_offset	0x30

#define ICU_INT0M	INT0M_offset
#define ICU_INT1M	INT1M_offset
#define ICU_INTR	INTR_offset
#define ICU_INTEN	INTEN_offset

/*  �����ݗv���r�b�g�p�^�[�� (���L�A�A�Z���u�������ł����p���Ă���B) */
#define TIMER0		BIT0
#define SERIAL0		BIT1
#define GBUS		BIT2
#define	BUS_ERR		BIT3
#define	TIMER1		BIT4
#define SERIAL1		BIT5
#define PARALEL		BIT6
#define DMAC		BIT7

/* ICU���̃��W�X�^�A�N�Z�X�p�̊֐�  */
#define icu_reb( addr )		sil_reb_mem( (VP)(ICU_BASE_ADDR + addr) )
#define icu_wrb( addr, val )	sil_wrb_mem( (VP)(ICU_BASE_ADDR + addr), val )

#define icu_orb( mem, val )	icu_wrb( mem, icu_reb( mem ) | val )
#define icu_andb( mem, val )	icu_wrb( mem, icu_reb( mem ) & val )

/*
 *  �����݃R���g���[���̊����݃}�X�N�֌W
 */

/*  �\����ICU_IPM���̃I�t�Z�b�g�����߂邽�߂̃}�N���imakeoffset.c�ŗp����j
    �Ȃ��A���̃}�N���Œ�`�����l�́A���ɗ��p���Ă��Ȃ��B*/
#define OFFSET_DEF_ICU_IPM	OFFSET_DEF(ICU_IPM, int1m)

/*  �����݃R���g���[���ɐݒ�\�Ȋ����݃}�X�N�r�b�g�p�^�[���i�ō��l�j*/
#define MAX_ICU_IPM  0xff

/*  �����݃R���g���[���ɐݒ肷�銄���݃}�X�N�̃`�F�b�N  */
#define CHECK_ICU_IPM(ipm)						       \
		CHECK_PAR( 0 < (ipm.int0m) && (ipm.int0m) <= MAX_ICU_IPM );    \
		CHECK_PAR( 0 < (ipm.int1m) && (ipm.int1m) <= MAX_ICU_IPM )

#ifndef _MACRO_ONLY

/*  �����݃R���g���[���ɑ΂��銄���݃}�X�N�̋[���e�[�u��  */
extern ICU_IPM icu_intmask_table[];

/*  �����݃R���g���[����intmask�e�[�u���̐ݒ�  */
Inline void icu_set_ilv(INTNO intno, ICU_IPM *ipm) {
	/* CHECK_ICU_IPM(ipm) �́A��ʃ��[�`���Ŏ��s�ς� */
	icu_intmask_table[intno].int0m = ipm->int0m;
	icu_intmask_table[intno].int1m = ipm->int1m;
}

/*  ���荞�݃R���g���[���̃}�X�N�ݒ�  */
Inline void icu_set_ipm(ICU_IPM *ipm) {
	/* CHECK_ICU_IPM(ipm) �́A��ʃ��[�`���Ŏ��s�ς� */
	icu_wrb( (VP) ICU_INT0M, ipm->int0m );
	icu_wrb( (VP) ICU_INT1M, ipm->int1m );
}

/*  ���荞�݃R���g���[���̃}�X�N�擾  */
Inline void icu_get_ipm(ICU_IPM *ipm) {
	ipm->int0m = icu_reb( (VP) ICU_INT0M );
	ipm->int1m = icu_reb( (VP) ICU_INT1M );
}

#endif /* _MACRO_ONLY */

/*============================================================================*/
/*  �A�Z���u�������֌W  */

/*  �����݋��r�b�g�̑Ҕ��ƕ���  */
/*  �����݃R���g���[��ICU��IPM���X�^�b�N�ɕۑ�  */
/*  ���[�h���E�̊֌W�ŁA�{����1�o�C�g�̃}�X�N�ł͂��邯��ǂ��A
    ���[�h���E�̂��߂�2�o�C�g�P�ʂň����K�v������B */
#define PUSH_ICU_IPM						\
	li	t1, ICU_BASE_ADDR;				\
	addi	sp, sp, -2*2;					\
	lb	t3, INT0M_offset(t1);	/* t3 = INT0M */	\
	lb	t4, INT1M_offset(t1);	/* t4 = INT1M */	\
	sh	t3, (sp);					\
	sh	t4, 2(sp)

/*  �����݃R���g���[��ICU��IPM���X�^�b�N���畜��  */
#define POP_ICU_IPM						\
	li	t1, ICU_BASE_ADDR;				\
	lh	t3, (sp);					\
	lh	t4, 2(sp);					\
	sb	t3, INT0M_offset(t1);	/* INT0M = t3 */	\
	sb	t4, INT1M_offset(t1);	/* INT1M = t4 */	\
	addi	sp, sp, 2*2

/*  �����݃R���g���[��ICU��IPM��ݒ�  */
/*      t0�Ɋ����ݗv���ԍ�����������ԂŌĂ΂��  */
/*      t0�̓��e���󂵂Ă͂����Ȃ�  */
/*      t1�Ɋ����ݗv���N���A�̒萔�������Ă���̂Ŕj�󂵂Ă͂Ȃ�Ȃ��B  */
#define SET_ICU_IPM								\
	la	t4, icu_intmask_table;	/*  �f�[�^�e�[�u���̐擪�A�h���X  */	\
	sll	t2, t0, 1;		/*  �I�t�Z�b�g�������ݗv���ԍ��~2�{	\
						(�}�X�N�́A2�o�C�g)  */		\
	li	t3, ICU_BASE_ADDR;						\
	add	t4, t4, t2;		/*  �擪�A�h���X�{�I�t�Z�b�g  */	\
	lh	t5, (t4);		/*  t5 = INT0M:INT1M  */		\
					/*  ���ӁF���g���G���f�B�A���ˑ�  */	\
	sb	t5, INT0M_offset(t3);	/*  INT0M=t5�̉���1�o�C�g  */		\
	srl	t6, t5, 8;							\
	sb	t6, INT1M_offset(t3);	/*  INT1M=t5�̏��1�o�C�g  */

/*  �f�o�C�X������ʏ�����W�J����}�N��  */
/*    �����ݗv����t0�ɓ���� proc_END �ɔ��  */
#define MAKE_PROC(device)		\
proc_##device:				\
	li	t0, INTNO_##device;	\
 	j	proc_END;		\
	nop;

/*  �����ݗv���̔���  */
/*    �����݃R���g���[����MIPS3�R�A��Int0�ɐڑ�����Ă���  */
/*    �}�X�N�̃`�F�b�N*/
#define PROC_INT0				\
	li      t2, ICU_BASE_ADDR;		\
	lb      t3, INTR_offset(t2);		\
	lb	t4, INT0M_offset(t2);		\
	and	t5, t3, t4;		/* INT0M �ƃ}�X�N */	\
	beq	t5, zero, proc_END;		\
	nop;					\
						\
proc_BIT0:					\
	andi	t4, t3, TIMER0;			\
	beq	t4, zero, proc_BIT1;		\
	nop;					\
MAKE_PROC(TIMER0)				\
						\
proc_BIT1:					\
	andi	t4, t3, SERIAL0;		\
	beq	t4, zero, proc_BIT2;		\
	nop;					\
MAKE_PROC(SERIAL0)				\
						\
proc_BIT2:					\
	andi	t4, t3, GBUS;			\
	beq	t4, zero, proc_BIT3;		\
	nop;					\
MAKE_PROC(GBUS)					\
						\
proc_BIT3:					\
	andi	t4, t3, BUS_ERR;		\
	beq	t4, zero, proc_BIT4;		\
	nop;					\
MAKE_PROC(BUS_ERR)				\
						\
proc_BIT4:					\
	andi	t4, t3, TIMER1;			\
	beq	t4, zero, proc_BIT5;		\
	nop;					\
MAKE_PROC(TIMER1)				\
						\
proc_BIT5:					\
	andi	t4, t3, SERIAL1;		\
	beq	t4, zero, proc_BIT6;		\
	nop;					\
MAKE_PROC(SERIAL1)				\
						\
proc_BIT6:					\
	andi	t4, t3, PARALEL;		\
	beq	t4, zero, proc_BIT7;		\
	nop;					\
MAKE_PROC(PARALEL)				\
						\
proc_BIT7:					\
	andi	t4, t3, DMAC;			\
	beq	t4, zero, proc_END;		\
	nop;					\
MAKE_PROC(DMAC)					\
						\
proc_END:

#endif /* _PIC_ICU_H_ */
