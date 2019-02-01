#pragma once
#include "Zombie.h"
#include "GameManager.h"

class ZombieSpecificMove : public Zombie
{
public:
	Vector2 GetMovePattern() override;

	void PlayTurn(Vector2 _v2NewPosition) override;
};
