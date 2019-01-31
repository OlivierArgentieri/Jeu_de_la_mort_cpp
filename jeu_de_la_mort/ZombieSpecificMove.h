#pragma once
#include "Zombie.h"
#include "GameManager.h"

class ZombieSpecificMove : public Zombie
{
public:
	Vector2 GetMovePattern() override;

};
