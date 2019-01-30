#include "pch.h"
#include "Map.h"

void Map::SetSize(Vector2 _v2Size)
{
	if (_v2Size.m_x < 1 || _v2Size.m_y < 1)
		return;

	this->m_size_ = _v2Size;
}

void Map::InitCase()
{
	for (int i = 0; i < this->m_size_.m_x; i++)
	{
		for (int j=0; j< this->m_size_.m_y; j++)
		{
			Vector2 p_v2;
			p_v2.m_x = i;
			p_v2.m_y = j;
			this->m_ptr_cases_->PushBack(new Case(p_v2));
		}
	}
}

Map::Map(Vector2 _v2Size)
{
	this->m_ptr_cases_ = new MyNewList<Case*>();
	this->SetSize(_v2Size);
	this->InitCase();
}

Case* Map::GetCaseByPosition(Vector2 _v2Position)
{
	if (this->m_ptr_cases_ == nullptr)
		return nullptr;

	for (int i = 0; i < m_ptr_cases_->Size(); i++)
	{
		Iterator<Case*> it = m_ptr_cases_->Begin().operator++(i);
		if (it.operator*()->m_position_.m_x == _v2Position.m_x && it.operator*()->m_position_.m_y == _v2Position.m_y)
			return it.operator*();
	}
	return nullptr;
}
