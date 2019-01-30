#include "pch.h"
#include "Map.h"

void Map::SetSize(Vector2 _v2Size)
{
	if (_v2Size.m_x < 0 || _v2Size.m_y < 0)
		return;

	this->m_size_ = _v2Size;
}

Map::Map(Vector2 _v2Size)
{
	this->m_ptr_cases_ = new MyNewList<Case*>();

	this->SetSize(_v2Size);
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