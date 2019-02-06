#pragma once
#include "Vector2.h"
#include <string>
#include "Sprite.h"

class Map;


class Humanoid
{
private :
	Vector2 m_position_;
	Map *m_ptr_map_;
	Sprite *m_ptr_sprite_;

	int m_range_ = 1; // todo construct by object

public:
	virtual Vector2 GetMovePattern();

	void Move(Vector2 _v2NewPosition);
	Vector2 GetNewPosition(Vector2 _MovePattern);
	void TriggerPlayTurn();
	virtual void PlayTurn(Vector2 _v2NewPosition) =0;
	virtual std::string GetTag()=0;
	virtual Sprite GetSprite();
	virtual void ChangeColorSprite(color _cColor);
	void SetSprite(Sprite* _ptrSprite);
	void SetPosition(Vector2 _v2Position);
	void SetMap(Map *_ptrMap);
	virtual Map GetMap();
	Vector2 GetPosition();
	virtual int GetRange();
	virtual void SetRange(int _iNewRange);
	
	~Humanoid();
};