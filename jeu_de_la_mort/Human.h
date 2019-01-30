#pragma once
#include "Humanoid.h"

class Human : public Humanoid
{
public:
	bool CanPlayTurn() override;
	void PlayTurn() override;

	void TriggerUseEffect();
	virtual bool CanUseEffect() =0;
	virtual void UseEffect() =0;

};
