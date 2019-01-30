#pragma once
#include "Zombie.h"
#include "GameManager.h"

class ZombieSpecificMove : public Zombie
{
public:
	void Walk() override;
};
