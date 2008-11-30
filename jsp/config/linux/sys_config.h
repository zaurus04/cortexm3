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
 *  @(#) $Id: sys_config.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#ifndef _SYS_CONF_
/*
 *  OS �̎�ނ̒�`
 */

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g��
 */
#define	TARGET_NAME	"Linux"

/*
 *  CPU �� _setjmp/_longjmp ���C�u�����̎����Ɉˑ�����萔�̐ݒ�
 *
 *  JMPBUF_PC: jmp_buf �\���̒��ŁCPC �̒l������ꏊ�̃I�t�Z�b�g
 *  JMPBUF_SP: jmp_buf �\���̒��ŁCSP �̒l������ꏊ�̃I�t�Z�b�g
 *
 *  STACK_MERGIN: �X�^�b�N�|�C���^�̏����l���C�X�^�b�N�̈�̏�� (�m��
 *  �����̈�̎��̔Ԓn) ����� �ꂾ���������D�X�^�b�N�|�C���^���w����
 *  �n����g���n�߂�v���Z�b�T�� �̏ꍇ�ɂ́C������g���ăX�^�b�N�|�C
 *  ���^�̏����l��������牺����D�܂��Clongjmp ������ɁC�X�^�b�N�|�C
 *  ���^����̔Ԓn�� �A�N�Z�X����\��������ꍇ�ɂ́C������g����
 *  �}�[�W���̈���m�ۂ���D
 *
 *  SIGSTACK_MERGIN: �V�O�i���X�^�b�N���v���Z�X�X�^�b�N��Ɏ�鎞�̃}�[
 *  �W���D�X�^�[�g�A�b�v���[�`�����g�����߂̃X�^�b�N�̈�D
 */

#if defined(i386) | defined(_i386_) | defined(__i386__)

#define JMPBUF_PC		JB_PC
#define JMPBUF_SP		JB_SP
#define STACK_MERGIN		4
#define SIGSTACK_MERGIN		8192

#else /* i386 */

#error not supported.

#endif /* i386 */

/*
 *  �V�O�i���X�^�b�N�̕ύX�� sigaltstack ���g��
 */
#define USE_SIGALTSTACK

/*
 *  �X�^�b�N�G���A�̎擾/�ԋp�֐��� mprotect ���g�����̂ɍ���������
 */
#define	USE_MPROTECT_STACK



#ifdef _BSD_SERIAL_
#undef RAW			/* �Փ˂���V���{���̒�`�𖕏� */
#undef ECHO
#endif /* _BSD_SERIAL_ */


/*
 *  �V�X�e���^�X�N�Ɋւ����`
 */
#define	CONSOLE_PORTID	1	/* �R���\�[���p�ɗp����V���A���|�[�g�ԍ� */
#define	LOGTASK_PORTID	1	/* �V�X�e�����O���o�͂���V���A���|�[�g�ԍ� */
#define LOGTASK_STACK_SIZE 8192 /* ���O�^�X�N�̃X�^�b�N�T�C�Y */

#ifndef _MACRO_ONLY
/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
extern void	sys_initialize(void);

/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 *
 *  �V�X�e�����I�����鎞�Ɏg���DROM���j�^�ďo���Ŏ������邱�Ƃ�z�肵
 *  �Ă���D
 */
extern void	sys_exit(void);

/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 *
 *  �V�X�e���̒჌�x���̕����o�̓��[�`���DROM���j�^�ďo���Ŏ������邱
 *  �Ƃ�z�肵�Ă���D
 */
extern void	sys_putc(char c);

#endif /* _MACRO_ONLY */
#endif /* _SYS_CONF_ */



