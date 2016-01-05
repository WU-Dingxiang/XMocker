
// SystemSettingsView.cpp 2016-1-3 17:28:06

// Includes

// Includes - rc

// Includes - Views
#include "SystemSettingsView.h"
#include "GlobalSettingsView.h"
#include "DeviceManagementView.h"
#include "NetworkSettingsView.h"
#include "RecordStrategyView.h"
#include "RemoteMaintenanceView.h"

// Includes - Customs

// macros

#define IDC_BUTTON_SYSNAVBAR			(55000)

// Constructors
SystemSettingsView::SystemSettingsView() {
	TRACE("%s\n", __FUNCTION__);

	// Open this line when you need to find where memory leaks.
	// _CrtSetBreakAlloc(memory_block_number);

	// NavbarImage
	this->navbarImage("..\\..\\Resource\\bmp\\system_settings_navbar_background.bmp");
	this->navbarImageFrame(0,0,SCREEN_W-260,CTRL_H);

	// Navigation Bar Buttons + UIViews
	const static LPCTSTR titles[SYSNAVBAR_BTN_NUM] = {
		_T("全局配置"), _T("设备管理"), _T("网络设置"), _T("录像策略"), _T("远程维护")
	};
	const static int l = (SCREEN_W-260-SYSNAVBAR_BTN_NUM*117+117)/2;
	m_uiViews[0] = new GlobalSettingsView();
	m_uiViews[1] = new DeviceManagementView();
	m_uiViews[2] = new NetworkSettingsView();
	m_uiViews[3] = new RecordStrategyView();
	m_uiViews[4] = new RemoteMaintenanceView();
	for (int i=0; i<SYSNAVBAR_BTN_NUM; i++) {
		m_navbarBtns[i] = new UIButton(this, IDC_BUTTON_SYSNAVBAR+i);
		m_navbarBtns[i]->frame(l+117*i,0,97,CTRL_H);
		m_navbarBtns[i]->title(titles[i]);
		m_navbarBtns[i]->backgroundImage("..\\..\\Resource\\bmp\\system_settings_navbar_background.bmp");
		m_navbarBtns[i]->ShowWindow(SW_SHOW);
		// Setting Views
		m_uiViews[i]->SetParent(this);
		m_uiViews[i]->frame(0, CTRL_H, SCREEN_W-260, SCREEN_H-TITLE_H-NAVBAR_H-CTRL_H);
	}
	m_curSelectedBtnIndex = 0;
	m_navbarBtns[m_curSelectedBtnIndex]->select(TRUE);
	m_uiViews[m_curSelectedBtnIndex]->ShowWindow(SW_SHOW);

}  


// Methods(Setter)

// Methods - Set NavbarImage
void SystemSettingsView::navbarImage(LPCTSTR pszFileName, BOOL isPng) {
	TRACE("%s\n", __FUNCTION__);

	m_navbarImage.Load(pszFileName);
}

// Methods - Set NavbarImageFrame
void SystemSettingsView::navbarImageFrame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	m_navbarImageFrame.SetRect(x, y, x+w, y+h);
}

// Messages(Mappings)

BEGIN_MESSAGE_MAP(SystemSettingsView, UIView)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_COMMAND_RANGE(IDC_BUTTON_SYSNAVBAR, IDC_BUTTON_SYSNAVBAR+SYSNAVBAR_BTN_NUM-1, OnNavbarBtnClicked)
END_MESSAGE_MAP()

// Messages(Actions)

void SystemSettingsView::OnNavbarBtnClicked(UINT uID) {
	TRACE("%s\t", __FUNCTION__);
	TRACE("uID = %d\n", uID);

	// Filter
	UINT nextSelectedBtnIndex = uID - IDC_BUTTON_SYSNAVBAR;
	if (nextSelectedBtnIndex == m_curSelectedBtnIndex) return;

	// Hide Current View 
	m_navbarBtns[m_curSelectedBtnIndex]->select(FALSE);
	m_navbarBtns[m_curSelectedBtnIndex]->Invalidate(); // ASYNC
	m_uiViews[m_curSelectedBtnIndex]->ShowWindow(SW_HIDE);

	// Show Next View
	m_navbarBtns[nextSelectedBtnIndex]->select(TRUE);
	m_navbarBtns[nextSelectedBtnIndex]->Invalidate(); // ASYNC
	m_uiViews[nextSelectedBtnIndex]->ShowWindow(SW_SHOW);

	// Save Index
	m_curSelectedBtnIndex = nextSelectedBtnIndex;

}

BOOL SystemSettingsView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	// Clean
	if (!m_transparent) {
		__super::OnEraseBkgnd(pDC);
	}

	// Draw Images
	this->drawImage(m_navbarImage, m_navbarImageFrame, pDC);

	// return
	return TRUE;
}

void SystemSettingsView::OnDestroy() {
	TRACE("%s\n", __FUNCTION__);

	__super::OnDestroy();

	// Clean Navigation Bar Buttons
	for (int i=0; i<SYSNAVBAR_BTN_NUM; i++) {
		if (m_navbarBtns[i]) {
			delete m_navbarBtns[i];
			m_navbarBtns[i] = NULL;
		}
	}	
}

