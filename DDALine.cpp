// DDALine.cpp: implementation of the DDALine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Line.h"
#include "DDALine.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DDALine::DDALine()
{

}

DDALine::~DDALine()
{

}

inline int abs(int a) {
	return (a < 0) ? -a : a;
}

void DDALine::draw(CPoint from, CPoint to, CDC* dc) {
	float x = from.x + 0.5;
	float y = from.y + 0.5;
	float stepx, stepy;
	int times = 1;
	COLORREF color = RGB(255, 0, 0);

	int dy = to.y - from.y;
	int dx = to.x - from.x;
	if (abs(dy) >= abs(dx)) {
		times += abs(dy);
		stepx = dx * 1.f / dy;
		stepy = 1.f;
		if (from.y > to.y) {
			stepx *= -1;
			stepy *= -1;
		}
	} else {
		times += abs(dx);
		stepx = 1.f;
		stepy = dy * 1.f / dx;
		if (from.x > to.x) {
			stepx *= -1;
			stepy *= -1;
		}
	}

	while (times--) {
		dc->SetPixel((int) x, (int) y, color);
		x += stepx;
		y += stepy;
	}
}
