#pragma once
#include "Humanoid.h"
#include "Zombie.h"

class Human : public Humanoid
{
private:
	bool m_is_infected_;
	int m_number_lap_infected_;
	int m_cpt_lap_infected_;

	const int m_lap_before_transform_ = 2;
public:
	virtual bool UseEffect(Vector2 _v2NewPosition) = 0;
	void PlayTurn(Vector2 _v2NewPosition) override;
	virtual bool ImAdult() =0;
	void GetInfectedByZombie();
	virtual bool AmIinfected();
	void HealMe();
	void TransformToZombie();
	bool CanTransformToZombie();
	bool CanMove(Vector2 _v2NewPosition);
	void ProgressiveContamination();
};