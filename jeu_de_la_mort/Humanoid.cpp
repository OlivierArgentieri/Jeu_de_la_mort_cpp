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

void Humanoid::SetPosition(Vector2 *_ptrPosition)
{
	if (_ptrPosition->GetX() < 0 || _ptrPosition->GetY() < 0)
		return;

	this->m_ptr_position_ = _ptrPosition;
}

Vector2 Humanoid::GetPosition()
{
	if (this->m_ptr_position_ == nullptr)
		return Vector2(-1, -1);

	return *this->m_ptr_position_;
}
