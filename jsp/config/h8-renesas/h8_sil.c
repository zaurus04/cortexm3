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
 *  @(#) $Id: h8_sil.c,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 * �V�X�e���C���^�t�F�[�X���C���i�ǉ������j
 *�@�@I/O�|�[�g�̃f�[�^�E�f�B���N�V�����E���W�X�^DDR�ւ̃A�N�Z�X
 *�@�@H8��DDR�͏������ݐ�p�ł���A���̂܂܂ł͏��]�̃r�b�g������
 *�@�@�ύX���邱�Ƃ��ł��Ȃ��B�ibset,bclr���߂ł����s�j
 *�@�@���̂��߁A�{�����ł́A��������Ƀe���|������p�ӂ��āADDR��
 *�@�@���ݒl��ێ�������@���̂��Ă���B
 *�@�@
 *�@�@�|�[�g7�͓��͐�p�̂��߁A�ȗ����Ă���B
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include <h8_sil.h>

/*  ��������̃e���|�����̈�  */
static UB ddr_tmp[] = {
	/* 1         2         3         4         5      */
	H8P1DDR0, H8P2DDR0, H8P3DDR0, H8P4DDR0, H8P5DDR0, 
	/* 6         8         9         A         B      */
	H8P6DDR0, H8P8DDR0, H8P9DDR0, H8PADDR0, H8PBDDR0
};

/*  �e�|�[�g�̃A�h���X  */
static const VP ddr_adr[] = {
	/*    1            2            3            4            5    */
	(VP)H8P1DDR, (VP)H8P2DDR, (VP)H8P3DDR, (VP)H8P4DDR, (VP)H8P5DDR, 
	/*    6            8            9            A            B    */
	(VP)H8P6DDR, (VP)H8P8DDR, (VP)H8P9DDR, (VP)H8PADDR, (VP)H8PBDDR
};


/*
 *      DDR�̓ǂݏo��
 */
UB sil_reb_ddr(IO_PORT port)
{
	assert((IO_PORT1 <= port) && (port <= IO_PORTB));
	return ddr_tmp[port];
}

/*
 *      DDR�̏�������
 */
void sil_wrb_ddr(IO_PORT port, UB data)
{
	assert((IO_PORT1 <= port) && (port <= IO_PORTB));
	ddr_tmp[port] = data;
	sil_wrb_mem(ddr_adr[port], (VB)data);
}

/*
 *      DDR��AND���Z
 */
void sil_anb_ddr(IO_PORT port, UB data)
{
	UB ddr = sil_reb_ddr(port);
	
	ddr &= data;
	sil_wrb_ddr(port, ddr);
}

/*
 *      DDR��OR���Z
 */
void sil_orb_ddr(IO_PORT port, UB data)
{
	UB ddr = sil_reb_ddr(port);

	ddr |= data;
	sil_wrb_ddr(port, ddr);
}

