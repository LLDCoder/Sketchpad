#pragma once
#include "afxcolorbutton.h"
#include "afxwin.h"


// DrawPaint 对话框

class DrawPaint : public CDialogEx
{
	DECLARE_DYNAMIC(DrawPaint)
	int weight;
	COLORREF color;
public:
	DrawPaint(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DrawPaint();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedPaintcolor();
	afx_msg void OnCbnSelchangePaintweight();
	CMFCColorButton PaintColorSelect;
	CComboBox PaintWeightSelect;
};
