
// FTech_ScrollbarExDlg.h : header file
//

#pragma once
#include "ScrollbarEx.h"

// CFTech_ScrollbarExDlg dialog
class CFTech_ScrollbarExDlg : public CDialogEx
{
// Construction
public:
	CFTech_ScrollbarExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTECH_SCROLLBAREX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CScrollBarEx m_sbTest1;
	CScrollBarEx m_sbTest2;
	CScrollBarEx *m_psbTest3;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDestroy();
};
