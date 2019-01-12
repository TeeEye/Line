// Bresenham.cpp: implementation of the Bresenham class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Line.h"
#include "Bresenham.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Bresenham::Bresenham()
{

}

Bresenham::~Bresenham()
{

}

inline int abs(int a) {
	return (a < 0) ? -a : a;
}

void Bresenham::draw(CPoint from, CPoint to, CDC* dc) {
	int dx = abs(to.x - from.x);
	int dy = abs(to.y - from.y);
	int x = from.x;
	int y = from.y;
	COLORREF color = RGB(0, 255, 255);
	int stepx = (from.x < to.x) ? 1 : -1;
	int stepy = (from.y < to.y) ? 1 : -1;
	int e;
	if (dx > dy) {
		e = dy * 2 - dx;
		for (int i = 0; i <= dx; i++) {
			dc->SetPixel(x, y, color);
			x += stepx;
			e += 2 * dy;
			if (e > 0) {
				e -= 2 * dx;
				y += stepy;
			}
		}
	} else {
		e = dx * 2 - dy;
		for (int i = 0; i <= dy; i++) {
			dc->SetPixel(x, y, color);
			y += stepy;
			e += 2 * dx;
			if (e > 0) {
				e -= 2 * dy;
				x += stepx;
			}
		}
	}
}
