#pragma once
#include "Human.h"
#include "Zombie.h"
#include "MyNewList.h"

class Military : public Human
{
public:
	bool UseEffect(Vector2 _v2NewPosition) override;
	char GetSprite() override;
	Military(Vector2 _v2Position);
	void Reproduct(Vector2 _v2BabyPosition) override;
	Zombie* GetOneZombieInMyRange();
	MyNewList<Zombie*> GetZombiesInMyRange();
};