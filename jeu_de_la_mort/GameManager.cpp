#include "pch.h"
#include "Humanoid.h"
#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::RegisterHumanoid(Humanoid* _ptrHumanoid)
{
	if (m_ptr_game_ != nullptr)
		m_ptr_game_->AddHumanoid(_ptrHumanoid);
};