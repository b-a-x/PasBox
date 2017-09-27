#pragma once


// диалоговое окно CCreatDlg

class CCreatDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCreatDlg)

public:
	CCreatDlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CCreatDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CREAT };
#endif

protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString Wandering;
	CString Name;
	CString Login;
	CString Password;
	CString Coment;
	int Namber;
};
