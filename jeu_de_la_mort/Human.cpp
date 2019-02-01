#include "pch.h"
#include "Human.h"
#include "Case.h"
#include "Map.h"
#include "Doctor.h"


void Human::TriggerUseEffect()
{
	if(CanUseEffect())
	{
		UseEffect();
	}
}

std::string Human::GetTag()
{
	return "Human";
}

void Human::PlayTurn(Vector2 _v2NewPosition)
{
	if (CanReproduct(_v2NewPosition))
	{
		Vector2 temp = GetNearestEmptyPosition(_v2NewPosition);
		if (temp != -1)
			Reproduct(temp);

		return;
	}
		// todo make effect 

	if(CanUseEffect())
	{
		return;
	}


}

bool Human::CanReproduct(Vector2 _v2SecondPosition)
{
	if (this->GetTag() != "Human")
		return false;

	Case *h = GetMap().GetCaseByPosition(_v2SecondPosition);
	if (h != nullptr && h->GetTagOccupant() != "Human")
		return false;

	return true;
}


void Human::GetInfectedByZombie()
{
	this->m_is_infected_ = true;
}

bool Human::IAmInfected()
{
	return this->m_is_infected_;
}

Vector2 Human::GetNearestEmptyPosition(Vector2 _v2CurrentPosition)
{
	Vector2 v2Temp;
	Case *ptrCaseTemp = nullptr;


	for (int i =1; i>=this->GetRange(); i++)
	{
		v2Temp = Vector2(this->GetPosition().GetX() + i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);

		if (ptrCaseTemp != nullptr && !ptrCaseTemp->IsOccuped())
			return v2Temp;

		v2Temp = Vector2(this->GetPosition().GetX() + -i, this->GetPosition().GetY() + 0);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);
		if (ptrCaseTemp != nullptr && !ptrCaseTemp->IsOccuped())
			return v2Temp;

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);
		if (ptrCaseTemp != nullptr && !ptrCaseTemp->IsOccuped())
			return v2Temp;

		v2Temp = Vector2(this->GetPosition().GetX() + 0, this->GetPosition().GetY() + -i);
		ptrCaseTemp = GetMap().GetCaseByPosition(v2Temp);
		if (ptrCaseTemp != nullptr && !ptrCaseTemp->IsOccuped())
			return v2Temp;

	}

	return Vector2();
}