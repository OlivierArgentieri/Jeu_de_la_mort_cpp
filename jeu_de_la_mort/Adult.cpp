#include "pch.h"
#include "Adult.h"
#include "Case.h"
#include "Factory.h"
#include "Map.h"


void Adult::IncrementLapReproduct()
{
	this->m_cpt_lap_reproduct_++;
}

int Adult::GetLapReproduct()
{
	return this->m_cpt_lap_reproduct_;
}

void Adult::ResetLapReproduct()
{
	this->m_cpt_lap_reproduct_ = 0;
}

bool Adult::CanReproduct(Vector2 _v2SecondPosition)
{
	Case* h = GetMap().GetCaseByPosition(_v2SecondPosition);
	if (h != nullptr && h->GetTagOccupant() == "Human" && !h->GetAdultOccupant()->AmIinfected() && h->GetAdultOccupant()->GetLapReproduct() >
		5) // si humain + pas infecté + collision -> reproduction
		return true;

	return false;
}

void Adult::Reproduct(Vector2 _v2BabyPosition)
{
	Factory::InitiateRandomHuman(_v2BabyPosition);
	this->ResetLapReproduct();
}

Vector2 Adult::GetNearestEmptyPosition()
{
	Vector2 v2Temp;
	Case* ptrCaseTemp = nullptr;

	for (int i = 1; i <= this->GetMoveRange(); i++)
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

bool Adult::ImAdult()
{
	return true;
}

void Adult::PlayTurn(Vector2 _v2NewPosition)
{
	if (CanReproduct(_v2NewPosition))
	{
		Vector2 temp = GetNearestEmptyPosition();
		if (temp != -1)
			Reproduct(temp);
		return;
	}
	IncrementLapReproduct();
	Human::PlayTurn(_v2NewPosition);
}
