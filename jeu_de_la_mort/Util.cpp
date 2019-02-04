#include "pch.h"
#include "Util.h"
#include <windows.h>
#include <iostream>

void Util::SetCursorConsolePosition(Vector2 _v2Position, char _cContent)
{
	COORD pos = { _v2Position.GetX(), _v2Position.GetY() };
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, pos);
	std::cout << _cContent;
}
