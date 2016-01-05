
// NetworkSettingsView.cpp 2016-1-3 21:35:23

// Includes

// Includes - rc

// Includes - Views
#include "NetworkSettingsView.h"

// Includes - Customs

// Includes - Other

// macros

#define IDC_LABEL_HEAHER_IP				(55300)
#define IDC_BUTTON_SAVEIP				(55301)

#define IDC_LABEL_HEAHER_WIFI			(55310)
#define IDC_LABEL_SSID					(55311)
#define IDC_TEXTFIELD_SSID				(55312)
#define IDC_LABEL_CODEMODE				(55313)
#define IDC_TEXTFIELD_CODEMODE			(55314)
#define IDC_LABEL_PSWD					(55315)
#define IDC_TEXTFIELD_PSWD				(55316)

#define IDC_BUTTON_SAVEWIFI				(55317)
#define IDC_BUTTON_SCANWIFI				(55318)
#define IDC_TABLE_WIFI					(55319)

// constance

// Constructors
NetworkSettingsView::NetworkSettingsView() {
	TRACE("%s\n", __FUNCTION__);

	// Open this line when you need to find where memory leaks.
	// _CrtSetBreakAlloc(memory_block_number);

	const static int gh = 4;
	const static int gv = 11;
	const static int l = (SCREEN_W-260-(100+gh+353+gh+96))/2;

	// IP - Header Label
	m_ipHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_IP);
	m_ipHeaderLabel->title(_T("设置设备 IP"));	
	m_ipHeaderLabel->fontStyleBold();
	m_ipHeaderLabel->frame(26, 15, 100, 19);
	m_ipHeaderLabel->textAlign(DT_LEFT);
	m_ipHeaderLabel->ShowWindow(SW_SHOW);

	// IP - Save Settings - Button
	m_saveIpSettingsBtn = new UIButton(this, IDC_BUTTON_SAVEIP);
	m_saveIpSettingsBtn->frame(l+100+gh+353+gh, 48, 96, 19);
	m_saveIpSettingsBtn->title(_T("保存"));
	m_saveIpSettingsBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_saveIpSettingsBtn->ShowWindow(SW_SHOW);

	// cutline
	cutline.Load(_T("..\\..\\Resource\\bmp\\cutline.bmp"));
	cutlineFrames[0].SetRect(18, 48+(19+gv)*1, SCREEN_W-260-18, 48+(19+gv)*1+2);

	// WIFI - Header Label
	m_wifiHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_WIFI);
	m_wifiHeaderLabel->title(_T("添加远程设备"));	
	m_wifiHeaderLabel->fontStyleBold();
	m_wifiHeaderLabel->frame(26, 48+(19+gv)*1+2+15, 100, 19);
	m_wifiHeaderLabel->textAlign(DT_LEFT);
	m_wifiHeaderLabel->ShowWindow(SW_SHOW);

	// WIFI - SSID - Label
	m_ssidLabel = new UILabel(this, IDC_LABEL_SSID);
	m_ssidLabel->title(_T("SSID"));
	m_ssidLabel->frame(l, 48+(19+gv)*1+2+48, 100, 19);
	m_ssidLabel->textAlign(DT_RIGHT);
	m_ssidLabel->ShowWindow(SW_SHOW);

	// WIFI - SSID - TextField
	m_ssidTextField = new UITextField(this, IDC_TEXTFIELD_SSID);
	m_ssidTextField->frame(l+100+gh, 48+(19+gv)*1+2+48, 353, 19);
	m_ssidTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_ssidTextField->ShowWindow(SW_SHOW);

	// WIFI - Code Mode - Label
	m_codeModeLabel = new UILabel(this, IDC_LABEL_SSID);
	m_codeModeLabel->title(_T("加密方式"));
	m_codeModeLabel->frame(l, 48+(19+gv)*2+2+48, 100, 19);
	m_codeModeLabel->textAlign(DT_RIGHT);
	m_codeModeLabel->ShowWindow(SW_SHOW);

	// WIFI - Code Mode - TextField
	m_codeModeTextField = new UITextField(this, IDC_TEXTFIELD_SSID);
	m_codeModeTextField->frame(l+100+gh, 48+(19+gv)*2+2+48, 353, 19);
	m_codeModeTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_codeModeTextField->ShowWindow(SW_SHOW);

	// WIFI - Password - Label
	m_pswdLabel = new UILabel(this, IDC_LABEL_PSWD);
	m_pswdLabel->title(_T("设备密码"));	
	m_pswdLabel->frame(l, 48+(19+gv)*3+2+48, 100, 19);
	m_pswdLabel->textAlign(DT_RIGHT);
	m_pswdLabel->ShowWindow(SW_SHOW);

	// WIFI - Device Password - TextField
	m_pswdTextField = new UITextField(this, IDC_TEXTFIELD_PSWD);
	m_pswdTextField->frame(l+100+gh, 48+(19+gv)*3+2+48, 353, 19);
	m_pswdTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_pswdTextField->ShowWindow(SW_SHOW);

	// WIFI - Save Settings - Button
	m_saveWifiSettingsBtn = new UIButton(this, IDC_BUTTON_SAVEWIFI);
	m_saveWifiSettingsBtn->frame(l+100+gh+353+gh, 48+(19+gv)*3+2+48, 96, 19);
	m_saveWifiSettingsBtn->title(_T("保存"));
	m_saveWifiSettingsBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_saveWifiSettingsBtn->ShowWindow(SW_SHOW);

	// Local - Scan - Button
	m_scanWifiBtn = new UIButton(this, IDC_BUTTON_SCANWIFI);
	m_scanWifiBtn->frame(l+100+gh+353+gh+100, 48+(19+gv)*3+2+48, 20, 19);
	m_scanWifiBtn->title(_T("···"));
	m_scanWifiBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx20.bmp"));
	m_scanWifiBtn->ShowWindow(SW_SHOW);

	// Local - Device List
	const static int x = 103;
	const static int y = 48*2+(19+gv)*6+2+48;
	const static int w = SCREEN_W-260-x*2;
	m_wifiTableView = new CListCtrl(); m_wifiTableView->Create(
		WS_CHILD|WS_VISIBLE|LVS_REPORT,
		CRect(x, y, x+w, y+250),
		this,
		IDC_TABLE_WIFI);
	DWORD exStyle = m_wifiTableView->GetExtendedStyle();
	m_wifiTableView->SetExtendedStyle(exStyle|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	const static int COL_NUM = 4;
	const static char *colnames[COL_NUM] = {
		_T("序号"), _T("SSID"), _T("加密方式"), _T("信号强度"), 
	};
	for (int i=0; i<COL_NUM; i++) {
		m_wifiTableView->InsertColumn(i, colnames[i], LVCFMT_LEFT, (w-20)/(COL_NUM+0), i); 
	}
	char buff[100];
	for (int i=0; i<100; i++) {
		m_wifiTableView->InsertItem(i, _T("x"));
		for (int j=0; j<COL_NUM; j++) {
			sprintf_s(buff, "%d, %d", i, j);
			m_wifiTableView->SetItemText(i, j, buff);
		}
	}
	m_wifiTableView->ShowWindow(SW_SHOW);
}  

// Methods(Custom)

// Messages(Mappings)

BEGIN_MESSAGE_MAP(NetworkSettingsView, UIView)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_SAVEIP, OnSaveIpSettingsBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_SAVEWIFI, OnSaveWifiSettingsBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_SCANWIFI, OnScanWifiBtnClicked)
END_MESSAGE_MAP()

// Messages(Actions)

void NetworkSettingsView::OnSaveIpSettingsBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void NetworkSettingsView::OnSaveWifiSettingsBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void NetworkSettingsView::OnScanWifiBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

BOOL NetworkSettingsView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	drawImage(cutline, cutlineFrames[0], pDC);

	// return
	return TRUE;
}

void NetworkSettingsView::OnDestroy() {
	TRACE("%s\n", __FUNCTION__);

	__super::OnDestroy();

	// Clean Group
	if (m_ipHeaderLabel) {
		delete m_ipHeaderLabel;
		m_ipHeaderLabel = NULL;
	}
	if (m_saveIpSettingsBtn) {
		delete m_saveIpSettingsBtn;
		m_saveIpSettingsBtn = NULL;
	}

	// Clean WIFI
	if (m_wifiHeaderLabel) {
		delete m_wifiHeaderLabel;
		m_wifiHeaderLabel = NULL;
	}
	if (m_ssidLabel) {
		delete m_ssidLabel;
		m_ssidLabel = NULL;
	}
	if (m_ssidTextField) {
		delete m_ssidTextField;
		m_ssidTextField = NULL;
	}
	if (m_codeModeLabel) {
		delete m_codeModeLabel;
		m_codeModeLabel = NULL;
	}
	if (m_codeModeTextField) {
		delete m_codeModeTextField;
		m_codeModeTextField = NULL;
	}
	if (m_pswdLabel) {
		delete m_pswdLabel;
		m_pswdLabel = NULL;
	}
	if (m_pswdTextField) {
		delete m_pswdTextField;
		m_pswdTextField = NULL;
	}
	if (m_saveWifiSettingsBtn) {
		delete m_saveWifiSettingsBtn;
		m_saveWifiSettingsBtn = NULL;
	}
	if (m_scanWifiBtn) {
		delete m_scanWifiBtn;
		m_scanWifiBtn = NULL;
	}
	if (m_wifiTableView) {
		delete m_wifiTableView;
		m_wifiTableView = NULL;
	}
	
}

