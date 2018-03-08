#pragma once
enum UserSelectedMod
{
	Draw=0,
	Pick,
	Erase,
	Break
};
enum DrawMod 
{
	Point=0,
	Line,
	Rect,
	Circle,
	Besiel,
	Paint
};
enum PickMod  {};
enum EraseMod {};
enum BreakMod {};
class SelectMod
{

public:
	SelectMod();
	~SelectMod();

public:
		UserSelectedMod userSelectMod;
		DrawMod drawMod;
	//others
}; 
