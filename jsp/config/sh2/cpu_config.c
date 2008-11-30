/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iSH2�p�j
 *�@�@�@�@�@�J�[�l�������Ŏg�p�����`
 *�@�@�@�@�@�@C����֐��̎���
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <sh2.h>
#include <sil.h>

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
 *  �����݁^CPU��O�l�X�g�J�E���^
 */
UW	intnest;

/*
 *  �I���W�i���̃x�N�^�x�[�X���W�X�^�̕ۑ��̈�
 */
#ifdef KERNEL_HAS_A_VECTOR_TABLE
static VP org_vbr;
#endif /* KERNEL_HAS_A_VECTOR_TABLE */

#ifdef SUPPORT_CPU_EXC_ENTRY_CHECK

/*
 *  CPU��O�̗v����
 */
#ifndef NUM_EXC
#define NUM_EXC	(6 + 2)
#endif	/*  NUM_EXC  */

/*
 *  �o�^���ꂽCPU��O�̗v����
 */
static UW num_exc;

/*
 *  CPU��O�̓��������̐擪�A�h���X
 */
static FP exc_entries[NUM_EXC];

#endif /* SUPPORT_CPU_EXC_ENTRY_CHECK */

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize()
{
	/*
	 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N�̏�����
	 */
#ifdef SUPPORT_CHG_IPM
	task_intmask = 0x0000u;
#endif /* SUPPORT_CHG_IPM */

	/*
	 *  �����݁^CPU��O�l�X�g�J�E���^�̏�����
	 */
	intnest = 1u;

#ifndef GDB_STUB

	/*
	 * ���荞�݃R���g���[���̏�����
	 */
	sh2_init_intcontorller ();

#endif	/*  GDB_STUB  */

#ifdef KERNEL_HAS_A_VECTOR_TABLE
	/*
	 *  �x�N�^�e�[�u���͏����l�t���ϐ��i�z��j�ɂ����̂ŁA
	 *  �X�^�[�g�A�b�v���[�`����data�Z�N�V�������R�s�[����ۂ�
	 *  �����������B
	 *  �i�����ŏ���������K�v�͂Ȃ��B�j
	 */
	
	/*
	 *  �x�N�^�x�[�X���W�X�^�̏�����
	 */
	org_vbr = current_vbr();
	set_vbr((VP)vector_table);
#endif /* KERNEL_HAS_A_VECTOR_TABLE */

#ifdef SUPPORT_CPU_EXC_ENTRY_CHECK
	num_exc = 0;
#endif /* SUPPORT_CPU_EXC_ENTRY_CHECK */

}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate()
{
#ifdef KERNEL_HAS_A_VECTOR_TABLE
	set_vbr(org_vbr);
#endif /* KERNEL_HAS_A_VECTOR_TABLE */
}

/*
 *  CPU��O�n���h���̐ݒ�
 *
 *  �x�N�g���ԍ� excno ��CPU��O�n���h���̋N���Ԓn�� exchdr �ɐݒ肷��D
 */
void
define_exc(EXCNO excno, FP exchdr)
{
	/*  SH1�͊����݂�CPU��O�������`��  */
	define_inh((INHNO)excno, exchdr);

#ifdef SUPPORT_CPU_EXC_ENTRY_CHECK
//	CHECK_PAR(num_exc < NUM_EXC);
	exc_entries[num_exc++] = exchdr;
#endif /* SUPPORT_CPU_EXC_ENTRY_CHECK */
}

#ifdef SUPPORT_CPU_EXC_ENTRY_CHECK
/*
 *  CPU��O�̓��������Ŋ����݋֎~����܂ł̖��ߐ�
 */
#define NUM_INST_DIS_INT	5


/*
 *  �����݂���̖߂��̃`�F�b�N
 *
 *  �@����
 *  �@�@VP pc�F�X�^�b�N��ɐς܂ꂽ�߂�Ԓn
 *  �@�߂�l
 *  �@�@TRUE�F�߂�悪CPU��O�̓��������i�����݋֎~����O�j
 *  �@�@FALSE�F�߂�悪��L�ȊO
 *  �@���l
 *  �@�@�����݂̏o�������Ŋ����݋֎~�ŌĂ΂��B
 */

/* cpu_support.S��ret_int��������Ă΂��̂� 	*/
/* �w�b�_�[�t�@�C���ɂ͊܂߂Ȃ��B 		*/
BOOL check_cpu_exc_entry(VP pc)   throw();

BOOL check_cpu_exc_entry(VP pc)
{
	UW i;
	UH *entry;	/* 2�o�C�g�����߂ւ̃|�C���^ */
	
	for(i = 0; i < num_exc; i++) {
		entry = (UH *)exc_entries[i];
		if (((UW)entry <= (UW)pc) &&
		     ((UW)pc <= (UW)(entry + NUM_INST_DIS_INT)) ) {
			return TRUE;
		}
	}
	return FALSE;
}


#endif /* SUPPORT_CPU_EXC_ENTRY_CHECK */



#ifdef SUPPORT_CHG_IPM

/*
 *  �����݃}�X�N�̕ύX
 *
 *  chg_ipm ���g���� IPM ��0xf�iNMI �ȊO�̂��ׂĂ̊����݂��֎~�j�ɕύX
 *  ���邱�Ƃ͂ł��Ȃ��DNMI �ȊO�̂��ׂĂ̊����݂��֎~�������ꍇ�ɂ́C
 *  loc_cpu �ɂ��CPU���b�N��Ԃɂ���΂悢�D
 *  IPM �� 0 �ȊO�̎��ɂ��C�^�X�N�f�B�X�p�b�`�͕ۗ�����Ȃ��DIPM �́C
 *  �^�X�N�f�B�X�p�b�`�ɂ���āC�V�������s��ԂɂȂ����^�X�N�ֈ����p��
 *  ���D���̂��߁C�^�X�N�����s���ɁC�ʂ̃^�X�N�ɂ���� IPM ���ύX��
 *  ���ꍇ������DJSP�J�[�l���ł́CIPM �̕ύX�̓^�X�N��O�������[�`
 *  ���ɂ���Ă��N���邪�C����ɂ���Ĉ���������Ȃ�󋵂͏��Ȃ���
 *  �v����DIPM �̒l�ɂ���ă^�X�N�f�B�X�p�b�`���֎~�������ꍇ�ɂ́C
 *  dis_dsp �𕹗p����΂悢�D
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
	ER	ercd;

	LOG_CHG_IPM_ENTER(ipm);
	CHECK_TSKCTX_UNL();
	CHECK_PAR(0 <= ipm && ipm <= (MAX_IPM - 1) );

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
	ER	ercd;

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

/*
 * �o�^����Ă��Ȃ���O����������ƌĂяo�����
 */
void cpu_experr(EXCSTACK *sp)
{
    syslog(LOG_EMERG, "Exception error occurs.");

    syslog(LOG_EMERG, "PC = 0x%08x SR = 0x%08x PR = 0x%08x",
    			sp->pc, sp->sr, sp->pr);

    syslog(LOG_EMERG, "r0 = 0x%08x r1 = 0x%08x r2 = 0x%08x",
    			sp->r0, sp->r1, sp->r2);
    syslog(LOG_EMERG, "r3 = 0x%08x r4 = 0x%08x r5 = 0x%08x",
    			sp->r3, sp->r4, sp->r5);
    syslog(LOG_EMERG, "r6 = 0x%08x r7 = 0x%08x r8 = 0x%08x",
    			sp->r6, sp->r7, sp->r8);
    syslog(LOG_EMERG, "r9 = 0x%08x r10 = 0x%08x r11 = 0x%08x",
    			sp->r9, sp->r10, sp->r11);
    syslog(LOG_EMERG, "r12 = 0x%08x r13 = 0x%08x r14 = 0x%08x",
    			sp->r12, sp->r13, sp->r14);
    			/*  ��O�������O�̃X�^�b�N�|�C���^�̒l  */
    syslog(LOG_EMERG, "r15 = 0x%08x", (sp->r15)+19*4);

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
	VB	*d = (VB *)dest;
	VB	*s = (VB *)src;

	while (len-- > 0) {
		*d++ = *s++;
	}
	return(dest);
}

