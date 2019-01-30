#include "pch.h"
#include "Humanoid.h"

void Humanoid::Walk()
{
}

void Humanoid::TryTouch()
{
	if(CanTouch())
	{
		Touch();
	}
}