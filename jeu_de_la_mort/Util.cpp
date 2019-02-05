#include "pch.h"
#include "Util.h"
#include <windows.h>

void Util::SetCursorConsolePosition(Vector2 _v2Position)
{
	COORD pos = { _v2Position.GetX(), _v2Position.GetY() };
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, pos);
}
