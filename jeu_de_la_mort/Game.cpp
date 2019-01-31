#include "pch.h"
#include "Game.h"
#include "GameManager.h"
#include <chrono>
#include <iostream>


Game::Game(Vector2* _ptrSizeMap)
{
	GameManager::GetInstance()->RegisterGame(this);
	this->m_humanoids_ = new MyNewList<Humanoid*>();
	this->m_ptr_map = new Map(_ptrSizeMap);
	this->m_game_over_ = false;
}

void Game::AddHumanoid(Humanoid* _ptrHumanoid)
{
	if (m_humanoids_ != nullptr)
		m_humanoids_->PushBack(_ptrHumanoid);

	Case* temp = m_ptr_map->GetCaseByPosition(_ptrHumanoid->GetPosition());

	if (temp != nullptr)
		temp->Enter(_ptrHumanoid);
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
			printf("|%c", this->GetMap().GetCaseByPosition(Vector2(x, y))->GetSprite());
		std::cout << std::endl;
	}
}

void Game::GameLoop()
{
	while (!m_game_over_)
	{
		system("cls");





		this->DisplayMap();
	}
}