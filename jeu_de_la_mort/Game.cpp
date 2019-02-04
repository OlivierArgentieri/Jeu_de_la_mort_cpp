#include "pch.h"
#include "Game.h"
#include "GameManager.h"
#include <chrono>
#include <iostream>
#include "Util.h"


Game::Game(Vector2* _ptrSizeMap)
{
	GameManager::GetInstance()->RegisterGame(this);
	this->m_ptr_humanoids_ = new MyList<Humanoid*>();
	this->m_ptr_map = new Map(_ptrSizeMap);
	this->m_game_over_ = false;
}

void Game::AddHumanoid(Humanoid* _ptrHumanoid)
{
	if (_ptrHumanoid == nullptr)
		return;

	_ptrHumanoid->SetMap(this->m_ptr_map);

	if (m_ptr_humanoids_ != nullptr)
		m_ptr_humanoids_->push_back(_ptrHumanoid);

	Case* temp = m_ptr_map->GetCaseByPosition(_ptrHumanoid->GetPosition());

	if (temp != nullptr)
		temp->Enter(_ptrHumanoid);
}
void Game::DeleteHumanoid(Humanoid* _ptrHumanoid)
{
	// remove from list
	RemoveHumanoidFromList(_ptrHumanoid);

	// set nullptr in map
	Case* temp = m_ptr_map->GetCaseByPosition(_ptrHumanoid->GetPosition());
	if (temp != nullptr)
		temp->Exit();
}

void Game::RemoveHumanoidFromList(Humanoid *_ptrHumanoid)
{
	for (int i = 0; i < this->m_ptr_humanoids_->get_size(); i++)
	{
		Humanoid *ptr  = this->m_ptr_humanoids_->element_at(i);
		if (ptr == _ptrHumanoid)
			this->m_ptr_humanoids_->erase(this->m_ptr_humanoids_->begin().element_at(i));

	}
}

Map Game::GetMap()
{
	return *this->m_ptr_map;
}

void Game::DisplayMap()
{
	for (int y = 0; y < this->GetMap().GetSize().GetY(); y++)
	{
		for (int x = 0; x < this->GetMap().GetSize().GetX(); x++)
			Util::SetCursorConsolePosition(Vector2(x, y), this->GetMap().GetCaseByPosition(Vector2(x, y))->GetSprite());
			//printf("|%c", this->GetMap().GetCaseByPosition(Vector2(x, y))->GetSprite());
		//std::cout << std::endl;
	}
}

void Game::GameLoop()
{
	while (!m_game_over_)
	{
		//system("cls");
		this->TriggerAllPlayer();


		this->DisplayMap();

		//CheckGameOver();
	}
}

void Game::TriggerAllPlayer()
{
	for(int i =0; i< this->m_ptr_humanoids_->get_size(); i++)
	{
		Humanoid *ptr = this->m_ptr_humanoids_->element_at(i);
		ptr->TriggerPlayTurn();
	}
}

void Game::CheckGameOver()
{
	this->m_game_over_ = this->m_ptr_humanoids_->get_size() == this->m_ptr_map->GetSize().GetX() * this->m_ptr_map->GetSize().GetY();
}