#pragma once
#include "Case.h"
#include "MyNewList.h"

class Map
{
private:
	MyNewList<Case*> *m_ptr_cases_;
	Vector2 m_size_;

	void SetSize(Vector2 _v2Size);

	void InitCase();
public:
	Map(Vector2 _v2Size);
	Case* GetCaseByPosition(Vector2 _v2Position);

	
};
