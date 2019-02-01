#include "pch.h"
#include "Zombie.h"
#include "GameManager.h"


std::string Zombie::GetTag()
{
	return "Zombie";
}

char Zombie::GetSprite()
{
	return 'Z';
}

bool Zombie::CanPlayTurn(Vector2 _v2NewPosition)
{
	return GetMap().GetCaseByPosition(_v2NewPosition)->GetTagOccupant() == "Human";
}

void Zombie::PlayTurn(Vector2 _v2NewPosition)
{
	//manger l'humain

	// todo viré le cast
	//GameManager::GetInstance()->GetCurrentGame().
	
}