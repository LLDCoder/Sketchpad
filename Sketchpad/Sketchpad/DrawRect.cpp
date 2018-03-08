// DrawRect.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Sketchpad.h"
#include "DrawRect.h"
#include "afxdialogex.h"
#include "SelectedMode.h"

int t_RectLineweight;
COLORREF t_Rectcolor;
int t_Rectmod;
extern DrawRect drawRect;
extern SelectMod selectMod;
// DrawRect �Ի���

IMPLEMENT_DYNAMIC(DrawRect, CDialogEx)

DrawRect::DrawRect(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DrawRect, pParent)
{

}

DrawRect::~DrawRect()
{
}

void DrawRect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RectColor, RectColorSelect);
	DDX_Control(pDX, IDC_RectWeight, RectLineweight);
}


BEGIN_MESSAGE_MAP(DrawRect, CDialogEx)
	ON_BN_CLICKED(IDOK, &DrawRect::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RectColor, &DrawRect::OnBnClickedRectcolor)
	ON_CBN_SELCHANGE(IDC_RectWeight, &DrawRect::OnCbnSelchangeRectweight)
	ON_CBN_SELCHANGE(IDC_LineMod, &DrawRect::OnCbnSelchangeLinemod)
END_MESSAGE_MAP()


// DrawRect ��Ϣ�������
void DrawRect::OnBnClickedOk()
{
	drawRect.color = t_Rectcolor;
	drawRect.weight = t_RectLineweight;
	selectMod.drawMod = DrawMod::Rect;
	selectMod.userSelectMod = UserSelectedMod::Draw;
	CDialogEx::OnOK();
}


void DrawRect::OnBnClickedRectcolor()
{
	t_Rectcolor = RectColorSelect.GetColor();
}


void DrawRect::OnCbnSelchangeRectweight()
{
	//1 2 5 9
	int temp = RectLineweight.GetCurSel();
	if (temp == 0)
	{
		t_RectLineweight = 1;
	}
	else if (temp == 1)
	{
		t_RectLineweight = 2;
	}
	else if (temp == 2)
	{
		t_RectLineweight = 5;
	}
	else if (temp == 3)
	{
		t_RectLineweight = 9;
	}
	else
	{
		t_RectLineweight = 9;
	}
}


void DrawRect::OnCbnSelchangeLinemod()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
