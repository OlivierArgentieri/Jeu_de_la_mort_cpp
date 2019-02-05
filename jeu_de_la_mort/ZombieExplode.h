#pragma once
#include "Zombie.h"
#include "Node.h"
#include "Human.h"

class ZombieExplode : public Zombie
{
private:


public:
	~ZombieExplode();
	void Explode();
	MyNewList<Human*> GetHumanInMyRange();
	void InfectHuman(MyNewList<Human*> _lHumans);
	void KillMe() override;

	char GetSprite() override;
};
