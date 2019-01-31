#pragma once
#include "Map.h"

class Game
{
private:
	Map * m_ptr_map;
	MyNewList<Humanoid*> *m_humanoids_;

public:
	Game(Vector2 *_ptrSizeMap);

	void AddHumanoid(Humanoid* _ptrHumanoid);
	Map GetMap();
};
