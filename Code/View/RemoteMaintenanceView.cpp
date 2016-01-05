
// RemoteMaintenanceView.cpp 2016-1-3 21:35:23

// Includes

// Includes - rc

// Includes - Views
#include "RemoteMaintenanceView.h"

// Includes - Customs

// Includes - Other

// macros
typedef enum {
	/************ Device Info List ***************************/
	IDC_LABEL_HEAHER_INFO = 55500		,
	IDC_BUTTON_CHECKFIRMWARE			,
	IDC_TABLE_DEVICEINFO				,
	/************ Device Upgrade *****************************/
	IDC_LABEL_HEAHER_UPGRADE			,
	IDC_LABEL_SERVERVERSION				,
	IDC_TEXTFIELD_SERVERVERSION			,
	IDC_BUTTON_SERVERVERSION			,
	IDC_BUTTON_DOWNLOADFIRMWARE			,
	IDC_BUTTON_UPGRADE					,
	/************ Restart&Recovery ***************************/
	IDC_LABEL_HEAHER_RESTART			,
	IDC_BUTTON_RESTART					,
	IDC_BUTTON_RECOVERY					,
	IDC_BUTTON_SYNCTIME					,
};

// constance

// Constructors
RemoteMaintenanceView::RemoteMaintenanceView() {
	TRACE("%s\n", __FUNCTION__);

	// Open this line when you need to find where memory leaks.
	// _CrtSetBreakAlloc(memory_block_number);

	const static int gh = 4;
	const static int gv = 11;
	const static int l = (SCREEN_W-260-(100+gh+353+gh+96))/2;

	// Info - Header Label
	m_infoHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_INFO);
	m_infoHeaderLabel->title(_T("设备信息列表"));	
	m_infoHeaderLabel->fontStyleBold();
	m_infoHeaderLabel->frame(26, 15, 100, 19);
	m_infoHeaderLabel->textAlign(DT_LEFT);
	m_infoHeaderLabel->ShowWindow(SW_SHOW);

	// Info - Save Settings - Button
	m_checkFirmwareBtn = new UIButton(this, IDC_BUTTON_CHECKFIRMWARE);
	m_checkFirmwareBtn->frame(l+100+gh+353+gh, 48, 96, 19);
	m_checkFirmwareBtn->title(_T("检查固件版本"));
	m_checkFirmwareBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_checkFirmwareBtn->ShowWindow(SW_SHOW);

	// Info - Device List
	const static int x = 103;
	const static int y = 48*2+(19+gv)*6+2+48;
	const static int w = SCREEN_W-260-x*2;
	m_deviceInfoTableView = new CListCtrl(); m_deviceInfoTableView->Create(
		WS_CHILD|WS_VISIBLE|LVS_REPORT,
		CRect(x, y, x+w, y+250),
		this,
		IDC_TABLE_DEVICEINFO);
	DWORD exStyle = m_deviceInfoTableView->GetExtendedStyle();
	m_deviceInfoTableView->SetExtendedStyle(exStyle|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	const static int COL_NUM = 5;
	const static char *colnames[COL_NUM] = {
		_T("序号"), _T("设备名称"), _T("设备 ID"), _T("当前状态"), _T("固件版本"), 
	};
	for (int i=0; i<COL_NUM; i++) {
		m_deviceInfoTableView->InsertColumn(i, colnames[i], LVCFMT_LEFT, (w-20)/(COL_NUM+0), i); 
	}
	char buff[100];
	for (int i=0; i<100; i++) {
		m_deviceInfoTableView->InsertItem(i, _T("x"));
		for (int j=0; j<COL_NUM; j++) {
			sprintf_s(buff, "%d, %d", i, j);
			m_deviceInfoTableView->SetItemText(i, j, buff);
		}
	}
	m_deviceInfoTableView->ShowWindow(SW_SHOW);

	// cutline
	cutline.Load(_T("..\\..\\Resource\\bmp\\cutline.bmp"));
	cutlineFrames[0].SetRect(18, 48+(19+gv)*1, SCREEN_W-260-18, 48+(19+gv)*1+2);

	// Upgrade - Header Label
	m_upgradeHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_UPGRADE);
	m_upgradeHeaderLabel->title(_T("升级设备"));	
	m_upgradeHeaderLabel->fontStyleBold();
	m_upgradeHeaderLabel->frame(26, 48+(19+gv)*1+2+15, 100, 19);
	m_upgradeHeaderLabel->textAlign(DT_LEFT);
	m_upgradeHeaderLabel->ShowWindow(SW_SHOW);

	// Upgrade - Server Version - Label
	m_serverVersionLabel = new UILabel(this, IDC_LABEL_SERVERVERSION);
	m_serverVersionLabel->title(_T("最新版本"));
	m_serverVersionLabel->frame(l, 48+(19+gv)*1+2+48, 100, 19);
	m_serverVersionLabel->textAlign(DT_RIGHT);
	m_serverVersionLabel->ShowWindow(SW_SHOW);

	// Upgrade - Server Version - TextField
	m_serverVersionTextField = new UITextField(this, IDC_TEXTFIELD_SERVERVERSION);
	m_serverVersionTextField->frame(l+100+gh, 48+(19+gv)*1+2+48, 353, 19);
	m_serverVersionTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_serverVersionTextField->ShowWindow(SW_SHOW);

	// Upgrade - Server Version - Button
	m_serverVersionBtn = new UIButton(this, IDC_BUTTON_SERVERVERSION);
	m_serverVersionBtn->title(_T("···"));
	m_serverVersionBtn->frame(l+100+gh+353+gh, 48+(19+gv)*1+2+48, 20, 19);
	m_serverVersionBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx20.bmp"));
	m_serverVersionBtn->ShowWindow(SW_SHOW);

	// Upgrade - Password - Button
	m_upgradeBtn = new UIButton(this, IDC_BUTTON_UPGRADE);
	m_upgradeBtn->title(_T("升级系统"));	
	m_upgradeBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_upgradeBtn->frame(l+100+gh, 48+(19+gv)*2+2+48, 100, 19);
	m_upgradeBtn->ShowWindow(SW_SHOW);

	// cutline
	cutlineFrames[1].SetRect(18, 48+(19+gv)*3+2+48, SCREEN_W-260-18, 48+(19+gv)*3+2+48+2);

	// Restart - Header Label
	m_restartHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_RESTART);
	m_restartHeaderLabel->title(_T("重启与恢复"));	
	m_restartHeaderLabel->fontStyleBold();
	m_restartHeaderLabel->frame(26, 48*2+(19+gv)*3+2*2+15, 100, 19);
	m_restartHeaderLabel->textAlign(DT_LEFT);
	m_restartHeaderLabel->ShowWindow(SW_SHOW);

	// Restart - Device Password - Button
	m_restartBtn = new UIButton(this, IDC_BUTTON_RESTART);
	m_restartBtn->title(_T("重启设备"));
	m_restartBtn->frame(l+100+gh, 48*2+(19+gv)*3+2*2+48, 96, 19);
	m_restartBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_restartBtn->ShowWindow(SW_SHOW);

	// Restart - Save Settings - Button
	m_recoveryBtn = new UIButton(this, IDC_BUTTON_RECOVERY);
	m_recoveryBtn->frame(l+100+gh, 48*2+(19+gv)*4+2*2+48, 96, 19);
	m_recoveryBtn->title(_T("恢复出厂"));
	m_recoveryBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_recoveryBtn->ShowWindow(SW_SHOW);

	// Restart - Scan - Button
	m_syncTimeBtn = new UIButton(this, IDC_BUTTON_SYNCTIME);
	m_syncTimeBtn->frame(l+100+gh, 48*2+(19+gv)*5+2*2+48, 96, 19);
	m_syncTimeBtn->title(_T("同步系统时间"));
	m_syncTimeBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_syncTimeBtn->ShowWindow(SW_SHOW);
}  

// Methods(Custom)

// Messages(Mappings)

BEGIN_MESSAGE_MAP(RemoteMaintenanceView, UIView)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_CHECKFIRMWARE, OnCheckFirmwareBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_SERVERVERSION, OnServerVersionBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_UPGRADE, OnUpgradeBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_RESTART, OnRestartBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_RECOVERY, OnRecoveryBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_SYNCTIME, OnSyncTimeBtnClicked)
END_MESSAGE_MAP()

// Messages(Actions)

void RemoteMaintenanceView::OnCheckFirmwareBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void RemoteMaintenanceView::OnServerVersionBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void RemoteMaintenanceView::OnUpgradeBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void RemoteMaintenanceView::OnRestartBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void RemoteMaintenanceView::OnRecoveryBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void RemoteMaintenanceView::OnSyncTimeBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

BOOL RemoteMaintenanceView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	drawImage(cutline, cutlineFrames[0], pDC);
	drawImage(cutline, cutlineFrames[1], pDC);

	// return
	return TRUE;
}

void RemoteMaintenanceView::OnDestroy() {
	TRACE("%s\n", __FUNCTION__);

	__super::OnDestroy();

	/************ Device Info List ***************************/
	if (m_infoHeaderLabel) {
		delete m_infoHeaderLabel;
		m_infoHeaderLabel = NULL;
	}
	if (m_checkFirmwareBtn) {
		delete m_checkFirmwareBtn;
		m_checkFirmwareBtn = NULL;
	}

	/************ Device Upgrade *****************************/
	if (m_upgradeHeaderLabel) {
		delete m_upgradeHeaderLabel;
		m_upgradeHeaderLabel = NULL;
	}
	if (m_serverVersionLabel) {
		delete m_serverVersionLabel;
		m_serverVersionLabel = NULL;
	}
	if (m_serverVersionTextField) {
		delete m_serverVersionTextField;
		m_serverVersionTextField = NULL;
	}
	if (m_serverVersionBtn) {
		delete m_serverVersionBtn;
		m_serverVersionBtn = NULL;
	}
	if (m_upgradeBtn) {
		delete m_upgradeBtn;
		m_upgradeBtn = NULL;
	}

	/************ Restart&Recovery ***************************/
	if (m_restartHeaderLabel) {
		delete m_restartHeaderLabel;
		m_restartHeaderLabel = NULL;
	}
	if (m_restartBtn) {
		delete m_restartBtn;
		m_restartBtn = NULL;
	}
	if (m_recoveryBtn) {
		delete m_recoveryBtn;
		m_recoveryBtn = NULL;
	}
	if (m_syncTimeBtn) {
		delete m_syncTimeBtn;
		m_syncTimeBtn = NULL;
	}
	if (m_deviceInfoTableView) {
		delete m_deviceInfoTableView;
		m_deviceInfoTableView = NULL;
	}

}

