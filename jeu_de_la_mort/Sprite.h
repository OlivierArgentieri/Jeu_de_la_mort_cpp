#pragma once
#include "Color.h"

class Sprite
{
private:
	color m_color_;
	char m_char_;

public:
	Sprite(char _cChar = ' ', color _cColor = RESET);
	Sprite(const Sprite &_refSprite);
	void SetColor(color _cColor);
	void Display();
};