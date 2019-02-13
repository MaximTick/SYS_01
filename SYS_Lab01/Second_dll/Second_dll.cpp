// Second_dll.cpp: определяет экспортированные функции для приложения DLL.
//
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include "stdafx.h"
#include <iostream>
#include <string>

extern "C++" __declspec(dllexport) void WriteString(char * str)
{
	std::cin >> str;

	const char *fileName = "example.txt";
	FILE *file = fopen(fileName, "w");
	if (file)
	{
		char* mystring = str;
		bool result = fputs(mystring, file);
		if (!result)
			std::cout << "String was write in file" << std::endl;
	}
	else
	{
		std::cout << "No Acsess" << std::endl;
		fclose(file);		
	}

}


