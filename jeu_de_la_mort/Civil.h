#pragma once
#include "Human.h"
#include "GameManager.h"

class Civil : public Human
{
public:
	bool UseEffect(Vector2 _v2NewPosition) override;
	Civil(Vector2 _v2Position);
	char GetSprite() override;
	void Reproduct(Vector2 _v2BabyPosition) override;
};
