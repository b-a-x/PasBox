
// PasBoxDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� CPasBoxDlg
class CPasBoxDlg : public CDialogEx
{
// ��������
public:
	CPasBoxDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
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