
// SystemSettingsView.h 2016-1-3 17:28:31

#pragma once

#include "UIView.h"
#include "UIButton.h"

// macros

// constance

const static UINT SYSNAVBAR_BTN_NUM = 5;

// class
class SystemSettingsView : public UIView {
public:
	// Constructors
	SystemSettingsView();
	// Methods(Setter)
	void navbarImage(LPCTSTR pszFileName, BOOL isPng = FALSE);
	void navbarImageFrame(int x, int y, int w, int h);
protected:
	// Attributes(Objects)
	UINT m_curSelectedBtnIndex;
	CImage m_navbarImage;
	CRect m_navbarImageFrame;
	// Attributes(Pointers)
	UIButton *m_navbarBtns[SYSNAVBAR_BTN_NUM];
	UIView *m_uiViews[SYSNAVBAR_BTN_NUM];
	// Methods(Custom)
	// Messages(Actions)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNavbarBtnClicked(UINT uID);
	afx_msg void OnDestroy();
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

