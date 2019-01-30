#pragma once
#include "Vector2.h"
#include "Humanoid.h"

class Case
{
private:
	Vector2 m_position_;

public:
	Humanoid *m_ptr_humanoid;
};
