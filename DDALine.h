// DDALine.h: interface for the DDALine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDALINE_H__792F9195_4CDC_41B1_AD7D_68C0305B74C2__INCLUDED_)
#define AFX_DDALINE_H__792F9195_4CDC_41B1_AD7D_68C0305B74C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DDALine  
{
public:
	DDALine();
	virtual ~DDALine();
	static void draw(CPoint from, CPoint to, CDC* dc);
};

#endif // !defined(AFX_DDALINE_H__792F9195_4CDC_41B1_AD7D_68C0305B74C2__INCLUDED_)
