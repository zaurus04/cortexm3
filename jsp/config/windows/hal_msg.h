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
 *  @(#) $Id: hal_msg.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


#ifndef __HAL_MSG_H
#define __HAL_MSG_H

#include <constants.h>
#include <t_services.h>
#include <vwindows.h>


#ifndef __HAL_MSG_MSGONLY

    /* OS�̓�����Ǘ�����X���b�h�̃n���h�� */
extern HWND PrimaryDialogHandle;

    /* �Ǘ��X���b�h�����b�N�����Ȃ����߂�SendMessage */
Inline void HALSendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if(PrimaryDialogHandle != GetCurrentThread())
        SendMessage(PrimaryDialogHandle, uMsg, wParam, lParam);
    else
        PostMessage(PrimaryDialogHandle, uMsg, wParam, lParam);
}

    //�f�B�X�p�b�`�˗�
Inline void
HALDispatchRequest(void)
{   HALSendMessage(HALMSG_MESSAGE, HALMSG_DISPATCH, (LPARAM)0);   }

    //�R���e�L�X�g�j���˗� (�� : inline�����A������Q�Ƃ��Ă���ꏊ�͂ЂƂ����Ȃ̂ł��̂܂܂ɂ���)
Inline void
HALDestroyRequest(void * tcb)
{	PostMessage(PrimaryDialogHandle,HALMSG_MESSAGE,HALMSG_DESTROY,(LPARAM)tcb);   }

    //�����݈˗� (intno : �����ݔԍ�)
Inline void
HALInterruptRequest(unsigned int intno)
{	PostMessage(PrimaryDialogHandle,HALMSG_MESSAGE,HALMSG_INTERRUPT,(LPARAM)intno);   }

    //�����ݏ��������ʒm
Inline void
HALInterruptRequestAndWait(void)
{
	SendMessage(PrimaryDialogHandle,HALMSG_MESSAGE,HALMSG_INTERRUPT_FINISH,(LPARAM)0);
}

    //�C�ӂ̃��[�`���̎��s�v��
Inline BOOL
HALExecuteProcedure(void * func, void * param)
{
	void * _workofHALExecuteProcedure[2];
	
	if(func == NULL)
		return FALSE;

	_workofHALExecuteProcedure[0] = func;
	_workofHALExecuteProcedure[1] = param;
	HALSendMessage(HALMSG_MESSAGE,HALMSG_EXECUTEPROCEDURE,(LPARAM)_workofHALExecuteProcedure);

	return TRUE;
}

    //�j���`�F�[���Ɋ֐���o�^
Inline BOOL
HALAddDestructionProcedure(void * func, void * param)
{
	void * _workofHALAddDestructionProcedure[2];

	if(func == NULL)
		return FALSE;

	_workofHALAddDestructionProcedure[0] = func;
	_workofHALAddDestructionProcedure[1] = param;
    HALSendMessage(HALMSG_MESSAGE,HALMSG_ADDDESTRUCTIONPROCEDURE,(LPARAM)_workofHALAddDestructionProcedure);

	return TRUE;
}

    //�J�[�l������̏I���v��
Inline void
HALQuitRequest(void)
{
    HALSendMessage(HALMSG_MESSAGE,HALMSG_QUITREQUEST,0);
}

#endif

#endif

/***/