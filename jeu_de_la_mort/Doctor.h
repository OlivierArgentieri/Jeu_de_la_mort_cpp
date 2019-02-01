#pragma once
#include "Human.h"
#include "GameManager.h"

class Doctor : public Human
{
public:
	bool CanUseEffect(Vector2 _v2NewPosition) override;
	void UseEffect() override;
	Doctor(Vector2 _v2Position);
	char GetSprite() override;
	void Reproduct(Vector2 _v2BabyPosition) override;
};
