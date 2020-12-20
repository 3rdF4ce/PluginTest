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
	char Name[256];             // Модель считывателя
	char Description[256];      // Описание модели
	char Manufacturer[256];		// Производитель модуля
	DWORD Capabilities;			// Флаги совместимости
	WORD wReserved;				// Коэф. Масштабирования (%) = 180
	DWORD dwReserved;			// Не используется
}TReaderPluginInfo;

void SaveLog(char* in);
	//Заполняет поля структуры, на которую передан указатель, данными о модуле.
	//PluginInfoPtr – указатель на структуру.
	//Тип PreaderPluginInfo имеет следующее описание :
extern "C" PLUGINRFIDREADER_API void GetPluginInfo(_TReaderPluginInfo * PluginInfoPtr);
	//Инициализация считывателя.
	//HApp – хэндл главного окна прикладного ПО,
	//ClientID – не используется.
	//Возвращает признак успешной(0) или аварийной(1) инициализации
extern "C" PLUGINRFIDREADER_API int InitReader(void* HApp, WORD ClientID);
	//Деактивация считывателя.
	//Всегда возвращает 0
extern "C" PLUGINRFIDREADER_API int DeinitReader();
	//Деактивирует и снова активирует считыватель.
	//Всегда возвращает 0
extern "C" PLUGINRFIDREADER_API int ReinitReader();
	//Не используется.;
extern "C" PLUGINRFIDREADER_API void StartReader();
	//Не используется.;
extern "C" PLUGINRFIDREADER_API void StopReader();
	//Считывает данные из бесконтактной ИС
extern "C" PLUGINRFIDREADER_API void ReadData();
	//Принудительно останавливает считывание данных из бесконтактной ИС
extern "C" PLUGINRFIDREADER_API void CancelRfidData();
	//Установка ключа для чтения данных, защищённых с помощью механизма ВАС.
	//В качестве ключа всегда используется строка МСЗ, прочитанная OCR
extern "C" PLUGINRFIDREADER_API void SetBACKey();


