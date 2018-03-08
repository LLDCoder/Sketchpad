#pragma once
#include "afxwin.h"
#include "afxcolorbutton.h"
// DrawLine 对话框

class DrawLine : public CDialogEx
{
	DECLARE_DYNAMIC(DrawLine)
public:
	int weightLine;
	COLORREF color;
public:
	DrawLine(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DrawLine();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DrawLine };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox LineWeightSelect;
	CMFCColorButton LineColorSelect;
	afx_msg void OnBnClickedOk();
};
