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
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

#include "jsp_kernel.h"
#include <sil.h>
#include <s_services.h>
#include "sh7615scif.h"
/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
/* ���o�̓|�[�g�̐ݒ��sys_config.c */
/* �����݃x�N�^�ԍ��̐ݒ��hw_serial.h */
/* �Ǘ��u���b�N�̐ݒ��sh7615scif.c */
void
sys_initialize ()
{
	SIOPCB *siopcb;

	/* �g�p������Ӌ@��͂����ŗL���ɂ��Ă����B */
	/*  SCIF�f�[�^���o�̓|�[�g�̐ݒ�  */
#ifndef GDB_STUB

	/* SCIF1 */
	sil_wrh_mem (PBCR, sil_reh_mem (PBCR) | (0x0800 | 0x2000));
#if TNUM_PORT >= 2
	/* SCIF2 */
	sil_wrh_mem (PBCR2, sil_reh_mem (PBCR2) | (0x0200 | 0x0800));
#endif /* TNUM_PORT >= 2 */

#else	/*  GDB_STUB  */

	/* SCIF2 */
	sil_wrh_mem (PBCR2, sil_reh_mem (PBCR2) | (0x0200 | 0x0800));

#endif	/*  GDB_STUB  */
	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	/*�o�i�[�o�͂��邽�� */
	sh2scif_initialize();
	siopcb = sh2scif_opn_por (LOGTASK_PORTID, 0);

#ifndef GDB_STUB
	/* �x�N�^�ԍ��̏����� */

	sil_wrw_mem (DMA_VCRDMA0, 72);
	sil_wrw_mem (DMA_VCRDMA1, 73);

	sil_wrh_mem (VCRWDT, 74 * 0x100 + 75);
	sil_wrh_mem (VCRA, 76 * 0x100);
	sil_wrh_mem (VCRC, 77 * 0x100 + 78);
	sil_wrh_mem (VCRD, 79 * 0x100);
	sil_wrh_mem (VCRE, 80 * 0x100 + 81);
	sil_wrh_mem (VCRF, 82 * 0x100 + 83);
	sil_wrh_mem (VCRG, 84 * 0x100);
	sil_wrh_mem (VCRH, 85 * 0x100 + 86);
	sil_wrh_mem (VCRI, 87 * 0x100 + 88);
	sil_wrh_mem (VCRJ, 89 * 0x100 + 90);
	sil_wrh_mem (VCRK, 91 * 0x100 + 92);
	sil_wrh_mem (VCRL, 93 * 0x100 + 94);
	sil_wrh_mem (VCRM, 95 * 0x100 + 96);
	sil_wrh_mem (VCRN, 97 * 0x100 + 98);
	sil_wrh_mem (VCRO, 99 * 0x100 + 100);
	sil_wrh_mem (VCRP, 101 * 0x100 + 102);
	sil_wrh_mem (VCRQ, 103 * 0x100 + 104);
	sil_wrh_mem (VCRR, 105 * 0x100 + 106);
	sil_wrh_mem (VCRS, 107 * 0x100 + 108);
	sil_wrh_mem (VCRT, 109 * 0x100 + 110);
	sil_wrh_mem (VCRU, 111 * 0x100 + 112);
#endif	/*  GDB_STUB  */

}

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit()
{
	sh2_exit();
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		sh2_putc (LOGTASK_PORTID, '\r');
	}
	sh2_putc (LOGTASK_PORTID, c);
}

/* �n�[�h�E�F�A�̐ݒ� */
void
hardware_init_hook (void)
{
}
