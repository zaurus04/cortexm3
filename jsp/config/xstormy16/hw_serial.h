/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2005 by Embedded and Real-Time Systems Laboratory
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
 */

/*
 *  �V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iXstprmy16�p�j
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include <s_services.h>

/*
 *  SIO�̊����݃n���h���̃x�N�^�ԍ�
 */
#define INHNO_SIO   INHNO_UART

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 */
typedef struct sio_port_control_block {
    const UH uhMagic ;
    const UH uhBase ;
    const UH uhExcpMask ;
    VP_INT vpiExinf ;
    B bNotExist ;
    B bOpened ;
    B bTxIe ;
    B bRxIe ;
    B bLastIsCr ;
} SIOPCB;

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND    1u      /* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV    2u      /* ��M�ʒm�R�[���o�b�N */

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void sio_initialize(void) throw() ;

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB *sio_opn_por(ID siopid, VP_INT exinf) throw() ;

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void sio_cls_por(SIOPCB *siopcb) throw() ;

/*
 *  SIO�̊����݃n���h��
 */
extern void sio_handler(void) throw() ;

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL sio_snd_chr(SIOPCB *siopcb, char c) throw() ;

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT sio_rcv_chr(SIOPCB *siopcb) throw() ;

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void sio_ena_cbr(SIOPCB *siopcb, UINT cbrtn) throw() ;

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void sio_dis_cbr(SIOPCB *siopcb, UINT cbrtn) throw() ;

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void sio_ierdy_snd(VP_INT exinf) throw() ;

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void sio_ierdy_rcv(VP_INT exinf) throw() ;

/*
 *  �V���A��I/O�|�[�g�ւ̔񓯊������o��
 */
extern void sio_asnd_chr( INT c ) throw() ;

/*
 *  �V���A��I/O�|�[�g����̔񓯊���������
 */
extern INT sio_arcv_chr( void ) throw() ;

#endif /* _HW_SERIAL_H_ */
