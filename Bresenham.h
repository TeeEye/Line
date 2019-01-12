// Bresenham.h: interface for the Bresenham class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRESENHAM_H__68DEF603_4F18_42D6_9069_34D0D5D4B9DE__INCLUDED_)
#define AFX_BRESENHAM_H__68DEF603_4F18_42D6_9069_34D0D5D4B9DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Bresenham  
{
public:
	Bresenham();
	virtual ~Bresenham();
	void static draw(CPoint from, CPoint to, CDC* dc);
};

#endif // !defined(AFX_BRESENHAM_H__68DEF603_4F18_42D6_9069_34D0D5D4B9DE__INCLUDED_)
