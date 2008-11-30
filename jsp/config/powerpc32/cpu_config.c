/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 * 
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iPowerPC�p�j
 *�@�@�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@�@�@C����֐��̎���
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <sil.h>


/*
 *  �����݃n���h���^�����݃}�X�N�̋[���e�[�u��
 */
FP int_table[TMAX_INTNO];


/*
 *  ��O�x�N�^�̋[���e�[�u��
 */
FP exc_table[TMAX_EXCNO];

/*
 *  �G���[���b�Z�[�W�̃f�[�^�e�[�u��
 *
 *  �C���v�������e�[�V�����ŗL�̗�O0x1000�̓J�[�l�����p�ӂ���o
 *  �����������o�R���Ȃ��̂ŁA���̃e�[�u����0x10�Ԗڂ��g�p�����
 *  ���Ƃ͂Ȃ��B
 */
static const char *(exe_list[]) = {
	"",				/*  0x0  */
	"System Reset",			/*  0x1  */
	"Machine Check",		/*  0x2  */
	"DSI",				/*  0x3  */
	"ISI",				/*  0x4  */
	"External Interrupt",		/*  0x5  */
	"Alignment",			/*  0x6  */
	"Program",			/*  0x7  */
	"Floating Point Unavailable",	/*  0x8  */
	"Decrementer",			/*  0x9  */
	"Implement Exception 0xa00",	/*  0xa  */
	"",				/*  0xb  */
	"System Call",			/*  0xc  */
	"Trace",			/*  0xd  */
	"Floating Point Assist",	/*  0xe  */
};


/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize()
{
    	INHNO i;
    	EXCNO j;

    	/* 
    	 * �����݋[���x�N�^�e�[�u��������
    	 *
    	 *�@�@0�ŏ��������Ė��o�^�����ɂ��Ă���̂ŁA
    	 *�@�@�����ݏ�����ICU�ˑ�����PROC_ICU�ł́A
    	 *�@�@���o�^�̏ꍇ�̏��������Ă�������
         */
    	for( i = 0; i < TMAX_INTNO; i++ ) {
        	define_inh( i, (FP)0 );
    	}

    	/* CPU��O�[���x�N�^�e�[�u�������� */
    	for( j = 0; j < TMAX_EXCNO; j++ ) {
        	define_exc( j, (FP)&no_reg_exception );
    	}
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{
}

#ifdef SUPPORT_CHG_IPM

/*
 *  �����݃}�X�N�̕ύX
 *
 *  PowerPC�R�A�ɂ�IPM���Ȃ��A�����݃R���g���[����IPM�݈̂�����
 *  ����_�ɒ���
 *
 *  chg_ipm ���g���� NMI�ȊO�̂��ׂĂ̊����݂��֎~�ł��邩�ǂ���
 *  �͊����݃R���g���[���Ɉˑ�����B
 *  NMI�ȊO�̂��ׂĂ̊����݂��֎~�������ꍇ�ɂ́Cloc_cpu�ɂ��CPU
 *  ���b�N��Ԃɂ���΂悢�D
 *  IPM�ɂ���Ĉꕔ�̊����݂��}�X�N����Ă��鎞�ɂ��C�^�X�N�f�B�X
 *  �p�b�`�͕ۗ�����Ȃ��DIPM�́C�^�X�N�f�B�X�p�b�`�ɂ���āC�V��
 *  �����s��ԂɂȂ����^�X�N�ֈ����p�����D���̂��߁C�^�X�N����
 *  �s���ɁC�ʂ̃^�X�N�ɂ���� IPM���ύX�����ꍇ������DJSP�J�[
 *  �l���ł́CIPM�̕ύX�̓^�X�N��O�������[�`���ɂ���Ă��N���邪�C
 *  ����ɂ���Ĉ���������Ȃ�󋵂͏��Ȃ��Ǝv����DIPM �̒l
 *  �ɂ���ă^�X�N�f�B�X�p�b�`���֎~�������ꍇ�ɂ́Cdis_dsp�𕹗p
 *  ����΂悢�D
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);	/*  ICU�ˑ�  */
	CHECK_TSKCTX_UNL();
	CHECK_IPM(ipm);		/*  ICU�ˑ�  */

	t_lock_cpu();
	CHG_IPM(ipm);		/*  ICU�ˑ�  */
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_CHG_IPM_LEAVE(ercd);
	return(ercd);
}

/*
 *  �����݃}�X�N�̎Q��
 */
SYSCALL ER
get_ipm(IPM *p_ipm)
{
	ER	ercd;

	LOG_GET_IPM_ENTER(p_ipm);		/*  ICU�ˑ�  */
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	GET_IPM(p_ipm);				/*  ICU�ˑ�  */
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_GET_IPM_LEAVE(ercd, *p_ipm);	/*  ICU�ˑ�  */
	return(ercd);
}

#endif /* SUPPORT_CHG_IPM */


/*  CPU��O�^�����ݔ������̃X�^�b�N��̃f�[�^�\��  */
void syslog_data_on_stack(EXCSTACK *sp)
{
    syslog(LOG_EMERG, "PC = 0x%08x SR = 0x%08x",
    			sp->srr0, sp->srr1);

    syslog(LOG_EMERG, "r0 = 0x%08x ", sp->r0);
    syslog(LOG_EMERG, "r3 = 0x%08x r4 = 0x%08x r5 = 0x%08x",
    			sp->r3, sp->r4, sp->r5);
    syslog(LOG_EMERG, "r6 = 0x%08x r7 = 0x%08x r8 = 0x%08x",
    			sp->r6, sp->r7, sp->r8);
    syslog(LOG_EMERG, "r9 = 0x%08x r10 = 0x%08x r11 = 0x%08x",
    			sp->r9, sp->r10, sp->r11);
    syslog(LOG_EMERG, "r12 = 0x%08x ", sp->r12);


    syslog(LOG_EMERG, "LR = 0x%08x CTR = 0x%08x",
    			sp->lr, sp->ctr );
    syslog(LOG_EMERG, "CR = 0x%08x XER = 0x%08x",
    			sp->cr, sp->xer );
}


/*
 * �o�^����Ă��Ȃ���O����������ƌĂяo�����
 */

void no_reg_exception(EXCSTACK *sp)
{
    syslog(LOG_EMERG, "Exception error occurs.");
    syslog(LOG_EMERG, " [0x%02x]: %s", 
    	   sp->exc_no, exe_list[sp->exc_no]);

    /*  �X�^�b�N��̃f�[�^�̕\��  */
    syslog_data_on_stack(sp);

    while(1);
}


/*
 *  �������u���b�N���색�C�u����
 *	(ItIs����̗��p)
 *
 *  �֐��̎d�l�́CANSI C ���C�u�����̎d�l�Ɠ����D�W�����C�u�����̂��̂�
 *  �g���������������ǂ��\��������D
 *
 */
VP
_dummy_memcpy(VP dest, VP src, UINT len)
{
	VB *d = (VB *)dest;
	VB *s = (VB *)src;

	while (len-- > 0) {
		*d++ = *s++;
	}
	return(dest);
}

/*  end of file  */
