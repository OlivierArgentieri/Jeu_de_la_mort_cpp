#include "pch.h"
#include "Vector2.h"
#include "ZombieExplode.h"
#include "GameManager.h"

ZombieExplode::ZombieExplode(Vector2 _v2Position)
{
	SetSprite(new Sprite('E', YELLOW));
	SetEffectRange(3);
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}


ZombieExplode::~ZombieExplode()
{
	
	Explode();
	GameManager::GetInstance()->RemoveHumanoid(this);
}

void ZombieExplode::Explode()
{
	MyNewList<Human*> humans = GetHumansInMyRange();
	int listSize = humans.Size();

	if (listSize > 0)
	{
		InfectHuman(humans);
	}
}

MyNewList<Human*> ZombieExplode::GetHumansInMyRange()
{
	Vector2 v2Temp;
	Case* ptrCaseTemp = nullptr;
	MyNewList<Human*> returnList = MyNewList<Human*>();


	for (int i = 0; i < this->GetEffectRange(); i++)
	{
		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList.PushBack(ptrCaseTemp->GetHumanOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + -i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList.PushBack(ptrCaseTemp->GetHumanOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList.PushBack(ptrCaseTemp->GetHumanOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList.PushBack(ptrCaseTemp->GetHumanOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + -1, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList.PushBack(ptrCaseTemp->GetHumanOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList.PushBack(ptrCaseTemp->GetHumanOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + -1, this->GetPosition().GetY() + +i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList.PushBack(ptrCaseTemp->GetHumanOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + +i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList.PushBack(ptrCaseTemp->GetHumanOccupant());

	}
	return returnList;
}

void ZombieExplode::InfectHuman(MyNewList<Human*> _lHumans)
{
	for (int i = 0; i < _lHumans.Size(); i++)
	{
		// cast
		_lHumans.At(i).operator*()->GetInfectedByZombie();
	}
}

void ZombieExplode::KillMe()
{
	delete(this);
}