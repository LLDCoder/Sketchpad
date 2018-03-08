#pragma once
#include <vector>
using namespace std;
class PaintElement 
{
private:
	std::vector<CPoint> paintLine;
	COLORREF color;
	int weight;
	int mod;
public :
	void AddPoint(CPoint src);
	void Set(COLORREF in_color,int in_weight);
	void DrawPaint(CDC *pDC);
};
class PointElement
{
private:
	CPoint postion;
	COLORREF color;
	int weight;
	int mod;//ÏßÐÍ
public:
	void CreatPoint(CPoint in_Point, COLORREF in_Color, int in_Weight);
	void CreatPoint(CPoint in_Point, COLORREF in_Color, int in_Weight, int in_Mod);
	void DrawPoint(CDC *pDC);
};
class LineElement 
{
private:
	CPoint startPoint;
	CPoint endPoint;
	COLORREF color;
	int weight;
	int mod;
public :
	//Set option
	void CreatLine(CPoint sPoint,CPoint ePoint,COLORREF in_Color,int in_Weight);
	//Draw Option
	void LineDraw(CDC *pDC);
};
class RectElement 
{
private:
	CPoint leftUp;
	CPoint rightDown;
	COLORREF color;
	int weight;
	int mod;
public:
	void CreatRect(CPoint sPoint, CPoint ePoint, COLORREF in_Color, int in_Weight);
	void RectDraw(CDC *pDC);
};
class DrawManage 
{
private:
	std::vector<PointElement> pointSet;
	std::vector<LineElement> lineSet; 
	std::vector<RectElement> rectSet;
	std::vector<PaintElement>paintSet;
	//Set Option
public :
	DrawManage();
	~DrawManage();
	//Data Option
	void SetClear();
	void PointSetPushBack(PointElement src);
	void LineSetPushBack(LineElement src);
	void RectSetPushBack(RectElement src);
	void PaintSetPushBack(PaintElement src);
	//Draw Option
	void SetDraw(CDC *pDC);

	void PointSetDraw(CDC *pDC);
	void LineSetDraw(CDC *pDC);
	void RectSetDraw(CDC *pDC);
	void PaintSetDraw(CDC *pDC);
};
