#pragma once
#include "EnumHuman.h"
#include "Human.h"
#include "ZombieEnum.h"

class Factory
{
public:
	static human GetRandomHumanEnum();
	static void CreateHuman(human _eHuman, Vector2 _v2Position);
	static void InitiateRandomHuman(Vector2 _v2Position);


	static zombie GetRandomZombieEnum();
	static void CreateZombie(zombie _eZombie, Vector2 _v2Position);
	static void InitiateRandomZombie(Vector2 _v2Position);
};
