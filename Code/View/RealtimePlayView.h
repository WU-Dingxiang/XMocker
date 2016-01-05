
// RealtimePlayView.h 2016-1-3 17:55:30

#pragma once

#include "UIView.h"
#include "PictureEx.h"
#include "UIButton.h"

// macros

// constance

// class
class RealtimePlayView : public UIView {
public:
	// Constructors
	RealtimePlayView();
	// Methods(Setter)
	void ctrlImage(LPCTSTR pszFileName, BOOL isPng = FALSE);
	void ctrlImageFrame(int x, int y, int w, int h);
protected:
	// Attributes(Objects)
	CImage m_ctrlImage;
	CRect m_ctrlImageFrame;
	// Attributes(Pointers)
	UIButton *m_pauseBtn;
	UIButton *m_playBtn;
	CPictureEx *m_waitingPictureEx;
	// Methods(Custom)
	// Messages(Actions)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPauseBtnClicked();
	afx_msg void OnPlayBtnClicked();
	afx_msg void OnDestroy();
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

