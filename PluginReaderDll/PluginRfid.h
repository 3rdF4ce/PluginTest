#pragma once

#ifdef PLUGINRFIDREADER_EXPORTS
#define PLUGINRFIDREADER_API __declspec(dllexport)
#else
#define PLUGINRFIDREADER_API __declspec(dllimport)
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
}TReaderPluginInfo;

void SaveLog(char* in);
	//��������� ���� ���������, �� ������� ������� ���������, ������� � ������.
	//PluginInfoPtr � ��������� �� ���������.
	//��� PreaderPluginInfo ����� ��������� �������� :
extern "C" PLUGINRFIDREADER_API void GetPluginInfo(_TReaderPluginInfo * PluginInfoPtr);
	//������������� �����������.
	//HApp � ����� �������� ���� ����������� ��,
	//ClientID � �� ������������.
	//���������� ������� ��������(0) ��� ���������(1) �������������
extern "C" PLUGINRFIDREADER_API int InitReader(void* HApp, WORD ClientID);
	//����������� �����������.
	//������ ���������� 0
extern "C" PLUGINRFIDREADER_API int DeinitReader();
	//������������ � ����� ���������� �����������.
	//������ ���������� 0
extern "C" PLUGINRFIDREADER_API int ReinitReader();
	//�� ������������.;
extern "C" PLUGINRFIDREADER_API void StartReader();
	//�� ������������.;
extern "C" PLUGINRFIDREADER_API void StopReader();
	//��������� ������ �� ������������� ��
extern "C" PLUGINRFIDREADER_API void ReadData();
	//������������� ������������� ���������� ������ �� ������������� ��
extern "C" PLUGINRFIDREADER_API void CancelRfidData();
	//��������� ����� ��� ������ ������, ���������� � ������� ��������� ���.
	//� �������� ����� ������ ������������ ������ ���, ����������� OCR
extern "C" PLUGINRFIDREADER_API void SetBACKey();


