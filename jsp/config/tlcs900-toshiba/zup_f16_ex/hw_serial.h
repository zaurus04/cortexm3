/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *	�^�[�Q�b�g�ˑ��V���A��I/O���W���[���iZup-F16�g���{�[�h�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#include <sil.h>
#include <tmp91cy22.h>
#include <uart.h>

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND		UART_ERDY_SND			/* ���M�\�R�[���o�b�N			*/
#define SIO_ERDY_RCV		UART_ERDY_RCV			/* ��M�ʒm�R�[���o�b�N			*/

#ifndef _MACRO_ONLY

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize	uart_initialize

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
#define	sio_opn_por		uart_opn_por

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
#define	sio_cls_por		uart_cls_por

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr		uart_snd_chr

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr		uart_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr		uart_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr		uart_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define	sio_ierdy_snd	uart_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define	sio_ierdy_rcv	uart_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
