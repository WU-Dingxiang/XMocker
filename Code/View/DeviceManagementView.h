
// DeviceManagementView.h 2016-1-3 21:35:32

#pragma once

#include "UIView.h"
#include "UIButton.h"
#include "UITextField.h"
#include "UILabel.h"
#include "afxcmn.h"

// macros

// constance

const static int DEVICEMANAGEMENT_CUTLINE_NUM = 2;

// class
class DeviceManagementView : public UIView {
public:
	// Constructors
	DeviceManagementView();
	// Methods(Setter)
protected:
	// Attributes(Objects)
	CImage cutline;
	CRect cutlineFrames[DEVICEMANAGEMENT_CUTLINE_NUM];
	// Attributes(Pointers)
	/************ New Group ************************/
	UILabel *m_groupHeaderLabel;
	UILabel *m_newGroupLabel;
	UITextField *m_newGroupTextField;
	UIButton *m_newGroupBtn;
	/************ Add Remote Device ****************/
	UILabel *m_remoteHeaderLabel;
	UILabel *m_remoteDeviceIdLabel;
	UITextField *m_remoteDeviceIdTextField;
	UILabel *m_remoteDevicePswdLabel;
	UITextField *m_remoteDevicePswdTextField;
	UIButton *m_addRemoteDeviceBtn;
	/************ Add Local Device ****************/
	UILabel *m_localHeaderLabel;
	UILabel *m_localDeviceIdLabel;
	UITextField *m_localDeviceIdTextField;
	UILabel *m_localDevicePswdLabel;
	UITextField *m_localDevicePswdTextField;
	UIButton *m_addLocalDeviceBtn;
	UIButton *m_updateListBtn;
	CListCtrl *m_localDeviceTableView;
	// Methods(Custom)
	// Messages(Actions)
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNewGroupBtnClicked();
	afx_msg void OnAddRemoteDeviceBtnClicked();
	afx_msg void OnAddLocalDeviceBtnClicked();
	afx_msg void OnUpdateDeviceListBtnClicked();
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

