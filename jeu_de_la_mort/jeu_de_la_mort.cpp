// jeu_de_la_mort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Vector2.h"
#include "MyNewList.h"
#include "GameManager.h"

int main()
{
	Vector2 vector2;
	vector2.m_x = 10;
	vector2.m_y = 15;

	std::cout << vector2.m_x << std::endl;
	std::cout << vector2.m_y;


	MyNewList<int> *l = new MyNewList<int>();

	l->PushBack(12);


	l->Size();
}
