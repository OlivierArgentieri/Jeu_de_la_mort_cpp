#pragma once
#include "Vector2.h"
#include "Humanoid.h"

class Case
{
private:
	void SetPosition(Vector2 *_ptrPosition);
	Humanoid *m_ptr_humanoid_;

public:
	Vector2 *m_ptr_position; // todo refactor
	
	Case(Vector2 *_ptrPosition);

	char GetSprite();
	bool IsOccuped();

	void Enter(Humanoid *_ptrHumanoid);
	void Exit();
};