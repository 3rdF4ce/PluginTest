#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <ctime> 
#include "PluginReader.h"

void SaveLog(char* in)
{
	std::ofstream out("readerLog.txt", std::ios::app);
	
	if (out.is_open())
	{
		time_t rawtime;
		time(&rawtime); // ������� ���� � ��������
		out <<ctime(&rawtime)<<in<< std::endl << std::endl;
	}
	out.close();
};
//��������� ���� ���������, �� ������� ������� ���������, ������� � ������.
//PluginInfoPtr � ��������� �� ���������.
void GetPluginInfo(_TReaderPluginInfo* PluginInfoPtr)
{
	strcpy_s(PluginInfoPtr->Name, "R7024");
	strcpy_s(PluginInfoPtr->Description,"����������� ��������� � ��� ��� - 7024� Fintech");
	strcpy_s(PluginInfoPtr->Manufacturer, "FINTECH");
	PluginInfoPtr->Capabilities = 268439564;
	PluginInfoPtr->wReserved = 450;
	PluginInfoPtr->dwReserved = 3435973836;
	//MessageBox(NULL, NULL, L"PluginInfo", MB_OK);
	char logtext[] = "Calling function PluginInfo";
	SaveLog(logtext);
};

//������������� �����������.
//HApp � ����� �������� ���� ����������� ��,
//ClientID � �� ������������.
//���������� ������� ��������(0) ��� ���������(1) �������������
int InitReader(void* HApp, WORD ClientID) 
{
	
	//MessageBox(NULL, NULL, L"InitReader", MB_OK);
	char logtext[] = "Calling function: InitReader";
	SaveLog(logtext);
	return 0;
};

//����������� �����������.
//������ ���������� 0
int DeinitReader()
{
	//MessageBox(NULL, NULL, L"DeinitReader", MB_OK);
	char logtext[] = "Calling function: DeinitReader";
	SaveLog(logtext);
	return 0;
};

//������������ � ����� ���������� �����������.
//������ ���������� 0
int ReinitReader() 
{ 
	//MessageBox(NULL, NULL, L"ReinitReader", MB_OK);
	char logtext[] = "Calling function: ReinitReader";
	SaveLog(logtext);
	return 0;
};

//�������� ���������� �����������.
//��������� ������������
bool IsReaderActive() 
{ 
	//MessageBox(NULL, NULL, L"IsReaderActive", MB_OK);
	char logtext[] = "Calling function: IsReaderActive";
	SaveLog(logtext);
	return false;
};

//��� PChar255 ����� �������� : char PChar255[256].
//�� ������������.;
void GetSetupDialogOptions(char* OptionsPtr) 
{
	char logtext[] = "Calling function: GetSetupDialogOptions";
	SaveLog(logtext);
	
};

//�� ������������
void ExecuteSetupDialogCommand(WORD CommandIndex)
{
	char logtext[] = "Calling function: ExecuteSetupDialogCommand";
	SaveLog(logtext);
};

//������������� ����� ����������� �������������
void SetOCRMode() 
{
	//MessageBox(NULL, NULL, L"SetOCRMode", MB_OK);
	char logtext[] = "Calling function: SetOCRMode";
	SaveLog(logtext);
	
};

//������������� ����� ����������� ������������
void SetScanMode() 
{
	char logtext[] = "Calling function: SetScanMode";
	SaveLog(logtext);
	
};

//�� ������������
void SetLED(DWORD Value) 
{
	char logtext[] = "Calling function: SetLED";
	SaveLog(logtext);
};
