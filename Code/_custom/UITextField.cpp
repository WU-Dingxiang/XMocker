
// UITextField.cpp 2016-1-1 15:43:53

#include "UITextField.h"

// macros

// Constructors
UITextField::UITextField(CWnd* pParentWnd, UINT uID) {
	TRACE("%s\n", __FUNCTION__);

	if (!pParentWnd) {
		TRACE("pParentWnd can NOT be NULL.\n");
		return;
	}

	// Init with VALID pParentWnd
	this->Create(
		WS_CHILD | WS_VISIBLE,
		CRect(0, 0, 0, 0),
		pParentWnd,
		uID
		);

	// Clean Flags
	m_transparent = FALSE;

	// Init Font
	m_font.CreatePointFont(80, _T("Î¢ÈíÑÅºÚ"));
	this->SetFont(&m_font);
}

// Methods(Custom)

// Methods(Custom) - Set Frame
void UITextField::frame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	this->MoveWindow(x, y, w, h);
}

// Methods(Custom) - Set Transparent
void UITextField::transparent(BOOL isTransparent) {
	TRACE("%s\n", __FUNCTION__);

	m_transparent = isTransparent;
}

// Methods(Custom) - Set Background Image
void UITextField::backgroundImage(LPCTSTR pszFileName) {
	TRACE("%s\n", __FUNCTION__);

	m_backgroundImage.Load(pszFileName);
}

// Methods(virtual)

// Methods(virtual - invoke)

// Messages(Mappings)

BEGIN_MESSAGE_MAP(UITextField, CEdit)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()

// Messages(Actions)

HBRUSH UITextField::CtlColor(CDC* pDC, UINT nCtlColor) {
	TRACE("%s\n", __FUNCTION__);

	HBRUSH retval = (HBRUSH)::GetStockObject(NULL_BRUSH);

	// Filter For Invalid Rect
	CRect rect; GetClientRect(&rect);
	if (rect.Width()<1 || rect.Height()<1) {
		return retval;
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

	// Set pDC Params
	pDC->SetBkMode(TRANSPARENT);
	return retval;
}

BOOL UITextField::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	// return
	return TRUE;
}
