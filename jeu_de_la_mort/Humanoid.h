#pragma once
#include "Vector2.h"
#include <string>

class Humanoid
{
public:
	virtual void Walk();

	void TriggerPlayTurn();
	virtual bool CanPlayTurn() = 0;
	virtual void PlayTurn() = 0;
	virtual std::string GetTag() = 0;

	void SetPosition(Vector2 v2_value);
	Vector2 GetPosition();

private :
	Vector2 m_position_;
};
