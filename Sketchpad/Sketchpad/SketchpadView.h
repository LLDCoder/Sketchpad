
// SketchpadView.h : CSketchpadView ��Ľӿ�
//
#pragma once
class CSketchpadView : public CView
{
protected: // �������л�����
	CSketchpadView();
	DECLARE_DYNCREATE(CSketchpadView)

// ����
public:
	CSketchpadDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSketchpadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SketchpadView.cpp �еĵ��԰汾
inline CSketchpadDoc* CSketchpadView::GetDocument() const
   { return reinterpret_cast<CSketchpadDoc*>(m_pDocument); }
#endif

