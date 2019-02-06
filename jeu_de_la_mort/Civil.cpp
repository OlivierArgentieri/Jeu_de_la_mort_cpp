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


void Civil::Reproduct(Vector2 _v2BabyPosition)
{
	Human::Reproduct(_v2BabyPosition);
	new Civil(_v2BabyPosition);
}
