#include "pch.h"
#include "Military.h"
#include "GameManager.h"

bool Military::CanUseEffect(Vector2 _v2NewPosition)
{
	return true;
}

void Military::UseEffect(Vector2 _v2NewPosition)
{
	auto t = this->GetOneZombieInMyRange();
	if (t == nullptr)
		return;
	
	t->KillMe();
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

Zombie* Military::GetOneZombieInMyRange()
{
	MyNewList<Zombie*> temp = GetZombiesInMyRange();
	int listSize = temp.Size();

	if (listSize > 0)
	{
		int randNum = rand() % (listSize);
		return temp.At(randNum).operator*();;
	}
	return nullptr;
}


MyNewList<Zombie*> Military::GetZombiesInMyRange()
{
	Vector2 v2Temp;
	Case* ptrCaseTemp = nullptr;
	MyNewList<Zombie*> returnList = MyNewList<Zombie*>();


	for (int i = 0; i < this->GetRange() && returnList.Size() < 1; i++)
	{
		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList.PushBack(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + -i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList.PushBack(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList.PushBack(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList.PushBack(ptrCaseTemp->GetZombieOccupant());
	}

	return returnList;
}
