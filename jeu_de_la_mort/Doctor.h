#pragma once
#include "Human.h"

class Doctor : public Human
{
public:
	bool CanUseEffect() override;
	void UseEffect() override;

	Doctor(Vector2 _v2Position);
};
