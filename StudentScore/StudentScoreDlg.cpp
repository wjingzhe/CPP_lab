// StudentScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StudentScore.h"
#include "StudentScoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentScoreDlg dialog

CStudentScoreDlg::CStudentScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentScoreDlg)
	m_strMessage = _T("");
	m_strName = _T("");
	m_strNumber = _T("");
	m_fScore0 = '\0';
	m_fScore1 = '\0';
	m_fScore2 = '\0';
	m_fSum = '\0';
	m_strSex = _T("");
	m_strClass = _T("");
	m_fAverage = '\0';
	m_strQueryByName = _T("");
	m_strQueryByNumber = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentScoreDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT_MESSAGE, m_strMessage);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NUMBER, m_strNumber);
	DDX_Text(pDX, IDC_EDIT_SCORE0, m_fScore0);
	DDX_Text(pDX, IDC_EDIT_SCORE1, m_fScore1);
	DDX_Text(pDX, IDC_EDIT_SCORE2, m_fScore2);
	DDX_Text(pDX, IDC_EDIT_SUM, m_fSum);
	DDX_Text(pDX, IDC_EDIT_SEX, m_strSex);
	DDX_Text(pDX, IDC_EDIT_CLASS, m_strClass);
	DDX_Text(pDX, IDC_EDIT_AVERAGE, m_fAverage);
	DDX_Text(pDX, IDC_EDIT_QUERYBYNAME, m_strQueryByName);
	DDX_Text(pDX, IDC_EDIT_QUERYBYNUMBER, m_strQueryByNumber);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStudentScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentScoreDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_QUERYOK, OnButtonQueryok)
	ON_BN_CLICKED(IDC_BUTTON_SORTBYTOTALDOWN, OnButtonSortbytotaldown)
	ON_BN_CLICKED(IDC_BUTTON_SORTBYTOTALUP, OnButtonSortbytotalup)
	ON_BN_CLICKED(IDC_BUTTON_SORTBYNUMBERDOWN, OnButtonSortbynumberdown)
	ON_BN_CLICKED(IDC_BUTTON_SORTBYNUMBERUP, OnButtonSortbynumberup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentScoreDlg message handlers

BOOL CStudentScoreDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE);
	m_List.InsertColumn(0,"学号");
	m_List.InsertColumn(1,"姓名");
	m_List.InsertColumn(2,"性别");
	m_List.InsertColumn(3,"班级");
	m_List.InsertColumn(4,"语文");
	m_List.InsertColumn(5,"数学");
	m_List.InsertColumn(6,"英语");
	m_List.InsertColumn(7,"总分");
	m_List.InsertColumn(8,"平均分");
	//设置每列宽度
	RECT rectList;
	m_List.GetWindowRect(&rectList);
	int widList = rectList.right-rectList.left;
	for(int k = 0;k<9;k++)
	{
		m_List.SetColumnWidth(k,widList/9);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudentScoreDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStudentScoreDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStudentScoreDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStudentScoreDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	if(notSaved==1)
	{
		MessageBox("文件尚未保存，请先保存文件");
		return;
	}
	CFileDialog dlg(false,"txt",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"text file(*.txt)|*.txt",this);
	if(dlg.DoModal()!=IDOK)
		return;
	m_strFileName = dlg.GetPathName();//得到包含路径的文件名
	m_strFileShortName = dlg.GetFileName();//得到文件名

	FILE *fp;
	if((fp=fopen(m_strFileName,"wb"))==NULL)
	{
		MessageBox("文件无法创建。");
		exit(0);
	}
	m_strMessage = m_strFileShortName+"文件已经创建！";
	UpdateData(false);//将成员变量的数据传递给控件并显示
	fclose(fp);
}//CStudentScoreDlg::OnButtonNew()

void CStudentScoreDlg::OnButtonOpen() 
{
	// TODO: Add your control notification handler code here
	if(notSaved==1)
	{
		MessageBox("文件尚未保存，请先保存文件");
		return;
	}//if

	CFileDialog dlg(true,"txt",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"text file(*.txt)|*.txt",this);
	if(dlg.DoModal()!=IDOK)
		return;
	m_strFileName = dlg.GetPathName();//得到包含路径的文件名
	m_strFileShortName = dlg.GetFileName();//保存文件名
	m_List.DeleteAllItems(); //删除列表控件中的所有数据
	FILE *fp;
	StudentInfo Stu;
	int i = 0;
	if((fp=fopen(m_strFileName,"rb"))==NULL)
	{
		MessageBox("文件无法打开。");
		exit(0);
	}
	m_strMessage = m_strFileShortName+"文件已经打开！";
	while(fread(&Stu,sizeof(StudentInfo),1,fp)==1)
	{
		m_List.InsertItem(i,Stu.Number);
		m_List.SetItemText(i,1,Stu.Name);
		m_List.SetItemText(i,2,Stu.Sex);
		m_List.SetItemText(i,3,Stu.Class);
		char temp[10];
		gcvt(Stu.Score[0],3,temp);//将浮点数转化为字符串，保留三位有效数字
		m_List.SetItemText(i,4,temp);
		gcvt(Stu.Score[1],3,temp);//将浮点数转化为字符串，保留三位有效数字
		m_List.SetItemText(i,5,temp);
		gcvt(Stu.Score[2],3,temp);//将浮点数转化为字符串，保留三位有效数字
		m_List.SetItemText(i,6,temp);
		gcvt(Stu.Sum,3,temp);//将浮点数转化为字符串，保留三位有效数字
		m_List.SetItemText(i,7,temp);
		gcvt(Stu.Average,3,temp);//将浮点数转化为字符串，保留三位有效数字
		m_List.SetItemText(i,8,temp);
		i++;
	}//while
	UpdateData(false);//将成员变量的数据传递给控件并显示
	fclose(fp);
}//CStudentScoreDlg::OnButtonOpen()

void CStudentScoreDlg::CreateStudentInfo(int i, StudentInfo &Stu)
{
	char chTemp[20]={'\0'};
	m_List.GetItemText(i,0,chTemp,sizeof(chTemp));
	strcpy(Stu.Number,chTemp);
	m_List.GetItemText(i,1,chTemp,sizeof(chTemp));
	strcpy(Stu.Name,chTemp);
	m_List.GetItemText(i,2,chTemp,sizeof(chTemp));
	strcpy(Stu.Sex,chTemp);
	m_List.GetItemText(i,3,chTemp,sizeof(chTemp));
	strcpy(Stu.Class,chTemp);
	m_List.GetItemText(i,4,chTemp,sizeof(chTemp));
	Stu.Score[0] = atof(chTemp);
	m_List.GetItemText(i,5,chTemp,sizeof(chTemp));
	Stu.Score[1] = atof(chTemp);
	m_List.GetItemText(i,6,chTemp,sizeof(chTemp));
	Stu.Score[2] = atof(chTemp);
	m_List.GetItemText(i,7,chTemp,sizeof(chTemp));
	Stu.Sum = atof(chTemp);
	m_List.GetItemText(i,8,chTemp,sizeof(chTemp));
	Stu.Average = atof(chTemp);
}

void CStudentScoreDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	if(m_strFileName.IsEmpty())
	{
		MessageBox("请先指定操作的班级！\n请单击\"新建班级\"或\"打开班级\"按钮，将数据写入某个班级文件");
		return;
	}
	else
	{
		UpdateData();
		int n = m_List.GetItemCount();
		char str[20] = "\0";
		if(m_strNumber=="\0"||m_strName=="\0"||m_strSex=="\0"||m_strClass=="\0"||m_fScore0=='\0'||m_fScore1=='\0'||m_fScore2=='\0')
		{
			MessageBox("所有信息均不能为空！");
			return;
		}
		if(m_fScore0>100||m_fScore0<0||m_fScore1>100||m_fScore1<0||m_fScore2>100||m_fScore2<0)
		{
			MessageBox("成绩不能为负数或者大于100！");
			return;
		}

		//将数据显示到列表控件中
		m_List.InsertItem(n,m_strNumber);
		m_List.SetItemText(n,1,m_strName);
		m_List.SetItemText(n,2,m_strSex);
		m_List.SetItemText(n,3,m_strClass);
		char temp[10];
		gcvt(m_fScore0,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(n,4,temp);
		gcvt(m_fScore1,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(n,5,temp);
		gcvt(m_fScore2,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(n,6,temp);
		m_fSum = m_fScore0+m_fScore1+m_fScore2;
		gcvt(m_fSum,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(n,7,temp);
		m_fAverage = m_fSum/3.0;
		gcvt(m_fAverage,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(n,8,temp);
		m_strNumber = m_strName = m_strSex = "\0";
		m_fScore0 = m_fScore1 = m_fScore2 = m_fSum = m_fAverage = '\0';
		m_strMessage = "请记得保存数据到文件"+m_strFileShortName+"中!";
		notSaved = 1;
		MessageBox("信息添加成功！");
		UpdateData(false);

		//将数据保存到文件中
/*		StudentInfo Stu;
		CreateStudentInfo(n,Stu);
		FILE *fp;
		if((fp=fopen(m_strFileName,"ab"))==NULL)
		{
			MessageBox("文件无法打开。");
			exit(0);
		}
		fwrite(&Stu,sizeof(StudentInfo),1,fp);
		m_strMessage = "新增信息已添加到文件"+m_strFileShortName;
		fclose(fp);
		UpdateData(false);

  */
	
		
	}//if_else
}

void CStudentScoreDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	//保存当前编辑框内容
	int m;
	char str[20] = {'\0'};
	POSITION pos = m_List.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		//获取当前记录的位置游标
		m = m_List.GetNextSelectedItem(pos);

		UpdateData(true);  //将更新后的数据传给连接变量
		if(m_strNumber=="\0"||m_strName=="\0"||m_strSex=="\0"||m_strClass=="\0"||m_fScore0=='\0'||m_fScore1=='\0'||m_fScore2=='\0')
		{
			MessageBox("所有信息均不能为空！");
			return;
		}
		if(m_fScore0>100||m_fScore0<0||m_fScore1>100||m_fScore1<0||m_fScore2>100||m_fScore2<0)
		{
			MessageBox("成绩不能为负数或者大于100！");
			return;
		}

		m_List.DeleteItem(m);//删除原来的数据
		//将数据显示到列表控制框中
		m_List.InsertItem(m,m_strNumber);
		m_List.SetItemText(m,1,m_strName);
		m_List.SetItemText(m,2,m_strSex);
		m_List.SetItemText(m,3,m_strClass);
		char temp[10];
		gcvt(m_fScore0,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(m,4,temp);
		gcvt(m_fScore1,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(m,5,temp);
		gcvt(m_fScore2,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(m,6,temp);
		m_fSum = m_fScore0+m_fScore1+m_fScore2;
		gcvt(m_fSum,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(m,7,temp);
		m_fAverage = m_fSum/3.0;
		gcvt(m_fAverage,3,temp);//将浮点数转化为字符串
		m_List.SetItemText(m,8,temp);
		m_strNumber = m_strName = m_strSex = "\0";
		m_fScore0 = m_fScore1 = m_fScore2 = m_fSum = m_fAverage = '\0';
	}//if

	//写入文件
	int n = m_List.GetItemCount();
	int i = 0;
	StudentInfo Stu;
	if(m_strFileName.IsEmpty())
	{//指定待写入文件名
		CFileDialog dlg(false,"txt",NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"text file(*.txt)|*.txt",this);
		if(dlg.DoModal()!=IDOK)
		{
			return;
		}
		m_strFileName = dlg.GetPathName();
		m_strFileShortName = dlg.GetFileName();
	}//if

	FILE * fp;
	if((fp=fopen(m_strFileName,"wb"))==NULL)
	{
		MessageBox("文件无法打开");
		exit(0);
	}

	while(i<n)
	{
		CreateStudentInfo(i,Stu);//将列表控件的数据组成一个记录
		fwrite(&Stu,sizeof(StudentInfo),1,fp);//将记录写入文件
		i++;
	}

	m_strMessage = "所有信息已经保存到文件"+m_strFileShortName;
	UpdateData(false);
	fclose(fp);
	notSaved = 0;
}

void CStudentScoreDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//寻找当前选中的记录的位置
//	POSITION pos = m_List.GetFirstSelectedItemPosition();
//	if(pos = NULL) return;
//	i = m_List.GetNextSelectedItem(pos);//获取当前记录的位置游标
	for(int i=0;i<m_List.GetItemCount();i++)
	{
		if(m_List.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			char chTemp[20] = {'\0'};
			//将所选记录的数据放到编辑框中
			m_List.GetItemText(i,0,chTemp,sizeof(chTemp));
			m_strNumber = chTemp;
			m_List.GetItemText(i,1,chTemp,sizeof(chTemp));
			m_strName = chTemp;
			m_List.GetItemText(i,2,chTemp,sizeof(chTemp));
			m_strSex = chTemp;
			m_List.GetItemText(i,3,chTemp,sizeof(chTemp));
			m_strClass = chTemp;
			m_List.GetItemText(i,4,chTemp,sizeof(chTemp));
			m_fScore0 = atof(chTemp);
			m_List.GetItemText(i,5,chTemp,sizeof(chTemp));
			m_fScore1 = atof(chTemp);
			m_List.GetItemText(i,6,chTemp,sizeof(chTemp));
			m_fScore2 = atof(chTemp);
			m_List.GetItemText(i,7,chTemp,sizeof(chTemp));
			m_fSum = atof(chTemp);
			m_List.GetItemText(i,8,chTemp,sizeof(chTemp));
			m_fAverage = atof(chTemp);
			break;
		}//if
	}//for
	UpdateData(false);
	*pResult = 0;
}//CStudentScoreDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult)

void CStudentScoreDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	int n;
	char str[20] = {'\0'};
	POSITION pos = m_List.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{
		MessageBox("请先选中一条记录！");
		return;
	}
	//获取当前记录的位置游标
	n = m_List.GetNextSelectedItem(pos);
	

	UpdateData(true);  //将更新后的数据传给连接变量
	if(m_strNumber=="\0"||m_strName=="\0"||m_strSex=="\0"||m_strClass=="\0"||m_fScore0=='\0'||m_fScore1=='\0'||m_fScore2=='\0')
	{
		MessageBox("所有信息均不能为空！");
		return;
	}
	if(m_fScore0>100||m_fScore0<0||m_fScore1>100||m_fScore1<0||m_fScore2>100||m_fScore2<0)
	{
		MessageBox("成绩不能为负数或者大于100！");
		return;
	}

	m_List.DeleteItem(n);//删除原来的数据
	//将数据显示到列表控制框中
	m_List.InsertItem(n,m_strNumber);
	m_List.SetItemText(n,1,m_strName);
	m_List.SetItemText(n,2,m_strSex);
	m_List.SetItemText(n,3,m_strClass);
	char temp[10];
	gcvt(m_fScore0,3,temp);//将浮点数转化为字符串
	m_List.SetItemText(n,4,temp);
	gcvt(m_fScore1,3,temp);//将浮点数转化为字符串
	m_List.SetItemText(n,5,temp);
	gcvt(m_fScore2,3,temp);//将浮点数转化为字符串
	m_List.SetItemText(n,6,temp);
	m_fSum = m_fScore0+m_fScore1+m_fScore2;
	gcvt(m_fSum,3,temp);//将浮点数转化为字符串
	m_List.SetItemText(n,7,temp);
	m_fAverage = m_fSum/3.0;
	gcvt(m_fAverage,3,temp);//将浮点数转化为字符串
	m_List.SetItemText(n,8,temp);
	m_strNumber = m_strName = m_strSex = "\0";
	m_fScore0 = m_fScore1 = m_fScore2 = m_fSum = m_fAverage = '\0';
	m_strMessage = "请记得保存数据到文件"+m_strFileShortName+"中!";
	//自动保存方式
	/*
	StudentInfo Stu;
	CreateStudentInfo(n,Stu);
	FILE *fp;
	if((fp = fopen(m_strFileName,"rb+"))==NULL)
	{
		MessageBox("文件无法打开");
		exit(0);
	}
	fseek(fp,n*sizeof(StudentInfo),SEEK_SET);
	fwrite(&Stu,sizeof(StudentInfo),1,fp);
	m_strMessage = "信息修改成功";
	fclose(fp);

//	*/
	notSaved = 1;
	MessageBox("信息添加成功！");
	UpdateData(false);
	
}

void CStudentScoreDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	POSITION pos = m_List.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{
		MessageBox("请先选中一条记录！");
		return;
	}
	//获取当前记录的位置游标
	int n = m_List.GetNextSelectedItem(pos);
	m_List.DeleteItem(n);//删除原来的数据
	m_strNumber = m_strName = m_strSex = "\0";
	m_fScore0 = m_fScore1 = m_fScore2 = m_fSum = m_fAverage = '\0';	
	m_strMessage = "请记得保存数据到文件"+m_strFileShortName+"中!";
	UpdateData(false);
	MessageBox("信息删除成功！");
	notSaved = 1;

}//CStudentScoreDlg::OnButtonDelete()

void CStudentScoreDlg::OnButtonQueryok() 
{
	// TODO: Add your control notification handler code here
	int n = m_List.GetItemCount();
	int i = 0;
	int count = 0;
	if(m_strFileName.IsEmpty())
	{
		MessageBox("请先打开一个文件！");
		return;
	}
	if(n==0)
	{
		MessageBox("没有数据可以查询！");
		return;
	}

	UpdateData(true);
	POSITION pos;
	while((pos=m_List.GetFirstSelectedItemPosition())!=NULL)
	{
		int t = m_List.GetNextSelectedItem(pos);
		m_List.SetItemState(t,0,LVIS_SELECTED|LVIS_FOCUSED);//取消该行数据高亮显示
		m_List.SetFocus();
	}//while

	if(m_strQueryByNumber!="\0"&&m_strQueryByName!="\0")//按学号和姓名查询
	{
		while(i<n)
		{
			char Number[20] = {'\0'};
			char Name[20] = {'\0'};
			m_List.GetItemText(i,0,Number,sizeof(Number));
			m_List.GetItemText(i,1,Name,sizeof(Name));
			
			if(strcmp(m_strQueryByNumber,Number)==0 && strcmp(m_strQueryByName,Name)==0)
			{
				count++;
				m_List.SetItemState(i,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
				m_List.SetFocus();
			}//if
			i++;
		}//while_i
		m_strMessage.Format("共找到%d条记录",count);
		UpdateData(false);
		return;
	}//if_Number&&Name

	if(m_strQueryByNumber!="\0")//按学号查询
	{
		while(i<n)
		{
			char Number[20] = {'\0'};
			m_List.GetItemText(i,0,Number,sizeof(Number));
			
			if(strcmp(m_strQueryByNumber,Number)==0)
			{
				count++;
				m_List.SetItemState(i,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
				m_List.SetFocus();
			}//if
			i++;
		}//while_i
		m_strMessage.Format("共找到%d条记录",count);
		UpdateData(false);
		return;
	}//if_Number

	if(m_strQueryByName!="\0")//按姓名查询
	{
		while(i<n)
		{
			char Name[20] = {'\0'};
			m_List.GetItemText(i,1,Name,sizeof(Name));
			if(strcmp(m_strQueryByName,Name)==0)
			{
				count++;
				m_List.SetItemState(i,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
				m_List.SetFocus();
			}//if
			i++;
		}//while_i
		m_strMessage.Format("共找到%d条记录",count);
		UpdateData(false);
		return;
	}//if_Name
}//CStudentScoreDlg::OnButtonQueryok

void CStudentScoreDlg::OnButtonSortbytotaldown() 
{
	// TODO: Add your control notification handler code here
	int n = m_List.GetItemCount();
	int i = 0;

	if(m_strFileName.IsEmpty())
	{
		MessageBox("文件未打开！");
		return;
	}//if

	if(n==0)
	{
		MessageBox("没有数据可以排序！");
		return;
	}//if
	
	int m = INITIAL_SIZE;
	while(n>INITIAL_SIZE) m+=INITIAL_SIZE;
	StudentInfo Stu;
	StudentInfo * SortTemp = (StudentInfo *)malloc(sizeof(StudentInfo)*m);
	while(i<n)
	{
		CreateStudentInfo(i,Stu);
		SortTemp[i]=Stu;
		i++;
	}

	m_List.DeleteAllItems();

	//选择排序
	int j,k,temp;
	StudentInfo swap;
	for(j=0;j<n-1;j++)
	{
		temp = j;
		for(k = k+1;k<n;k++)
		{
			if(SortTemp[k].Sum>SortTemp[temp].Sum)
				temp = k;
		}//for
		if(temp!=j)
		{
			swap = SortTemp[j];
			SortTemp[j] = SortTemp[temp];
			 SortTemp[temp] = swap;
		}//if
	}//for

	i = 0;
	while(i<n)
	{
		MyInsertItem(i,&SortTemp[i]);
		i++;
	}//while

	UpdateData(false);
}//CStudentScoreDlg::OnButtonSortbytotaldown

void CStudentScoreDlg::OnButtonSortbytotalup() 
{
	// TODO: Add your control notification handler code here
	int n = m_List.GetItemCount();
	int i = 0;

	if(m_strFileName.IsEmpty())
	{
		MessageBox("文件未打开！");
		return;
	}//if

	if(n==0)
	{
		MessageBox("没有数据可以排序！");
		return;
	}//if
	
	int m = INITIAL_SIZE;
	while(n>INITIAL_SIZE) m+=INITIAL_SIZE;
	StudentInfo Stu;
	StudentInfo * SortTemp = (StudentInfo *)malloc(sizeof(StudentInfo)*m);

	while(i<n)
	{
		CreateStudentInfo(i,Stu);
		SortTemp[i]=Stu;
		i++;
	}

	m_List.DeleteAllItems();

	//选择排序
	int j,k,temp;
	StudentInfo swap;
	for(j=0;j<n-1;j++)
	{
		temp = j;
		for(k = k+1;k<n;k++)
		{
			if(SortTemp[k].Sum<SortTemp[temp].Sum)
				temp = k;
		}//for
		if(temp!=j)
		{
			swap = SortTemp[j];
			SortTemp[j] = SortTemp[temp];
			SortTemp[temp] = swap;
		}//if
	}//for

	i = 0;
	while(i<n)
	{
		MyInsertItem(i,&SortTemp[i]);
		i++;
	}//while

	UpdateData(false);
}//CStudentScoreDlg::OnButtonSortbytotalup

void CStudentScoreDlg::OnButtonSortbynumberdown() 
{
	// TODO: Add your control notification handler code here
	int n = m_List.GetItemCount();
	int i = 0;

	if(m_strFileName.IsEmpty())
	{
		MessageBox("文件未打开！");
		return;
	}//if

	if(n==0)
	{
		MessageBox("没有数据可以排序！");
		return;
	}//if
	
	int m = INITIAL_SIZE;
	while(n>INITIAL_SIZE) m+=INITIAL_SIZE;
	StudentInfo Stu;
	StudentInfo * SortTemp = (StudentInfo *)malloc(sizeof(StudentInfo)*m);

	while(i<n)
	{
		CreateStudentInfo(i,Stu);
		SortTemp[i]=Stu;
		i++;
	}

	m_List.DeleteAllItems();

	//选择排序
	int j,k,temp;
	StudentInfo swap;
	for(j=0;j<n-1;j++)
	{
		temp = j;
		for(k = k+1;k<n;k++)
		{
			if(strcmp(SortTemp[k].Number,SortTemp[temp].Number)>=0)
				temp = k;
		}//for
		if(temp!=j)
		{
			swap = SortTemp[j];
			SortTemp[j] = SortTemp[temp];
			SortTemp[temp] = swap;
		}//if
	}//for

	i = 0;
	while(i<n)
	{
		MyInsertItem(i,&SortTemp[i]);
		i++;
	}//while

	UpdateData(false);
}//CStudentScoreDlg::OnButtonSortbynumberdown

void CStudentScoreDlg::OnButtonSortbynumberup() 
{
	// TODO: Add your control notification handler code here
		int n = m_List.GetItemCount();
	int i = 0;

	if(m_strFileName.IsEmpty())
	{
		MessageBox("文件未打开！");
		return;
	}//if

	if(n==0)
	{
		MessageBox("没有数据可以排序！");
		return;
	}//if
	
	int m = INITIAL_SIZE;
	while(n>INITIAL_SIZE) m+=INITIAL_SIZE;
	StudentInfo Stu;
	StudentInfo * SortTemp = (StudentInfo *)malloc(sizeof(StudentInfo)*m);

	while(i<n)
	{
		CreateStudentInfo(i,Stu);
		SortTemp[i]=Stu;
		i++;
	}

	m_List.DeleteAllItems();

	//选择排序
	int j,k,temp;
	StudentInfo swap;
	for(j=0;j<n-1;j++)
	{
		temp = j;
		for(k = k+1;k<n;k++)
		{
			if(strcmp(SortTemp[k].Number,SortTemp[temp].Number)<0)
				temp = k;
		}//for
		if(temp!=j)
		{
			swap = SortTemp[j];
			SortTemp[j] = SortTemp[temp];
			SortTemp[temp] = swap;
		}//if
	}//for

	i = 0;
	while(i<n)
	{
		MyInsertItem(i,&SortTemp[i]);
		i++;
	}//while

	UpdateData(false);
}//CStudentScoreDlg::OnButtonSortbynumberup

void CStudentScoreDlg::MyInsertItem(int i,StudentInfo *Stu)
{
	m_List.InsertItem(i,Stu->Number);
	m_List.SetItemText(i,1,Stu->Name);
	m_List.SetItemText(i,2,Stu->Sex);
	m_List.SetItemText(i,3,Stu->Class);
	char temp[20];
	gcvt(Stu->Score[0],3,temp);  //将浮点数转换为字符串，保留三位有效数字
	m_List.SetItemText(i,4,temp);
	gcvt(Stu->Score[1],3,temp);  //将浮点数转换为字符串，保留三位有效数字
	m_List.SetItemText(i,5,temp);
	gcvt(Stu->Score[2],3,temp);  //将浮点数转换为字符串，保留三位有效数字
	m_List.SetItemText(i,6,temp);
	gcvt(Stu->Sum,3,temp);  //将浮点数转换为字符串，保留三位有效数字
	m_List.SetItemText(i,7,temp);
	gcvt(Stu->Average,3,temp);  //将浮点数转换为字符串，保留三位有效数字
	m_List.SetItemText(i,8,temp);
}
