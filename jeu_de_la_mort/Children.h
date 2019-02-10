#pragma once
#include "Human.h"

class Children : public Human
{
private :
	int m_nb_lap_grow_;
public:
	Children(Vector2 _v2Position);
	void PlayTurn(Vector2 _v2NewPosition) override;
	bool UseEffect(Vector2 _v2NewPosition) override;
	bool ImAdult() override;
	bool CanGrow();
	void Grow();
	void IncrementGrowLapCount();
};

