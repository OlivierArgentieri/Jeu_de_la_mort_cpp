// jeu_de_la_mort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Vector2.h"
#include "GameManager.h"
#include "Civil.h"
#include "Doctor.h"
#include "Military.h"
#include "ZombieRandomMove.h"
#include "ZombieExplode.h"



/* 
 * Humain :
 *		tous les humains peuvent se reproduire
 *	-> D : Doctor : Soigne les humains infecté
 *	-> M : Military : Tue les zombie sur une range, impossible au corps a corps.
 *	-> C : Civil 
 * 
 * Zombie : 
 *	-> E : Explosive Zombie : Ils infectent les humains present dans leur range en explosant
 *	-> Z : Zombie classique : Ils infectent les humains en les touchant au corps à corps
*/
int main()
{
	Vector2 *vector2 = new Vector2(15, 15);
	Game *g = new Game(vector2);
	Humanoid *test = new Civil(Vector2(0, 0));
	Humanoid *test1 = new Doctor(Vector2(1, 0));
	Humanoid *test2 = new Military(Vector2(2, 0));
	Humanoid *test3 = new ZombieRandomMove(Vector2(3, 10));
	Humanoid *test4 = new ZombieRandomMove(Vector2(4, 10));
	Humanoid *test5 = new ZombieRandomMove(Vector2(5, 10));
	Humanoid *test6 = new ZombieRandomMove(Vector2(6, 10));
	Humanoid *test7 = new ZombieExplode(Vector2(7, 10));
	Humanoid *test8 = new ZombieExplode(Vector2(8, 10));

	g->GameLoop();

	delete(g);
}
