/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 *	�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iTI16PIR552�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <tl16pir552.h>		/* siopcb, tl16pir552_openflag */

/*
 *  SIO�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SIO1		INTNO_SERIAL0
#define INHNO_SIO2		INTNO_SERIAL1

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize		tl16pir552_initialize

/*
 *  �J�[�l���N�����p�̏����� (sys_putc�ŗ��p)
 */
#define sio_init		tl16pir552_init

#ifndef _MACRO_ONLY

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;
	BOOL	openflag;

	UB	mask = 0;

	/*
	 *  �I�[�v�������|�[�g�����邩�� openflag �ɓǂ�ł����D
	 */
	openflag = tl16pir552_openflag();

	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	siopcb = tl16pir552_opn_por(siopid, exinf);

	/*
	 *  �V���A��I/O�����݂̊����݃��x����ݒ肵�C�}�X�N����������D
	 */
	if (!openflag) {
		switch(siopid) {
		case 1 :	/* �|�[�g�P; �V���A���O */
			all_set_ilv( INTNO_SERIAL0, &((IPM) IPM_SCC0) );
							/* �����݃��x���ݒ� */
			mask = SERIAL0;
			break;
		case 2 :	/* �|�[�g�Q; �V���A���P */
			all_set_ilv( INTNO_SERIAL1, &((IPM) IPM_SCC1) );
							/* �����݃��x���ݒ� */
			mask = SERIAL1;
			break;
		}
		icu_orb( (VP) ICU_INT0M, mask );
							/* �}�X�N�ݒ菈�� */
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
	tl16pir552_cls_por(siopcb);

	/*
	 *  �V���A��I/O�����݂��}�X�N����D(�|�[�g�P�A�Q�̗���)
	 */
	if (!tl16pir552_openflag) {
		icu_andb( (VP) ICU_INT0M, ~(SERIAL0 | SERIAL1) );
							/* �}�X�N�ݒ菈�� */
	}
}

#endif /* _MACRO_ONLY */

/*
 *  SIO�̊����݃n���h��
 */
#define	sio1_handler		tl16pir552_uart0_isr
#if TNUM_SIOP >= 2
#define sio2_handler		tl16pir552_uart1_isr
#endif /* TNUM_SIOP */

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr		tl16pir552_snd_chr

/*
 *  �V���A��I/O�|�[�g�ւ̕������M�i�|�[�����O�j
 */
#define	sio_snd_chr_pol		tl16pir552_putchar_pol

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr		tl16pir552_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr		tl16pir552_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr		tl16pir552_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define	sio_ierdy_snd		tl16pir552_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define	sio_ierdy_rcv		tl16pir552_ierdy_rcv

#endif /* _HW_SERIAL_H_ */
