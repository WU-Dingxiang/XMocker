
// UITreeView.h 2015-12-31 17:34:40

#pragma once

#include "AppDelegate.h"
#include "atlimage.h"
#include "afxcmn.h"

class UITreeView : public CTreeCtrl {
public:
	// Constructors
	UITreeView(CWnd* pParentWnd);
	// Methods(Setter)
	void transparent(BOOL isTransparent);
	void backgroundImage(LPCTSTR pszFileName);
	// Methods(Custom)
	void frame(int x, int y, int w, int h);
	// Attributes(Objects)
protected:
	// Attributes(Objects)
	BOOL m_transparent;
	CImage m_backgroundImage;
	// Messages(Actions)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

