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
 *  @(#) $Id: st16c2550.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *   ST16C2550 �p �Ȉ�SIO�h���C�o
 */
#ifndef _ST16C2550_H_
#define _ST16C2550_H_

#include <t_config.h>

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block {
    UW reg_base;    /* ���W�X�^�̃x�[�X�A�h���X */
    UB lcr_val;     /* ���[�h���W�X�^�̐ݒ�l   */
    UB dlm_val;     /* �{�[���[�g��ʂ̐ݒ�l   */
    UB dll_val;     /* �{�[���[�g���ʂ̐ݒ�l   */
    UW pinter_val;  /* �����݋��r�b�g   */    
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N
 */
typedef struct sio_port_control_block {
    const SIOPINIB  *siopinib; /* �V���A��I/O�|�[�g�������u���b�N */
    VP_INT          exinf;     /* �g����� */
    BOOL    openflag;          /* �I�[�v���ς݃t���O */
    BOOL    sendflag;          /* ���M�����݃C�l�[�u���t���O */
    BOOL    getready;          /* ��������M������� */
    BOOL    putready;          /* �����𑗐M�ł����� */
}SIOPCB;


/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND    1u      /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u      /* ��M�ʒm�R�[���o�b�N */


/*
 * �J�[�l���N�����p�̏�����(sys_putc���g�p���邽��)
 */
extern void st16c2550_init(void);

/*
 *  �V���A��I/O�|�[�g�ւ̃|�[�����O�ł̏o��
 */
extern void st16c2550_pol_putc(char c, ID siopid);


/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void st16c2550_initialize(void);


/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL st16c2550_openflag(void);


/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB   *st16c2550_opn_por(ID siopid, VP_INT exinf);


/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void st16c2550_cls_por(SIOPCB *siopcb);


/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL st16c2550_snd_chr(SIOPCB *siopcb, char c);


/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT  st16c2550_rcv_chr(SIOPCB *siopcb);


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void st16c2550_ena_cbr(SIOPCB *siopcb, UINT cbrtn);


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void st16c2550_dis_cbr(SIOPCB *siopcb, UINT cbrtn);


/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void st16c2550_isr(void);


/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void st16c2550_ierdy_snd(VP_INT exinf);


/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void st16c2550_ierdy_rcv(VP_INT exinf);


#endif /* _FDC37C935A_H_ */
