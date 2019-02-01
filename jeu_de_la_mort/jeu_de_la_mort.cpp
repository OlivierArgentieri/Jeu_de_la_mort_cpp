// jeu_de_la_mort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Vector2.h"
#include "MyNewList.h"
#include "GameManager.h"
#include "Civil.h"
#include "Doctor.h"
#include "Military.h"
#include "ZombieRandomMove.h"

int main()
{
	/**/
	Vector2 *vector2 = new Vector2(20, 20);
	Game *g = new Game(vector2);
	Humanoid *test = new Civil(Vector2(0,0));
	Humanoid *test1 = new Doctor(Vector2(1,0));
	Humanoid *test2 = new Military(Vector2(2,0));
	Humanoid *test3 = new ZombieRandomMove(Vector2(3,0));


	g->GameLoop();
}
