#pragma once
#include "Humanoid.h"

class Human : public Humanoid
{
private:
	bool m_is_infected_;
	int m_number_lap_infected_;
public:
	void TriggerUseEffect();
	virtual bool CanUseEffect()=0;
	virtual void UseEffect()=0;

	std::string GetTag() override;
	bool CanPlayTurn(Vector2 _v2NewPosition) override =0;
	void PlayTurn(Vector2 _v2NewPosition) override = 0;

	void GetInfectedByZombie();
	virtual bool IAmInfected();
};
