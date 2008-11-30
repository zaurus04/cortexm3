/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Takagi Nobuhisa
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
 *  @(#) $Id: cxxrt.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */
#include "../kernel/jsp_kernel.h"
#include "../kernel/task.h"
#include "kernel_id.h"

typedef int _toppers_cxxrt_sync_t;
typedef volatile char _toppers_cxxrt_once_t;

static inline int _get_tid()
{
	return runtsk - tcb_table + TMIN_TSKID;
}

/*
 *	For Syncronization
 */
int _toppers_cxxrt_lock(_toppers_cxxrt_sync_t *sync)
{
	if (iniflg)
		dis_dsp();
	return 0;
}

int _toppers_cxxrt_trylock(_toppers_cxxrt_sync_t *sync)
{
	return _toppers_cxxrt_lock(sync);
}

int _toppers_cxxrt_unlock(_toppers_cxxrt_sync_t *sync)
{
	if (iniflg)
		ena_dsp();
	return 0;
}

int _toppers_cxxrt_get_tskid(void)
{
	return iniflg ? _get_tid() : 0;
}

/*
 *	For recursive semaphore lock
 */
static ID cxxrt_holder;
static UINT cxxrt_counter;

static inline void _toppers_cxxrt_recursive_semaphore_lock(ID semid)
{
	if (iniflg && !sns_dsp())
	{
		ID tskid;
		tskid = _get_tid();

		if (cxxrt_holder != tskid)
		{
			wai_sem(semid);
			cxxrt_holder = tskid;
		}
		++cxxrt_counter;
	}
}

static inline void _toppers_cxxrt_recursive_semaphore_unlock(ID semid)
{
	if (iniflg && !sns_dsp())
	{
		if (--cxxrt_counter == 0)
		{
			cxxrt_holder = 0;
			sig_sem(semid);
		}
	}
}


/*
 *	For function call once
 */
int _toppers_cxxrt_once(_toppers_cxxrt_once_t *once, void (*func)(void))
{
	if (!*once)
	{
		static _toppers_cxxrt_sync_t sync;

		_toppers_cxxrt_recursive_semaphore_lock(_CXXRT_SEM);
		if (!*once)
		{
			(*func)();
			*once = 1;
		}
		_toppers_cxxrt_recursive_semaphore_unlock(_CXXRT_SEM);
	}
	return 0;
}


/*
 *	For task-local storage
 */
#ifndef CXXRT_KEY_MAX
#define CXXRT_KEY_MAX	2
#endif

struct _toppers_cxxrt_tls
{
	void **data;
	void (*dtor)(void*);
};

extern const ID tmax_tskid;

static void **tls_data[CXXRT_KEY_MAX];
static struct _toppers_cxxrt_tls tls[CXXRT_KEY_MAX];

int _toppers_cxxrt_key_create(struct _toppers_cxxrt_tls **key, void (*dtor)(void*))
{
	struct _toppers_cxxrt_tls *p;

	for (p = &tls[0]; p < &tls[CXXRT_KEY_MAX]; p++)
	{
		if (p->data == NULL)
		{
			p->data = tls_data[p - &tls[0]];
			p->dtor = dtor;
			*key = p;
			return 0;
		}
	}
	return -1;
}

int _toppers_cxxrt_key_delete(struct _toppers_cxxrt_tls *key)
{
	int i;

	for (i = 0; i <= tmax_tskid; i++)
	{
		if (key->dtor != 0)
			(*key->dtor)(key->data[i]);
	}
	key->data = NULL;
	key->dtor = 0;
	return 0;
}

/* JSP 1.4�Ƃ̌݊����̂��߂�_toppers_cxxrt_reset_specific���c���Ă��� */
void _toppers_cxxrt_reset_specific(void)
{
}

void _toppers_cxxrt_init(void)
{
	int i, tmax = tmax_tskid + 1;
	void **p = (void**)malloc(sizeof(void*) * CXXRT_KEY_MAX * tmax);

	for (i = 0; i < CXXRT_KEY_MAX * tmax; i++)
		p[i] = NULL;
	for (i = 0; i < CXXRT_KEY_MAX; i++)
		tls_data[i] = p + i * tmax;
}

