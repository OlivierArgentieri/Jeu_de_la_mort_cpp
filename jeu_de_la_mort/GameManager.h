#pragma once
#include "Map.h"
#include "Game.h"


class GameManager
{
private:
	static GameManager * m_ptr_game_manager;
	Game* m_ptr_game_ = nullptr;

	GameManager();
public:
	static GameManager* GetInstance()
	{
		if (m_ptr_game_manager == nullptr)
			m_ptr_game_manager = new GameManager();

		return  m_ptr_game_manager;
	}

	void RegisterGame(Game* _ptr_game);
	void RegisterHumanoid(Humanoid* _ptrHumanoid);
};
