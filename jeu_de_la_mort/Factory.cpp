#include "pch.h"
#include "Factory.h"
#include <cstdlib>
#include "Human.h"
#include "Civil.h"
#include "Doctor.h"
#include "Military.h"

human Factory::GetRandomHumanEnum()
{
	return human(rand() % 3);
}

void Factory::CreateHuman(human _eHuman, Vector2 _v2Position)
{
	switch (_eHuman)
	{
	case CIVIL:
		new Civil(_v2Position);
		break;

	case DOCTOR:
		new Doctor(_v2Position);
		break;

	case MILITARY:
		new Military(_v2Position);

	default:
		break;
	}	
}

void Factory::InitiateRandomHuman(Vector2 _v2Position)
{
	if (_v2Position == -1)
		return;

	human h = Factory::GetRandomHumanEnum();
	Factory::CreateHuman(h, _v2Position);
}