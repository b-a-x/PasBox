// CreatDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "PasBox.h"
#include "CreatDlg.h"
#include "afxdialogex.h"
#include "PasBoxDlg.h"
#include "User.h"
#include "Check.h"

// диалоговое окно CCreatDlg

IMPLEMENT_DYNAMIC(CCreatDlg, CDialogEx)

CCreatDlg::CCreatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CREAT, pParent)
	, Name(_T(""))
	, Wandering(_T(""))
	, Login(_T(""))
	, Password(_T(""))
	, Coment(_T(""))
{

}

CCreatDlg::~CCreatDlg()
{
}

void CCreatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Name, Name);
	DDX_Text(pDX, IDC_EDIT_Login, Login);
	DDX_Text(pDX, IDC_EDIT_Password, Password);
	DDX_Text(pDX, IDC_EDIT5, Coment);
}


BEGIN_MESSAGE_MAP(CCreatDlg, CDialogEx)
	
	ON_BN_CLICKED(IDOK, &CCreatDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений CCreatDlg


void CCreatDlg::OnBnClickedOk()
{
	if (Wandering == _T("1"))
	{
		User add;
		UpdateData(TRUE);
		if (Name == _T(""))
		{
			AfxMessageBox(_T("¬ведите название."));
			return;
		}
		add.AddArrCStringDB(Name, Login, Password, Coment);
		CDialogEx::OnOK();
	}
	else if (Wandering == _T("0"))
	{
		User creat;
		UpdateData(TRUE);
		creat.CreatArrCStringDB(Namber, Name, Login, Password, Coment);
		CDialogEx::OnOK();
	}
}