#include "pch.h"
#include "Zombie.h"
#include "GameManager.h"
#include "Human.h"


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
	Case *h = GetMap().GetCaseByPosition(_v2NewPosition);
	if (h != nullptr && h->GetTagOccupant() == "Human")
		return true;
	return false;
}

void Zombie::PlayTurn(Vector2 _v2NewPosition)
{
	Human *h = GetMap().GetCaseByPosition(_v2NewPosition)->GetHumanOccupant();
	h->GetInfectedByZombie();
	//manger l'humain

	// todo viré le cast
	//GameManager::GetInstance()->GetCurrentGame().
	
}