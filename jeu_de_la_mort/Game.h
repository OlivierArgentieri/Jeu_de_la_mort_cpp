#pragma once
#include "Map.h"

class Game
{
private:
	Map* m_ptr_map;
	MyNewList<Humanoid*> *m_ptr_humanoids_;
	bool m_game_over_;
public:
	Game(Vector2* _ptrSizeMap);

	void AddHumanoid(Humanoid* _ptrHumanoid);
	Map GetMap();

	void DisplayMap();
	void GameLoop();
	void TriggerAllPlayer();

	// todo get huamn by position

};
