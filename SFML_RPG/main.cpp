#include"stdafx.h"
#include"Game.h"
#include<Windows.h>
#include <conio.h>

#include <direct.h>
#include <string>
#include <limits.h>
#include <iostream>
using namespace std;



int main()
{


	Game game;
	
	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	game.run();

	system("pause");
	
	int c = getch();

	
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	cout << std::string(buf) + '\\';
	
	

	return 0;
}
