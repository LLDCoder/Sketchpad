#pragma once
#include "afxcolorbutton.h"
#include "afxwin.h"


// DrawRect 对话框

class DrawRect : public CDialogEx
{
	DECLARE_DYNAMIC(DrawRect)
	int weight;
	COLORREF color;
	int mod;

public:
	DrawRect(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DrawRect();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DrawRect };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRectcolor();
	afx_msg void OnCbnSelchangeRectweight();
	afx_msg void OnCbnSelchangeLinemod();
	CMFCColorButton RectColorSelect;
	CComboBox RectLineweight;
};
