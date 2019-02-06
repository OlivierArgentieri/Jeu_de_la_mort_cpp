#include "pch.h"
#include "ZombieRandomMove.h"
#include "GameManager.h"

ZombieRandomMove::ZombieRandomMove(Vector2 _v2Position)
{
	SetSprite(new Sprite('Z', YELLOW));
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}
