#pragma once


// ���������� ���� CCreatDlg

class CCreatDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCreatDlg)

public:
	CCreatDlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CCreatDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CREAT };
#endif

protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

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
