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
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iDVE68K/40�p�j
 */

#include "jsp_kernel.h"
#include <sil.h>
#include <dve68k_dga.h>

/*
 *  �v���Z�b�T���ʂ̂��߂̕ϐ��i�}���`�v���Z�b�T�Ή��j
 */
UINT	board_id;		/* �{�[�hID */
VP	board_addr;		/* ���[�J���������̐擪�A�h���X */

/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
	/*
	 *  �v���Z�b�T���ʂ̂��߂̕ϐ��̏�����
	 */
	board_id = ((UINT)(sil_rew_mem((VP) TADR_BOARD_REG0)) & 0x1f);
	board_addr = (VP)(board_id << 24);

	/*
	 *  �����݊֘A�̏�����
	 *
	 *  ���ׂĂ̊����݂��}�X�N�E�N���A���C�����݃x�N�g����ݒ肷��D
	 */
	dga_write((VP) TADR_DGA_CSR21, 0);
	dga_write((VP) TADR_DGA_CSR23, ~0);
	dga_write((VP) TADR_DGA_CSR19, (TVEC_G0I << 24) | (TVEC_G1I << 16)
					| (TVEC_SWI << 8) | TVEC_SPRI);

	/*
	 *  �A�{�[�g�����݂̐ݒ�iNMI�j
	 *
	 *  �A�{�[�g�����݂̊����݃��x����ݒ肵�C�v�����N���A������C
	 *  �}�X�N����������D
	 */
	dga_set_ilv((VP) TADR_DGA_CSR24, TBIT_ABTIL, TIRQ_NMI);
	dga_write((VP) TADR_DGA_CSR23, TBIT_ABT);
	dga_bit_or((VP) TADR_DGA_CSR21, TBIT_ABT);

	/*
	 *  �������̈�̐ݒ�
	 *
	 *  ���[�J����������VME�o�X��ł̐擪�A�h���X�ƃT�C�Y�i16MB�j
	 *  ���C�A�N�Z�X���󂯕t����悤�ɐݒ肷��D�܂��CVME�o�X����
	 *  �g���A�h���X�A�N�Z�X���󂯕t����悤�ɂɐݒ肷��D
	 */
	dga_write((VP) TADR_DGA_CSR4, (UW) board_addr | 0x00ff);
	dga_write((VP) TADR_DGA_CSR5, 0x0000012fu);

	/*
	 *  �C���^�t�F�[�X���W�X�^�iIFR�j�̐ݒ�
	 *
	 *  �C���^�t�F�[�X���W�X�^�̃x�[�X�A�h���X��ݒ肷��D�܂��C�C
	 *  ���^�t�F�[�X���W�X�^0�̃T�[�r�X���N�G�X�g�t���O���N���A�D
	 *  �C���^�t�F�[�X���W�X�^3�Ƀ{�[�h��ID�ԍ���ݒ�D
	 */
	dga_write((VP) TADR_DGA_CSR3, (board_id << 4) | 0x3);
	dga_write((VP) TADR_DGA_IFR0, 0x80000000u);
	dga_write((VP) TADR_DGA_IFR3, board_id);

	/*
	 *  ���E���h���r�����[�h�ɐݒ�i�}���`�v���Z�b�T�Ή��j
	 */
	dga_write((VP) TADR_DGA_CSR1, (dga_read((VP) TADR_DGA_CSR1)
			& 0xffeffcff) | (1u << 20) | ((board_id % 4) << 8));
}

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit()
{
	dve68k_exit();
}

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		dve68k_putc('\r');
	}
	dve68k_putc(c);
}
