
// PasBoxDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "PasBox.h"
#include "PasBoxDlg.h"
#include "afxdialogex.h"
#include "User.h"
#include "CreatDlg.h"
#include "Check.h"
#include "Check1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CPasBoxDlg



CPasBoxDlg::CPasBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PASBOX_DIALOG, pParent)
	, Login(_T(""))
	, Password(_T(""))
	, Coment(_T(""))
	, Name(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPasBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Name, ctrlName);
	DDX_Text(pDX, IDC_EDIT_Login, Login);
	DDX_Text(pDX, IDC_EDIT_Password, Password);
	DDX_Text(pDX, IDC_EDIT_Coment, Coment);
	DDX_Control(pDX, IDC_EDIT_Login, ctrlLogin);
	DDX_Control(pDX, IDC_EDIT_Password, ctrlPassword);
	DDX_Control(pDX, IDC_EDIT_Coment, ctrlComent);
	DDX_CBString(pDX, IDC_COMBO_Name, Name);
}

BEGIN_MESSAGE_MAP(CPasBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_Name, &CPasBoxDlg::OnCbnSelchangeComboName)
	ON_BN_CLICKED(IDC_BUTTON_Add, &CPasBoxDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_Creat, &CPasBoxDlg::OnBnClickedButtonCreat)
	ON_COMMAND(ID_Project, &CPasBoxDlg::OnProject)
	ON_COMMAND(ID_AddDB, &CPasBoxDlg::OnAdddb)
END_MESSAGE_MAP()


// ����������� ��������� CPasBoxDlg

BOOL CPasBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	//ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	//ASSERT(IDM_ABOUTBOX < 0xF000);
	/*
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
	*/
	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	User user;
	for (int i = 0; i < user.GetLength(); i++)
	{
		ctrlName.AddString(user.GetName(i));
	}
	
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CPasBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CPasBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CPasBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPasBoxDlg::OnCbnSelchangeComboName()
{
	User user;
	int i = ctrlName.GetCurSel();
	
	Login = user.GetLogin(i);
	Password = user.GetPassword(i);
	Coment = user.GetComent(i);
	UpdateData(FALSE);
}
void CPasBoxDlg::OnBnClickedButtonAdd()
{
	CString q = _T("1");
	CCreatDlg dlg;
	dlg.Wandering = q;
	dlg.DoModal();
	User user;

	CString s;
	for (int i = 0; i < user.GetLength(); i++)
	{
		ctrlName.GetLBText(i, s);
		if (s == _T(""))
		{
			ctrlName.InsertString(i, user.GetName(i));
			ctrlName.SetCurSel(i);
			Login = user.GetLogin(i);
			Password = user.GetPassword(i);
			Coment = user.GetComent(i);
			UpdateData(FALSE);
			break;
		}
	}
	
}

void CPasBoxDlg::OnBnClickedButtonCreat()
{
	CString q = _T("0");
	CCreatDlg dlg;
	UpdateData(TRUE);
	if (Name == _T(""))
	{
		AfxMessageBox(_T("����� ������� ��������."));
		return;
	}
	dlg.Name = Name;
	dlg.Login = Login;
	dlg.Password = Password;
	dlg.Coment = Coment;
	dlg.Wandering = q;
	dlg.Namber = ctrlName.GetCurSel();
	dlg.DoModal();

	User creat;
	for (int i = 0; i < creat.GetLength(); i++)
	{
		if (i == dlg.Namber)
		{
			ctrlName.DeleteString(i);
			ctrlName.InsertString(i, creat.GetName(i));
			ctrlName.SetCurSel(i);
			Login = creat.GetLogin(i);
			Password = creat.GetPassword(i);
			Coment = creat.GetComent(i);
			UpdateData(FALSE);
			break;
		}
	}
}


void CPasBoxDlg::OnProject()
{	
	CAboutDlg AboutDlg;
	AboutDlg.DoModal();
}


void CPasBoxDlg::OnAdddb()
{
	Check1 add;
	add.Wandering = _T("2");
	add.DoModal();
	User user;
}
