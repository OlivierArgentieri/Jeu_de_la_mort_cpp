#include "pch.h"
#include "Map.h"

void Map::SetSize(Vector2* _ptrSize)
{
	if (_ptrSize->GetX() < 1 || _ptrSize->GetY() < 1)
		return;

	this->m_ptr_size_ = _ptrSize;
}

void Map::InitCase()
{
	for (int i = 0; i < this->m_ptr_size_->GetX(); i++)
	{
		for (int j=0; j< this->m_ptr_size_->GetY(); j++)
		{
			Vector2 *p_v2 = new Vector2(i, j);
			this->m_ptr_cases_->PushBack(new Case(p_v2));
		}
	}
}

Map::Map(Vector2* _ptrSize)
{
	this->m_ptr_cases_ = new MyNewList<Case*>();
	this->SetSize(_ptrSize);
	this->InitCase();
}

Case* Map::GetCaseByPosition(Vector2 _v2Position)
{
	if (this->m_ptr_cases_ == nullptr)
		return nullptr;

	for (int i = 0; i < m_ptr_cases_->Size(); i++)
	{
		Iterator<Case*> it = m_ptr_cases_->Begin().operator++(i);
		if (it.operator*()->m_ptr_position_ != nullptr && it.operator*()->m_ptr_position_->GetX() == _v2Position.GetX() && it.operator*()->m_ptr_position_->GetY() == _v2Position.GetY())
			return it.operator*();
	}
	return nullptr;
}

Vector2* Map::FindExistingPosition(Vector2 _v2Position)
{
	auto p_case = GetCaseByPosition(_v2Position);

	if (p_case != nullptr)
		return p_case->m_ptr_position_;

	return nullptr;
}
