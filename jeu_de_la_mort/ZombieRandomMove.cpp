#include "pch.h"
#include "ZombieRandomMove.h"

ZombieRandomMove::ZombieRandomMove(Vector2 _v2Position)
{
	GameManager::GetInstance()->RegisterHumanoid(this);
	this->SetPosition(_v2Position);
}

void ZombieRandomMove::Walk()
{
}