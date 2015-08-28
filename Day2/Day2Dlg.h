
// Day2Dlg.h : header file
//

#pragma once

#define CONTROLSTOVARIALBES TRUE
#define VARIABLESTOCONTROLS FALSE


// CDay2Dlg dialog
class CDay2Dlg : public CDialogEx
{
// Construction
public:
	CDay2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DAY2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeProgtorun();
	// user's message
	CString m_strMessage;
	// Program to run
	CString m_strProgToRun;
private:
	BOOL m_bEnableMsg;
	BOOL m_bEnablePgm;
	BOOL m_bShowMsg;
	BOOL m_bShowPgm;
public:
	afx_msg void OnClickedExit();
	afx_msg void OnClickedShwmsg();
	afx_msg void OnClickedClrmsg();
	afx_msg void OnClickedDfltmsg();
	afx_msg void OnClickedCkenblmsg();
	afx_msg void OnClickedCkshwmsg();
};
