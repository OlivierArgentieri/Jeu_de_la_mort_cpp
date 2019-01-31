#pragma once
#include "Zombie.h"
#include "GameManager.h"


class ZombieRandomMove : public Zombie
{
public:
	ZombieRandomMove(Vector2 _v2Position);
	bool CanPlayTurn() override;
	void PlayTurn() override;
	//void Walk() override;
};
