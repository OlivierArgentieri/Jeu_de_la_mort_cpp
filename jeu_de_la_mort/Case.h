#pragma once
#include "Vector2.h"
#include "Humanoid.h"

class Case
{
private:
	char m_char_;
	void SetPosition(Vector2 _v2Position);
public:
	Vector2 m_position_;
	Humanoid *m_ptr_humanoid;
	Case(Vector2 _v2Position);
	char GetSprite();
};