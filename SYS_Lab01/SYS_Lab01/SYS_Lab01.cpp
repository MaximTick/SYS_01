// SYS_Lab01.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "dll.h"
#include "My_DLL.h"
#include <iostream>
#include <conio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int x = PutInt(5);
	LetterList();
	std::cout << x<< std::endl;
	_getch();
	CreateStringandWrirteFile();
	CheckFile();
	_getch();
	StartProcess();
    return 0;
}

