
// SketchpadView.cpp : CSketchpadView 类的实现
//

#include "stdafx.h"
#include "DrawPoint.h"
#include "DrawLine.h"
#include "SelectedMode.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sketchpad.h"
#endif

#include "SketchpadDoc.h"
#include "SketchpadView.h"
#include "DrawElement.h"
#include "DrawPaint.h"
#include "DrawRect.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//public 
SelectMod selectMod;
DrawPoint drawPoint;
DrawLine drawLine;
DrawRect drawRect;
DrawPaint drawPaint;
//private for this cpp
DrawManage drawManage;
// CSketchpadView
//temp variable
int flag = 0;
PaintElement tempPaint;
std::vector<CPoint> tempPointVector;

IMPLEMENT_DYNCREATE(CSketchpadView, CView)

BEGIN_MESSAGE_MAP(CSketchpadView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CSketchpadView 构造/析构
CSketchpadView::CSketchpadView(){	/* TODO: 在此处添加构造代码*/}

CSketchpadView::~CSketchpadView(){}

BOOL CSketchpadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSketchpadView 绘制

void CSketchpadView::OnDraw(CDC* pDC)
{
	CSketchpadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	drawManage.SetDraw(pDC);

	// TODO: 在此处为本机数据添加绘制代码
}
// CSketchpadView 打印
BOOL CSketchpadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSketchpadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSketchpadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}
// CSketchpadView 诊断
#ifdef _DEBUG
void CSketchpadView::AssertValid() const
{
	CView::AssertValid();
}

void CSketchpadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketchpadDoc* CSketchpadView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketchpadDoc)));
	return (CSketchpadDoc*)m_pDocument;
}
#endif //_DEBUG
// CSketchpadView 消息处理程序
void CSketchpadView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (selectMod.userSelectMod== UserSelectedMod::Draw)
	{
		if (selectMod.drawMod== DrawMod::Point)
		{
			PointElement tempPoint;
			tempPoint.CreatPoint(point, drawPoint.pointcolor, drawPoint.weight);
			drawManage.PointSetPushBack(tempPoint);
			Invalidate();
		}
		if (selectMod.drawMod == DrawMod::Line)
		{
			if (flag == 0) 
			{
				flag = 1;
				tempPointVector.push_back(point);
			}
			else if (flag == 1) 
			{
				flag = 0;
				LineElement tempLine;			
				tempLine.CreatLine(tempPointVector[0],point, drawLine.color, drawLine.weightLine);
				drawManage.LineSetPushBack(tempLine);
				tempPointVector.clear();
				Invalidate();
			}
		}
		if (selectMod.drawMod==DrawMod::Rect) 
		{
			if (flag==0) 
			{
				flag = 1;
				tempPointVector.push_back(point);
			}
			else if (flag==1) 
			{
				flag = 0;
				RectElement tempRect;
				tempRect.CreatRect(tempPointVector[0],point, drawRect.color, drawRect.weight);
				drawManage.RectSetPushBack(tempRect);
				tempPointVector.clear();
				Invalidate();
			}
		}
		if (selectMod.drawMod==DrawMod::Paint)
		{
			flag = 1;
			tempPaint.Set(drawPaint.color, drawPaint.weight);
		}
	}


	CView::OnLButtonDown(nFlags, point);
}


void CSketchpadView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (selectMod.userSelectMod == UserSelectedMod::Draw && selectMod.drawMod == DrawMod::Paint && flag==1)
	{
		tempPaint.AddPoint(point);
	}
	CView::OnMouseMove(nFlags, point);
}


void CSketchpadView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (selectMod.userSelectMod == UserSelectedMod::Draw && selectMod.drawMod == DrawMod::Paint && flag == 1)
	{
		flag = 0;
		drawManage.PaintSetPushBack(tempPaint);
		Invalidate();
	}

	CView::OnLButtonUp(nFlags, point);
}
