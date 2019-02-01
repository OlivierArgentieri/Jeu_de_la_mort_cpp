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

void Human::GetInfectedByZombie()
{
	this->m_is_infected_ = true;
}

bool Human::IAmInfected()
{
	return this->m_is_infected_;
}

