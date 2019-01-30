#include "pch.h"
#include "Zombie.h"



bool Zombie::CanPlayTurn()
{
	// if human are present 
	return false;
}

void Zombie::PlayTurn()
{
	// todo transfrom human to zombie
	// test Collision
}

std::string Zombie::GetTag()
{
	return "Zombie";
}
