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

void Humanoid::SetPosition(Vector2 _v2Position)
{
	if (_v2Position.m_x < 0 || _v2Position.m_y < 0)
		return;

	this->m_position_ = _v2Position;
}

Vector2 Humanoid::GetPosition()
{
	return this->m_position_;
}
