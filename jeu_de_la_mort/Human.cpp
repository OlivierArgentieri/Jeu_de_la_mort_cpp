#include "pch.h"
#include "Human.h"

bool Human::CanTouch()
{
	return false;
}

void Human::Touch()
{
}

void Human::TryUseEffect()
{
	if(CanUseEffect())
	{
		UseEffect();
	}
}
