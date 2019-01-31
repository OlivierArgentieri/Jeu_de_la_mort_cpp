#include "pch.h"
#include "Game.h"
#include "GameManager.h"


Game::Game(Vector2* _ptrSizeMap)
{
	GameManager::GetInstance()->RegisterGame(this);
	this->m_humanoids_ = new MyNewList<Humanoid*>();
	this->m_ptr_map = new Map(_ptrSizeMap);
}

void Game::AddHumanoid(Humanoid* _ptrHumanoid)
{
	if (m_humanoids_ != nullptr)
		m_humanoids_->PushBack(_ptrHumanoid);

	Case* temp = m_ptr_map->GetCaseByPosition(_ptrHumanoid->GetPosition());

	if (temp != nullptr)
		temp->m_ptr_humanoid = _ptrHumanoid;
}

Map Game::GetMap()
{
	return *this->m_ptr_map;
}
