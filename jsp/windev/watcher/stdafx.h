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
 *  @(#) $Id: stdafx.h,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���A
//            �܂��͎Q�Ɖ񐔂������A�����܂�ύX����Ȃ�
//            �v���W�F�N�g��p�̃C���N���[�h �t�@�C�����L�q���܂��B

#if !defined(AFX_STDAFX_H__D427C5C9_3DF2_4C06_BC74_B35DCF7062FC__INCLUDED_)
#define AFX_STDAFX_H__D427C5C9_3DF2_4C06_BC74_B35DCF7062FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
// CComModule �N���X����h�������N���X���g�p���āA�I�[�o�[���C�h����ꍇ
// _Module �̖��O�͕ύX���Ȃ��ł��������B
extern CComModule _Module;
#include <atlcom.h>
#include <atlctl.h>


/*
 *  ITRON�f�o�b�M���O�C���^�t�F�[�X�֘A�̒�`
 */

/*
 *  �f�B�X�p�b�`���
 */
#define DSP_NORMAL		0;	//�^�X�N�R���e�L�X�g����̃f�B�X�p�b�`
#define DSP_NONTSKCTX	1;	//�����ݏ��������CPU��O����̃f�B�X�p�b�` 

typedef	short		 BITMASK;
typedef unsigned int INHNO;

/* �����݃n���h�� */
typedef struct t_rglog_interrupt{
	int inhno;	//�����݃n���h���ԍ�
} T_RGLOG_INTERRUPT;

/* �����݃T�[�r�X�n���h��(���g�p) */
typedef struct t_rglog_isr {
	int		isrid;	//�����݃T�[�r�X���[�`��ID
	int     inhno;	//�����݃n���h���ԍ�
} T_RGLOG_ISR;

/* �^�C���C�x���g�n���h�� */
typedef struct t_rglog_timerhdr {
	unsigned int	type;	//�^�C�}�[�̎��
	int             hdrid;	//�^�C���C�x���g�n���h����ID
	void *          exinf;	//�g�����
} T_RGLOG_TIMERHDR;

/* CPU��O�n���h�� */
typedef struct t_rglog_cupexc {
	int		tskid;	//�ΏۂƂȂ�^�X�NID
} T_RGLOG_CPUEXC;

/* �^�X�N��O�������[�`�� */
typedef struct t_rglog_tskexc {
	int		tskid;	//�ΏۂƂȂ�^�X�NID
} T_RGLOG_TSKEXC;

/* �^�X�N��ԕω� */
typedef struct t_rglog_tskstat {
	int		tskid;		//�^�X�NID
	int		tskstat;	//�J�ڐ�^�X�N���
	int		tskwait;	//�҂����
	int		wobjid;		//�҂��Ώۂ̃I�u�W�F�N�gID
} T_RGLOG_TSKSTAT;

/* �f�B�X�p�b�`���J�n */
typedef struct t_rglog_dispatch_enter {
	int				tskid;		//�^�X�NID
	unsigned int	disptype;	//�f�B�X�p�b�`���
} T_RGLOG_DISPATCH_ENTER;

/* �f�B�X�p�b�`���I�� */
typedef struct t_rglog_dispatch_leave {
	int		tskid;		//�^�X�NID
} T_RGLOG_DISPATCH_LEAVE;

/* �T�[�r�X�R�[�� */
typedef struct t_rglog_svc {
	int				fncno;		//�@�\�R�[�h
	unsigned int	prmcnt;		//�p�����[�^��
	void *			prmary[1];	//�p�����[�^
} T_RGLOG_SVC;

/* �R�����g�i������݂̂̃��O�j */
typedef struct t_rglog_comment {
	unsigned int	length;		//������̒���
	char			strtext[1];	//������(NULL�I�[)-���f����
} T_RGLOG_COMMENT;

typedef struct t_rglog_header {
	unsigned int	logtype;
	unsigned int	logtim;
	unsigned int	valid;
	unsigned int	bufsz;
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
	unsigned int logtype;
	unsigned int logtim;
	unsigned int valid;
	unsigned int bufsz;
	char		 buf[1];
} T_RGLOG;

/*
 *  ���O���̎�ʂ̒�`
 */
#define LOG_TYP_INTERRUPT	0x01	/* �����݃n���h�� */
#define LOG_TYP_ISR			0x02	/* �����݃T�[�r�X�n���h�� */
#define LOG_TYP_TIMERHDR	0x03	/* �^�C���C�x���g�n���h�� */
#define LOG_TYP_CPUEXC		0x04	/* CPU��O�n���h�� */
#define LOG_TYP_TSKEXC		0x05	/* �^�X�N��O�������[�`�� */
#define LOG_TYP_TSKSTAT		0x06	/* �^�X�N��ԕω� */
#define LOG_TYP_DISPATCH	0x07	/* �f�B�X�p�b�`�� */
#define LOG_TYP_SVC			0x08	/* �T�[�r�X�R�[�� */
#define LOG_TYP_COMMENT		0x09	/* �R�����g�i������݂̂̃��O�j */
#define LOG_ENTER			0x00	/* �����^�J�n */
#define LOG_LEAVE			0x80	/* �o���^�I�� */

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_STDAFX_H__D427C5C9_3DF2_4C06_BC74_B35DCF7062FC__INCLUDED)
