
// PasBox.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPasBoxApp:
// О реализации данного класса см. PasBox.cpp
//

class CPasBoxApp : public CWinApp
{
public:
	CPasBoxApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CPasBoxApp theApp;