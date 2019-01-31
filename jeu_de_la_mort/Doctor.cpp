#include "pch.h"
#include "Doctor.h"

bool Doctor::CanUseEffect()
{
	return false;
}

void Doctor::UseEffect()
{
}

Doctor::Doctor(Vector2 _v2Position)
{
	SetPosition(GameManager::GetInstance()->GetCurrentGame().GetMap().FindExistingPosition(_v2Position));
	GameManager::GetInstance()->RegisterHumanoid(this);
}


char Doctor::GetSprite()
{
	return 'D';
}
