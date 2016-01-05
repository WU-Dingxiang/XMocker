
// AppDelegate.cpp 2015-12-30 20:09:57

#include "AppDelegate.h"
#include "LaurnchView.h"

AppDelegate theApp;

BOOL AppDelegate::InitInstance() {
	TRACE("%s\n", __FUNCTION__);

	// Init Workarea Rect
	SystemParametersInfo(SPI_GETWORKAREA, 0, &m_workAreaRect, 0);

	// Show LaurnchView
	m_pMainWnd = new LaurnchView();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	// return
	return TRUE;
}