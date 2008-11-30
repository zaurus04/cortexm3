/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: t_syslog.h,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *	�V�X�e�����O�@�\
 *
 *  �V�X�e�����O�T�[�r�X�́C�V�X�e���̃��O�����o�͂��邽�߂̃T�[�r�X
 *  �ł���D�J�[�l������̃��O���̏o�͂ɂ��p���邽�߁C�����ő҂����
 *  �ɂ͂��邱�Ƃ͂Ȃ��D
 *
 *  ���O���́C�J�[�l�����̃��O�o�b�t�@�ɏ������ނ��C�჌�x���̕����o
 *  �͊֐���p���ďo�͂���D�ǂ�����g�����́C�g���T�[�r�X�R�[���Ő؂�
 *  �����邱�Ƃ��ł���D
 *
 *  ���O�o�b�t�@�̈悪�I�[�o�t���[�����ꍇ�ɂ́C�Â����O���������ď�
 *  ��������D
 *
 *  �A�Z���u������̃\�[�X�t�@�C����V�X�e���R���t�B�M�����[�V�����t�@
 *  �C�����炱�̃t�@�C�����C���N���[�h���鎞�́C_MACRO_ONLY ���`����
 *  �������ƂŁC�}�N����`�ȊO�̋L�q���������Ƃ��ł���D
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h����邱�Ƃ͂Ȃ��D
 *
 *  ���̃t�@�C�����C���N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N
 *  ���[�h���Ă������Ƃ��K�v�ł���D
 */

#ifndef _T_SYSLOG_H_
#define _T_SYSLOG_H_

/*
 *  ���O���̎�ʂ̒�`
 *
 *  LOG_TYPE_CYC�CLOG_TYPE_ASSERT �ȊO�́C�f�o�b�M���O�C���^�t�F�[�X�d
 *  �l�ƍ��v���Ă���D
 */
#define LOG_TYPE_INH		0x01u	/* �����݃n���h�� */
#define LOG_TYPE_ISR		0x02u	/* �����݃T�[�r�X���[�`�� */
#define LOG_TYPE_CYC		0x03u	/* �����n���h�� */
#define LOG_TYPE_EXC		0x04u	/* CPU��O�n���h�� */
#define LOG_TYPE_TEX		0x05u	/* �^�X�N��O�������[�`�� */
#define LOG_TYPE_TSKSTAT	0x06u	/* �^�X�N��ԕω� */
#define LOG_TYPE_DSP		0x07u	/* �f�B�X�p�b�`�� */
#define LOG_TYPE_SVC		0x08u	/* �T�[�r�X�R�[�� */
#define LOG_TYPE_COMMENT	0x09u	/* �R�����g */
#define LOG_TYPE_ASSERT		0x0au	/* �A�T�[�V�����̎��s */

#define LOG_ENTER		0x00u	/* �����^�J�n */
#define LOG_LEAVE		0x80u	/* �o���^�I�� */

/*
 *  ���O���̏d�v�x�̒�`
 */
#define LOG_EMERG	0u		/* �V���b�g�_�E���ɒl����G���[ */
#define LOG_ALERT	1u
#define LOG_CRIT	2u
#define LOG_ERROR	3u		/* �V�X�e���G���[ */
#define LOG_WARNING	4u		/* �x�����b�Z�[�W */
#define LOG_NOTICE	5u
#define LOG_INFO	6u
#define LOG_DEBUG	7u		/* �f�o�b�O�p���b�Z�[�W */

#ifndef _MACRO_ONLY

/*
 *  ���O���̃f�[�^�\��
 */

#define TMAX_LOGINFO	6

typedef struct {
		UINT	logtype;		/* ���O���̎�� */
		SYSTIM	logtim;			/* ���O���� */
		VP_INT	loginfo[TMAX_LOGINFO];	/* ���̑��̃��O��� */
	} SYSLOG;

/*
 *  ���O���̏d�v�x�̃r�b�g�}�b�v����邽�߂̃}�N��
 */
#define LOG_MASK(prio)	(1u << (prio))
#define LOG_UPTO(prio)	((1u << ((prio) + 1)) - 1)

#ifndef OMIT_SYSLOG

/*
 *  ���O���̏o��
 */
extern ER	vwri_log(UINT prio, SYSLOG *p_log) throw();

/*
 *  ���O�o�b�t�@����̃��O���̓Ǐo��
 */
extern ER_UINT	vrea_log(SYSLOG *p_log) throw();

/* 
 *  �o�͂��ׂ����O���̏d�v�x�̐ݒ�
 */
extern ER	vmsk_log(UINT logmask, UINT lowmask) throw();

/*
 *  ���O�����o�͂��邽�߂̃��C�u�����֐�
 */

Inline ER
_syslog_0(UINT prio, UINT type)
{
	SYSLOG	log;

	log.logtype = type;
	return(vwri_log(prio, &log));
}

Inline ER
_syslog_1(UINT prio, UINT type, VP_INT arg1)
{
	SYSLOG	log;

	log.logtype = type;
	log.loginfo[0] = arg1;
	return(vwri_log(prio, &log));
}

Inline ER
_syslog_2(UINT prio, UINT type, VP_INT arg1, VP_INT arg2)
{
	SYSLOG	log;

	log.logtype = type;
	log.loginfo[0] = arg1;
	log.loginfo[1] = arg2;
	return(vwri_log(prio, &log));
}

Inline ER
_syslog_3(UINT prio, UINT type, VP_INT arg1, VP_INT arg2, VP_INT arg3)
{
	SYSLOG	log;

	log.logtype = type;
	log.loginfo[0] = arg1;
	log.loginfo[1] = arg2;
	log.loginfo[2] = arg3;
	return(vwri_log(prio, &log));
}

Inline ER
_syslog_4(UINT prio, UINT type, VP_INT arg1, VP_INT arg2,
				VP_INT arg3, VP_INT arg4)
{
	SYSLOG	log;

	log.logtype = type;
	log.loginfo[0] = arg1;
	log.loginfo[1] = arg2;
	log.loginfo[2] = arg3;
	log.loginfo[3] = arg4;
	return(vwri_log(prio, &log));
}

Inline ER
_syslog_5(UINT prio, UINT type, VP_INT arg1, VP_INT arg2,
				VP_INT arg3, VP_INT arg4, VP_INT arg5)
{
	SYSLOG	log;

	log.logtype = type;
	log.loginfo[0] = arg1;
	log.loginfo[1] = arg2;
	log.loginfo[2] = arg3;
	log.loginfo[3] = arg4;
	log.loginfo[4] = arg5;
	return(vwri_log(prio, &log));
}

Inline ER
_syslog_6(UINT prio, UINT type, VP_INT arg1, VP_INT arg2, VP_INT arg3,
				VP_INT arg4, VP_INT arg5, VP_INT arg6)
{
	SYSLOG	log;

	log.logtype = type;
	log.loginfo[0] = arg1;
	log.loginfo[1] = arg2;
	log.loginfo[2] = arg3;
	log.loginfo[3] = arg4;
	log.loginfo[4] = arg5;
	log.loginfo[5] = arg6;
	return(vwri_log(prio, &log));
}

#else /* OMIT_SYSLOG */

#define vwri_log(prio, p_log)		E_OK
#define vrea_log(p_log)			E_OK
#define vmsk_log(logmask, lowmask)	E_OK

#define _syslog_0(prio, type)						E_OK
#define _syslog_1(prio, type, arg1)					E_OK
#define _syslog_2(prio, type, arg1, arg2)				E_OK
#define _syslog_3(prio, type, arg1, arg2, arg3)				E_OK
#define _syslog_4(prio, type, arg1, arg2, arg3, arg4)			E_OK
#define _syslog_5(prio, type, arg1, arg2, arg3, arg4, arg5)		E_OK
#define _syslog_6(prio, type, arg1, arg2, arg3, arg4, arg5, arg6)	E_OK

#endif /* OMIT_SYSLOG */

/*
 *  ���O���i�R�����g�j���o�͂��邽�߂̃}�N��
 *
 *  format ����ь㑱�̈�������쐬�������b�Z�[�W���C�d��x prio ��
 *  ���O���Ƃ��ďo�͂��邽�߂̃}�N���Darg1�`argn �� VP_INT�^�ɃL��
 *  �X�g���邽�߁CVP_INT�^�Ɍ^�ϊ��ł���C�ӂ̌^�ł悢�D
 */

#define	syslog_0(prio, format) \
		_syslog_1(prio, LOG_TYPE_COMMENT, (VP_INT) format)

#define	syslog_1(prio, format, arg1) \
		_syslog_2(prio, LOG_TYPE_COMMENT, (VP_INT) format, \
							(VP_INT)(arg1))

#define	syslog_2(prio, format, arg1, arg2) \
		_syslog_3(prio, LOG_TYPE_COMMENT, (VP_INT) format, \
					(VP_INT)(arg1), (VP_INT)(arg2))

#define	syslog_3(prio, format, arg1, arg2, arg3) \
		_syslog_4(prio, LOG_TYPE_COMMENT, (VP_INT) format, \
			(VP_INT)(arg1), (VP_INT)(arg2), (VP_INT)(arg3))

#define	syslog_4(prio, format, arg1, arg2, arg3, arg4) \
		_syslog_5(prio, LOG_TYPE_COMMENT, (VP_INT) format, \
			(VP_INT)(arg1), (VP_INT)(arg2), (VP_INT)(arg3), \
							(VP_INT)(arg4))

#define	syslog_5(prio, format, arg1, arg2, arg3, arg4, arg5) \
		_syslog_6(prio, LOG_TYPE_COMMENT, (VP_INT) format, \
			(VP_INT)(arg1), (VP_INT)(arg2), (VP_INT)(arg3), \
					(VP_INT)(arg4), (VP_INT)(arg5))

/*
 *  ���O���i�R�����g�j���o�͂��邽�߂̃��C�u�����֐��ivasyslog.c�j
 */
extern ER	syslog(UINT prio, const char *format, ...) throw();

/* 
 *  ���O���̃t�H�[�}�b�g�o�́ilog_output.c�j
 */
extern void	syslog_printf(const char *format, VP_INT *args,
						void (*putc)(char)) throw();
extern void	syslog_print(SYSLOG *p_log, void (*putc)(char)) throw();
extern void	syslog_output(void (*putc)(char)) throw();

#endif /* _MACRO_ONLY */
#endif /* _T_SYSLOG_H_ */
