#include "pch.h"
#include "Humanoid.h"
#include <ctime>
#include "GameManager.h"
#include <chrono>

void Humanoid::Walk()
{
	// random walking
	srand(time(NULL)); // Seed the time
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

	Move(movePattern);
}

void Humanoid::Move(Vector2 _v2MovePattern)
{
	// todo 
	// move to new position
	auto newPosition = GameManager::GetInstance()->GetCurrentMap().FindExistingPosition(_v2MovePattern + this->GetPosition());

	// new position == nullptr si depassement ou impossible !!
	if (this->_ptr_map_ == nullptr)
		return;

	// on retire le player de la case courrante
	_ptr_map_->GetCaseByPosition(this->GetPosition())->Exit(); // liberate current case
	this->SetPosition(newPosition); // on lui donne sa nouvelle position.
	_ptr_map_->GetCaseByPosition(this->GetPosition())->Enter(this); // liberate current case
	// vector player + pattern 
	// if depassement : osef 

}

void Humanoid::TriggerPlayTurn()
{
	if (CanPlayTurn())
		PlayTurn();
	else
		Walk();
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
	_ptr_map_ = _ptrMap;
}

Vector2 Humanoid::GetPosition()
{
	if (this->m_ptr_position_ == nullptr)
		return Vector2(-1, -1);

	return *this->m_ptr_position_;
}
