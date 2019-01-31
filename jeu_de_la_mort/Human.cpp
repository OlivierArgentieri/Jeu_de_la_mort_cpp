#include "pch.h"
#include "Human.h"


void Human::TriggerUseEffect()
{
	if(CanUseEffect())
	{
		UseEffect();
	}
}

std::string Human::GetTag()
{
	return "Human";
}

