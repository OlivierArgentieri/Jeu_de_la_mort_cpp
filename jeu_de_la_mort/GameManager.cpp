#include "pch.h"
#include "Humanoid.h"
#include "GameManager.h"

GameManager *GameManager::m_ptr_game_manager = nullptr;
GameManager::GameManager()
{
}

void GameManager::RegisterGame(Game* _ptr_game)
{
	this->m_ptr_game_ = _ptr_game;
}

void GameManager::RegisterHumanoid(Humanoid* _ptrHumanoid)
{
	if (m_ptr_game_ != nullptr && _ptrHumanoid !=  nullptr)
		m_ptr_game_->AddHumanoid(_ptrHumanoid);
}

Game GameManager::GetCurrentGame()
{
	return *this->m_ptr_game_;
}

Map GameManager::GetCurrentMap()
{
	return this->m_ptr_game_->GetMap();
}