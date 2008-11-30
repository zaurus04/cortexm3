/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
volatile IPM	task_intmask = 0;		/* IPM -> UB�F��������8�r�b�g */
#endif /* SUPPORT_CHG_IPM */

/*
 *  ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
volatile IPM	int_intmask = 0;

/*
 *  �����݃l�X�g�J�E���^
 */
volatile UB	intnest = 1;

/*
 *  CPU���b�N��Ԃ�\���t���O
 *  �@�E�����݋֎~�i�J�[�l���Ǘ����̊����݂̂݁j
 *  �@�@�@����
 *  �@�Eiscpulocked == TRUE
 *  �@�@�@�̂Ƃ�CPU���b�N��ԂƂ���B
 */
volatile BOOL     iscpulocked = TRUE;

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void cpu_initialize(void) {

        /*
         *  �ȉ���4�̓X�^�[�g�A�b�v���[�`���ŏ��������ς�ł���B
         *  �@�@�E�����݃l�X�g�J�E���^ intnest = 1;
         *  �@�@�E��^�X�N�R���e�L�X�g�̊����݃}�X�N int_intmask = 0;
         *  �@�@�E�^�X�N�R���e�L�X�g�̊����݃}�X�N task_intmask = 0;
         *  �@�@�@�@�ichg_ipm���T�|�[�g����ꍇ�j
         *  �@�@�ECPU���b�N�t���O iscpulocked = TRUE;
         */

	/* �����ݐ��䃂�[�h�̐ݒ� */
	h8s_wrb_reg(SYSCR, SYS_SYSCR);

	/* �����݃��x���̏����� */
	h8s_wrb_reg(IPRA, 0);
	h8s_wrb_reg(IPRB, 0);
	h8s_wrb_reg(IPRC, 0);
	h8s_wrb_reg(IPRD, 0);
	h8s_wrb_reg(IPRE, 0);
	h8s_wrb_reg(IPRF, 0);
	h8s_wrb_reg(IPRG, 0);
	h8s_wrb_reg(IPRH, 0);
	h8s_wrb_reg(IPRI, 0);
	h8s_wrb_reg(IPRJ, 0);
	h8s_wrb_reg(IPRK, 0);
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void cpu_terminate(void) {
}

/*
 * �������ԑ҂�
 * �@�@���ӎ����F
 * �@�@�@�W���ł�dlytim��UINT�^����16�r�b�g�����Ȃ��̂ŁA
 * �@�@�@UW�^�ɕύX���Ă���B
 * �@�@�@sil_dly_nse()�͓�����sil_dly_nse_long()���Ăяo���B
 */
void sil_dly_nse(UINT dlytim) {
	sil_dly_nse_long((UW)dlytim);
}

#ifdef SUPPORT_CHG_IPM

/*
 *  �����݃}�X�N�̕ύX
 *
 *�@IPM�ɐݒ�ł���l��0�`MAX_IPM�ł���B
 *�@�����݃v���C�I���e�B���x����(MAX_IPM+1)�ȏ�̊����݂̓J�[�l���Ǘ��O
 *�@�����ł���B
 *
 *  IPM �� 0 �ȊO�̎��ɂ��C�^�X�N�f�B�X�p�b�`�͕ۗ�����Ȃ��D
 *  �f�B�X�p�b�`���֎~�������ꍇ�ɂ́Cloc_cpu �ɂ��CPU���b�N��Ԃ�
 *  ����΂悢�DIPM �́C
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
        CHECK_PAR(ipm <= MAX_IPM);

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

/*============================================================================*/
/*  ���ʃh�L�������g�ɂ͂Ȃ��A�Ǝ��̕���  */

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
    
    syslog(LOG_EMERG, "Unexpected interrupt.");
    syslog(LOG_EMERG, "PC  = 0x%08lx SP  = 0x%08lx CCR  = 0x%02x",
                       (VP)pc, (VP)sp2, (INT)ccr);
    syslog(LOG_EMERG, "EXR  = 0x%02x", (INT)(sp->exr));
    syslog(LOG_EMERG, "ER0 = 0x%08lx ER1 = 0x%08lx ER2 = 0x%08lx ER3 = 0x%08lx",
           (VP)(sp->er0), (VP)(sp->er1), (VP)(sp->er2), (VP)(sp->er3));
    syslog(LOG_EMERG, "ER4 = 0x%08lx ER5 = 0x%08lx ER6 = 0x%08lx",
                       (VP)(sp->er4), (VP)(sp->er5), (VP)(sp->er6));
    while(1)
    	;
}


/*============================================================================*/
/*  �f�o�b�O�p�R�[�h  */

#ifdef TEST_CPU_INSN

volatile UB ccr, exr;
volatile IPM intmask;

void test_cpu_insn(void)
{
	ccr = current_ccr();
	set_ccr(0xf);
	ccr = current_ccr();

	exr = current_exr();
	set_exr(0x7);
	exr = current_exr();

	intmask = current_intmask();
	set_intmask(0x3);
	intmask = current_intmask();
	
	disint();
	enaint();
	
	_disint_();
}

#endif /* TEST_CPU_INSN */


#ifdef TEST_CPU_CONFIG

volatile BOOL b;
volatile ER err;
volatile IPM ipm;

void dummy(void)
{
}

void test_cpu_config(void)
{
	b = sense_context();
	dummy();
	intnest = 1;
	dummy();
	b = sense_context();
	dummy();
	intnest = 0;
	dummy();
	b = sense_context();
	dummy();

	b = t_sense_lock();
	dummy();
	t_lock_cpu();
	dummy();
	b = t_sense_lock();
	dummy();
	t_unlock_cpu();
	dummy();
	b = t_sense_lock();
	dummy();

	i_lock_cpu();
	dummy();
	b = i_sense_lock();
	dummy();
	i_unlock_cpu();
	dummy();
	b = i_sense_lock();
	dummy();
	
	err = chg_ipm(6);
	dummy();
	err = get_ipm(&ipm);
	dummy();
	err = chg_ipm(3);
	dummy();
	err = get_ipm(&ipm);
	dummy();
	err = chg_ipm(8);
	dummy();
}

#endif /* TEST_CPU_CONFIG */

#ifdef TEST_H8S_SIL

volatile UB ddr;

void test_h8s_sil(void)
{
	ddr = sil_reb_ddr(IO_PORT7);
	sil_wrb_ddr(IO_PORT7, 0xff);
	ddr = sil_reb_ddr(IO_PORT7);
	sil_anb_ddr(IO_PORT7, 0xf);
	ddr = sil_reb_ddr(IO_PORT7);
	sil_orb_ddr(IO_PORT7, 0x80);
	ddr = sil_reb_ddr(IO_PORT7);
}

#endif /* TEST_H8S_SIL */



