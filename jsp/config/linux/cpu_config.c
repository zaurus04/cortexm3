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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iLinux�p�j
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
#ifdef SUPPORT_CHG_IMS
IMS     task_sigmask;
#endif /* SUPPORT_CHG_IMS */

/*
 *  ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
IMS	int_sigmask;

void
dispatch()
{
    sigset_t waitmask;
    sigemptyset(&waitmask);
    sigaddset(&waitmask,SIGUSR1);
        if (enadsp && (!runtsk || (runtsk != schedtsk
                        && _setjmp(runtsk->tskctxb.env) == 0))) {
            while (!(runtsk = schedtsk)) {
                sigsuspend(&waitmask);
            }
            _longjmp(runtsk->tskctxb.env, 1);
        }else{
            calltex();
        }
}


/*
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`
 *
 *  exit_and_dispatch �́CCPU���b�N��ԂŌĂяo���Ȃ���΂Ȃ�Ȃ��D
 */

void
exit_and_dispatch() 
{                   
    runtsk = 0;
    dispatch();
}


/*
 *  �v���Z�b�T�ˑ��̏�����
 */


extern void kernel_start();

void
cpu_initialize()
{

	/*
	 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N�̏�����
	 */
#ifdef SUPPORT_CHG_IPM
    sigemptyset(&task_sigmask);
#endif /* SUPPORT_CHG_IPM */

    /*
     *  �V�O�i���X�^�b�N���C�v���Z�X�X�^�b�N��Ɏ��D
     *  BSD�̃V�O�i���ƈقȂ�ss.ss_flags��SS_ONSTACK��
     *  ��������ł����f����Ȃ����߁A�^�X�N�Ɨ�����\��
     *  inSigStack���g�p����B
     */


    /*
     *  �f�B�X�p�b�`�p�̃V�O�i���n���h����ݒ�D
     *  ���荞�݃n���h���̏o����SIGUSR1���g�p���ČĂяo��
     *  ���Ƃɂ���B
     */
	{
            struct sigaction dis_action;
            dis_action.sa_handler = dispatch;
            dis_action.sa_flags   =  0;
            sigfillset(&dis_action.sa_mask);
            sigaction(SIGUSR1,&dis_action,((void *)0));

	}
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{
}



#ifdef SUPPORT_CHG_IMS
/*
 *   IMASK�̐ݒ�Q�Ƌ@�\
 */
SYSCALL ER
chg_ims(IMS ims)
{

    if(sense_context()){
        if(!sigismember(&ims,SIGUSR1))
            return(E_PAR);
    }else{
        if(sigismember(&ims,SIGUSR1))
            return(E_PAR);
    }
    
    
    sigprocmask(SIG_SETMASK,&ims,0);    
	return(E_OK);
}

/*
 *  �����݃}�X�N�̎Q��
 */
SYSCALL ER
get_ims(IMS *p_ims)
{
    sigprocmask(SIG_SETMASK,p_ims,0);        
	return(E_OK);
}


#endif /* SUPPORT_CHG_IMS */


/*
 * �^�X�N�N�����[�`��
 *
 */

void
activate_r()
{
    /*
     *  �V�O�i���}�X�N��ݒ肵�āC�^�X�N���N������D
     */
#ifdef SUPPORT_CHG_IMS
    sigprocmask(SIG_SETMASK,&task_sigmask,((void *)0));
#else /* SUPPORT_CHG_IMS */
    sigset_t set;
    sigemptyset(&set);
    sigprocmask(SIG_SETMASK,&set,((void *)0));
#endif /* SUPPORT_CHG_IMS */
    (*runtsk->tinib->task)(runtsk->tinib->exinf);
    
    ext_tsk();
}



