/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Platform Development Center
 *                                          RICOH COMPANY,LTD. JAPAN
 * 
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iM3029�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>
#ifndef _MACRO_ONLY
#include <sfruart.h>
#endif /* _MACRO_ONLY */

/*
 *  �V���A��I/O�̊����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_SERIAL_IN1	INT_S0R
#define	INHNO_SERIAL_OUT1	INT_S0T
#define INHNO_SERIAL_IN2	INT_S1R
#define INHNO_SERIAL_OUT2	INT_S1T

#ifndef _MACRO_ONLY

/*
 *  SIO�h���C�o�̏��������[�`��
 */
#define	sio_initialize	sfruart_initialize

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
#define	sio_opn_por		sfruart_opn_por

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
#define	sio_cls_por		sfruart_cls_por

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
#define	sio_snd_chr		sfruart_snd_chr

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
#define	sio_rcv_chr		sfruart_rcv_chr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
#define	sio_ena_cbr		sfruart_ena_cbr

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
#define	sio_dis_cbr		sfruart_dis_cbr

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
#define	sio_ierdy_snd	sfruart_ierdy_snd

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
#define	sio_ierdy_rcv	sfruart_ierdy_rcv

#endif /* _MACRO_ONLY */
#endif /* _HW_SERIAL_H_ */
