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

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <cpu_rename.h>

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 */
#include <cpu_insn.h>

/*
 *  chg_ipm/get_ipm ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_CHG_IPM

/*
 *  TCB �֘A�̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */
#ifndef _MACRO_ONLY

/*  �^�X�N�R���e�L�X�g�u���b�N�̒�`  */
typedef struct task_context_block {
        VP	sp;             /* �X�^�b�N�|�C���^ */
        FP	pc;             /* �v���O�����J�E���^ */
} CTXB;

#endif /* _MACRO_ONLY */

/*  TCB ���̃t�B�[���h�̃r�b�g���̒�`  */
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */

/*
 *  �V�X�e����ԎQ��
 */

#ifndef _MACRO_ONLY

/*
 *  �R���e�L�X�g�Q��
 *    �����݃l�X�g�J�E���^��ǂݏo��������Ɋ����݂��������Ă��A�߂����Ƃ��ɂ�
 *    �R���e�L�X�g�����ɖ߂��Ă���B
 */
Inline BOOL sense_context() {

	UW intnest;

	Asm("move %0, "str_k0 :"=r"(intnest));

	return(intnest > 0);
}

Inline BOOL sense_lock() {

	return(!(current_sr() & SR_IE));
}

#endif /* _MACRO_ONLY */

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *    CPU���b�N��Ԃ̔��f�́A�X�e�[�^�X���W�X�^��IE�r�b�g��p���Ĕ��f���Ă���B
 */

#ifndef _MACRO_ONLY

Inline void t_lock_cpu() {

	disint();		/* cpu_insn.h */
}

Inline void t_unlock_cpu() {

	enaint();		/* cpu_insn.h */
}

#endif /* _MACRO_ONLY */

/*
 *  CPU���b�N�Ƃ��̉����i��^�X�N�R���e�L�X�g�p�j
 */

#define i_lock_cpu	t_lock_cpu
#define i_unlock_cpu	t_unlock_cpu

/*
 *  �^�X�N�f�B�X�p�b�`��
 */

#ifndef _MACRO_ONLY

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�icpu_support.S�j
 *    dispatch �́A�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[���������ŁA
 *    CPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��B
 */
extern void	dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.S�j
 *    exit_and_dispatch �́ACPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��B
 */
extern void	exit_and_dispatch(void);

/*
 *  �����݃n���h���^CPU��O�n���h���̐ݒ�
 */

/*  �����݃n���h���^�����݃}�X�N�[���e�[�u��  */
extern INT_TABLE int_table[ TMAX_ALL_INTNO ];

/*  ��O�n���h���[���e�[�u��  */
extern FP	 exc_table[ TMAX_CORE_EXCNO ];

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ�(�����ݗv���ԍ�)intno �̊����݃n���h���̋N���Ԓn��inthdr�ɐݒ�B
 */

Inline void define_inh(INTNO intno, FP inthdr) {

	int_table[intno].inthdr = inthdr;
}

/*
 *   CPU��O�n���h���̐ݒ�
 */

Inline void define_exc(EXCNO excno, FP exchdr) {

	exc_table[excno] = exchdr;
}

#endif /* _MACRO_ONLY */

/*
 *  �����݃n���h���̏o���������̐����}�N��
 */

#define	INTHDR_ENTRY(inthdr)  extern void inthdr(void)
#define INT_ENTRY(inthdr) inthdr

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 */
#define	EXCHDR_ENTRY(exchdr)  extern void exchdr(VP sp)
#define	EXC_ENTRY(exchdr)     exchdr

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

#ifndef _MACRO_ONLY

/*
 *  CPU��O�̔����������̃R���e�L�X�g����
 */
Inline BOOL exc_sense_context(VP p_excinf) {

	UW  nest;

	Asm( "move %0, "str_k0 : "=r"(nest) );

	return( nest > 1 );
		/* 1�Ɣ�r����̂́A���ݎ��s����CPU��O�̕����������݃l�X�g
		   �J�E���^���C���N�������g����Ă��邽�� */
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL exc_sense_lock(VP p_excinf) {

	/* Status���W�X�^�́A�X�^�b�N��22�Ԗڂɐς܂�Ă���B
	   exc_stack(mips3.h), cpu_support.S �Q�� */
	return( !( *((UW *)p_excinf + 21) & SR_IE) );
}

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY */

/*============================================================================*/
/*  ���ʃh�L�������g�ɂ͂Ȃ��A�Ǝ��̕���  */

/*  �v���Z�b�T�R�A�{�����݃R���g���[���ɐݒ肷�銄���݃}�X�N�̃`�F�b�N  */
#define CHECK_IPM(ipm)	     CHECK_CORE_IPM( (ipm.core >> 8) & 0xff );	\
			     CHECK_ICU_IPM( ipm.icu )

#ifndef _MACRO_ONLY

/*
 *  ���荞�݃��x���̐ݒ�i���ʕ�����͌Ăяo����Ȃ��j
 */

Inline void all_set_ilv(INTNO intno, IPM *ipm) {

	/*  MIPS�R�A�� intmask �e�[�u���̐ݒ�  */
	int_table[intno].intmask = SR_BEV | (ipm->core) | SR_IE;
			/* �����݃x�N�^���Akseg1�Ɏ����Ă��邽�߁ABEV=1 */

	/*  �����݃R���g���[���̊����݃}�X�N�e�[�u���̐ݒ�  */
	/*  �i�����݃��x���̐ݒ�j  */
	icu_set_ilv( intno, &(ipm->icu) );
}

#endif /* _MACRO_ONLY */

/*
 *  ���O�o�͗p�̊֐�
 */

#ifndef _MACRO_ONLY

/* �o�^����Ă��Ȃ������݁E��O�������̃��O�o�� (cpu_config.c, cpu_support.S) */
extern void     cpu_experr( EXCSTACK *sp, UW SR, UW CR );

#endif /* _MACRO_ONLY */

#endif /* _CPU_CONFIG_H_ */
