#include "pch.h"
#include "Case.h"


void Case::SetPosition(Vector2 * _ptrPosition)
{
	if (_ptrPosition == nullptr || _ptrPosition->GetX() < 0 || _ptrPosition->GetY()< 0)
		return;

	this->m_ptr_position_ = _ptrPosition;
}

Case::Case(Vector2* _ptrPosition)
{
	this->SetPosition(_ptrPosition);
}

char Case::GetSprite()
{
	if (this->m_ptr_humanoid != nullptr)
		return this->m_ptr_humanoid->GetSprite();

	return ' ';
}
