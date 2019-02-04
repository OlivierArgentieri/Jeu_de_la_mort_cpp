#pragma once
#include "Human.h"
#include "Zombie.h"
#include "MyList.h"

class Military : public Human
{
public:
	bool CanUseEffect(Vector2 _v2NewPosition) override;
	void UseEffect(Vector2 _v2NewPosition) override;
	char GetSprite() override;
	Military(Vector2 _v2Position);
	void Reproduct(Vector2 _v2BabyPosition) override;
	Zombie* GetOneZombiePositionInMyRange();
	MyList<Zombie*>* GetZombiesInMyRange();
};
