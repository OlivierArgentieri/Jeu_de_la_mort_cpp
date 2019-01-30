#include "pch.h"
#include "Game.h"

Game::Game()
{
	this->m_humanoids_ = new MyNewList<Humanoid*>();
}

void Game::AddHumanoid(Humanoid* _ptrHumanoid)
{
	if (m_humanoids_ != nullptr)
		m_humanoids_->PushBack(_ptrHumanoid);

	Case* temp = m_ptr_map->GetCaseByPosition(_ptrHumanoid->GetPosition());

	if (temp != nullptr)
		temp->m_ptr_humanoid = _ptrHumanoid;
}
