#pragma once
#include "Vector2.h"
#include <string>

class Map;


class Humanoid
{
private :
	Vector2 *m_ptr_position_;
	Map *_ptr_map_;
public:
	virtual void Walk();
	void Move(Vector2 _v2MovePattern);
	void TriggerPlayTurn();
	virtual bool CanPlayTurn() = 0;
	virtual void PlayTurn() = 0;
	virtual std::string GetTag() = 0;
	virtual char GetSprite() = 0;

	void SetPosition(Vector2 *_ptrPosition);
	void SetMap(Map *_ptrMap);
	Vector2 GetPosition();
};
