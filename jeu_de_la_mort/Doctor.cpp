#include "pch.h"
#include "Doctor.h"

bool Doctor::CanUseEffect(Vector2 _v2NewPosition)
{
	
}

void Doctor::UseEffect(Vector2 _v2NewPosition)
{
	Case* c = GetMap().GetCaseByPosition(_v2NewPosition);
	if (c != nullptr && c->GetTagOccupant() == "Human" && c->GetHumanOccupant()->AmIinfected())
		c->GetHumanOccupant()->HealMe();

}

Doctor::Doctor(Vector2 _v2Position)
{
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}

char Doctor::GetSprite()
{
	return 'D';
}

void Doctor::Reproduct(Vector2 _v2BabyPosition)
{
	Human::Reproduct(_v2BabyPosition);
	new Doctor(_v2BabyPosition);
}