#include "pch.h"
#include "Civil.h"
#include "GameManager.h"

bool Civil::CanUseEffect(Vector2 _v2NewPosition)
{
	return false;
}

void Civil::UseEffect(Vector2 _v2NewPosition)
{
	
}

Civil::Civil(Vector2 _v2Position)
{
	
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}

char Civil::GetSprite()
{
	return 'C';
}

void Civil::Reproduct(Vector2 _v2BabyPosition)
{
	Human::Reproduct(_v2BabyPosition);
	new Civil(_v2BabyPosition);
}
