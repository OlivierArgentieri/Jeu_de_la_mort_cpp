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

Vector2::Vector2()
{
	this->m_x = -1;
	this->m_y = -1;
}

Vector2 Vector2::operator+(Vector2 _v2Vector)
{
	return Vector2(this->GetX() + _v2Vector.GetX(), this->GetY() + _v2Vector.GetY());
}

bool Vector2::operator==(int _iValue)
{
	return this->m_x == _iValue && this->m_y == _iValue;
}
bool Vector2::operator==(Vector2 _v2Value)
{
	return this->m_x == _v2Value.GetX() && this->m_y == _v2Value.GetY();
}	
bool Vector2::operator!=(int _iValue)
{
	return !(this->operator==(_iValue));
}
