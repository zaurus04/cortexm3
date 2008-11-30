/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2008 by TOPPERS/JSP for CORTEX-M3 project
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
 *  @(#) $Id: cpu_config.h,v 1.19 2008/08/02 07:36:14 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iCORTEX-M3�p�j
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
 * CORTEX-M3�ڐA���́u���ߑ��v�B�R���p�C���G���[���Ԃ����߂�
 * �֋X��A��ɂ����֐��̒���CM3NI�Ə����Ă����B�ȉ���#define��`��
 * �R�����g�A�E�g����ƁA�ڐA���������Ă��Ȃ��֐���􂢏o����B
 * 
 * CORTEX-M3 Not Implemented
 */
#define CM3NI
 
/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 */
#ifndef _MACRO_ONLY
#include <cpu_insn.h>
#endif /* _MACRO_ONLY */


/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY
/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	VP	sp;		/* �X�^�b�N�|�C���^ */
	FP	pc;		/* �v���O�����J�E���^ */
} CTXB;



/*
 *  �V�X�e����ԎQ��
 * 
 *  ��^�X�N�E�R���e�L�X�g�Ȃ�TRUE��Ԃ��BTOPPERS/JSP for CORTEX-M3�ł́A
 *  �^�X�N�E�R���e�L�X�g��Thread���[�h�Ɋ��蓖�ĂĂ��邽�߁Aipsr��0�Ȃ�^�X�N
 *  �R���e�L�X�g�A����ȊO�͔�^�X�N�E�R���e�L�X�g�Ƃ�����B���̊֐��́Adispatch()��
 *  ���ŌĂԂƐ��m�ȏ���Ԃ��Ȃ����Adispatch()�͂�����Ă΂Ȃ��̂Ŗ��Ȃ��B
 * 
 * MRS Rx, IPSR ���߂�IPSR�̒l�����o���BIPSR�͉���9bit�Ɏ��s���x������
 * �����Ă���̂ŁA���������}�X�N�Ŏ��o���Đ^�U����ɂ����B
 */

Inline BOOL
sense_context()
{
	unsigned int ipsr_value;
	
	Asm( "mrs %0,ipsr" : "=r"(ipsr_value) );
	return(ipsr_value & 0x1FF);
}

/*
 *  ���b�N��ԎQ��
 * 
 * CPU���b�N��ԂȂ�TRUE��Ԃ��BTOPPERS/JSP for CORTEX-M3�ł́A
 * �S���荞�݋֎~�������ă��b�N��ԂƂ���B���̂��߁APRIMASK��bit1��
 * ���b�N��Ԃ𔽉f����B
 * 
 * MRS Rx, PRIMASK ���߂�PRIMASK�̒l�����o���BPRIMASK��LSB��
 * ���荞�݋֎~���������Ă���A1�Ȃ�֎~�ł���B���������}�X�N�Ŏ��o����
 * �^�U����ɂ����B
 */

Inline BOOL
sense_lock()
{
	unsigned int primask_value;
	
	Asm( "mrs %0,primask" : "=r"(primask_value) );
	return(primask_value & 0x01);
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 * CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *
 * CORTEX-M3�łł́ACPU���b�N��S���荞�݋֎~�ōs���B���̂��߁A
 * CPSID I���߂�CPU���b�N�ACPSIE I���߂ŃA�����b�N�ł���B����
 * ���߂̓R���e�L�X�g�ɂ�����炸�g����B
 */


Inline void
t_lock_cpu()
{
	Asm( "cpsid i" );
}

Inline void
t_unlock_cpu()
{
	Asm( "cpsie i" );
}

/*
 *  CPU���b�N�Ƃ��̉����i��^�X�N�R���e�L�X�g�p�j
 */

#define i_lock_cpu t_lock_cpu
#define i_unlock_cpu t_unlock_cpu

/*
 *  �^�X�N�f�B�X�p�b�`��
 */

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�icpu_support.S�j
 *
 *  dispatch �́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[������
 *  ���ŁCCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	dispatch(void);

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.S�j
 *
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	exit_and_dispatch(void);

/*
 *  �����݃n���h���^CPU��O�n���h���̐ݒ�
 */

/*
 *  ��O�x�N�^�e�[�u���̍\���̒�`
 */
typedef struct exc_vector_entry {
	FP	exchdr;			/* ��O�n���h���̋N���Ԓn */
} EXCVE;

extern EXCVE exception_vector[];

/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
Inline void
define_inh(INHNO inhno, FP inthdr)
{

	exception_vector[inhno].exchdr = inthdr;
}

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ肷��D
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
	exception_vector[excno].exchdr = exchdr;
}

/*
 *  �����݃n���h���^CPU��O�n���h���̏o��������
 */

/*
 *  �����݃n���h���̏o���������̐����}�N��
 *
 */

#define	INTHDR_ENTRY(inthdr)		\
extern void inthdr##_entry(void);	\
asm(".text				\n" \
#inthdr "_entry:			\n" \
"	push {lr} \n"				/* �߂�Ԓn��ۑ� */\
"	ldr r0,=" #inthdr "+1 \n"		/* �n���h���̔Ԓn */\
"	blx r0 \n"					/* �n���h�����Ăяo�� */\
"	pop {lr} \n"				/* �߂�Ԓn�𕜋A */\
"	and r0,lr,#0x0F \n"			/* EXC_RETURN�̉���4bit�����o�� */\
"	cmp r0,#0x0D \n"			/* LSB 4bit�� 0b1101�Ȃ�΁A��ԊO���̊��荞�� */\
"   beq.w _kernel_ret_int \n"	/* ��ԊO���Ȃ�o������ */\
"	bx lr " );					/* ���^�[�� */

#define	INT_ENTRY(inthdr)	inthdr##_entry

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 * CORTEX-M3�łł͎������Ȃ�
 */

#define	EXCHDR_ENTRY(exchdr)
#define	EXC_ENTRY(exchdr)	exchdr##_entry

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 *  CORTEX-M3�łł͎������Ȃ��B�Ԃ��̂͂ł���߂̒l�ł���B
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return(0);
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 *  CORTEX-M3�łł͎������Ȃ��B�Ԃ��̂͂ł���߂̒l�ł���B
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return(0);
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
#endif /* _CPU_CONFIG_H_ */
