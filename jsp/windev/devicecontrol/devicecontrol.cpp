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
 *  @(#) $Id: devicecontrol.cpp,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

#include "stdafx.h"
#include "device.h"
#include "devicecontrol.h"

/////////////////////////////////////////////////////////////////////////////
// CDeviceControl

const CLSID CLSID_Device = {0xFEE2A68B,0x7F98,0x40E0,{0x98,0x53,0x18,0x3E,0xE6,0x8B,0xC7,0xF8}};

STDMETHODIMP CDeviceControl::Connect()
{
    if(!FAILED(manager.CoCreateInstance(CLSID_Device)) && !FAILED(manager.Advise((_IDeviceEvents *)this,__uuidof(_IDeviceEvents),&cookie))) {
        STARTUPINFO info;

        info.cb = sizeof(info);
        GetStartupInfo(&info);

        devname.Empty();
        devname.Append(info.lpTitle);
        manager->SetDeviceName(devname);
        
        return S_OK;
    }

    if(! !manager)
        manager.Release();

    return E_FAIL;
}

STDMETHODIMP CDeviceControl::Close()
{
    if(!manager)
        return E_FAIL;

    AtlUnadvise(manager,__uuidof(_IDeviceEvents),cookie);
    manager.Release();
    cookie = 0;
    return S_OK;
}

STDMETHODIMP CDeviceControl::get_Valid(BOOL *pVal)
{
    *pVal = !manager ? FALSE : ~0;
    return S_OK;
}

STDMETHODIMP CDeviceControl::RaiseInterrupt(long inhno)
{
    if(!manager)
        return E_FAIL;
    
    return manager->RaiseInterrupt(inhno);
}

STDMETHODIMP CDeviceControl::Map(long address, long size)
{
    if(!manager)
        return E_FAIL;

    return manager->Map(address, size);
}

STDMETHODIMP CDeviceControl::Unmap(long address)
{
    if(!manager)
        return E_FAIL;

    return manager->Unmap(address);
}


STDMETHODIMP CDeviceControl::get_IsKernelStarted(BOOL *pVal)
{
    *pVal = KernelStarted ? ~0 : 0;
    return S_OK;
}

STDMETHODIMP CDeviceControl::get_Offset(long *pVal)
{
    *pVal = Offset;
    return S_OK;
}

STDMETHODIMP CDeviceControl::put_Offset(long newVal)
{
    if(newVal >= Limitation)
        return E_FAIL;

    Offset = newVal;

    return S_OK;
}

STDMETHODIMP CDeviceControl::get_AccessSize(short *pVal)
{
    *pVal = AccessSize;
    return S_OK;
}

STDMETHODIMP CDeviceControl::put_AccessSize(short newVal)
{
    switch(newVal)
    {
    case 1: case 2: case 4:
        break;
    default:
        return E_FAIL;
    }

    AccessSize = newVal;
    return S_OK;
}

STDMETHODIMP CDeviceControl::get_Value(long *pVal)
{
    if(DataPointer == 0)
        return E_FAIL;

    *pVal = 0;
    CopyMemory(pVal, DataPointer + Offset, AccessSize);

    Offset += AccessSize;
    if(Offset >= Limitation)
        Offset = Limitation -1;
    
    return S_OK;
}

STDMETHODIMP CDeviceControl::put_Value(long newVal)
{
    if(DataPointer == 0)
        return E_FAIL;

    CopyMemory(DataPointer + Offset, &newVal, AccessSize);

    Offset += AccessSize;
    if(Offset >= Limitation)
        Offset = Limitation -1;

    return S_OK;
}

STDMETHODIMP CDeviceControl::OnRead(long address,long sz,byte __RPC_FAR data[])
{
    if(!KernelStarted)
        this->OnKernelStart();

    DataPointer = (unsigned char *)data;
    Limitation = sz;
    Offset = 0;

    Fire_OnRead(address, sz);
    
    DataPointer = 0;
    return S_OK;
}

STDMETHODIMP CDeviceControl::OnWrite(long address,long sz,byte __RPC_FAR data[])
{
    if(!KernelStarted)
        this->OnKernelStart();

    DataPointer = (unsigned char *)data;
    Limitation = sz;
    Offset = 0;
    Fire_OnWrite(address,sz);
    DataPointer = 0;
    return S_OK;
}

STDMETHODIMP CDeviceControl::OnKernelStart()
{
    KernelStarted = true;
    Fire_OnKernelStart();
    return S_OK;
}

STDMETHODIMP CDeviceControl::OnKernelExit()
{
    KernelStarted = false;
    Fire_OnKernelExit();
    return S_OK;
}

STDMETHODIMP CDeviceControl::get_DeviceName(BSTR* pVal)
{
    if(!manager)
        return E_FAIL;

    devname.CopyTo(pVal);
    return S_OK;
}

STDMETHODIMP CDeviceControl::put_DeviceName(BSTR newVal)
{
    if(!manager)
        return E_FAIL;

    devname = newVal;
    manager->SetDeviceName(devname);
    return S_OK;
}
