#include "pch.h"
#include "Doctor.h"

bool Doctor::CanUseEffect()
{
	return false;
}

void Doctor::UseEffect()
{
}

Doctor::Doctor(Vector2 _v2Position)
{
}

char Doctor::GetSprite()
{
	return 'D';
}
