#pragma once
#include "Human.h"

class Doctor : public Human
{
public:
	bool CanUseEffect() override;
	void UseEffect() override;
};
