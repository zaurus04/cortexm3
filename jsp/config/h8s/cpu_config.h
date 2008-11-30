/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

/*
 *  �v���Z�b�T�ˑ����W���[��(H8S�p)
 *
 *  ���̃C���N���[�h�t�@�C���́Ct_config.h �݂̂���C���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���Ă͂Ȃ�Ȃ��D
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <cpu_rename.h>

/*
 *  �v���Z�b�T�֘A�̒�`
 */
#include <h8s.h>
#include <h8s_sil.h>

/*
 *  �ݒ�\�ȃJ�[�l���Ǘ����̍ō��������݃r�b�g�p�^�[��
 *  (�G�N�X�e���h���W�X�^�֐ݒ�;cpu_insn.h ���ŗ��p����̂ŁA��ɒ�`����B)
 */
#ifndef GDB_STUB
#define  MAX_IPM	7	/* = EXR_I2|EXR_I1|EXR_I0 (�ō����x��) */
#else  /* GDB_STUB */
#define  MAX_IPM	6	/* ���x���V�̊��荞�݂́AGDB_STUB �����p���� */
#endif /* GDB_STUB */

#define  str_MAX_IPM	TO_STRING(MAX_IPM)
			/* �����ݓ�������INTHDR_ENTRY�}�N���p (cpu_config.h) */

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 *    �����ŁAMAX_IPM�𗘗p���Ă���̂ŁA��`��ɓǂݍ���
 */
#include <cpu_insn.h>

/*
 *  chg_ipm/get_ipm ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_CHG_IPM

/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
#ifndef _MACRO_ONLY

typedef struct task_context_block {
	VP	sp;		/* �X�^�b�N�|�C���^ */
	FP	pc;		/* �v���O�����J�E���^ */
} CTXB;

#endif /* _MACRO_ONLY */

/*
 *  �V�X�e����ԎQ��
 */
#ifndef _MACRO_ONLY

/*
 *  �����݃l�X�g�J�E���^
 *    �l�X�g�J�E���^�̒l�ŃR���e�L�X�g�̔��f���s���̂ŁA�R���e�L�X�g�Q�Ǝ���
 *    ���p����B
 */

extern UW	intnest;

/*
 *  �R���e�L�X�g�Q��
 *    �����݃l�X�g�J�E���^��ǂݏo��������Ɋ����݂��������Ă��A�߂����Ƃ��ɂ�
 *    �R���e�L�X�g�����ɖ߂��Ă���
 */

Inline BOOL
sense_context(void)
{
	return( intnest > 0 );
}

Inline BOOL
sense_lock(void)
{
	return( current_intmask() == MAX_IPM );
}

#endif /* _MACRO_ONLY */

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

#ifndef _MACRO_ONLY

/*
 *  CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *
 *  task_intmask �́Achg_ipm ���T�|�[�g���邽�߂̕ϐ��Bchg_ipm ���T�|�[�g
 *  ���Ȃ��ꍇ�ɂ́At_unlock_cpu ���� task_intmask �� 0 �ɒu�������Ă悢�B
 */

#ifdef SUPPORT_CHG_IPM
extern IPM	task_intmask;	/* �^�X�N�R���e�L�X�g�ł̊����݃}�X�N */
#endif /* SUPPORT_CHG_IPM */

Inline void
t_lock_cpu(void)
{
	disint();		/* cpu_insn.h */
}

Inline void
t_unlock_cpu(void)
{
#ifdef SUPPORT_CHG_IPM
	/*
	 *  t_unlock_cpu ���Ăяo�����̂� CPU���b�N��Ԃ݂̂ł��邽�߁B
	 *  �����̓r���� task_intmask ����������邱�Ƃ͂Ȃ��B
	 */
	set_intmask(task_intmask);
#else /* SUPPORT_CHG_IPM */
	enaint();		/* cpu_insn.h */
#endif /* SUPPORT_CHG_IPM */
}

/*
 *  CPU���b�N�Ƃ��̉����i��^�X�N�R���e�L�X�g�p�j
 */

extern IPM	int_intmask;	/* ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N */

Inline void
i_lock_cpu(void)
{
	IPM	intmask;

	/*
	 *  �ꎞ�ϐ� intmask ���g���Ă���̂́Acurrent_intmask()���Ă񂾒����
	 *  �����݂��������A�N�����ꂽ�����݃n���h������ int_intmask ���ύX
	 *  �����\�������邽�߂ł���B
	 */
	intmask = current_intmask();
	disint();		/* cpu_insn.h */
	int_intmask = intmask;
}

Inline void
i_unlock_cpu(void)
{
	set_intmask(int_intmask);
}

/*
 *  �^�X�N�f�B�X�p�b�`��
 */

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�icpu_support.S�j
 *    dispatch �́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[���������ŁA
 *    CPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��B
 */
extern void	dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.S�j
 *    exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��B
 */
extern void	exit_and_dispatch(void);

/*
 *  �����݃n���h���̐ݒ�
 *    H8S�ł́A�����݃n���h���e�[�u���̐ݒ��ROM�ɒ��ڍs�����ߎg�p���Ȃ��B
 */

Inline void define_inh(INHNO inhno, FP inthdr) {
}

/*
 *  CPU��O�n���h���̐ݒ�
 *    H8S�ł́A�����݃n���h���e�[�u���̐ݒ��ROM�ɒ��ڍs�����ߎg�p���Ȃ��B
 */

Inline void define_exc(EXCNO excno, FP exchdr) {
}

#endif /* _MACRO_ONLY */

/*
 *  �����݃n���h���̏o��������
 */

/*
 *  �����݃n���h���̓�������
 *    ���̏����ɗ���܂łɁA�n�[�h�E�F�A�ɂāA���Y�����݃��x���܂ł̊����݂�
 *    �֎~���鏈�����s���Ă���B
 *    entry�F���������̃��x��
 *    inthdr�FC���ꃋ�[�`���̐擪�A�h���X
 */
#define	_INTHDR_ENTRY(entry, inthdr)		    \
asm("	.text					\n" \
"	.align 2				\n" \
"	.global _"#entry"			\n" \
"						\n" \
"_"#entry":					\n" \
"	push.l	er0				\n" \
			/* CPU���b�N�ɕK�v�ȃ��W�X�^���^�X�N�X�^�b�N�ɑҔ� */ \
"	stc.b	exr, r0l			\n" \
			/* exr �� r0l (er0) �ɃR�s�[ \
"			  (_kernel_ret_main ���ŁA�����݋֎~������Ɏg��) */ \
"						\n" \
"	ldc.b	#"str_MAX_IPM", exr		\n" \
			/* lock_cpu ���� (�����݋֎~) */ \
"						\n" \
"	push.l	er1				\n" \
			/* er1 ���^�X�N�X�^�b�N�ɑҔ� */ \
"	mov.l	#_"#inthdr", er1		\n" \
			/* er1 = �����݃n���h���̃A�h���X */ \
"	jmp	_kernel_ret_main		\n" \
			/* �����ݓ��������փW�����v */ \
)

/*
 *  �����݃n���h���̏o���������̐����}�N��
 */
#define INTHDR_ENTRY(inthdr)			\
	extern void inthdr##_entry(void);	\
	_INTHDR_ENTRY(inthdr##_entry, inthdr)	/* ���̏����͏�L�}�N���Œ�` */
#define	INT_ENTRY(inthdr)	inthdr##_entry

/* �x�N�^�e�[�u��(sys_support.S)�L�q�p���x���擾�}�N�� */
#define	__INT_ENTRY(inthdr)	_##inthdr##_entry
#define	_INT_ENTRY(inthdr)	__INT_ENTRY(inthdr)

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 */
#define	EXCHDR_ENTRY(exchdr)	INTHDR_ENTRY(exchdr)
#define	EXC_ENTRY(exchdr)	exchdr##_entry

/* �x�N�^�e�[�u��(sys_support.S)�L�q�p���x���擾�}�N�� */
#define	__EXC_ENTRY(exchdr)	_##exchdr##_entry
#define	_EXC_ENTRY(exchdr)	__EXC_ENTRY(exchdr)

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */
#ifndef _MACRO_ONLY

/*
 *  CPU��O�̔����������̃R���e�L�X�g����
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return(intnest > 1);
		/* 1�Ɣ�r����̂́A���ݎ��s����CPU��O�̕������݃l�X�g
		   �J�E���^���C���N�������g����Ă��邽�� */
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 *    H8S�łł́A�Ă΂�邱�Ƃ͖������A�\�[�X���r����ꍇ�����ɐݒ肷��B
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return(TRUE);
}

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void	cpu_terminate(void);

#endif /* _MACRO_ONLY_ */

/*============================================================================*/
/*  ���ʃh�L�������g�ɂ͂Ȃ��A�Ǝ��̕���  */

/*
 *  �����݃��x���ݒ�p�}�N���i�������́A�C�����C���֐��j
 *  �Ex : �C���^���v�g�v���C�I���e�B���W�X�^	( IPRA - IPRK )
 *  �Ey : IPR�ݒ�p�}�X�N�i��ʂ����ʂ̑I���j	( IPR_UPR, IPR_LOW )
 *  �Ez : �����݃��x��				( 0 - 7 )
 */
#ifndef _MACRO_ONLY

Inline void icu_set_ilv( VP ipr, BOOL mask, INT level ) {

	if( mask == IPR_UPR ) {
		h8s_wrb_mem( ipr, ( h8s_reb_mem( ipr ) & ~IPR_UPR_MASK ) | TO_HI4((UB) level) );
	} else if( mask == IPR_LOW ) {
		h8s_wrb_mem( ipr, ( h8s_reb_mem( ipr ) & ~IPR_LOW_MASK ) | TO_LO4((UB) level) );
	}
}

#endif /* _MACRO_ONLY_ */

#ifndef _MACRO_ONLY
/*
 *  ����`�����ݔ������̃G���[�o�� (cpu_config.c, cpu_support.S)
 *    �\���� EXCSTACK �́Ah8s.h �Œ�`
 */
extern void	cpu_experr(EXCSTACK *sp);

#endif /* _MACRO_ONLY_ */

#endif /* _CPU_CONFIG_H_ */
