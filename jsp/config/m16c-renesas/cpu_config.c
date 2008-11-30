/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RICOH COMPANY,LTD. JAPAN
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
 *  @(#) $Id: cpu_config.c,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */

/*
 *  �v���Z�b�T�ˑ����W���[���iM16C�p�j
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

/* 
 *  ������/CPU��O�l�X�g�J�E���^
 */
char	intnest;

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize(void)
{
	/* �����݃l�X�g�J�E���g������(�^�X�N�R���e�L�X�g) */
	intnest = 0;
}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate(void)
{
}

/*
 * software_init_hook�̉���`
 */
#ifndef EXTERNAL_SOFT_HOOK
const VP_INT software_init_hook = 0;
#endif  /* EXTERNAL_SOFT_HOOK */


/*
 * ���荞�ݐ��䃌�W�X�^���荞�ݗD��x�ύX
 *
 * ���荞�ݐ��䃌�W�X�^�́C���̃��W�X�^�ɑΉ����銄���ݗv�����������Ȃ��ӏ���
 * �ύX����K�v������D���̂��߁C�����݂��֎~������C�ύX����K�v������D
 * �����݂��֎~���Ċ����ݐ��䃌�W�X�^��ύX����ꍇ�́C�g�p���閽�߂ɒ��ӂ���
 * �K�v������D
 * IR�r�b�g�ȊO��ύX����ꍇ�ɂ́CAND,OR,BCLR,BSET���߂��g�p���邱�ƁD
 * IR�r�b�g��MOV���߂��g�p���邱�ƁD
 * �܂��CI�t���O��p���Ċ����݂��֎~����ꍇ�́C������O�ɐ����߂������ƁD
 * �ڍׂ́CM16C�n�[�h�E�F�A�}�j���A����
 *       "�g�p��̒���->���荞��->�����ݐ��䃌�W�X�^�̕ύX"
 * ���Q�Ƃ̂��ƁD 
 */
void
set_ic_ilvl(VP addr, UB val){
    BOOL    locked;
    
    locked = sense_lock();
    if (!(locked)) {
        sense_context() ? i_lock_cpu() : t_lock_cpu();
    }
    
    _asm("PUSH.W A0");
    _asm("PUSH.B R0L");
    _asm("MOV.W $$[FB], A0", addr);
    _asm("MOV.B $$[FB], R0L", val);
    _asm("AND.B #08H, [A0]");
    _asm("OR.B  R0L, [A0]");
    _asm("NOP");
    _asm("NOP");    
    _asm("POP.B R0L");
    _asm("POP.W A0");

    if (!(locked)) {
        sense_context() ? i_unlock_cpu() : t_unlock_cpu();
    }
    
}

