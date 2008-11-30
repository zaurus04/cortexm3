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
 *  @(#) $Id: sys_defs.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


#ifndef __SYS_DEFS_H
#define __SYS_DEFS_H

#include <cpu_rename.h>

    /*
     *  �g�p����f�B�X�p�b�`����I��
     */
#define WIN32_THREADMODEL               //�X���b�h = �^�X�N
//#define WIN32_NATIVEDISPATCHER        //x86���߃f�B�X�p�b�`��(PUSHAD, FSAVE)  ���I��s��
//#define WIN32_EXCEPTIONDISPATCHER     //Windows�\������O�f�B�X�p�b�`�� ���I��s��
//#define WIN32_VIRTUALMACHINE          //���z�}�V���N���X���C�u���� ���I��s��

    /*
     * Windows�ˑ����g���@�\�̑I��
     */
//#define DEBUG_ENABLE       /* �f�o�b�O�o�̓R���\�[����L���ɂ��邩�ǂ��� */

//#define DEVICE_ENABLE      /* �f�o�C�X�G�~�����[�V�����@�\���g�p���邩�ǂ��� */

//#define EVENTLOG_ENABLE    /* �J�[�l�����샍�O�擾�@�\��L���ɂ��邩�ǂ��� */

	/*
     *  �V�~�����[�V�����ɗp����^�C�}�[�̎�� 
     */
//#define TIMER_NOTHING         // �g�p���Ȃ� (�O�����狟������)
#define TIMER_MULTIMEDIATIMER	// �}���`���f�B�A�^�C�}
//#define TIMER_WINDOWSTIMER	// �W���̃^�C�} (SetTimer�Ƃ�KillTimer�Ƃ�)
//#define TIMER_WAITABLETIMER   // NT4��WaitableTimer���g�p����o�[�W����

    /*
     *  ���̑��̋@�\�I��
     */
//#define KERNEL_DEBUG_MODE    /* �J�[�l���̃f�o�b�O���O���o��(Windows�ˑ����f�o�b�O�p) */


#ifndef _MACRO_ONLY
/*
 *  �V�X�e���A�{�[�g�n���h��
 */
extern void kernel_abort(void);

#endif /* _MACRO_ONLY */

#endif


