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
 *  @(#) $Id: newlibrt.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */
#include <stddef.h>
#include <reent.h>
#include <errno.h>
#include "../kernel/jsp_kernel.h"

#ifndef	HEAP_TOP
#define	HEAP_TOP		~0UL
#endif

/*
 *	For malloc (Newlib)
 */
static int cxxrt_dis_dsp;

void __malloc_lock(struct _reent *ptr)
{
	if (!iniflg || sns_dsp())
		return;
	dis_dsp();
	cxxrt_dis_dsp = 1;
}

void __malloc_unlock(struct _reent *ptr)
{
	if (!cxxrt_dis_dsp)
		return;
	cxxrt_dis_dsp = 0;
	ena_dsp();
}

void *_sbrk_r(struct _reent *ptr, ptrdiff_t nbyte)
{
	extern char end;
	static char *heap_ptr = &end;
	static char *heap_end = (char*)HEAP_TOP;
	char *base;

	if (!iniflg)
	{
		volatile char _auto;
		if (&end < &_auto && &_auto < heap_end)
			heap_end = (char*)&_auto;
	}

	if (heap_ptr + nbyte + 32 > heap_end)
	{
		ptr->_errno = errno = ENOMEM;
		return (void*)-1;
	}

	base = heap_ptr;
	heap_ptr += nbyte;
	return base;
}

/*
 *	For program termination
 */
#define	ATEXIT_MAX	(32 + 1)

static void (*atexit_table[ATEXIT_MAX])(void);
static int atexit_num;

/*
 * abort���ɍŏ��Ɍďo�����t�b�N
 * raise(SIGABRT)���ďo���悤�ɂ���΁A�z�X�g���Ƃ̌݊����Ƃ邱�Ƃ��\�ɂȂ�B
 */
void (*_atabort)(void) = 0;

int atexit(void (*func)(void))
{
	int result = -1;
	int sync = iniflg;

	if (sync)
		loc_cpu();

	if (atexit_num < ATEXIT_MAX)
	{
		atexit_table[atexit_num++] = func;
		result = 0;
	}

	if (sync)
		unl_cpu();

	return result;
}

void exit(int status)
{
	if (iniflg)
		kernel_exit();
	_exit(status);
}

void abort(void)
{
	if (_atabort != 0)
		(*_atabort)();
	if (iniflg)
		kernel_abort();
	_exit(3);
}

/*
 *	For software hooks
 */
void software_init_hook(void)
{
	extern void _toppers_cxxrt_init(void);
	_toppers_cxxrt_init();
	{
#ifdef	__ELF__
		extern void _init(void);
		extern void _fini(void);
		atexit(_fini);
		_init();
#else
		extern void __main(void);
		__main();
#endif
	}
}

void software_term_hook(void)
{
	int i;

	for (i = atexit_num - 1; i >= 0; i--)
		(*atexit_table[i])();
}

/* �����N�����p�̃_�~�[ */
int main() { return 0; }

