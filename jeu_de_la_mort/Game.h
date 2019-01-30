#pragma once
#include "Map.h"

class Game
{
private:
	Map * m_ptr_map;
	MyNewList<Humanoid*> *m_humanoids_;


public:
	Game();

	void AddHumanoid(Humanoid* _ptrHumanoid);

};
