#include "pch.h"
#include "Doctor.h"

bool Doctor::UseEffect(Vector2 _v2NewPosition)
{
	Case* c = GetMap().GetCaseByPosition(_v2NewPosition);
	if (c != nullptr && c->GetTagOccupant() == "Human" && c->GetAdultOccupant()!= nullptr && c->GetAdultOccupant()->AmIinfected())
	{
		c->GetAdultOccupant()->HealMe();
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