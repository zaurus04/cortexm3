/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

/*
 *  �v���Z�b�T�ˑ����W���[��(H8S�p)
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/*
 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
#ifdef SUPPORT_CHG_IPM
IPM	task_intmask;		/* IPM -> UB�F��������8�r�b�g */
#endif /* SUPPORT_CHG_IPM */

/*
 *  ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
IPM	int_intmask;

/*
 *  �����݃l�X�g�J�E���^
 */
UW	intnest;

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void cpu_initialize() {

#ifdef SUPPORT_CHG_IPM
	/* �^�X�N�R���e�L�X�g�ł̊����݃}�X�N�̏����� */
	task_intmask = 0x00;
#endif /* SUPPORT_CHG_IPM */

	/* �����݁^CPU��O�l�X�g�J�E���^�̏����� */
	intnest = 1;

	/* �����݃��x���̏����� */
	icu_set_ilv( (VP) IPRA, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRA, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRB, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRB, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRC, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRC, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRD, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRD, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRE, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRE, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRF, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRF, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRG, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRG, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRH, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRH, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRI, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRI, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRJ, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRJ, IPR_LOW, 0 );
	icu_set_ilv( (VP) IPRK, IPR_UPR, 0 );
	icu_set_ilv( (VP) IPRK, IPR_LOW, 0 );
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
	/* er0 = dlytim */
	Asm("		sub.l	%0, er0" :: "g"(SIL_DLY_TIM1) );
	Asm("		ble	sil_dly_nse_2");
				/* dlytim < SIL_DLY_TIM1 �Ȃ烋�[�v�I�� */
	Asm("	sil_dly_nse_1:");
	Asm("		sub.l	%0, er0" :: "g"(SIL_DLY_TIM2) );
	Asm("		bgt	sil_dly_nse_1");
				/* dlytim > SIL_DLY_TIM2 �Ȃ烋�[�v���s */
	Asm("	sil_dly_nse_2:");
}

#ifdef SUPPORT_CHG_IPM

/*
 *  �����݃}�X�N�̕ύX
 *
 *  �Echg_ipm ���g���āA�����݃}�X�N�� MAX_IPM �iNMI �X�^�u�����[�g�u���[�N �ȊO
 *    �̂��ׂĂ̊����݂��֎~�j�ȏ�ɕύX���邱�Ƃ͂ł��܂���BNMI �X�^�u�����[�g
 *    �u���[�N�ȊO�̂��ׂĂ̊����݂��֎~�������ꍇ�ɂ́Aloc_cpu�ɂ��CPU���b�N
 *    ��Ԃɂ��Ă��������B
 *  �E�����݃}�X�N�� 0 �ȊO�̎��ł����Ă��A�^�X�N�f�B�X�p�b�`�͕ۗ�����܂���B
 *    ���̂Ƃ��A�����݃}�X�N�̏�Ԃ́A�^�X�N�f�B�X�p�b�`�ɂ���ĐV�������s��Ԃ�
 *    �Ȃ����^�X�N�ցA���̓s�x�A�����p����܂��B
 *    ���̂��߁A�^�X�N�����s���ɁA�����݂��������A�f�B�X�p�b�`������̕ʂ̃^�X�N
 *    �ɂ���Ċ����݃}�X�N���ύX�����ꍇ������܂��B
 *    TOPPERS/JSP �J�[�l���ł́A�����݃}�X�N�̕ύX�̓^�X�N��O�������[�`���ɂ��
 *    �Ă��N����̂ŁC����ɂ���Ĉ���������Ȃ�󋵂͏��Ȃ��Ǝv���܂��B
 *  �E�����݃}�X�N�̒l�ɂ���ă^�X�N�f�B�X�p�b�`���֎~�������ꍇ�ɂ́Adis_dsp ��
 *    ���p���Ă��������B
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_PAR( /*(0 <= ipm) &&*/ (ipm <= MAX_IPM) );
	/* IPM�^ �́Aunsigned �Œ�`���Ă���̂ŁA�R�����g�A�E�g����
	   ����Ƃ���́A��ɐ������Ă��邽�߁AWarnning ����������B
	   �������A�ǐ��̖�肩��A�����I�ɋL�q���Ă����B */

	t_lock_cpu();
	task_intmask = ipm;
	ercd = E_OK;
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
	ER	ercd;

	LOG_GET_IPM_ENTER(p_ipm);
	CHECK_TSKCTX_UNL();

	t_lock_cpu();
	*p_ipm = task_intmask;
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
 * �o�^����Ă��Ȃ����荞�݂���������ƌĂяo�����
 */
void cpu_experr(EXCSTACK *sp)
{
	syslog( LOG_EMERG, "Unexpected interrupt." );
	syslog( LOG_EMERG, "SP  = %08x PC  = %08x CCR = %08x",
				sp - 34, sp->pc,  sp->ccr );
	syslog( LOG_EMERG, "ER0 = %08x ER1 = %08x ER2 = %08x ER3 = %08x",
				sp->er0, sp->er1, sp->er2, sp->er3 );
	syslog( LOG_EMERG, "ER4 = %08x ER5 = %08x ER6 = %08x ",
				sp->er4, sp->er5, sp->er6 );

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
VP _dummy_memcpy(VP dest, VP src, UINT len)
{
	VB	*d = (VB *)dest;
	VB	*s = (VB *)src;

	while (len-- > 0) {
		*d++ = *s++;
	}

	return(dest);
}
