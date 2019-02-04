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

void Humanoid::Move(Vector2 _v2NewPosition)
{

	if (_v2NewPosition.GetX() < 0 || _v2NewPosition.GetY() < 0 || _v2NewPosition.GetX() >= this->GetMap().GetSize().GetX() || _v2NewPosition.GetY() >= this->GetMap().GetSize().GetY())
		return;

	// POSITION OK -> move
	m_ptr_map_->GetCaseByPosition(this->GetPosition())->Exit(); // liberate current case
	this->SetPosition(_v2NewPosition);
	m_ptr_map_->GetCaseByPosition(this->GetPosition())->Enter(this);
}

Vector2 Humanoid::GetNewPosition(Vector2 _MovePattern)
{
	// new position == nullptr si depassement ou impossible !!
	if (this->m_ptr_map_ == nullptr)
		return Vector2();

	return this->m_ptr_map_->FindExistingPosition(_MovePattern + this->GetPosition());
}

void Humanoid::TriggerPlayTurn()
{
	auto newPosition = this->GetNewPosition(GetMovePattern());
	PlayTurn(newPosition);
}


void Humanoid::SetPosition(Vector2 _v2Position)
{
	if (_v2Position.GetX() < 0 || _v2Position.GetY() < 0)
		return;

	this->m_position_ = _v2Position;
}

void Humanoid::SetMap(Map* _ptrMap)
{
	if (_ptrMap == nullptr)
		return;
	m_ptr_map_ = _ptrMap;
}

Map Humanoid::GetMap()
{
	if (this->m_ptr_map_ == nullptr)
		return Map(nullptr);
	return *this->m_ptr_map_;
}

Vector2 Humanoid::GetPosition()
{
	return this->m_position_;
}

int Humanoid::GetRange()
{
	return this->m_range_;
}

void Humanoid::SetRange(int _iNewRange)
{
	if (_iNewRange <= 0)
		return;

	this->m_range_ = _iNewRange;
}

Humanoid::~Humanoid()
{
	GameManager::GetInstance()->RemoveHumanoid(this);
}
