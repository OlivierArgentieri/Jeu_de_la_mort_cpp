#pragma once
#include "Human.h"
#include "GameManager.h"

class Civil : public Human
{
public:
	bool CanUseEffect() override;
	void UseEffect() override;
	Civil(Vector2 _Position);
	char GetSprite() override;
};
