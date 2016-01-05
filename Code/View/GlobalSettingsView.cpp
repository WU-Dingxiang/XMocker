
// GlobalSettingsView.cpp 2016-1-3 21:35:23

// Includes

// Includes - rc

// Includes - Views
#include "GlobalSettingsView.h"

// Includes - Customs

// Includes - Other
#include "Shlobj.h"

// macros

#define IDC_LABEL_HEAHER				(55100)

#define IDC_LABEL_VIDEOSAVEPATH			(55101)
#define IDC_TEXTFIELD_VIDEOSAVEPATH		(55102)
#define IDC_BUTTON_VIDEOSAVEPATH		(55103)

#define IDC_LABEL_IMAGESAVEPATH			(55104)
#define IDC_TEXTFIELD_IMAGESAVEPATH		(55105)
#define IDC_BUTTON_IMAGESAVEPATH		(55106)

#define IDC_BUTTON_RESETTODEFAULT		(55107)

// constance

const static char *DEFAULT_VIDEO_SAVE_PATH = _T("D:\\Ô®Í¨¼à»¤\\video");
const static char *DEFAULT_IMAGE_SAVE_PATH = _T("D:\\Ô®Í¨¼à»¤\\image");

// Constructors
GlobalSettingsView::GlobalSettingsView() {
	TRACE("%s\n", __FUNCTION__);

	// Open this line when you need to find where memory leaks.
	// _CrtSetBreakAlloc(memory_block_number);

	const static int gh = 4;
	const static int gv = 11;
	const static int l = (SCREEN_W-260-(100+gh+353+gh+20))/2;

	// Header Label
	m_headerLabel = new UILabel(this, IDC_LABEL_HEAHER);
	m_headerLabel->title(_T("´æ´¢ÉèÖÃ"));	
	m_headerLabel->fontStyleBold();
	m_headerLabel->frame(26, 15, 100, 19);
	m_headerLabel->textAlign(DT_LEFT);
	m_headerLabel->ShowWindow(SW_SHOW);

	// Video Save Path - Label
	m_videoSavePathLabel = new UILabel(this, IDC_LABEL_VIDEOSAVEPATH);
	m_videoSavePathLabel->title(_T("Â¼Ïñ´æ´¢Â·¾¶"));	
	m_videoSavePathLabel->frame(l, 48, 100, 19);
	m_videoSavePathLabel->textAlign(DT_RIGHT);
	m_videoSavePathLabel->ShowWindow(SW_SHOW);

	// Video Save Path - TextField
	m_videoSavePathTextField = new UITextField(this, IDC_TEXTFIELD_VIDEOSAVEPATH); 
	m_videoSavePathTextField->SetReadOnly();
	m_videoSavePathTextField->frame(l+100+gh, 48, 353, 19);
	m_videoSavePathTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_videoSavePathTextField->SetWindowText(DEFAULT_VIDEO_SAVE_PATH);
	m_videoSavePathTextField->ShowWindow(SW_SHOW);

	// Video Save Path - Button
	m_videoSavePathBtn = new UIButton(this, IDC_BUTTON_VIDEOSAVEPATH);
	m_videoSavePathBtn->frame(l+100+gh+353+gh, 48, 20, 19);
	m_videoSavePathBtn->title(_T("¡¤¡¤¡¤"));
	m_videoSavePathBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx20.bmp"));
	m_videoSavePathBtn->ShowWindow(SW_SHOW);

	// Image Save Path - Label
	m_imageSavePathLabel = new UILabel(this, IDC_LABEL_IMAGESAVEPATH);
	m_imageSavePathLabel->title(_T("½ØÍ¼´æ´¢Â·¾¶"));	
	m_imageSavePathLabel->frame(l, 48+19+gv, 100, 19);
	m_imageSavePathLabel->textAlign(DT_RIGHT);
	m_imageSavePathLabel->ShowWindow(SW_SHOW);

	// Image Save Path Edit
	m_imageSavePathTextField = new UITextField(this, IDC_TEXTFIELD_IMAGESAVEPATH); 
	m_imageSavePathTextField->SetReadOnly();
	m_imageSavePathTextField->frame(l+100+gh, 48+19+gv, 353, 19);
	m_imageSavePathTextField->backgroundImage(_T("..\\..\\Resource\\bmp\\textfield_background.bmp"));
	m_imageSavePathTextField->SetWindowText(DEFAULT_IMAGE_SAVE_PATH);
	m_imageSavePathTextField->ShowWindow(SW_SHOW);

	// Image Save Path - Button
	m_imageSavePathBtn = new UIButton(this, IDC_BUTTON_IMAGESAVEPATH);
	m_imageSavePathBtn->frame(l+100+gh+353+gh, 48+19+gv, 20, 19);
	m_imageSavePathBtn->title(_T("¡¤¡¤¡¤"));
	m_imageSavePathBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx20.bmp"));
	m_imageSavePathBtn->ShowWindow(SW_SHOW);

	// Reset to Default Save Paths
	m_resetToDefaultBtn = new UIButton(this, IDC_BUTTON_RESETTODEFAULT);
	m_resetToDefaultBtn->frame(l+100+gh, 48+19+gv+19+gv, 96, 18);
	m_resetToDefaultBtn->title(_T("»Ö¸´Ä¬ÈÏÂ·¾¶"));
	m_resetToDefaultBtn->backgroundImage(_T("..\\..\\Resource\\bmp\\button_backgroundx96.bmp"));
	m_resetToDefaultBtn->ShowWindow(SW_SHOW);

	// cutline
	cutline.Load(_T("..\\..\\Resource\\bmp\\cutline.bmp"));
	cutlineFrame.SetRect(18, 48+(19+gv)*3, SCREEN_W-260-18, 48+(19+gv)*3+2);

}  

// Methods(Custom)

void GlobalSettingsView::getPath(UITextField *textField) {
	TRACE("%s\n", __FUNCTION__);

	char szPath[MAX_PATH]; ZeroMemory(szPath, sizeof(szPath));

	CString str; BROWSEINFO bi;   
	bi.hwndOwner = m_hWnd;   
	bi.pidlRoot = NULL;   
	bi.pszDisplayName = szPath;   
	bi.lpszTitle = _T("Ö¸¶¨Â¼Ïñ´æ´¢Ä¿Â¼"); 
	bi.ulFlags = 0;   
	bi.lpfn = NULL;   
	bi.lParam = 0;   
	bi.iImage = 0;   

	LPITEMIDLIST lp = SHBrowseForFolder(&bi); 

	if(lp && SHGetPathFromIDList(lp, szPath)) {
		textField->SetWindowText(szPath);
		TRACE("szPath = %s\n",  szPath);
		return;
	}

	AfxMessageBox(_T("ÎÞÐ§µÄÄ¿Â¼£¬ÇëÖØÐÂÑ¡Ôñ"));
}

// Messages(Mappings)

BEGIN_MESSAGE_MAP(GlobalSettingsView, UIView)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON_VIDEOSAVEPATH, OnVideoSavePathBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_IMAGESAVEPATH, OnImageSavePathBtnClicked)
	ON_BN_CLICKED(IDC_BUTTON_RESETTODEFAULT, OnResetToDefaultBtnClicked)
END_MESSAGE_MAP()

// Messages(Actions)

void GlobalSettingsView::OnVideoSavePathBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

	this->getPath(m_videoSavePathTextField);
}

void GlobalSettingsView::OnImageSavePathBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

	this->getPath(m_imageSavePathTextField);
}

void GlobalSettingsView::OnResetToDefaultBtnClicked() {
	TRACE("%s\n", __FUNCTION__);

	m_imageSavePathTextField->SetWindowText(DEFAULT_IMAGE_SAVE_PATH);
	m_videoSavePathTextField->SetWindowText(DEFAULT_VIDEO_SAVE_PATH);
}

BOOL GlobalSettingsView::OnEraseBkgnd(CDC* pDC) {
	TRACE("%s\n", __FUNCTION__);

	drawImage(cutline, cutlineFrame, pDC);

	// return
	return TRUE;
}

void GlobalSettingsView::OnDestroy() {
	TRACE("%s\n", __FUNCTION__);

	__super::OnDestroy();

	// Clean Video Static
	if (m_headerLabel) {
		delete m_headerLabel;
		m_headerLabel = NULL;
	}

	// Clean Video Static
	if (m_videoSavePathLabel) {
		delete m_videoSavePathLabel;
		m_videoSavePathLabel = NULL;
	}

	// Clean Video Edit
	if (m_videoSavePathTextField) {
		delete m_videoSavePathTextField;
		m_videoSavePathTextField = NULL;
	}

	// Clean Video Button
	if (m_videoSavePathBtn) {
		delete m_videoSavePathBtn;
		m_videoSavePathBtn = NULL;
	}

	// Clean Image Static
	if (m_imageSavePathLabel) {
		delete m_imageSavePathLabel;
		m_imageSavePathLabel = NULL;
	}

	// Clean Image Edit
	if (m_imageSavePathTextField) {
		delete m_imageSavePathTextField;
		m_imageSavePathTextField = NULL;
	}

	// Clean Image Button
	if (m_imageSavePathBtn) {
		delete m_imageSavePathBtn;
		m_imageSavePathBtn = NULL;
	}

	// Clean Reset Button
	if (m_resetToDefaultBtn) {
		delete m_resetToDefaultBtn;
		m_resetToDefaultBtn = NULL;
	}
}

