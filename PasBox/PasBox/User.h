#pragma once
#include "PasBoxDlg.h"
#include "PasBox.h"
//class User : public CPasBoxDlg
class User : public CDialogEx
{
	int Length; //размер базы данных
	std::vector<CString> ArrCStringDB; //храним базу данных
	CString Pass; //пароль

public:
	CString Version; //= _T("0"); //версия программы
	CString S1;// = _T("limpopo10000");
	CString S2;// = _T("limpopo12000");
	CString S3;// = _T("limpopo12300");
	CString S4;// = _T("limpopo12340");
	CString S5;// = _T("limpopo12345");

	User();
	~User();

	int GetLength();

	CString GetName(int);
	CString GetLogin(int);
	CString GetPassword(int);
	CString GetComent(int);
	CString GetPass();

	void AddArrCStringDB(CString, CString, CString, CString);
	void CreatArrCStringDB(int, CString, CString, CString, CString);
	void Write();
	void ReadDB();
	void ReadLog();
	void WriteLog(CString, CString);

	char Decrypt(char);
	wchar_t Encrypt(wchar_t);
};

