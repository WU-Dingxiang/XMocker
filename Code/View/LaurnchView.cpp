
// LaurnchView.cpp 2015-12-30 20:10:09

// Includes

// Includes - rc
#include "resource.h"

// Includes - Views
#include "LaurnchView.h"
#include "RealtimePlayView.h"
#include "SystemSettingsView.h"

// Includes - Customs

// macros

#define IDC_BUTTON_NAVBAR			(50000)

// Constructors
LaurnchView::LaurnchView() {
	TRACE("%s\n", __FUNCTION__);

	// Open this line to stop at specific 'memory_block_number'.
	// _CrtSetBreakAlloc(905);

	// Set Frame
	this->frame(0, 0, SCREEN_W, SCREEN_H);

	// Load Icon
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_ICON_LOGO); // execute
	this->SetIcon(hIcon, TRUE); // big
	this->SetIcon(hIcon, FALSE); // small

	// Title - Image
	this->titleImage("..\\..\\Resource\\bmp\\title_background.bmp");
	this->titleImageFrame(0,0,SCREEN_W,TITLE_H);

	// Navigation Bar - Image
	this->navbarImage("..\\..\\Resource\\bmp\\navbar_background.bmp");
	this->navbarImageFrame(0,TITLE_H,SCREEN_W,NAVBAR_H);

	// Navigation Bar - Buttons
	const static LPCTSTR titles[NAVBAR_BTN_NUM] = {
		_T("实时监控"), _T("远程播放"), _T("本地播放"), _T("报警查询"), _T("系统设置")
	};
	const static LPCTSTR iconPaths[NAVBAR_BTN_NUM] = {
		_T("..\\..\\Resource\\png\\realtime_play.png"),
		_T("..\\..\\Resource\\png\\remote_play.png"),
		_T("..\\..\\Resource\\png\\local_play.png"),
		_T("..\\..\\Resource\\png\\alarm_query.png"),
		_T("..\\..\\Resource\\png\\system_settings.png"),
	};
	m_uiViews[0] = new RealtimePlayView();
	m_uiViews[1] = new RealtimePlayView();
	m_uiViews[2] = new RealtimePlayView();
	m_uiViews[3] = new RealtimePlayView();
	m_uiViews[4] = new SystemSettingsView();
	for (int i=0; i<NAVBAR_BTN_NUM; i++) {
		// Navigation Bar Buttons
		m_navbarBtns[i] = new UIButton(this, IDC_BUTTON_NAVBAR+i);
		m_navbarBtns[i]->frame(48+117*i,TITLE_H,97,NAVBAR_H);
		m_navbarBtns[i]->backgroundImage("..\\..\\Resource\\bmp\\navbar_button_background.bmp");
		m_navbarBtns[i]->icon(iconPaths[i]);
		m_navbarBtns[i]->title(titles[i]);
		m_navbarBtns[i]->ShowWindow(SW_SHOW);
		// Main Views
		m_uiViews[i]->SetParent(this);
		m_uiViews[i]->frame(260, TITLE_H+NAVBAR_H, SCREEN_W-260, SCREEN_H-TITLE_H-NAVBAR_H);

	}
	m_curSelectedBtnIndex = 0;
	m_navbarBtns[m_curSelectedBtnIndex]->select(TRUE);
	m_uiViews[m_curSelectedBtnIndex]->ShowWindow(SW_SHOW);
	
	// LeftTreeView
	m_leftTreeView = new UITreeView(this); 
	m_leftTreeView->frame(0,TITLE_H+NAVBAR_H,260,SCREEN_H-(TITLE_H+NAVBAR_H));
	m_leftTreeView->backgroundImage("..\\..\\Resource\\bmp\\tree_background.bmp");
	m_leftTreeView->ShowWindow(SW_SHOW);

	HTREEITEM rootItem;
	rootItem = m_leftTreeView->InsertItem("Root_0");
	m_leftTreeView->InsertItem("Child_01", rootItem);
	m_leftTreeView->InsertItem("Child_02", rootItem);

	rootItem = m_leftTreeView->InsertItem("Root_1");
	m_leftTreeView->InsertItem("Child_11", rootItem);
	m_leftTreeView->InsertItem("Child_12", rootItem);
}  


// Methods(Setter)

// Methods - Set TitleImage
void LaurnchView::titleImage(LPCTSTR pszFileName, BOOL isPng) {
	TRACE("%s\n", __FUNCTION__);

	m_titleImage.Load(pszFileName);
}

// Methods - Set NavbarImage
void LaurnchView::navbarImage(LPCTSTR pszFileName, BOOL isPng) {
	TRACE("%s\n", __FUNCTION__);

	m_navbarImage.Load(pszFileName);
}

// Methods - Set TitleImageFrame
void LaurnchView::titleImageFrame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	m_titleImageFrame.SetRect(x, y, x+w, y+h);
}

// Methods - Set NavbarImageFrame
void LaurnchView::navbarImageFrame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	m_navbarImageFrame.SetRect(x, y, x+w, y+h);
}

// Messages(Mappings)

BEGIN_MESSAGE_MAP(LaurnchView, UIView)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_COMMAND_RANGE(IDC_BUTTON_NAVBAR, IDC_BUTTON_NAVBAR+NAVBAR_BTN_NUM-1, OnNavbarBtnClicked)
END_MESSAGE_MAP()

// Messages(Actions)

void LaurnchView::OnNavbarBtnClicked(UINT uID) {
	TRACE("%s\t", __FUNCTION__);
	TRACE("uID = %d\n", uID);

	// Filter
	UINT nextSelectedBtnIndex = uID - IDC_BUTTON_NAVBAR;
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

BOOL LaurnchView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	// Clean
	if (!m_transparent) {
		__super::OnEraseBkgnd(pDC);
	}

	// Draw Images
	this->drawImage(m_titleImage, m_titleImageFrame, pDC);
	this->drawImage(m_navbarImage, m_navbarImageFrame, pDC);

	// return
	return TRUE;
}

void LaurnchView::OnDestroy() {
	TRACE("%s\n", __FUNCTION__);

	__super::OnDestroy();

	// Clean Navigation Bar Buttons
	for (int i=0; i<NAVBAR_BTN_NUM; i++) {
		if (m_navbarBtns[i]) {
			delete m_navbarBtns[i];
			m_navbarBtns[i] = NULL;
		}
	}

	// Clean Left Tree
	if (m_leftTreeView) {
		delete m_leftTreeView;
		m_leftTreeView = NULL;
	}
	
}

