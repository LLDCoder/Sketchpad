
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "Sketchpad.h"
#include "DrawPoint.h"
#include "DrawLine.h"
#include "DrawRect.h"
#include "SelectedMode.h"
#include "DrawElement.h"
#include "DrawPaint.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
extern SelectMod selectMod;
extern DrawManage drawManage;
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_32772, &CMainFrame::On32772)
	ON_COMMAND(ID_32773, &CMainFrame::On32773)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)
	ON_COMMAND(ID_32775, &CMainFrame::On32775)
	ON_COMMAND(ID_32776, &CMainFrame::On32776)
	ON_COMMAND(ID_32783, &CMainFrame::On32783)
	ON_COMMAND(ID_32784, &CMainFrame::On32784)
	ON_COMMAND(ID_32786, &CMainFrame::On32786)
	ON_COMMAND(IDD_Paint, &CMainFrame::OnPaint)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ����
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������
void CMainFrame::On32772()
{
	DrawPoint drawPoint;
	drawPoint.DoModal();
}


void CMainFrame::On32773()
{
	DrawLine drawLine;
	drawLine.DoModal();
}


void CMainFrame::On32774()
{
	DrawRect drawRect;
	drawRect.DoModal();
}


void CMainFrame::On32775()
{
	// TODO: �ڴ���������������
}


void CMainFrame::On32776()
{
	// TODO: �ڴ���������������
}


//Pick any
void CMainFrame::On32783()
{
	selectMod.userSelectMod = UserSelectedMod::Pick;
}

//Clear All
void CMainFrame::On32784()
{
	drawManage.SetClear();
	Invalidate();
}

//��Բ
void CMainFrame::On32786()
{
	// TODO: �ڴ���������������
}


void CMainFrame::OnPaint()
{
	DrawPaint drawPaint;
	drawPaint.DoModal();
}
