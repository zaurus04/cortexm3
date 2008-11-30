/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */

/*
 * �^�[�Q�b�g�ˑ��V���A��I/O���W���[��(LUXUN2)
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include "s_services.h"

/*
 *  �V���A��I/O�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SERIAL_IN		S1C33_INHNO_SERIAL0RX
#define INHNO_SERIAL_OUT	S1C33_INHNO_SERIAL0TX
#define INHNO_SERIAL_ERR	S1C33_INHNO_SERIAL0ERR

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND		1	/* ���M�\�R�[���o�b�N	*/
#define SIO_ERDY_RCV		2	/* ��M�ʒm�R�[���o�b�N	*/

#define INDEX_SIO(sioid)	((UINT)((sioid) - 1))

/*
 *  SIO���荞�ݗv���t���O �r�b�g�ʒu
 */
#define SIO_INT_ERR		0x01
#define	SIO_INT_RCV		0x02
#define	SIO_INT_SND		0x04

/*
 * �G���[�t���O �r�b�g�ʒu
 */
#define SIO_ERR_FRAME		0x10
#define SIO_ERR_PARITY		0x08
#define SIO_ERR_OVERRUN		0x04

#ifndef _MACRO_ONLY
/*
 *	�V���A���|�[�g�̃n�[�h�E�F�A�ˑ����̒�`
 */
typedef struct {
	UB	ch_no;		/* SIO�`���l���ԍ�		*/
	UB	err_vector;	/* �ʐM�G���[���荞�݃x�N�^�ԍ�	*/
	UB	rx_vector;	/* ��M���荞�݃x�N�^�ԍ�	*/
	UB	tx_vector;	/* ���M�������荞�݃x�N�^�ԍ�	*/
} SIOPINIB;

/*
 *  �V���A���|�[�g�̐���u���b�N
 */
typedef struct {
	const SIOPINIB	*inib;		/* �������u���b�N	*/
	VP_INT		exinf;		/* �g�����		*/
	BOOL		openflag;	/* �I�[�v���ς݃t���O	*/
	BOOL		tx_cbrflag;	/* ���M�R�[���o�b�N���s�t���O*/
	BOOL		rx_cbrflag;	/* ��M�R�[���o�b�N���s�t���O*/
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  �O���֐��̎Q��
 */
extern void	sio_initialize (void);
extern void	sio_ena_cbr(SIOPCB *siopcb, UINT cbrtn);
extern void	sio_dis_cbr(SIOPCB *siopcb, UINT cbrtn);
extern void	serial_handler_in(ID portid);
extern void	serial_handler_out(ID portid);
extern void	sio_ierdy_snd(VP_INT exinf);
extern void	sio_ierdy_rcv(VP_INT exinf);
extern ER	ena_int(INTNO);
extern ER	dis_int(INTNO);

/*
 *  �V���A���|�[�g�̏�����
 */
Inline SIOPCB
*sio_opn_por(ID siopid, VP_INT exinf)
{
	B	temp;

	/*
	 *  ���荞�݂̋֎~
	 */
	if(siopid == 1){
		dis_int(S1C33_INHNO_SERIAL0RX);
		dis_int(S1C33_INHNO_SERIAL0TX);
#ifdef SIO_ERR_HANDLER
		dis_int(S1C33_INHNO_SERIAL0ERR);
#endif
	} else {
		dis_int(S1C33_INHNO_SERIAL1RX);
		dis_int(S1C33_INHNO_SERIAL1TX);
#ifdef SIO_ERR_HANDLER
		dis_int(S1C33_INHNO_SERIAL1ERR);
#endif
	}

	/*
	 *  �V���A��I/F�̐ݒ�
	 *
	 *  8bit��������  �p���e�B�Ȃ� �X�g�b�v�r�b�g1bit  �O���N���b�N
	 */
	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[INDEX_SIO(siopid)].bControl = 0x07;

	((s1c33Port_t *)S1C33_PORT_BASE)->stPPort[INDEX_SIO(siopid)].bFuncSwitch = 0x07;
	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[INDEX_SIO(siopid)].bIrDA = 0x00;

	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[INDEX_SIO(siopid)].bControl = 0xc7;

	/*
	 *  �����ݗv�����N���A
	 */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntFactor[6] |= (0x07 << INDEX_SIO(siopid));

	/*
	 *  ��M�o�b�t�@�̃N���A
	 */
	temp = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[INDEX_SIO(siopid)].bRxd;

	/*
	 *  ������̐ݒ�
	 */
	siopcb_table[INDEX_SIO(siopid)].openflag = TRUE;
	if(exinf != NULL){
		siopcb_table[INDEX_SIO(siopid)].exinf = exinf;
	}

	/*
	 *  ���荞�݂̋���
	 */
	if(siopid == 1){
		ena_int(S1C33_INHNO_SERIAL0RX);
		ena_int(S1C33_INHNO_SERIAL0TX);
#ifdef SIO_ERR_HANDLER
		ena_int(S1C33_INHNO_SERIAL0ERR);
#endif
	} else {
		ena_int(S1C33_INHNO_SERIAL1RX);
		ena_int(S1C33_INHNO_SERIAL1TX);
#ifdef SIO_ERR_HANDLER
		ena_int(S1C33_INHNO_SERIAL1ERR);
#endif
	}

	return (&(siopcb_table[INDEX_SIO(siopid)]));
}

/*
 *  �ʐM�̒�~
 */
Inline void
sio_cls_por(SIOPCB *siopcb)
{
	UB	ch_no;

	ch_no = siopcb->inib->ch_no;
	/*
	 *  �]��������҂�
	 */
	while(((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bStatus & 0x20){
		;
	}

	/*
	 *  �ʐM���֎~����
	 */
	((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bControl = 0x07;

	return;
}

/*
 *  ���M�@�\�̏�Ԃ��擾
 */
Inline BOOL
sio_get_txready(UB ch_no)
{
	UB	bSioSts;

	bSioSts = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bStatus;

	return(!(bSioSts & 0x20));
}

/*
 *  ��M�@�\�̏�Ԃ��擾
 */
Inline BOOL
sio_get_rxready(UB ch_no)
{
	UB	bSioSts;

	bSioSts = ((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bStatus;

	return(bSioSts & 0x01);
}

/*
 *  ��M����1������ǂݍ���
 */
Inline INT
sio_rcv_chr(SIOPCB *siopcb)
{
	BOOL	blRxSts;
	UB	ch_no;


	ch_no = siopcb->inib->ch_no;
	blRxSts  = sio_get_rxready(ch_no);

	if(blRxSts){
		return (((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bRxd);
	}

	return (-1);
}

/*
 *  ���M����1��������������
 */
Inline BOOL
sio_snd_chr(SIOPCB *siopcb, char c)
{
	BOOL	blTxSts;
	UB	ch_no;

	ch_no = siopcb->inib->ch_no;
	blTxSts = sio_get_txready(ch_no);
	if(blTxSts){
		((s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bTxd = c;
	}

	return(blTxSts);
}

/*
 *  �w�肳�ꂽSIO�`���l���̊��荞�ݗv�����N���A����
 */
Inline void
sio_clr_factor(UB bFlag)
{
	((volatile s1c33Intc_t *) S1C33_INTC_BASE)->bIntFactor[6] |= bFlag;
}

/*  �w�肳�ꂽSIO�`���l���̃G���[�t���O���N���A����
 *
 */
Inline void
sio_clr_errflag(UB ch_no)
{
	((volatile s1c33Serial_t *)S1C33_SERIAL_BASE)->stChannel01[ch_no].bStatus
		&= ~(SIO_ERR_OVERRUN | SIO_ERR_PARITY | SIO_ERR_FRAME);
}

#endif /* _MACRO_ONLY   */
#endif /* _HW_SERIAL_H_ */
