#pragma once
#include "Humanoid.h"

class Zombie : public Humanoid
{
public:
	std::string GetTag() override;
	bool CanEatHuman(Vector2 _v2NewPosition);
	void PlayTurn(Vector2 _v2NewPosition) override;

	virtual void KillMe();
	void EatHuman(Vector2 _v2NewPosition);
	bool CanMove(Vector2 _v2NewPosition);
};