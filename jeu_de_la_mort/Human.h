#pragma once
#include "Humanoid.h"

class Human : public Humanoid
{
private:
	bool m_is_infected_;
	int m_number_lap_infected_;
	int m_cpt_lap_infected_;
public:
	virtual bool CanUseEffect(Vector2 _v2NewPosition)=0;
	virtual void UseEffect(Vector2 _v2NewPosition)=0;

	std::string GetTag() override;
	void PlayTurn(Vector2 _v2NewPosition) override;

	bool CanReproduct(Vector2 _v2SecondPosition);
	virtual void Reproduct(Vector2 _v2BabyPosition) = 0;
	void GetInfectedByZombie();
	virtual bool AmIinfected();
	void HealMe();
	Vector2 GetNearestEmptyPosition(Vector2 _v2CurrentPosition);
};
