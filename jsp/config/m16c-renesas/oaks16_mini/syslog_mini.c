/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RICOH COMPANY,LTD. JAPAN
 * 
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: syslog_mini.c,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

/*
 *  �V�X�e�����O�@�\�ȗ���
 */

#undef OMIT_SYSLOG
#include "jsp_kernel.h"
#include "time_event.h"
#include "serial.h"

/*
 *  �o�͂��ׂ����O���̏d�v�x�i�r�b�g�}�b�v�j
 */
static UINT	syslog_logmask;		/* �L�^�^�o�͂��ׂ��d�v�x */
static UINT	syslog_lowmask;		/* �჌�x���o�͂��ׂ��d�v�x */

/*
 *  �V�X�e�����O�@�\�̏�����
 */
void syslog_initialize(void)
{
	syslog_logmask = LOG_UPTO(LOG_NOTICE);
	syslog_lowmask = LOG_UPTO(LOG_NOTICE);
}

/* 
 *  ���O���̏o��
 */
SYSCALL ER
vwri_log(UINT prio, SYSLOG *p_log)
{
	BOOL	locked;

	p_log->logtim = systim_offset + current_time;
	if ((syslog_logmask & LOG_MASK(prio)) != 0) {
		/*
	 	*  �჌�x���o�͂ւ̏��o��
	 	*/
		syslog_print(p_log, sys_putc);
		sys_putc('\n');
	}
	return(E_OK);
}

/* 
 *  �o�͂��ׂ����O���̏d�v�x�̐ݒ�
 */
SYSCALL ER
vmsk_log(UINT logmask, UINT lowmask)
{
	syslog_logmask = logmask;
	syslog_lowmask = lowmask;
	return(E_OK);
}

/* 
 *  �V�X�e�����O�@�\�̏I������
 *
 *  ���O�o�b�t�@�ɋL�^���ꂽ���O�����C�჌�x���o�͋@�\��p���ďo�͂�
 *  ��D
 */
void
syslog_terminate(void){}

/*
 *  ���l�𕶎���ɕϊ�
 */
static void
convert(unsigned long val, int radix, const char *radchar, int width,
		int minus, int padzero, void (*putc)(char))
{
	char	buf[12];
	int	i, j;

	i = 0;
	do {
		buf[i++] = radchar[val % radix];
		val /= radix;
	} while (val != 0);

	width -= minus;
	if (minus > 0 && padzero > 0) {
		(*putc)('-');
	}
	for (j = i; j < width; j++) {
		(*putc)((char)(padzero > 0 ? '0' : ' '));
	}
	if (minus > 0 && padzero <= 0) {
		(*putc)('-');
	}
	while (i > 0) {
		(*putc)(buf[--i]);
	}
}

/*
 *  ���O���t�H�[�}�b�g�p���C�u�����֐�
 */
static char const raddec[] = "0123456789";
static char const radhex[] = "0123456789abcdef";
static char const radHEX[] = "0123456789ABCDEF";

void
syslog_print(SYSLOG *p_syslog, void (*putc)(char))
{
	char const	*format;
	int	argno;
	int	c;
	int	width;
	int	padzero;
	long	val;
	char const	*str;

	format = (char const *)(p_syslog->loginfo[0]);
	argno = 1;

	while ((c = *format++) != '\0') {
		if (c != '%') {
			(*putc)((char) c);
			continue;
		}

		width = padzero = 0;
		if ((c = *format++) == '0') {
			padzero = 1;
			c = *format++;
		}
		while ('0' <= c && c <= '9') {
			width = width*10 + c - '0';
			c = *format++;
		}
		switch (c) {
		case 'd':
			val = (long)(p_syslog->loginfo[argno++]);
			if (val >= 0) {
				convert(val, 10, raddec, width,
						0, padzero, putc);
			}
			else {
				convert(-val, 10, raddec, width,
						1, padzero, putc);
			}
			break;
		case 'u':
			val = (long)(p_syslog->loginfo[argno++]);
			convert(val, 10, raddec, width, 0, padzero, putc);
			break;
		case 'x':
			val = (long)(p_syslog->loginfo[argno++]);
			convert(val, 16, radhex, width, 0, padzero, putc);
			break;
		case 'X':
			val = (long)(p_syslog->loginfo[argno++]);
			convert(val, 16, radHEX, width, 0, padzero, putc);
			break;
		case 'c':
			(*putc)((char)(int)(p_syslog->loginfo[argno++]));
			break;
		case 's':
			str = (char const *)(p_syslog->loginfo[argno++]);
			while ((c = *str++) != '\0') {
				(*putc)((char) c);
			}
			break;
		case '%':
			(*putc)('%');
			break;
		case '\0':
			format--;
			break;
		default:
			break;
		}
	}
}

