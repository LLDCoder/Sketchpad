
// Sketchpad.h : Sketchpad Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSketchpadApp:
// �йش����ʵ�֣������ Sketchpad.cpp
//

class CSketchpadApp : public CWinApp
{
public:
	CSketchpadApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSketchpadApp theApp;