#include "stdafx.h"
#include "User.h"
#include "PasBox.h"
#include "PasBoxDlg.h"
#include "afxdialogex.h"
#include "CreatDlg.h"
#include "Check.h"

User::User()
{
	Version = _T("10"); //версия программы
	S0 = _T("triel");
	S1 = _T("limpopo10000");
	S2 = _T("limpopo12000");
	S3 = _T("limpopo12300");
	S4 = _T("limpopo12340");
	S5 = _T("limpopo12345");
	//Читаем серийник диска
	InfoDisc();
	//подключаемся к файлу log.txt и формируем Length
	ReadLog();
	//подключаемся к файлу db.txt и формируем вектор ArrCStringDB
	ReadDB();
}

User::~User()
{
	ArrCStringDB.clear();
}
int User::GetLength()
{
	return Length;
}
CString User::GetName(int i)
{
	i += i * 3;
	return ArrCStringDB[i];
}
CString User::GetLogin(int i)
{
	i += i * 3 + 1;
	return ArrCStringDB[i];
}
CString User::GetPassword(int i)
{
	i += i * 3 + 2;
	return ArrCStringDB[i];
}
CString User::GetComent(int i)
{
	i += i * 3 + 3;
	return ArrCStringDB[i];
}
CString User::GetPass()
{
	return Pass;
}
void User::AddArrCStringDB(CString AddName, CString AddLogin, CString AddPassword, CString AddComent)
{
	for (int i = 0; i <= ArrCStringDB.size()-4; i += 4)
	{
		if (ArrCStringDB[i] == _T(""))
		{
			ArrCStringDB[i] = AddName;
			ArrCStringDB[i + 1] = AddLogin;
			ArrCStringDB[i + 2] = AddPassword;
			ArrCStringDB[i + 3] = AddComent;
			break;
		}
		if (ArrCStringDB.size()-4 == i)
		{
			CString s;
			s.Format(_T("%d"), Length);
			AfxFormatString1(s, IDS_STRING103, s);
			AfxMessageBox(s);
		}
	}
	Write();
}
void User::CreatArrCStringDB(int CreatNamber, CString CreatName, CString CreatLogin, CString CreatPassword, CString CreatComent)
{
	CreatNamber = CreatNamber * 4;
	for (int i = 0; i < ArrCStringDB.size() - 4; i += 4)
	{
		if (i == CreatNamber)
		{
			ArrCStringDB[i] = CreatName;
			ArrCStringDB[i + 1] = CreatLogin;
			ArrCStringDB[i + 2] = CreatPassword;
			ArrCStringDB[i + 3] = CreatComent;
			break;
		}
	}
	Write();
}
wchar_t User::Encrypt(wchar_t s)
{
	s += 1;
	return s;
}
char User::Decrypt(char s)
{
	s -= 1;
	return s;
}
void User::Write()
{
	char ArrDB[100000] = { 0 };
	int q = 0;
	for (size_t i = 0; i < ArrCStringDB.size(); i++)
	{
		if (ArrCStringDB[i] != _T(""))
		{
			CString s = ArrCStringDB[i];
			for (size_t j = 0; j <= s.GetLength() - 1; j++)
			{
				ArrDB[q] = Encrypt(s.GetAt(j));
				if (s.GetLength() - 1 == j)
				{
					ArrDB[q + 1] = Encrypt(';');
					q++;
				}
				q++;
			}
		}
		else
		{
			ArrDB[q] = Encrypt(';');
			q++;
		}
	}
	TCHAR* DBName = _T("db.txt");
	CFile DB;
	CFileException DBException;
	if (DB.Open(DBName, CFile::modeWrite, &DBException))
	{
		DB.Write(ArrDB, sizeof(ArrDB));
	}
	DB.Close();
}
void User::ReadDB()
{
	char ArrDB[100000] = { 0 };
	TCHAR* DBName = _T("db.txt");
	CFile DB;
	UINT    nActual = 0;
	CFileException DBException;
	if (DB.Open(DBName, CFile::modeRead, &DBException))
	{	
		nActual = DB.Read(ArrDB, sizeof(ArrDB));
	}
	else
	{
		DB.Open(DBName, CFile::modeCreate, &DBException);
	}

	int i = 0;
	CString pr;
	while (i < nActual)
	{
		ArrDB[i] = Decrypt(ArrDB[i]);
		if (ArrDB[i] == '\n' || ArrDB[i] == '\r')
		{
			i++;
			continue;
		}
		if (ArrDB[i] == ';')
		{
			ArrCStringDB.push_back(pr);
			pr.Empty();
			i++;
			continue;
		}
		pr += ArrDB[i];
		i++;
	}
	int size = ArrCStringDB.size();
	if (size < Length*4)
	{
		for (int i = size; i < Length * 4; i++)
		{
			ArrCStringDB.push_back(_T(""));
		}
	}
	DB.Close();
}
void User::ReadLog()
{
	TCHAR* DBName = _T("log.txt");
	CFile Log;
	UINT    nActual = 0;
	CFileException DBException;
	if (Log.Open(DBName, CFile::modeRead, &DBException))
	{
		char ArrLog[50] = { 0 };

		nActual = Log.Read(ArrLog, sizeof(ArrLog));

		Log.Close();

		int i = 0, q = 0;
		CString pr;
		while (i < nActual)
		{
			ArrLog[i] = Decrypt(ArrLog[i]);
			if (ArrLog[i] == '\n' || ArrLog[i] == '\r')
			{
				i++;
				continue;
			}
			if (ArrLog[i] == ';')
			{
				if (q == 0)
				{
					if (pr == S0 + Version)
					{
						Length = 2;
					}
					else if (pr == S1 + Version)
					{
						Length = 10;
					}
					else if (pr == S2 + Version)
					{
						Length = 20;
					}
					else if (pr == S3 + Version)
					{
						Length = 30;
					}
					else if (pr == S4 + Version)
					{
						Length = 40;
					}
					else if (pr == S5 + Version)
					{
						Length = 50;
					}
					else
					{
						CString oldpr;
						for (size_t k = 0; k < pr.GetLength(); k++)
						{
							oldpr += pr[k];
							if (oldpr == S0)
							{
								Length = 2;
								WriteLog(oldpr+Version, L"");
							}
							else if (oldpr == S1)
							{
								Length = 10;
								WriteLog(oldpr + Version, L"");
							}
							else if (oldpr == S2)
							{
								Length = 20;
								WriteLog(oldpr + Version, L"");
							}
							else if (oldpr == S3)
							{
								Length = 30;
								WriteLog(oldpr + Version, L"");
							}
							else if (oldpr == S4)
							{
								Length = 40;
								WriteLog(oldpr + Version, L"");
							}
							else if (oldpr == S5)
							{
								Length = 50;
								WriteLog(oldpr + Version, L"");
							}
						}
					}
				}
				else if (q == 1)
				{
					Pass = pr;
				}
				else if (q == 2)
				{
					ChekDiscOld = pr;
				}
				pr.Empty();
				i++;
				q++;
				continue;
			}
			pr += ArrLog[i];
			i++;
		}
	}
	else
	{
		Log.Open(DBName, CFile::modeCreate, &DBException);
	}
}
void User::WriteLog(CString indef, CString password)
{
	char ArrLog[50] = { 0 };
	TCHAR* DBName = _T("log.txt");
	CFile Log;
	CFileException DBException;
	int sizelog = 0;
	if (Log.Open(DBName, CFile::modeReadWrite, &DBException))
	{
		sizelog = Log.Read(ArrLog, sizeof(ArrLog));
	}
	CString s;
	int s1 = 0;
	if (indef == _T(""))
	{
		indef = password + _T(";");
		for (size_t j = 0; j <= sizelog - 1; j++)
		{
			s += Decrypt(ArrLog[j]);
			if (Decrypt(ArrLog[j]) == ';')
				break;
		}
		s += indef + ChekDiscNew + _T(";");
		ZeroMemory(ArrLog, 50);
		for (size_t j = 0; j <= s.GetLength() - 1; j++)
		{
			ArrLog[j] = Encrypt(s.GetAt(j));
		}
	}
	else if (password == _T(""))
	{
		indef += _T(";");
		for (size_t j = 0; j <= sizelog - 1; j++)
		{
			if (s1 == 1)
				s += Decrypt(ArrLog[j]);
			if (Decrypt(ArrLog[j]) == ';')
				s1++;
			if (s1 == 2)
				break;
		}
		indef += s + ChekDiscNew + _T(";");
		for (size_t j = 0; j <= indef.GetLength() - 1; j++)
		{
			ArrLog[j] = Encrypt(indef.GetAt(j));
		}
	}
	else
	{
		indef += _T(";") + password + _T(";") + ChekDiscNew + _T(";");
		for (size_t j = 0; j <= indef.GetLength() - 1; j++)
		{
			ArrLog[j] = Encrypt(indef.GetAt(j));
		}
	}
	Log.SeekToBegin();
	Log.Write(ArrLog, sizeof(ArrLog));	
	Log.Close();
}
void User::InfoDisc()
{
	char VolumeNameBuffer[100];
	char FileSystemNameBuffer[100];
	LPDWORD sz = 0, fs = 0;
	unsigned long drive_sn;
	if (GetVolumeInformationA(
		NULL,
		VolumeNameBuffer,
		100,
		&drive_sn,
		sz,
		fs,
		FileSystemNameBuffer,
		100
	))
	ChekDiscNew.Format(_T("%u"),drive_sn);
}