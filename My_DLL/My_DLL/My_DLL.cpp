// My_DLL.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>


using namespace std;


extern "C++" __declspec(dllexport) void CreateStringandWrirteFile()
{
	setlocale(NULL, "RUS");
	char buf[50];
	cout << "Enter string for write file" << endl;
	fgets(buf, sizeof(buf), stdin);
	ofstream out;
	out.open("D:\\study3course\\6thsem\\SystemProgramming\\Labs\\string.txt");

	if (out.is_open()) {
		out << buf << endl;
	}
}

extern "C++" __declspec(dllexport) void StartProcess()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("notepad.exe");
	if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0,
		NULL, NULL, &cif, &pi)))
		std::wcout << "Error " << '\n';
}

extern "C++" __declspec(dllexport) void CheckFile()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	TCHAR directorySearch[] = TEXT("D:\\study3course\\6thsem\\SystemProgramming\\Labs\\string.txt\\*");
	TCHAR filesearch[] = TEXT("D:\\study3course\\6thsem\\SystemProgramming\\Labs\\string.txt");
	hFind = FindFirstFile(filesearch, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u.\n", GetLastError());
	}
	else
	{
		std::wcout << "Found: " << FindFileData.cFileName << '\n';
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			std::wcout << "Found: " << FindFileData.cFileName << '\n';
		}
		FindClose(hFind);

	}
}