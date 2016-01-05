
// UITreeView.cpp 2015-12-31 17:36:31

#include "AppDelegate.h"
#include "UITreeView.h"
#include "atlimage.h"

// Constructors

UITreeView::UITreeView(CWnd* pParentWnd) {
	TRACE("%s\n", __FUNCTION__);

	if (!pParentWnd) {
		TRACE("pParentWnd can NOT be NULL.\n");
		return;
	}

	// Init with VALID pParentWnd
	this->Create(
		TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_DISABLEDRAGDROP,
		CRect(0,0,0,0),
		pParentWnd,
		UINT(0)
		);

	// Clean Flags
	m_transparent = FALSE;
}

// Methods

// Methods(Setter) - Set Transparent
void UITreeView::transparent(BOOL isTransparent) {
	TRACE("%s\n", __FUNCTION__);

	m_transparent = isTransparent;
}

// Methods - Set Frame
void UITreeView::frame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	this->MoveWindow(x, y, w, h);
}

// Methods - Set Background Image
void UITreeView::backgroundImage(LPCTSTR pszFileName) {
	TRACE("%s\n", __FUNCTION__);

	m_backgroundImage.Load(pszFileName);
}


// Messages(Mappings)

BEGIN_MESSAGE_MAP(UITreeView, CTreeCtrl)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// Messages(Actions)

BOOL UITreeView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	// Get Rect
	CRect rect; GetClientRect(rect);
	if (rect.Width()<1 || rect.Height()<1) {
		return TRUE;
	}

	// Clean
	if (!m_transparent) {
		__super::OnEraseBkgnd(pDC);
	}

	// Filter
	if (!m_backgroundImage.IsDIBSection()) {
		return TRUE;
	}

	// Change Mode - Avoid Twist
	::SetStretchBltMode(*pDC, HALFTONE);
	::SetBrushOrgEx(*pDC, 0, 0, NULL);

	// Draw Background Image
	m_backgroundImage.Draw(pDC->m_hDC, rect);

	// return
	return TRUE;
}

