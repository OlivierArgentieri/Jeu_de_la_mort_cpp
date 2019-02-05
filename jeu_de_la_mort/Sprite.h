#pragma once
#include "Color.h"

class Sprite
{
private:
	color m_color_;
	char m_char_;

public:
	void SetColor(color _cColor);

	void Display();

};