
// PasBoxDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CPasBoxDlg
class CPasBoxDlg : public CDialogEx
{
// Создание
public:
	CPasBoxDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboName();
	CComboBox ctrlName;
	CString Login;
	CString Password;
	CString Coment;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonCreat();
	CEdit ctrlLogin;
	CEdit ctrlPassword;
	CEdit ctrlComent;
	CString Name;
	afx_msg void OnProject();
	afx_msg void OnAdddb();
};