
// RecordStrategyView.h 2016-1-3 21:35:32

#pragma once

#include "UIView.h"
#include "UIButton.h"
#include "UITextField.h"
#include "UILabel.h"
#include "afxcmn.h"

// macros

// constance

const static int RECORDSTRATEGY_CUTLINE_NUM = 2;

// class
class RecordStrategyView : public UIView {
public:
	// Constructors
	RecordStrategyView();
	// Methods(Setter)
protected:
	// Attributes(Objects)
	CImage cutline;
	CRect cutlineFrames[RECORDSTRATEGY_CUTLINE_NUM];
	// Attributes(Pointers)
	/************ Basic Config ******************************/
	UILabel *m_basicHeaderLabel;
	UILabel *m_saveModeLabel;
	UILabel *m_triggerModeLabel;
	/************ Record Config *****************************/
	UILabel *m_recordHeaderLabel;
	/************ TF Card Config *****************************/
	UILabel *m_tfCardHeaderLabel;
	UILabel *m_totalLabel;
	UITextField *m_totalTextField;
	UILabel *m_freeLabel;
	UITextField *m_freeTextField;
	UIButton *m_updateBtn;
	UIButton *m_formatBtn;
	// Methods(Custom)
	// Messages(Actions)
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnUpdateBtnClicked();
	afx_msg void OnFormatBtnClicked();
	// Messages(Mappings)
	DECLARE_MESSAGE_MAP()
};

