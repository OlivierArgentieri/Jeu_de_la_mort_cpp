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

bool Zombie::CanEatHuman(Vector2 _v2NewPosition)
{
	Case* h = GetMap().GetCaseByPosition(_v2NewPosition);
	if (h != nullptr && h->GetTagOccupant() == "Human")
		return true;
	return false;
}

void Zombie::PlayTurn(Vector2 _v2NewPosition)
{
	if (this->CanEatHuman(_v2NewPosition))
	{
		Human* h = GetMap().GetCaseByPosition(_v2NewPosition)->GetHumanOccupant();
		h->GetInfectedByZombie();
	}
	// todo vir� le cast

}
