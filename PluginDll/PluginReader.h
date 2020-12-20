#pragma once

#ifdef PLUGINREADER_EXPORTS
#define PLUGINREADER_API __declspec(dllexport)
#else
#define PLUGINREADER_API __declspec(dllimport)
#endif




typedef unsigned __int16   WORD; 
//typedef unsigned __int32   DWORD;

struct _TReaderPluginInfo
{
	char Name[256];             // ������ �����������
	char Description[256];      // �������� ������
	char Manufacturer[256];		// ������������� ������
	DWORD Capabilities;			// ����� �������������
	WORD wReserved;				// ����. ��������������� (%) = 180
	DWORD dwReserved;			// �� ������������
} TReaderPluginInfo;

void SaveLog(char* in);


	//_TReaderPluginInfo *PReaderPluginInfo;
	//��������� ���� ���������, �� ������� ������� ���������, ������� � ������.
	//PluginInfoPtr � ��������� �� ���������.
	//��� PreaderPluginInfo ����� ��������� �������� :
extern "C" PLUGINREADER_API void GetPluginInfo(_TReaderPluginInfo* PluginInfoPtr);
	//������������� �����������.
	//HApp � ����� �������� ���� ����������� ��,
	//ClientID � �� ������������.
	//���������� ������� ��������(0) ��� ���������(1) �������������
extern "C" PLUGINREADER_API int InitReader(void* HApp, WORD ClientID);
	//����������� �����������.
	//������ ���������� 0
extern "C" PLUGINREADER_API int DeinitReader();
	//������������ � ����� ���������� �����������.
	//������ ���������� 0
extern "C" PLUGINREADER_API int ReinitReader();
	//�������� ���������� �����������.
	//��������� ������������
extern "C" PLUGINREADER_API bool IsReaderActive();
	//��� PChar255 ����� �������� : char PChar255[256].
	//�� ������������.;
extern "C" PLUGINREADER_API void GetSetupDialogOptions(char* OptionsPtr);
	//�� ������������
extern "C" PLUGINREADER_API void ExecuteSetupDialogCommand(WORD CommandIndex);
	//������������� ����� ����������� �������������
extern "C" PLUGINREADER_API void SetOCRMode();
	//������������� ����� ����������� ������������
extern "C" PLUGINREADER_API void SetScanMode();
	//�� ������������
extern "C" PLUGINREADER_API void SetLED(DWORD Value);
	