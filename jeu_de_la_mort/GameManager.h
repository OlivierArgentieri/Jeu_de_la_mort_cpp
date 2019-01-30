#pragma once
#include "Humanoid.h"
#include "Map.h"
#include "Game.h"

class GameManager
{
private:
	static GameManager * m_ptr_game_manager;
	Map* m_ptr_map_ = nullptr;
	Game* m_ptr_game_ = nullptr;

	GameManager();
public:
	GameManager* GetInstance()
	{
		if (m_ptr_game_manager == nullptr)
			GameManager::m_ptr_game_manager = new GameManager();

		return  m_ptr_game_manager;
	}


	void RegisterHumanoid(Humanoid* _ptrHumanoid);

};
