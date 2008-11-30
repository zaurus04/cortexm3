/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

/*
 *	�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iH8S�t�@�~���[�p�j
 */
#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <h8s_sci.h>

/*
 *  SIO�̊����݃n���h���̃x�N�^�ԍ�
 */
/* �|�[�g1 */
#ifndef OMIT_SCI0
#define INHNO_SERIAL1_ERROR	IRQ_ERI0
#define INHNO_SERIAL1_IN	IRQ_RXI0
#define INHNO_SERIAL1_OUT	IRQ_TXI0
#endif /* OMIT_SCI0 */

#if TNUM_PORT >= 2
/* �|�[�g2 */
#define INHNO_SERIAL2_ERROR	IRQ_ERI1
#define INHNO_SERIAL2_IN	IRQ_RXI1
#define INHNO_SERIAL2_OUT	IRQ_TXI1
#endif /* TNUM_PORT */

#if TNUM_PORT >= 3
/* �|�[�g3 */
#define INHNO_SERIAL3_ERROR	IRQ_ERI2
#define INHNO_SERIAL3_IN	IRQ_RXI2
#define INHNO_SERIAL3_OUT	IRQ_TXI2
#endif /* TNUM_PORT */


/*
 *  ���W���[���X�g�b�v���[�h�R���g���[�����W�X�^�̃r�b�g��`
 */
#ifndef OMIT_SCI0

#if TNUM_SIOP == 1
#define MSTPCR_SCI	MSTPCR_SCI0
#endif /* TNUM_SIOP == 1 */

#if TNUM_SIOP == 2
#define MSTPCR_SCI	(MSTPCR_SCI0 | MSTPCR_SCI1)
#endif /* TNUM_SIOP == 2 */

#if TNUM_SIOP == 3
#define MSTPCR_SCI	(MSTPCR_SCI0 | MSTPCR_SCI1 | MSTPCR_SCI2)
#endif /* TNUM_SIOP == 3 */

#else /* OMIT_SCI0 */

#if TNUM_SIOP == 1
#error Invalid serial port ID.
#endif /* TNUM_SIOP == 1 */

#if TNUM_SIOP == 2
#define MSTPCR_SCI	MSTPCR_SCI1
#endif /* TNUM_SIOP == 2 */

#if TNUM_SIOP == 3
#define MSTPCR_SCI	(MSTPCR_SCI1 | MSTPCR_SCI2)
#endif /* TNUM_SIOP == 3 */

#endif /* OMIT_SCI0 */

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize		h8s_sci_initialize

/*
 *  �J�[�l���N�����p�̏����� (sys_putc�ŗ��p)
 */
#define sio_init		h8s_sci_init

#ifndef _MACRO_ONLY

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;
	BOOL	openflag;

	/*
	 *  �I�[�v�������|�[�g�����邩�� openflag �ɓǂ�ł����B
	 */
	openflag = h8s_sci_openflag();

	/*
	 * ���W���[���X�g�b�v���[�h����
	 */
	h8s_andh_reg( (VP) MSTPCR, ~MSTPCR_SCI );

	/*
	 *  �f�o�C�X�ˑ��̃I�[�v������
	 */
	siopcb = h8s_sci_opn_por(siopid, exinf);

	/*
	 *  �V���A��I/O�����݂̊����݃��x����ݒ肷��B
	 */
	if (!openflag) {
		/* �����݃��x���ݒ� */
#ifndef OMIT_SCI0
		icu_set_ilv( IPRJ, IPR_LOW, SCI0_INT_LVL );
#endif 	/*  OMIT_SCI0  */

#if TNUM_SIOP >= 2
		icu_set_ilv( IPRK, IPR_UPR, SCI1_INT_LVL );
#endif /* TNUM_SIOP >= 2 */

#if TNUM_SIOP >= 3
		icu_set_ilv( IPRK, IPR_LOW, SCI0_INT_LVL );
#endif /* TNUM_SIOP >= 3 */

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
	 *  �f�o�C�X�ˑ��̃N���[�Y����
	 */
	h8s_sci_cls_por(siopcb);

	/*
	 *  ���W���[���X�g�b�v���[�h�Z�b�g
	 */
	h8s_orh_reg( (VP) MSTPCR,   MSTPCR_SCI);

	/*
	 *  �V���A��I/O�����݂��}�X�N����B
	 */
	if (!h8s_sci_openflag()) {
		/* �����݃}�X�N���� */
		icu_set_ilv( IPRJ, IPR_LOW, 0 );
#if TNUM_SIOP >= 2
		icu_set_ilv( IPRK, IPR_UPR, 0 );
#endif /* TNUM_SIOP >= 2 */

#if TNUM_SIOP >= 3
		icu_set_ilv( IPRK, IPR_LOW, 0 );
#endif /* TNUM_SIOP >= 3 */

	}
}

#endif /* _MACRO_ONLY */

/*
 *  SIO�̊����݃n���h��
 *    sio1_handler_in    : ��M�����݃n���h��
 *    sio1_handler_out   : ���M�����݃n���h��
 *    sio1_handler_error : ��M�G���[�����݃n���h��
 */
/* �|�[�g1 */
#define	sio1_handler_in		h8s_sci0_isr_in
#define	sio1_handler_out	h8s_sci0_isr_out
#define	sio1_handler_error	h8s_sci0_isr_error

#if TNUM_SIOP >= 2
/* �|�[�g2 */
#define	sio2_handler_in		h8s_sci1_isr_in
#define	sio2_handler_out	h8s_sci1_isr_out
#define	sio2_handler_error	h8s_sci1_isr_error
#endif /* TNUM_SIOP >= 2 */

#if TNUM_SIOP >= 3
/* �|�[�g3 */
#define	sio3_handler_in		h8s_sci2_isr_in
#define	sio3_handler_out	h8s_sci2_isr_out
#define	sio3_handler_error	h8s_sci2_isr_error
#endif /* TNUM_SIOP >= 3 */

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr		h8s_sci_snd_chr

/*
 *  �V���A��I/O�|�[�g�ւ̕������M�i�|�[�����O�j
 */
#define	sio_snd_chr_pol		h8s_sci_putchar_pol

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr		h8s_sci_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr		h8s_sci_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr		h8s_sci_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define	sio_ierdy_snd		h8s_sci_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define	sio_ierdy_rcv		h8s_sci_ierdy_rcv

#endif /* _HW_SERIAL_H_ */
