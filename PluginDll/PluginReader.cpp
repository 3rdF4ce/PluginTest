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
		time(&rawtime); // текущая дата в секундах
		out <<ctime(&rawtime)<<in<< std::endl << std::endl;
	}
	out.close();
};
//Заполняет поля структуры, на которую передан указатель, данными о модуле.
//PluginInfoPtr – указатель на структуру.
void GetPluginInfo(_TReaderPluginInfo* PluginInfoPtr)
{
	strcpy_s(PluginInfoPtr->Name, "R7024");
	strcpy_s(PluginInfoPtr->Description,"Считыватель паспортов и виз СПВ - 7024М Fintech");
	strcpy_s(PluginInfoPtr->Manufacturer, "FINTECH");
	PluginInfoPtr->Capabilities = 268439564;
	PluginInfoPtr->wReserved = 450;
	PluginInfoPtr->dwReserved = 3435973836;
	//MessageBox(NULL, NULL, L"PluginInfo", MB_OK);
	char logtext[] = "Calling function PluginInfo";
	SaveLog(logtext);
};

//Инициализация считывателя.
//HApp – хэндл главного окна прикладного ПО,
//ClientID – не используется.
//Возвращает признак успешной(0) или аварийной(1) инициализации
int InitReader(void* HApp, WORD ClientID) 
{
	
	//MessageBox(NULL, NULL, L"InitReader", MB_OK);
	char logtext[] = "Calling function: InitReader";
	SaveLog(logtext);
	return 0;
};

//Деактивация считывателя.
//Всегда возвращает 0
int DeinitReader()
{
	//MessageBox(NULL, NULL, L"DeinitReader", MB_OK);
	char logtext[] = "Calling function: DeinitReader";
	SaveLog(logtext);
	return 0;
};

//Деактивирует и снова активирует считыватель.
//Всегда возвращает 0
int ReinitReader() 
{ 
	//MessageBox(NULL, NULL, L"ReinitReader", MB_OK);
	char logtext[] = "Calling function: ReinitReader";
	SaveLog(logtext);
	return 0;
};

//Проверка активности считывателя.
//Выполняет сканирование
bool IsReaderActive() 
{ 
	//MessageBox(NULL, NULL, L"IsReaderActive", MB_OK);
	char logtext[] = "Calling function: IsReaderActive";
	SaveLog(logtext);
	return false;
};

//Тип PChar255 имеет описание : char PChar255[256].
//Не используется.;
void GetSetupDialogOptions(char* OptionsPtr) 
{
	char logtext[] = "Calling function: GetSetupDialogOptions";
	SaveLog(logtext);
	
};

//Не используется
void ExecuteSetupDialogCommand(WORD CommandIndex)
{
	char logtext[] = "Calling function: ExecuteSetupDialogCommand";
	SaveLog(logtext);
};

//Устанавливает режим оптического распознавания
void SetOCRMode() 
{
	//MessageBox(NULL, NULL, L"SetOCRMode", MB_OK);
	char logtext[] = "Calling function: SetOCRMode";
	SaveLog(logtext);
	
};

//Устанавливает режим оптического сканирования
void SetScanMode() 
{
	char logtext[] = "Calling function: SetScanMode";
	SaveLog(logtext);
	
};

//Не используется
void SetLED(DWORD Value) 
{
	char logtext[] = "Calling function: SetLED";
	SaveLog(logtext);
};
