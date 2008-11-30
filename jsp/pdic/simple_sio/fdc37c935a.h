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
 *  @(#) $Id: fdc37c935a.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 * �X�[�pI/O FDC37C935A �p�h���C�o
 */
#ifndef _FDC37C935A_H_
#define _FDC37C935A_H_

#include <t_config.h>

/*
 * �x�[�X�A�h���X 
 */
//#define SMSC_BASE_ADDR 0xB0400000

#define SMSC_CONFIG_PORT (SMSC_BASE_ADDR + 0x7E0)  /* H */
#define SMSC_INDEX_PORT  (SMSC_BASE_ADDR + 0x7E0)  /* H */
#define SMSC_DATA_PORT   (SMSC_BASE_ADDR + 0x7E2)  /* H */


#ifndef _MACRO_ONLY

Inline void
smsc_config_write(UH index, UH data)
{
    sil_wrh_mem((VP)SMSC_INDEX_PORT, (index << 8));
    sil_wrh_mem((VP)SMSC_DATA_PORT, (data << 8));
}

Inline UH
smsc_config_read(UH index)
{
    sil_wrh_mem((VP)SMSC_INDEX_PORT, (index << 8));
    return(sil_reh_mem((VP)SMSC_DATA_PORT) >> 8);
}

/*
 *  ������
 */
extern void smsc_init(void);



#endif /*  _MACRO_ONLY */


/*
 * SCI0
 */
#define SMSC_SCI0_BASE_ADDR  0x03f8

#define SMSC_SCI0_RBR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x0)  /* H */
#define SMSC_SCI0_THR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x0)  /* H */
#define SMSC_SCI0_DLL (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x0)  /* H */
#define SMSC_SCI0_IER (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x2)  /* H */
#define SMSC_SCI0_DLM (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x2)  /* H */
#define SMSC_SCI0_IIR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x4)  /* H */
#define SMSC_SCI0_FCR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x4)  /* H */
#define SMSC_SCI0_LCR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x6)  /* H */
#define SMSC_SCI0_MCR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0x8)  /* H */
#define SMSC_SCI0_LSR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0xA)  /* H */
#define SMSC_SCI0_MSR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0xC)  /* H */
#define SMSC_SCI0_SCR (SMSC_BASE_ADDR + SMSC_SCI0_BASE_ADDR * 2 + 0xE)  /* H */

/*
 *  �X�[�p�[I/O(FDC37C935A)�p �Ȉ�SIO�h���C�o
 */

#ifndef _MACRO_ONLY

/*
 *  �����݈ȊO�̏�����
 *  �J�[�l���N�����p�̏�����(sys_putc���g�p���邽��)
 */
extern void fdc37c935a_init(void);


/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
typedef struct sio_port_control_block   SIOPCB;

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND    1u      /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u      /* ��M�ʒm�R�[���o�b�N */


/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void smsc_sci0_initialize(void);


/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL smsc_sci0_openflag(void);


/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB   *smsc_sci0_opn_por(ID siopid, VP_INT exinf);


/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void smsc_sci0_cls_por(SIOPCB *siopcb);


/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL smsc_sci0_snd_chr(SIOPCB *siopcb, char c);


/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT  smsc_sci0_rcv_chr(SIOPCB *siopcb);


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void smsc_sci0_ena_cbr(SIOPCB *siopcb, UINT cbrtn);


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void smsc_sci0_dis_cbr(SIOPCB *siopcb, UINT cbrtn);


/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void smsc_sci0_isr(void);


/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void smsc_sci0_ierdy_snd(VP_INT exinf);


/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void smsc_sci0_ierdy_rcv(VP_INT exinf);




#endif /* _MACRO_ONLY */


#endif /* _FDC37C935A_H_ */
