#pragma once
#include "Human.h"
#include "GameManager.h"

class Doctor : public Human
{
public:
	bool CanUseEffect() override;
	void UseEffect() override;

	Doctor(Vector2 _v2Position);
	char GetSprite() override;
};
