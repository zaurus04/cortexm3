/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: cpu_config.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


/*
 *	�v���Z�b�T�ˑ����W���[���iWindows�p�j
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  Windows-HAL�Ǝ��̃C���N���[�h�t�@�C��
 */


/*
 *  Windows-HAL�Ǝ��̒�`
 */

#define FPU_CONTEXTSIZE 108     /* ���������_���j�b�g���ޔ�����R���e�L�X�g�̑傫�� */

/*
 *  chg_ims/ref_ims ���T�|�[�g���邩�ǂ����̒�`
 */
#define	SUPPORT_CHG_IMS

/*
 *  TCB �֘A�̒�`
 *
 *  cpu_context.h �ɓ��������G���K���g�����C�Q�Ƃ̈ˑ����̊֌W�ŁC
 *  cpu_context.h �ɂ͓�����Ȃ��D
 */

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 */
#define	TBIT_TCB_PRIORITY	8	/* priority �t�B�[���h�̃r�b�g�� */
#define	TBIT_TCB_TSTAT		8	/* tstat �t�B�[���h�̃r�b�g�� */


#ifndef _MACRO_ONLY

#include <s_services.h>

/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	HANDLE	        ThreadHandle;		//�^�X�N�Ɋ��蓖�Ă�ꂽ�X���b�h�̃n���h��
	DWORD		    ThreadID;			//�^�X�N�Ɋ��蓖�Ă�ꂽ�X���b�h��ID
	unsigned int    InterruptLevel;		//���̃^�X�N�������Ă���Ƃ��̊����݃}�X�N���x��
} CTXB;

/*
 * CPU��ԃt���O
 */
#define CPU_STAT_LOCK			0x01		//CPU���b�N��Ԃł�
#define CPU_STAT_EXC			0x02		//��O�������ł�
#define CPU_STAT_DOUBLEFAULT	0x04		//�_�u���t�H���g���N�����Ă܂�

extern volatile char CPUStatus;

/*
 *   CPU��O�n���h��
 */

/*#define EXCHNO_ZDIV  EXCEPTION_INT_DIVIDE_BY_ZERO */

/*
 *  �V�X�e����ԎQ��
 */

Inline BOOL
sense_context()
{
		/* �����ݑS���łȂ���Δ�^�X�N�R���e�L�X�g�ł� */
	return (CurrentInterruptLevel != 0) ? TRUE : FALSE;
}

Inline BOOL
sense_lock()
{
		/* ��O������ or ���b�N��ԃt���O�������Ă���� CPU���b�N��Ԃł� */
	return (CPUStatus & (CPU_STAT_LOCK|CPU_STAT_EXC)) != 0 ? TRUE : FALSE;
}

#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *
 *  task_intmask �́Cchg_ipm ���T�|�[�g���邽�߂̕ϐ��Dchg_ipm ���T�|�[
 *  �g���Ȃ��ꍇ�ɂ́Ctask_intmask ����� 0 �ɂȂ��Ă���ƍl����΂悢�D
 */

#include "debugout.h"
#include "device.h"

unsigned long task_intmask;

Inline void
i_lock_cpu()
{   dis_int(0);   }

Inline void
i_unlock_cpu()
{	ena_int(0);   }

#define t_lock_cpu	i_lock_cpu
#define t_unlock_cpu	i_unlock_cpu

/*
 *  �^�X�N�f�B�X�p�b�`��
 */

/*
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`
 *
 *  dispatch �́C�^�X�N�R���e�L�X�g����Ăяo���ꂽ�T�[�r�X�R�[������
 *  ���ŁCCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */
extern void	dispatch();
extern void idispatch();

/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`
 *
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */

extern void    exit_and_dispatch(void);

/*
 *  �����݃n���h���^CPU��O�n���h���̐ݒ�
 */


/*
 *  �����݃n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */

Inline void
define_inh(INHNO inhno, FP inthdr)
{	def_int((unsigned int)inhno,(void *)inthdr);   }

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ肷��D
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{	def_exc( (DWORD)excno, (void *)exchdr);   }

/*
 *  �����݃n���h���^CPU��O�n���h���̏o��������
 */

/*
 *  �����݃n���h���̏o���������̐����}�N��
 *
 *  �S�Ă̊��荞�݃n���h���̓f�B�X�p�b�`�����N������SIGUSR1���}�X�N����
 *  ���삷��B
 *  reqflg ���`�F�b�N����O�Ɋ����݂��֎~���Ȃ��ƁCreqflg ���`�F�b�N��
 *  �ɋN�����ꂽ�����݃n���h�����Ńf�B�X�p�b�`���v�����ꂽ�ꍇ�ɁC�f�B
 *  �X�p�b�`����Ȃ��D
 */

	/* Windows-HAL�ɂ����Ă��̏����͊����݃G�~�����[�^�Ɉ�C���Ă��� */

#define INT_ENTRY(hdr) hdr
#define INTHDR_ENTRY(inthdr) extern void inthdr(void)

/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 *  CPU��O�n���h���́C��^�X�N�R���e�L�X�g�Ŏ��s����D���̂��߁CCPU��
 *  �O�n���h�����Ăяo���O�Ɋ����݃��[�h�Ɉڍs���C���^�[�����Ă������
 *  ���̃��[�h�ɖ߂��D���̃��[�h�ɖ߂����߂ɁC�����݃��[�h�Ɉڍs����O
 *  �� SR �������݃X�^�b�N��ɕۑ�����DCPU��O���^�X�N�R���e�L�X�g��
 *  �������Creqflg �� TRUE �ɂȂ������ɁCret_exc �֕��򂷂�D
 *  reqflg ���`�F�b�N����O�Ɋ����݂��֎~���Ȃ��ƁCreqflg ���`�F�b�N��
 *  �ɋN�����ꂽ�����݃n���h�����Ńf�B�X�p�b�`���v�����ꂽ�ꍇ�ɁC�f�B
 *  �X�p�b�`����Ȃ��D
 */

#define EXC_ENTRY(hdr) hdr
#define EXCHDR_ENTRY(inthdr) extern void inthdr(void)

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃f�B�X�p�b�`
 *
 *   WindowsHAL�͐�p�t���O�������Ă����ŁA�����ݑO�̏��͂��̂܂�
 *   �i�[����Ă���B
 */
#define exc_sense_context sense_context

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
#define exc_sense_lock sense_lock

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void	cpu_terminate(void);

/*
 *  atexit�œo�^���ꂽ�֐��̓Ǐo�� (Windows�͉������Ȃ� -> CRT�ɔC����)
 */
extern void	call_atexit(void);

/*
 *   Windows Dedicated Routines 
 */
extern LONG WINAPI HALExceptionHandler( EXCEPTION_POINTERS * exc );

/*
 *   �v���I�Ȏ��s�ɑ΂���Ώ����[�`��
 */
extern void FatalAssertion(int exp, LPCSTR format, ... );


/*
 *   ���O�̏o�͐��䃋�[�`��
 */
extern void set_logcontrol(BOOL enable);

/*
 *   �J�[�l���f�o�b�O�pprintf
 */

#ifdef KERNEL_DEBUG_MODE
#  define kprintf(x) _kernel_debugprintf x
#else
#  define kprintf(x)
#endif

extern void _kernel_debugprintf(const char * format, ... );

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
