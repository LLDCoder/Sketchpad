#pragma once
#include "afxcolorbutton.h"
#include "afxwin.h"


// DrawPaint �Ի���

class DrawPaint : public CDialogEx
{
	DECLARE_DYNAMIC(DrawPaint)
	int weight;
	COLORREF color;
public:
	DrawPaint(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DrawPaint();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedPaintcolor();
	afx_msg void OnCbnSelchangePaintweight();
	CMFCColorButton PaintColorSelect;
	CComboBox PaintWeightSelect;
};
