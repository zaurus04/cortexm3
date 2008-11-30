/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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

#include "jsp_kernel.h"
#include <sil.h>
#include <s_services.h>
#include "sh7145sci.h"

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
/*
 *  �V���A��I/O�|�[�g�̏����� banner�o�͂̂��߃J�[�l���̏������Ɩ��֌W�ɍs��
 */
void
sys_initialize ()
{
	SIOPCB *siopcb;

	/* �g�p������Ӌ@��͂����ŗL���ɂ��Ă����B */
	/*  SCI�f�[�^���o�̓|�[�g�̐ݒ�  */

#ifndef GDB_STUB

	/* SCI1 */
	sil_wrh_mem (MSTCR1, (VH) ((VH) sil_reh_mem (MSTCR1) & ~0x0002));
	sil_wrh_mem (PACRL2, sil_reh_mem (PACRL2) | (PFC_TXD1 | PFC_RXD1));
#if TNUM_PORT >=2
	/* SCI0 */
	sil_wrh_mem (MSTCR1, (VH) ((VH) sil_reh_mem (MSTCR1) & ~0x0001));
	sil_wrh_mem (PACRL2, sil_reh_mem (PACRL2) | (PFC_TXD0 | PFC_RXD0));
#endif /*TNUM_PORT >=2 */

#else /* GDB_STUB */

	/* SCI0 */
	sil_wrh_mem (MSTCR1, (VH) ((VH) sil_reh_mem (MSTCR1) & ~0x0001));
	sil_wrh_mem (PACRL2, sil_reh_mem (PACRL2) | (PFC_TXD0 | PFC_RXD0));

#endif /* GDB_STUB */

	/* CMT0 */
	sil_wrh_mem (MSTCR2, (VH) ((VH) sil_reh_mem (MSTCR2) & ~0x1000));
	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	/*�o�i�[�o�͂��邽�� */
	sh2sci_initialize();
	siopcb = sh2sci_opn_por (LOGTASK_PORTID, 0);
}

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit ()
{
	sh2_exit ();
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc (char c)
{
	if (c == '\n') {
		sh2_putc (LOGTASK_PORTID, '\r');
	}
	sh2_putc (LOGTASK_PORTID, c);
}

/* �n�[�h�E�F�A�̐ݒ� */
/* �����ł̓o�X�̐ݒ�̂ݍs���B���Ӌ@��̐ݒ��sys_initialize�ōs���B */
#ifndef GDB_STUB
void
hardware_init_hook (void)
{
	sil_wrh_mem (BCR1, 0x202f);
	sil_wrh_mem (BCR2, 0x5500);
	sil_wrh_mem (WCR1, 0x0010);
	sil_wrh_mem (PACRH, 0x5000);
	sil_wrh_mem (PACRL1, 0x1540);
	sil_wrh_mem (PACRL2, 0x0140);
	sil_wrh_mem (PBCR1, 0x0002);
	sil_wrh_mem (PBCR2, 0xa005);
	sil_wrh_mem (PCCR, 0xfffc);
	sil_wrh_mem (PDCRH1, 0x5555);
	sil_wrh_mem (PDCRH2, 0x5555);
	sil_wrh_mem (PDCRL1, 0xffff);
	sil_wrh_mem (PDCRL2, 0x0000);
	sil_wrh_mem (PECRL1, 0x0000);
	sil_wrh_mem (PECRL2, 0x0000);
	sil_wrh_mem (PAIORL, 0x87e7);
	sil_wrh_mem (PBIOR, 0x023c);
}
#else /*  GDB_STUB  */
void
hardware_init_hook (void)
{
}
#endif /*  GDB_STUB  */
