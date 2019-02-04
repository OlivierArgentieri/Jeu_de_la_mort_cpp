#include "pch.h"
#include "Military.h"
#include "GameManager.h"

bool Military::CanUseEffect(Vector2 _v2NewPosition)
{
	/**/
	auto temp = GetZombiesInMyRange();
	//if (temp != nullptr && temp->get_size() > 0)
	//	return true;

	return false;
}

void Military::UseEffect(Vector2 _v2NewPosition)
{
	/*
	Zombie *temp = GetOneZombiePositionInMyRange();
	if (temp == nullptr)
		return;

	temp->KillMe();*/
}

char Military::GetSprite()
{
	return 'M';
}

Military::Military(Vector2 _v2Position)
{
	this->SetRange(2);
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}

void Military::Reproduct(Vector2 _v2BabyPosition)
{
	Human::Reproduct(_v2BabyPosition);
	new Military(_v2BabyPosition);
}

Zombie* Military::GetOneZombiePositionInMyRange()
{
	//todo refactor
	MyNewList<Zombie*> *temp = this->GetZombiesInMyRange();
	if (temp == nullptr)
		return nullptr;

	int listSize = temp->Size();

	if(listSize>0)
	{
		int randNum = rand() % (listSize);
		return temp->At(randNum).operator*();
	}
	delete(temp);
	return nullptr;
}


MyNewList<Zombie*>* Military::GetZombiesInMyRange()
{
	Vector2 v2Temp;
	Case *ptrCaseTemp = nullptr;
	MyNewList<Zombie*> *returnList = new MyNewList<Zombie*>();


	for (int i = 0; i < this->GetRange() && returnList->Size()<1; i++)
	{
		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + -i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(ptrCaseTemp->GetZombieOccupant());

	}
	return returnList;
}