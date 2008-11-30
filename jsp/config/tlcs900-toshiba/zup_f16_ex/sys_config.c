/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[���iZup-F16�g���{�[�h�p�j
 */


#include "jsp_kernel.h"
#include <sil.h>
#include <tmp91cy22.h>
#include "hw_serial.h"


/* �V�X�e�����O���M���t���O */
BOOL	log_io_busy;

/*
 *  �^�[�Q�b�g�V�X�e���ˑ� ���������[�`��
 */

void
sys_initialize()
{
	/*
	 *  �o�i�[�\���p�V���A���|�[�g�̏�����
	 *
	 *  ���M�o�b�t�@��t���O�������C�|�[�����O�ɂ�鑗�M�����̎�����
	 *  �ł��Ȃ����߁C���M���������ݗv���t���O���|�[�����O���C���񑗐M
	 *  �p�ɃV�X�e�����O���M���t���O��p����D
	 */
	/* �V�X�e�����O���M���t���O������ */
	log_io_busy = FALSE;

	/* �V���A��I/O�h���C�o������	*/
	/* ��M��~	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD0), 0x00 );
	/* �|�[�g�ݒ�(TXD1)�Ƃ��Ďg�p	*/
	sil_wrb_mem((VP)(TADR_SFR_P9FC), 0x08 );
	sil_wrb_mem((VP)(TADR_SFR_P9CR), 0x08 );
	/* ���샂�[�h�ݒ�	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD0), (VB)(TBIT_SIOSMU8 | TBIT_SIOSCBRG) );
							/* 8bitUART���[�h,�{�[���[�g�W�F�l���[�^�g�p	*/
	sil_reb_mem((VP)(TADR_SFR_SC1CR));	/* �Ǐo���ɂ��G���[�t���O�N���A	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1CR), 0x00 );	/* �p���e�B����	*/
	sil_wrb_mem((VP)(TADR_SFR_BR1CR), (VB)BRCR_19200);
							/* ��T2�g�p,19200bps,�␳�@�\���g�p	*/
	sil_wrb_mem((VP)(TADR_SFR_BR1ADD), BRADD_19200);
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD1), TBIT_SIOI2S);

	/* �V���A�������ݗv���t���O�N���A	 */
	sil_wrb_mem((VP)(TADR_SFR_INTCLR), TBIT_TX1_CLR );	/* ���M�v���N���A	*/

	/* LED������	*/
	sil_wrb_mem((VP)(TADR_SFR_PA), 0xff );
	sil_wrb_mem((VP)(TADR_SFR_PAFC), 0x00 );
	sil_wrb_mem((VP)(TADR_SFR_PACR), 0xff );

}

/*
 *  �^�[�Q�b�g�V�X�e���̏I�����[�`��
 */

void
sys_exit(void)
{
  while(1);
}

/*
 *  �V�X�e�����O�p�������M�֐�
 *
 *  �{�֐���CPU���b�N���(�����݋֎~)�Ŏ��s���邱��
 */
void
sys_putc(char c)
{
	/* ���s�R�[�h�̏ꍇ���'\r'�𑗂�	*/
	if(c == '\n'){
		if( log_io_busy == TRUE ){
			/* ���ɑ��M���̏ꍇ�͊����ݗv���t���O���|�[�����O	*/
			while( (sil_reb_mem((VP)(TADR_SFR_INTES1)) & TBIT_INTC_H) == 0 );
			sil_wrb_mem((VP)TADR_SFR_INTCLR, (TBIT_TX1_CLR) );	/* ���M�v���N���A	*/
			sil_wrb_mem((VP)(TADR_SFR_SC1BUF), '\r');
		}
		else{
			/* ���M��Ԃɂ��ĕ����𑗐M	*/
			log_io_busy = TRUE;
			sil_wrb_mem((VP)(TADR_SFR_SC1BUF), '\r');
		}
	}
	if( log_io_busy == TRUE ){
		/* ���ɑ��M���̏ꍇ�͊����ݗv���t���O���|�[�����O	*/
		while( (sil_reb_mem((VP)(TADR_SFR_INTES1)) & TBIT_INTC_H) == 0 );
		sil_wrb_mem((VP)TADR_SFR_INTCLR, (TBIT_TX1_CLR) );	/* ���M�v���N���A	*/
		sil_wrb_mem((VP)(TADR_SFR_SC1BUF), c);
	}
	else{
		/* ���M��Ԃɂ��ĕ����𑗐M	*/
		log_io_busy = TRUE;
		sil_wrb_mem((VP)(TADR_SFR_SC1BUF), c);
	}
}



