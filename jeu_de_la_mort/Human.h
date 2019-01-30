#pragma once
#include "Humanoid.h"

class Human : public Humanoid
{
public:
	virtual ~Human() = default;
	bool CanTouch() override;
	void Touch() override;

	void TryUseEffect();
	virtual bool CanUseEffect() =0;
	virtual void UseEffect() =0;

};
