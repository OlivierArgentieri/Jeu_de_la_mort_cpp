#pragma once
#include "Map.h"

class Game
{
private:
	Map* m_ptr_map_;
	MyNewList<Humanoid*> *m_ptr_humanoids_;
	bool m_game_over_;
public:
	Game(Vector2* _ptrSizeMap);
	Game(const Game &_refGame);
	~Game();
	void AddHumanoid(Humanoid* _ptrHumanoid);
	void DeleteHumanoid(Humanoid* _ptrHumanoid);
	void RemoveHumanoidFromList(Humanoid* _ptrHumanoid);
	Map GetMap();

	void DisplayMap();
	void DisplayATH();
	void GameLoop();
	void TriggerAllPlayer();
	void CheckGameOver();
	Humanoid* GetHumanoidByPosition(Vector2 _v2Position);
	int GetNumberOfInfectedHuman();
	MyNewList<Humanoid*> GetAllHumanoid();
	MyNewList<Human*> GetAllHumans();
	MyNewList<Zombie*> GetAllZombies();
};