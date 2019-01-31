#include "pch.h"
#include "ZombieRandomMove.h"

ZombieRandomMove::ZombieRandomMove(Vector2 _v2Position)
{
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}

bool ZombieRandomMove::CanPlayTurn(Vector2 _v2NewPosition)
{
	return false;
}

void ZombieRandomMove::PlayTurn(Vector2 _v2NewPosition)
{
}