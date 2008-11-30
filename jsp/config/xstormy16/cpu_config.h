/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2005 by Embedded and Real-Time Systems Laboratory
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
 */

/*
 *  �v���Z�b�T�ˑ����W���[���iXstormy16�p�j
 */

#ifndef _CPU_CONFIG_H_
#define _CPU_CONFIG_H_

/*
 *  �J�[�l���̓������ʖ��̃��l�[��
 */
#include <cpu_rename.h>

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`
 */
#include <cpu_insn.h>

/*
 *  chg_ipm/get_ipm �̓T�|�[�g���Ȃ�
 */
#undef  SUPPORT_CHG_IPM

/*
 *  calltex �͎g�p���Ȃ�
 */
#define OMIT_CALLTEX

/*
 *  �V���A���|�[�g���̒�`
 */
#define TNUM_PORT   2   /* �T�|�[�g����V���A���|�[�g�̐� */

/*
 *  �V���A���|�[�g�ԍ��Ɋւ����`
 */
#define LOGTASK_PORTID  2   /* �V�X�e�����O�ɗp����V���A���|�[�g�ԍ� */

/*
 *  ���O�^�X�N�̕K�v�X�^�b�N�T�C�Y
 */
#define LOGTASK_STACK_SIZE 256

/*
 *  ���O�o�b�t�@�̃T�C�Y
 */
#define TCNT_SYSLOG_BUFFER  8

/*
 *  TCB ���̃t�B�[���h�̃r�b�g���̒�`
 */
#define TBIT_TCB_TSTAT      8   /* tstat �t�B�[���h�̃r�b�g�� */
#define TBIT_TCB_PRIORITY   4   /* priority �t�B�[���h�̃r�b�g�� */

#ifndef _MACRO_ONLY

/*
 *  �^�X�N�R���e�L�X�g�u���b�N�̒�`
 */
typedef struct task_context_block {
    unsigned short sp;          /* �X�^�b�N�|�C���^ */
    unsigned short mode;        /* dispatcher�̕��A�� */
} CTXB;

/*
 *  �^�X�N/��^�X�N�Q�Ɨp�O���[�o���ϐ�
 */
extern unsigned short _kernel_intnest ;

/*
 *  �V�X�e����ԎQ��
 */
#define sense_context() ( _kernel_intnest > 0)
#define sense_lock() (!( __PSW & 0x0080 ))
#define t_sense_lock sense_lock
#define i_sense_lock sense_lock
#define t_lock_cpu() ({__asm__( "clr1 psw,#7" );})
#define t_unlock_cpu() ({__asm__( "set1 psw,#7" );})
#define i_lock_cpu t_lock_cpu
#define i_unlock_cpu t_unlock_cpu

/*
 *  CPU��O�̔����������̃R���e�L�X�g�̎Q��
 */
#define exc_sense_context(p_excinf) ( _kernel_intnest > 1 )

/*
 *  CPU��O�̔�����������CPU���b�N��Ԃ̎Q��
 */
#define exc_sense_lock(p_excinf) (!(((unsigned short*)p_excinf)[-1] & 0x0080))

/*
 *  �����݃n���h�������}�N��
 */
#define INTHDR_ENTRY(inthdr) extern void inthdr(void)
#define INT_ENTRY(inthdr) inthdr

/*
 *  CPU��O�����}�N��
 */
#define EXCHDR_ENTRY(exchdr) extern void exchdr(VP sp)
#define EXC_ENTRY(exchdr) exchdr

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
extern void cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������
 */
extern void cpu_terminate(void);

/*
 *  �����݃n���h���̐ݒ�
 */
extern void define_inh(INHNO inhno, FP inthdr) ;

/*
 *  CPU��O�n���h���̐ݒ�
 */
extern void define_exc(EXCNO excno, FP exchdr) ;

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
extern void sys_putc(char c);

/*
 *  �^�X�N�f�B�X�p�b�`��
 *  �ō��D�揇�ʃ^�X�N�ւ̃f�B�X�p�b�`�icpu_support.S���j
 */
extern void dispatch(void);

/*
 *  �^�X�N�f�B�X�p�b�`��
 *  ���݂̃R���e�L�X�g���̂Ăăf�B�X�p�b�`�icpu_support.S���j
 */
extern void exit_and_dispatch(void);

#endif /* _MACRO_ONLY */
#endif /* _CPU_CONFIG_H_ */
