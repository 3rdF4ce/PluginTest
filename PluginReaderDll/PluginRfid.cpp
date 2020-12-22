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
		time(&rawtime); // текущая дата в секундах
		out << ctime(&rawtime) << in << std::endl << std::endl;
	}
	out.close();
};
	//Заполняет поля структуры, на которую передан указатель, данными о модуле.
	//PluginInfoPtr – указатель на структуру.
void GetPluginInfo(_TReaderPluginInfo* PluginInfoPtr)
{
	strcpy_s(PluginInfoPtr->Name, "FintechR7024");
	strcpy_s(PluginInfoPtr->Description, "RFID СПВ - 7024М Fintech");
	strcpy_s(PluginInfoPtr->Manufacturer, "Regula");
	PluginInfoPtr->Capabilities = 536870912;
	PluginInfoPtr->wReserved = 500;
	PluginInfoPtr->dwReserved = 3435973836;
	MessageBox(NULL, NULL, L"GetPluginInfo", MB_OK);
	//char logtext[] = "Calling function GetRfidPluginInfo";
	//SaveLog(logtext);

};

	//Инициализация считывателя.
	//HApp – хэндл главного окна прикладного ПО,
	//ClientID – не используется.
	//Возвращает признак успешной(0) или аварийной(1) инициализации
int InitReader(void* HApp, WORD ClientID)
{
	MessageBox(NULL, NULL, L"InitRfidReader", MB_OK);
	//char logtext[] = "Calling function InitRfidReader";
	//SaveLog(logtext);
	return 0;
};

	//Деактивация считывателя.
	//Всегда возвращает 0
int DeinitReader()
{
	char logtext[] = "Calling function DeinitRfidReader";
	SaveLog(logtext);
	return 0;
};

//Деактивирует и снова активирует считыватель.
//Всегда возвращает 0
int ReinitReader()
{
	char logtext[] = "Calling function ReinitRfidReader";
	SaveLog(logtext);
	return 0;
};

//Не используется;
void StartReader()
{
	char logtext[] = "Calling function StartRfidReader";
	SaveLog(logtext);
};

//Не используется;
void StopReader() 
{
	char logtext[] = "Calling function StopRfidReader";
	SaveLog(logtext);
};

//Считывает данные из бесконтактной ИС
void ReadData() 
{
	char logtext[] = "Calling function ReadRfidReader";
	SaveLog(logtext);
};

//Принудительно останавливает считывание данных из бесконтактной ИС
void CancelReadData()
{
	char logtext[] = "Calling function CancelReadRfidReader";
	SaveLog(logtext);
};

	//Установка ключа для чтения данных, защищённых с помощью механизма ВАС.
	//В качестве ключа всегда используется строка МСЗ, прочитанная OCR
void SetBACKey()
{
	char logtext[] = "Calling function SetBACKeyRfidReader";
	SaveLog(logtext);
};
