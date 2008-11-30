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
 *  @(#) $Id: device.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#ifndef __DEVICE_H
#define __DEVICE_H

#include <cpu_rename.h>
#include <s_services.h>

#ifdef DEVICE_ENABLE

#define MAX_MSGSIZE 256

#define DEVICE_TIMEOUT INFINITE

#define OnDevice

extern struct tagDeviceGlobalVariables
{
    CRITICAL_SECTION cs;
    HANDLE ManagerSlot;
    HANDLE ListenerThread;
    HANDLE Blocker;
    HANDLE ThreadBlocker;
    HANDLE ReplySlot;
    DWORD ListenerThreadID;
} DeviceVars;

void InitializeDeviceSupportModule(void);
void FinalizeDeviceSupportModule(void);

int DeviceRead(unsigned long address, unsigned long size, void * storage);
int DeviceWrite(unsigned long address, unsigned long size, void * storage);


#define SIL_ENDIAN SIL_ENDIAN_LITTLE

/*
 *  �G���f�B�A���̔��]
 */
#ifndef SIL_REV_ENDIAN_H
#define	SIL_REV_ENDIAN_H(data) \
    ((VH)((((UH)(data) & 0xff) << 8) | (((UH)(data) >> 8) & 0xff)))
#endif /* SIL_REV_ENDIAN_H */

#ifndef SIL_REV_ENDIAN_W
#define	SIL_REV_ENDIAN_W(data) \
    ((VW)((((UW)(data) & 0xff) << 24) | (((UW)(data) & 0xff00) << 8) \
    | (((UW)(data)>> 8) & 0xff00) | (((UW)(data) >> 24) & 0xff)))
#endif /* SIL_REV_ENDIAN_H */

/*
 *  ���R�ȃG���f�B�A���ł̓Ǐo��
 */
Inline VB
sil_reb_mem(VP mem)
{
    VB data;
    DeviceRead((unsigned long)mem, sizeof(data), &data);
    return data;
}

Inline VH
sil_reh_mem(VP mem)
{
    VH data;
    DeviceRead((unsigned long)mem, sizeof(data), &data);
    return data;
}

Inline VW
sil_rew_mem(VP mem)
{
    VW data;
    DeviceRead((unsigned long)mem, sizeof(data), &data);
    return data;
}

Inline void
sil_rek_mem(VP mem, VP data, UINT len)
{	DeviceRead((unsigned long)mem, len, data);   }

/*
 *  ���g���G���f�B�A���ł̓Ǐo���i���g���G���f�B�A���v���Z�b�T�j
 */
#define	sil_reh_lem(mem)	sil_reh_mem(mem)
#define	sil_rew_lem(mem)	sil_rew_mem(mem)

/*
 *  �r�b�O�G���f�B�A���ł̓Ǐo���i���g���G���f�B�A���v���Z�b�T�j
 */
Inline VH
sil_reh_bem(VP mem)
{   return SIL_REV_ENDIAN_H(sil_reh_mem(mem));   }

Inline VW
sil_rew_bem(VP mem)
{   return SIL_REV_ENDIAN_W(sil_rew_mem(mem));   }

/*
 *  ���R�ȃG���f�B�A���ł̏�����
 */
Inline void
sil_wrb_mem(VP mem, VB data)
{   DeviceWrite((unsigned long)mem, sizeof(data), &data);   }

Inline void
sil_wrh_mem(VP mem, VH data)
{   DeviceWrite((unsigned long)mem, sizeof(data), &data);   }

Inline void
sil_wrw_mem(VP mem, VW data)
{   DeviceWrite((unsigned long)mem, sizeof(data), &data);   }

Inline void
sil_wrk_mem(VP mem, VP data, UINT len)
{	DeviceWrite((unsigned long)mem, len, data);   }

#define	sil_wrh_lem(mem, data)	sil_wrh_mem(mem, data)
#define	sil_wrw_lem(mem, data)	sil_wrw_mem(mem, data)

/*
 *  �r�b�O�G���f�B�A���ł̏����݁i���g���G���f�B�A���v���Z�b�T�j
 */
Inline void
sil_wrh_bem(VP mem, VH data)
{
    data = SIL_REV_ENDIAN_H(data);
    DeviceWrite((unsigned long)mem, sizeof(data), &data);   		
}

Inline void
sil_wrw_bem(VP mem, VW data)
{
    data = SIL_REV_ENDIAN_W(data);
    DeviceWrite((unsigned long)mem, sizeof(data), &data);   		
}

#else // DEVICE_ENABLE

//�f�o�C�X�͗��p���Ȃ�

#define OnDevice /##/
#define InitializeDeviceSupportModule /##/
#define FinalizeDeviceSupportModule /##/

/*
#define DeviceRead(address, size, storage) \
    memcpy(storage, (void *)address, size)

#define DeviceWrite(address, size, storage) \
    memcpy((void *)address, storage, size)
*/

#define DeviceRead /##/
#define DeviceWrite /##/

#endif

#endif

