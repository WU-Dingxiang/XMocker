
// UILabel.cpp 2016-1-1 15:43:53

#include "UILabel.h"

// macros

// Constructors
UILabel::UILabel(CWnd* pParentWnd, UINT uID) {
	TRACE("%s\n", __FUNCTION__);

	if (!pParentWnd) {
		TRACE("pParentWnd can NOT be NULL.\n");
		return;
	}

	// Init with VALID pParentWnd
	this->Create(
		_T(""),
		WS_CHILD|WS_VISIBLE,
		CRect(0, 0, 0, 0),
		pParentWnd,
		uID
		);

	// Clean Flags
	m_textAlign = DT_CENTER;
	m_transparent = FALSE;
	m_font.CreatePointFont(80, _T("Î¢ÈíÑÅºÚ"));
	m_title = _T("");
}

// Methods(Custom)

// Methods(Custom) - Set Frame
void UILabel::textAlign(UINT textAlign) {
	TRACE("%s\n", __FUNCTION__);

	m_textAlign = textAlign;
}

// Methods(Custom) - Set Frame
void UILabel::frame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	this->MoveWindow(x, y, w, h);
}

// Methods(Custom) - Set Title
void UILabel::title(LPCTSTR text) {
	TRACE("%s\n", __FUNCTION__);

	m_title = text;
}

// Methods(Custom) - Set Font Bold
void UILabel::fontStyleBold(BOOL isBold) {
	TRACE("%s\n", __FUNCTION__);
	
	LOGFONT logFont; m_font.GetLogFont(&logFont);
	logFont.lfWeight = isBold?FW_BOLD:FW_NORMAL;
	m_font.DeleteObject(); // re-create is not allowed without delete 
	m_font.CreateFontIndirect(&logFont);
}

// Methods(Custom) - Set Transparent
void UILabel::transparent(BOOL isTransparent) {
	TRACE("%s\n", __FUNCTION__);

	m_transparent = isTransparent;
}

// Methods(Custom) - Set Background Image
void UILabel::backgroundImage(LPCTSTR pszFileName) {
	TRACE("%s\n", __FUNCTION__);

	m_backgroundImage.Load(pszFileName);
}

// Methods(virtual)

// Methods(virtual - invoke)

// Messages(Mappings)

BEGIN_MESSAGE_MAP(UILabel, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// Messages(Actions)

void UILabel::OnPaint() {
	TRACE("%s\n", __FUNCTION__);

	// Filter For Invalid Rect
	CRect rect; GetClientRect(&rect);
	if (rect.Width()<1 || rect.Height()<1) {
		return;
	}

	// BackgroundType: Original
	CPaintDC dc(this);
	if (!m_transparent) {
		__super::OnEraseBkgnd(&dc); 
	} 

	// Change Mode - Avoid Twist
	::SetStretchBltMode(dc, HALFTONE);
	::SetBrushOrgEx(dc, 0, 0, NULL);

	// Draw Background Image
	if (m_backgroundImage.IsDIBSection()) {
		m_backgroundImage.Draw(dc.m_hDC, rect);
	}

	// Set pDC Params
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,0,0));
	dc.SelectObject(&m_font);

	// Draw Text
	dc.DrawText(m_title, rect, DT_SINGLELINE|DT_VCENTER|m_textAlign);
}

BOOL UILabel::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	// return
	return TRUE;
}
