
// RemoteMaintenanceView.h 2016-1-3 21:35:32

#pragma once

#include "UIView.h"
#include "UIButton.h"
#include "UITextField.h"
#include "UILabel.h"
#include "afxcmn.h"

// macros

// constance

const static int REMOTEMAINTENANCE_CUTLINE_NUM = 2;

// class
class RemoteMaintenanceView : public UIView {
public:
	// Constructors
	RemoteMaintenanceView();
	// Methods(Setter)
protected:
	// Attributes(Objects)
	CImage cutline;
	CRect cutlineFrames[REMOTEMAINTENANCE_CUTLINE_NUM];
	// Attributes(Pointers)
	/************ Device Info List ***************************/
	UILabel *m_infoHeaderLabel;
	UIButton *m_checkFirmwareBtn;
	CListCtrl *m_deviceInfoTableView;
	/************ Device Upgrade *****************************/
	UILabel *m_upgradeHeaderLabel;
	UILabel *m_serverVersionLabel;
	UITextField *m_serverVersionTextField;
	UIButton *m_serverVersionBtn;
	UIButton *m_upgradeBtn;
	/************ Restart&Recovery ***************************/
	UILabel *m_restartHeaderLabel;
	UIButton *m_restartBtn;
	UIButton *m_recoveryBtn;
	UIButton *m_syncTimeBtn;
	// Methods(Custom)
	// Messages(Actions)
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCheckFirmwareBtnClicked();
	afx_msg void OnServerVersionBtnClicked();
	afx_msg void OnUpgradeBtnClicked();
	afx_msg void OnRestartBtnClicked();
	afx_msg void OnRecoveryBtnClicked();
	afx_msg void OnSyncTimeBtnClicked();
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

