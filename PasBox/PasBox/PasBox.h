
// PasBox.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CPasBoxApp:
// � ���������� ������� ������ ��. PasBox.cpp
//

class CPasBoxApp : public CWinApp
{
public:
	CPasBoxApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CPasBoxApp theApp;