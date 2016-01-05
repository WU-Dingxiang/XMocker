
// UILabel.h 2016-1-1 15:42:37

#pragma once

#include "AppDelegate.h"
#include "atlimage.h"

class UILabel : public CStatic {
public:
	// Constructors
	UILabel(CWnd* pParentWnd, UINT uID);
	// Methods(Setter)
	void transparent(BOOL isTransparent);
	void title(LPCTSTR text);
	void backgroundImage(LPCTSTR pszFileName);
	void textAlign(UINT textAlign);
	// Methods(Custom)
	void fontStyleBold(BOOL isBold=TRUE);
	void frame(int x, int y, int w, int h);
protected:
	// Attributes(Objects)
	BOOL m_transparent;
	CFont m_font;
	CImage m_backgroundImage;
	UINT m_textAlign;
	// Attributes(Pointers)
	LPCTSTR m_title;
	// Methods(virtual)
	// Methods(invoke)
	void drawEntireItem(CDC *pDC, CRect rect);
	// Messages(Actions)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};
