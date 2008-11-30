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
 *  @(#) $Id: linux_sigio.h,v 1.1 2008/06/17 00:04:43 suikan Exp $
 */

/*
 *  LINUX�p �m���u���b�L���OI/O �T�|�[�g���W���[��
 *
 *  �m���u���b�L���OI/O �T�|�[�g���W���[���́CSIGIO �V�O�i���ɂ��C���[
 *  �U���o�^�����R�[���o�b�N�֐����Ăяo���@�\�����D
 *
 *  SIGIO �V�O�i���ɂ��R�[���o�b�N�֐������s���������ꍇ�ɂ́CSIGIO 
 *  �ʒm�C�x���g�u���b�N��p�ӂ��C���� callback �t�B�[���h�ɃR�[���o�b
 *  �N�֐��Carg �t�B�[���h�ɃR�[���o�b�N�֐��֓n��������ݒ肵�C
 *  eneuque_sigioeb ��p���� SIGIO �ʒm�C�x���g�L���[�ɓo�^����D
 *
 *  �Ăяo���ꂽ�R�[���o�b�N�֐��� 0 ��Ԃ��ƁC�֘A���� SIGIO �ʒm�C�x
 *  ���g�u���b�N �̓L���[�ɓo�^���ꂽ�܂܂ƂȂ�C���� SIGIO �V�O�i����
 *  �Ăѓ����R�[ ���o�b�N�֐����Ăяo�����D�R�[���o�b�N�֐��� 0 �ȊO
 *  ��Ԃ��ƁCSIGIO �ʒm�C�x���g�u���b�N�̓L���[����폜����C�R�[���o�b
 *  �N�֐��͂���ȍ~�Ăяo����Ȃ��Ȃ�D
 */

#ifndef	_LINUX_SIGIO_H_
#define	_LINUX_SIGIO_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  SIGIO �ʒm�C�x���g�u���b�N�̒�`
 */
typedef BOOL	(*SIGIO_CBACK)(VP);	/* SIGIO �R�[���o�b�N�֐��̌^ */

typedef struct bsd_sigio_event_block {
	VP		queue[2];	/* SIGIO �ʒm�C�x���g�L���[�G���A */
	SIGIO_CBACK	callback;	/* SIGIO �R�[���o�b�N�֐� */
	VP		arg;		/* �R�[���o�b�N�֐��֓n������ */
} SIGIOEB;

/*
 *  SIGIO �ʒm�C�x���g�u���b�N�̓o�^
 */
extern ER	enqueue_sigioeb(SIGIOEB *sigioeb) throw();

/*
 *  �V�X�e���N�����p SIGIO �ʒm�C�x���g�u���b�N�̓o�^
 */
extern ER	enqueue_sigioeb_initialize(SIGIOEB *sigioeb) throw();

/*
 *   �m���u���b�L���OI/O ���W���[���N�����[�`��
 */

extern void linux_sigio_initialize(VP_INT exinf) throw();

/*
 *  �����݃n���h���̃x�N�^�ԍ�
 */
#define	INHNO_SIGIO	SIGIO

/*
 *  SIGIO���荞�݃n���h��
 */

extern void linux_sigio_handler() throw();
    
/*
 * SIGIO�^�X�N�̐ݒ�
 */
#define LINUX_SIGIO_PRIORITY      2
#define LINUX_SIGIO_STACK_SIZE 8192

extern void linux_sigio_task(void) throw();

#ifdef __cplusplus
}
#endif

#endif /* _LINUX_SIGIO_H_ */
