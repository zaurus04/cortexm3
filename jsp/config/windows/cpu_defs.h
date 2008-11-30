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
 *  @(#) $Id: cpu_defs.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


/*
 *	�v���Z�b�T�Ɉˑ������`�iWindows�p�j
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

#define OMIT_SIL_ACCESS

#define WINDOWS

#define INT_NUMINTERRUPTS	7	/* �����ݖ{�� */

#ifndef _MACRO_ONLY

#include <itron.h>
#include <vwindows.h>

typedef	UINT		INHNO;		/* �����݃n���h���ԍ� */
typedef	UINT		EXCNO;		/* CPU��O�n���h���ԍ� */

/*
 * �����݃G�~�����[�V�����֘A
 */

#define INT_STAT_MASK		0x0000ffffu
#define INT_STAT_PENDING	0x00000001u
#define INT_STAT_RUNNING	0x00000002u
#define INT_STAT_ENABLED	0x00000004u

#define INT_MOD_MASK		0xff000000u
#define INT_MOD_LOGMASK		0x01000000u

struct tagInterruptLevel
{
	HANDLE			ThreadHandle;
	DWORD			ThreadID;
	void *			Routine;
	unsigned int	Flags;
};

extern struct tagInterruptLevel InterruptLevel[INT_NUMINTERRUPTS];
extern unsigned int             CurrentInterruptLevel;

/*  ��O�֘A�̒�` */

#define EXC_MAXITEMS 32

struct tagExceptionLevel
{
	DWORD ExceptionCode;
	void * Routine;
};

extern struct tagExceptionLevel ExceptionLevel[EXC_MAXITEMS];

/*
 * �����݃G�~�����[�V�����p����֐�
 */

extern BOOL			def_int( unsigned int ims, void * rtn);	/* �n���h����` */
extern BOOL			ini_int( void );				/* ������ */
extern void			fin_int( void );
extern BOOL			ras_int(unsigned int ims);		/* �����ݗv�� */
extern unsigned int sns_int( void );				/* Sense the highest pending request */
extern HANDLE		sch_int( void );				/* ���荞�݂̃X�P�W���[�� */

extern BOOL			set_intlogmask( unsigned int ims, BOOL mask );

 /* ���Ƌ֎~�͈����Ɋ֌W�Ȃ��S����&�S�֎~�ƂȂ� */
extern ER	ena_int(unsigned int ims);			/* ���� */
extern ER	dis_int(unsigned int ims);			/* �֎~ */

extern ER	chg_ims(unsigned int ims);			/* �����݃��x���̐ݒ� */
extern ER	get_ims(unsigned int *p_ims);		/* �����݃��x���̎擾 */
extern ER	vget_ims(unsigned int *p_ims);		/* �����݃��x���̎擾 */

extern BOOL def_exc(DWORD exc, void * routine);
extern BOOL ini_exc(void);
extern void fin_exc(void);

	/*
	 * �V�X�e���N���e�B�J���Z�N�V����
	 *   �������CPU���b�N�ŁA�����ɓ����Ă���ԃf�B�X�p�b�`�͔������Ȃ�
	 */
extern void enter_system_critical_section(BOOL *);
extern void leave_system_critiacl_section(BOOL *);

	/* �w�肳�ꂽ�^�X�N���V�X�e���N���e�B�J���Z�N�V�����O�Œ�~������ */
extern ER   wait_for_thread_suspension_completion(HANDLE thread);

    /* �V�~�����[�V�����^�C�}���� */
extern unsigned int current_timer_clock_unit;

    /* �V�~�����[�V���������̃e�B�b�N���C������
     *   clk : ���̃^�C�}�����ݖ��ɉ�����V�~�����[�V��������
     *     (clk = 0 : ���R�Ȓl (TIMER_CLOCK_WINDOWS))
     */
extern ER set_clk(unsigned int clk);

#endif /* _MACRO_ONLY */

/*
 * �^�C�}�[�֘A
 */

#include <hw_timer.h>

/*
 *  �^�C���e�B�b�N�̒�`
 */
#define	TIC_NUME	current_timer_clock_unit	/* �^�C���e�B�b�N�̎����̕��q */
#define	TIC_DENO	1						    /* �^�C���e�B�b�N�̎����̕��� */

#ifndef _MACRO_ONLY

/*
 * �g���^�C�}�[ (Pentium Timer)
 */

typedef UD SYSUTIM;

Inline ER
vxget_tim(SYSUTIM * pk_sysutim)
{
	QueryPerformanceCounter((LARGE_INTEGER *)pk_sysutim);
	return E_OK;
}

#endif /* _MACRO_ONLY */

#endif /* _CPU_DEFS_H_ */
