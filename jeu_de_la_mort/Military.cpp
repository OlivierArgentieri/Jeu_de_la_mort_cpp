#include "pch.h"
#include "Military.h"
#include "GameManager.h"


bool Military::UseEffect(Vector2 _v2NewPosition)
{
	auto t = this->GetOneZombieInMyRange();
	if (t == nullptr)
		return false;
	
	t->KillMe();

	return true;
}

Military::Military(Vector2 _v2Position)
{
	SetSprite(new Sprite('M', WHITE));
	SetRange(2);
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}


Zombie* Military::GetOneZombieInMyRange()
{
	MyNewList<Vector2*> *temp = GetZombiesInMyRange();
	int listSize = temp->Size();

	if (listSize > 0)
	{
		int randNum = rand() % (listSize);
		Humanoid *h = GameManager::GetInstance()->GetHumanoidByPosition(temp->At(randNum).operator*());
		delete(temp);

		return static_cast<Zombie*>(h);
	}
	delete(temp);
	return nullptr;
}


MyNewList<Vector2*>* Military::GetZombiesInMyRange()
{
	Vector2 v2Temp;
	Case* ptrCaseTemp = nullptr;
	MyNewList<Vector2*> *returnList = new MyNewList<Vector2*>();

	for (int i = 1; i < this->GetRange() && returnList->Size() < 1; i++)
	{
		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + -i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + -1, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(new Vector2(v2Temp));


		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(new Vector2(v2Temp));

		v2Temp = Vector2(this->GetPosition().GetX() + -1, this->GetPosition().GetY() + +i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(new Vector2(v2Temp));


		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + +i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && ptrCaseTemp->IsOccuped() && ptrCaseTemp->GetTagOccupant() == "Zombie")
			returnList->PushBack(new Vector2(v2Temp));
	}
	return returnList;
}