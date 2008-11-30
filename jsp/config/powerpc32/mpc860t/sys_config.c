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
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iMPC860T TB6102S�p�j
 *�@�@�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@�@�@C����֐��̎���
 */

#include "jsp_kernel.h"
#include <mpc860_sil.h>

/*
 *  �����ݔ������ɃX�^�b�N�ɑҔ����ꂽ��Ԃ�IPM�̃f�[�^�\��
 *    4�o�C�g���E���ێ����邽�߁A�_�~�[�̈悪����
 */
typedef struct ipm_stack {
	UH	ipm;
	UH	dummy;
} IPM_STACK;

/*
 *  �����݃}�X�N�p�[���x�N�^�e�[�u��
 *	ipm_table���̂�$(CPU)�Ƃ̃C���^�[�t�F�[�X�Ɋ܂܂�Ȃ�
 *�@�@�@�idefine_ipm�ɂ��A�B������Ă���j
 */
IPM ipm_table[TMAX_EXCNO];

/*
 *  SIL���g�p�����Ƃ��̃��O�@�\
 */
#ifdef SIL_DEBUG

BOOL sil_debug_on = FALSE;
char sil_buffer[SIL_BUFFER_SIZE];
int sil_pos = -1;
UW sil_log_id = 0;

#endif	/* SIL_DEBUG */

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
    	INHNO j;
	
	/*
	 *  �ʐM�v���Z�b�TCPM�̏�����
	 */
	
	/*  ���Z�b�g�E�R�}���h�̔��s  */
    	mpc860_wrh_mem(CPCR, CPCR_RST | CPCR_FLG);
	
	/*
	 *  �����݃R���g���[���̏�����
	 *�@�@IRL�FSIU�ɑ΂��銄���݃��x��
	 *�@�@IEN=1�FCPM�����݃C�l�[�u��
	 */
	mpc860_wrw_mem(CICR, CICR_IRL0 | CICR_IEN);

	/*  IPM�̏������FCPM�����݂̋���  */
	mpc860_wrh_mem(SIMASK, ENABLE_CPM);


	/*
	 *  �����f�[�^�̏�����
	 */

    	/* IPM�e�[�u���̏����� */
    	for( j = 0; j < TMAX_EXCNO; j++ ) {
        	ipm_table[j] = DEFAULT_IPM;
    	}
    	
    	/*  CPM�����݂�IPM��ݒ�  */
    	ipm_table[INHNO_CPM] = IPM_CPM;
	
	/*
	 *  �v���Z�b�T���ʂ̂��߂̕ϐ��̏�����
	 */
	/*  ������  */
}

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit()
{
	tb6102s_exit();
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		tb6102s_putc('\r');
	}
	tb6102s_putc(c);
}

/*
 * �o�^����Ă��Ȃ������ݔ������̃��O�o��
 * �@�@�}�N��PROC_ICU�̒��ŌĂяo�����
 * �@�@�֐���������̌^�̓v���Z�b�T���Ɍ��߂ėǂ�
 *
 *     MPC860�ł͊����݃R���g���[�����J�X�P�[�h�ڑ�����Ă��邽�߁A
 *�@�@ �e�����݃R���g���[���ɐ�p�̊֐���p�ӂ����B
 *
 */

/*  SIU�����݁iCPM�����݈ȊO�j  */
void no_reg_SIU_interrupt(INHNO intno, UW *sp)
{
    syslog(LOG_EMERG, "SIU interrupt error occurs.");
    syslog(LOG_EMERG, "Interrupt No.=%d", intno);
    syslog(LOG_EMERG, "IPM=0x%04x", ((IPM_STACK *)sp)->ipm);

    /*  
     *  �X�^�b�N��̃f�[�^�̕\��
     *    �����݃}�X�N���X�^�b�N�ɐς�ł���̂�
     *�@  ���̕��A�X�L�b�v����
     */
    ++sp;
    syslog_data_on_stack((EXCSTACK *)sp);
    
    while(1);
}

/*  CPM������  */
void no_reg_CPM_interrupt(INHNO intno, UW *sp)
{
    syslog(LOG_EMERG, "CPM interrupt error occurs.");
    syslog(LOG_EMERG, "Interrupt No.=%d(total %d)", 
           intno, intno + TMAX_SIU_INTNO);
    syslog(LOG_EMERG, "IPM=0x%04x", ((IPM_STACK *)sp)->ipm);

    /*  
     *  �X�^�b�N��̃f�[�^�̕\��
     *    �����݃}�X�N���X�^�b�N�ɐς�ł���̂�
     *�@  ���̕��A�X�L�b�v����
     */
    ++sp;
    syslog_data_on_stack((EXCSTACK *)sp);
    
    while(1);
}

/*  end of file  */
