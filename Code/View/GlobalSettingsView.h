
// GlobalSettingsView.h 2016-1-3 21:35:32

#pragma once

#include "UIView.h"
#include "UIButton.h"
#include "UITextField.h"
#include "UILabel.h"

// macros

// constance

// class
class GlobalSettingsView : public UIView {
public:
	// Constructors
	GlobalSettingsView();
	// Methods(Setter)
protected:
	// Attributes(Objects)
	CImage cutline;
	CRect cutlineFrame;
	// Attributes(Pointers)
	UIButton *m_videoSavePathBtn;
	UIButton *m_imageSavePathBtn;
	UIButton *m_resetToDefaultBtn;
	UITextField *m_videoSavePathTextField;
	UITextField *m_imageSavePathTextField;
	UILabel *m_videoSavePathLabel;
	UILabel *m_imageSavePathLabel;
	UILabel *m_headerLabel;
	// Methods(Custom)
	void getPath(UITextField *textField);
	// Messages(Actions)
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnVideoSavePathBtnClicked();
	afx_msg void OnImageSavePathBtnClicked();
	afx_msg void OnResetToDefaultBtnClicked();
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

