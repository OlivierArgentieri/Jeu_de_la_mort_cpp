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
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}


char Doctor::GetSprite()
{
	return 'D';
}

bool Doctor::CanPlayTurn(Vector2 _v2NewPosition)
{	
	return false;
}

void Doctor::PlayTurn(Vector2 _v2NewPosition)
{
}
