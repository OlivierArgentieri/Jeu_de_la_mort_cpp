#pragma once
#include "Vector2.h"
#include <string>

class Map;


class Humanoid
{
private :
	Vector2 m_position_;
	Map *m_ptr_map_;

	int m_range_;

public:
	virtual Vector2 GetMovePattern();

	void Move(Vector2 _PtrNewPosition);
	Vector2* GetNewPosition(Vector2 _MovePattern);
	void TriggerPlayTurn();
	virtual bool CanPlayTurn(Vector2 *_ptrNewPosition) =0;
	virtual void PlayTurn(Vector2 *_ptrNewPosition) =0;
	virtual std::string GetTag()=0;
	virtual char GetSprite()=0;

	void SetPosition(Vector2 _v2Position);
	void SetMap(Map *_ptrMap);
	Vector2 GetPosition();
};
