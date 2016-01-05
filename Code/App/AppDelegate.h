
// AppDelegate.h 2015-12-30 20:10:01

#pragma once

// macros(win32)

#if !defined(_WIN32_WINNT) && !defined(_CHICAGO_)
#define  _WIN32_WINNT   0x0502
#endif

// includes

#include <sdkddkver.h>
#include <afxwin.h>

// macros(custom) - Application

#define APP			(((AppDelegate*)AfxGetApp()))
#define WORKAREA	(APP->m_workAreaRect)

// macros(custom) - Size

#define SCREEN_WS	(GetSystemMetrics(SM_CXSCREEN))
#define SCREEN_HS	(GetSystemMetrics(SM_CYSCREEN))
#define SCREEN_W	(WORKAREA.Width())
#define SCREEN_H	(WORKAREA.Height())
#define TITLE_H		((int)(SCREEN_HS/(SCREEN_HS*0.0026+31.4)))
#define NAVBAR_H	((int)(SCREEN_HS/(SCREEN_HS*0.0016+18.4)))
#define CTRL_H		((int)(SCREEN_HS/(SCREEN_HS*0.0013+24.6)))
#define TREE_H		(SCREEN_H-TITLE_H-NAVBAR_H)

// macros(custom) - Color

#define THEME_COLOR	(RGB(71,92,251))

// AppDelegate

class AppDelegate : public CWinApp {
public:
	// Methods(virtual)
	virtual BOOL InitInstance();
	// Methods(static)
	// Attributes
	CRect m_workAreaRect;
};

