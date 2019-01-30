#include "pch.h"
#include "Case.h"

void Case::SetPosition(Vector2 _v2Position)
{
	if (_v2Position.m_x < 0 || _v2Position.m_y < 0)
		return;

	this->m_position_ = _v2Position;
}

Case::Case(Vector2 _v2Position)
{
	this->SetPosition(_v2Position);
	this->m_char_ = ' ';
}

char Case::GetSprite()
{
	if (this->m_ptr_humanoid != nullptr)
		return this->m_ptr_humanoid->GetSprite();

	return this->m_char_;
}