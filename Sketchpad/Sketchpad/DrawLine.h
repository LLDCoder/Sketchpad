#pragma once
#include "afxwin.h"
#include "afxcolorbutton.h"
// DrawLine �Ի���

class DrawLine : public CDialogEx
{
	DECLARE_DYNAMIC(DrawLine)
public:
	int weightLine;
	COLORREF color;
public:
	DrawLine(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DrawLine();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DrawLine };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox LineWeightSelect;
	CMFCColorButton LineColorSelect;
	afx_msg void OnBnClickedOk();
};
