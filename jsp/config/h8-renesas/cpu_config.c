/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Katsuhiro Amano
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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  �v���Z�b�T�ˑ����W���[���iH8�p�j
 *�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@C����֐��̎���
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "sil.h"
#include <hw_serial.h>  /*  SCI_putchar_pol()  */

#ifdef SUPPORT_CHG_IPM
/*
 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
volatile UB      task_intmask = 0;
#endif /* SUPPORT_CHG_IPM */

/*
 *  ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
volatile UB      int_intmask = 0;

/*
 *  �����݃l�X�g�J�E���^
 */
volatile UB      intnest = 0;

/*
 *  CPU���b�N��Ԃ�\���t���O
 */
volatile BOOL    iscpulocked = TRUE;

/*
 *  �^�C�}�̃v���C�I���e�B���x���ݒ�p�̃f�[�^
 *      �{����hw_timer.h�ɋL�q����ׂ������A���������
 *      hw_timer.h���C���N���[�h�����t�@�C���ł��ׂĎ��̉������
 *�@�@�@�������̈���L���Ă��܂����߁A���̂͂����ɋL�q����B
 */
const IRC TIMER_IRC = {(UB*)SYSTEM_TIMER_IPR,
                        SYSTEM_TIMER_IP_BIT,
                        SYSTEM_TIMER_IPM
};

/*
 *  SYSCR�̏����l
 *      $CPU�f�B���N�g���Œ�`������e
 *      �@�r�b�g7 SSBY=0�Fsleep���߂ŃX���[�v���[�h�ֈڍs
 *      �@�r�b�g3 UE=1�FCCR.UI�������݃}�X�N�r�b�g�Ƃ��ė��p
 *      �@�r�b�g1 1�F���U�[�u�r�b�g
 *      �@�r�b�g0 RAME=1�F����RAM�L��
 *      $SYS�f�B���N�g����SYSCR_SYS�Ƃ��Ē�`������e
 *      �@�r�b�g6-4 STS�F�X�^���o�C�E�^�C�}�E�Z���N�g
 *      �@�r�b�g2 NMIEG�FNMI�G�b�W
 */
#define SYSCR_INI	(H8SYSCR_UE | BIT1 | H8SYSCR_RAME | SYSCR_SYS)

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize(void)
{
        /*
         *  �ȉ��̂R�̓X�^�[�g�A�b�v���[�`���ŏ��������ς�ł���B
         *  �@�@�E�����݃l�X�g�J�E���^ intnest
         *  �@�@�E��^�X�N�R���e�L�X�g�̊����݃}�X�N int_intmask
         *  �@�@�E�^�X�N�R���e�L�X�g�̊����݃}�X�N task_intmask
         *  �@�@�@�@�ichg_ipm���T�|�[�g����ꍇ�j
         */

        /*
         *  SYSCR�̐ݒ�
         */
        sil_wrb_mem((VP)H8SYSCR, (VB)SYSCR_INI);
         
        /*  ������  */
        /*  sleep���߂őJ�ڂ���ȓd�͏�Ԃ̐ݒ�  */

        /*  �჌�x���o�͗p�V���A���|�[�g�̏�����  */
        SCI_initialize(SCI_LOW_PORTID);
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate(void)
{
}

#ifdef SUPPORT_CHG_IPM
/*
 *  �����݃}�X�N�̕ύX
 *
 *�@IPM�ɐݒ�ł���l�Ƃ���IPM_LEVEL0�AIPM_LEVEL1���}�N����`����Ă���B
 *
 *
 *�@IPM_LEVEL0�F���x���O�@���ׂĂ̊����݂��󂯕t����
 *�@IPM_LEVEL1�F���x���P�@NMI����уv���C�I���e�B���x���P�̊����݂݂̂�
 *�@�@�@�@�@�@�@�@�@�@�@�@�󂯕t����
 *
 *  chg_ipm ���g���� IPM �����x��2�iNMI �ȊO�̂��ׂĂ̊����݂��֎~�j��
 *  �ύX���邱�Ƃ͂ł��Ȃ��DNMI �ȊO�̂��ׂĂ̊����݂��֎~�������ꍇ
 *  �ɂ́Cloc_cpu �ɂ��CPU���b�N��Ԃɂ���΂悢�D
 *  IPM �� 0 �ȊO�̎��ɂ��C�^�X�N�f�B�X�p�b�`�͕ۗ�����Ȃ��DIPM �́C
 *  �^�X�N�f�B�X�p�b�`�ɂ���āC�V�������s��ԂɂȂ����^�X�N�ֈ����p��
 *  ���D���̂��߁C�^�X�N�����s���ɁC�ʂ̃^�X�N�ɂ���� IPM ���ύX��
 *  ���ꍇ������DJSP�J�[�l���ł́CIPM �̕ύX�̓^�X�N��O�������[�`
 *  ���ɂ���Ă��N����̂��C����ɂ���Ĉ���������Ȃ�󋵂͏��Ȃ���
 *  �v����D
 *�@IPM �̒l�ɂ���ă^�X�N�f�B�X�p�b�`���֎~�������ꍇ�ɂ́Cdis_dsp��
 *  ���p����΂悢�D
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
        ER      ercd = E_OK;

        LOG_CHG_IPM_ENTER(ipm);
        CHECK_TSKCTX_UNL();
        CHECK_PAR( (ipm == IPM_LEVEL0) || (ipm == IPM_LEVEL1) || (ipm == IPM_LEVEL2));

        t_lock_cpu();
        task_intmask = ipm;
        t_unlock_cpu();

    exit:
        LOG_CHG_IPM_LEAVE(ercd)
        return(ercd);
}

/*
 *  �����݃}�X�N�̎Q��
 */
SYSCALL ER
get_ipm(IPM *p_ipm)
{
        ER      ercd = E_OK;

        LOG_GET_IPM_ENTER(p_ipm);
        CHECK_TSKCTX_UNL();

        t_lock_cpu();
        *p_ipm = task_intmask;
        t_unlock_cpu();

    exit:
        LOG_GET_IPM_LEAVE(ercd, *p_ipm);
        return(ercd);
}

#endif /* SUPPORT_CHG_IPM */

/*
 * �������ԑ҂�
 * �@�@���ӎ����F
 * �@�@�@�W���ł�dlytim��UINT�^����16�r�b�g�����Ȃ��̂ŁA
 * �@�@�@UW�^�ɕύX���Ă���B
 * �@�@�@sil_dly_nse()�͓�����sil_dly_nse2()���Ăяo���B
 */
void sil_dly_nse(UINT dlytim) {
	sil_dly_nse_long((UW)dlytim);
}

/*****�ȉ��A���ʕ��Ƃ̃C���^�[�t�F�[�X�Ɋ܂܂�Ȃ�����*********/

/*
 * �o�^����Ă��Ȃ����荞�݂̃f�t�H���g����
 */

/*
 * �X�^�b�N�̐擪����e���W�X�^�̂܂ł̃I�t�Z�b�g
 * 
 * �@�X�^�b�N�\��
 *�@�@ +0:er0
 *�@�@ +4:er1
 *�@�@ +8:er2
 *�@�@+12:er3
 *�@�@+16:er4
 *�@�@+20:er5
 *�@�@+24:er6
 *�@�@+28:crr
 *�@�@+29:pc
 *�@�@+32�`:�����ݑO�Ɏg�p����Ă����X�^�b�N�̈�
 */

/*
 * �����ݔ������O�̃X�^�b�N�|�C���^�܂ł̃I�t�Z�b�g
 */
#define OFFSET_SP	32

/*
 * �o�^����Ă��Ȃ����荞�݂���������ƌĂяo�����
 */
void 
cpu_experr(EXCSTACK *sp)
{
    UW sp2, pc, ccr, tmp;
    
    sp2 = (UW)sp + OFFSET_SP;
    tmp = sp->pc;
    ccr = (tmp >> 24U) & 0xff;	/*  ���1�o�C�g  */
    pc = tmp & 0x00ffffffUL;	/*  ����3�o�C�g  */
    
	/*
	 *  %x�i�����^�j�ł�2�o�C�g�����\���ł��Ȃ��̂�
	 *  %p�i�|�C���^�^�j��p����4�o�C�g�\�����Ă���B
	 */
    syslog(LOG_EMERG, "Unexpected interrupt.");
    syslog(LOG_EMERG, "PC  = 0x%08p SP  = 0x%08p CCR  = 0x%02x",
                       (VP)pc, (VP)sp2, (INT)ccr);
    syslog(LOG_EMERG, "ER0 = 0x%08p ER1 = 0x%08p ER2 = 0x%08p ER3 = 0x%08p",
           (VP)(sp->er0), (VP)(sp->er1), (VP)(sp->er2), (VP)(sp->er3));
    syslog(LOG_EMERG, "ER4 = 0x%08p ER5 = 0x%08p ER6 = 0x%08p",
                       (VP)(sp->er4), (VP)(sp->er5), (VP)(sp->er6));
    while(1)
    	;
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���D
 */
void
cpu_putc(char c)
{
    if (c == '\n') {
        SCI_putchar_pol('\r');
    }
    SCI_putchar_pol((UB)c);
}
