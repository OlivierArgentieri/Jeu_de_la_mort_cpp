#pragma once
class Vector2
{
private:
	int m_x;
	int m_y;

public:
	Vector2(int _iX, int _iY);// todo 
	Vector2(const Vector2 &_ptrVector);
	int GetX();
	int GetY();
	Vector2();
	Vector2 operator+(Vector2 _v2Vector);
	Vector2 operator-(Vector2 _v2Vector);
	bool operator==(int _iValue);
	bool operator==(Vector2 _v2Vector);
	bool operator!=(int _iValue);
	bool operator!=(Vector2 _v2Value);
};