// MidLine.h: interface for the MidLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MIDLINE_H__F93FC133_C75F_4D35_8927_061247F7F396__INCLUDED_)
#define AFX_MIDLINE_H__F93FC133_C75F_4D35_8927_061247F7F396__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MidLine  
{
public:
	MidLine();
	virtual ~MidLine();
	static void draw(CPoint from, CPoint to, CDC* dc);
};

#endif // !defined(AFX_MIDLINE_H__F93FC133_C75F_4D35_8927_061247F7F396__INCLUDED_)
