#include "pch.h"
#include "Game.h"
#include "GameManager.h"
#include <chrono>
#include <iostream>
#include "Util.h"


Game::Game(Vector2* _ptrSizeMap)
{
	GameManager::GetInstance()->RegisterGame(this);
	this->m_ptr_humanoids_ = new MyNewList<Humanoid*>();
	this->m_ptr_map_ = new Map(_ptrSizeMap);
	this->m_game_over_ = false;
}

Game::~Game()
{
	delete(m_ptr_humanoids_);
	delete(m_ptr_map_);
}

void Game::AddHumanoid(Humanoid* _ptrHumanoid)
{
	if (_ptrHumanoid == nullptr)
		return;

	_ptrHumanoid->SetMap(this->m_ptr_map_);

	if (m_ptr_humanoids_ != nullptr)
		m_ptr_humanoids_->PushBack(_ptrHumanoid);

	Case* temp = m_ptr_map_->GetCaseByPosition(_ptrHumanoid->GetPosition());

	if (temp != nullptr)
		temp->Enter(_ptrHumanoid);
}

void Game::DeleteHumanoid(Humanoid* _ptrHumanoid)
{
	// remove from list
	RemoveHumanoidFromList(_ptrHumanoid);

	// set nullptr in map
	Case* temp = m_ptr_map_->GetCaseByPosition(_ptrHumanoid->GetPosition());
	if (temp != nullptr)
		temp->Exit();
}

void Game::RemoveHumanoidFromList(Humanoid* _ptrHumanoid)
{
	for (int i = 0; i < this->m_ptr_humanoids_->Size(); i++)
	{
		Humanoid* ptr = this->m_ptr_humanoids_->At(i).operator*();
		if (ptr == _ptrHumanoid)
			this->m_ptr_humanoids_->EraseAt(this->m_ptr_humanoids_->At(i));
	}
}

Map Game::GetMap()
{
	return *this->m_ptr_map_;
}

void Game::DisplayMap()
{
	for (int y = 0; y < this->GetMap().GetSize().GetY(); y++)
	{
		for (int x = 0; x < this->GetMap().GetSize().GetX(); x++)
		{
			Util::SetCursorConsolePosition(Vector2(x, y));
			this->GetMap().GetCaseByPosition(Vector2(x, y))->GetSprite().Display();
		}
	}
}

void Game::DisplayATH()
{
	Util::SetCursorConsolePosition(GetMap().GetSize());
	std::cout << std::endl << "                     ";
	std::cout << std::endl << "                     ";

	Util::SetCursorConsolePosition(GetMap().GetSize());
	std::cout << std::endl << "Nb of human : " << GetAllHumans().Size();
	std::cout << std::endl << "Nb of Zombie : " << GetAllZombies().Size();

}

void Game::GameLoop()
{
	while (!m_game_over_)
	{
		TriggerAllPlayer();

		DisplayMap();

		DisplayATH();
		CheckGameOver();
	}
}

void Game::TriggerAllPlayer()
{
	for (int i = 0; i < this->m_ptr_humanoids_->Size(); i++)
	{
		Humanoid* ptr = m_ptr_humanoids_->At(i).operator*();
		ptr->TriggerPlayTurn();
	}
}

void Game::CheckGameOver()
{
	if (GetNumberOfInfectedHuman() == 0 && GetAllZombies().Size() == 0 || GetAllHumans().Size() == 0)
		this->m_game_over_ = true;
}

Humanoid* Game::GetHumanoidByPosition(Vector2 _v2Position)
{
	for (int i = 0; i < m_ptr_humanoids_->Size(); i++)
	{
		if (m_ptr_humanoids_->At(i).operator*()->GetPosition() == _v2Position)
			return m_ptr_humanoids_->At(i).operator*();
	}
	return nullptr;
}

int Game::GetNumberOfInfectedHuman()
{
	int toReturn = 0;
	for (int i = 0; i < this->m_ptr_humanoids_->Size(); i++)
	{
		if (this->m_ptr_humanoids_->At(i).operator*()->GetTag() == "Human" && static_cast<Human*>(this->m_ptr_humanoids_->At(i).operator*())->AmIinfected())
			toReturn++;
	}
	return toReturn;
}

MyNewList<Human*> Game::GetAllHumans()
{
	MyNewList<Human*> toReturn = MyNewList<Human*>();
	for (int i = 0; i < this->m_ptr_humanoids_->Size(); i++)
	{
		auto temp = this->m_ptr_humanoids_->At(i).operator*();
		if (temp->GetTag() == "Human")
			toReturn.PushBack(static_cast<Human*>(temp));
	}
	return toReturn;
}

MyNewList<Zombie*> Game::GetAllZombies()
{
	MyNewList<Zombie*> toReturn = MyNewList<Zombie*>();
	for (int i = 0; i < this->m_ptr_humanoids_->Size(); i++)
	{
		auto temp = this->m_ptr_humanoids_->At(i).operator*();
		if (temp->GetTag() == "Zombie")
			toReturn.PushBack(static_cast<Zombie*>(temp));
	}
	return toReturn;
}
