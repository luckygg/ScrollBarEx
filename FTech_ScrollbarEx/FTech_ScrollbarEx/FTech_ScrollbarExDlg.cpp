
// FTech_ScrollbarExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_ScrollbarEx.h"
#include "FTech_ScrollbarExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_ScrollbarExDlg dialog




CFTech_ScrollbarExDlg::CFTech_ScrollbarExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_ScrollbarExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_psbTest3 = NULL;
}

void CFTech_ScrollbarExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_sbTest1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_sbTest2);
}

BEGIN_MESSAGE_MAP(CFTech_ScrollbarExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CFTech_ScrollbarExDlg message handlers

BOOL CFTech_ScrollbarExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_psbTest3 = new CScrollBarEx();
	m_psbTest3->CreateContol(this,true,CRect(10,100,200,20),2020);
	m_psbTest3->SetScrollRange(0,100);
	SetDlgItemInt(IDC_LbInfo3,0);

	m_sbTest1.InitControl(this);
	m_sbTest1.SetScrollRange(0,100);
	m_sbTest1.SetScrollPos(50);
	SetDlgItemInt(IDC_LbInfo1,50);
	m_sbTest1.SetColorChannel(255,255,0,0);
	m_sbTest1.SetColorArrow(255,0,255,0,255,0,255,0);
	m_sbTest1.SetEnable(false);

	m_sbTest2.InitControl(this,false);
	m_sbTest2.SetScrollRange(0,100);
	m_sbTest2.SetScrollPos(0);
	SetDlgItemInt(IDC_LbInfo2,0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_ScrollbarExDlg::OnPaint()
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
HCURSOR CFTech_ScrollbarExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFTech_ScrollbarExDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar->m_hWnd == m_sbTest1.m_hWnd)
	{
		int pos = m_sbTest1.GetScrollPos();
		SetDlgItemInt(IDC_LbInfo1,pos);
	}

	if (pScrollBar->m_hWnd == m_psbTest3->m_hWnd)
	{
		int pos = m_psbTest3->GetScrollPos();
		SetDlgItemInt(IDC_LbInfo3,pos);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CFTech_ScrollbarExDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar->m_hWnd == m_sbTest2.m_hWnd)
	{
		int pos = m_sbTest2.GetScrollPos();
		SetDlgItemInt(IDC_LbInfo2,pos);
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CFTech_ScrollbarExDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_psbTest3 != NULL)
	{
		m_psbTest3->DestroyWindow();
		delete m_psbTest3;
		m_psbTest3 = NULL;
	}
}
