/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005 by Freelines CO.,Ltd
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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�v���Z�b�T�ˑ����W���[���iV850�p�j
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <hw_serial.h>

/*
 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
#ifdef SUPPORT_CHG_IPM
UH	task_intmask;
#endif /* SUPPORT_CHG_IPM */

/*
 *  ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
UH	int_intmask;


/*
 *  �����݃l�X�g�J�E���^
 */

UW	intnest = 0;

/*
 *  �����݃n���h���e�[�u��
 */
INTVE InterruptHandlerEntry[NUM_INTERRUPT];

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize(void)
{
	hw_port_initialize(SERIAL_PORT);
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate(void)
{
}

/*
 * �o�^����Ă��Ȃ����荞�݂���������ƌĂяo�����
 */

void cpu_experr(unsigned int intno)
{
    syslog(LOG_EMERG, "!Unexpected interrupt. [INTNO = %d]", intno);
    __asm("halt");
}

/*
 *   �V�X�e�������o�͐�̎w��
 */

void
cpu_putc(char c)
{
    if (c == '\n') {
        hw_port_wait_putchar(SERIAL_PORT, '\r');
    }
    hw_port_wait_putchar(SERIAL_PORT, c);
}

void *
local_memcpy (void *out, const void *in, unsigned int n)
{
    char *o = out;
    const char *i = in;

    while (n -- > 0)
        *o ++ = *i ++;
    return out;
}
