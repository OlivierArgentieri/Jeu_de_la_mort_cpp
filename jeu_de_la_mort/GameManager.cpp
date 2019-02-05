#include "pch.h"
#include "Humanoid.h"
#include "GameManager.h"
#include <ctime>

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

Game GameManager::GetCurrentGame()
{
	return *this->m_ptr_game_;
}

Map GameManager::GetCurrentMap()
{
	return this->m_ptr_game_->GetMap();
}