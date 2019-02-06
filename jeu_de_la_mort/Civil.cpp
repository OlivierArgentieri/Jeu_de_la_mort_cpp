#include "pch.h"
#include "Civil.h"
#include "GameManager.h"

bool Civil::UseEffect(Vector2 _v2NewPosition)
{
	return false; // no action for civil
}

Civil::Civil(Vector2 _v2Position)
{
	SetSprite(new Sprite('C', WHITE));
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}
