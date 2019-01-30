#include "pch.h"
#include "Human.h"

bool Human::CanPlayTurn()
{
	// todo put tryUseEffectHEre() ? 
	TriggerUseEffect();
	return false;
}

void Human::PlayTurn()
{
	// todo reproduction
}

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