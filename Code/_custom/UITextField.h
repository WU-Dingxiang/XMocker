
// UITextField.h 2016-1-1 15:42:37

#pragma once

#include "AppDelegate.h"
#include "atlimage.h"

class UITextField : public CEdit {
public:
	// Constructors
	UITextField(CWnd* pParentWnd, UINT uID);
	// Methods(Setter)
	void transparent(BOOL isTransparent=TRUE);
	void backgroundImage(LPCTSTR pszFileName);
	// Methods(Custom)
	void frame(int x, int y, int w, int h);
protected:
	// Attributes(Objects)
	BOOL m_transparent;
	CImage m_backgroundImage;
	CFont m_font;
	// Attributes(Pointers)
	// Methods(virtual)
	// Methods(invoke)
	// Messages(Actions)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};
