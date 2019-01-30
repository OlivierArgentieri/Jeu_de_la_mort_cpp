#pragma once
#include "Human.h"

class Civil : public Human
{
public:
	bool CanUseEffect() override;
	void UseEffect() override;
	Civil(Vector2 _v2Position);
	char GetSprite() override;
};
