#include "pch.h"
#include "ZombieRandomMove.h"

ZombieRandomMove::ZombieRandomMove(Vector2 _v2Position)
{
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}
