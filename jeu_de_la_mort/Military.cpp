#include "pch.h"
#include "Military.h"
#include "GameManager.h"
bool Military::CanUseEffect()
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

Military::Military(Vector2 _v2Position)
{
	SetPosition(GameManager::GetInstance()->GetCurrentGame().GetMap().FindExistingPosition(_v2Position));
	GameManager::GetInstance()->RegisterHumanoid(this);
}