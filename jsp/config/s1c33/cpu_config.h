/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */

/*
 *  �v���Z�b�T�ˑ����W���[��(S1C33�p)
 */


#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include "cpu_rename.h"


/*
 *  �ݒ�\�ȍō����荞�ݗD��x
 */
#define	TPS_INTLEV_MAX	(0x04)
#define	TPS_CPULOCK_LEV	(TPS_INTLEV_MAX + 1)

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 */
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g��	 */


#ifndef _MACRO_ONLY
/*
 *  TCB �֘A�̒�`
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 *  Task context block.
 */
typedef struct task_context_block {
	VP sp;				/* �X�^�b�N�|�C���^	*/
	FP pc;				/* �v���O�����J�E���^	*/
} CTXB;


/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`(cpu_config.c)
 *
 *  dispatch �́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[������
 *  ���ŁCCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`(cpu_config.c)
 *
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void exit_and_dispatch(void);

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void	cpu_terminate(void);

/*
 *  CPU���b�N�������ɕ������銄�荞�݃��x��
 */
extern UINT	tps_OrgIntLevel;

/*
 *  �����݃l�X�g�J�E���^
 */
extern UINT	tps_IntNestCnt;

/*
 *  �r�b�g�T�[�`�}�N���g�p�̐ݒ�
 */
#ifndef __c33pe
#define CPU_BITMAP_SEARCH
#endif  /* __c33pe */

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 */
#include "cpu_insn.h"

/*
 * �V�X�e����ԎQ�Ɗ֐��̕ʖ���`
 */
#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock
#define	t_lock_cpu	lock_cpu
#define	i_lock_cpu	lock_cpu
#define	t_unlock_cpu	unlock_cpu
#define	i_unlock_cpu	unlock_cpu

/*
 *  ���݂̃R���e�L�X�g��Ԃ��Q��
 */
Inline BOOL
sense_context()
{
	return ((tps_IntNestCnt) ? TRUE : FALSE);
}

/*
 *  ���݂�CPU���b�N��Ԃ��Q��
 */
Inline BOOL
sense_lock()
{
	UW	ulIntLevel;

	ulIntLevel = get_psr();

	ulIntLevel = (ulIntLevel & S1C33_PSR_MASK_IL);
	return ((ulIntLevel < (TPS_CPULOCK_LEV << 8)) ? FALSE : TRUE);
}

/*
 * CPU���b�N��Ԑݒ菈��
 */
Inline void
lock_cpu()
{
	UW	ulPsr, ulIntLevel;

	ulPsr = get_psr();
	ulIntLevel = (ulPsr & S1C33_PSR_MASK_IL);

	if(ulIntLevel < (TPS_CPULOCK_LEV << 8)){
		ulPsr &= ~S1C33_PSR_MASK_IL;
		set_psr(ulPsr | (TPS_CPULOCK_LEV << 8));
		tps_OrgIntLevel = ulIntLevel;
	}
}

Inline void
unlock_cpu()
{
	UW	ulPsr;

	ulPsr = get_psr();
	ulPsr &= ~S1C33_PSR_MASK_IL;
	ulPsr |= tps_OrgIntLevel;
	tps_OrgIntLevel = (TPS_INIT_INTLEVEL << 8);

	set_psr(ulPsr);
}

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */
/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return ((tps_IntNestCnt > 1) ? TRUE : FALSE);
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	UW	ulPsr;

	ulPsr = ((*((UW *)p_excinf) & S1C33_PSR_MASK_IL) >> 8);
	return (ulPsr == TPS_CPULOCK_LEV) ? TRUE : FALSE;
}

/*
 *  ��O�x�N�^�e�[�u���̍\���̒�`
 */
typedef struct exc_vector_entry {
	FP exchdr;				/* ��O�n���h���̋N���Ԓn */
} EXCVE;

/*
 *  CPU��O�n���h���̐ݒ�
 */
#define	define_exc	define_inh

/*
 *  �����݃n���h���̐ݒ�
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{
	EXCVE	*excvt;

	excvt = (EXCVE *) get_ttbr();
	excvt[inhno].exchdr = inthdr;
}

/*
 *  �����݃n���h���̏o���������̐����}�N��
 */
#define INTHDR_ENTRY(inthdr)	void inthdr##_entry(void) { tpsIntPreWrap(); asm("xcall " #inthdr); tpsIntPostWrap(); }
#define	INT_ENTRY(inthdr)	inthdr##_entry

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 */
#define EXCHDR_ENTRY(exchdr)	INTHDR_ENTRY(exchdr)
#define	EXC_ENTRY(exchdr)	exchdr##_entry

/*
 *  ������/CPU��O�n���h���̏o��������
 *
 *  idle���͊��荞�܂ꂽ�X�^�b�N==stacktop�Ȃ̂ŁA
 *  idle���[�`���ɂ�reti�ŕ��A�ł���ʒu�Ɋ��荞�݃X�^�b�N��ݒ肵�Ă���
 */
Inline void
tpsIntPreWrap(void)
{
#if TPS_DAREA_CNT == 4			/* �f�[�^�G���A���ɉ����đޔ�	*/
	Asm("pushn %r11");		/* ���W�X�^����ύX����B	*/
#elif TPS_DAREA_CNT == 3
	Asm("pushn %r12");
#elif TPS_DAREA_CNT == 2
	Asm("pushn %r13");
#elif TPS_DAREA_CNT == 1
	Asm("pushn %r14");
#else
	Asm("pushn %r15");
#endif /* TPS_DAREA */

#ifdef	__c33adv
	Asm("pushs 	%sor				");
#else	/* __c33adv */
	Asm("ld.w	%r0, %ahr			");
	Asm("ld.w	%r1, %alr			");
#endif	/* __c33adv */

	Asm("ld.w	%r2, %sp			");	/* �X�^�b�N�̐؂�ւ��A		*/
	Asm("xld.w	%r3, _kernel_tps_IntNestCnt	");	/* ���荞�݃J�E���^�̍X�V�A	*/
	Asm("ld.w	%r5, [%r3]			");	/* ���d���荞�݂̋����s��	*/
	Asm("xld.w	%%r4, %0 - 8  " : : "g"(STACKTOP));
	Asm("cmp	%r5, 0x00			");
	Asm("jrne	0f				");
	Asm("ld.w	%sp, %r4			");
	Asm("0:						");
	Asm("add	%r5, 1				");
	Asm("ld.w	[%r3], %r5			");
	Asm("ld.w	%r4, %psr			");
	Asm("or		%r4, 0x10			");
	Asm("ld.w	%psr, %r4			");
	Asm("ld.w	%r6, %r2			");

#ifdef	__c33adv						/* pushs���߂ɂ��X�^�b�N�g�p	*/
	Asm("add	%r6, 24");				/* �T�C�Y�����Z����		*/
#endif	/* __c33adv */
	
#if TPS_DAREA_CNT == 4
	Asm("add	%r6, 48");
#elif TPS_DAREA_CNT == 3
	Asm("add	%r6, 52");
#elif TPS_DAREA_CNT == 2
	Asm("add	%r6, 56");
#elif TPS_DAREA_CNT == 1
	Asm("add	%r6, 60");
#else
	Asm("ext	0x0001");
	Asm("add	%r6, 0x00");
#endif /* TPS_DAREA */
}

Inline void
tpsIntPostWrap(void)
{
	Asm("ld.w	%r4, %psr		");	/* ���荞�݂��f�B�Z�[�u������	*/
	Asm("xand	%r4, 0xfffff0ff		");
	Asm("xld.w	%%r5, %0"
		: : "g"(TPS_CPULOCK_LEV << 8));
	Asm("or		%r4, %r5		");
	Asm("ld.w	%psr, %r4		");

	Asm("ld.w	%r4, [%r3]		");	/* tps_IntNestCnt���X�V����	*/
	Asm("sub	%r4, 1			");
	Asm("ld.w	[%r3], %r4		");

	Asm("ld.w	%sp, %r2		");	/* �X�^�b�N�̈�𕜌�����	*/

	Asm("cmp	%r4, 0x00		");
	Asm("xjrne	0f			");
	Asm("xld.w	%r3, _kernel_reqflg	");
	Asm("ld.w	%r3, [%r3]		");
	Asm("cmp	%r3, 1			");	/* tps_IntNestCnt== 0�Ńf�B�X	  */
	Asm("xjreq	_kernel_ret_int		");	/* �p�b�`���������Ă���΃W�����v */
	Asm("0:					");	/* ����				  */

#ifdef	__c33adv					/* �ޔ��������ꃌ�W�X�^�𕜌����� */
	Asm("pops	%sor			");
#else	/* __c33adv */
	Asm("ld.w	%alr, %r1		");
	Asm("ld.w	%ahr, %r0		");
#endif	/* __c33adv */

#if TPS_DAREA_CNT == 4
	Asm("popn %r11");
#elif TPS_DAREA_CNT == 3
	Asm("popn %r12");
#elif TPS_DAREA_CNT == 2
	Asm("popn %r13");
#elif TPS_DAREA_CNT == 1
	Asm("popn %r14");
#else
	Asm("popn %r15");
#endif /* TPS_DAREA */

	Asm("reti");
}

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
