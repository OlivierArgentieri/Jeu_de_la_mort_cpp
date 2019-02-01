#pragma once
#include "Human.h"

class Military : public Human
{
public:
	bool CanUseEffect(Vector2 _v2NewPosition) override;
	void UseEffect() override;
	char GetSprite() override;
	Military(Vector2 _v2Position);
	void Reproduct(Vector2 _v2BabyPosition) override;
};
