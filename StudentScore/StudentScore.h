// StudentScore.h : main header file for the STUDENTSCORE application
//

#if !defined(AFX_STUDENTSCORE_H__E9C9793F_43DB_4A02_8B37_BE204B0D2B65__INCLUDED_)
#define AFX_STUDENTSCORE_H__E9C9793F_43DB_4A02_8B37_BE204B0D2B65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStudentScoreApp:
// See StudentScore.cpp for the implementation of this class
//

class CStudentScoreApp : public CWinApp
{
public:
	CStudentScoreApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentScoreApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStudentScoreApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTSCORE_H__E9C9793F_43DB_4A02_8B37_BE204B0D2B65__INCLUDED_)
