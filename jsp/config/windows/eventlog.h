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
 *  @(#) $Id: eventlog.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


#ifndef __EVENTLOG_H__
#define __EVENTLOG_H__

#include <constants.h>

#include <stdarg.h>
#include "syslog.h"

	/*
	 *  ITRON�f�o�b�M���O�C���^�t�F�[�X�֘A�̒�`
	 */

	/*
	 *  �f�B�X�p�b�`���
	 */
#define DSP_NORMAL		0;	//�^�X�N�R���e�L�X�g����̃f�B�X�p�b�`
#define DSP_NONTSKCTX	1;	//�����ݏ��������CPU��O����̃f�B�X�p�b�` 

	typedef	W		BITMASK;
	typedef UINT	INHNO;

	/* �����݃n���h�� */
	typedef struct t_rglog_interrupt{
		INHNO	inhno;	//�����݃n���h���ԍ�
	} T_RGLOG_INTERRUPT;

	/* �����݃T�[�r�X�n���h��(���g�p) */
	typedef struct t_rglog_isr {
		ID		isrid;	//�����݃T�[�r�X���[�`��ID
		INHNO	inhno;	//�����݃n���h���ԍ�
	} T_RGLOG_ISR;

	/* �^�C���C�x���g�n���h�� */
	typedef struct t_rglog_timerhdr {
		UINT	type;	//�^�C�}�[�̎��
		ID		hdrid;	//�^�C���C�x���g�n���h����ID
		VP_INT	exinf;	//�g�����
	} T_RGLOG_TIMERHDR;

	/* CPU��O�n���h�� */
	typedef struct t_rglog_cupexc {
		ID		tskid;	//�ΏۂƂȂ�^�X�NID
	} T_RGLOG_CPUEXC;

	/* �^�X�N��O�������[�`�� */
	typedef struct t_rglog_tskexc {
		ID		tskid;	//�ΏۂƂȂ�^�X�NID
	} T_RGLOG_TSKEXC;

	/* �^�X�N��ԕω� */
	typedef struct t_rglog_tskstat {
		ID		tskid;		//�^�X�NID
		STAT	tskstat;	//�J�ڐ�^�X�N���
		STAT	tskwait;	//�҂����
		ID		wobjid;		//�҂��Ώۂ̃I�u�W�F�N�gID
	} T_RGLOG_TSKSTAT;

	/* �f�B�X�p�b�`���J�n */
	typedef struct t_rglog_dispatch_enter {
		ID		tskid;		//�^�X�NID
		UINT	disptype;	//�f�B�X�p�b�`���
	} T_RGLOG_DISPATCH_ENTER;

	/* �f�B�X�p�b�`���I�� */
	typedef struct t_rglog_dispatch_leave {
		ID		tskid;		//�^�X�NID
	} T_RGLOG_DISPATCH_LEAVE;

	/* �T�[�r�X�R�[�� */
	typedef struct t_rglog_svc {
		FN		fncno;		//�@�\�R�[�h
		UINT	prmcnt;		//�p�����[�^��
		VP_INT	prmary[1];	//�p�����[�^
	} T_RGLOG_SVC;

	/* �R�����g�i������݂̂̃��O�j */
	typedef struct t_rglog_comment {
		UINT	length;		//������̒���
		char	strtext[1];	//������(NULL�I�[)-���f����
	} T_RGLOG_COMMENT;

	typedef struct t_rglog_header {
		UINT	logtype;
		SYSTIM	logtim;
		BITMASK	valid;
		UINT	bufsz;
	} T_RGLOG_HEADER;

	typedef union t_rglog_body
	{
		T_RGLOG_INTERRUPT		interrupt;
		T_RGLOG_ISR				isr;
		T_RGLOG_TIMERHDR		timerhdr;
		T_RGLOG_CPUEXC			cpuexc;
		T_RGLOG_TSKEXC			tskexc;
		T_RGLOG_TSKSTAT			tskstat;
		T_RGLOG_DISPATCH_ENTER	dispatch_enter;
		T_RGLOG_DISPATCH_LEAVE	dispatch_leave;
		T_RGLOG_SVC				svc;
		T_RGLOG_COMMENT			comment;
	} T_RGLOG_BODY;

	typedef struct DBIFLOG
	{
		struct	t_rglog_header	header;
		union	t_rglog_body	body;
	} DBIFLOG;

	typedef struct t_rglog
	{
		UINT	logtype;
		SYSTIM	logtim;
		BITMASK	valid;
		UINT	bufsz;
		char	buf[1];
	} T_RGLOG;

#ifdef EVENTLOG_ENABLE
#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN extern
#endif

		EXTERN void event_write_syslog(const SYSLOG * str);
		EXTERN void event_write(unsigned int logtype, unsigned int valid, UINT bufsz, ... );
		EXTERN void event_write_svc_enter(int fncd, unsigned int params, ... );
		EXTERN void event_write_svc_leave(int fncd, unsigned int ercd, unsigned int retaddr);
		EXTERN void event_write_wait_unknown(int tskid);

#undef EXTERN

#endif //EVENTLOG_ENABLE

#endif //__EVENTLOG_H__

