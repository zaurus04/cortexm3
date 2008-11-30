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
 *  @(#) $Id: hw_serial.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *  �^�[�Q�b�g�ˑ��V���A��I/O���W���[���iH8�p�j
 *    �E�|�[�g�� 1�{�̏ꍇ�� HWPORT1_ADDR�Ɏw�肳�ꂽ�|�[�g���g�p���A
 *      2�{�̏ꍇ�́AHWPORT1_ADDR�����[�U�p�AHWPORT2_ADDR���R���\�[��
 *      �o�͂Ƃ��Ďg�p����B
 *      HWPORTx_ADDR�� �^�[�Q�b�g�ˑ��� sys_config.h���Ŏw�肷��B
 *    �E���ʕ��̃��W���[���ɂ���āAXON/XOFF�t���[���䂪�s��
 *      ��Ă���̂ŁA�M������TxD��RxD��2�{�ł悢
 */

#include "jsp_kernel.h"
#include <hw_serial.h>
#include <h8_sil.h>

/*
 *  �{�[���[�g��1�r�b�g���̎���[nsec]�ɕϊ�����}�N��
 *  �@���Z�̓r���ŃI�[�o�[�t���[���Ȃ��悤long�^�萔��p���Ă���
 */
#define BAUD_TO_NSEC(b)       (UINT)(((1000000ul / (b)) + 1ul) * 1000ul)

/*
 *  �{�[���[�g��BRR�̒l�ɕϊ�����}�N��
 */
#define H8BRR_RATE(b)	(((b)>38400)?((UB)(((CPU_CLOCK+(16*(b)))/(32*(b)))-1))\
			          :((UB)((CPU_CLOCK/(32*(b)))-1)))

/*
 *  �V���A���|�[�g�̏������u���b�N
 */

static const SIOPINIB siopinib_table[TNUM_PORT] = {
	{
		SYSTEM_SCI,
		SYSTEM_BAUD_RATE,
                {
                        (UB*)SYSTEM_SCI_IPR,
                        SYSTEM_SCI_IP_BIT,
                        SYSTEM_SCI_IPM
                },
		SYSTEM_SCI_SMR
	}

#if TNUM_PORT >= 2
	,{
		USER_SCI,
		USER_BAUD_RATE,
                {
                        (UB*)USER_SCI_IPR,
                        USER_SCI_IP_BIT,
                        USER_SCI_IPM
                },
		USER_SCI_SMR
	}
#endif	/* of #if TNUM_PORT >= 2 */

#if TNUM_PORT >= 3
	,{
		USER2_SCI,
		USER2_BAUD_RATE,
                {
                        (UB*)USER2_SCI_IPR,
                        USER2_SCI_IP_BIT,
                        USER2_SCI_IPM
                },
		USER2_SCI_SMR
	}
#endif	/* of #if TNUM_PORT >= 3 */

};


/*
 *  �V���A���|�[�g�̐���u���b�N
 */

SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ����Ǘ��u���b�N�ւ̕ϊ��}�N��
 */

#define get_siopinib(sioid)	(&(siopinib_table[INDEX_SIO(sioid)]))

/*
 *  SCI �̏�����
 */

void
SCI_initialize (ID sioid)
{
	const SIOPINIB	*inib;

	inib = get_siopinib(sioid);
	SCI_cls_por(inib->base);
			/*
			 *�@���[�h�ݒ�
			 *�@�@�E����������
			 *�@�@�E�L�����N�^��
			 *�@�@�E�p���e�B
			 *�@�@�E�X�g�b�v�r�b�g��
			 *�@�@�E�N���b�N�I��
			 */
	sil_wrb_mem((VP)(inib->base + H8SMR), inib->smr_init);

					/*  �{�[���[�g�ݒ�  	*/
	sil_wrb_mem((VP)(inib->base + H8BRR), H8BRR_RATE(inib->baudrate));

			/* �����݋֎~�ƃN���b�N�\�[�X�̑I��	*/
	h8_anb_reg((UB *)(inib->base + H8SCR),
            	    (UB)~(H8SCR_TIE  | H8SCR_RIE  | H8SCR_MPIE |
            	          H8SCR_TEIE | H8SCR_CKE1 | H8SCR_CKE0 ));

	/* �{�[���[�g�̐ݒ��A1�r�b�g���҂��Ȃ���΂Ȃ�Ȃ��B*/
	sil_dly_nse(BAUD_TO_NSEC(inib->baudrate));

					/* �G���[�t���O���N���A		*/
	h8_anb_reg((UB *)(inib->base + H8SSR),
	            ~(H8SSR_ORER | H8SSR_FER | H8SSR_PER));

        /*
         *  �v���C�I���e�B���x���̐ݒ�
         *      �{���͊����݃R���g���[���ˑ������𕪗����ׂ�
         */
        define_int_plevel(&(inib->irc));

	/* ��M���荞�݂Ƒ��M�����݂̋��̓V���A�� I/O �ōs�� */
	/* ����M���� */
	h8_orb_reg((VP)(inib->base + H8SCR), (H8SCR_TE | H8SCR_RE));
}

/*
 *  SCI �̃N���[�Y
 */

void
SCI_cls_por (UW base)
{
	/* TDRE �� 1 �ɂȂ�܂ő҂� */
	while ((sil_reb_mem((VP)(base + H8SSR)) & H8SSR_TDRE) == 0)
		;

	/* 11�r�b�g���M���҂B*/
	sil_dly_nse(11*BAUD_TO_NSEC(H8_MIN_BAUD_RATE));
					/* ����M��~		*/
	h8_anb_reg((UB *)(base + H8SCR),
	           (UB)~(H8SCR_TIE | H8SCR_RIE | H8SCR_TE | H8SCR_RE));
}

/*
 *  SCI_in_handler -- SCI ���͊����݃n���h��
 */

void
SCI_in_handler(ID sioid)
{
	SIOPCB	*pcb;
	UB	status;
	
	pcb = get_siopcb(sioid);
	status = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
	
	if (status & (H8SSR_ORER | H8SSR_FER | H8SSR_PER)) {

		/* �G���[����		*/

	    	/* �G���[�t���O���N���A	*/
		sil_wrb_mem((VP)(pcb->inib->base + H8SSR),
		            status & ~(H8SSR_ORER | H8SSR_FER | H8SSR_PER));
	}

	if (status & H8SSR_RDRF) {
		if (pcb->openflag) {
			/* ��M�\�R�[���o�b�N���[�`�����ďo���B*/
			SCI_ierdy_rcv(pcb->exinf);
		} else {
			sil_wrb_mem((VP)(pcb->inib->base + H8SSR), 
			             status & ~H8SSR_RDRF);
		}
	}
}

/*
 *  SCI_out_handler -- SCI �o�͊����݃n���h��
 */

void
SCI_out_handler(ID sioid)
{
	SIOPCB	*pcb;

	pcb = get_siopcb(sioid);
	if (pcb->openflag) {
		/* ���M�\�R�[���o�b�N���[�`�����ďo���B*/
		SCI_ierdy_snd(pcb->exinf);
	}
}

#ifdef H8_CFG_SCI_ERR_HANDLER

/*
 *  SCI_err_handler -- SCI �G���[���͊����݃n���h��
 */

void
SCI_err_handler(ID sioid)
{
	SIOPCB	*pcb;
	UB	status;

	pcb = get_siopcb(sioid);
	status = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
	if (status & (H8SSR_ORER | H8SSR_FER | H8SSR_PER)) {

		/* �G���[����		*/

	    	/* �G���[�t���O���N���A	*/
		sil_wrb_mem((VP)(pcb->inib->base + H8SSR),
		            status & ~(H8SSR_ORER | H8SSR_FER | H8SSR_PER));
	}
}

#endif	/* of #ifdef H8_CFG_SCI_ERR_HANDLER */

/*
 *  sio_initialize -- �V���A���|�[�g�h���C�o�̏�����
 */

void
sio_initialize (void)
{
	int ix;

	/* SIO �Ǘ��u���b�N�̏����� */
	for (ix = TNUM_PORT; ix -- > 0; ) {
		siopcb_table[ix].inib     = &siopinib_table[ix];
		siopcb_table[ix].openflag = FALSE;
	}
}

/*
 *  sio_ena_cbr -- �V���A�� I/O ����̃R�[���o�b�N�̋���
 */

void
sio_ena_cbr(SIOPCB *pcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		SCI_enable_send(pcb);
		break;
	case SIO_ERDY_RCV:
		SCI_enable_recv(pcb);
		break;
	}
}

/*
 *  sio_dis_cbr -- �V���A�� I/O ����̃R�[���o�b�N�̋֎~
 */

void
sio_dis_cbr(SIOPCB *pcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:
		SCI_disable_send(pcb);
		break;
	case SIO_ERDY_RCV:
		SCI_disable_recv(pcb);
		break;
	}
}

/*
 *  SCI ���荞��
 */

void
sio_in_handler (void)
{
	SCI_in_handler(1);
}

void
sio_out_handler (void)
{
	SCI_out_handler(1);
}

#ifdef H8_CFG_SCI_ERR_HANDLER

void
sio_err_handler (void)
{
	SCI_err_handler(1);
}

#endif	/* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#if TNUM_PORT >= 2

void
sio_in2_handler (void)
{
	SCI_in_handler(2);
}

void
sio_out2_handler (void)
{
	SCI_out_handler(2);
}

#ifdef H8_CFG_SCI_ERR_HANDLER

void
sio_err2_handler (void)
{
	SCI_err_handler(2);
}

#endif	/* of #ifdef H8_CFG_SCI_ERR_HANDLER */
#endif	/* of #if TNUM_PORT >= 2 */

#if TNUM_PORT >= 3

void
sio_in3_handler (void)
{
	SCI_in_handler(3);
}

void
sio_out3_handler (void)
{
	SCI_out_handler(3);
}

#ifdef H8_CFG_SCI_ERR_HANDLER

void
sio_err3_handler (void)
{
	SCI_err_handler(3);
}

#endif	/* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#endif	/* of #if TNUM_PORT >= 3 */
