/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */


/*
 *	�v���Z�b�T�ˑ����W���[��(S1C33�p)
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "itron.h"
#include "s1c33.h"
#include "sys_config.h"

/*
 *  CPU���b�N�������ɕ�������
 */
UINT	tps_OrgIntLevel;

/*
 *  �����݃l�X�g�J�E���^
 */
UINT	tps_IntNestCnt;

/*
 *  �����ݐ��䃌�W�X�^ �ʒu���菈��
 */
ER	get_Offset(INTNO);
ER	get_BitFlag(INTNO);

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize()
{
	tps_IntNestCnt = 0;			/* �����݃l�X�g�J�E���g�̏����� */
	tps_OrgIntLevel = TPS_INIT_INTLEVEL;

	/*
	 *  ���荞�݋��t���O��ݒ肵�AOS�Ǘ����̊��荞�݂��}�X�N����
	 */
	set_psr((TPS_CPULOCK_LEV << 8) | S1C33_PSR_FLAG_IE);

}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{

}

/*
 *  �^�X�N�N������
 */
void
activate_r(void)
{
	unlock_cpu();
	Asm("xld.w %r0, ext_tsk");		/* �߂�ʒu��ext_tsk�ɐݒ� */
	Asm("pushn %r0");
	Asm("ld.w %%r6, %0": : "r"(runtsk->tinib->exinf));
	set_pc(runtsk->tinib->task);
}

/*
 *  �^�X�N�f�B�X�p�b�`��
 *
 *  dispatch�̓^�X�N�R���e�L�X�g�ECPU���b�N��ԂŌĂяo���B
 *  exit_and_dispatch�����l�����A�J�[�l���N�����ɑΉ����邽��
 *  ��^�X�N�R���e�L�X�g�ECPU���b�N������Ԃ̌Ăяo���ɂ��Ή�
 *  ���Ă���B
 */
void
dispatch(void)
{
	TCB * task;

	Asm("pushn %r3");
	task = runtsk;
	task->tskctxb.sp = get_sp();
	task->tskctxb.pc = && dispatch_1;	/* gcc�g���@�\���g�p���� */
	Asm("xjp _kernel_exit_and_dispatch");
dispatch_1:
	Asm("popn %r3");
	task = (TCB * volatile) runtsk;
	if ((task->enatex != FALSE) && (task->texptn != 0)) {
		Asm("xjp _kernel_calltex");	/* ��O�n���h���N��	*/
	}
}

void
exit_and_dispatch(void)
{
	register UW	ulPsr;

	lock_cpu();			/* CPU�����b�N����	*/
	runtsk = schedtsk;
	if (runtsk != NULL) {
		set_sp(runtsk->tskctxb.sp);
		set_pc(runtsk->tskctxb.pc);
	}

	set_sp(STACKTOP);			/* ���s�\�ȃ^�X�N���Ȃ��ꍇ	*/
	ulPsr = get_psr();			/* ���荞�݂������ăC�x���g	*/
	ulPsr |= S1C33_PSR_FLAG_IE;	/* ������҂�					*/
	set_psr(ulPsr);
	unlock_cpu();

	while (1) {
		Asm("halt");
	}
}

/*
 *  �����݃n���h��/CPU��O�n���h���o������
 */
void
ret_int(void)
{
	static	TCB * task;

	reqflg = FALSE;
	task = runtsk;

	if (task == NULL) {			/* �A�C�h�������փW�����v���� */
		Asm("xjp _kernel_exit_and_dispatch");
	}

	if ((enadsp != FALSE) && (task != schedtsk)) {
#ifndef	__c33adv
		Asm("pushn %r1");
#endif	/* __c33adv */
		task->tskctxb.sp = get_sp();
		task->tskctxb.pc = && ret_int_2;/* gcc�g���@�\���g�p */
						/* �f�B�X�p�b�`�����փW�����v */
		Asm("xjp _kernel_exit_and_dispatch");
ret_int_2:
#ifndef	__c33adv
		Asm("popn %r1");
#endif	/* __c33adv */
	}
	task = (TCB * volatile) runtsk;
	if ((task->enatex != FALSE) && (task->texptn != 0)) {
		call_texrtn();			/* ��O�n���h���N��	*/
	}
#ifdef	__c33adv
	Asm("pops %sor");
#else	/* __c33adv */
	Asm("ld.w %alr, %r1");
	Asm("ld.w %ahr, %r0");
#endif	/* __c33adv */

#if TPS_DAREA_CNT == 4				/* �f�[�^�G���A�|�C���^����	*/
	Asm("popn %r11");			/* ������pop�������s��		*/
#elif TPS_DAREA_CNT == 3
	Asm("popn %r12");
#elif TPS_DAREA_CNT == 2
	Asm("popn %r13");
#elif TPS_DAREA_CNT == 1
	Asm("popn %r14");
#else
	Asm("popn %r15");
#endif /* TPS_DAREA */

	Asm("reti");				/* CPU���b�N��Ԃ͕��A����	*/
						/* �^�X�N�̃T�[�r�X�R�[������	*/
						/* ���^�[�����鎞�ɉ��������	*/
}


/*
 *  �����݃��x���ύX����
 */
ER
chg_ilv(ILEVNO ilevno)
{
	UW	ulPsr;
	ER	ercd;

	LOG_CHG_ILV_ENTER(ilevno)
	CHECK_TSKCTX_UNL();
	if(ilevno > TPS_INTLEV_MAX){
		ercd = E_PAR;
	} else {
		ulPsr = get_psr();			/* ���݂�PSR�l���擾	*/
		ulPsr = (ulPsr & ~S1C33_PSR_MASK_IL) | (ilevno << 8);
		set_psr(ulPsr);				/* PSR�l���X�V		*/
		ercd = E_OK;
	}
exit:
	LOG_CHG_ILV_LEAVE(ercd)				/* Set New IL		*/
	return(ercd);
}

/*
 *  �����݃��x���擾����
 */
ER
get_ilv(ILEVNO *p_ilevno)
{
	UW	ulPsr;
	ER	ercd;

	LOG_GET_ILV_ENTER(p_ilevno)
	CHECK_TSKCTX_UNL();
	if(p_ilevno == NULL){
		ercd = E_PAR;
	} else {
		ulPsr = get_psr();			/* ���݂̊����݃��x�����擾 */
		*p_ilevno = (ulPsr & S1C33_PSR_MASK_IL) >> 8;
		ercd = E_OK;
	}
exit:
	LOG_GET_ILV_LEAVE(ercd, piLevno)
	return(ercd);
}

#ifndef __c33pe
/*
 *  �����ݔ���������
 */
ER
ena_int(INTNO intno)
{
	INT	iOffset, iBitFlag;

	iOffset = get_Offset(intno);			/* ���W�X�^�ʒu���擾���� */
	iBitFlag = get_BitFlag(intno);

	if(iOffset == E_PAR || iBitFlag == E_PAR){
		return (E_PAR);
	}
							/* ���荞�݂������� */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntEnable[iOffset] |= (UB)iBitFlag;

	return (E_OK);
}

/*
 *  �����ݔ����֎~����
 */
ER
dis_int(INTNO intno)
{
	INT	iOffset, iBitFlag;

	iOffset = get_Offset(intno);			/* ���W�X�^�ʒu���擾����  */
	iBitFlag = get_BitFlag(intno);

	if(iOffset == E_PAR || iBitFlag == E_PAR){
		return (E_PAR);
	}
							/* ���荞�݂��֎~���� */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntEnable[iOffset] &= ~((UB)iBitFlag);

	return (E_OK);
}

/*
 *  �����ݔ����v���N���A
 */
ER
clr_int(INTNO intno)
{
	INT	iOffset, iBitFlag;

	iOffset = get_Offset(intno);			/* ���W�X�^�ʒu���擾���� */
	iBitFlag = get_BitFlag(intno);

	if(iOffset == E_PAR || iBitFlag == E_PAR){
		return (E_PAR);
	}
#ifdef	__c33adv
	if(intno > S1C33_INHNO_SERIAL3TX){		/* ����/�֎~���W�X�^�Ɨv��    */
		iOffset -= 0x0d;			/* �t���O���W�X�^�̃I�t�Z�b�g */
	}						/* �ʒu����v���Ȃ�����       */
#endif /* __c33adv */
							/* ���荞�ݗv�����N���A���� */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntFactor[iOffset] = ((UB)iBitFlag);

	return (E_OK);
}
#else  /* __c33pe */
#error "*_int() are valid for C33 Standard/Advanced macro."
#endif /* __c33pe */
