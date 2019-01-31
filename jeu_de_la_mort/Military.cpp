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

Military::Military(Vector2 _v2Position): Human()
{
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}

bool Military::CanPlayTurn(Vector2* _ptrNewPosition)
{
	return false;
}

void Military::PlayTurn(Vector2* _ptrNewPosition)
{
}
