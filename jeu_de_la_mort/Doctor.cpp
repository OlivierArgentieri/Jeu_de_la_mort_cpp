#include "pch.h"
#include "Doctor.h"

bool Doctor::UseEffect(Vector2 _v2NewPosition)
{
	Case* c = GetMap().GetCaseByPosition(_v2NewPosition);
	if (c != nullptr && c->GetTagOccupant() == "Human" && c->GetHumanOccupant()->AmIinfected())
	{
		c->GetHumanOccupant()->HealMe();
		return true;
	}

	return false;
}

Doctor::Doctor(Vector2 _v2Position)
{

	SetSprite(new Sprite('D', WHITE));
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}


void Doctor::Reproduct(Vector2 _v2BabyPosition)
{
	Human::Reproduct(_v2BabyPosition);
	new Doctor(_v2BabyPosition);
}