// StudentScoreDlg.h : header file
//

#if !defined(AFX_STUDENTSCOREDLG_H__F2A01D37_4CB5_42D9_9A61_664101026CC6__INCLUDED_)
#define AFX_STUDENTSCOREDLG_H__F2A01D37_4CB5_42D9_9A61_664101026CC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStudentScoreDlg dialog
#include"Student.h"
class CStudentScoreDlg : public CDialog
{
// Construction
public:
	CStudentScoreDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentScoreDlg)
	enum { IDD = IDD_STUDENTSCORE_DIALOG };
	CListCtrl	m_List;
	CString	m_strMessage;
	CString	m_strName;
	CString	m_strNumber;
	double	m_fScore0;
	double	m_fScore1;
	double	m_fScore2;
	double	m_fSum;
	CString	m_strSex;
	CString	m_strClass;
	double	m_fAverage;
	CString	m_strQueryByName;
	CString	m_strQueryByNumber;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStudentScoreDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonOpen();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonSave();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonQueryok();
	afx_msg void OnButtonSortbytotaldown();
	afx_msg void OnButtonSortbytotalup();
	afx_msg void OnButtonSortbynumberdown();
	afx_msg void OnButtonSortbynumberup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void CreateStudentInfo(int i,StudentInfo &Stu);
	int notSaved;//当前信息是否已经保存，0：已经保存，1：未保存
	CString m_strFileName;//记录绝对路径的文件名
	CString m_strFileShortName;//记录不含路径的文件名
	void MyInsertItem(int i,StudentInfo *Stu); //公共模块，实现读取内存中学生数据添加在列表控制框中
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTSCOREDLG_H__F2A01D37_4CB5_42D9_9A61_664101026CC6__INCLUDED_)
