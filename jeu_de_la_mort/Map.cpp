#include "pch.h"
#include "Map.h"

Map::Map()
{
	this->m_ptr_cases_ = new MyNewList<Case*>();
}

Case* Map::GetCaseByPosition(Vector2 _v2Position)
{
	if (this->m_ptr_cases_ == nullptr)
		return nullptr;

	for (int i = 0; i < m_ptr_cases_->Size(); i++)
	{
		Iterator<Case*> it = m_ptr_cases_->Begin().operator++(i);
		if (it.operator*()->m_ptr_humanoid->GetPosition().m_x == _v2Position.m_x && it.operator*()->m_ptr_humanoid->GetPosition().m_y == _v2Position.m_y)
			return it.operator*();
	}
	return nullptr;
}
