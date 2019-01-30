#pragma once
#include "Zombie.h"

class ZombieRandomMove : public Zombie
{
public:
	ZombieRandomMove(Vector2 _v2Position); 

	void Walk() override;
};
