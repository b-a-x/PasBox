#pragma once


// ���������� ���� Check

class Check : public CDialogEx
{
	DECLARE_DYNAMIC(Check)

public:
	Check(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~Check();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Check };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString Password;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonCheckpass();
};
