#pragma once
#include "Vector2.h"
#include <string>
class Humanoid
{
private :
	Vector2 *m_ptr_position_;

public:
	virtual ~Humanoid() = default;
	virtual void Walk();

	void TriggerPlayTurn();
	virtual bool CanPlayTurn() = 0;
	virtual void PlayTurn() = 0;
	virtual std::string GetTag() = 0;
	virtual char GetSprite() = 0;

	void SetPosition(Vector2 *_ptrPosition);
	Vector2 GetPosition();
};
