#pragma once
#include "Zombie.h"
#include "Node.h"
#include "Human.h"

class ZombieExplode : public Zombie
{
private:


public:
	ZombieExplode(Vector2 _v2Position);
	~ZombieExplode();
	void Explode();
	MyNewList<Vector2*>* GetHumanInMyRange();
	void InfectHuman(MyNewList<Human*> _lHumans);
	void KillMe() override;
};