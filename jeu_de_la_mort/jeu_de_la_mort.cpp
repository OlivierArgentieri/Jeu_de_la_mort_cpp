// jeu_de_la_mort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Vector2.h"
#include "MyNewList.h"
#include "GameManager.h"
#include "Civil.h"

int main()
{
	Vector2 vector2;
	vector2.m_x = 1;
	vector2.m_y = 2;

	Vector2 size;
	size.m_x = 10;
	size.m_y = 10;
	Game *g = new Game(size);
	Humanoid *test = new Civil(vector2);



	std::cout << test->GetTag();
}
