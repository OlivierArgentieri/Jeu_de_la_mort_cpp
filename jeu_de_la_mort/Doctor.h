#pragma once
#include "GameManager.h"
#include "Adult.h"

class Doctor : public Adult
{
public:
	bool UseEffect(Vector2 _v2NewPosition) override;
	Doctor(Vector2 _v2Position);
};
