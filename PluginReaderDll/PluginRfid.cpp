#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <ctime> 
#include "PluginRfid.h"

void SaveLog(char* in)
{
	std::ofstream out("readerLog.txt", std::ios::app);

	if (out.is_open())
	{
		time_t rawtime;
		time(&rawtime); // ������� ���� � ��������
		out << ctime(&rawtime) << in << std::endl << std::endl;
	}
	out.close();
};
	//��������� ���� ���������, �� ������� ������� ���������, ������� � ������.
	//PluginInfoPtr � ��������� �� ���������.
void GetPluginInfo(_TReaderPluginInfo* PluginInfoPtr)
{
	strcpy_s(PluginInfoPtr->Name, "FintechR7024");
	strcpy_s(PluginInfoPtr->Description, "RFID ��� - 7024� Fintech");
	strcpy_s(PluginInfoPtr->Manufacturer, "Regula");
	PluginInfoPtr->Capabilities = 536870912;
	PluginInfoPtr->wReserved = 500;
	PluginInfoPtr->dwReserved = 3435973836;
	MessageBox(NULL, NULL, L"GetPluginInfo", MB_OK);
	//char logtext[] = "Calling function GetRfidPluginInfo";
	//SaveLog(logtext);

};

	//������������� �����������.
	//HApp � ����� �������� ���� ����������� ��,
	//ClientID � �� ������������.
	//���������� ������� ��������(0) ��� ���������(1) �������������
int InitReader(void* HApp, WORD ClientID)
{
	MessageBox(NULL, NULL, L"InitRfidReader", MB_OK);
	//char logtext[] = "Calling function InitRfidReader";
	//SaveLog(logtext);
	return 0;
};

	//����������� �����������.
	//������ ���������� 0
int DeinitReader()
{
	char logtext[] = "Calling function DeinitRfidReader";
	SaveLog(logtext);
	return 0;
};

//������������ � ����� ���������� �����������.
//������ ���������� 0
int ReinitReader()
{
	char logtext[] = "Calling function ReinitRfidReader";
	SaveLog(logtext);
	return 0;
};

//�� ������������;
void StartReader()
{
	char logtext[] = "Calling function StartRfidReader";
	SaveLog(logtext);
};

//�� ������������;
void StopReader() 
{
	char logtext[] = "Calling function StopRfidReader";
	SaveLog(logtext);
};

//��������� ������ �� ������������� ��
void ReadData() 
{
	char logtext[] = "Calling function ReadRfidReader";
	SaveLog(logtext);
};

//������������� ������������� ���������� ������ �� ������������� ��
void CancelReadData()
{
	char logtext[] = "Calling function CancelReadRfidReader";
	SaveLog(logtext);
};

	//��������� ����� ��� ������ ������, ���������� � ������� ��������� ���.
	//� �������� ����� ������ ������������ ������ ���, ����������� OCR
void SetBACKey()
{
	char logtext[] = "Calling function SetBACKeyRfidReader";
	SaveLog(logtext);
};
