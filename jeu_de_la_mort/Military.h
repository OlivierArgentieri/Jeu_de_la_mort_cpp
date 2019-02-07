#pragma once
#include "Human.h"
#include "Zombie.h"
#include "MyNewList.h"

class Military : public Human
{
public:
	bool UseEffect(Vector2 _v2NewPosition) override;
	Military(Vector2 _v2Position);
	Zombie* GetOneZombieInMyRange();
	MyNewList<Vector2*>* GetZombiesInMyRange();
};