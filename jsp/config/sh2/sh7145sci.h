/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 *  @(#) $Id: sh7145sci.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

/*
 *   SH2�����V���A���R�~���j�P�[�V�����C���^�t�F�[�XSCI�p �ȈՃh���C�o
 */

#ifndef _sh7145sci_H_
#define _sh7145sci_H_

#include <t_config.h>

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_initialization_block
{
	UW reg_base;				/* ���W�X�^�̃x�[�X�A�h���X */
	UB brr;						/* �{�[���[�g�̐ݒ�l   */
	UB smr;						/* ���[�h���W�X�^�̐ݒ�l   */
	UB int_level;				/* ���荞�݃��x���̐ݒ�l   */
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N
 */
typedef struct sio_port_control_block
{
	const SIOPINIB *siopinib;	/* �V���A��I/O�|�[�g�������u���b�N */
	VP_INT exinf;				/* �g����� */
	BOOL openflag;				/* �I�[�v���ς݃t���O */
	BOOL sendflag;				/* ���M�����݃C�l�[�u���t���O */
	BOOL getready;				/* ��������M������� */
	BOOL putready;				/* �����𑗐M�ł����� */
} SIOPCB;

/*
 *  �R���g���[�����W�X�^�̃A�h���X�̃I�t�Z�b�g 
 */
#define SCI_SCR	0x2
#define SCI_SSR	0x4
#define SCI_BRR	0x1
#define SCI_SMR	0x0
#define SCI_TDR	0x3
#define SCI_RDR	0x5
#define SCI_SDCR 0x6


/*
 *  �R���g���[�����W�X�^�̐ݒ�l
 */
#define SCI_TIE		0x80		/* �g�����X�~�b�g�C���^���v�g�C�l�[�u�� */
#define SCI_RIE		0x40		/* ���V�[�u�C���^���v�g�C�l�[�u��   */
#define SCI_TE		0x20		/* �g�����X�~�b�g�C�l�[�u��         */
#define SCI_RE		0x10		/* ���V�[�u�C�l�[�u��           */
#define SSR_ORER	0x20		/* �I�[�o�[�����G���[           */
#define SSR_FER		0x10		/* �t���[�~���O�G���[           */
#define SSR_PER		0x08		/* �p���e�B�G���[           */
#define SSR_TDRE	0x80		/* �g�����X�~�b�g�f�[�^���W�X�^�G���v�e�B */
#define SSR_RDRF	0x40		/* ���V�[�u�f�[�^���W�X�^�t��       */

#define sh2sci_DELAY 	105000

#define PFC_TXD0	0x0004
#define PFC_RXD0	0x0001
#define PFC_TXD1	0x0100
#define PFC_RXD1	0x0040
#define PFC_TXD2	0x0020
#define PFC_RXD2	0x8000

/*
 *  SCI�̐ݒ�
 */
#define SMR_CKS 	0x0			/*  ������          */
#define BRR9600 	79			/*  9600 �r�b�g���[�g    */
#define BRR19200	39			/*  19200 �r�b�g���[�g    */
#define BRR38400	19			/*  38400 �r�b�g���[�g    */

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND	1u		/* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV	2u		/* ��M�ʒm�R�[���o�b�N */

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void sh2sci_initialize (void);

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL sh2sci_openflag (ID siopid);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB *sh2sci_opn_por (ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void sh2sci_cls_por (SIOPCB * siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL sh2sci_snd_chr (SIOPCB * siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT sh2sci_rcv_chr (SIOPCB * siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void sh2sci_ena_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void sh2sci_dis_cbr (SIOPCB * siopcb, UINT cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void sh2sci_isr (void);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void sh2sci_ierdy_snd (VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void sh2sci_ierdy_rcv (VP_INT exinf);

#endif /* _sh7145sci_H_ */
