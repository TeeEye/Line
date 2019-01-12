// Control.cpp : implementation file
//

#include "stdafx.h"
#include "Line.h"
#include "Control.h"
#include "LineDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControl

IMPLEMENT_DYNCREATE(CControl, CFormView)

CControl::CControl()
	: CFormView(CControl::IDD)
{
	//{{AFX_DATA_INIT(CControl)
	//}}AFX_DATA_INIT
}

CControl::~CControl()
{
}

void CControl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CControl)
	DDX_Control(pDX, IDC_MODE, m_mode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CControl, CFormView)
	//{{AFX_MSG_MAP(CControl)
	ON_CBN_SELCHANGE(IDC_MODE, OnSelchangeMode)
	ON_BN_CLICKED(IDC_REFER, OnRefer)
	ON_BN_CLICKED(IDC_COMPARE, OnCompare)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControl diagnostics

#ifdef _DEBUG
void CControl::AssertValid() const
{
	CFormView::AssertValid();
}

void CControl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControl message handlers

void CControl::OnSelchangeMode() 
{
	// TODO: Add your control notification handler code here
	CLineDoc* doc = (CLineDoc*)GetDocument();
	doc->mode = m_mode.GetCurSel();
	doc->UpdateAllViews(this);
}

void CControl::OnRefer() 
{
	// TODO: Add your control notification handler code here
	CLineDoc* doc = (CLineDoc*)GetDocument();
	doc->refer = !doc->refer;
}

void CControl::OnCompare() 
{
	// TODO: Add your control notification handler code here
	CLineDoc* doc = (CLineDoc*)GetDocument();
	doc->mode += 8;
	doc->UpdateAllViews(this);
}
