#pragma once
#include "Case.h"
#include "MyNewList.h"

class Map
{
private:
	MyNewList<Case*> *m_ptr_cases_;
	Vector2 *m_ptr_size_;

	void SetSize(Vector2 *_ptrSize);
	void InitCase();
public:
	Map(Vector2 *_ptrSize);
	Map(const Map& _refMap);
	~Map();
	Vector2 GetSize();
	Case* GetCaseByPosition(Vector2 _v2Position);
	Vector2 FindExistingPosition(Vector2 _v2Position);
};