#pragma once
#include "Vector2.h"

class Humanoid
{
public:
	virtual ~Humanoid() = default;
	virtual void Walk();

	void TriggerPlayTurn();
	virtual bool CanPlayTurn() = 0;
	virtual void PlayTurn() = 0;

	void SetPosition(Vector2 v2_value);
	Vector2 GetPosition();

private :
	Vector2 m_position_;
};
