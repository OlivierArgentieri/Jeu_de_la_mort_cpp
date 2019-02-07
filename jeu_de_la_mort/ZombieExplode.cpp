#include "pch.h"
#include "Vector2.h"
#include "ZombieExplode.h"
#include "GameManager.h"

ZombieExplode::ZombieExplode(Vector2 _v2Position)
{
	SetSprite(new Sprite('E', YELLOW));
	SetRange(3);
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}


ZombieExplode::~ZombieExplode()
{
	this->Explode();
	GameManager::GetInstance()->RemoveHumanoid(this);
}

void ZombieExplode::Explode()
{
	InfectHuman(GetHumanInMyRange());
}

MyNewList<Vector2*>* ZombieExplode::GetHumanInMyRange()
{
	Vector2 v2Temp;
	Case* ptrCaseTemp = nullptr;
	MyNewList<Vector2*> *returnList = new MyNewList<Vector2*>();


	for (int i = 0; i < this->GetRange(); i++)
	{
		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + -i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + i);
		returnList->PushBack(new Vector2(v2Temp));

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + -i);
		returnList->PushBack(new Vector2(v2Temp));

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList->PushBack(new Vector2(v2Temp));

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + -1, this->GetPosition().GetY() + +i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + +i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Human")
			returnList->PushBack(new Vector2(v2Temp));

	return returnList;
}

void ZombieExplode::InfectHuman(MyNewList<Human*> _lHumans)
{
	for(int i=0; i< _lHumans.Size(); i++)
	{
		if (_lHumans.At(i).operator*() != nullptr)
			_lHumans.At(i).operator*()->GetInfectedByZombie();
	}
}

void ZombieExplode::KillMe()
{
	Explode();
	delete(this);
}