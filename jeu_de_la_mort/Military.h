#pragma once
#include "Human.h"

class Military : public Human
{
public:
	bool CanUseEffect() override;
	void UseEffect() override;
	char GetSprite() override;
	Military(Vector2 _v2Position);
	bool CanPlayTurn(Vector2* _ptrNewPosition) override;
	void PlayTurn(Vector2* _ptrNewPosition) override;
};
