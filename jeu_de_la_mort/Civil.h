#pragma once
#include "Human.h"

class Civil : public Human
{
public:
	bool CanUseEffect() override;
	void UseEffect() override;
};
