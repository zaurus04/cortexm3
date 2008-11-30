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
 *  @(#) $Id: devicecontrol.h,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

#ifndef __DEVICECONTROL_H_
#define __DEVICECONTROL_H_

#include "resource.h"       // ���C�� �V���{��
#include <atlctl.h>
#include "deviceCP.h"

/////////////////////////////////////////////////////////////////////////////
// CDeviceControl

MIDL_INTERFACE("DA93137D-FB52-4421-B95D-9077340AD03B")
_IDeviceEvents : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE OnRead(long address,long sz,byte __RPC_FAR data[]) = 0;
    virtual HRESULT STDMETHODCALLTYPE OnWrite(long address,long sz,byte __RPC_FAR data[]) = 0;
    virtual HRESULT STDMETHODCALLTYPE OnKernelStart(void) = 0;
    virtual HRESULT STDMETHODCALLTYPE OnKernelExit(void) = 0;
};

MIDL_INTERFACE("6575FAAB-8750-42D2-ADDD-4BE764AA2767")
IDevice : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE IsValid(BOOL __RPC_FAR *valid) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetDeviceName(BSTR devname) = 0;
    virtual HRESULT STDMETHODCALLTYPE Map(unsigned long address,unsigned long size) = 0;
    virtual HRESULT STDMETHODCALLTYPE Unmap(unsigned long address) = 0;
    virtual HRESULT STDMETHODCALLTYPE RaiseInterrupt(unsigned long inhno) = 0;
};

class ATL_NO_VTABLE CDeviceControl : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IDeviceControl, &IID_IDeviceControl, &LIBID_ATLDEVICELib>,
	public CComControl<CDeviceControl>,
	public IPersistStreamInitImpl<CDeviceControl>,
	public IOleControlImpl<CDeviceControl>,
	public IOleObjectImpl<CDeviceControl>,
	public IOleInPlaceActiveObjectImpl<CDeviceControl>,
	public IViewObjectExImpl<CDeviceControl>,
	public IOleInPlaceObjectWindowlessImpl<CDeviceControl>,
	public IConnectionPointContainerImpl<CDeviceControl>,
	public IPersistStorageImpl<CDeviceControl>,
	public ISpecifyPropertyPagesImpl<CDeviceControl>,
	public IQuickActivateImpl<CDeviceControl>,
	public IDataObjectImpl<CDeviceControl>,
	public IProvideClassInfo2Impl<&CLSID_DeviceControl, &DIID__IDeviceControlEvents, &LIBID_ATLDEVICELib>,
	public IPropertyNotifySinkCP<CDeviceControl>,
	public CComCoClass<CDeviceControl, &CLSID_DeviceControl>,
	public _IDeviceEvents,
	public CProxy_IDeviceControlEvents< CDeviceControl >
{
public:
	CDeviceControl()
        :   cookie(), manager(), KernelStarted(false),
            DataPointer(0), Limitation(0), Offset(0), AccessSize(1)
    {
        m_bWindowOnly = TRUE;
    }

    ~CDeviceControl()
    {
        if(cookie != 0 && manager != 0) {
            Close();
        }
    }

DECLARE_REGISTRY_RESOURCEID(IDR_DEVICECONTROL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDeviceControl)
	COM_INTERFACE_ENTRY(IDeviceControl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(_IDeviceEvents)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROP_MAP(CDeviceControl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("AccessSize",9,CLSID_NULL)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CDeviceControl)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__IDeviceControlEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CDeviceControl)
	CHAIN_MSG_MAP(CComControl<CDeviceControl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IDeviceControl
public:
	STDMETHOD(get_Value)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Value)(/*[in]*/ long newVal);
	STDMETHOD(get_AccessSize)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_AccessSize)(/*[in]*/ short newVal);
	STDMETHOD(get_Offset)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Offset)(/*[in]*/ long newVal);
	STDMETHOD(get_IsKernelStarted)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(Unmap)(/*[in]*/long address);
	STDMETHOD(Map)(/*[in]*/long address,/*[in]*/long size);
	STDMETHOD(RaiseInterrupt)(/*[in]*/long inhno);
	STDMETHOD(get_Valid)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(Close)();
	STDMETHOD(Connect)();
    STDMETHOD(get_DeviceName)(BSTR* pVal);
    STDMETHOD(put_DeviceName)(BSTR newVal);

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		HDC memDC;
		HINSTANCE hInstance;
		HBITMAP memImage;
		HBITMAP oldImage;

		hInstance = (HINSTANCE)GetWindowLong(GWL_HINSTANCE);
		memImage = ::LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_DEVICECONTROL_BIG));
		memDC = ::CreateCompatibleDC(di.hdcDraw);
		oldImage = (HBITMAP) ::SelectObject(memDC,memImage);

		::StretchBlt(di.hdcDraw,rc.left,rc.top,rc.right,rc.bottom,memDC,0,0,64,64,SRCCOPY);

		::SelectObject(memDC, oldImage);
		::DeleteObject(memImage);
		::DeleteDC(memDC);
		
		return S_OK;
	}

// _IDeviceEvents
	STDMETHOD(OnRead)(long address,long sz,byte __RPC_FAR data[]);
	STDMETHOD(OnWrite)(long address,long sz,byte __RPC_FAR data[]);
	STDMETHOD(OnKernelStart)();
	STDMETHOD(OnKernelExit)();

	DWORD cookie;
    CComBSTR devname;
	CComPtr<IDevice> manager;
	bool KernelStarted;

	unsigned char * DataPointer;
	long Limitation;
	long Offset;
	short AccessSize;
};

#endif //__DEVICECONTROL_H_
