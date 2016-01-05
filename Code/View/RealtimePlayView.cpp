
// RealtimePlayView.cpp 2016-1-3 17:53:07

// Includes

// Includes - rc

// Includes - Views
#include "RealtimePlayView.h"

// Includes - Customs

// macros

#define IDC_BUTTON_PAUSE			(51000)
#define IDC_BUTTON_PLAY				(51001)

// Constructors
RealtimePlayView::RealtimePlayView() {
	TRACE("%s\n", __FUNCTION__);

	// Open this line when you need to find where memory leaks.
	// _CrtSetBreakAlloc(memory_block_number);

	// Ctrl Image
	this->ctrlImage("..\\..\\Resource\\bmp\\ctrl_background.bmp");
	this->ctrlImageFrame(0,559-TITLE_H-NAVBAR_H,SCREEN_W-260,CTRL_H);

	// m_pauseBtn
	m_pauseBtn = new UIButton(this, IDC_BUTTON_PAUSE);
	m_pauseBtn->frame(0,559-TITLE_H-NAVBAR_H,32,30);
	m_pauseBtn->backgroundImage("..\\..\\Resource\\bmp\\ctrl_pause.bmp");
	m_pauseBtn->ShowWindow(SW_SHOW);

	// m_playBtn
	m_playBtn = new UIButton(this, IDC_BUTTON_PLAY);
	m_playBtn->frame(32,559-TITLE_H-NAVBAR_H,32,30);
	m_playBtn->backgroundImage("..\\..\\Resource\\bmp\\ctrl_play.bmp");
	m_playBtn->ShowWindow(SW_SHOW);
	
	// Waiting PictureEx
	m_waitingPictureEx = new CPictureEx(); m_waitingPictureEx->Create(
		NULL,
		WS_CHILD|WS_VISIBLE,
		CRect(300, 100, 100, 100), 
		this, 
		UINT(0)
		);
	if (m_waitingPictureEx->Load("..\\..\\Resource\\gif\\loading.gif"))
		m_waitingPictureEx->Draw();
}  


// Methods(Setter)

// Methods - Set CtrlImage
void RealtimePlayView::ctrlImage(LPCTSTR pszFileName, BOOL isPng) {
	TRACE("%s\n", __FUNCTION__);

	m_ctrlImage.Load(pszFileName);
}

// Methods - Set CtrlImageFrame
void RealtimePlayView::ctrlImageFrame(int x, int y, int w, int h) {
	TRACE("%s\n", __FUNCTION__);

	m_ctrlImageFrame.SetRect(x, y, x+w, y+h);
}

// Messages(Mappings)

BEGIN_MESSAGE_MAP(RealtimePlayView, UIView)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// Messages(Actions)

BOOL RealtimePlayView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	// Clean
	if (!m_transparent) {
		__super::OnEraseBkgnd(pDC);
	}

	// Draw Images]
	this->drawImage(m_ctrlImage, m_ctrlImageFrame, pDC);

	// return
	return TRUE;
}

void RealtimePlayView::OnDestroy() {
	TRACE("%s\n", __FUNCTION__);

	__super::OnDestroy();

	// Clean Pause Button
	if (m_pauseBtn) {
		delete m_pauseBtn;
		m_pauseBtn = NULL;
	}

	// Clean Play Button
	if (m_playBtn) {
		delete m_playBtn;
		m_playBtn = NULL;
	}

	// Clean Waiting Picture
	if (m_waitingPictureEx) {
		delete m_waitingPictureEx;
		m_waitingPictureEx = NULL;
	}
	
}

