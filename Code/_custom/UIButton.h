
// UIButton.h 2016-1-1 15:42:37

#pragma once

#include "AppDelegate.h"
#include "atlimage.h"

class UIButton : public CButton {
public:
	// Constructors
	UIButton(CWnd* pParentWnd, UINT uID);
	// Methods(Setter)
	void select(BOOL isSelected);
	void transparent(BOOL isTransparent);
	void title(LPCTSTR text);
	void backgroundImage(LPCTSTR pszFileName);
	void icon(LPCTSTR pszFileName);
	// Methods(Custom)
	void frame(int x, int y, int w, int h);
protected:
	// Attributes(Objects)
	BOOL m_selected;
	BOOL m_transparent;
	CFont m_font;
	CImage m_backgroundImage;
	CImage m_iconImage;
	// Attributes(Pointers)
	LPCTSTR m_title;
	// Methods(virtual)
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	// Methods(invoke)
	void drawEntireItem(CDC *pDC, CRect rect);
	// Messages(Actions)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};
