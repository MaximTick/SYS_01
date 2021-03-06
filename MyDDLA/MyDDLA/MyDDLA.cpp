// MyDDLA.cpp: определяет экспортированные функции для приложения DLL.
//
#pragma warning(disable: 4996)
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <ctime>
extern "C" __declspec(dllexport) int __stdcall AddNumbers(int x, int y)
{
	return x + y;
}


extern "C" __declspec(dllexport) void __stdcall printBuildDateTime()
{
	printf(__TIMESTAMP__);
}

extern "C" __declspec(dllexport) void __stdcall CurrentTime()
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds); //locltime() преобразует число секунд типв time_t в структуру типа tm
	printf(asctime(timeinfo)); // astime преобразует в читаем вид в тип char*
}

