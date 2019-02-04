#include "pch.h"
#include "Map.h"

void Map::SetSize(Vector2* _ptrSize)
{
	if (_ptrSize != nullptr && _ptrSize->GetX() < 1 || _ptrSize->GetY() < 1)
		return;

	this->m_ptr_size_ = _ptrSize;
}

void Map::InitCase()
{
	if (this->m_ptr_size_ == nullptr)
		return;
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

Vector2 Map::GetSize()
{
	return *this->m_ptr_size_;
}

Case* Map::GetCaseByPosition(Vector2 _v2Position)
{
	if (this->m_ptr_cases_ == nullptr)
		return nullptr;

	if (_v2Position.GetX() < 0 || _v2Position.GetX() >= this->GetSize().GetX() || _v2Position.GetY() < 0 || _v2Position.GetY() >= this->GetSize().GetY())
		return nullptr;

	for (int i = 0; i < m_ptr_cases_->Size(); i++)
	{
		Iterator<Case*> it = m_ptr_cases_->Begin().operator++(i);
		if (it.operator*()->GetPosition().GetX() == _v2Position.GetX() && it.operator*()->GetPosition().GetY() == _v2Position.GetY())
			return it.operator*();
	}
	return nullptr;
}

Vector2 Map::FindExistingPosition(Vector2 _v2Position)
{
	auto p_case = GetCaseByPosition(_v2Position);

	if (p_case != nullptr)
		return p_case->GetPosition();

	return Vector2();
}