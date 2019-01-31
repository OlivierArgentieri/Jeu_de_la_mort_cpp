#pragma once
#include "Zombie.h"
#include "GameManager.h"

class ZombieSpecificMove : public Zombie
{
public:
	Vector2 GetMovePattern() override;

	bool CanPlayTurn(Vector2* _ptrNewPosition) override;
	void PlayTurn(Vector2* _ptrNewPosition) override;
};
