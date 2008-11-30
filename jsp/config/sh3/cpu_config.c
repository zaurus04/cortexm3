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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  �v���Z�b�T�ˑ����W���[���iSH3/4�p�j
 */
#include <s_services.h>
#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
#ifdef SUPPORT_CHG_IPM
UW	task_intmask;
#endif /* SUPPORT_CHG_IPM */


/*
 *  ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
UW	int_intmask;


/*
 * ���荞�݃n���h��/�D��x�̋^���e�[�u��
 */
FP  int_table[(MAX_INTIVT>>5) + 1];
VW  int_plevel_table[(MAX_INTIVT>>5) + 1];


/*
 * CPU��O�n���h���̋^���e�[�u��
 */
FP	exc_table[(0x1E0 >> 5) + 1];


/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize()
{
    int i;
    
    /*
     *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N�̏�����
     */
#ifdef SUPPORT_CHG_IPM
    task_intmask = 0x0000;    
#endif /* SUPPORT_CHG_IPM */
    
    /*
     * int_table[],int_plevel_table[]�̏�����
     * ���o�^�̊����ݔ�������cpu_interrup()���Ăяo�����悤��
     * no_reg_interrup()��o�^����
     * �f�B�t�H���g��int_plevel_table[]�̊����ݗD��x��MAX_IPM - 1
     * �Ƃ���D
     */
    for(i = 0; i < ((MAX_INTIVT>>5) + 1); i++){
        int_table[i] = no_reg_interrupt;
        int_plevel_table[i] = 0x40000000 | (MAX_IPM - 1) << 4;
    }
    
#ifndef GDB_STUB
    /*
     * ���荞�݃R���g���[���̏����� 
     */
#if defined(SH7750)
    sil_wrh_mem((VP)ICR, 0x0000);
    sil_wrh_mem((VP)IPRA, 0x0000);
    sil_wrh_mem((VP)IPRB, 0x0000);
    sil_wrh_mem((VP)IPRC, 0x0000);
#else /* SH7708 || SH7709 || SH7709A || SH7729R || SH7727 */   
    sil_wrh_mem((VP)ICR0, 0x0000);
    sil_wrh_mem((VP)IPRA, 0x0000);     
    sil_wrh_mem((VP)IPRB, 0x0000);
#if defined(SH7709) || defined(SH7709A) || defined(SH7729R) || defined(SH7727) 
    sil_wrh_mem((VP)ICR1, 0x4000);
    sil_wrh_mem((VP)ICR2, 0x0000);     
    sil_wrh_mem((VP)PINTER, 0x0000);
    sil_wrh_mem((VP)IPRC, 0x0000);
    sil_wrh_mem((VP)IPRD, 0x0000);
    sil_wrh_mem((VP)IPRE, 0x0000);
    sil_wrb_mem((VP)IRR0, 0x0000);   
    sil_wrb_mem((VP)IRR1, 0x0000);
    sil_wrb_mem((VP)IRR2, 0x0000);
#endif /* SH7709 || SH7709A  */   
#endif /* SH7750 */
    
    /*
     *  �x�N�^�x�[�X���W�X�^�[�̏�����
     */
    set_vbr(BASE_VBR);
    
#endif /* GDB_STUB */
}


/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{
}


/*
 * Trapa�ȊO�̗�O�œo�^����Ă��Ȃ���O����������ƌĂяo�����
 */
void
cpu_expevt(VW expevt,VW spc,VW ssr,VW pr)
{
    syslog(LOG_EMERG, "Unregistered Expevt error occurs.");
    syslog(LOG_EMERG, "Expevt = %08x SPC = %08x SR = %08x PR=%08X",
           expevt,spc,ssr,pr);
    while(1);
}

/*
 * ���o�^�̊����݂����������ꍇ�ɌĂяo�����
 */
void
cpu_interrupt(VW intevt, VW intevt2,VW spc,VW ssr)
{
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
#if defined(SH7709) || defined(SH7709A) || defined(SH7729R) || defined(SH7727) 
    syslog(LOG_EMERG, "INTEVT = %08x INTEVT2 = %08x SPC = %08x SR = %08x ",
           intevt,intevt2,spc,ssr);
#else /* SH7708 || SH7750 */   
    syslog(LOG_EMERG, "INTEVT = %08x  SPC = %08x SR = %08x ",intevt,spc,ssr);
#endif    
    while(1);
}



#ifdef SUPPORT_CHG_IPM

/*
 *  �����݃}�X�N�̕ύX
 *
 *  chg_ipm ���g���� IPM �� MAX_IPM �iNMI �X�^�u�����[�g�u���[�N �ȊO
 *  �̂��ׂĂ̊����݂��֎~�j�ȏ�ɕύX���邱�Ƃ͂ł��Ȃ��DNMI �X�^�u��
 *  ���[�g�u���[�N�ȊO�̂��ׂĂ̊����݂��֎~�������ꍇ�ɂ́Aloc_cpu ��
 *  ���CPU���b�N��Ԃɂ���΂悢�DIPM �� 0 �ȊO�̎��ɂ��C�^�X�N�f�B�X
 *  �p�b�`�͕ۗ�����Ȃ��DIPM �́C�^�X�N�f�B�X�p�b�`�ɂ���āC�V������
 *  �s��ԂɂȂ����^�X�N�ֈ����p�����D���̂��߁C�^�X�N�����s���ɁC��
 *  �̃^�X�N�ɂ���� IPM ���ύX�����ꍇ������DJSP�J�[�l���ł́CIPM
 *  �̕ύX�̓^�X�N��O�������[�`���ɂ���Ă��N����̂ŁC����ɂ���Ĉ�
 *  ��������Ȃ�󋵂͏��Ȃ��Ǝv����DIPM �̒l�ɂ���ă^�X�N�f�B�X
 *  �p�b�`���֎~�������ꍇ�ɂ́Cdis_dsp �𕹗p����΂悢�D
 */

SYSCALL ER
chg_ipm(IPM ipm)
{
    ER  ercd;
    
    LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_PAR(0 <= ipm && ipm <= MAX_IPM - 1);

	t_lock_cpu();
	task_intmask = (ipm << 4);
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
    ER  ercd;

    LOG_GET_IPM_ENTER(p_ipm);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_ipm = (task_intmask >> 4);
    ercd = E_OK;
	t_unlock_cpu();

  exit:
    LOG_GET_IPM_LEAVE(ercd, *p_ipm);
    return(ercd);
}

#endif /* SUPPORT_CHG_IPM */
