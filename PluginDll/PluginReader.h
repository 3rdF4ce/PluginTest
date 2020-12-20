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
	char Name[256];             // Модель считывателя
	char Description[256];      // Описание модели
	char Manufacturer[256];		// Производитель модуля
	DWORD Capabilities;			// Флаги совместимости
	WORD wReserved;				// Коэф. Масштабирования (%) = 180
	DWORD dwReserved;			// Не используется
} TReaderPluginInfo;

void SaveLog(char* in);


	//_TReaderPluginInfo *PReaderPluginInfo;
	//Заполняет поля структуры, на которую передан указатель, данными о модуле.
	//PluginInfoPtr – указатель на структуру.
	//Тип PreaderPluginInfo имеет следующее описание :
extern "C" PLUGINREADER_API void GetPluginInfo(_TReaderPluginInfo* PluginInfoPtr);
	//Инициализация считывателя.
	//HApp – хэндл главного окна прикладного ПО,
	//ClientID – не используется.
	//Возвращает признак успешной(0) или аварийной(1) инициализации
extern "C" PLUGINREADER_API int InitReader(void* HApp, WORD ClientID);
	//Деактивация считывателя.
	//Всегда возвращает 0
extern "C" PLUGINREADER_API int DeinitReader();
	//Деактивирует и снова активирует считыватель.
	//Всегда возвращает 0
extern "C" PLUGINREADER_API int ReinitReader();
	//Проверка активности считывателя.
	//Выполняет сканирование
extern "C" PLUGINREADER_API bool IsReaderActive();
	//Тип PChar255 имеет описание : char PChar255[256].
	//Не используется.;
extern "C" PLUGINREADER_API void GetSetupDialogOptions(char* OptionsPtr);
	//Не используется
extern "C" PLUGINREADER_API void ExecuteSetupDialogCommand(WORD CommandIndex);
	//Устанавливает режим оптического распознавания
extern "C" PLUGINREADER_API void SetOCRMode();
	//Устанавливает режим оптического сканирования
extern "C" PLUGINREADER_API void SetScanMode();
	//Не используется
extern "C" PLUGINREADER_API void SetLED(DWORD Value);
	