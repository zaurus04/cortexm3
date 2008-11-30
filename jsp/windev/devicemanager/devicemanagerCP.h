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
 *  @(#) $Id: devicemanagerCP.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

#ifndef _ATLDEVICEMANAGERCP_H_
#define _ATLDEVICEMANAGERCP_H_

template <class T>
class CProxy_IKernelEvents : public IConnectionPointImpl<T, &IID__IKernelEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:
	HRESULT Fire_OnInterruptRequest(ULONG inhno)
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
			_IKernelEvents* p_IKernelEvents = reinterpret_cast<_IKernelEvents*>(sp.p);
			if (p_IKernelEvents != NULL)
				ret = p_IKernelEvents->OnInterruptRequest(inhno);
		}	return ret;
	
	}
};




template <class T>
class CProxy_IDeviceEvents : public IConnectionPointImpl<T, &IID__IDeviceEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:
	HRESULT Fire_OnRead(LONG address, LONG sz, unsigned char * data)
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
			_IDeviceEvents* p_IDeviceEvents = reinterpret_cast<_IDeviceEvents*>(sp.p);
			if (p_IDeviceEvents != NULL)
				ret = p_IDeviceEvents->OnRead(address, sz, data);
		}	return ret;
	
	}
	HRESULT Fire_OnWrite(LONG address, LONG sz, unsigned char * data)
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
			_IDeviceEvents* p_IDeviceEvents = reinterpret_cast<_IDeviceEvents*>(sp.p);
			if (p_IDeviceEvents != NULL)
				ret = p_IDeviceEvents->OnWrite(address, sz,data);
		}	return ret;
	
	}
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
			_IDeviceEvents* p_IDeviceEvents = reinterpret_cast<_IDeviceEvents*>(sp.p);
			if (p_IDeviceEvents != NULL)
				ret = p_IDeviceEvents->OnKernelStart();
		}	return ret;
	
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
			_IDeviceEvents* p_IDeviceEvents = reinterpret_cast<_IDeviceEvents*>(sp.p);
			if (p_IDeviceEvents != NULL)
				ret = p_IDeviceEvents->OnKernelExit();
		}	return ret;
	
	}
};




template <class T>
class CProxy_IInformationEvents : public IConnectionPointImpl<T, &IID__IInformationEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:
	HRESULT Fire_OnDeviceChanged(SHORT reason, LONG devid, LONG extra = 0)
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
			_IInformationEvents* p_IInformationEvents = reinterpret_cast<_IInformationEvents*>(sp.p);
			if (p_IInformationEvents != NULL)
				ret = p_IInformationEvents->OnDeviceChanged(reason, devid, extra);
		}	return ret;
	
	}
	HRESULT Fire_OnKernelChanged(SHORT reason)
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
			_IInformationEvents* p_IInformationEvents = reinterpret_cast<_IInformationEvents*>(sp.p);
			if (p_IInformationEvents != NULL)
				ret = p_IInformationEvents->OnKernelChanged(reason);
		}	return ret;
	
	}
};


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
			{
				if((ret = p_IKernelLogEvents->OnKernelStart()) == S_OK)
					onKernelStart_Performed = true;
			}
		}
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
		if(nConnectionIndex != 0)
			onKernelStart_Performed = true;	
		return ret;	
	}
};
#endif
