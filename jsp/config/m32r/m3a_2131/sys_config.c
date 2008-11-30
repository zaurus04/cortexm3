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
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iM3A-2131�p�j
 */

#include <sys_rename.h>

#include <s_services.h>

#include "jsp_kernel.h"
#include <hw_serial.h>


/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
	sil_wrh_mem((void *)0xef106e, 0);		//�|�[�g7���g�p����
	sil_wrb_mem((void *)0xef1047, 0xff);	//�o�̓��[�h
	sil_wrb_mem((void *)LED,      0);

		/* UART������ */
	sil_wrb_mem((void *)(SIOCR(CONSOLE_PORTID-1)+3), 0);

		/* �|�[�g���J��(UART0) */
	sil_wrb_mem((void *)PDATA(5), 0);
	sil_wrb_mem((void *)PDIR(5),  0x80);

		/* UART, Non-parity, 1 stop-bit */
	sil_wrb_mem((void *)(SIOMOD0(CONSOLE_PORTID-1)+3), 0);

		/* 8bit, internal clock */
	sil_wrh_mem((void *)(SIOMOD1(CONSOLE_PORTID-1)+2), 0x0800);

		/* M32R(32102) - f(BLK)=16MHz��115200bps */
	sil_wrh_mem((void *)(SIOBAUR(CONSOLE_PORTID-1)+2), SERIAL_CLKDIV);
	sil_wrb_mem((void *)(SIORBAUR(CONSOLE_PORTID-1)+3), SERIAL_CLKCMP);

		/* �X�e�[�^�X�N���A, ����M����J�n */
	sil_wrb_mem((void *)(SIOCR(CONSOLE_PORTID-1)+2), 0x3);
	sil_wrb_mem((void *)(SIOCR(CONSOLE_PORTID-1)+3), 0x3);

		/* TxD,RxD�s���L��(UART0) */
	sil_wrh_mem((void *)PMOD(5), 0x5500);

}

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit(void)
{
	dis_int();
	*(volatile unsigned char *)(ICUIMASK+1) = 0;
	while(1==1)
	{
		sil_wrb_mem((void *)LED, sil_reb_mem((void *)LED) + 1);

			/* �����d�̓��[�h�ֈڍs */
		__asm(	"stb	%0, @%1	\n"
				"ldb	%0, @%1 \n"
			  	"nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop"
			: : "r"(1), "r"(CLKMOD+3) );
	}
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc(char c)
{
	if(c == '\n')
		sys_putc('\r');
	while( (sil_reb_mem((void *)(SIOSTS(CONSOLE_PORTID-1)+3)) & 0x1) == 0);	//���M�����҂�
	sil_wrb_mem((void *)(SIOTXB(CONSOLE_PORTID-1)+3), c);	//�ꕶ�����M
}
