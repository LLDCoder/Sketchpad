// DrawLine.cpp : 实现文件
//

#include "stdafx.h"
#include "Sketchpad.h"
#include "DrawLine.h"
#include "afxdialogex.h"
#include "SelectedMode.h"

//extern SelectMod selectMod;
// DrawLine 对话框
int t_weightLine;
COLORREF t_color;
extern DrawLine drawLine;
extern SelectMod selectMod;
IMPLEMENT_DYNAMIC(DrawLine, CDialogEx)

DrawLine::DrawLine(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DrawLine, pParent)
{
}

DrawLine::~DrawLine()
{
}

void DrawLine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, LineWeightSelect);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, LineColorSelect);
}


BEGIN_MESSAGE_MAP(DrawLine, CDialogEx)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &DrawLine::OnBnClickedMfccolorbutton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &DrawLine::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &DrawLine::OnBnClickedOk)
END_MESSAGE_MAP()


// DrawLine 消息处理程序


void DrawLine::OnBnClickedMfccolorbutton1()
{
	t_color = LineColorSelect.GetColor();
}

void DrawLine::OnCbnSelchangeCombo1()
{
	//1 2 5 9
	int temp = LineWeightSelect.GetCurSel();
	if (temp == 0)
	{
		t_weightLine = 1;
	}
	else if (temp == 1)
	{
		t_weightLine = 2;
	}
	else if (temp == 2)
	{
		t_weightLine = 5;
	}
	else if (temp == 3)
	{
		t_weightLine = 9;
	}
	else
	{
		t_weightLine = 9;
	}
}

void DrawLine::OnBnClickedOk()
{
	drawLine.color = t_color;
	drawLine.weightLine = t_weightLine;
	selectMod.userSelectMod = UserSelectedMod::Draw;
	selectMod.drawMod = DrawMod::Line;
	CDialogEx::OnOK();
}
