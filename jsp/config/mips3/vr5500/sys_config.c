/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

#include "jsp_kernel.h"
#include <hw_serial.h>		/* �V���A���R���g���[���֌W */

/*  �����݃R���g���[���ɗp���銄���݃}�X�N�̋[���e�[�u��  */
ICU_IPM icu_intmask_table[ TMAX_ALL_INTNO ];

/*
 *  �^�[�Q�b�g�V�X�e���ˑ� ���������[�`��
 */
void sys_initialize() {

	ICU_IPM icu_ipm0 = {INIT_INT0M, INIT_INT1M};

	/*
	 *  �O�������݃R���g���[���̊����݃}�X�N�̏�����
	 */
	icu_set_ipm( &icu_ipm0 );

	/*
	 *  �o�i�[�\���p�V���A���|�[�g�̏�����
	 */
	sio_init();
}

/*
 *  �^�[�Q�b�g�V�X�e���̏I�����[�`��
 */
void sys_exit(void) {

#ifndef GDB_STUB
	while (1);
#else	/*  GDB_STUB  */
	vr5500_exit();
#endif	/*  GDB_STUB  */

}

/*
 *  GDB STUB / ���ڌďo�� �R���\�[���ďo�����[�`��
 */

/*
 *  gdb stub �ɂ��R���\�[���o��
 */
/* a0($4) = 0xfe00, a1($5) = �o�͂������L�����N�^ �������āA
   SYSCALL ��O�𔭐�������B */

/* ���̊֐����Ăяo�����ɂ́A�X�e�[�^�X���W�X�^��EXL�r�b�g = 0 �ŌĂяo�����ƁB
   �Ȃ��A���݁A�J�[�l���ł́A�o�i�[�\�����A�V���A���o�͎��Ɍďo���s���Ă���B*/
Inline void stub_putc(int c) {

	Asm("	move	$5, %0;		\
	     	li	$4, 0xfe00;	\
		syscall;		\
		nop"
		:: "r"(c)
		: "$4","$5" );
}

#ifdef GDB_STUB
#define vr5500_putc(c) stub_putc( c )
#else  /* GDB_STUB */
#define	vr5500_putc(c) sio_snd_chr_pol( c )
#endif /* GDB_STUB */

/*
 *   �V�X�e�������o�͐�̎w��
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		vr5500_putc('\r');
	}
	vr5500_putc(c);
}

