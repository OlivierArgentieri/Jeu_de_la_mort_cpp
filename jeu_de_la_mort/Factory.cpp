#include "pch.h"
#include "Factory.h"
#include <cstdlib>
#include "Civil.h"
#include "Doctor.h"
#include "Military.h"
#include "ZombieRandomMove.h"
#include "ZombieExplode.h"

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


zombie Factory::GetRandomZombieEnum()
{
	return zombie(rand() % 2);
}


void Factory::CreateZombie(zombie _eZombie, Vector2 _v2Position)
{
	switch (_eZombie)
	{
	case ZOMBIE_RANDOM_MOVE:
		new ZombieRandomMove(_v2Position);
		break;

	case ZOMBIE_EXPLODE:
		new ZombieExplode(_v2Position);
		break;

	default:
		break;
	}
}

void Factory::InitiateRandomZombie(Vector2 _v2Position)
{
	if (_v2Position == -1)
		return;

	zombie z = Factory::GetRandomZombieEnum();
	Factory::CreateZombie(z, _v2Position);
}