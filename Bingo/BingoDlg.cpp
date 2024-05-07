// BingoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bingo.h"
#include "BingoDlg.h"
#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CBingoDlg dialog




CBingoDlg::CBingoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBingoDlg::IDD, pParent)
	, m_Automatic(true)
	, m_Delay(15)
	, m_nColorDrawn(0)
	, m_nColorPending(0)
	, m_nJumbleIdx(0)
	, m_nTimerID(0)
	, m_Sound(true)
	, m_TimerDirty(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	for (unsigned char i=1;i<=75;i++) {
		aJumble[i]=i;
	};
	aDrawn[1] = &tbBoard01;
	aDrawn[2] = &tbBoard02;
	aDrawn[3] = &tbBoard03;
	aDrawn[4] = &tbBoard04;
	aDrawn[5] = &tbBoard05;
	aDrawn[6] = &tbBoard06;
	aDrawn[7] = &tbBoard07;
	aDrawn[8] = &tbBoard08;
	aDrawn[9] = &tbBoard09;
	aDrawn[10] = &tbBoard10;
	aDrawn[11] = &tbBoard11;
	aDrawn[12] = &tbBoard12;
	aDrawn[13] = &tbBoard13;
	aDrawn[14] = &tbBoard14;
	aDrawn[15] = &tbBoard15;
	aDrawn[16] = &tbBoard16;
	aDrawn[17] = &tbBoard17;
	aDrawn[18] = &tbBoard18;
	aDrawn[19] = &tbBoard19;
	aDrawn[20] = &tbBoard20;
	aDrawn[21] = &tbBoard21;
	aDrawn[22] = &tbBoard22;
	aDrawn[23] = &tbBoard23;
	aDrawn[24] = &tbBoard24;
	aDrawn[25] = &tbBoard25;
	aDrawn[26] = &tbBoard26;
	aDrawn[27] = &tbBoard27;
	aDrawn[28] = &tbBoard28;
	aDrawn[29] = &tbBoard29;
	aDrawn[30] = &tbBoard30;
	aDrawn[31] = &tbBoard31;
	aDrawn[32] = &tbBoard32;
	aDrawn[33] = &tbBoard33;
	aDrawn[34] = &tbBoard34;
	aDrawn[35] = &tbBoard35;
	aDrawn[36] = &tbBoard36;
	aDrawn[37] = &tbBoard37;
	aDrawn[38] = &tbBoard38;
	aDrawn[39] = &tbBoard39;
	aDrawn[40] = &tbBoard40;
	aDrawn[41] = &tbBoard41;
	aDrawn[42] = &tbBoard42;
	aDrawn[43] = &tbBoard43;
	aDrawn[44] = &tbBoard44;
	aDrawn[45] = &tbBoard45;
	aDrawn[46] = &tbBoard46;
	aDrawn[47] = &tbBoard47;
	aDrawn[48] = &tbBoard48;
	aDrawn[49] = &tbBoard49;
	aDrawn[50] = &tbBoard50;
	aDrawn[51] = &tbBoard51;
	aDrawn[52] = &tbBoard52;
	aDrawn[53] = &tbBoard53;
	aDrawn[54] = &tbBoard54;
	aDrawn[55] = &tbBoard55;
	aDrawn[56] = &tbBoard56;
	aDrawn[57] = &tbBoard57;
	aDrawn[58] = &tbBoard58;
	aDrawn[59] = &tbBoard59;
	aDrawn[60] = &tbBoard60;
	aDrawn[61] = &tbBoard61;
	aDrawn[62] = &tbBoard62;
	aDrawn[63] = &tbBoard63;
	aDrawn[64] = &tbBoard64;
	aDrawn[65] = &tbBoard65;
	aDrawn[66] = &tbBoard66;
	aDrawn[67] = &tbBoard67;
	aDrawn[68] = &tbBoard68;
	aDrawn[69] = &tbBoard69;
	aDrawn[70] = &tbBoard70;
	aDrawn[71] = &tbBoard71;
	aDrawn[72] = &tbBoard72;
	aDrawn[73] = &tbBoard73;
	aDrawn[74] = &tbBoard74;
	aDrawn[75] = &tbBoard75;
}

void CBingoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BOARD01, tbBoard01);
	DDX_Control(pDX, IDC_BOARD02, tbBoard02);
	DDX_Control(pDX, IDC_BOARD03, tbBoard03);
	DDX_Control(pDX, IDC_BOARD04, tbBoard04);
	DDX_Control(pDX, IDC_BOARD05, tbBoard05);
	DDX_Control(pDX, IDC_BOARD06, tbBoard06);
	DDX_Control(pDX, IDC_BOARD07, tbBoard07);
	DDX_Control(pDX, IDC_BOARD08, tbBoard08);
	DDX_Control(pDX, IDC_BOARD09, tbBoard09);
	DDX_Control(pDX, IDC_BOARD10, tbBoard10);
	DDX_Control(pDX, IDC_BOARD11, tbBoard11);
	DDX_Control(pDX, IDC_BOARD12, tbBoard12);
	DDX_Control(pDX, IDC_BOARD13, tbBoard13);
	DDX_Control(pDX, IDC_BOARD14, tbBoard14);
	DDX_Control(pDX, IDC_BOARD15, tbBoard15);
	DDX_Control(pDX, IDC_BOARD16, tbBoard16);
	DDX_Control(pDX, IDC_BOARD17, tbBoard17);
	DDX_Control(pDX, IDC_BOARD18, tbBoard18);
	DDX_Control(pDX, IDC_BOARD19, tbBoard19);
	DDX_Control(pDX, IDC_BOARD20, tbBoard20);
	DDX_Control(pDX, IDC_BOARD21, tbBoard21);
	DDX_Control(pDX, IDC_BOARD22, tbBoard22);
	DDX_Control(pDX, IDC_BOARD23, tbBoard23);
	DDX_Control(pDX, IDC_BOARD24, tbBoard24);
	DDX_Control(pDX, IDC_BOARD25, tbBoard25);
	DDX_Control(pDX, IDC_BOARD26, tbBoard26);
	DDX_Control(pDX, IDC_BOARD27, tbBoard27);
	DDX_Control(pDX, IDC_BOARD28, tbBoard28);
	DDX_Control(pDX, IDC_BOARD29, tbBoard29);
	DDX_Control(pDX, IDC_BOARD30, tbBoard30);
	DDX_Control(pDX, IDC_BOARD31, tbBoard31);
	DDX_Control(pDX, IDC_BOARD32, tbBoard32);
	DDX_Control(pDX, IDC_BOARD33, tbBoard33);
	DDX_Control(pDX, IDC_BOARD34, tbBoard34);
	DDX_Control(pDX, IDC_BOARD35, tbBoard35);
	DDX_Control(pDX, IDC_BOARD36, tbBoard36);
	DDX_Control(pDX, IDC_BOARD37, tbBoard37);
	DDX_Control(pDX, IDC_BOARD38, tbBoard38);
	DDX_Control(pDX, IDC_BOARD39, tbBoard39);
	DDX_Control(pDX, IDC_BOARD40, tbBoard40);
	DDX_Control(pDX, IDC_BOARD41, tbBoard41);
	DDX_Control(pDX, IDC_BOARD42, tbBoard42);
	DDX_Control(pDX, IDC_BOARD43, tbBoard43);
	DDX_Control(pDX, IDC_BOARD44, tbBoard44);
	DDX_Control(pDX, IDC_BOARD45, tbBoard45);
	DDX_Control(pDX, IDC_BOARD46, tbBoard46);
	DDX_Control(pDX, IDC_BOARD47, tbBoard47);
	DDX_Control(pDX, IDC_BOARD48, tbBoard48);
	DDX_Control(pDX, IDC_BOARD49, tbBoard49);
	DDX_Control(pDX, IDC_BOARD50, tbBoard50);
	DDX_Control(pDX, IDC_BOARD51, tbBoard51);
	DDX_Control(pDX, IDC_BOARD52, tbBoard52);
	DDX_Control(pDX, IDC_BOARD53, tbBoard53);
	DDX_Control(pDX, IDC_BOARD54, tbBoard54);
	DDX_Control(pDX, IDC_BOARD55, tbBoard55);
	DDX_Control(pDX, IDC_BOARD56, tbBoard56);
	DDX_Control(pDX, IDC_BOARD57, tbBoard57);
	DDX_Control(pDX, IDC_BOARD58, tbBoard58);
	DDX_Control(pDX, IDC_BOARD59, tbBoard59);
	DDX_Control(pDX, IDC_BOARD60, tbBoard60);
	DDX_Control(pDX, IDC_BOARD61, tbBoard61);
	DDX_Control(pDX, IDC_BOARD62, tbBoard62);
	DDX_Control(pDX, IDC_BOARD63, tbBoard63);
	DDX_Control(pDX, IDC_BOARD64, tbBoard64);
	DDX_Control(pDX, IDC_BOARD65, tbBoard65);
	DDX_Control(pDX, IDC_BOARD66, tbBoard66);
	DDX_Control(pDX, IDC_BOARD67, tbBoard67);
	DDX_Control(pDX, IDC_BOARD68, tbBoard68);
	DDX_Control(pDX, IDC_BOARD69, tbBoard69);
	DDX_Control(pDX, IDC_BOARD70, tbBoard70);
	DDX_Control(pDX, IDC_BOARD71, tbBoard71);
	DDX_Control(pDX, IDC_BOARD72, tbBoard72);
	DDX_Control(pDX, IDC_BOARD73, tbBoard73);
	DDX_Control(pDX, IDC_BOARD74, tbBoard74);
	DDX_Control(pDX, IDC_BOARD75, tbBoard75);
	DDX_Control(pDX, IDC_DRAW, tbDraw);
	DDX_Control(pDX, IDOK, pbIDOK);
}

BEGIN_MESSAGE_MAP(CBingoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CBingoDlg::OnBnClickedButton1)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDOK, &CBingoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_pbClear, &CBingoDlg::OnBnClickedpbclear)
	ON_BN_CLICKED(IDC_pbStart, &CBingoDlg::OnBnClickedpbstart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_pbSlower, &CBingoDlg::OnBnClickedpbslower)
	ON_BN_CLICKED(IDC_pbFaster, &CBingoDlg::OnBnClickedpbfaster)
	ON_BN_CLICKED(IDC_pbMute, &CBingoDlg::OnBnClickedpbmute)
	ON_BN_CLICKED(IDC_pbConfig, &CBingoDlg::OnBnClickedpbconfig)
END_MESSAGE_MAP()


// CBingoDlg message handlers

BOOL CBingoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	OnBnClickedpbclear();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBingoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBingoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBingoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBingoDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	static bool bUsed = 0;
	bUsed = !bUsed;
	if (bUsed)
		tbBoard01.put_ForeColor(m_nColorDrawn);
	else
		tbBoard01.put_ForeColor(m_nColorPending);
}

int CBingoDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_Automatic = TRUE;
	m_Delay = 15;
	//m_Delay = 1;	// for testing only!
	m_nColorDrawn = RGB(255,0,0);
	m_nColorPending = RGB(169,169,169);
	TossBalls();

	return 0;
}

void CBingoDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (m_Automatic && m_nTimerID!=0) {
		KillTimer(m_nTimerID);
		m_nTimerID = 0;
		GetDlgItem(IDC_pbStart)->EnableWindow(true);
		GetDlgItem(IDC_pbClear)->EnableWindow(true);
		GetDlgItem(IDC_pbStart)->SetFocus();
	} else {
		//OnOK();	// This will be commented out later
		GetDlgItem(IDC_pbStart)->SetFocus();
	}
}

void CBingoDlg::OnBnClickedpbclear()
{
	// TODO: Add your control notification handler code here
	for (unsigned char i=1;i<=75;i++) {
		aDrawn[i]->put_ForeColor(m_nColorPending);
		aJumble[i] = i;
	}
	tbDraw.put_Text(_T(""));
	TossBalls();
	GetDlgItem(IDC_pbStart)->SetFocus();
}

void CBingoDlg::OnBnClickedpbstart()
{
	// TODO: Add your control notification handler code here
	if (m_Automatic) {
		//NextDraw();	// temporary call for testing
		// Start a timer
		m_nTimerID = SetTimer(1, m_Delay * 1000, NULL);
		if (m_nTimerID==0) {
			if (MessageBox(CString("System resources cannot support automatic draws at this time. Switch to manual draw?"),CString("Bingo"),MB_YESNO)==IDYES) {
				m_Automatic = false;
				NextDraw();
			}
			return;
		}
		NextDraw();	// draw an immediate number rather than waiting for first timeout
		GetDlgItem(IDC_pbStart)->EnableWindow(false);
		GetDlgItem(IDC_pbClear)->EnableWindow(false);
		pbIDOK.SetFocus();
	} else {
		NextDraw();
		pbIDOK.EnableWindow(FALSE);
	}
	return;
}

// 'Draws' the next number and handles it's display
void CBingoDlg::NextDraw(void)
{
	if (m_nJumbleIdx > 75) return;
	CString tmpDraw;
	unsigned char tmpNumber = aJumble[m_nJumbleIdx];
	if (tmpNumber < 16) {
		tmpDraw = "B-";
	} else if (tmpNumber < 31) {
		tmpDraw = "I-";
	} else if (tmpNumber < 46) {
		tmpDraw = "N-";
	} else if (tmpNumber < 61) {
		tmpDraw = "G-";
	} else {
		tmpDraw = "O-";
	}
	tmpDraw.AppendFormat(_T("%d"),tmpNumber);
	tbDraw.put_Text(tmpDraw);
	if (m_Sound)
		MessageBeep(-1);
	aDrawn[tmpNumber]->put_ForeColor(m_nColorDrawn);
	// Increment Jumble index ONLY after finished with display issues
	m_nJumbleIdx++;
	return;
}

int CBingoDlg::TossBalls(void)
{
	unsigned char tmp,j;
	srand(GetTickCount());
	for (unsigned char i=1;i<=100;i++) {
		j = rand() % 75 + 1;
		tmp = aJumble[1];
		aJumble[1] = aJumble[j];
		aJumble[j] = tmp;
	}
	m_nJumbleIdx = 1;
	return 0;
}

void CBingoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == m_nTimerID) {
		NextDraw();
		if (m_TimerDirty) {
			KillTimer(m_nTimerID);
			m_nTimerID = SetTimer(1, m_Delay * 1000, NULL);
			m_TimerDirty = false;
		}
		if (m_nJumbleIdx>75)
			OnBnClickedOk();
	}

	CDialog::OnTimer(nIDEvent);
}

void CBingoDlg::OnBnClickedpbslower()
{
	// TODO: Add your control notification handler code here
	m_Delay++;
	if (m_nTimerID!=0) m_TimerDirty=true;
}

void CBingoDlg::OnBnClickedpbfaster()
{
	// TODO: Add your control notification handler code here
	if (m_Delay>1) {
		m_Delay--;
		if (m_nTimerID!=0) m_TimerDirty=true;
	}
}

void CBingoDlg::OnBnClickedpbmute()
{
	// TODO: Add your control notification handler code here
	m_Sound = !m_Sound;
	if (m_nTimerID!=0)
		pbIDOK.SetFocus();
	else
		GetDlgItem(IDC_pbStart)->SetFocus();
}

void CBingoDlg::OnBnClickedpbconfig()
{
	CConfigDlg CfgDlg;
	CfgDlg.m_bAuto = !m_Automatic;
	CfgDlg.m_nDelay = m_Delay;
	CfgDlg.DoModal();
	m_Automatic = !CfgDlg.m_bAuto;
	m_Delay = CfgDlg.m_nDelay;
	// TODO: Add your control notification handler code here
}
