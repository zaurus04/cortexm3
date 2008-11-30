/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 * 
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iOAKS16�p�j
 */

#include "jsp_kernel.h"
#include <sil.h>
#include "oaks16.h"

/*
 *  �^�[�Q�b�g�V�X�e���ˑ� ���������[�`��
 */

void
sys_initialize(void)
{
	VB * p;
	/* �R���g���[��#2���W�X�^�̏����� */
	p = (VB*)TADR_SFR_UART0_BASE;
	sil_wrb_mem((VP)(p+TADR_SFR_UC2_OFFSET), 0x00);
	/* UAERT1�̐ݒ� */
	p = (VB*)TADR_SFR_UART1_BASE;
  			/* ����M���[�h���W�X�^�̏����� */
	sil_wrb_mem((VP)(p+TADR_SFR_UMR_OFFSET), 0x05);	/* ����M���|�h���W�X�^ �����N���b�N,*/
													/* �񓯊��A8�r�b�g�A�p���e�B�Ȃ��A	*/
													/* �X���[�v�Ȃ�						*/
			/* ���M���䃌�W�X�^�̏����� */
	sil_wrb_mem((VP)(p+TADR_SFR_UC0_OFFSET), 0x10);	/* ����M���䃌�W�X�^�O �N���b�Nf1�I�� */
			/* �]�����x���W�X�^�̏����� (38400bps��25) */
	sil_wrb_mem((VP)(p+TADR_SFR_UBRG_OFFSET), 51);	/* �]�����x���W�X�^(19200bps)		*/
			/* ����M���䃌�W�X�^�̏����� */
	sil_wrb_mem((VP)(p+TADR_SFR_UC1_OFFSET), (TBIT_UiC1_TE | TBIT_UiC1_RE));
													/* ����M���䃌�W�X�^�P ����M����	*/

	/* �|�[�g0�̏����� */
	sil_wrb_mem((VP)TADR_SFR_P0, 0xff);				/* �|�[�g0�f�[�^������				*/
	sil_wrb_mem((VP)TADR_SFR_PD0, 0xff);			/* �|�[�g0�o�͐ݒ�					*/
}

/*
 *  �^�[�Q�b�g�V�X�e���̏I�����[�`��
 */

void
sys_exit(void)
{
  while (1)
  	;
}

void
sys_putc(char c)
{
	if(c == '\n'){
	    oaks16_putc( '\r' );
	}
    oaks16_putc( c );
}

