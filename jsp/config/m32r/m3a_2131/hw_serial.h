/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *	�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iM32102�����񓯊��V���A���p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <sil.h>
#include <s_services.h>

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND    1u              /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u              /* ��M�ʒm�R�[���o�b�N */

/*
 *  �V���A��I/O�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SERIAL_IN		(48 + ((CONSOLE_PORTID-1)*2))
#define INHNO_SERIAL_OUT	(49 + ((CONSOLE_PORTID-1)*2))

#define SIO_TYP(x)				( (x) & 0x000000ff )
#define SIO_TYP_M32RUART	0x00000001

#define SIO_STS(x)				( (x) & 0xffff0000 )
#define SIO_STS_SENDING		0x80000000

typedef struct
{
	int		flags;
	int		port;
	VP_INT	exinf;
} SIOPCB;

//extern SIOPCB siopcb_table[TNUM_PORT];

extern void sio_handler_in(void);
extern void sio_handler_out(void);

/*
 *  �V���A���|�[�g�̏�����
 */
extern void sio_initialize(void);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB * sio_opn_por(ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void sio_cls_por(SIOPCB *siopcb);

/*
 *  �ꕶ�����M
 */
Inline BOOL
sio_snd_chr(SIOPCB * siopcb, INT chr)
{
	if((siopcb->flags & SIO_STS_SENDING) != 0)
		return FALSE;

	switch(SIO_TYP(siopcb->flags))
	{
	case SIO_TYP_M32RUART:	
		if((sil_reb_mem((void *)(SIOSTS(siopcb->port)+3)) & 0x3) != 0)
		{
			siopcb->flags |= SIO_STS_SENDING;
			sil_wrb_mem((void *)(SIOTXB(siopcb->port)+3), (char)chr);
		} else
			return FALSE;
		break;
	default:
		return FALSE;
	}
	return TRUE;
}


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

#endif /* _HW_SERIAL_H_ */
