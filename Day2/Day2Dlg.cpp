
// Day2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Day2.h"
#include "Day2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
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
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDay2Dlg dialog



CDay2Dlg::CDay2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDay2Dlg::IDD, pParent)
	, m_strMessage(_T(""))
	, m_strProgToRun(_T(""))
	, m_bEnableMsg(FALSE)
	, m_bEnablePgm(FALSE)
	, m_bShowMsg(FALSE)
	, m_bShowPgm(FALSE)
	, fInitialized(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDay2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MSG, m_strMessage);
	DDX_CBString(pDX, IDC_PROGTORUN, m_strProgToRun);
	DDX_Check(pDX, IDC_CKENBLMSG, m_bEnableMsg);
	DDX_Check(pDX, IDC_CKENBLPGM, m_bEnablePgm);
	DDX_Check(pDX, IDC_CKSHWMSG, m_bShowMsg);
	DDX_Check(pDX, IDC_CKSHWPGM, m_bShowPgm);
	DDX_Control(pDX, IDC_EDIT2, c_edit2);
}

BEGIN_MESSAGE_MAP(CDay2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CDay2Dlg::OnClickedExit)
	ON_BN_CLICKED(IDC_SHWMSG, &CDay2Dlg::OnClickedShwmsg)
	ON_BN_CLICKED(IDC_CLRMSG, &CDay2Dlg::OnClickedClrmsg)
	ON_BN_CLICKED(IDC_DFLTMSG, &CDay2Dlg::OnClickedDfltmsg)
	ON_BN_CLICKED(IDC_CKENBLMSG, &CDay2Dlg::OnClickedCkenblmsg)
	ON_BN_CLICKED(IDC_CKSHWMSG, &CDay2Dlg::OnClickedCkshwmsg)
END_MESSAGE_MAP()


// CDay2Dlg message handlers

BOOL CDay2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	//My code starts here
	m_strMessage = _T("Puneţi un mesaj aici");
	m_bEnableMsg = TRUE;
	m_bEnablePgm = TRUE;
	m_bShowMsg = TRUE;
	m_bShowPgm = TRUE;
	c_edit2.SetWindowTextW(_T("Control variable behind"));

	UpdateData(FALSE);

	fInitialized = TRUE;
	//My code ends here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDay2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDay2Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDay2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDay2Dlg::OnClickedExit()
{
	OnOK();
}


void CDay2Dlg::OnClickedShwmsg()
{
	UpdateData(TRUE);
	MessageBox(m_strMessage);
}


void CDay2Dlg::OnClickedClrmsg()
{
	m_strMessage = "";
	UpdateData(FALSE);
}


void CDay2Dlg::OnClickedDfltmsg()
{
	m_strMessage = _T("Place a message here");
}


void CDay2Dlg::OnClickedCkenblmsg()
{
	///////////////////////
	// MY CODE STARTS HERE
	///////////////////////
	
	// Get the current values from the screen
	UpdateData(TRUE);
	
	// Is the Enable Message Action check box checked?
	if (m_bEnableMsg == TRUE)
	{
		// Yes, so enable all controls that have anything
		// to do with showing the user message
		GetDlgItem(IDC_MSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_SHWMSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_DFLTMSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_CLRMSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATICMSG)->EnableWindow(TRUE);
	}
	else
	{
		// No, so disable all controls that have anything
		// to do with showing the user message
		GetDlgItem(IDC_MSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_SHWMSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_DFLTMSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_CLRMSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATICMSG)->EnableWindow(FALSE);
	}
	//TTT http://www.flounder.com/getdlgitem.htm - avoid GetDlgItem - always have control variables
	// variabila fInitialized se foloseste pentru a evita accesul la controale care nu exista inca
	// vezi in link-ul de mai sus partea cu WM_SIZE
	if (fInitialized)
	{
		m_bEnableMsg ? c_edit2.EnableWindow(TRUE) : c_edit2.EnableWindow(FALSE);
	}
	
	///////////////////////
	// MY CODE ENDS HERE
	///////////////////////
}


void CDay2Dlg::OnClickedCkshwmsg()
{
	
	///////////////////////
	// MY CODE STARTS HERE
	///////////////////////
	
	// Get the current values from the screen
	UpdateData(CONTROLSTOVARIALBES);
	
	// Is the Show Message Action check box checked?
	if (m_bShowMsg == TRUE)
	{
	// Yes, so show all controls that have anything
	// to do with showing the user message
	GetDlgItem(IDC_MSG)->ShowWindow(TRUE);
	GetDlgItem(IDC_SHWMSG)->ShowWindow(TRUE);
	GetDlgItem(IDC_DFLTMSG)->ShowWindow(TRUE);
	GetDlgItem(IDC_CLRMSG)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATICMSG)->ShowWindow(TRUE);
	}
	else
	{
	// No, so hide all controls that have anything
	// to do with showing the user message
	GetDlgItem(IDC_MSG)->ShowWindow(FALSE);
	GetDlgItem(IDC_SHWMSG)->ShowWindow(FALSE);
	GetDlgItem(IDC_DFLTMSG)->ShowWindow(FALSE);
	GetDlgItem(IDC_CLRMSG)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATICMSG)->ShowWindow(FALSE);
	}
}
