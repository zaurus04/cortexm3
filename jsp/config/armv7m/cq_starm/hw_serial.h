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
 *  @(#) $Id: hw_serial.h,v 1.5 2008/06/20 14:46:25 suikan Exp $
 */

/*
 *	�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iDVE68K/40�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
//#include <dve68k_dga.h>
#ifndef _MACRO_ONLY
#include <usart.h>
#endif /* _MACRO_ONLY */

/*
 *  SIO�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SIO 0	CM3NI // STM32F103��SIO(USART)���荞�݃n���h���̃x�N�^�ԍ�������t���邱�ƁB0�͂Ƃ肠�����B

#ifndef _MACRO_ONLY

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize	upd72001_initialize

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	CM3NI
//	SIOPCB	*siopcb;
//	BOOL	openflag;

	/*
	 *  �I�[�v�������|�[�g�����邩�� openflag �ɓǂ�ł����D
	 */
//	openflag = upd72001_openflag();

	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
//	siopcb = upd72001_opn_por(siopid, exinf);

	/*
	 *  �V���A��I/O�����݂̊����݃��x����ݒ肵�C�}�X�N����������D
	 */
//	if (!openflag) {
//		dga_set_ilv((VP) TADR_DGA_CSR25, TBIT_GP0IL, TIRQ_LEVEL6);
//		dga_bit_or((VP) TADR_DGA_CSR21, TBIT_GP0);
//	}
//	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
Inline void
sio_cls_por(SIOPCB *siopcb)
{
	CM3NI
	/*
	 *  �f�o�C�X�ˑ��̃N���[�Y�����D
	 */
//	upd72001_cls_por(siopcb);

	/*
	 *  �V���A��I/O�����݂��}�X�N����D
	 */
//	if (!upd72001_openflag()) {
//		dga_bit_and((VP) TADR_DGA_CSR21, ~TBIT_GP0);
//	}
}

/*
 *  SIO�̊����݃n���h��
 */
#define	sio_handler	upd72001_isr

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr	upd72001_snd_chr

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr	upd72001_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr	upd72001_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr	upd72001_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define	sio_ierdy_snd	upd72001_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define	sio_ierdy_rcv	upd72001_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
