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
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *�@�@�V���A��I/O�f�o�C�X�iSIO/SCIF�j�h���C�o�iapsh02f6a�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#ifndef _MACRO_ONLY
#include "sh7145sci.h"
#endif /* _MACRO_ONLY */

/*
 *  SIO�̊����݃n���h���̃x�N�^�ԍ�
 */
#ifndef GDB_STUB

#define INHNO_SERIAL_IN	 RXI1
#define INHNO_SERIAL_OUT TXI1
#define INHNO_SERIAL_ERROR ERI1
#if TNUM_PORT >= 2
#define INHNO_SERIAL2_IN	 RXI0
#define INHNO_SERIAL2_OUT TXI0
#define INHNO_SERIAL2_ERROR ERI0
#endif /* TNUM_PORT >= 2 */

#else /* GDB_STUB */

#define INHNO_SERIAL_IN	 RXI0
#define INHNO_SERIAL_OUT TXI0
#define INHNO_SERIAL_ERROR ERI0

#endif /* GDB_STUB */

/*
 * SCI�̊��荞�݃��x��
 * �@�����݃n���h���͑���M�ʁX�ɓo�^�ł��邪�A�����݃��x����
 * �@���M����M���������x���ɂ����ݒ�ł��Ȃ��B
 */
#define LEVEL0		0			/*  �����݉������̃��x��  */

#ifndef _MACRO_ONLY

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize	sh2sci_initialize

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;
	BOOL openflag;

	/*
	 *  �I�[�v�������|�[�g�����邩�� openflag �ɓǂ�ł����D
	 */
	openflag = sh2sci_openflag (siopid);

	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	siopcb = sh2sci_opn_por (siopid, exinf);

	/*
	 *  �����݃R���g���[���ˑ�
	 *  �@�V���A��I/O�����݂̊����݃��x����ݒ肷��
	 */
	if (!openflag) {
		if ((siopcb->siopinib->reg_base) == 0xffff81c0)
			define_int_plevel (IPRI, siopcb->siopinib->int_level, 12);
		if ((siopcb->siopinib->reg_base) == 0xffff81a0)
			define_int_plevel (IPRF, siopcb->siopinib->int_level, 4);
		if ((siopcb->siopinib->reg_base) == 0xffff81b0)
			define_int_plevel (IPRF, siopcb->siopinib->int_level, 0);
	}
	return (siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
Inline void
sio_cls_por (SIOPCB * siopcb)
{
	/*
	 *  �f�o�C�X�ˑ��̃N���[�Y�����D
	 */
	sh2sci_cls_por (siopcb);

	/*
	 *  �V���A��I/O�����݃��x�����Œ჌�x���ɂ���
	 */
	if ((siopcb->siopinib->reg_base) == 0xffff81c0)
		define_int_plevel (IPRI, LEVEL0, 12);
	if ((siopcb->siopinib->reg_base) == 0xffff81a0)
		define_int_plevel (IPRF, LEVEL0, 4);
	if ((siopcb->siopinib->reg_base) == 0xffff81b0)
		define_int_plevel (IPRF, LEVEL0, 0);
}

/*
 *  SIO�̊����݃n���h��
 */
#define	sio_handler_in	sh2sci_isr_in	/*  ��M�����݃n���h��  */
#define	sio_handler_out	sh2sci_isr_out	/*  ���M�����݃n���h��  */
#define	sio_handler_error sh2sci_isr_error	/*  ��M�G���[�����݃n���h��  */
#if TNUM_PORT >= 2
#define	sio_handler2_in		sh2sci_isr2_in	/*  ��M�����݃n���h��  */
#define	sio_handler2_out	sh2sci_isr2_out	/*  ���M�����݃n���h��  */
#define	sio_handler2_error	sh2sci_isr2_error	/*  ��M�G���[�����݃n���h��  */
#endif /* TNUM_PORT >= 2 */

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr	sh2sci_snd_chr

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr	sh2sci_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr	sh2sci_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr	sh2sci_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 *  �@�@jsp/systask/serial.c�ɂ�����̂����l�[�����Ă���
 *  �@�@�i���̑O���Q�Ɓj
 */
#define	sio_ierdy_snd	sh2sci_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 *  �@�@jsp/systask/serial.c�ɂ�����̂����l�[�����Ă���
 *  �@�@�i���̑O���Q�Ɓj
 */
#define	sio_ierdy_rcv	sh2sci_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
