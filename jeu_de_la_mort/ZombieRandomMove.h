#pragma once
#include "Zombie.h"
#include "GameManager.h"


class ZombieRandomMove : public Zombie
{
public:
	ZombieRandomMove(Vector2 _v2Position);
	//bool CanPlayTurn(Vector2 _v2NewPosition) override;
	//void PlayTurn(Vector2 _v2NewPosition) override;
	//void Walk() override;
};