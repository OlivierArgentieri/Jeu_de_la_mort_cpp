#pragma once
#include "Humanoid.h"

class Zombie : public Humanoid
{
public:
	std::string GetTag() override;
	char GetSprite() override;
	bool CanPlayTurn(Vector2 _v2NewPosition) override;
	void PlayTurn(Vector2 _v2NewPosition) override;
};