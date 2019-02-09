#pragma once
#include "Human.h"

class Adult : public Human
{
private:
	int m_cpt_lap_reproduct_ = 2;

public :
	void IncrementLapReproduct();
	int GetLapReproduct();
	void ResetLapReproduct();
	bool CanReproduct(Vector2 _v2SecondPosition);
	virtual void Reproduct(Vector2 _v2BabyPosition);
	Vector2 GetNearestEmptyPosition();
	bool UseEffect(Vector2 _v2NewPosition) override;
};

