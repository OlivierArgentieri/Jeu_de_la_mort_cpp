#include "pch.h"
#include "Vector2.h"

Vector2::Vector2(int _iX, int _iY)
{
	this->m_x = _iX;
	this->m_y = _iY;
}

int Vector2::GetX()
{
	if (this == nullptr)
		return-1;
	return m_x;
}

int Vector2::GetY()
{
	if (this == nullptr)
		return-1;
	return m_y;
}