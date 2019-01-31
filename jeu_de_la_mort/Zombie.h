#pragma once
#include "Humanoid.h"

class Zombie : public Humanoid
{
public:
	std::string GetTag() override;
	char GetSprite() override;
};