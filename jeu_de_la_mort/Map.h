#pragma once
#include "Case.h"
#include "MyList.h"

class Map
{
private:
	MyList<Case*> *m_ptr_cases_;
	Vector2 *m_ptr_size_;

	void SetSize(Vector2 *_ptrSize);

	void InitCase();
public:
	Map(Vector2 *_ptrSize);
	Vector2 GetSize();
	Case* GetCaseByPosition(Vector2 _v2Position); // todo
	Vector2 FindExistingPosition(Vector2 _v2Position);


};
