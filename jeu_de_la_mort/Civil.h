#pragma once
#include "GameManager.h"
#include "Adult.h"

class Civil : public Adult
{
public:
	bool UseEffect(Vector2 _v2NewPosition) override;
	Civil(Vector2 _v2Position);
};
