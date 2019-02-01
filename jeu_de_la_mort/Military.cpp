#include "pch.h"
#include "Military.h"
#include "GameManager.h"
bool Military::CanUseEffect(Vector2 _v2NewPosition)
{
	return false;
}

void Military::UseEffect()
{
}

char Military::GetSprite()
{
	return 'M';
}

Military::Military(Vector2 _v2Position): Human()
{
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}

void Military::Reproduct(Vector2 _v2BabyPosition)
{
	new Military(_v2BabyPosition);
}
