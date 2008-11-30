/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
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
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 *  �V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iCQ-STARM�p�j
 */

#ifndef TOPPERS_TARGET_SERIAL_H
#define TOPPERS_TARGET_SERIAL_H

#include "cq_starm.h"

/*
 *  SIO�̊����݃x�N�^�ԍ�
 */
#if (SIO_PORTID == 1)
#define INHNO_SIO		IRQ_VECTOR_USART1
#define INTNO_SIO		IRQ_VECTOR_USART1
#elif (SIO_PORID == 2)
#define INHNO_SIO		IRQ_VECTOR_USART2
#define INTNO_SIO		IRQ_VECTOR_USART2
#endif
#define INTPRI_SIO		-3				/* �����ݗD��x */
#define INTATR_SIO		0				/* �����ݑ��� */

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_RDY_SND    1U        /* ���M�\�R�[���o�b�N */
#define SIO_RDY_RCV    2U        /* ��M�ʒm�R�[���o�b�N */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �V���A���|�[�g�̊Ǘ��u���b�N
 */
typedef struct sio_port_control_block {
	ID port;
	uint32_t reg;
	intptr_t exinf;
} SIOPCB;

/*
 *  SIO������
 */
extern void sio_initialize(intptr_t exinf);

/*
 *  �V���A���I�[�v��
 */
extern SIOPCB *sio_opn_por(ID siopid, intptr_t exinf);

/*
 *  �V���A���N���[�Y
 */
extern void sio_cls_por(SIOPCB *p_siopcb);

/*
 *  �����݃n���h��
 */
extern void sio_isr(intptr_t exinf);

/*
 *  1�������M
 */
extern bool_t sio_snd_chr(SIOPCB *siopcb, char_t c);

/*
 *  1������M
 */
extern int_t sio_rcv_chr(SIOPCB *siopcb);

/*
 *  �R�[���o�b�N�̋���
 */
extern void sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn);

/* 
 *  �R�[���o�b�N�̋֎~
 */
extern void sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn);

/*
 *  ���M�\�R�[���o�b�N
 */
extern void sio_irdy_snd(intptr_t exinf);

/*
 *  ��M�ʒm�R�[���o�b�N
 */
extern void sio_irdy_rcv(intptr_t exinf);

/*
 *  1�������M�i�|�[�����O�ł̏o�́j
 */
extern void sio_pol_snd_chr(char_t c, ID siopid);

/*
 *  �^�[�Q�b�g�̃V���A��������
 */
extern void target_usart_init(ID siopid);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_SERIAL_H */
