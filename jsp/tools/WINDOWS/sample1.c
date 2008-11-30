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
 *  @(#) $Id: sample1.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/* 
 *  �T���v���v���O����(1)�̖{��
 *
 *  JSP�J�[�l���̊�{�I�ȓ�����m�F���邽�߂̃T���v���v���O�����D
 *
 *  �v���O�����̊T�v:
 *
 *  ���[�U�C���^�t�F�[�X���󂯎����C���^�X�N�i�^�X�NID: MAIN_TASK�C
 *  �D��x: MAIN_PRIORITY�j�ƁC�O�̕�����s�����^�X�N�i�^�X�NID:
 *  TASK1�`TASK3�C�����D��x: MID_PRIORITY�j�ō\�������D�܂��C�N����
 *  ����2�b�̎����n���h���i�����n���h��ID: CYCHDR1�j��p����D
 *
 *  ������s�����^�X�N�́Ctask_loop ��󃋁[�v�����s����x�ɁC�^�X�N
 *  �����s���ł��邱�Ƃ�����킷���b�Z�[�W��\������D
 *
 *  �����n���h���́C�O�̗D��x�iHIGH_PRIORITY�CMID_PRIORITY�C
 *  LOW_PRIORITY�j�̃��f�B�L���[����]������D�v���O�����̋N������́C
 *  �����n���h���͒�~��ԂɂȂ��Ă���D
 *
 *  ���C���^�X�N�́C�V���A��I/O�|�[�g����̕������͂��s���i�������͂�
 *  �҂��Ă���Ԃ́C������s�����^�X�N�����s����Ă���j�C���͂��ꂽ
 *  �����ɑΉ��������������s����D���͂��ꂽ�����Ə����̊֌W�͎��̒ʂ�D
 *  Control-C �܂��� 'Q' �����͂����ƁC�v���O�������I������D
 *
 *  '1' : �ȍ~�̃R�}���h�� TASK1 �ɑ΂��čs���D
 *  '2' : �ȍ~�̃R�}���h�� TASK2 �ɑ΂��čs���D
 *  '3' : �ȍ~�̃R�}���h�� TASK3 �ɑ΂��čs���D
 *  'a' : �^�X�N�� act_tsk �ɂ��N������D
 *  'A' : �^�X�N�ɑ΂���N���v���� can_act �ɂ��L�����Z������D
 *  'e' : �^�X�N�� ext_tsk ���Ăяo�����C�I��������D
 *  't' : �^�X�N�� ter_tsk �ɂ�苭���I������D
 *  '>' : �^�X�N�̗D��x�� HIGH_PRIORITY �ɂ���D
 *  '=' : �^�X�N�̗D��x�� MID_PRIORITY �ɂ���D
 *  '<' : �^�X�N�̗D��x�� LOW_PRIORITY �ɂ���D
 *  'G' : �^�X�N�̗D��x�� get_pri �œǂݏo���D
 *  's' : �^�X�N�� slp_tsk ���Ăяo�����C�N���҂��ɂ�����D
 *  'S' : �^�X�N�� tslp_tsk(10�b) ���Ăяo�����C�N���҂��ɂ�����D
 *  'w' : �^�X�N�� wup_tsk �ɂ��N������D
 *  'W' : �^�X�N�ɑ΂���N���v���� can_wup �ɂ��L�����Z������D
 *  'l' : �^�X�N�� rel_wai �ɂ�苭���I�ɑ҂������ɂ���D
 *  'u' : �^�X�N�� sus_tsk �ɂ�苭���҂���Ԃɂ���D
 *  'm' : �^�X�N�̋����҂���Ԃ� rsm_tsk �ɂ���������D
 *  'M' : �^�X�N�̋����҂���Ԃ� frsm_tsk �ɂ�苭����������D
 *  'd' : �^�X�N�� dly_tsk(10�b) ���Ăяo�����C���Ԍo�ߑ҂��ɂ�����D
 *  'x' : �^�X�N�Ƀp�^�[�� 0x0001 �̗�O������v������D
 *  'X' : �^�X�N�Ƀp�^�[�� 0x0002 �̗�O������v������D
 *  'y' : �^�X�N�� dis_tex ���Ăяo�����C�^�X�N��O���֎~����D
 *  'Y' : �^�X�N�� ena_tex ���Ăяo�����C�^�X�N��O��������D
 *  'r' : �O�̗D��x�iHIGH_PRIORITY�CMID_PRIORITY�CLOW_PRIORITY�j��
 *        ���f�B�L���[����]������D
 *  'c' : �����n���h���𓮍삳����D
 *  'C' : �����n���h�����~������D
 *  'z' : CPU��O�𔭐�������D
 *  'Z' : CPU���b�N��Ԃ�CPU��O�𔭐�������i�v���O�������I������j�D
 *  'V' : vxget_tim �Ő��\�]���p�V�X�e��������2��ǂށD
 *  'v' : ���s�����V�X�e���R�[����\������i�f�t�H���g�j�D
 *  'q' : ���s�����V�X�e���R�[����\�����Ȃ��D
 */

#include <t_services.h>
#include "kernel_id.h"
#include "sample1.h"

/*
 *  ���s���s�����^�X�N�ւ̃��b�Z�[�W�̈�
 */
UB	message[3];

/*
 *  ���[�v��
 */
UW	task_loop;		/* �^�X�N���ł̃��[�v�� */
UW	tex_loop;		/* ��O�������[�`�����ł̃��[�v�� */

/*
 *  ���s���s�����^�X�N
 */
void task(VP_INT exinf)
{
	volatile UW	i;
	INT	n = 0;
	INT	tskno = (INT) exinf;
	UB	*graph[] = { "|", "  +", "    *" };
	UB	c;

	ena_tex();
	while (1) {
		syslog(LOG_NOTICE, "task%d is running (%03d).   %s",
					tskno, ++n, graph[tskno-1]);
		for (i = 0; i < task_loop; i++);
		c = message[tskno-1];
		message[tskno-1] = 0;
		switch (c) {
		case 'e':
			syslog(LOG_INFO, "#%d#ext_tsk()", tskno);
			ext_tsk();
		case 's':
			syslog(LOG_INFO, "#%d#slp_tsk()", tskno);
			syscall(slp_tsk());
			break;
		case 'S':
			syslog(LOG_INFO, "#%d#tslp_tsk(10000)", tskno);
			syscall(tslp_tsk(10000));
			break;
		case 'd':
			syslog(LOG_INFO, "#%d#dly_tsk(10000)", tskno);
			syscall(dly_tsk(10000));
			break;
		case 'y':
			syslog(LOG_INFO, "#%d#dis_tex()", tskno);
			syscall(dis_tex());
			break;
		case 'Y':
			syslog(LOG_INFO, "#%d#ena_tex()", tskno);
			syscall(ena_tex());
			break;
#ifdef CPUEXC1
		case 'z':
			syslog(LOG_NOTICE, "#%d#raise CPU exception", tskno);
			RAISE_CPU_EXCEPTION;
			break;
		case 'Z':
			loc_cpu();
			syslog(LOG_NOTICE, "#%d#raise CPU exception", tskno);
			RAISE_CPU_EXCEPTION;
			unl_cpu();
			break;
#endif /* CPUEXC1 */
		default:
			break;
		}
	}
}

/*
 *  ���s���Ď��s�����^�X�N�p�̃^�X�N��O�������[�`��
 */
void tex_routine(TEXPTN texptn, VP_INT exinf)
{
	volatile UW	i;
	INT	tskno = (INT) exinf;

	syslog(LOG_NOTICE, "task%d receives exception 0x%04x. ",
					tskno, texptn);
	for (i = 0; i < tex_loop; i++);

	if (texptn & 0x8000) {
		syslog(LOG_INFO, "#%d#ext_tsk()", tskno);
		ext_tsk();
	}
}

/*
 *  CPU��O�n���h��
 */
#ifdef CPUEXC1

void
cpuexc_handler(VP p_excinf)
{
	ID	tskid;

	syslog(LOG_NOTICE, "CPU exception handler (p_excinf = %08x).",
							 p_excinf);
	if (sns_ctx() != TRUE) {
		syslog(LOG_WARNING,
			"sns_ctx() is not TRUE in CPU exception handler.");
	}
	if (sns_dpn() != TRUE) {
		syslog(LOG_WARNING,
			"sns_dpn() is not TRUE in CPU exception handler.");
	}
	syslog(LOG_DEBUG,
		"sns_loc = %d sns_dsp = %d", sns_loc(), sns_dsp());
	syslog(LOG_DEBUG,
		"vxsns_loc = %d vxsns_ctx = %d vxsns_dsp = %d vxsns_dpn = %d",
		vxsns_loc(p_excinf), vxsns_ctx(p_excinf),
		vxsns_dsp(p_excinf), vxsns_dpn(p_excinf));

	if (!vxsns_loc(p_excinf) && !vxsns_ctx(p_excinf)) {
		syscall(iget_tid(&tskid));
		syscall(iras_tex(tskid, 0x8000));
	}
	else {
		syslog(LOG_NOTICE, "Sample program ends with exception.");
		kernel_exit();
	}
}

#endif /* CPUEXC1 */

/*
 *  �����n���h��
 *
 *  HIGH_PRIORITY�CMID_PRIORITY�CLOW_PRIORITY �̊e�D��x�̃��f�B�L���[
 *  ����]������D
 */
void cyclic_handler(VP_INT exinf)
{
	irot_rdq(HIGH_PRIORITY);
	irot_rdq(MID_PRIORITY);
	irot_rdq(LOW_PRIORITY);
}

/*
 *  ���C���^�X�N
 */
void main_task(VP_INT exinf)
{
	UB	c;
	ID	tskid = TASK1;
	volatile UW	i;
	INT count;
	INT	tskno = 1;
	ER_UINT	ercd;	
	PRI	tskpri;
	SYSTIM	stime1, stime2;
#ifndef OMIT_VGET_TIM
	SYSUTIM	utime1, utime2;
#endif /* OMIT_VGET_TIM */

	vmsk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG));
	syslog(LOG_NOTICE, "Sample program starts (exinf = %d).", exinf);

	serial_ctl_por(TASK_PORTID, (IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV));

	/*
 	 *  ���[�v�񐔂̐ݒ�
	 */
	count = 0;
	task_loop = LOOP_REF;
	get_tim(&stime1);
	do {
		++ count;
		for (i = 0; i < task_loop; i++);
		get_tim(&stime2);
	}while(stime1 == stime2);
	task_loop = LOOP_REF * 400 / (stime2 - stime1);
	tex_loop = task_loop / 5;

	/*
 	 *  �^�X�N�̋N��
	 */
	act_tsk(TASK1);
	act_tsk(TASK2);
	act_tsk(TASK3);

	/*
 	 *  ���C�����[�v
	 */
	do {
		serial_rea_dat(TASK_PORTID, &c, 1);
		switch (c) {
		case 'e':
		case 's':
		case 'S':
		case 'd':
		case 'y':
		case 'Y':
		case 'z':
		case 'Z':
			message[tskno-1] = c;
			break;
		case '1':
			tskno = 1;
			tskid = TASK1;
			break;
		case '2':
			tskno = 2;
			tskid = TASK2;
			break;
		case '3':
			tskno = 3;
			tskid = TASK3;
			break;
		case 'a':
			syslog(LOG_INFO, "#act_tsk(%d)", tskno);
			syscall(act_tsk(tskid));
			break;
		case 'A':
			syslog(LOG_INFO, "#can_act(%d)", tskno);
			syscall(ercd = can_act(tskid));
			if (MERCD(ercd) >= 0) {
				syslog(LOG_NOTICE, "can_act(%d) returns %d",
						tskid, ercd);
			}
			break;
		case 't':
			syslog(LOG_INFO, "#ter_tsk(%d)", tskno);
			syscall(ter_tsk(tskid));
			break;
		case '>':
			syslog(LOG_INFO, "#chg_pri(%d, HIGH_PRIORITY)", tskno);
			chg_pri(tskid, HIGH_PRIORITY);
			break;
		case '=':
			syslog(LOG_INFO, "#chg_pri(%d, MID_PRIORITY)", tskno);
			chg_pri(tskid, MID_PRIORITY);
			break;
		case '<':
			syslog(LOG_INFO, "#chg_pri(%d, LOW_PRIORITY)", tskno);
			chg_pri(tskid, LOW_PRIORITY);
			break;
		case 'G':
			syslog(LOG_INFO, "#get_pri(%d, &tskpri)", tskno);
			syscall(ercd = get_pri(tskid, &tskpri));
			if (MERCD(ercd) >= 0) {
				syslog(LOG_NOTICE, "priority of task %d is %d",
						tskid, tskpri);
			}
			break;
		case 'w':
			syslog(LOG_INFO, "#wup_tsk(%d)", tskno);
			syscall(wup_tsk(tskid));
			break;
		case 'W':
			syslog(LOG_INFO, "#can_wup(%d)", tskno);
			syscall(ercd = can_wup(tskid));
			if (MERCD(ercd) >= 0) {
				syslog(LOG_NOTICE, "can_wup(%d) returns %d",
						tskid, ercd);
			}
			break;
		case 'l':
			syslog(LOG_INFO, "#rel_wai(%d)", tskno);
			syscall(rel_wai(tskid));
			break;
		case 'u':
			syslog(LOG_INFO, "#sus_tsk(%d)", tskno);
			syscall(sus_tsk(tskid));
			break;
		case 'm':
			syslog(LOG_INFO, "#rsm_tsk(%d)", tskno);
			syscall(rsm_tsk(tskid));
			break;
		case 'M':
			syslog(LOG_INFO, "#frsm_tsk(%d)", tskno);
			syscall(frsm_tsk(tskid));
			break;
		case 'x':
			syslog(LOG_INFO, "#ras_tsk(%d, 0x0001)", tskno);
			syscall(ras_tex(tskid, 0x0001));
			break;
		case 'X':
			syslog(LOG_INFO, "#ras_tsk(%d, 0x0002)", tskno);
			syscall(ras_tex(tskid, 0x0002));
			break;
		case 'r':
			syslog(LOG_INFO, "#rot_rdq(three priorities)");
			rot_rdq(HIGH_PRIORITY);
			rot_rdq(MID_PRIORITY);
			rot_rdq(LOW_PRIORITY);
			break;
		case 'c':
			sta_cyc(CYCHDR1);
			break;
		case 'C':
			stp_cyc(CYCHDR1);
			break;
#ifndef OMIT_VGET_TIM
		case 'V':
			syscall(vxget_tim(&utime1));
			syscall(vxget_tim(&utime2));
			syslog(LOG_NOTICE, "utime1 = %d, utime2 = %d",
						(UINT) utime1, (UINT) utime2);
			break;
#endif /* OMIT_VGET_TIM */
		case 'v':
			vmsk_log(LOG_UPTO(LOG_INFO), LOG_UPTO(LOG_EMERG));
			break;
		case 'q':
			vmsk_log(LOG_UPTO(LOG_NOTICE), LOG_UPTO(LOG_EMERG));
			break;
		default:
			break;
		}
	} while (c != '\003' && c != 'Q');

	syslog(LOG_NOTICE, "Sample program ends.");
	kernel_exit();
}
