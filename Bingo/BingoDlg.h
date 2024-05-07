// BingoDlg.h : header file
//

#pragma once
#include "board01.h"
#include "afxwin.h"


// CBingoDlg dialog
class CBingoDlg : public CDialog
{
// Construction
public:
	CBingoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BINGO_DIALOG };

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
	CBoard01 tbBoard01;
	afx_msg void OnBnClickedButton1();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CBoard01 tbBoard02;
	CBoard01* aDrawn[76];
	CBoard01 tbBoard03;
	CBoard01 tbBoard04;
	CBoard01 tbBoard05;
	CBoard01 tbBoard06;
	CBoard01 tbBoard07;
	CBoard01 tbBoard08;
	CBoard01 tbBoard09;
	CBoard01 tbBoard10;
	CBoard01 tbBoard11;
	CBoard01 tbBoard12;
	CBoard01 tbBoard13;
	CBoard01 tbBoard14;
	CBoard01 tbBoard15;
	CBoard01 tbBoard16;
	CBoard01 tbBoard17;
	CBoard01 tbBoard18;
	CBoard01 tbBoard19;
	CBoard01 tbBoard20;
	CBoard01 tbBoard21;
	CBoard01 tbBoard22;
	CBoard01 tbBoard23;
	CBoard01 tbBoard24;
	CBoard01 tbBoard25;
	CBoard01 tbBoard26;
	CBoard01 tbBoard27;
	CBoard01 tbBoard28;
	CBoard01 tbBoard29;
	CBoard01 tbBoard30;
	CBoard01 tbBoard31;
	CBoard01 tbBoard32;
	CBoard01 tbBoard33;
	CBoard01 tbBoard34;
	CBoard01 tbBoard35;
	CBoard01 tbBoard36;
	CBoard01 tbBoard37;
	CBoard01 tbBoard38;
	CBoard01 tbBoard39;
	CBoard01 tbBoard40;
	CBoard01 tbBoard41;
	CBoard01 tbBoard42;
	CBoard01 tbBoard43;
	CBoard01 tbBoard44;
	CBoard01 tbBoard45;
	CBoard01 tbBoard46;
	CBoard01 tbBoard47;
	CBoard01 tbBoard48;
	CBoard01 tbBoard49;
	CBoard01 tbBoard50;
	CBoard01 tbBoard51;
	CBoard01 tbBoard52;
	CBoard01 tbBoard53;
	CBoard01 tbBoard54;
	CBoard01 tbBoard55;
	CBoard01 tbBoard56;
	CBoard01 tbBoard57;
	CBoard01 tbBoard58;
	CBoard01 tbBoard59;
	CBoard01 tbBoard60;
	CBoard01 tbBoard61;
	CBoard01 tbBoard62;
	CBoard01 tbBoard63;
	CBoard01 tbBoard64;
	CBoard01 tbBoard65;
	CBoard01 tbBoard66;
	CBoard01 tbBoard67;
	CBoard01 tbBoard68;
	CBoard01 tbBoard69;
	CBoard01 tbBoard70;
	CBoard01 tbBoard71;
	CBoard01 tbBoard72;
	CBoard01 tbBoard73;
	CBoard01 tbBoard74;
	CBoard01 tbBoard75;
private:
	unsigned char aJumble[76];
public:
	CBoard01 tbDraw;
	afx_msg void OnBnClickedOk();
	bool m_Automatic;
	unsigned char m_Delay;
	afx_msg void OnBnClickedpbclear();
	long m_nColorDrawn;
	long m_nColorPending;
	unsigned char m_nJumbleIdx;
	afx_msg void OnBnClickedpbstart();
	// 'Draws' the next number and handles it's display
	void NextDraw(void);
	int TossBalls(void);
	CButton pbIDOK;
	UINT_PTR m_nTimerID;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	bool m_Sound;
	// Defaults to false - set true when the interval is changed during an active sraw sequence
	bool m_TimerDirty;
	afx_msg void OnBnClickedpbslower();
	afx_msg void OnBnClickedpbfaster();
	afx_msg void OnBnClickedpbmute();
	afx_msg void OnBnClickedpbconfig();
};
