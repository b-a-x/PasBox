// Check1.cpp: файл реализации
//

#include "stdafx.h"
#include "PasBox.h"
#include "Check1.h"
#include "afxdialogex.h"
#include "User.h"


// диалоговое окно Check1

IMPLEMENT_DYNAMIC(Check1, CDialogEx)

Check1::Check1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Check1, pParent)
	, Indef(_T(""))
	, OldPassword(_T(""))
	, NewPassword(_T(""))
	, Password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

Check1::~Check1()
{
}

void Check1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_OldPassword, ctrlOldPasswordEdit);
	DDX_Control(pDX, IDC_OldPassword, ctrlOldPasswordTxt);
	DDX_Text(pDX, IDC_EDIT_Indef, Indef);
	DDX_Text(pDX, IDC_EDIT_OldPassword, OldPassword);
	DDX_Text(pDX, IDC_EDIT_NewPassword, NewPassword);
	DDX_Text(pDX, IDC_EDIT_NewPassword1, Password);
	DDX_Control(pDX, IDC_Indef, ctrlIndefTxt);
	DDX_Control(pDX, IDC_EDIT_Indef, ctrlIndefEdit);
	DDX_Control(pDX, IDC_NewPassword, ctrlNewPassword);
	DDX_Control(pDX, IDC_EDIT_NewPassword, ctrlNewPasswordEdit);
	DDX_Control(pDX, IDC_EDIT_NewPassword1, ctrlPassword);
	DDX_Control(pDX, IDC_PasswordTxt, ctrlPasswordTxt);
}


BEGIN_MESSAGE_MAP(Check1, CDialogEx)
	ON_BN_CLICKED(IDOK, &Check1::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений Check1
BOOL Check1::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	User user;
	if (user.GetLength() == 0)
	{
		ctrlOldPasswordEdit.ShowWindow(SW_HIDE);
		ctrlOldPasswordTxt.ShowWindow(SW_HIDE);
	}
	else if (Wandering == _T("1"))
	{
		ctrlIndefTxt.ShowWindow(SW_HIDE);
		ctrlIndefEdit.ShowWindow(SW_HIDE);
	}
	else if (Wandering == _T("2"))
	{
		ctrlOldPasswordEdit.ShowWindow(SW_HIDE);
		ctrlOldPasswordTxt.ShowWindow(SW_HIDE);
		ctrlNewPassword.ShowWindow(SW_HIDE);
		ctrlNewPasswordEdit.ShowWindow(SW_HIDE);
		ctrlPassword.ShowWindow(SW_HIDE);
		ctrlPasswordTxt.ShowWindow(SW_HIDE);
	}
	return TRUE;
}

void Check1::OnBnClickedOk()
{
	UpdateData(TRUE);
	User user;
	
	if (user.GetLength() == 0)
	{
		if (Indef == _T(""))
		{
			AfxMessageBox(_T("Введите Индентификатор"));
			return;
		}
		else if (Indef != user.S0 + user.Version && Indef != user.S1 + user.Version && Indef != user.S2 + user.Version &&
			Indef != user.S3 + user.Version && Indef != user.S4 + user.Version &&
			Indef != user.S5 + user.Version)
		{
			AfxMessageBox(_T("Не Верный Индентификатор"));
			return;
		}
		else if (NewPassword == _T(""))
		{
			AfxMessageBox(_T("Введите Пароль"));
			return;
		}
		else if (Password == _T(""))
		{
			AfxMessageBox(_T("Повторите Пароль"));
			return;
		}
		else if (Password != NewPassword)
		{
			AfxMessageBox(_T("Пароль не совпадает"));
			return;
		}
		else
		{
			user.WriteLog(Indef, Password);
			AfxMessageBox(_T("Регистрация прошла успешно"));
		}
	}
	else if (Wandering == _T("1"))
	{
		if (OldPassword == _T(""))
		{
			AfxMessageBox(_T("Введите Старый Пароль"));
			return;
		}
		else if (OldPassword != user.GetPass())
		{
			AfxMessageBox(_T("Пароль не совпадает со старым"));
			return;
		}
		else if (NewPassword == _T(""))
		{
			AfxMessageBox(_T("Введите новый пароль"));
			return;
		}
		else if (Password == _T(""))
		{
			AfxMessageBox(_T("Повторите Пароль"));
			return;
		}
		else if (Password != NewPassword)
		{
			AfxMessageBox(_T("Новый пароль не совпадает"));
			return;
		}
		else
		{
			user.WriteLog(Indef, Password);
			AfxMessageBox(_T("Пароль успешно изменен"));
		}
	}
	else if (Wandering == _T("2"))
	{
		if (Indef == _T(""))
		{
			AfxMessageBox(_T("Введите Индентификатор"));
			return;
		}
		else if (Indef != user.S0 + user.Version && Indef != user.S1 + user.Version && Indef != user.S2 + user.Version &&
			Indef != user.S3 + user.Version && Indef != user.S4 + user.Version &&
			Indef != user.S5 + user.Version)
		{
			AfxMessageBox(_T("Не Верный Индентификатор"));
			return;
		}
		else
		{
			user.WriteLog(Indef, Password);
			AfxMessageBox(_T("База данных увеличина.\nПерезапустите программу."));
		}
	}
	CDialogEx::OnOK();
}
