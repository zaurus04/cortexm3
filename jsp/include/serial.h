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
 *  @(#) $Id: serial.h,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *	�V���A���C���^�t�F�[�X�h���C�o
 */

#ifndef _SERIAL_H_
#define _SERIAL_H_

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̗p����p�P�b�g
 */
typedef struct {
		UINT	reacnt;		/* ��M�o�b�t�@���̕����� */
		UINT	wricnt;		/* ���M�o�b�t�@���̕����� */
	} T_SERIAL_RPOR;

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̏��������[�`��
 */
extern void	serial_initialize(VP_INT exinf) throw();

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̃T�[�r�X�R�[��
 */
extern ER	serial_opn_por(ID portid) throw();
extern ER	serial_cls_por(ID portid) throw();
extern ER_UINT	serial_rea_dat(ID portid, char *buf, UINT len) throw();
extern ER_UINT	serial_wri_dat(ID portid, char *buf, UINT len) throw();
extern ER	serial_ctl_por(ID portid, UINT ioctl) throw();
extern ER	serial_ref_por(ID portid, T_SERIAL_RPOR *pk_rpor) throw();

/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̓��쐧��p�̂��߂̒萔
 *
 *  �ȉ��̒萔�́C�r�b�g���ɘ_���a���Ƃ��ėp����D
 */
#define	IOCTL_NULL	0u		/* �w��Ȃ� */
#define	IOCTL_ECHO	0x0001u		/* ��M�����������G�R�[�o�b�N */
#define	IOCTL_CRLF	0x0010u		/* LF �𑗐M����O�� CR ��t�� */
#define	IOCTL_FCSND	0x0100u		/* ���M�ɑ΂��ăt���[������s�� */
#define	IOCTL_FCANY	0x0200u		/* �ǂ̂悤�ȕ����ł����M�ĊJ */
#define	IOCTL_FCRCV	0x0400u		/* ��M�ɑ΂��ăt���[������s�� */

#endif /* _SERIAL_H_ */
