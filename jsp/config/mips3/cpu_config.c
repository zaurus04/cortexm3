/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 *  �v���Z�b�T�ˑ����W���[���iMIPS3�p�j
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  �����݃n���h���^�����݃}�X�N�̋[���e�[�u��
 */
INT_TABLE int_table[ TMAX_ALL_INTNO ];

/*
 *  ��O�n���h���̋[���e�[�u��
 */
FP exc_table[ TMAX_CORE_EXCNO ];

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void cpu_initialize() {

	int i;

	/* �����݃n���h���^�����݃}�X�N�̋[���e�[�u�������� */
	for( i = 0; i < TMAX_ALL_INTNO; i++ ) {
		define_inh( i, (FP) &cpu_experr );
	}

	/* ��O�x�N�^�̋[���e�[�u�������� */
	for( i = 0; i < TMAX_CORE_EXCNO; i++ ) {
		define_exc( i, (FP) &cpu_experr );
	}

}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void cpu_terminate() {
}

/*
 *  �������ԑ҂�
 */
void sil_dly_nse(UINT dlytim) {

	/* $2 : v0, $3 : v1 */
	Asm("	move	$2, %0" :: "r"(dlytim) );
	Asm("	li	$3, %0" :: "g"(SIL_DLY_TIM1) );

	Asm("	sub	$2, $2, $3");	/* v0 -= v1 (dlytim -= SIL_DLY_TIM1) */
	Asm("	blez    $2, sil_dly_nse_2");	/* v0 <= 0 �Ȃ烊�^�[�� */

	Asm("	li      $3, %0" :: "g"(SIL_DLY_TIM2) );

	Asm("sil_dly_nse_1:");
	Asm("	sub     $2, $2, $3");	/* v0 -= v1 (dlytim -= SIL_DLY_TIM2) */
	Asm("	bgtz    $2, sil_dly_nse_1");	/* v0 > 0 �Ȃ烋�[�v */

	Asm("sil_dly_nse_2:");
}

#ifdef SUPPORT_CHG_IPM

/*
 *  �����݃}�X�N�̕ύX
 *
 *  �����݃}�X�N�́A�^�X�N�f�B�X�p�b�`�ɂ���āA�V�������s��ԂɂȂ����^�X�N��
 *  �����p�����B���̂��߁A�^�X�N�����s���ɁA�ʂ̃^�X�N�ɂ���Ċ����݃}�X�N��
 *  �ύX�����ꍇ������BJSP�J�[�l���ł́A�����݃}�X�N�̕ύX�̓^�X�N��O����
 *  ���[�`���ɂ���Ă��N���邪�A����ɂ���Ĉ���������Ȃ�󋵂͏��Ȃ��Ǝv��
 *  ���B�����݃}�X�N�̒l�ɂ���ă^�X�N�f�B�X�p�b�`���֎~�������ꍇ�ɂ́A
 *  dis_dsp �𕹗p����΂悢�B
 *  MIPS3�^�[�Q�b�g�ł́AMIPS3�R�A�̊����݃}�X�N�����łȂ��A�����݃R���g���[��
 *  �̊����݃R���g���[���������Ă���̂Œ��ӁB
 */

SYSCALL ER chg_ipm(IPM ipm) {

	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_IPM(ipm);

	t_lock_cpu();
	cpu_set_ipm( ipm.core );	/* MIPS3�R�A�̊����݃}�X�N�̐ݒ� */
	icu_set_ipm( &(ipm.icu) );	/* �O�������݃R���g���[���̊����݃}�X�N
					   �̐ݒ� */
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_CHG_IPM_LEAVE(ercd);
	return(ercd);
}

/*
 *  �����݃}�X�N�̎Q��
 */
SYSCALL ER get_ipm(IPM *p_ipm) {

	ER	ercd;

	LOG_GET_IPM_ENTER(p_ipm);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	p_ipm->core = cpu_get_ipm();	/* MIPS3�R�A�̊����݃}�X�N�Q�� */
	icu_get_ipm(&(p_ipm->icu));	/* �O�������݃R���g���[���̊����݃}�X�N
					   �̎Q�� */
	ercd = E_OK;
	t_unlock_cpu();

    exit:
	LOG_GET_IPM_LEAVE(ercd, *p_ipm);
	return(ercd);
}

#endif /* SUPPORT_CHG_IPM */

/*============================================================================*/
/*  ���ʃh�L�������g�ɂ͂Ȃ��A�Ǝ��̕���  */

/*
 * �n���h�����o�^����Ă��Ȃ������݁E��O����������ƌĂяo�����
 */
void cpu_experr( EXCSTACK *sp, UW SR, UW CR) {

    syslog_0(LOG_EMERG, "Interrupt/Exception error occurs.");

    syslog_1(LOG_EMERG, "PC(EPC;CP0_r14) = 0x%08x",
    			sp->CP0_EPC);
    syslog_2(LOG_EMERG, "SR(Status;CP0_r12) = 0x%08x CR(Cause;CP0_r13) = 0x%08x",
    			SR, CR);	/* SR�ł��Asp->CP0_Status�ł��� */
    syslog_3(LOG_EMERG, "at(r1 ) = %08x v0(r2 ) = %08x v1(r3 ) = %08x",
    			sp->at, sp->v0, sp->v1);
    syslog_4(LOG_EMERG, "a0(r4 ) = %08x a1(r5 ) = %08x a2(r6 ) = %08x a3(r7 ) = %08x",
    			sp->a0, sp->a1, sp->a2, sp->a3);
    syslog_4(LOG_EMERG, "t0(r8 ) = %08x t1(r9 ) = %08x t2(r10) = %08x t3(r11) = %08x",
    			sp->t0, sp->t1, sp->t2, sp->t3);
    syslog_4(LOG_EMERG, "t4(r12) = %08x t5(r13) = %08x t6(r14) = %08x t7(r15) = %08x",
    			sp->t4, sp->t5, sp->t6, sp->t7);
    syslog_2(LOG_EMERG, "t8(r24) = %08x t9(r25) = %08x",
    			sp->t8, sp->t9);
    syslog_2(LOG_EMERG, "HI = %08x LO = %08x",
    			sp->hi, sp->lo);
    syslog_4(LOG_EMERG, "gp(r28) = %08x sp(r29) = %08x fp(r30) = %08x ra(r31) = %08x",
    			sp->gp, sp->sp, sp->fp, sp->ra);
    while(1);
}

/*
 *  �������u���b�N���색�C�u�����i�����N�X�N���v�g���Ŏg�p�j
 *	(ItIs����̗��p)
 *
 *  �֐��̎d�l�́CANSI C ���C�u�����̎d�l�Ɠ����D�W�����C�u�����̂��̂�
 *  �g���������������ǂ��\��������D
 */
VP _dummy_memcpy(VP dest, VP src, UINT len) {

	VB	*d = dest;
	VB	*s = src;

	while (len-- > 0) {
		*d++ = *s++;
	}

	return(dest);
}
