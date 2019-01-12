// MidLine.cpp: implementation of the MidLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Line.h"
#include "MidLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MidLine::MidLine()
{

}

MidLine::~MidLine()
{

}

inline abs(int a) {
	return (a < 0) ? -a : a;
}

void MidLine::draw(CPoint from, CPoint to, CDC* dc) {
	if ((abs(from.x - to.x) <= 1) && (abs(from.y - to.y) <= 1)) return;
	CPoint mid((from.x + to.x) / 2, (from.y + to.y) / 2);
	dc->SetPixel(mid, RGB(0, 255, 0));
	draw(from, mid, dc);
	draw(mid, to, dc);
}
