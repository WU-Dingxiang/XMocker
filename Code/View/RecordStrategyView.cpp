
// RecordStrategyView.cpp 2016-1-3 21:35:23

// Includes

// Includes - rc

// Includes - Views
#include "RecordStrategyView.h"

// Includes - Customs

// Includes - Other

// macros

/************ Basic Config ******************************/
#define IDC_LABEL_HEAHER_BASIC		(55400)
#define IDC_LABEL_SAVEMODE			(55401)
#define IDC_LABEL_TRIGGERMODE		(55402)
/************ Record Config *****************************/
#define IDC_LABEL_HEAHER_RECORD		(55403)
/************ TF Card Config *****************************/
#define IDC_LABEL_HEAHER_TFCARD		(55404)
#define IDC_LABEL_TOTAL				(55405)
#define IDC_TEXTFIELD_TOTAL			(55406)
#define IDC_LABEL_FREE				(55407)
#define IDC_TEXTFIELD_FREE			(55408)
#define IDC_BUTTON_UPDATE			(55409)
#define IDC_BUTTON_FORMAT			(55410)

// constance

// Constructors
RecordStrategyView::RecordStrategyView() {
	TRACE("%s\n", __FUNCTION__);

	// Open this line when you need to find where memory leaks.
	// _CrtSetBreakAlloc(memory_block_number);

	const static int gh = 4;
	const static int gv = 11;
	const static int l = (SCREEN_W-260-(100+gh+353+gh+96))/2;

	// Basic - Header Label
	m_basicHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_BASIC);
	m_basicHeaderLabel->title(_T("基本配置"));	
	m_basicHeaderLabel->fontStyleBold();
	m_basicHeaderLabel->frame(26, 15, 100, 19);
	m_basicHeaderLabel->textAlign(DT_LEFT);
	m_basicHeaderLabel->ShowWindow(SW_SHOW);

	// Basic - Save Mode Label
	m_saveModeLabel = new UILabel(this, IDC_LABEL_SAVEMODE);
	m_saveModeLabel->title(_T("存储策略"));
	m_saveModeLabel->frame(l, 48, 100, 19);
	m_saveModeLabel->textAlign(DT_RIGHT);
	m_saveModeLabel->ShowWindow(SW_SHOW);

	// Basic - Trigger Mode - Label
	m_triggerModeLabel = new UILabel(this, IDC_LABEL_TRIGGERMODE);
	m_triggerModeLabel->title(_T("触发方式"));
	m_triggerModeLabel->frame(l, 48+(19+gv)*1, 100, 19);
	m_triggerModeLabel->textAlign(DT_RIGHT);
	m_triggerModeLabel->ShowWindow(SW_SHOW);

	// cutline
	cutline.Load(_T("..\\..\\Resource\\bmp\\cutline.bmp"));
	cutlineFrames[0].SetRect(18, 48+(19+gv)*2, SCREEN_W-260-18, 48+(19+gv)*2+2);

	// Record - Header Label
	m_recordHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_RECORD);
	m_recordHeaderLabel->title(_T("录像配置"));	
	m_recordHeaderLabel->fontStyleBold();
	m_recordHeaderLabel->frame(26, 48+(19+gv)*2+2+15, 100, 19);
	m_recordHeaderLabel->textAlign(DT_LEFT);
	m_recordHeaderLabel->ShowWindow(SW_SHOW);

	// cutline
	cutlineFrames[1].SetRect(18, 48*2+(19+gv)*2+2, SCREEN_W-260-18, 48*2+(19+gv)*2+2*2);

	// TF Card - Header - Label
	m_tfCardHeaderLabel = new UILabel(this, IDC_LABEL_HEAHER_TFCARD);
	m_tfCardHeaderLabel->title(_T("TF 卡设置"));	
	m_tfCardHeaderLabel->fontStyleBold();
	m_tfCardHeaderLabel->frame(26, 48*2+(19+gv)*2+2*2+15, 100, 19);
	m_tfCardHeaderLabel->textAlign(DT_LEFT);
	m_tfCardHeaderLabel->ShowWindow(SW_SHOW);

	// TF Card - Total - Label
	m_totalLabel = new UILabel(this, IDC_LABEL_TOTAL);
	m_totalLabel->title(_T("总容量"));
	m_totalLabel->frame(l, 48*2+(19+gv)*2+2*2+48, 100, 19);
	m_totalLabel->textAlign(DT_RIGHT);
	m_totalLabel->ShowWindow(SW_SHOW);

	// TF Card - Total - TextField
	m_totalTextField = new UITextField(this, IDC_TEXTFIELD_TOTAL);
	m_totalTextField->frame(l+100+gh, 48*2+(19+gv)*2+2*2+48, 353, 19);
	m_totalTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_totalTextField->ShowWindow(SW_SHOW);

	// TF Card - Free - Label
	m_freeLabel = new UILabel(this, IDC_LABEL_FREE);
	m_freeLabel->title(_T("剩余容量"));
	m_freeLabel->frame(l, 48*2+(19+gv)*3+2*2+48, 100, 19);
	m_freeLabel->textAlign(DT_RIGHT);
	m_freeLabel->ShowWindow(SW_SHOW);

	// TF Card - Free - TextField
	m_freeTextField = new UITextField(this, IDC_TEXTFIELD_FREE);
	m_freeTextField->frame(l+100+gh, 48*2+(19+gv)*3+2*2+48, 353, 19);
	m_freeTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_freeTextField->ShowWindow(SW_SHOW);

	// TF Card - Update - Button
	m_updateBtn = new UIButton(this, IDC_BUTTON_UPDATE);
	m_updateBtn->frame(l+100+gh+353+gh, 48*2+(19+gv)*3+2*2+48, 20, 19);
	m_updateBtn->title(_T("···"));
	m_updateBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx20.bmp"));
	m_updateBtn->ShowWindow(SW_SHOW);

	// TF Card - Format - Button
	m_formatBtn = new UIButton(this, IDC_BUTTON_FORMAT);
	m_formatBtn->frame(l+100+gh+353+gh+20+gh, 48*2+(19+gv)*3+2*2+48, 96, 19);
	m_formatBtn->title(_T("格式化"));
	m_formatBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_formatBtn->ShowWindow(SW_SHOW);
}  

// Methods(Custom)

// Messages(Mappings)

BEGIN_MESSAGE_MAP(RecordStrategyView, UIView)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnUpdateBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_FORMAT, OnFormatBtnClicked)
END_MESSAGE_MAP()

// Messages(Actions)

void RecordStrategyView::OnUpdateBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

void RecordStrategyView::OnFormatBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

}

BOOL RecordStrategyView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	drawImage(cutline, cutlineFrames[0], pDC);
	drawImage(cutline, cutlineFrames[1], pDC);

	// return
	return TRUE;
}

void RecordStrategyView::OnDestroy() {
	TRACE("%s\n", __FUNCTION__);

	__super::OnDestroy();

	/************ Basic Config ******************************/
	if (m_basicHeaderLabel) {
		delete m_basicHeaderLabel;
		m_basicHeaderLabel = NULL;
	}
	if (m_saveModeLabel) {
		delete m_saveModeLabel;
		m_saveModeLabel = NULL;
	}
	if (m_triggerModeLabel) {
		delete m_triggerModeLabel;
		m_triggerModeLabel = NULL;
	}

	/************ Record Config *****************************/
	if (m_recordHeaderLabel) {
		delete m_recordHeaderLabel;
		m_recordHeaderLabel = NULL;
	}

	/************ TF Card Config *****************************/
	if (m_tfCardHeaderLabel) {
		delete m_tfCardHeaderLabel;
		m_tfCardHeaderLabel = NULL;
	}
	if (m_totalLabel) {
		delete m_totalLabel;
		m_totalLabel = NULL;
	}
	if (m_totalTextField) {
		delete m_totalTextField;
		m_totalTextField = NULL;
	}
	if (m_freeLabel) {
		delete m_freeLabel;
		m_freeLabel = NULL;
	}
	if (m_freeTextField) {
		delete m_freeTextField;
		m_freeTextField = NULL;
	}
	if (m_updateBtn) {
		delete m_updateBtn;
		m_updateBtn = NULL;
	}
	if (m_formatBtn) {
		delete m_formatBtn;
		m_formatBtn = NULL;
	}

}

