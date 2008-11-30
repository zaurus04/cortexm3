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
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *  �V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iMS7717CP01�p�j
 *  
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>

#include <sh3.h>
#include <ms7727cp01.h>
#include <st16c2550.h>

/*
 *  �V���A���̊����݃n���h���̃x�N�^�ԍ�(�����ݗD��x)
 */
#define INHNO_SIO   ST16C2550_INT

/*
 * ���荞�݃��x��
 */
#define SIO_INTLVL   8

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define sio_initialize  st16c2550_initialize

#ifndef _MACRO_ONLY
/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB  *siopcb;
    BOOL    openflag;

    /*
     *  �I�[�v�������|�[�g�����邩�� openflg �ɓǂ�ł����D
     */
    openflag = st16c2550_openflag();
    
    /*
     *  �f�o�C�X�ˑ��̃I�[�v�������D
     */
    siopcb = st16c2550_opn_por(siopid, exinf);

    /*
     * ���荞�݊֘A�̐ݒ�
     * �G���[�n���h�����o�^���ׂ�
     */
    if(!openflag){
        define_int_plevel(INHNO_SIO,SIO_INTLVL);     /* SW�D��x */
        sil_wrh_mem((VP)IPRD,                        /* HW�D��x */  
                    (sil_reh_mem((VP)IPRD) | (SIO_INTLVL << 12))); 
        /* PINT�C�l�[�u�� */
        sil_wrh_mem((VP)PINTER,
                    (sil_reh_mem((VP)PINTER) | siopcb->siopinib->pinter_val));
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
    st16c2550_cls_por(siopcb);
}


/*
 *  SIO�̊����݃n���h��
 */
#define sio_handler st16c2550_isr

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define sio_snd_chr st16c2550_snd_chr

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define sio_rcv_chr st16c2550_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define sio_ena_cbr st16c2550_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define sio_dis_cbr st16c2550_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define sio_ierdy_snd   st16c2550_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define sio_ierdy_rcv   st16c2550_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
