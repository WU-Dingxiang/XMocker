
// UIView.h 2015-12-31 15:25:30

#pragma once

#include "AppDelegate.h"
#include "atlimage.h"

class UIView : public CFrameWnd {
public:
	// Constructors
	UIView();
	// Methods(Setter)
	void transparent(BOOL isTransparent);
	// Methods(Custom)
	void frame(int x, int y, int w, int h);
protected:
	// Attributes(Objects)
	BOOL m_transparent;
	// Attributes(Pointers)
	// Methods(Custom)
	void drawImage(CImage &img/*atlimage.h 1573 without '&'*/, CRect rect, CDC* pDC);
	// Messages(Actions)
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};
