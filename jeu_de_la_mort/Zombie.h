#pragma once
#include "Humanoid.h"

class Zombie : public Humanoid
{
public:
	bool CanPlayTurn() override;
	void PlayTurn() override;
	std::string GetTag() override;
	char GetSprite() override;

};