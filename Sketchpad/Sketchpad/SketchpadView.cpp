
// SketchpadView.cpp : CSketchpadView ���ʵ��
//

#include "stdafx.h"
#include "DrawPoint.h"
#include "DrawLine.h"
#include "SelectedMode.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CSketchpadView ����/����
CSketchpadView::CSketchpadView(){	/* TODO: �ڴ˴���ӹ������*/}

CSketchpadView::~CSketchpadView(){}

BOOL CSketchpadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSketchpadView ����

void CSketchpadView::OnDraw(CDC* pDC)
{
	CSketchpadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	drawManage.SetDraw(pDC);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}
// CSketchpadView ��ӡ
BOOL CSketchpadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSketchpadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSketchpadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}
// CSketchpadView ���
#ifdef _DEBUG
void CSketchpadView::AssertValid() const
{
	CView::AssertValid();
}

void CSketchpadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketchpadDoc* CSketchpadView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketchpadDoc)));
	return (CSketchpadDoc*)m_pDocument;
}
#endif //_DEBUG
// CSketchpadView ��Ϣ�������
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
