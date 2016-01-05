
// NetworkSettingsView.h 2016-1-3 21:35:32

#pragma once

#include "UIView.h"
#include "UIButton.h"
#include "UITextField.h"
#include "UILabel.h"
#include "afxcmn.h"

// macros

// constance

const static int NETWORKSETTINGS_CUTLINE_NUM = 1;

// class
class NetworkSettingsView : public UIView {
public:
	// Constructors
	NetworkSettingsView();
	// Methods(Setter)
protected:
	// Attributes(Objects)
	CImage cutline;
	CRect cutlineFrames[NETWORKSETTINGS_CUTLINE_NUM];
	// Attributes(Pointers)
	/************ Device IP Settings ************************/
	UILabel *m_ipHeaderLabel;
	UIButton *m_saveIpSettingsBtn;
	/************ WIFI Settings *****************************/
	UILabel *m_wifiHeaderLabel;
	UILabel *m_ssidLabel;
	UITextField *m_ssidTextField;
	UILabel *m_codeModeLabel;
	UITextField *m_codeModeTextField;
	UILabel *m_pswdLabel;
	UITextField *m_pswdTextField;
	UIButton *m_saveWifiSettingsBtn;
	UIButton *m_scanWifiBtn;
	CListCtrl *m_wifiTableView;
	// Methods(Custom)
	// Messages(Actions)
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSaveIpSettingsBtnClicked();
	afx_msg void OnSaveWifiSettingsBtnClicked();
	afx_msg void OnScanWifiBtnClicked();
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

