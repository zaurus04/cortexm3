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
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */


#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#include "c54x.h"
#include "tl16c550cfn.h"
/*
 *  �V���A��I/O�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SIO   INT1_VEC

/*
 *  �V���A��I/O�|�[�g�̏�����
 */
#ifndef _MACRO_ONLY

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define sio_initialize  uart_initialize

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;
	BOOL	openflag;

	/*
	 *  �I�[�v�������|�[�g�����邩�� openflag �ɓǂ�ł����D
	 */
	openflag = uart_openflag();

	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	siopcb = uart_opn_por(siopid, exinf);
      
	/*
	 * �����݊֘A�̐ݒ�
	 */
	/* Enable Interrupt Rx */
	if (!openflag) {
		/* ���荞�݃t���O�̃N���A */
		sil_wrh_mem((VP) IFR,
			    (sil_reh_mem((VP) IFR) | (0x1 << INT1)));
		/* ���荞�݃}�X�N���W�X�^�̐ݒ� */
		sil_wrh_mem((VP) IMR,
			    (sil_reh_mem((VP) IMR) | (0x1 << INT1)));
	}
	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
Inline void
sio_cls_por(SIOPCB *siopcb)
{
	/*
	 *  �f�o�C�X�ˑ��̃N���[�Y�����D
	 */
	uart_cls_por(siopcb);

	/*
	 *  �V���A��I/O�����݂��}�X�N����D
	 */
	if (!uart_openflag()) {
		/*
		 *  �V���A��I/O�����݂��}�X�N����D
		 */
		sil_wrh_mem((VP) IMR,
			    (sil_reh_mem((VP) IMR) & ~(0x1 << INT1)));
		sil_wrh_mem((VP) IFR,
			    (sil_reh_mem((VP) IFR) | (0x1 << INT1)));
	}
}

/*
 *  SIO�̊����݃n���h��
 */
#define sio_handler uart_isr

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define sio_snd_chr uart_snd_chr

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define sio_rcv_chr uart_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define sio_ena_cbr uart_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define sio_dis_cbr uart_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define sio_ierdy_snd   uart_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define sio_ierdy_rcv   uart_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
