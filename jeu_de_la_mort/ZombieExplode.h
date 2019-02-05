#pragma once
#include "Zombie.h"
#include "Node.h"
#include "Human.h"

class ZombieExplode : public Zombie
{
private:


public:
	ZombieExplode(Vector2 _v2Position, int _iRange);
	~ZombieExplode();
	void Explode();
	MyNewList<Human*> GetHumanInMyRange();
	void InfectHuman(MyNewList<Human*> _lHumans);
	void KillMe() override;

	char GetSprite() override;
};