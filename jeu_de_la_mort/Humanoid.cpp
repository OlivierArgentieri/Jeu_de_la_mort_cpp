#include "pch.h"
#include "Humanoid.h"
#include "GameManager.h"

Vector2 Humanoid::GetMovePattern()
{
	// random walking
	int random = rand() % (4 + 1) + 1;

	Vector2 movePattern(0, 0);
	switch (random)
	{
	case 1:
		movePattern = Vector2(0, 1);
		break;

	case 2:
		movePattern = Vector2(1, 0);
		break;

	case 3:
		movePattern = Vector2(0, -1);
		break;

	case 4:
		movePattern = Vector2(-1, 0);
		break;
	}

	return movePattern;
}

void Humanoid::Move(Vector2 *_PtrNewPosition)
{

	// POSITION OK -> move
	m_ptr_map_->GetCaseByPosition(this->GetPosition())->Exit(); // liberate current case
	this->SetPosition(_PtrNewPosition);
	m_ptr_map_->GetCaseByPosition(this->GetPosition())->Enter(this);
}

Vector2* Humanoid::GetNewPosition(Vector2 _MovePattern)
{
	// todo 
	// move to new position

	// new position == nullptr si depassement ou impossible !!
	if (this->m_ptr_map_ == nullptr)
		return;

	auto newPosition = this->m_ptr_map_->FindExistingPosition(_MovePattern + this->GetPosition());

	if (newPosition == nullptr)
		return; // posotion invalide


	if (this->m_ptr_map_->GetCaseByPosition(*newPosition)->IsOccuped())
	{
		this->PlayTurn();
		// make test : if(tag == military) execute instant playTurn(); 
		// test range in military :]

		return; // todo make collision
	}

}

void Humanoid::TriggerPlayTurn()
{
	// get next position to go
	if (CanPlayTurn())
		PlayTurn();

	GetMovePattern();
}

void Humanoid::SetPosition(Vector2 *_ptrPosition)
{
	if (_ptrPosition == nullptr || _ptrPosition->GetX() < 0 || _ptrPosition->GetY() < 0)
		return;

	this->m_ptr_position_ = _ptrPosition;
}

void Humanoid::SetMap(Map* _ptrMap)
{
	if (_ptrMap == nullptr)
		return;
	m_ptr_map_ = _ptrMap;
}

Vector2 Humanoid::GetPosition()
{
	if (this->m_ptr_position_ == nullptr)
		return Vector2(-1, -1);

	return *this->m_ptr_position_;
}
