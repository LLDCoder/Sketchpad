#include "stdafx.h"
#include "SelectedMode.h"

SelectMod::SelectMod()
{
	userSelectMod = UserSelectedMod::Draw;
	drawMod = DrawMod::Point;
}

SelectMod::~SelectMod()
{
}