
// MainFrm.cpp : CMainFrame 类的实现
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
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代
	
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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序
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
	// TODO: 在此添加命令处理程序代码
}


void CMainFrame::On32776()
{
	// TODO: 在此添加命令处理程序代码
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

//椭圆
void CMainFrame::On32786()
{
	// TODO: 在此添加命令处理程序代码
}


void CMainFrame::OnPaint()
{
	DrawPaint drawPaint;
	drawPaint.DoModal();
}
