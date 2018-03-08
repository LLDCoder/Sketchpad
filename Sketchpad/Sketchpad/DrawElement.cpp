#include "stdafx.h"
#include <vector>
#include "DrawElement.h"
//Math
float t_abs(float src) 
{
	return src > 0 ? src : -src;
}
void DrawPoint(CDC *pDC,CPoint postion, COLORREF color, int weight)
{
	if (weight == 1)
	{
		pDC->SetPixel(postion, color);
	}
	else if (weight == 2)
	{
		pDC->SetPixel(postion, color);
		pDC->SetPixel(postion.x - 1, postion.y, color);
	}
	else if (weight == 5)
	{
		pDC->SetPixel(postion.x, postion.y + 1, color);
		pDC->SetPixel(postion.x, postion.y - 1, color);
		pDC->SetPixel(postion, color);
		pDC->SetPixel(postion.x + 1, postion.y, color);
		pDC->SetPixel(postion.x - 1, postion.y, color);
	}
	else if (weight == 9)
	{
		pDC->SetPixel(postion.x, postion.y + 1, color);
		pDC->SetPixel(postion.x, postion.y - 1, color);
		pDC->SetPixel(postion, color);
		pDC->SetPixel(postion.x + 1, postion.y, color);
		pDC->SetPixel(postion.x - 1, postion.y, color);
		pDC->SetPixel(postion.x + 1, postion.y + 1, color);
		pDC->SetPixel(postion.x - 1, postion.y + 1, color);
		pDC->SetPixel(postion.x + 1, postion.y - 1, color);
		pDC->SetPixel(postion.x - 1, postion.y - 1, color);
	}
}

//DrawManage
DrawManage::DrawManage() 
{
}
DrawManage::~DrawManage()
{
}
void DrawManage::SetDraw(CDC *pDC)
{
	PointSetDraw(pDC);
	LineSetDraw(pDC);
	RectSetDraw(pDC);
	PaintSetDraw(pDC);
}
void DrawManage::SetClear()
{
	pointSet.clear();
	lineSet.clear();
	rectSet.clear();
}
void DrawManage::PointSetPushBack(PointElement src)
{
	pointSet.push_back(src);
}
void DrawManage::LineSetPushBack(LineElement src)
{
	lineSet.push_back(src);
}
void DrawManage::RectSetPushBack(RectElement src)
{
	rectSet.push_back(src);
}
void DrawManage::PaintSetPushBack(PaintElement src)
{
	paintSet.push_back(src);
}
void DrawManage::PointSetDraw(CDC *pDC)
{
	for (unsigned int i = 0; i < pointSet.size(); i++)
	{
		pointSet[i].DrawPoint(pDC);
	}
}

void DrawManage::LineSetDraw(CDC * pDC)
{
	for (unsigned int i = 0; i < lineSet.size(); i++)
	{
		lineSet[i].LineDraw(pDC);
	}
}

void DrawManage::RectSetDraw(CDC * pDC)
{
	for (unsigned int i = 0; i < rectSet.size(); i++)
	{
		rectSet[i].RectDraw(pDC);
	}
}

void DrawManage::PaintSetDraw(CDC * pDC)
{
	for (int i = 0; i < paintSet.size();i++) 
	{
		paintSet[i].DrawPaint(pDC);
	}
}

//Point
void  PointElement::CreatPoint(CPoint in_Point, COLORREF in_Color, int in_Weight)
{
	postion = in_Point;
	color = in_Color;
	weight = in_Weight;
}
void PointElement::CreatPoint(CPoint in_Point, COLORREF in_Color, int in_Weight, int in_Mod)
{
	postion = in_Point;
	color = in_Color;
	weight = in_Weight;
	mod = in_Mod;
}
void PointElement::DrawPoint(CDC *pDC)
{
	if (weight == 1)
	{
		pDC->SetPixel(postion, color);
	}
	else if (weight == 2)
	{
		pDC->SetPixel(postion, color);
		pDC->SetPixel(postion.x-1,postion.y, color);
	}
	else if (weight == 5)
	{
		pDC->SetPixel(postion.x,postion.y + 1, color);
		pDC->SetPixel(postion.x,postion.y - 1, color);
		pDC->SetPixel(postion, color);
		pDC->SetPixel(postion.x + 1,postion.y, color);
		pDC->SetPixel(postion.x - 1,postion.y, color);
	}
	else if (weight == 9)
	{
		pDC->SetPixel(postion.x, postion.y + 1, color);
		pDC->SetPixel(postion.x, postion.y - 1, color);
		pDC->SetPixel(postion, color);
		pDC->SetPixel(postion.x + 1, postion.y, color);
		pDC->SetPixel(postion.x - 1, postion.y, color);
		pDC->SetPixel(postion.x + 1, postion.y + 1, color);
		pDC->SetPixel(postion.x - 1, postion.y + 1, color);
		pDC->SetPixel(postion.x + 1, postion.y - 1, color);
		pDC->SetPixel(postion.x - 1, postion.y - 1, color);
	}
}
//Line
void LineElement::CreatLine(CPoint sPoint, CPoint ePoint, COLORREF in_Color, int in_Weight)
{
	startPoint = sPoint;
	endPoint = ePoint;
	color = in_Color;
	weight = in_Weight;
}
void LineElement::LineDraw(CDC *pDC) 
{
	float dx =endPoint.x-startPoint.x;
	float dy = endPoint.y - startPoint.y;
	float k = dy / dx;
	if (dx>0) 
	{
		if (k<=1 && k>=-1)
		{
			for (int i = 0; i <= dx; i++)
			{
				/*PointElement tempPoint;
				tempPoint.CreatPoint(CPoint(startPoint.x + i, int(0.5 + startPoint.y + k * (+i))), color, weight);
				tempPoint.DrawPoint(pDC);*/
				DrawPoint(pDC,CPoint(startPoint.x + i, int(0.5 + startPoint.y + k * (+i))), color, weight);
			}
		}
		else 
		{
			if (dy>0) 
			{
				for (int i = 0; i <= dy; i++)
				{
					//PointElement tempPoint;
					//tempPoint.CreatPoint(CPoint(int(startPoint.x + i / k + 0.5), startPoint.y + i), color, weight);
					//tempPoint.DrawPoint(pDC);
					DrawPoint(pDC, CPoint(int(startPoint.x + i / k + 0.5), startPoint.y + i), color, weight);
				}
			}
			else 
			{
				for (int i = 0; i >= dy; i--)
				{
					//PointElement tempPoint;
					//tempPoint.CreatPoint(CPoint(int(startPoint.x + i / k + 0.5), startPoint.y + i), color, weight);
					//tempPoint.DrawPoint(pDC);
					DrawPoint(pDC, CPoint(int(startPoint.x + i / k + 0.5), startPoint.y + i), color, weight);
				}
			}
		}
	}
	else if(dx<0)
	{
		if (k <= 1 && k >= -1)
		{
			for (int i = 0; i >= dx; i--)
			{
				//PointElement tempPoint;
				//tempPoint.CreatPoint(CPoint(startPoint.x + i, int(0.5 + startPoint.y + k * (+i))), color, weight);
				//tempPoint.DrawPoint(pDC);
				DrawPoint(pDC, CPoint(startPoint.x + i, int(0.5 + startPoint.y + k * (+i))), color, weight);
			}
		}
		else
		{
			if (dy>0) 
			{
				for (int i = 0; i <= dy; i++)
				{
					//PointElement tempPoint;
					//tempPoint.CreatPoint(CPoint(int(startPoint.x + i / k + 0.5), startPoint.y + i), color, weight);
					//tempPoint.DrawPoint(pDC);
					DrawPoint(pDC, CPoint(int(startPoint.x + i / k + 0.5), startPoint.y + i), color, weight);
				}
			}
			else 
			{
				for (int i = 0; i >= dy; i--)
				{
					//PointElement tempPoint;
					//tempPoint.CreatPoint(CPoint(int(startPoint.x + i / k + 0.5), startPoint.y + i), color, weight);
					//tempPoint.DrawPoint(pDC);
					DrawPoint(pDC, CPoint(int(startPoint.x + i / k + 0.5), startPoint.y + i), color, weight);
				}
			}
		}
	}
	else if(dx==0)
	{
		if (dy>0) 
		{
			for (int i = 0; i <= dy; i++)
			{
				//PointElement tempPoint;
				//tempPoint.CreatPoint(CPoint(startPoint.x, startPoint.y + i), color, weight);
				//tempPoint.DrawPoint(pDC);
				DrawPoint(pDC, CPoint(startPoint.x, startPoint.y + i), color, weight);
			}
		}
		else 
		{
			for (int i = 0; i >= dy; i--)
			{
				//PointElement tempPoint;
				//tempPoint.CreatPoint(CPoint(startPoint.x, startPoint.y + i), color, weight);
				//tempPoint.DrawPoint(pDC);
				DrawPoint(pDC, CPoint(startPoint.x, startPoint.y + i), color, weight);
			}
		}	
	}
}

void RectElement::CreatRect(CPoint sPoint, CPoint ePoint, COLORREF in_Color, int in_Weight)
{
	leftUp=sPoint;
	rightDown=ePoint;
	color=in_Color;
	weight=in_Weight;
}

void RectElement::RectDraw(CDC * pDC)
{
	LineElement lineup ;
	LineElement linedown;
	LineElement lineleft;
	LineElement lineright;

	lineup.CreatLine(leftUp,CPoint(rightDown.x,leftUp.y),color,weight);
	linedown.CreatLine(CPoint(leftUp.x,rightDown.y), rightDown, color, weight);
	lineleft.CreatLine(leftUp, CPoint(leftUp.x, rightDown.y), color, weight);
	lineright.CreatLine(CPoint(rightDown.x, leftUp.y), rightDown, color, weight);

	lineup.LineDraw(pDC);
	linedown.LineDraw(pDC);
	lineleft.LineDraw(pDC);
	lineright.LineDraw(pDC);
}

void PaintElement::AddPoint(CPoint src)
{
	paintLine.push_back(src);
}

void PaintElement::Set(COLORREF in_color, int in_weight)
{
	color = in_color;
	weight = in_weight;
}

void PaintElement::DrawPaint(CDC * pDC)
{
	for (int i=0;i<paintLine.size();i++) 
	{
		DrawPoint(pDC, paintLine[i],color, weight);
	}
}
