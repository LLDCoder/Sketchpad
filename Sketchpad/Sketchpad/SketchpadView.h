
// SketchpadView.h : CSketchpadView 类的接口
//
#pragma once
class CSketchpadView : public CView
{
protected: // 仅从序列化创建
	CSketchpadView();
	DECLARE_DYNCREATE(CSketchpadView)

// 特性
public:
	CSketchpadDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSketchpadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SketchpadView.cpp 中的调试版本
inline CSketchpadDoc* CSketchpadView::GetDocument() const
   { return reinterpret_cast<CSketchpadDoc*>(m_pDocument); }
#endif

