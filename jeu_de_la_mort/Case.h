#pragma once
#include "Vector2.h"
#include "Humanoid.h"
#include "Human.h"
#include "Zombie.h"

class Case
{
private:
	void SetPosition(Vector2 *_ptrPosition);
	Humanoid *m_ptr_humanoid_;
	Vector2 *m_ptr_position_; // todo refactor
public:
	
	Case(Vector2 *_ptrPosition);
	Vector2 GetPosition();

	Sprite GetSprite();
	bool IsOccuped();
	void Enter(Humanoid *_ptrHumanoid);
	void Exit();

	std::string GetTagOccupant();
	Human* GetHumanOccupant();
	Zombie* GetZombieOccupant();
};