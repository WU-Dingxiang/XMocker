
// DeviceManagementView.cpp 2016-1-3 21:35:23

// Includes

// Includes - rc

// Includes - Views
#include "DeviceManagementView.h"

// Includes - Customs

// Includes - Other

// macros

#define IDC_LABEL_HEAHER_GROUP			(55200)
#define IDC_LABEL_NEWGROUP				(55201)
#define IDC_TEXTFIELD_NEWGROUP			(55202)
#define IDC_BUTTON_NEWGROUP				(55203)

#define IDC_LABEL_HEAHER_REMOTEADD		(55204)
#define IDC_LABEL_REMOTEDEVICEID		(55205)
#define IDC_TEXTFIELD_REMOTEDEVICEID	(55206)
#define IDC_LABEL_REMOTEDEVICEPSWD		(55207)
#define IDC_TEXTFIELD_REMOTEDEVICEPSWD	(55208)
#define IDC_BUTTON_REMOTEADD			(55209)

#define IDC_LABEL_HEAHER_LOCALADD		(55210)
#define IDC_LABEL_LOCALDEVICEID			(55211)
#define IDC_TEXTFIELD_LOCALDEVICEID		(55212)
#define IDC_LABEL_LOCALDEVICEPSWD		(55213)
#define IDC_TEXTFIELD_LOCALDEVICEPSWD	(55214)
#define IDC_BUTTON_LOCALADD				(55215)
#define IDC_BUTTON_UPDATELIST			(55216)
#define IDC_TABLE_DEVICELIST			(55217)

// constance

// Constructors
DeviceManagementView::DeviceManagementView() {
	TRACE("%s\n", __FUNCTION__);

	// Open this line when you need to find where memory leaks.
	// _CrtSetBreakAlloc(memory_block_number);

	const static int gh = 4;
	const static int gv = 11;
	const static int l = (SCREEN_W-260-(100+gh+353+gh+96))/2;

	// Group - Header Label
	m_groupHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_GROUP);
	m_groupHeaderLabel->title(_T("设备分组信息"));	
	m_groupHeaderLabel->fontStyleBold();
	m_groupHeaderLabel->frame(26, 15, 100, 19);
	m_groupHeaderLabel->textAlign(DT_LEFT);
	m_groupHeaderLabel->ShowWindow(SW_SHOW);

	// Group - New Group - Label
	m_newGroupLabel = new UILabel(this, IDC_LABEL_NEWGROUP);
	m_newGroupLabel->title(_T("新分组名称"));	
	m_newGroupLabel->frame(l, 48, 100, 19);
	m_newGroupLabel->textAlign(DT_RIGHT);
	m_newGroupLabel->ShowWindow(SW_SHOW);

	// Group - New Group - TextField
	m_newGroupTextField = new UITextField(this, IDC_TEXTFIELD_NEWGROUP);
	m_newGroupTextField->frame(l+100+gh, 48, 353, 19);
	m_newGroupTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_newGroupTextField->ShowWindow(SW_SHOW);

	// Group - New Group - Button
	m_newGroupBtn = new UIButton(this, IDC_BUTTON_NEWGROUP);
	m_newGroupBtn->frame(l+100+gh+353+gh, 48, 96, 19);
	m_newGroupBtn->title(_T("添加"));
	m_newGroupBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_newGroupBtn->ShowWindow(SW_SHOW);

	// cutline
	cutline.Load(_T("..\\..\\Resource\\bmp\\cutline.bmp"));
	cutlineFrames[0].SetRect(18, 48+(19+gv)*1, SCREEN_W-260-18, 48+(19+gv)*1+2);

	// Remote - Header Label
	m_remoteHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_REMOTEADD);
	m_remoteHeaderLabel->title(_T("添加远程设备"));	
	m_remoteHeaderLabel->fontStyleBold();
	m_remoteHeaderLabel->frame(26, 48+(19+gv)*1+2+15, 100, 19);
	m_remoteHeaderLabel->textAlign(DT_LEFT);
	m_remoteHeaderLabel->ShowWindow(SW_SHOW);

	// Remote - Device ID - Label
	m_remoteDeviceIdLabel = new UILabel(this, IDC_LABEL_REMOTEDEVICEID);
	m_remoteDeviceIdLabel->title(_T("设备ID"));	
	m_remoteDeviceIdLabel->frame(l, 48+(19+gv)*1+2+48, 100, 19);
	m_remoteDeviceIdLabel->textAlign(DT_RIGHT);
	m_remoteDeviceIdLabel->ShowWindow(SW_SHOW);

	// Remote - Device ID - TextField
	m_remoteDeviceIdTextField = new UITextField(this, IDC_TEXTFIELD_REMOTEDEVICEID);
	m_remoteDeviceIdTextField->frame(l+100+gh, 48+(19+gv)*1+2+48, 353, 19);
	m_remoteDeviceIdTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_remoteDeviceIdTextField->ShowWindow(SW_SHOW);

	// Remote - Device Password - Label
	m_remoteDevicePswdLabel = new UILabel(this, IDC_LABEL_REMOTEDEVICEPSWD);
	m_remoteDevicePswdLabel->title(_T("设备密码"));	
	m_remoteDevicePswdLabel->frame(l, 48+(19+gv)*2+2+48, 100, 19);
	m_remoteDevicePswdLabel->textAlign(DT_RIGHT);
	m_remoteDevicePswdLabel->ShowWindow(SW_SHOW);

	// Remote - Device Password - TextField
	m_remoteDevicePswdTextField = new UITextField(this, IDC_TEXTFIELD_NEWGROUP);
	m_remoteDevicePswdTextField->frame(l+100+gh, 48+(19+gv)*2+2+48, 353, 19);
	m_remoteDevicePswdTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_remoteDevicePswdTextField->ShowWindow(SW_SHOW);

	// Remote - New Device - Button
	m_addRemoteDeviceBtn = new UIButton(this, IDC_BUTTON_NEWGROUP);
	m_addRemoteDeviceBtn->frame(l+100+gh+353+gh, 48+(19+gv)*2+2+48, 96, 19);
	m_addRemoteDeviceBtn->title(_T("添加"));
	m_addRemoteDeviceBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_addRemoteDeviceBtn->ShowWindow(SW_SHOW);

	// cutline
	cutlineFrames[1].SetRect(18, 48*2+(19+gv)*3, SCREEN_W-260-18, 48*2+(19+gv)*3+2);

	// Local - Header Label
	m_localHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_REMOTEADD);
	m_localHeaderLabel->title(_T("添加本地设备"));	
	m_localHeaderLabel->fontStyleBold();
	m_localHeaderLabel->frame(26, 48*2+(19+gv)*3+2+15, 100, 19);
	m_localHeaderLabel->textAlign(DT_LEFT);
	m_localHeaderLabel->ShowWindow(SW_SHOW);

	// Local - Device ID - Label
	m_localDeviceIdLabel = new UILabel(this, IDC_LABEL_REMOTEDEVICEID);
	m_localDeviceIdLabel->title(_T("设备ID"));	
	m_localDeviceIdLabel->frame(l, 48*2+(19+gv)*3+2+48, 100, 19);
	m_localDeviceIdLabel->textAlign(DT_RIGHT);
	m_localDeviceIdLabel->ShowWindow(SW_SHOW);

	// Local - Device ID - TextField
	m_localDeviceIdTextField = new UITextField(this, IDC_TEXTFIELD_REMOTEDEVICEID);
	m_localDeviceIdTextField->frame(l+100+gh, 48*2+(19+gv)*3+2+48, 353, 19);
	m_localDeviceIdTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_localDeviceIdTextField->ShowWindow(SW_SHOW);

	// Local - Device Password - Label
	m_localDevicePswdLabel = new UILabel(this, IDC_LABEL_REMOTEDEVICEPSWD);
	m_localDevicePswdLabel->title(_T("设备密码"));	
	m_localDevicePswdLabel->frame(l, 48*2+(19+gv)*4+2+48, 100, 19);
	m_localDevicePswdLabel->textAlign(DT_RIGHT);
	m_localDevicePswdLabel->ShowWindow(SW_SHOW);

	// Local - Device Password - TextField
	m_localDevicePswdTextField = new UITextField(this, IDC_TEXTFIELD_NEWGROUP);
	m_localDevicePswdTextField->frame(l+100+gh, 48*2+(19+gv)*4+2+48, 353, 19);
	m_localDevicePswdTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_localDevicePswdTextField->ShowWindow(SW_SHOW);

	// Local - New Device - Button
	m_addLocalDeviceBtn = new UIButton(this, IDC_BUTTON_NEWGROUP);
	m_addLocalDeviceBtn->frame(l+100+gh+353+gh, 48*2+(19+gv)*4+2+48, 96, 19);
	m_addLocalDeviceBtn->title(_T("添加"));
	m_addLocalDeviceBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_addLocalDeviceBtn->ShowWindow(SW_SHOW);

	// Local - Update List - Button
	m_updateListBtn = new UIButton(this, IDC_BUTTON_UPDATELIST);
	m_updateListBtn->frame(l+100+gh+353+gh+100, 48*2+(19+gv)*4+2+48, 20, 19);
	m_updateListBtn->title(_T("···"));
	m_updateListBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx20.bmp"));
	m_updateListBtn->ShowWindow(SW_SHOW);

	// Local - Device List
	const static int x = 103;
	const static int y = 48*2+(19+gv)*6+2+48;
	const static int w = SCREEN_W-260-x*2;
	m_localDeviceTableView = new CListCtrl(); m_localDeviceTableView->Create(
		WS_CHILD|WS_VISIBLE|LVS_REPORT,
		CRect(x, y, x+w, y+250),
		this,
		IDC_TABLE_DEVICELIST);
	DWORD exStyle = m_localDeviceTableView->GetExtendedStyle();
	m_localDeviceTableView->SetExtendedStyle(exStyle|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	const static int COL_NUM = 8;
	const static char *colnames[COL_NUM] = {
		_T("设备编号"), _T("设备 ID"), _T("设备 IP"), _T("MAC 地址"), 
		_T("设备名称"), _T("CPU 类型"), _T("WIFI 类型"), _T("设备类型"),
	};
	for (int i=0; i<COL_NUM; i++) {
		m_localDeviceTableView->InsertColumn(i, colnames[i], LVCFMT_LEFT, (w-20)/(COL_NUM+0), i); 
	}
	char buff[100];
	for (int i=0; i<100; i++) {
		m_localDeviceTableView->InsertItem(i, _T("x"));
		for (int j=0; j<COL_NUM; j++) {
			sprintf_s(buff, "%d, %d", i, j);
			m_localDeviceTableView->SetItemText(i, j, buff);
		}
	}
	m_localDeviceTableView->ShowWindow(SW_SHOW);
}  

// Methods(Custom)

// Messages(Mappings)

BEGIN_MESSAGE_MAP(DeviceManagementView, UIView)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_NEWGROUP, OnNewGroupBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_REMOTEADD, OnAddRemoteDeviceBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_LOCALADD, OnAddLocalDeviceBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_UPDATELIST, OnUpdateDeviceListBtnClicked)
END_MESSAGE_MAP()

// Messages(Actions)

void DeviceManagementView::OnNewGroupBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void DeviceManagementView::OnAddRemoteDeviceBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void DeviceManagementView::OnAddLocalDeviceBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void DeviceManagementView::OnUpdateDeviceListBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

BOOL DeviceManagementView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	drawImage(cutline, cutlineFrames[0], pDC);
	drawImage(cutline, cutlineFrames[1], pDC);

	// return
	return TRUE;
}

void DeviceManagementView::OnDestroy() {
	TRACE("%s\n", __FUNCTION__);

	__super::OnDestroy();

	// Clean Group
	if (m_groupHeaderLabel) {
		delete m_groupHeaderLabel;
		m_groupHeaderLabel = NULL;
	}
	if (m_newGroupLabel) {
		delete m_newGroupLabel;
		m_newGroupLabel = NULL;
	}
	if (m_newGroupTextField) {
		delete m_newGroupTextField;
		m_newGroupTextField = NULL;
	}
	if (m_newGroupBtn) {
		delete m_newGroupBtn;
		m_newGroupBtn = NULL;
	}

	// Clean Remote
	if (m_remoteHeaderLabel) {
		delete m_remoteHeaderLabel;
		m_remoteHeaderLabel = NULL;
	}
	if (m_remoteDeviceIdLabel) {
		delete m_remoteDeviceIdLabel;
		m_remoteDeviceIdLabel = NULL;
	}
	if (m_remoteDeviceIdTextField) {
		delete m_remoteDeviceIdTextField;
		m_remoteDeviceIdTextField = NULL;
	}
	if (m_remoteDevicePswdLabel) {
		delete m_remoteDevicePswdLabel;
		m_remoteDevicePswdLabel = NULL;
	}
	if (m_remoteDevicePswdTextField) {
		delete m_remoteDevicePswdTextField;
		m_remoteDevicePswdTextField = NULL;
	}
	if (m_addRemoteDeviceBtn) {
		delete m_addRemoteDeviceBtn;
		m_addRemoteDeviceBtn = NULL;
	}

	// Clean Local
	if (m_localHeaderLabel) {
		delete m_localHeaderLabel;
		m_localHeaderLabel = NULL;
	}
	if (m_localDeviceIdLabel) {
		delete m_localDeviceIdLabel;
		m_localDeviceIdLabel = NULL;
	}
	if (m_localDeviceIdTextField) {
		delete m_localDeviceIdTextField;
		m_localDeviceIdTextField = NULL;
	}
	if (m_localDevicePswdLabel) {
		delete m_localDevicePswdLabel;
		m_localDevicePswdLabel = NULL;
	}
	if (m_localDevicePswdTextField) {
		delete m_localDevicePswdTextField;
		m_localDevicePswdTextField = NULL;
	}
	if (m_addLocalDeviceBtn) {
		delete m_addLocalDeviceBtn;
		m_addLocalDeviceBtn = NULL;
	}
	if (m_updateListBtn) {
		delete m_updateListBtn;
		m_updateListBtn = NULL;
	}
	if (m_localDeviceTableView) {
		delete m_localDeviceTableView;
		m_localDeviceTableView = NULL;
	}
	
}

