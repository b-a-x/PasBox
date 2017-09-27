// Check.cpp: ���� ����������
//

#include "stdafx.h"
#include "PasBox.h"
#include "Check.h"
#include "afxdialogex.h"
#include "User.h"
#include "PasBoxDlg.h"
#include "CreatDlg.h"
#include "Check1.h"


// ���������� ���� Check

IMPLEMENT_DYNAMIC(Check, CDialogEx)

Check::Check(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Check, pParent)
	, Password(_T(""))
{
	IDD_DIALOG_Check1;
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

Check::~Check()
{
}

void Check::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Password, Password);
}


BEGIN_MESSAGE_MAP(Check, CDialogEx)
	ON_BN_CLICKED(IDOK, &Check::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Check::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_CheckPass, &Check::OnBnClickedButtonCheckpass)
END_MESSAGE_MAP()


// ����������� ��������� Check

BOOL Check::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	User user;
	
	if (user.GetLength() == 0)
	{
		Check1 check;
		INT_PTR nResponse = check.DoModal();
		if (nResponse == IDOK) {}
		else if (nResponse == IDCANCEL) 
		{
			CDialogEx::OnCancel();
		}
		else if (nResponse == -1)
		{
			TRACE(traceAppMsg, 0, "��������������. �� ������� ������� ���������� ����, ������� ������ ���������� ���������� ���������.\n");
			TRACE(traceAppMsg, 0, "��������������. ��� ������������� ��������� ���������� MFC ��� ����������� ���� ���������� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
		}
		
	}
	return TRUE;
}

void Check::OnBnClickedOk()
{
	User user;
	UpdateData(TRUE);
	if (user.GetPass() != Password || user.GetPass() == _T(""))
	{
		AfxMessageBox(_T("������ ������ �������"));
		return;
	}
	else if (user.ChekDiscNew != user.ChekDiscOld)
	{
		AfxMessageBox(_T("�������� ����� ��������"));
		return;
	}
	CPasBoxDlg dlg;
	CDialogEx::OnOK();
	dlg.DoModal();
}

void Check::OnBnClickedCancel()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialogEx::OnCancel();
}


void Check::OnBnClickedButtonCheckpass()
{
	User user;
	if (user.ChekDiscNew != user.ChekDiscOld)
	{
		AfxMessageBox(_T("�������� ����� ��������"));
		return;
	}
	CString q = _T("1");
	Check1 check;
	check.Wandering = q;
	INT_PTR nResponse = check.DoModal();
	if (nResponse == IDOK) {}
	else if (nResponse == IDCANCEL)
	{
		CDialogEx::OnCancel();
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "��������������. �� ������� ������� ���������� ����, ������� ������ ���������� ���������� ���������.\n");
		TRACE(traceAppMsg, 0, "��������������. ��� ������������� ��������� ���������� MFC ��� ����������� ���� ���������� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}
}
