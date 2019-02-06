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
	std::cout <<std::endl<< "Nb of human : " << GetNumberOfHumanoidsByTag("Human");
	std::cout << std::endl<< "Nb of Zombie : " << GetNumberOfHumanoidsByTag("Zombie");

}

void Game::GameLoop()
{
	while (!m_game_over_)
	{
		TriggerAllPlayer();

		DisplayMap();


//		DisplayATH();
//		CheckGameOver();
	}
}

void Game::TriggerAllPlayer()
{
	for (int i = 0; i < this->m_ptr_humanoids_->Size(); i++)
	{
		Humanoid* ptr = this->m_ptr_humanoids_->At(i).operator*();
		ptr->TriggerPlayTurn();
	}
}

void Game::CheckGameOver()
{
	if (GetNumberOfInfectedHuman()==0 &&  GetNumberOfHumanoidsByTag("Zombie") == 0)
		this->m_game_over_ = true;
}

int Game::GetNumberOfHumanoidsByTag(std::string _sTag)
{
	int toReturn = 0;
	for (int i = 0; i < this->m_ptr_humanoids_->Size(); i++)
	{
		if (this->m_ptr_humanoids_->At(i).operator*()->GetTag() == _sTag)
			toReturn++;
	}

	return toReturn;
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