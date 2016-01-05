
// LaurnchView.h 2015-12-31 15:25:59

#pragma once

// Includes(Customs)
#include "UIView.h"
#include "UITreeView.h"
#include "UIButton.h"

// macros

const static UINT NAVBAR_BTN_NUM = 5;

// constance

// class
class LaurnchView : public UIView {
public:
	// Constructors
	LaurnchView();
	// Methods(Setter)
	void titleImage(LPCTSTR pszFileName, BOOL isPng = FALSE);
	void navbarImage(LPCTSTR pszFileName, BOOL isPng = FALSE);
	// Methods(Setter)
	void titleImageFrame(int x, int y, int w, int h);
	void navbarImageFrame(int x, int y, int w, int h);
protected:
	// Attributes(Objects)
	UINT m_curSelectedBtnIndex;
	CImage m_titleImage;
	CImage m_navbarImage;
	CRect m_titleImageFrame;
	CRect m_navbarImageFrame;
	// Attributes(Pointers)
	UIView *m_uiViews[NAVBAR_BTN_NUM];
	UIButton *m_navbarBtns[NAVBAR_BTN_NUM];
	UITreeView *m_leftTreeView;
	// Methods(Custom)
	// Messages(Actions)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNavbarBtnClicked(UINT uID);
	afx_msg void OnDestroy();
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

