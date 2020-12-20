
// PluginTestDlg.h : header file
//

#pragma once


// CPluginTestDlg dialog
class CPluginTestDlg : public CDialogEx
{
// Construction
public:
	CPluginTestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLUGINTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	struct _TReaderPluginInfo
	{
		char Name[256];             // Модель считывателя
		char Description[256];      // Описание модели
		char Manufacturer[256];		// Производитель модуля
		DWORD Capabilities;			// Флаги совместимости
		WORD wReserved;				// Коэф. Масштабирования (%) = 180
		DWORD dwReserved;			// Не используется
	} TReaderPluginInfo;
	
	typedef unsigned __int16   WORD;
	HINSTANCE hDLL;
	
	//плагин считывателя
	typedef int (WINAPI* GETPLUGININFO)(_TReaderPluginInfo*);
	GETPLUGININFO GetPluginInfoDll;
	typedef int (WINAPI* INITREADER)(void*,WORD);
	INITREADER InitReaderDll;
	typedef int (WINAPI* DEINITREADER)();
	DEINITREADER DeInitReaderDll;
	typedef int (WINAPI* REINITREADER)();
	REINITREADER ReInitReaderDll;
	typedef void (WINAPI* SETOCRMODE)();
	SETOCRMODE SetOCRModeDll;
	typedef void (WINAPI* SETSCANMODE)();
	SETSCANMODE SetScanModeDll;
	typedef bool (WINAPI* ISREADERACTIVE)();
	ISREADERACTIVE IsReaderActiveDll;
	
	//плагин RFID считывателя
	typedef int (WINAPI* GETRFIDPLUGININFO)(_TReaderPluginInfo*);
	GETRFIDPLUGININFO GetRfidPluginInfoDll;
	typedef int (WINAPI* INITRFIDREADER)(void*, WORD);
	INITRFIDREADER InitRfidReaderDll;
	typedef int (WINAPI* DEINITRFIDREADER)();
	DEINITRFIDREADER DeInitRfidReaderDll;
	typedef int (WINAPI* REINITRFIDREADER)();
	REINITRFIDREADER ReInitRfidReaderDll;
	typedef int (WINAPI* READRFIDDATA)();
	READRFIDDATA ReadRfidDataDll;
	typedef int (WINAPI* CANCELREADRFIDDATA)();
	CANCELREADRFIDDATA CancelReadRfidDataDll;
	typedef void (WINAPI* SETRFIDBACKKEY)();
	SETRFIDBACKKEY SetRfidBACKeyDll;
	

	
public:
	afx_msg void OnBnClickedInitReader();
	afx_msg void OnBnClickedDeinitReader();
	afx_msg void OnBnClickedIsReaderActive();
	afx_msg void OnBnClickedSetocrmode();
	afx_msg void OnBnClickedSetscanmode();
	afx_msg void OnBnClickedReInitReader();
	afx_msg void OnBnClickedInitRfidReader();
	afx_msg void OnBnClickedReInitRfidReader();
	afx_msg void OnBnClickedDeinitRfidReader();
	afx_msg void OnBnClickedGetPluginInfo();
	afx_msg void OnBnClickedGetrfidinfo();
	afx_msg void OnBnClickedReadRfidData();
	afx_msg void OnBnClickedCancelReadRfidData();
	afx_msg void OnBnClickedSetBacKey();
};
