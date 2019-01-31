#include "pch.h"
#include "ZombieSpecificMove.h"

Vector2 ZombieSpecificMove::GetMovePattern()
{
	return Vector2(0, 0);
	// todo
}

bool ZombieSpecificMove::CanPlayTurn(Vector2 _v2NewPosition)
{
	return false;
}

void ZombieSpecificMove::PlayTurn(Vector2 _v2NewPosition)
{
}