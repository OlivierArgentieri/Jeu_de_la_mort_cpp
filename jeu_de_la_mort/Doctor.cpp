#include "pch.h"
#include "Doctor.h"

bool Doctor::CanUseEffect(Vector2 _v2NewPosition)
{
	Case* h = GetMap().GetCaseByPosition(_v2NewPosition);
	if (h != nullptr && h->GetTagOccupant() == "Human" && h->GetHumanOccupant()->AmIinfected())
		return true;
	return false;
}

void Doctor::UseEffect(Vector2 _v2NewPosition)
{
	Human *h = GetMap().GetCaseByPosition(_v2NewPosition)->GetHumanOccupant();

	if (h != nullptr)
		h->HealMe();
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