#if !defined(AFX_CONTROL_H__8ACC42E2_0743_4E70_B615_23C566B8FE8E__INCLUDED_)
#define AFX_CONTROL_H__8ACC42E2_0743_4E70_B615_23C566B8FE8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Control.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CControl form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CControl : public CFormView
{
protected:
	CControl();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CControl)

// Form Data
public:
	//{{AFX_DATA(CControl)
	enum { IDD = IDD_CONTROL };
	CComboBox	m_mode;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CControl();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CControl)
	afx_msg void OnSelchangeMode();
	afx_msg void OnRefer();
	afx_msg void OnCompare();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROL_H__8ACC42E2_0743_4E70_B615_23C566B8FE8E__INCLUDED_)
