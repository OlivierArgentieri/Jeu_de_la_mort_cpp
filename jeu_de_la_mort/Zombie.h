#pragma once
#include "Humanoid.h"

class Zombie : public Humanoid
{
public:
	virtual ~Zombie() = default;
	bool CanTouch() override;
	void Touch() override;
};
