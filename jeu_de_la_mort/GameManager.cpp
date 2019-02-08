#include "pch.h"
#include "Humanoid.h"
#include "GameManager.h"
#include <ctime>
#include "Civil.h"
#include "Doctor.h"
#include "Military.h"
#include "ZombieRandomMove.h"
#include "ZombieExplode.h"

GameManager *GameManager::m_ptr_game_manager = nullptr;
GameManager::GameManager()
{
	srand(time(NULL)); // Seed the time
}

void GameManager::RegisterGame(Game* _ptr_game)
{
	this->m_ptr_game_ = _ptr_game;
}

void GameManager::RegisterHumanoid(Humanoid* _ptrHumanoid)
{
	if (m_ptr_game_ != nullptr && _ptrHumanoid != nullptr)
	{
		m_ptr_game_->AddHumanoid(_ptrHumanoid);;
	}
}

void GameManager::RemoveHumanoid(Humanoid* _ptrHumanoid)
{
	if (m_ptr_game_ != nullptr && _ptrHumanoid != nullptr)
	{
		m_ptr_game_->DeleteHumanoid(_ptrHumanoid);;
	}
}

Game* GameManager::GetCurrentGame()
{
	return this->m_ptr_game_; // todo copy
}


Humanoid* GameManager::GetHumanoidByPosition(Vector2 _v2Position)
{
	return m_ptr_game_->GetHumanoidByPosition(_v2Position);
}

void GameManager::InstantiateRandomHuman(Vector2 _v2Position)
{

	int r = rand() % (3);
	switch (r)
	{
	case 0:
		new Civil(_v2Position);
		break;

	case 1:
		new Doctor(_v2Position);
		break;

	case 2:
		new Military(_v2Position);
		break;

	}
}


void GameManager::InstantiateRandomZombieType(Vector2 _v2Position)
{
	int r = rand() % (2);
	if (r == 0)
		new ZombieRandomMove(_v2Position);
	else
		new ZombieExplode(_v2Position);
}
