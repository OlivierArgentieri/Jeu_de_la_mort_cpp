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
}
