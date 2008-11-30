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
 *  @(#) $Id: startup.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�J�[�l���̏������ƏI������
 */

#include "jsp_kernel.h"
#include "time_event.h"
#include "syslog.h"

/*
 *  �J�[�l�������ԃt���O
 */
BOOL	iniflg;

/*
 *  �J�[�l���̏�����
 */
void
kernel_start()
{
	/*
	 *  �^�[�Q�b�g�ˑ��̏�����
	 */
	cpu_initialize();
	sys_initialize();
	tool_initialize();

	/*
	 *  �V�X�e�����O�@�\�̏�����
	 */
	syslog_initialize();

	/*
	 *  �N�����b�Z�[�W�̕\��
	 */
	print_banner();

	/*
	 *  �e���W���[���̏�����
	 *
	 *  �^�C���C�x���g�Ǘ����W���[���͑��̃��W���[������ɏ�����
	 *  ����K�v������D
	 */
	tmevt_initialize();
	object_initialize();

	/*
	 *  ���������[�`���̎��s
	 */ 
	call_inirtn();

	/*
	 *  �J�[�l������̊J�n
	 */
	iniflg = TRUE;
	exit_and_dispatch();
}

/*
 *  �J�[�l���̏I������
 */
void
kernel_exit()
{
	/*
	 *  �����݂��֎~
	 */
	if (!sense_lock()) {
		if (sense_context()) {
			i_lock_cpu();
		}
		else  {
			t_lock_cpu();
		}
	}
	iniflg = FALSE;

	/*
	 *  �I���������[�`���̎��s
	 */
	call_terrtn();

	/*
	 *  atexit �̏����ƃf�X�g���N�^�̎��s
	 */
	call_atexit();

	/*
	 *  �V�X�e�����O�@�\�̏I������
	 */
	syslog_terminate();

	/*
	 *  �^�[�Q�b�g�ˑ��̏I������
	 */
	cpu_terminate();
	sys_exit();
}
