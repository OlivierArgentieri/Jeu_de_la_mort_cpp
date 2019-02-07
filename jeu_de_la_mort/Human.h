#pragma once
#include "Humanoid.h"
#include "Zombie.h"

class Human : public Humanoid
{
private:
	bool m_is_infected_;
	int m_number_lap_infected_;
	int m_cpt_lap_infected_;
	int m_cpt_lap_reproduct_ =2; 

	const int m_lap_before_transform_ = 1;
public:
	virtual bool UseEffect(Vector2 _v2NewPosition) =0;
	std::string GetTag() override;
	void IncrementLapReproduct();
	int GetLapReproduct();
	void ResetLapReproduct();
	void PlayTurn(Vector2 _v2NewPosition) override;

	bool CanReproduct(Vector2 _v2SecondPosition);
	virtual void Reproduct(Vector2 _v2BabyPosition);
	void GetInfectedByZombie();
	virtual bool AmIinfected();
	void HealMe();
	Vector2 GetNearestEmptyPosition();
	void TransformToZombie();
	bool CanTransformToZombie();
	bool CanMove(Vector2 _v2NewPosition);
	void ProgressiveContamination();
};