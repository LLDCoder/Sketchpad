// DrawPoint.cpp : 实现文件
//

#include "stdafx.h"
#include "Sketchpad.h"
#include "DrawPoint.h"
#include "afxdialogex.h"
#include "SelectedMode.h"
#include <string>     
// DrawPoint 对话框
extern DrawPoint drawPoint;
extern SelectMod selectMod;
COLORREF t_pointcolor;
int t_weight;

IMPLEMENT_DYNAMIC(DrawPoint, CDialogEx)

DrawPoint::DrawPoint(CWnd* pParent /*=NULL*/)	: CDialogEx(IDD_DrawPoint, pParent){}

DrawPoint::~DrawPoint(){}

void DrawPoint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_POINTCOLORSELECT, PointColorSelect);
	DDX_Control(pDX, IDC_POINTWEIGHTSELECT, PointWeightSelect);
}


BEGIN_MESSAGE_MAP(DrawPoint, CDialogEx)
	ON_BN_CLICKED(IDOK, &DrawPoint::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DrawPoint::OnBnClickedCancel)
	
	ON_BN_CLICKED(IDC_POINTCOLORSELECT, &DrawPoint::OnBnClickedPointcolorselect)
	ON_CBN_SELCHANGE(IDC_POINTWEIGHTSELECT, &DrawPoint::OnCbnSelchangePointweightselect)
END_MESSAGE_MAP()

LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
	return wcstring;
}

// DrawPoint 消息处理程序
void DrawPoint::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	drawPoint.pointcolor = t_pointcolor;
	drawPoint.weight = t_weight;
	selectMod.userSelectMod = UserSelectedMod::Draw;
	selectMod.drawMod = DrawMod::Point;
	
	CDialogEx::OnOK();
}

void DrawPoint::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
void DrawPoint::OnBnClickedPointcolorselect()
{
	t_pointcolor =	PointColorSelect.GetColor();
}

void DrawPoint::OnCbnSelchangePointweightselect()
{
	//1 2 5 9
	int temp = PointWeightSelect.GetCurSel();
	if (temp == 0)
	{
		t_weight = 1;
	}
	else if (temp == 1)
	{
		t_weight = 2;
	}
	else if (temp == 2)
	{
		t_weight = 5;
	}
	else if (temp == 3)
	{
		t_weight = 9;
	}
	else 
	{
		t_weight = 9;
	}
}
