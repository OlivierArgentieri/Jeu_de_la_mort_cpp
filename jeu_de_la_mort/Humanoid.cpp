#include "pch.h"
#include "Humanoid.h"

void Humanoid::Walk()
{
}

void Humanoid::TriggerPlayTurn()
{
	if (CanPlayTurn())
		PlayTurn();
}

void Humanoid::SetPosition(Vector2 _v2_value)
{
	if (_v2_value.m_x < 0 || _v2_value.m_y < 0)
		return;

	this->m_position_ = _v2_value;
}

Vector2 Humanoid::GetPosition()
{
	return this->m_position_;
}
