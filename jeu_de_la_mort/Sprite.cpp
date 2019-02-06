#include "pch.h"
#include "Sprite.h"
#include <iostream>

Sprite::Sprite(char _cChar, color _cColor)
{
	m_char_ = _cChar;
	SetColor(_cColor);
}

void Sprite::SetColor(color _cColor)
{
	m_color_ = _cColor;
}

void Sprite::Display()
{
	std::cout << "\033[" << m_color_<<"m" << m_char_ << "\033[" << RESET << "m";
}