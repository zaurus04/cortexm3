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
 *  @(#) $Id: kernellog.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

// KernelLog.h : CKernelLog �̐錾

#ifndef __KERNELLOG_H_
#define __KERNELLOG_H_

#include "resource.h"       // ���C�� �V���{��
#include "devicemanagerCP.h"

/////////////////////////////////////////////////////////////////////////////
// CKernelLog
class ATL_NO_VTABLE CKernelLog : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CKernelLog, &CLSID_KernelLog>,
    public IConnectionPointContainerImpl<CKernelLog>,
    public IKernelLog,
    public CProxy_IKernelLogEvents< CKernelLog >
{
public:
    CKernelLog();
    ~CKernelLog();

DECLARE_REGISTRY_RESOURCEID(IDR_KERNELLOG)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CKernelLog)
    COM_INTERFACE_ENTRY(IKernelLog)
    COM_INTERFACE_ENTRY(IConnectionPointContainer)
    COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CKernelLog)
CONNECTION_POINT_ENTRY(IID__IKernelLogEvents)
END_CONNECTION_POINT_MAP()


// IKernelLog
public:
};

#endif //__KERNELLOG_H_



#if 0

template <class T>
class CProxy_IKernelLogEvents : public IConnectionPointImpl<T, &IID__IKernelLogEvents, CComDynamicUnkArray>
{
public:
    bool onKernelStart_Performed;

    CProxy_IKernelLogEvents(void) : onKernelStart_Performed(false) {};

    //Warning this class may be recreated by the wizard.
public:
    HRESULT Fire_OnKernelStart()
    {
        HRESULT ret;
        T* pT = static_cast<T*>(this);
        int nConnectionIndex;
        int nConnections = m_vec.GetSize();
        
        for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();
            _IKernelLogEvents* p_IKernelLogEvents = reinterpret_cast<_IKernelLogEvents*>(sp.p);
            if (p_IKernelLogEvents != NULL)
                ret = p_IKernelLogEvents->OnKernelStart();
        }
        onKernelStart_Performed = true;
        return ret;
    }

    HRESULT Fire_OnKernelExit()
    {
        HRESULT ret;
        T* pT = static_cast<T*>(this);
        int nConnectionIndex;
        int nConnections = m_vec.GetSize();
        
        for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();
            _IKernelLogEvents* p_IKernelLogEvents = reinterpret_cast<_IKernelLogEvents*>(sp.p);
            if (p_IKernelLogEvents != NULL)
                ret = p_IKernelLogEvents->OnKernelExit();
        }
        onKernelStart_Performed = false;    
        return ret;
    }

    HRESULT Fire_OnLogEvent(LONG sz, unsigned char * data)
    {
        HRESULT ret;
        T* pT = static_cast<T*>(this);
        int nConnectionIndex;
        int nConnections = m_vec.GetSize();
        
        for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();
            _IKernelLogEvents* p_IKernelLogEvents = reinterpret_cast<_IKernelLogEvents*>(sp.p);
            if (p_IKernelLogEvents != NULL)
            {
                if(!onKernelStart_Performed)
                    p_IKernelLogEvents->OnKernelStart();
                ret = p_IKernelLogEvents->OnLogEvent(sz, data);
            }
        }
        onKernelStart_Performed = true; 
        return ret; 
    }
};
#endif