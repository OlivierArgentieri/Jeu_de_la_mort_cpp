#pragma once
#include "Zombie.h"

class ZombieSpecificMove : public Zombie
{
public:
	void Walk() override;
};
