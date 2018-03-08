// DrawPaint.cpp : 实现文件
//

#include "stdafx.h"
#include "Sketchpad.h"
#include "DrawPaint.h"
#include "DrawPoint.h"
#include "SelectedMode.h"
#include "afxdialogex.h"

//extern DrawPoint drawPoint;
extern SelectMod selectMod;
extern DrawPaint drawPaint;
// DrawPaint 对话框

IMPLEMENT_DYNAMIC(DrawPaint, CDialogEx)
int t_paintweight;
COLORREF t_paintcolor;
DrawPaint::DrawPaint(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

DrawPaint::~DrawPaint()
{
}

void DrawPaint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PaintColor, PaintColorSelect);
	DDX_Control(pDX, IDC_PaintWeight, PaintWeightSelect);
}


BEGIN_MESSAGE_MAP(DrawPaint, CDialogEx)
	ON_BN_CLICKED(IDOK, &DrawPaint::OnBnClickedOk)
	ON_BN_CLICKED(IDC_PaintColor, &DrawPaint::OnBnClickedPaintcolor)
	ON_CBN_SELCHANGE(IDC_PaintWeight, &DrawPaint::OnCbnSelchangePaintweight)
END_MESSAGE_MAP()


// DrawPaint 消息处理程序


void DrawPaint::OnBnClickedOk()
{
	drawPaint.color = t_paintcolor;
	drawPaint.weight = t_paintweight;
	selectMod.drawMod = DrawMod::Paint;
	selectMod.userSelectMod = UserSelectedMod::Draw;
	CDialogEx::OnOK();
}


void DrawPaint::OnBnClickedPaintcolor()
{
	t_paintcolor = PaintColorSelect.GetColor();
}


void DrawPaint::OnCbnSelchangePaintweight()
{
	//1 2 5 9
	int temp = PaintWeightSelect.GetCurSel();
	if (temp == 0)
	{
		t_paintweight = 1;
	}
	else if (temp == 1)
	{
		t_paintweight = 2;
	}
	else if (temp == 2)
	{
		t_paintweight = 5;
	}
	else if (temp == 3)
	{
		t_paintweight = 9;
	}
	else
	{
		t_paintweight = 9;
	}
}
