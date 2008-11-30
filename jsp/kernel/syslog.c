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
 *  @(#) $Id: syslog.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�V�X�e�����O�@�\
 */

#undef OMIT_SYSLOG
#include "jsp_kernel.h"
#include "time_event.h"
#include "syslog.h"

/*
 *  �R���e�L�X�g�Ɉ˂�Ȃ�CPU���b�N�^���b�N����
 */
#define	lock_cpu()	(sense_context() ? i_lock_cpu() : t_lock_cpu())
#define	unlock_cpu()	(sense_context() ? i_unlock_cpu() : t_unlock_cpu())

#ifdef __logini

/*
 *  ���O�o�b�t�@�Ƃ���ɃA�N�Z�X���邽�߂̃|�C���^
 */
SYSLOG	syslog_buffer[TCNT_SYSLOG_BUFFER];	/* ���O�o�b�t�@ */
UINT	syslog_count;			/* ���O�o�b�t�@���̃��O�̐� */
UINT	syslog_head;			/* �擪�̃��O�̊i�[�ʒu */
UINT	syslog_tail;			/* ���̃��O�̊i�[�ʒu */
UINT	syslog_lost;			/* ����ꂽ���O�̐� */

/*
 *  �o�͂��ׂ����O���̏d�v�x�i�r�b�g�}�b�v�j
 */
UINT	syslog_logmask;			/* ���O�o�b�t�@�ɋL�^���ׂ��d�v�x */
UINT	syslog_lowmask;			/* �჌�x���o�͂��ׂ��d�v�x */

/*
 *  �V�X�e�����O�@�\�̏�����
 */
void
syslog_initialize()
{
	syslog_count = 0;
	syslog_head = syslog_tail = 0;
	syslog_lost = 0;

	syslog_logmask = 0;
	syslog_lowmask = LOG_UPTO(LOG_NOTICE);
}     

#endif /* __logini */

/* 
 *  ���O���̏o��
 *
 *  CPU���b�N��Ԃ���s�R���e�L�X�g�ɂ�炸����ł���悤�Ɏ������Ă���D
 */
#ifdef __vwri_log

SYSCALL ER
vwri_log(UINT prio, SYSLOG *p_log)
{
	BOOL	locked;

	locked = sense_lock();
	if (!locked) {
		lock_cpu();
	}

	/*
	 *  ���O�����̐ݒ�
	 */
	p_log->logtim = systim_offset + current_time;

	/*
	 *  ���O�o�b�t�@�ɋL�^
	 */
	if ((syslog_logmask & LOG_MASK(prio)) != 0) {
		syslog_buffer[syslog_tail] = *p_log;
		syslog_tail++;
		if (syslog_tail >= TCNT_SYSLOG_BUFFER) {
			syslog_tail = 0;
		}
		if (syslog_count < TCNT_SYSLOG_BUFFER) {
			syslog_count++;
		}
		else {
			syslog_head = syslog_tail;
			syslog_lost++;
		}
	}

	/*
	 *  �჌�x���o��
	 */
	if ((syslog_lowmask & LOG_MASK(prio)) != 0) {
		syslog_print(p_log, sys_putc);
	}

	if (!locked) {
		unlock_cpu();
	}
	return(E_OK);
}

#endif /* __vwri_log */

/*
 *  ���O�o�b�t�@����̓Ǐo��
 *
 *  CPU���b�N��Ԃ���s�R���e�L�X�g�ɂ�炸����ł���悤�Ɏ������Ă���D
 */
#ifdef __vrea_log

SYSCALL ER_UINT
vrea_log(SYSLOG *p_log)
{
	BOOL	locked;
	ER_UINT	ercd;

	locked = sense_lock();
	if (!locked) {
		lock_cpu();
	}
	if (syslog_count > 0) {
		*p_log = syslog_buffer[syslog_head];
		syslog_count--;
		syslog_head++;
		if (syslog_head >= TCNT_SYSLOG_BUFFER) {
			syslog_head = 0;
		}
		ercd = (ER_UINT) syslog_lost;
		syslog_lost = 0;
	}
	else {
		ercd = E_OBJ;
	}
	if (!locked) {
		unlock_cpu();
	}
	return(ercd);
}

#endif /* __vrea_log */

/* 
 *  �o�͂��ׂ����O���̏d�v�x�̐ݒ�
 */
#ifdef __vmsk_log

SYSCALL ER
vmsk_log(UINT logmask, UINT lowmask)
{
	syslog_logmask = logmask;
	syslog_lowmask = lowmask;
	return(E_OK);
}

#endif /* __vmsk_log */

/* 
 *  �V�X�e�����O�@�\�̏I������
 *
 *  ���O�o�b�t�@�ɋL�^���ꂽ���O�����C�჌�x���o�͋@�\��p���ďo�͂�
 *  ��D
 */
#ifdef __logter

void
syslog_terminate()
{
	syslog_printf("-- buffered messages --", NULL, sys_putc);
	syslog_output(sys_putc);
}

#endif /* __logter */
