
// UIView.cpp 2015-12-31 15:25:23

#include "UIView.h"

// macros

// Constructors
UIView::UIView() {
	TRACE("%s\n", __FUNCTION__);

	// Init UIView
	this->Create(
		NULL, 
		NULL, 
		WS_OVERLAPPEDWINDOW,
		CRect(0, 0, 0, 0),
		NULL,
		UINT(0)
		);

	// Remove Default Title And Edge
	this->ModifyStyle(WS_TILEDWINDOW, 0, SWP_DRAWFRAME);
	this->ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_DRAWFRAME);

	// Clean Flags
	m_transparent = FALSE;
}

// Methods

// Methods(Setter) - Set Transparent
void UIView::transparent(BOOL isTransparent) {
	TRACE("%s\n", __FUNCTION__);

	m_transparent = isTransparent;
}

// Methods(Custom) - Set Frame
void UIView::frame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	this->MoveWindow(x, y, w, h);
}

// Methods(Utilities) - Set Draw Image
void UIView::drawImage(CImage &img, CRect rect, CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	// Get Rect
	if (rect.Width()<1 || rect.Height()<1) {
		return;
	}

	// Filter
	if (!img.IsDIBSection()) {
		return; // BackgroundType: None
	}

	// Change Mode - Avoid Twist
	::SetStretchBltMode(*pDC, HALFTONE);
	::SetBrushOrgEx(*pDC, 0, 0, NULL);

	// Draw Background Image 
	img.Draw(pDC->m_hDC, rect); // BackgroundType: Image
}

// Messages(Mappings)

BEGIN_MESSAGE_MAP(UIView, CFrameWnd)
END_MESSAGE_MAP()

// Messages(Actions)