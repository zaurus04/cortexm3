/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Katsuhiro Amano
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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

#include <hw_serial.h>

/*
 *  �v���Z�b�T�ˑ����W���[���iH8�p�j
 */

#ifdef SUPPORT_CHG_IPM
/*
 *  �^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */
volatile UB task_intmask = 0;
#endif /* SUPPORT_CHG_IPM */

/*
 *  ��^�X�N�R���e�L�X�g�ł̊����݃}�X�N
 */

volatile UB int_intmask = 0;

/*
 *  �����݃l�X�g�J�E���^
 */

volatile UB intnest = 0;

/*
 *  CPU���b�N��Ԃ�\���t���O
 *�@�@TRUE �FCPU���b�N���
 *�@�@FALSE�FCPU���b�N�������
 */
volatile BOOL iscpulocked = TRUE;

/*
 *  �^�C�}�̃v���C�I���e�B���x���ݒ�p�̃f�[�^
 *      �{����hw_timer.h�ɋL�q����ׂ������A���������
 *      hw_timer.h���C���N���[�h�����t�@�C���ł��ׂĎ��̉������
 *�@�@�@�������̈���L���Ă��܂����߁A���̂͂����ɋL�q����B
 */
const IRC TIMER_IRC = {(UB*)SYSTEM_TIMER_IPR,
                        SYSTEM_TIMER_IP_BIT,
                        SYSTEM_TIMER_IPM
                      };

/*
 *  �x�N�^�e�[�u���̏������ifor RedBoot�j
 */
#ifdef REDBOOT

/*  VECTOR_TABLE_ADDR��sys_config.h�Œ�`����  */
extern void	vector(void);

static void
copy_vector_table(void)
{
	UW n;
	UW *dst = (UW *)VECTOR_TABLE_ADDR;	/* �x�N�^�e�[�u���R�s�[�� */
	UW *src = (UW *)vector;			/* �x�N�^�e�[�u���R�s�[�� */
	TMP_VECTOR tmp_vector;

	load_vector(&tmp_vector);
	for (n = 0; n < VECTOR_SIZE; n++) {
		*dst = JMP_OPECODE | (*src);	/* jmp���߂̕t�� */
		++dst;
		++src;
	}
	save_vector(&tmp_vector);
}
#endif	/* of #ifdef REDBOOT */

/*
 *  �v���Z�b�T�ˑ��̏�����
 */

#ifndef H8IPRA_INI
#define H8IPRA_INI	0
#endif  /*  H8IPRA_INI  */

#ifndef H8IPRB_INI
#define H8IPRB_INI	0
#endif  /*  H8IPRB_INI  */

void
cpu_initialize(void)
{
	/* 
	 *�@CCR ��UI�r�b�g�����荞�݃}�X�N�r�b�g�Ƃ��Ďg�p����B
	 *�@�@SYSCR.UE��0
	 */
	bitclr((UB*)H8SYSCR, H8SYSCR_UE_BIT);
	
	/* 
	 *�@���ׂĂ̊����݃v���C�I���e�B�����x���O�ɂ���
	 *
	 *�@�@�E���j�^��X�^�u�������݂��g�p����ꍇ
	 *�@�@�@�@H8IPRA_INI��H8IPRB_INI���`���āA�ݒ���e��ێ�����B
	 *�@�@�@�@IER���W�X�^�̓J�[�l�����ŕύX���Ă��Ȃ��̂ŁA���̂܂܂�
	 *�@�@�@�@�悢�B
	 */
	sil_wrb_mem((VP)H8IPRA, H8IPRA_INI);
	sil_wrb_mem((VP)H8IPRB, H8IPRB_INI);
	
	SCI_initialize(SYSTEM_PORTID);

#ifdef REDBOOT
	copy_vector_table();
#endif	/* of #ifdef REDBOOT */
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */

void
cpu_terminate(void)
{
}

#ifdef SUPPORT_CHG_IPM
/*
 *  �����݃}�X�N�̕ύX
 *
 *�@IPM�ɐݒ�ł���l�Ƃ���IPM_LEVEL0�AIPM_LEVEL1�AIPM_LEVEL2���}�N��
 *�@��`����Ă���B
 *
 *
 *�@IPM_LEVEL0�F���x���O�@���ׂĂ̊����݂��󂯕t����
 *�@IPM_LEVEL1�F���x���P�@NMI����уv���C�I���e�B���x���P�̊����݂݂̂�
 *�@�@�@�@�@�@�@�@�@�@�@�@�󂯕t����
 *�@IPM_LEVEL2�F���x���Q�@NMI�ȊO�̊����݂��󂯕t���Ȃ�
 *
 *  IPM �����x��0�ȊO�̎��ɂ��C�^�X�N�f�B�X�p�b�`�͕ۗ�����Ȃ��DIPM �́C
 *  �^�X�N�f�B�X�p�b�`�ɂ���āC�V�������s��ԂɂȂ����^�X�N�ֈ����p��
 *  ���D���̂��߁C�^�X�N�����s���ɁC�ʂ̃^�X�N�ɂ���� IPM ���ύX��
 *  ���ꍇ������DJSP�J�[�l���ł́CIPM �̕ύX�̓^�X�N��O�������[�`
 *  ���ɂ���Ă��N����̂ŁC�ʂ̃^�X�N�ɂ���� IPM ���ύX����邱�Ƃ�
 *  ����āC����������Ȃ�󋵂͏��Ȃ��Ǝv����DIPM �̒l�ɂ���ă^
 *  �X�N�f�B�X�p�b�`���֎~�������ꍇ�ɂ́Cdis_dsp �𕹗p����΂悢�D
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
        ER      ercd = E_OK;

        LOG_CHG_IPM_ENTER(ipm);
        CHECK_TSKCTX_UNL();
        CHECK_PAR( (ipm == IPM_LEVEL0) || (ipm == IPM_LEVEL1) || (ipm == IPM_LEVEL2) );

        t_lock_cpu();
        task_intmask = ipm;
        t_unlock_cpu();
        
    exit:
        LOG_CHG_IPM_LEAVE(ercd)
        return(ercd);
}

/*
 *  �����݃}�X�N�̎Q��
 */
SYSCALL ER
get_ipm(IPM *p_ipm)
{
        ER      ercd = E_OK;

        LOG_GET_IPM_ENTER(p_ipm);
        CHECK_TSKCTX_UNL();

        t_lock_cpu();
        *p_ipm = task_intmask;
        t_unlock_cpu();

    exit:
        LOG_GET_IPM_LEAVE(ercd, *p_ipm);
        return(ercd);
}

#endif /* SUPPORT_CHG_IPM */

/*****�ȉ��A���ʕ��Ƃ̃C���^�[�t�F�[�X�Ɋ܂܂�Ȃ�����*********/

/*
 * ����`�����ݔ������̃G���[�o��
 * �@�@�o�^����Ă��Ȃ������݂���������ƌĂяo�����
 * 
 * �@�X�^�b�N�\��
 *�@�@ +0:er0
 *�@�@ +4:er1
 *�@�@ +8:er2
 *�@�@+12:er3
 *�@�@+16:er4
 *�@�@+20:er5
 *�@�@+24:er6
 *�@�@+28:crr
 *�@�@+29:pc
 *�@�@+32�`:�����ݑO�Ɏg�p����Ă����X�^�b�N�̈�
 */

/*
 * �����ݔ������O�̃X�^�b�N�|�C���^�܂ł̃I�t�Z�b�g
 */
#define OFFSET_SP	32u

void cpu_experr(EXCSTACK *sp)
{
    UW sp2, pc, ccr, tmp;
    
    sp2 = (UW)sp + OFFSET_SP;
    tmp = sp->pc;
    ccr = (tmp >> 24u) & 0xffu;	/*  ���1�o�C�g  */
    pc = tmp & 0x00ffffffu;	/*  ����3�o�C�g  */
    
    syslog(LOG_EMERG, "Unexpected interrupt.");
    syslog(LOG_EMERG, "PC  = 0x%08x SP  = 0x%08x CCR  = 0x%02x",
                       pc, sp2, ccr);
    syslog(LOG_EMERG, "ER0 = 0x%08x ER1 = 0x%08x ER2 = 0x%08x ER3 = 0x%08x",
                       sp->er0, sp->er1, sp->er2, sp->er3);
    syslog(LOG_EMERG, "ER4 = 0x%08x ER5 = 0x%08x ER6 = 0x%08x",
                       sp->er4, sp->er5, sp->er6);
    while(1)
    	;
}

/*
 *   �V�X�e�������o�͐�̎w��
 */

void
cpu_putc(char c)
{
    if (c == '\n') {
        SCI_wait_putchar(SYSTEM_SCI, '\r');
    }
    SCI_wait_putchar(SYSTEM_SCI, c);
}

/*
 *  local_memcpy
 *
 *    �W�� C ���C�u������ memcpy �Ɠ����A�ᐅ���R�s�[�֐�
 *    �����N���ɃG���[���������邽�߁A���O��ς��Ă���B
 *    �܂��A�����N�X�N���v�g�̍Ō�̍s��
 *
 *       PROVIDE(_memcpy = _local_memcpy);
 *
 *    ��ǉ������B
 *
 *    eepmov.w���߂��g�����������I�����A�f�[�^�]�����́i�������ԁj
 *    �����݋֎~�ɂȂ��Ă��܂��̂ŁA�g�p���Ă��Ȃ��B
 */

void *
local_memcpy (void *out, const void *in, size_t n)
{
    char *o = out;
    const char *i = in;

    while (n > 0) {
        *o = *i;
        ++o;
        ++i;
        --n;
    }
    return out;
}

