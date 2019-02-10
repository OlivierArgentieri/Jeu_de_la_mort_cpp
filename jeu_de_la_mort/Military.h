#pragma once
#include "Zombie.h"
#include "MyNewList.h"
#include "Adult.h"

class Military : public Adult
{
public:
	bool UseEffect(Vector2 _v2NewPosition) override;
	Military(Vector2 _v2Position);
	Zombie* GetOneZombieInMyRange();
	MyNewList<Zombie*> GetZombiesInMyRange();
};
