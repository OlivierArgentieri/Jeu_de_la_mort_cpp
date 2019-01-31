#pragma once
class Vector2
{
private:
	int m_x;
	int m_y;

public:
	Vector2(int _iX, int _iY);
	int GetX();
	int GetY();
	Vector2();
	Vector2 operator+(Vector2 _v2Vector);
};