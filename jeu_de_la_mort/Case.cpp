#include "pch.h"
#include "Case.h"


void Case::SetPosition(Vector2 * _ptrPosition)
{
	if (_ptrPosition == nullptr || _ptrPosition->GetX() < 0 || _ptrPosition->GetY()< 0)
		return;

	this->m_ptr_position = _ptrPosition;
}

Case::Case(Vector2* _ptrPosition)
{
	this->SetPosition(_ptrPosition);
}

Vector2 Case::GetPosition()
{
	if (this->m_ptr_position == nullptr)
		return Vector2();

	return *this->m_ptr_position;
}

char Case::GetSprite()
{
	if (this->IsOccuped())
		return this->m_ptr_humanoid_->GetSprite();

	return ' ';
}

bool Case::IsOccuped()
{
	return this->m_ptr_humanoid_ != nullptr;
}

void Case::Enter(Humanoid* _ptrHumanoid)
{
	if (_ptrHumanoid == nullptr)
		return;
	this->m_ptr_humanoid_ = _ptrHumanoid;
}

void Case::Exit()
{
	this->m_ptr_humanoid_ = nullptr;
}
