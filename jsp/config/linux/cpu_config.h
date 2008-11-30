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
 *	�v���Z�b�T�ˑ����W���[���iLinux�p�j
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <cpu_rename.h>

#ifndef _MACRO_ONLY

/*
 *  Linux�p�W���C���N���[�h�t�@�C��
 */

#include <signal.h>
#include <setjmp.h>

/*
 *  chg_ims/get_ims ���T�|�[�g���邩�ǂ����̒�`
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

/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
	jmp_buf env;		/* CPU�R���e�L�X�g */
} CTXB;

/*
 *   CPU��O�n���h��
 */

#define EXCHNO_ZDIV  SIGFPE

/*
 *  �V�X�e����ԎQ��
 */


Inline int
current_stack()
{
    struct sigaltstack      ss;

    sigaltstack(((void *)0), &ss);
    return(ss.ss_flags & SS_ONSTACK);
}


Inline BOOL
sense_context()
{
	return(current_stack());
}

Inline BOOL
sense_lock()
{
    sigset_t currentSet;
    
    sigprocmask(SIG_BLOCK, ((void *)0), &currentSet);

#if defined(linux) & (defined(i386) | defined(_i386_) | defined(__i386__))
    if(currentSet.__val[0] == ~(0 | (1<<(SIGKILL-1)) | (1<<(SIGSTOP-1)))
       &&  currentSet.__val[1] == ~0 )
        return(TRUE);
    else
        return(FALSE);
#else
    
#error not supported.
    
#endif /* linux */    
}


#define t_sense_lock	sense_lock
#define i_sense_lock	sense_lock

/*
 *  CPU���b�N�Ƃ��̉����i�^�X�N�R���e�L�X�g�p�j
 *
 *  task_intmask �́Cchg_ipm ���T�|�[�g���邽�߂̕ϐ��Dchg_ipm ���T�|�[
 *  �g���Ȃ��ꍇ�ɂ́Ctask_intmask ����� 0 �ɂȂ��Ă���ƍl����΂悢�D
 */

#ifdef SUPPORT_CHG_IMS
extern IMS	task_sigmask;	/* �^�X�N�R���e�L�X�g�ł̊����݃}�X�N */
#endif /* SUPPORT_CHG_IMS */

Inline void
t_lock_cpu()
{
    sigset_t  newmask;
    
    sigfillset(&newmask);
    sigprocmask(SIG_SETMASK,&newmask,0);
}

Inline void
t_unlock_cpu()
{
#ifdef SUPPORT_CHG_IMS
	/*
	 *  t_unlock_cpu ���Ăяo�����̂� CPU���b�N��Ԃ݂̂ł��邽
	 *  �߁C�����̓r���� task_intmask ����������邱�Ƃ͂Ȃ��D
	 */
    sigprocmask(SIG_SETMASK,&task_sigmask,0);
#else /* SUPPORT_CHG_IMS */
    sigset_t  mask;
    
    sigemptyset(&mask);
    sigprocmask(SIG_SETMASK,&mask,0);
#endif /* SUPPORT_CHG_IMS */
}

/*
 *  CPU���b�N�Ƃ��̉����i��^�X�N�R���e�L�X�g�p�j
 */

extern IMS	int_sigmask;	/* ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N */

Inline void
i_lock_cpu()
{
    sigset_t  mask;
    
    sigfillset(&mask);
    sigprocmask(SIG_SETMASK,&mask,&int_sigmask);
}

Inline void
i_unlock_cpu()
{
    sigprocmask(SIG_SETMASK,&int_sigmask,0);
}

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
{
    /*
     *  SIGUSR1���u���b�N�A�X�^�b�N�؂�ւ��L��œo�^����B
     *  �D��x��t�������ꍇ�̓}�X�N����r�b�g���w�肷��
     *  �K�v������̂ł��̕��@�͎g���Ȃ��B
     */
    
    struct sigaction action;

    action.sa_handler = inthdr;
    sigemptyset(&action.sa_mask);
    sigaddset(&action.sa_mask,SIGUSR1);
    action.sa_flags = SA_ONSTACK;
    
    sigaction(inhno, &action, 0);    
}

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ肷��D
 */
Inline void
define_exc(EXCNO excno, FP exchdr)
{
    /*
     * �u���b�N����}�X�N�����A�X�^�b�N�؂�ւ��L��œo�^����B
     */
    struct sigaction action;

    action.sa_handler = exchdr;
    sigemptyset(&action.sa_mask);
    sigaddset(&action.sa_mask,SIGUSR1);    
    action.sa_flags = SA_ONSTACK;    
    sigaction(excno, &action, 0);
}

/*
 *  �����݃n���h���^CPU��O�n���h���̏o��������
 */

/*
 *  �����݃n���h���̏o���������̐����}�N��
 *
 *  �V�O�i�������s����Ă�ƃV�O�i���X�^�b�N�Ɏ����I�ɐ؂�ւ��B
 *  �S�Ă̊��荞�݃n���h���̓f�B�X�p�b�`�����N������SIGUSR1���}�X�N����
 *  ���삷��B���̂���reqflg�̃`�F�b�N��V�O�i�������s����ċN�����ꂽ
 *  �n���h���Ńf�B�X�p�b�`���v������Ă�����������
 */


#define	INTHDR_ENTRY(inthdr)      \
void inthdr##_entry(void){        \
     inthdr();                           /* ���荞�݃n���h�����Ăяo�� */ \
     if(_kernel_reqflg)                  /* regflg ��TRUE�ł����      */ \
       raise(SIGUSR1);                   /* �f�B�X�p�b�`�����Ăяo��   */ \
}                                      

#define INT_ENTRY(inthdr)   inthdr##_entry


/*
 *  CPU��O�n���h���̏o���������̐����}�N��
 *
 *  �V�O�i�������s����Ă�ƃV�O�i���X�^�b�N�Ɏ����I�ɐ؂�ւ��B 
 *  �S�Ă�CPU��O�n���h���̓f�B�X�p�b�`�����N������SIGUSR1���}�X�N����
 *  ���삷��B���̂���reqflg�̃`�F�b�N��V�O�i�������s����ċN�����ꂽ
 *  �n���h���Ńf�B�X�p�b�`���v������Ă����������� 
 */
#define	EXCHDR_ENTRY(exchdr)	  \
void exchdr##_entry(VP sp){        \
     exchdr(sp);                         /* ���荞�݃n���h�����Ăяo�� */ \
     if(_kernel_reqflg)                  /* regflg ��TRUE�ł����      */ \
       raise(SIGUSR1);                   /* �f�B�X�p�b�`�����Ăяo��   */ \
}

#define EXC_ENTRY(exchdr) exchdr##_entry

/*
 *  CPU��O�̔����������̃V�X�e����Ԃ̎Q��
 */

/*
 *  CPU��O�̔����������̃f�B�X�p�b�`
 */
Inline BOOL
exc_sense_context(VP p_excinf)
{
	return((*((UH *) p_excinf) & 0x1000) == 0);
}

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
Inline BOOL
exc_sense_lock(VP p_excinf)
{
	return((*((UH *) p_excinf) & 0x0700) == 0x0700);
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







