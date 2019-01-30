#include "pch.h"
#include "Humanoid.h"
#include "GameManager.h"

GameManager *GameManager::m_ptr_game_manager = nullptr;

GameManager::GameManager()
{
}

void GameManager::RegisterHumanoid(Humanoid* _ptrHumanoid)
{
	if (m_ptr_game_ != nullptr && _ptrHumanoid !=  nullptr)
		m_ptr_game_->AddHumanoid(_ptrHumanoid);
}
