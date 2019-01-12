// LineView.cpp : implementation of the CLineView class
//

#include "stdafx.h"
#include "Line.h"

#include "LineDoc.h"
#include "LineView.h"
#include "DDALine.h"
#include "MidLine.h"
#include "Bresenham.h"
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PI 3.1415926

/////////////////////////////////////////////////////////////////////////////
// CLineView

IMPLEMENT_DYNCREATE(CLineView, CView)

BEGIN_MESSAGE_MAP(CLineView, CView)
	//{{AFX_MSG_MAP(CLineView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineView construction/destruction

CLineView::CLineView()
{
	// TODO: add construction code here

}

CLineView::~CLineView()
{
}

BOOL CLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLineView drawing

void CLineView::OnDraw(CDC* pDC)
{
	CLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
	GetWindowRect(&rect);
	CPoint center(rect.Width() / 2, rect.Height() / 2);
	CPoint org(0, 0);
	double i;
	if (pDoc->mode > 8) {
		pDoc->mode %= 8;
		int radius = 150;
		for (i = 0; i < 2 * PI; i += 0.1) {
			CPoint point(radius * sin(i) + center.x, radius * cos(i) + center.y);
			pDC->MoveTo(center);
			pDC->LineTo(point);
		}
		for (i = 0; i < 2 * PI; i += 0.1) {
			CPoint point(radius * sin(i) + center.x, radius * cos(i) + center.y);
			switch (pDoc->mode) {
				case 1:
					DDALine::draw(center, point, pDC);
					break;
				case 2:
					MidLine::draw(center, point, pDC);
					break;
				case 3:
					Bresenham::draw(center, point, pDC);
					break;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLineView printing

BOOL CLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLineView diagnostics

#ifdef _DEBUG
void CLineView::AssertValid() const
{
	CView::AssertValid();
}

void CLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLineDoc* CLineView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLineDoc)));
	return (CLineDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLineView message handlers

void CLineView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CRect rect;
	GetWindowRect(&rect);
	CPoint center(rect.Width() / 2, rect.Height() / 2);
	CClientDC dc(this);
	CLineDoc* doc = (CLineDoc*) GetDocument();
	if (doc->refer) {
		dc.MoveTo(center);
		dc.LineTo(point);
	}
	switch (doc->mode) {
	case 1:
		DDALine::draw(center, point, &dc);
		break;
	case 2:
		MidLine::draw(center, point, &dc);
		break;
	case 3:
		Bresenham::draw(center, point, &dc);
		break;
	case 4:
		dc.MoveTo(center);
		dc.LineTo(point);
		break;
	}
}
