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
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */



/*
 *  TOPPERS/JSP for Windows - �V���A���G�~�����[�^
 */

#ifndef __HW_SERIAL_H
#define __HW_SERIAL_H

#include <s_services.h>

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 *  OPB_UARTLITE �́C����M�����݂�������Ă��Ȃ����߁C�Ӗ��͂Ȃ��D
 */
#define SIO_ERDY_SND    1u              /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u              /* ��M�ʒm�R�[���o�b�N */

	/* �f�o�C�X���J�����̐ݒ� */
#define SIO_MOD_MASK		0x80000000
#define SIO_MOD(x)			((x) & SIO_MOD_MASK)
#define SIO_MOD_SERVER		0x80000000
#define SIO_MOD_CLIENT		0x00000000

	/* �f�o�C�X�̎�� */
#define SIO_TYP_MASK		0x000000ff
#define SIO_TYP(x)			((x) & SIO_TYP_MASK)
#define SIO_TYP_CONSOLE		0x00000001			/* �E�B���h�E�R���\�[��  */
#define SIO_TYP_TTY			0x00000002			/* Windows�̃R���\�[�� */
#define SIO_TYP_SCRBUF		0x00000003			/* �X�N���[���o�b�t�@    */
#define SIO_TYP_RAWSIO		0x00000004			/* �V���A��              */

	/* �f�o�C�X�̏�� */
#define SIO_STA_MASK		0x0fff0000
#define SIO_STA(x)			((x) & SIO_STA_MASK)
#define SIO_STA_OPEN		0x00010000
#define SIO_STA_INTRCV		0x00020000
#define SIO_STA_INTSND		0x00040000

#define INHNO_SERIAL	3

#define TNUM_PORT		1

#ifndef _MACRO_ONLY

typedef struct serial_port_descriptor
{
	int					Flag;
	HANDLE				Handle;
	volatile int		ReceiveBuffer;
	void *				versatile;
	VP_INT              exinf;
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void	sio_initialize(void);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB * sio_opn_por(ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void	sio_cls_por(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL	sio_snd_chr(SIOPCB *siopcb, INT chr);

/*
 *  �V���A��I/O�|�[�g�ւ̕�����M
 */
extern INT	sio_rcv_chr(SIOPCB *siopcb);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void	sio_isr(void);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void sio_ena_cbr(SIOPCB * siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void sio_dis_cbr(SIOPCB * siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M�����R�[���o�b�N
 */
extern void sio_ierdy_snd(VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�ւ̕�����M�����R�[���o�b�N
 */
extern void sio_ierdy_rcv(VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̕�����M�ʒm�R�[���o�b�N
 */
extern void	sio_ercv_chr(ID siopid, INT chr);

/*
 *  �V���A��I/O�|�[�g�����݃n���h��
 */
extern void	sio_handler(void);

#endif

#endif

