/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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

#include <jsp_kernel.h>
#include <hw_serial.h>

/*
 *  �^�[�Q�b�g�V�X�e���ˑ� ���������[�`��
 */
void
sys_initialize()
{

#ifndef GDB_STUB

	/*
	 * ���W���[���X�g�b�v���[�h����
	 */
#if TNUM_SIOP < 2
	h8s_andh( (VP) MSTPCR, ~( BIT5 ) );
#else /* TNUM_SIOP < 2 */
	h8s_andh( (VP) MSTPCR, ~( BIT6 | BIT5 ) );
#endif /* TNUM_SIOP < 2 */

	/*
	 *  �o�i�[�\���p�V���A���|�[�g�̏�����
	 */
	sio_init();

#endif /* GDB_STUB */

}

/*
 *  �^�[�Q�b�g�V�X�e���̏I�����[�`��
 */
void
sys_exit(void)
{
	while (1);
}


/*
 *  GDB STUB / ���ڌďo�� �R���\�[���ďo�����[�`��
 */

/* er0 ��0, er1 �ɏo�͂�������������� trapa #1 �����s���� */
void
stub_putc(char c)
{
	/* er0 = c */
	Asm("push.l	er1");
	Asm("mov.l	er0, er1");
	Asm("sub.l	er0, er0");
	Asm("trapa	#1");
	Asm("pop.l	er1");
}

#ifdef GDB_STUB
#define h8s_putc(c)	stub_putc(c)		/* GDB�X�^�u�̃V�X�e���R�[���o�� */
#else  /* GDB_STUB */
#define	h8s_putc(c)	sio_snd_chr_pol(c)	/* �V���A���|�[�g�ւ̃|�[�����O�o�� */
#endif /* GDB_STUB */

/*   print_banner()  */
void
sys_putc(char c)
{
	if (c == '\n') {
		h8s_putc('\r');
	}
	h8s_putc(c);
}
