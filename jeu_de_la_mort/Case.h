#pragma once
#include "Vector2.h"
#include "Humanoid.h"

class Case
{
private:
	void SetPosition(Vector2 *_ptrPosition);

public:
	Vector2 *m_ptr_position_; // todo refactor
	Humanoid *m_ptr_humanoid;
	Case(Vector2 *_ptrPosition);
	char GetSprite();
};