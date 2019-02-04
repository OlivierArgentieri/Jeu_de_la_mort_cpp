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
	if (CanEatHuman(_v2NewPosition))
	{
		EatHuman(_v2NewPosition);
	}

	if (_v2NewPosition != -1 && !GetMap().GetCaseByPosition(_v2NewPosition)->IsOccuped())
		Move(_v2NewPosition);
}

void Zombie::KillMe()
{
	delete(this);
}

void Zombie::EatHuman(Vector2 _v2NewPosition)
{

	Human* h = GetMap().GetCaseByPosition(_v2NewPosition)->GetHumanOccupant(); // todo viré le cast
	h->GetInfectedByZombie();
}
