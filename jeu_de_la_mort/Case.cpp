#include "pch.h"
#include "Case.h"
#include "Human.h"
#include "Zombie.h"


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

Vector2 Case::GetPosition()
{
	if (this->m_ptr_position_ == nullptr)
		return Vector2();

	return *this->m_ptr_position_;
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

std::string Case::GetTagOccupant()
{
	if (this->m_ptr_humanoid_ == nullptr)
		return "";

	return this->m_ptr_humanoid_->GetTag();
}

Human* Case::GetHumanOccupant()
{
	if (this->m_ptr_humanoid_ != nullptr && this->m_ptr_humanoid_->GetTag() != "Human")
		return nullptr;

	return  static_cast<Human*>(this->m_ptr_humanoid_);
}


Zombie* Case::GetZombieOccupant()
{
	if (this->m_ptr_humanoid_ != nullptr && this->m_ptr_humanoid_->GetTag() != "Zombie")
		return nullptr;

	return  dynamic_cast<Zombie*>(this->m_ptr_humanoid_);
}