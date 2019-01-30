#pragma once
#include "Case.h"
#include "MyNewList.h"

class Map
{
private:
	MyNewList<Case*> *m_ptr_cases_;

public:
	Map();
	Case* GetCaseByPosition(Vector2 _v2Position);

};
