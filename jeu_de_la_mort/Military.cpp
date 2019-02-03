#include "pch.h"
#include "Military.h"
#include "GameManager.h"

bool Military::CanUseEffect(Vector2 _v2NewPosition)
{
	// todo

}

void Military::UseEffect(Vector2 _v2NewPosition)
{
	Zombie *temp = GetOneZombiePositionInMyRange();
	if (temp == nullptr)
		return;

	temp->KillMe();
}

char Military::GetSprite()
{
	return 'M';
}

Military::Military(Vector2 _v2Position) : Human()
{
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}

void Military::Reproduct(Vector2 _v2BabyPosition)
{
	new Military(_v2BabyPosition);
}

Zombie* Military::GetOneZombiePositionInMyRange()
{
	//todo refactor
	MyList<Zombie*> *temp = this->GetZombiesInMyRange();
	if (temp == nullptr)
		return nullptr;

	int listSize = temp->get_size();

	if(listSize>0)
	{
		int randNum = rand() % (listSize);
		return temp->element_at(randNum);
	}
	return nullptr;
}


MyList<Zombie*>* Military::GetZombiesInMyRange()
{
	Vector2 v2Temp;
	Case *ptrCaseTemp = nullptr;
	MyList<Zombie*> *returnList = new MyList<Zombie*>();


	for (int i = 0; i < this->GetRange() && returnList->get_size()<1; i++)
	{
		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->push_back(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + -i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->push_back(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->push_back(ptrCaseTemp->GetZombieOccupant());

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->push_back(ptrCaseTemp->GetZombieOccupant());

	}
	return returnList;
}


