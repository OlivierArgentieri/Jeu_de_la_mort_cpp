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
	/**/
	Vector2 *vector2 = new Vector2(10, 10);
	Game *g = new Game(vector2);
	Humanoid *test = new Civil(Vector2(20,0));
	
	auto c = test->GetSprite();

	std::cout << c;
}
