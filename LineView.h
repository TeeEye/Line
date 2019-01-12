// LineView.h : interface of the CLineView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEVIEW_H__1400B3EF_BC4E_4827_8227_DCC2DE6E280B__INCLUDED_)
#define AFX_LINEVIEW_H__1400B3EF_BC4E_4827_8227_DCC2DE6E280B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLineView : public CView
{
protected: // create from serialization only
	CLineView();
	DECLARE_DYNCREATE(CLineView)

// Attributes
public:
	CLineDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLineView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LineView.cpp
inline CLineDoc* CLineView::GetDocument()
   { return (CLineDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEVIEW_H__1400B3EF_BC4E_4827_8227_DCC2DE6E280B__INCLUDED_)
