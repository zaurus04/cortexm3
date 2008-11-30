/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: task.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�^�X�N�Ǘ����W���[��
 */

#ifndef _TASK_H_
#define _TASK_H_

#include "queue.h"
#include "time_event.h"

/*
 *  �^�X�N�D��x�̓����\���E�O���\���ϊ��}�N��
 */
#define INT_PRIORITY(x)		((UINT)((x) - TMIN_TPRI))
#define EXT_TSKPRI(x)		((PRI)(x) + TMIN_TPRI)

/*
 *  �^�X�N��Ԃ̓����\��
 *
 *  TCB ���̃^�X�N��Ԃł́C���s��ԁiRUNNING�j�Ǝ��s�\��ԁiREADY�j
 *  �͋�ʂ��Ȃ��D����Ԃ𑍏̂��āC���s�ł����ԁiRUNNABLE�j�ƌĂԁD
 *  ��d�҂���Ԃ́C(TS_WAITING | TS_SUSPENDED) �ŕ\���DTS_WAIT_???? 
 *  �́C�҂���Ԃɔ����t����Ԃ�\���C�҂���ԁi��d�҂���Ԃ��܂ށj��
 *  �ꍇ�ɂ̂ݐݒ肳���D
 */
#define	TS_DORMANT	0x00u	/* �x�~��� */
#define	TS_RUNNABLE	0x01u	/* ���s�ł����� */
#define	TS_WAITING	0x02u	/* �҂���� */
#define	TS_SUSPENDED	0x04u	/* �����҂���� */

#define	TS_WAIT_SLEEP	0x08u	/* �N���҂���� */
#define	TS_WAIT_WOBJ	0x10u	/* �����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���� */
#define	TS_WAIT_WOBJCB	0x20u	/* ���ʕ����̑҂��L���[�ɂȂ����Ă��� */

/*
 *  �^�X�N��Ԕ��ʃ}�N��
 *
 *  TSTAT_DORMANT �̓^�X�N���x�~��Ԃł��邩�ǂ������CTSTAT_RUNNABLE 
 *  �̓^�X�N�����s�ł����Ԃł��邩�ǂ����𔻕ʂ���DTSTAT_WAITING ��
 *  �҂���ԂƓ�d�҂���Ԃ̂����ꂩ�ł��邩�ǂ������CTSTAT_SUSPENDED 
 *  �͋����҂���ԂƓ�d�҂���Ԃ̂����ꂩ�ł��邩�ǂ����𔻕ʂ���D
 */
#define TSTAT_DORMANT(tstat)	((tstat) == TS_DORMANT)
#define TSTAT_RUNNABLE(tstat)	(((tstat) & TS_RUNNABLE) != 0)
#define TSTAT_WAITING(tstat)	(((tstat) & TS_WAITING) != 0)
#define TSTAT_SUSPENDED(tstat)	(((tstat) & TS_SUSPENDED) != 0)

/*
 *  �҂����u���b�N�iWINFO�j�̒�`
 *
 *  �^�X�N���҂���Ԃ̊Ԃ́CTCB ����т�������w����� WINFO �����̂�
 *  ���ɐݒ肵�Ȃ���΂Ȃ�Ȃ��D
 *
 *  (a) TCB �̃^�X�N��Ԃ�҂���Ԃɂ���D���̍ۂɁC�҂���Ԃɔ����t��
 *  ��ԁiTS_WAIT_????�j���ݒ肷��D
 *
 *  (b) �^�C���A�E�g���Ď����邽�߂ɁC�^�C���C�x���g�u���b�N��o�^����D
 *  �o�^����^�C���C�x���g�u���b�N�́C�҂��ɓ���T�[�r�X�R�[�������֐�
 *  �̃��[�J���ϐ��Ƃ��Ċm�ۂ��C����ւ̃|�C���^�� WINFO �� tmevtb ��
 *  �L������D�^�C���A�E�g�̊Ď����K�v�Ȃ��ꍇ�i�i�v�҂��̏ꍇ�j�ɂ́C
 *  tmevtb �� NULL �ɂ���D
 *
 *  �����E�ʐM�I�u�W�F�N�g�ɑ΂���҂���Ԃ̏ꍇ�ɂ́C�W���� WINFO �� 
 *  wobjcb�t�B�[���h��ǉ������\���́iWINFO_WOBJ�Cwait.h �Œ�`�j���g
 *  ���C�^�X�N��Ԃ� TS_WAIT_WOBJ ��ݒ肷��D�܂��C�ȉ��� (c)�`(e) ��
 *  �ݒ���s���K�v������D�����E�ʐM�I�u�W�F�N�g�Ɋ֌W���Ȃ��҂��i�N��
 *  �҂��C���Ԍo�ߑ҂��j�̏ꍇ�ɂ́C(c)�`(e) �͕K�v�Ȃ��D
 *
 *  (c) TCB ��҂��Ώۂ̓����E�ʐM�I�u�W�F�N�g�̑҂��L���[�ɂȂ��D��
 *  ���L���[�ɂȂ����߂ɁCtask_queue ���g���DTCB �𓯊��E�ʐM�I�u�W�F
 *  �N�g�̊Ǘ��u���b�N�̋��ʕ����iWOBJCB�j�̑҂��L���[�ɂȂ����ꍇ��
 *  �́C�^�X�N��Ԃ� TS_WAIT_WOBJCB ��ݒ肷��D
 *
 *  (d) �҂��Ώۂ̓����E�ʐM�I�u�W�F�N�g�̊Ǘ��u���b�N�ւ̃|�C���^���C
 *  WINFO_WOBJ �� wobjcb �ɋL������D
 *  JSP�J�[�l���� wobjcb ���g���̂́C�D��x���̑҂��L���[�ɂȂ����
 *  ����^�X�N�̗D��x���ύX���ꂽ�ꍇ�݂̂ł��邪�C�f�o�b�O�������
 *  �o���₷���悤�ɁC�҂��L���[���D��x���łȂ��ꍇ�ɂ� wobjcb ��ݒ�
 *  ����D
 *
 *  (e) �҂��Ώۂ̓����E�ʐM�I�u�W�F�N�g�Ɉˑ����ċL�����邱�Ƃ��K�v��
 *  ��񂪂���ꍇ�ɂ́CWINFO_WOBJ �ɕK�v�ȏ��̂��߂̃t�B�[���h��ǉ�
 *  �����\���̂��`���CWINFO_WOBJ �̑���ɗp����D
 *
 *  �҂���Ԃ���������ۂɂ́C�҂����������^�X�N����̕Ԓl�� WINFO ��
 *  wercd �ɐݒ肷��Dwercd ���g���̂͑҂������ȍ~�ł���̂ɑ΂��āC
 *  tmevtb �͑҂�������͎g��Ȃ����߁C�������ߖ�̂��߂ɋ��p�́iunion�j
 *  ���g���Ă���D
 */
typedef union waiting_information {
	ER	wercd;		/* �҂��������̃G���[�R�[�h */
	TMEVTB	*tmevtb;	/* �҂���ԗp�̃^�C���C�x���g�u���b�N */
} WINFO;

/*
 *  �^�X�N�������u���b�N
 *
 *  �^�X�N�Ɋւ�������C�l���ς��Ȃ����߂�ROM�ɒu���镔���i�^�X�N
 *  �������u���b�N�j�ƁC�l���ω����邽�߂�RAM�ɒu���Ȃ���΂Ȃ�Ȃ���
 *  ���i�^�X�N�Ǘ��u���b�N�CTCB�j�ɕ������CTCB���ɑΉ�����^�X�N������
 *  �u���b�N���w���|�C���^������D�^�X�N�������u���b�N���ɑΉ�����
 *  TCB���w���|�C���^��������@�̕����CRAM�̐ߖ�̊ϓ_����͖]�܂���
 *  ���C���s�����������Ȃ邽�߂ɍ̗p���Ă��Ȃ��D���̃I�u�W�F�N�g�ɂ�
 *  �Ă����l�Ɉ����D
 *  �^�X�N�������u���b�N�ɂ́CDEF_TEX �Œ�`�����^�X�N��O�������[�`
 *  ���Ɋւ�������܂ށD
 */
typedef struct task_initialization_block {
	ATR	tskatr;		/* �^�X�N���� */
	VP_INT	exinf;		/* �^�X�N�̊g����� */
	FP	task;		/* �^�X�N�̋N���Ԓn */
	UINT	ipriority;	/* �^�X�N�̋N�����D��x�i�����\���j */
	SIZE	stksz;		/* �X�^�b�N�̈�̃T�C�Y�i�ۂ߂��l�j */
	VP	stk;		/* �X�^�b�N�̈�̐擪�Ԓn */

	ATR	texatr;		/* �^�X�N��O�������[�`������ */
	FP	texrtn;		/* �^�X�N��O�������[�`���̋N���Ԓn */
} TINIB;

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 *
 *  TCB ���̃t�B�[���h�̔z�u�́C���\�ɑ傫���e������Ǝv���邽�߁C�^�[
 *  �Q�b�g�ˑ��Ƀt�B�[���h�̃r�b�g����ύX���邱�Ƃ������Ă���D
 */
#ifndef TBIT_TCB_TSTAT
#define	TBIT_TCB_TSTAT		6	/* tstat �t�B�[���h�̃r�b�g�� */
#endif /* TBIT_TCB_TSTAT */

#ifndef TBIT_TCB_PRIORITY
#define	TBIT_TCB_PRIORITY	4	/* priority �t�B�[���h�̃r�b�g�� */
#endif /* TBIT_TCB_PRIORITY */

/*
 *  �^�X�N�Ǘ��u���b�N�iTCB�j
 *
 *  JSP�ł́C�^�X�N�̋N���v���L���[�C���O���̍ő�l�iTMAX_ACTCNT�j�ƋN
 *  ���v���L���[�C���O���̍ő�l�iTMAX_WUPCNT�j�� 1 �ɌŒ肳��Ă��邽
 *  �߁C�L���[�C���O����Ă��邩�ǂ����̐^�U�l�ŕ\�����邱�Ƃ��ł���D
 *  �܂��C�����҂��v���l�X�g���̍ő�l�iTMAX_SUSCNT�j�� 1 �ɌŒ肳���
 *  ����̂ŁC�����҂��v���l�X�g���isuscnt�j�͕K�v�Ȃ��D
 */
typedef struct task_control_block {
	QUEUE	task_queue;	/* �^�X�N�L���[ */
	const TINIB *tinib;	/* �^�X�N�������u���b�N�ւ̃|�C���^ */

	unsigned int	tstat : TBIT_TCB_TSTAT;	/* �^�X�N��ԁi�����\���j*/
	unsigned int	priority : TBIT_TCB_PRIORITY;
						/* ���݂̗D��x�i�����\���j*/
	unsigned int	actcnt : 1;		/* �N���v���L���[�C���O */
	unsigned int	wupcnt : 1;		/* �N���v���L���[�C���O */
	unsigned int	enatex : 1;		/* �^�X�N��O��������� */

	TEXPTN	texptn;		/* �ۗ���O�v�� */
	WINFO	*winfo;		/* �҂����u���b�N�ւ̃|�C���^ */
	CTXB	tskctxb;	/* �^�X�N�R���e�L�X�g�u���b�N */
} TCB;

/*
 *  ���s��Ԃ̃^�X�N
 *
 *  ���s��Ԃ̃^�X�N�i���v���Z�b�T���R���e�L�X�g�������Ă���^�X�N�j��
 *  TCB ���w���|�C���^�D���s��Ԃ̃^�X�N���Ȃ��ꍇ�� NULL �ɂ���D
 *  �T�[�r�X�R�[���̏������ŁC���^�X�N�i�T�[�r�X�R�[�����Ăяo�����^�X
 *  �N�j�Ɋւ�������Q�Ƃ���ꍇ�� runtsk ���g���Druntsk ����������
 *  ��̂́C�f�B�X�p�b�`���i�Ə����������j�݂̂ł���D
 */
extern TCB	*runtsk;

/*
 *  �ō��D�揇�ʂ̃^�X�N
 *
 *  ���s�ł���^�X�N�̒��ōō��D�揇�ʂ̃^�X�N�� TCB ���w���|�C���^�D��
 *  �s�ł���^�X�N���Ȃ��ꍇ�� NULL �ɂ���D
 *  �f�B�X�p�b�`�֎~��ԂȂǁC�f�B�X�p�b�`���ۗ�����Ă���Ԃ́Cruntsk
 *  �ƈ�v���Ă���Ƃ͌���Ȃ��D
 */
extern TCB	*schedtsk;

/*
 *  �f�B�X�p�b�`�^�^�X�N��O�������[�`���N���v���t���O
 *
 *  �����݃n���h���^CPU��O�n���h���̏o�������ɁC�f�B�X�p�b�`�܂���
 *  �^�X�N��O�������[�`���̋N����v�����邱�Ƃ������t���O�D
 */
extern BOOL	reqflg;

/*
 *  �f�B�X�p�b�`�����
 *
 *  �f�B�X�p�b�`����Ԃł���i���Ȃ킿�C�f�B�X�p�b�`�֎~��ԂłȂ��j
 *  ���Ƃ������t���O�D
 */
extern BOOL	enadsp;

/*
 *  ���f�B�L���[
 *
 *  ���f�B�L���[�́C���s�ł����Ԃ̃^�X�N���Ǘ����邽�߂̃L���[�ł���D
 *  ���s��Ԃ̃^�X�N���Ǘ����Ă��邽�߁C���f�B�i���s�\�j�L���[�Ƃ���
 *  ���̂͐��m�ł͂Ȃ����C���f�B�L���[�Ƃ������̂��蒅���Ă��邽�߁C��
 *  �̖��̂ŌĂԂ��Ƃɂ���D
 *
 *  ���f�B�L���[�́C�D��x���Ƃ̃^�X�N�L���[�ō\������Ă���D�^�X�N��
 *  TCB�́C�Y������D��x�̃L���[�ɓo�^�����D
 */
extern QUEUE	ready_queue[TNUM_TPRI];

/*
 *  ���f�B�L���[�T�[�`�̂��߂̃r�b�g�}�b�v
 *
 *  ���f�B�L���[�̃T�[�`�������悭�s�����߂ɁC�D��x���Ƃ̃^�X�N�L���[
 *  �Ƀ^�X�N�������Ă��邩�ǂ����������r�b�g�}�b�v��p�ӂ��Ă���D�r�b
 *  �g�}�b�v���g�����ƂŁC�������A�N�Z�X�̉񐔂����炷���Ƃ��ł��邪�C
 *  �r�b�g���얽�߂��[�����Ă��Ȃ��v���Z�b�T�ŁC�D��x�̒i�K�������Ȃ�
 *  �ꍇ�ɂ́C�r�b�g�}�b�v����̃I�[�o�[�w�b�h�̂��߂ɁC�t�Ɍ���������
 *  ��\��������D
 */
extern UINT	ready_primap;

/*
 *  �^�X�NID�̍ő�l�ikernel_cfg.c�j
 */
extern const ID	tmax_tskid;

/*
 *  �^�X�N�������u���b�N�̃G���A�ikernel_cfg.c�j
 */
extern const TINIB	tinib_table[];

/*
 *  �^�X�N���������e�[�u���ikernel_cfg.c�j
 */
extern const ID	torder_table[];

/*
 *  TCB�̃G���A�ikernel_cfg.c�j
 */
extern TCB	tcb_table[];

/*
 *  �^�X�N�̐�
 */
#define TNUM_TSK	((UINT)(tmax_tskid - TMIN_TSKID + 1))

/*
 *  �^�X�NID����TCB�����o�����߂̃}�N��
 */
#define INDEX_TSK(tskid)	((UINT)((tskid) - TMIN_TSKID))
#define get_tcb(tskid)		(&(tcb_table[INDEX_TSK(tskid)]))
#define get_tcb_self(tskid)	((tskid) == TSK_SELF ? runtsk : get_tcb(tskid))

/*
 *  TCB����^�X�NID�����o�����߂̃}�N��
 */
#define	TSKID(tcb)	((ID)(((tcb) - tcb_table) + TMIN_TSKID))

/*
 *  �^�X�N�Ǘ����W���[���̏�����
 */
extern void	task_initialize(void);

/*
 *  �ō��D�揇�ʃ^�X�N�̃T�[�`
 *
 *  ���f�B�L���[���̍ō��D�揇�ʂ̃^�X�N���T�[�`���C����TCB�ւ̃|�C���^
 *  ��Ԃ��D���f�B�L���[����̏ꍇ�ɂ́C���̊֐����Ăяo���Ă͂Ȃ�Ȃ��D
 */
extern TCB	*search_schedtsk(void);

/*
 *  ���s�ł����Ԃւ̈ڍs
 *
 *  tcb �Ŏw�肳���^�X�N�̏�Ԃ����s�ł����ԂƂ��C���f�B�L���[�ɑ}
 *  ������D���s�ł����ԂɂȂ����^�X�N�̗D��x���C�ō��D�揇�ʂ̃^�X
 *  �N�̗D��x���������ꍇ�́C�ō��D�揇�ʂ̃^�X�N���X�V���C�f�B�X�p�b
 *  �`����Ԃł���� TRUE ��Ԃ��D�����łȂ��ꍇ�� FALSE ��Ԃ��D
 */
extern BOOL	make_runnable(TCB *tcb);

/*
 *  ���s�ł����Ԃ��瑼�̏�Ԃւ̈ڍs
 *
 *  tcb �Ŏw�肳���^�X�N�����f�B�L���[����폜����Dtcb �Ŏw�肵���^
 *  �X�N���ō��D�揇�ʂ̃^�X�N�ł������ꍇ�ɂ́C�ō��D�揇�ʂ̃^�X�N��
 *  �ݒ肵�Ȃ����C�f�B�X�p�b�`����Ԃł���� TRUE ��Ԃ��D�����łȂ�
 *  �ꍇ�� FALSE ��Ԃ��D�^�X�N�̏�Ԃ͍X�V���Ȃ��D
 */
extern BOOL	make_non_runnable(TCB *tcb);

/*
 *  �x�~��Ԃւ̈ڍs
 *
 *  tcb �Ŏw�肳���^�X�N�̏�Ԃ��x�~��ԂƂ���D�܂��C�^�X�N�̋N����
 *  �ɏ��������ׂ��ϐ��̏������ƁC�^�X�N�N���̂��߂̃R���e�L�X�g��ݒ�
 *  ����D
 */
extern void	make_dormant(TCB *tcb);

/*
 *  �x�~��Ԃ�����s�ł����Ԃւ̈ڍs
 *
 *  tcb �Ŏw�肳���^�X�N�̏�Ԃ��x�~��Ԃ�����s�ł����ԂƂ���D��
 *  �s�ł����ԂɈڍs�����^�X�N�ւ̃f�B�X�p�b�`���K�v�ȏꍇ�� TRUE�C
 *  �����łȂ��ꍇ�� FALSE ��Ԃ��D
 */
extern BOOL	make_active(TCB *tcb);

/*
 *  ���s��Ԃ̃^�X�N�̏I��
 *
 *  exit_task �� ext_tsk �ɖ��ߍ��܂��ɕʂ̊֐��ɂ��Ă���̂́C
 *  create_context �� activate_context �����^�X�N�̏I�������Ŏg�p����
 *  �X�^�b�N��j�󂵂Ȃ��悤�ɂ��邽�߂̑΍�̈�ł���Dext_tsk �Ƃ�
 *  �ʊ֐��ɂ��Ă������ƂŁC���[�J���ϐ����܂߂āC�g�p����X�^�b�N�̈�
 *  ���d�Ȃ�Ȃ��悤�ɂł���D�܂��C�R���p�C���������I�ɃC�����C���W�J
 *  ����̂�����邽�߂ɁCext_tsk �Ƃ͕ʂ̃t�@�C���ɓ���Ă���D
 */
extern void	exit_task(void);

/*
 *  ���f�B�L���[���̃^�X�N�̗D��x�̕ύX
 *
 *  tcb �Ŏw�肳��郌�f�B�L���[���̃^�X�N�̗D��x�� newpri�i�����\���j
 *  �ɕύX����D�܂��C�K�v�ȏꍇ�ɂ͍ō��D�揇�ʂ̃^�X�N���X�V���C�f�B
 *  �X�p�b�`����Ԃł���� TRUE ��Ԃ��D�����łȂ��ꍇ�� FALSE ���
 *  ���D
 */
extern BOOL	change_priority(TCB *tcb, UINT newpri);

/*
 *  ���f�B�L���[�̉�]
 *
 *  ���f�B�L���[���́Cpri �Ŏw�肳���D��x�̃^�X�N�L���[����]������D
 *  �܂��C�K�v�ȏꍇ�ɂ͍ō��D�揇�ʂ̃^�X�N��ύX���C�f�B�X�p�b�`����
 *  ������Ă��Ȃ���� TRUE ��Ԃ��D�����łȂ��ꍇ�� FALSE ��Ԃ��D
 */
extern BOOL	rotate_ready_queue(UINT pri);

/*
 *  �^�X�N��O�������[�`���̌ďo��
 *
 *  �^�X�N��O�������[�`�����Ăяo���D�Ăяo���O�ɁC���s��Ԃ̃^�X�N��
 *  �ۗ���O�v�����N���A���C�^�X�N��O�����֎~��Ԃɂ��CCPU���b�N����
 *  ������D
 *  �^�X�N��O�������[�`������߂�ƁC�܂�CPU���b�N��Ԃɖ߂��C���̊�
 *  �ɕۗ���O�v���� 0 �łȂ��Ȃ��Ă���΁C�Ăу^�X�N��O�������[�`��
 *  ���Ăяo���D�ۗ���O�v���� 0 �̏ꍇ�ɂ́C��O��������Ԃɂ��Ċ�
 *  �����烊�^�[������D
 *  ���̊֐��́C���s��Ԃ̃^�X�N���C�^�X�N��O��������ԁienatex �� 
 *  TRUE�j�ŁC�ۗ���O�v���� 0 �łȂ��itexptn �� 0 �łȂ��j�ꍇ�ɌĂ�
 *  �o�����Ƃ�z�肵�Ă���D���̊֐��́CCPU���b�N��ԂŌĂяo���Ȃ���
 *  �΂Ȃ�Ȃ��D
 */
extern void	call_texrtn(void);

/*
 *  �^�X�N��O�������[�`���̋N��
 *
 *  ���s��Ԃ̃^�X�N���^�X�N��O�������[�`���̋N�������𖞂����Ă���΁C
 *  �^�X�N��O�������[�`�����Ăяo���DCPU��O�������[�`�����Ăяo����
 *  �́C�ꎞ�I��CPU���b�N����������D
 *  ���̊֐��́C�f�B�X�p�b�`���⊄���݃n���h���^CPU��O�n���h���̏o��
 *  ��������Ăяo����邱�Ƃ�z�肵�Ă��邪�C�����̏������^�[�Q�b�g��
 *  �����ŋL�q���Ă��悢�D���̏ꍇ�ɂ́COMIT_CALLTEX ���}�N����`����
 *  �΂悢�D
 */
extern void	calltex(void);

#endif /* _TASK_H_ */
