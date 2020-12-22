
// PluginTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "PluginTest.h"
#include "PluginTestDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPluginTestDlg dialog



CPluginTestDlg::CPluginTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLUGINTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPluginTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPluginTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INIT_READER, &CPluginTestDlg::OnBnClickedInitReader)
	ON_BN_CLICKED(IDC_DEINIT_READER, &CPluginTestDlg::OnBnClickedDeinitReader)
	ON_BN_CLICKED(IDC_IS_READER_ACTIVE, &CPluginTestDlg::OnBnClickedIsReaderActive)
	ON_BN_CLICKED(IDC_SETOCRMODE, &CPluginTestDlg::OnBnClickedSetocrmode)
	ON_BN_CLICKED(IDC_SETSCANMODE, &CPluginTestDlg::OnBnClickedSetscanmode)
	ON_BN_CLICKED(IDC_RE_INIT_READER, &CPluginTestDlg::OnBnClickedReInitReader)
	ON_BN_CLICKED(IDC_INIT_RFID_READER2, &CPluginTestDlg::OnBnClickedInitRfidReader)
	ON_BN_CLICKED(IDC_RE_INIT_RFID_READER, &CPluginTestDlg::OnBnClickedReInitRfidReader)
	ON_BN_CLICKED(IDC_DEINIT_RFID_READER2, &CPluginTestDlg::OnBnClickedDeinitRfidReader)
	ON_BN_CLICKED(IDC_GET_PLUGIN_INFO, &CPluginTestDlg::OnBnClickedGetPluginInfo)
	ON_BN_CLICKED(IDC_GETRFIDINFO, &CPluginTestDlg::OnBnClickedGetrfidinfo)
	ON_BN_CLICKED(IDC_READ_RFID_DATA, &CPluginTestDlg::OnBnClickedReadRfidData)
	ON_BN_CLICKED(IDC_CANCEL_READ_RFID_DATA, &CPluginTestDlg::OnBnClickedCancelReadRfidData)
	ON_BN_CLICKED(IDC_SET_BAC_KEY, &CPluginTestDlg::OnBnClickedSetBacKey)
END_MESSAGE_MAP()


// CPluginTestDlg message handlers

BOOL CPluginTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	GetPluginInfoDll = NULL;
	InitReaderDll = NULL;
	DeInitReaderDll = NULL;
	ReInitReaderDll = NULL;
	SetOCRModeDll = NULL;
	SetScanModeDll = NULL;
	IsReaderActiveDll = NULL;
	
	int Error = GetLastError();
	//Error = GetLastError();
	hDLL = LoadLibrary(_T("R7024.reader"));
	Error = GetLastError();
	if (hDLL)
	{
		
		GetPluginInfoDll = (GETPLUGININFO)GetProcAddress(hDLL, "GetPluginInfo");
		InitReaderDll = (INITREADER)GetProcAddress(hDLL, "InitReader");
		DeInitReaderDll = (DEINITREADER)GetProcAddress(hDLL, "DeinitReader");
		ReInitReaderDll = (REINITREADER)GetProcAddress(hDLL, "ReinitReader");
		SetOCRModeDll = (SETOCRMODE)GetProcAddress(hDLL, "SetOCRMode");
		SetScanModeDll = (SETSCANMODE)GetProcAddress(hDLL, "SetScanMode");
		IsReaderActiveDll = (ISREADERACTIVE)GetProcAddress(hDLL, "IsReaderActive");
		TRACE("DeinitReader: %x ReinitReader: %x SetOCRMode: %x SetScanMode: %x IsReaderActive: %x\n ", DeInitReaderDll, ReInitReaderDll, SetOCRModeDll, SetScanModeDll, IsReaderActiveDll);
		
	}
	else
	{
		AfxMessageBox(_T("Ошибка загрузки R7024.reader"));
		
	}

	hDLL = LoadLibrary(_T("R7024.rfid"));
	if (hDLL)
	{
		GetRfidPluginInfoDll = (GETRFIDPLUGININFO)GetProcAddress(hDLL, "GetPluginInfo");
		InitRfidReaderDll = (INITRFIDREADER)GetProcAddress(hDLL, "InitReader");
		DeInitRfidReaderDll = (DEINITRFIDREADER)GetProcAddress(hDLL, "DeinitReader");
		ReInitRfidReaderDll = (REINITRFIDREADER)GetProcAddress(hDLL, "ReinitReader");
		ReadRfidDataDll = (READRFIDDATA)GetProcAddress(hDLL, "ReadData");
		CancelReadRfidDataDll = (CANCELREADRFIDDATA)GetProcAddress(hDLL, "CancelReadData"); 
		SetRfidBACKeyDll = (SETRFIDBACKKEY)GetProcAddress(hDLL, "SetBACKey");
		TRACE("DeinitRfidReader: %x ReinitRfidReader: %x ReadRfidData: %x CancelReadRfidData: %x SetRfidBACKey: %x\n ", DeInitRfidReaderDll, ReInitRfidReaderDll, ReadRfidDataDll, CancelReadRfidDataDll, SetRfidBACKeyDll);

	}
	else
	{
		AfxMessageBox(_T("Ошибка загрузки R7024.rfid"));

	}


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPluginTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPluginTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.

HCURSOR CPluginTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
/// <summary>
/// //////////////////////////////////Reader Call
/// </summary>
void CPluginTestDlg::OnBnClickedGetPluginInfo()
{
	// TODO: Add your control notification handler code here
	_TReaderPluginInfo TRPI;
	_TReaderPluginInfo* pTRPI = &TRPI;
	try
	{
		if (GetPluginInfoDll == NULL)
			throw 123;
		GetPluginInfoDll(pTRPI);
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция GetPluginInfoDll не инициализирована!"));
	}

	
}


void CPluginTestDlg::OnBnClickedInitReader()
{
	// TODO: Add your control notification handler code here
	void* p = NULL;
	WORD w(0);
	int result(0);
	
	try
		{
			if (InitReaderDll == NULL)
				throw 123;
			if(!InitReaderDll(p, w))
				AfxMessageBox(_T("Считыватель инициализирован."));
		}
	catch(int i)
		{
			if(i == 123)
				AfxMessageBox(_T("Функция InitReaderDll не инициализирована!"));
		}
	
	//FreeLibrary(hDLL);
}
void CPluginTestDlg::OnBnClickedReInitReader()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (ReInitReaderDll == NULL)
			throw 123;
		ReInitReaderDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция ReInitReaderDll не инициализирована!"));
	}
}

void CPluginTestDlg::OnBnClickedDeinitReader()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (DeInitReaderDll == NULL)
			throw 123;
		DeInitReaderDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция DeInitReaderDll не инициализирована!"));
	}
	//FreeLibrary(hDLL);
}


void CPluginTestDlg::OnBnClickedIsReaderActive()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (IsReaderActiveDll == NULL)
			throw 123;
		IsReaderActiveDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция IsReaderActiveDll не инициализирована!"));
	}
}


void CPluginTestDlg::OnBnClickedSetocrmode()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (SetOCRModeDll == NULL)
			throw 123;
		SetOCRModeDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция SetOCRModeDll не инициализирована!"));
	}
}


void CPluginTestDlg::OnBnClickedSetscanmode()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (SetScanModeDll == NULL)
			throw 123;
		SetScanModeDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция SetScanModeDll не инициализирована!"));
	}
}




/////////////////////Rfid call
void CPluginTestDlg::OnBnClickedInitRfidReader()
{
	// TODO: Add your control notification handler code here
	void* p = NULL;
	WORD w(0);
	try
	{
		if (InitRfidReaderDll == NULL)
			throw 123;
		InitRfidReaderDll(p, w);
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция InitRfidReaderDll не инициализирована!"));
	}

}

void CPluginTestDlg::OnBnClickedGetrfidinfo()
{
	// TODO: Add your control notification handler code here
	_TReaderPluginInfo TRPI;
	_TReaderPluginInfo* pTRPI = &TRPI;
	
	try
	{
		if (GetRfidPluginInfoDll == NULL)
			throw 123;
		GetRfidPluginInfoDll(pTRPI);
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция GetRfidPluginInfoDll не инициализирована!"));
	}
	
}


void CPluginTestDlg::OnBnClickedReInitRfidReader()
{
	// TODO: Add your control notification handler code here
	ReInitRfidReaderDll();
	try
	{
		if (ReInitRfidReaderDll == NULL)
			throw 123;
		ReInitRfidReaderDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция ReInitRfidReaderDll не инициализирована!"));
	}
}



void CPluginTestDlg::OnBnClickedDeinitRfidReader()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (DeInitRfidReaderDll == NULL)
			throw 123;
		DeInitRfidReaderDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция DeInitRfidReaderDll не инициализирована!"));
	}
}


void CPluginTestDlg::OnBnClickedReadRfidData()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (ReadRfidDataDll == NULL)
			throw 123;
		ReadRfidDataDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция ReadRfidDataDll не инициализирована!"));
	}
}


void CPluginTestDlg::OnBnClickedCancelReadRfidData()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (CancelReadRfidDataDll == NULL)
			throw 123;
		CancelReadRfidDataDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция CancelReadRfidDataDll не инициализирована!"));
	}
	
}


void CPluginTestDlg::OnBnClickedSetBacKey()
{
	// TODO: Add your control notification handler code here
	try
	{
		if (SetRfidBACKeyDll == NULL)
			throw 123;
		SetRfidBACKeyDll();
	}
	catch (int i)
	{
		if (i == 123)
			AfxMessageBox(_T("Функция SetRfidBACKeyDll не инициализирована!"));
	}
}
