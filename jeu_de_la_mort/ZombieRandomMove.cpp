#include "pch.h"
#include "ZombieRandomMove.h"

ZombieRandomMove::ZombieRandomMove(Vector2 _v2Position)
{
	SetPosition(GameManager::GetInstance()->GetCurrentGame().GetMap().FindExistingPosition(_v2Position));
	GameManager::GetInstance()->RegisterHumanoid(this);
}

bool ZombieRandomMove::CanPlayTurn()
{
	return false;
}

void ZombieRandomMove::PlayTurn()
{
}