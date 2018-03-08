#pragma once
#include "afxcolorbutton.h"
#include "afxwin.h"
// DrawPoint 对话框

class DrawPoint : public CDialogEx
{
	DECLARE_DYNAMIC(DrawPoint)
public :
	COLORREF pointcolor;
	int weight;
public:
	DrawPoint(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DrawPoint();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DrawPoint };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CMFCColorButton PointColorSelect;
	afx_msg void OnBnClickedPointcolorselect();
	afx_msg void OnCbnSelchangePointweightselect();
	CComboBox PointWeightSelect;
};
