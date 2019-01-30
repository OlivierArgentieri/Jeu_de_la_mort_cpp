#include "pch.h"
#include "Civil.h"
#include "GameManager.h"

bool Civil::CanUseEffect()
{
	return false;
}

void Civil::UseEffect()
{
}

Civil::Civil(Vector2 _v2Position)
{
	GameManager::GetInstance()->RegisterHumanoid(this);
	this->SetPosition(_v2Position);
}
