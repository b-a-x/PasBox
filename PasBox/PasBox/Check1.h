#pragma once
#include "afxwin.h"


// диалоговое окно Check1

class Check1 : public CDialogEx
{
	DECLARE_DYNAMIC(Check1)

public:
	Check1(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~Check1();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Check1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit ctrlOldPasswordEdit;
	CStatic ctrlOldPasswordTxt;
	CString Indef;
	CString OldPassword;
	CString NewPassword;
	CString Password;
	CString Wandering;
	CStatic ctrlIndefTxt;
	CEdit ctrlIndefEdit;
	CStatic ctrlNewPassword;
	CEdit ctrlNewPasswordEdit;
	CEdit ctrlPassword;
	CStatic ctrlPasswordTxt;
};
