#pragma once
#include "Human.h"

class Military : public Human
{
public:
	bool CanUseEffect() override;
	void UseEffect() override;
	char GetSprite() override;
	Military(Vector2 _v2Position);
};
