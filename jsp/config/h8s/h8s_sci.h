/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

#ifndef _H8S_SCI_H_
#define _H8S_SCI_H_

#include <s_services.h>		/* �f�o�C�X�h���C�o�p�W���C���N���[�h�t�@�C�� */
#include <h8s_sil.h>

/*
 *  H8S �����V���A���R�~���j�P�[�V�����C���^�t�F�[�X(SCI)�֘A�̒�`
 */

/* SCI���W�X�^�̃A�h���X */
/* �x�[�X�A�h���X */
#define SCI0_BASE_ADDR	0xff78	/* �`���l���O */
#define SCI1_BASE_ADDR	0xff80	/* �`���l���P */
/* ���W�X�^�I�t�Z�b�g */
#define SMR		0	/* �V���A�����[�h���W�X�^�^ */
#define BRR		1	/* �r�b�g���[�g���W�X�^ */
#define SCR		2	/* �V���A���R���g���[�����W�X�^ */
#define TDR		3	/* �g�����X�~�b�g�f�[�^���W�X�^ */
#define SSR		4	/* �V���A���X�e�[�^�X���W�X�^ */
#define RDR		5	/* ���V�[�u�f�[�^���W�X�^ */
#define SCMR		6	/* �X�}�[�g�J�[�h���[�h���W�X�^ */

/* �e���W�X�^�̃r�b�g�p�^�[�� */

/* RSR, RDR, TSR, TDR */
/* ��`���ׂ����̂́A���ɖ��� */

/* SMR */
#define CA	BIT7
#define	CHR	BIT6	/* 8bit = 0 / 7bit = 1 */
#define	PE	BIT5	/* Parity OFF = 0 / Parity ON = 1 */
#define	OE	BIT4	/* EVEN Parity = 0 / ODD Parity = 1 */
#define	STOP	BIT3	/* 1 STOP BIT = 0 / 2 STOP BIT = 1 */
#define MP	BIT2
#define	CSK1	BIT1
#define	CSK0	BIT0

/* SCR */
#define TIE	BIT7
#define	RIE	BIT6
#define	TE	BIT5
#define	RE	BIT4
#define	MPIE	BIT3
#define TEIE	BIT2
#define	CKE1	BIT1
#define	CKE0	BIT0

/* SSR */
#define TDRE	BIT7
#define	RDRF	BIT6
#define	ORER	BIT5
#define	FER	BIT4
#define	PER	BIT3
#define TEND	BIT2
#define	MPB	BIT1
#define	MPBT	BIT0

/*
 *  �{�[���[�g�֌W�̒�`
 *    ������g���F20 [MHz] �Ȃ̂ŁA�}�j���A��p567��茈�܂�B
 */
#if BAUD_RATE == 9600		/* �r�b�g���[�g�F 9600 [bit/s] */
	#define BRR_RATE	64	/* N = 64 */
#elif BAUD_RATE == 38400	/* �r�b�g���[�g�F38400 [bit/s] */
	#define BRR_RATE	15	/* N = 15 */
#elif BAUD_RATE == 57600	/* �r�b�g���[�g�F57600 [bit/s] */
	#define BRR_RATE	10	/* N = 10 */
#endif

#ifndef _MACRO_ONLY

/*
 *  �V���A��I/O�|�[�g�������u���b�N
 */
typedef struct sio_port_control_block	SIOPCB;

#endif /* _MACRO_ONLY */

/*
 *  SCI�p�V�X�e���C���^�t�F�[�X���C���[
 */
/* x : �|�[�g�̃x�[�X�A�h���X(UW �^)
   y : ���W�X�^�I�t�Z�b�g(UW �^)
   z : ���W�X�^�l */
#define h8s_sci_wrb( x, y, z )	h8s_wrb_mem( (VP)(x + y), z )
#define h8s_sci_reb( x, y )	h8s_reb_mem( (VP)(x + y) )

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND	1u		/* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV	2u		/* ��M�ʒm�R�[���o�b�N */

#ifndef _MACRO_ONLY

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void	h8s_sci_initialize(void);

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL	h8s_sci_openflag(void);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB	*h8s_sci_opn_por(ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void	h8s_sci_cls_por(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL	h8s_sci_snd_chr(SIOPCB *siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT	h8s_sci_rcv_chr(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void	h8s_sci_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void	h8s_sci_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void	h8s_sci_isr_in(void);
extern void	h8s_sci_isr_out(void);

/*
 *  SIO�̎�M�G���[�����݃T�[�r�X���[�`��
 */
extern void	h8s_sci_isr_error(void);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void	h8s_sci_ierdy_snd(VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void	h8s_sci_ierdy_rcv(VP_INT exinf);

/*
 *  �J�[�l���N�����p�̏����� (sys_putc�ŗ��p)
 */
extern void	h8s_sci_init(void);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M�i�|�[�����O�j
 */
extern void	h8s_sci_putchar_pol(char c);

#endif /* _MACRO_ONLY */

#endif /* _H8S_sci_H_ */
