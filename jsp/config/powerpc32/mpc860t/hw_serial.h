/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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
 * 
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *�@�@�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iMPC860T�p�j
 *�@�@�@�@MPC860T�����V���A���E�}�l�[�W�����g�R���g���[��SMC1���g�p
 *
 *�@�@�@�@smc.{c,h}��hw_serial.h�̕����̊
 *�@�@�@�@�@�@�Esmc.{c,h}�F�V���A���f�o�C�X�Ɉˑ����镔���̂݋L�q
 *�@�@�@�@�@�@�Ehw_serial.h�F�V���A���f�o�C�X�ȊO�ɋN�����鎖����
 *�@�@�@�@ �@�@�@�@�@�@�@�@�@hw_serial.h�ɋL�q����
 *�@�@�@�@�@�@�@�@�@�@�@�@�@�@�����݃R���g���[���ˑ��Ȃ�
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#ifndef _MACRO_ONLY
#include <mpc860_smc.h>
#endif /* _MACRO_ONLY */

/*
 *  SIO�̊����݃n���h���̃x�N�^�ԍ��i����M���ʁj
 */
#define INHNO_SERIAL	INTNO_SMC1

/*
 *�@SIU���猩��CPM�����݃\�[�X�̊����݃��x���͈�܂Ƃ߂ɂȂ�A
 *�@CPM���ł̊����݃��x���̓n�[�h�E�F�A�ɂ�茈�肳���B
 *�@���̂��߁ASMC1�ŗL��IPM�͗p�ӂ��Ă��Ȃ��B
 */

#ifndef _MACRO_ONLY

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize	smc_initialize

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB	*siopcb;

	/*
	 *  �f�o�C�X�ˑ��̃I�[�v�������D
	 */
	siopcb = smc_opn_por(siopid, exinf);

    	/*
    	 *  CPM�����݃R���g���[���̐ݒ�
    	 *  �@CPM�����݃R���t�B�M�����[�V�����E���W�X�^CICR��
    	 *  �@�ݒ��CPU�̏������ōs���Ă���Ƃ���
    	 *  �@�i�����݃R���g���[���ˑ����j
    	 *  �@
    	 *  �@CPM���ł̊����ݏ��ʂ͌Œ肳��Ă���B
    	 *  �@�iSCC�������j
    	 */
    	mpc860_orw_mem(CIMR, CIMR_SMC1);	/*  SMC1�����݂�����  */

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
	smc_cls_por(siopcb);

	if (!smc_openflag()) {
		/*  ���ׂẴ|�[�g���N���[�Y����Ă����  */
		/*  �V���A���f�o�C�X�ւ̃N���b�N������~  */
	}

    	/*
    	 *  CPM�����݃R���g���[���̐ݒ�
    	 *  �@�i�����݃R���g���[���ˑ����j
    	 */
    	mpc860_andw_mem(CIMR, ~CIMR_SMC1);	/*  SMC1�����݂��֎~  */
}

/*
 *  SIO�̊����݃n���h���i����M���ʁj
 */
#define	sio_handler	smc_isr

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr	smc_snd_chr

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr	smc_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr	smc_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr	smc_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 *  �@�@jsp/systask/serial.c�ɂ�����̂����l�[�����Ă���
 *  �@�@�i���̑O���Q�Ɓj
 */
#define	sio_ierdy_snd	smc_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 *  �@�@jsp/systask/serial.c�ɂ�����̂����l�[�����Ă���
 *  �@�@�i���̑O���Q�Ɓj
 */
#define	sio_ierdy_rcv	smc_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
/*  end of file  */
