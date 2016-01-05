
// UIButton.cpp 2016-1-1 15:43:53

#include "UIButton.h"

// macros

// Constructors
UIButton::UIButton(CWnd* pParentWnd, UINT uID) {
	TRACE("%s\n", __FUNCTION__);

	if (!pParentWnd) {
		TRACE("pParentWnd can NOT be NULL.\n");
		return;
	}

	// Init with VALID pParentWnd
	this->Create(
		_T(""),
		WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		CRect(0, 0, 0, 0),
		pParentWnd,
		uID
		);

	// Clean Flags
	m_selected = FALSE;
	m_transparent = FALSE;
	m_font.CreatePointFont(80, _T("Î¢ÈíÑÅºÚ"));
	m_title = _T("");

	// Cursor Type
	LONG hCursor = (LONG)(AfxGetApp()->LoadStandardCursor(IDC_HAND));
	SetClassLongPtr(this->m_hWnd, GCLP_HCURSOR, hCursor);
}

// Methods(Custom)

// Methods(Custom) - Set Frame
void UIButton::frame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	this->MoveWindow(x, y, w, h);
}

// Methods(Custom) - Set Title
void UIButton::title(LPCTSTR text) {
	TRACE("%s\n", __FUNCTION__);

	m_title = text;
}

// Methods(Custom) - Set Transparent
void UIButton::transparent(BOOL isTransparent) {
	TRACE("%s\n", __FUNCTION__);

	m_transparent = isTransparent;
}

// Methods(Custom) - Set Transparent
void UIButton::select(BOOL isSelected) {
	TRACE("%s\n", __FUNCTION__);

	m_selected = isSelected;
}

// Methods(Custom) - Set Icon
void UIButton::icon(LPCTSTR pszFileName) {
	TRACE("%s\n", __FUNCTION__);

	m_iconImage.Load(pszFileName);
}

// Methods(Custom) - Set Background Image
void UIButton::backgroundImage(LPCTSTR pszFileName) {
	TRACE("%s\n", __FUNCTION__);

	m_backgroundImage.Load(pszFileName);
}

// Methods(virtual)
void UIButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) {
	//TRACE("%s\n", __FUNCTION__);

	switch(lpDrawItemStruct->itemAction) {
	case 1: 
		drawEntireItem(
			CDC::FromHandle(lpDrawItemStruct->hDC), 
			lpDrawItemStruct->rcItem
			); 
		break;
	default: 
		break;
	}
}

// Methods(virtual - invoke)
void UIButton::drawEntireItem(CDC *pDC, CRect rect) {
	TRACE("%s\n", __FUNCTION__);

	// Filter For Invalid Rect
	if (rect.Width()<1 || rect.Height()<1) {
		return;
	}

	// BackgroundType: Original
	if (!m_transparent) {
		__super::OnEraseBkgnd(pDC); 
	} 

	// Change Mode - Avoid Twist
	::SetStretchBltMode(*pDC, HALFTONE);
	::SetBrushOrgEx(*pDC, 0, 0, NULL);

	// Draw Background Image
	if (m_backgroundImage.IsDIBSection()) {
		m_backgroundImage.Draw(pDC->m_hDC, rect);
	}

	// Draw Icon Image
	int h = 16; int t = (rect.Height()-h)/2;
	if (m_iconImage.IsDIBSection()) {
		m_iconImage.Draw(pDC->m_hDC, CRect(t,t,t+h,t+h));
		rect.left += 25;
	}

	// Set pDC Params
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(m_selected?THEME_COLOR:RGB(0,0,0));
	pDC->SelectObject(&m_font);

	// Draw Text
	pDC->DrawText(m_title, rect, DT_SINGLELINE|DT_VCENTER|DT_CENTER);

}

// Messages(Mappings)

BEGIN_MESSAGE_MAP(UIButton, CButton)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// Messages(Actions)

BOOL UIButton::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	// return
	return TRUE;
}
