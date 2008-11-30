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
 *	�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iVR4131����DSIU�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <vr4131_dsiu.h>		/* siopcb, vr4131_dsiu_openflag */

/*
 *  SIO�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SIO		INTNO_DSIU

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize		vr4131_dsiu_initialize

/*
 *  �J�[�l���N�����p�̏����� (sys_putc�ŗ��p)
 */
#define sio_init		vr4131_dsiu_init

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
	 *  �I�[�v�������|�[�g�����邩�� openflag �ɓǂ�ł����D
	 */
	openflag = vr4131_dsiu_openflag();

	/*
	 * DSIU�ւ̃N���b�N�����J�n
	 */
	vr4131_orh( (VP) CMUCLKMSK, (MSKDSIU | MSKSSIU | MSKSIU) );

	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	siopcb = vr4131_dsiu_opn_por(siopid, exinf);

	/*
	 *  �V���A��I/O�����݂̊����݃��x����ݒ肵�C�}�X�N����������D
	 */
	if (!openflag) {
		/* �����݃��x���ݒ� */
		all_set_ilv( (UINT) INTNO_DSIU, &((IPM) IPM_DSIU) );

		/* �}�X�N��������(���x���P) */
		vr4131_orh( (VP) MSYSINT2REG, DSIUINTR );

		/* �}�X�N��������(���x���Q) */
		vr4131_orh( (VP) MDSIUINTREG, INTDSIU );
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
	 *  �V���A��I/O�����݂��}�X�N����D
	 */
	if (!vr4131_dsiu_openflag) {
		/* �}�X�N�ݒ菈��(���x���P) */
		vr4131_andh( (VP) MSYSINT2REG, ~DSIUINTR );

		/* �}�X�N�ݒ菈��(���x���Q) */
		vr4131_andh( (VP) MDSIUINTREG, ~INTDSIU );
	}

	/*
	 *  �f�o�C�X�ˑ��̃N���[�Y�����D
	 */
	vr4131_dsiu_cls_por(siopcb);

	/*
	 *  DSIU�ւ̃N���b�N������~
	 */
	vr4131_andh( (VP) CMUCLKMSK, ~(MSKDSIU | MSKSSIU | MSKSIU) );

}

#endif /* _MACRO_ONLY */

/*
 *  SIO�̊����݃n���h��
 */
#define	sio_handler		vr4131_dsiu_isr

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr		vr4131_dsiu_snd_chr

/*
 *  �V���A��I/O�|�[�g�ւ̕������M�i�|�[�����O�j
 */
#define	sio_snd_chr_pol		vr4131_dsiu_putchar_pol

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr		vr4131_dsiu_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr		vr4131_dsiu_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr		vr4131_dsiu_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define	sio_ierdy_snd		vr4131_dsiu_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define	sio_ierdy_rcv		vr4131_dsiu_ierdy_rcv

#endif /* _HW_SERIAL_H_ */
