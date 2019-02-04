#include "pch.h"
#include "Human.h"
#include "Case.h"
#include "Map.h"
#include "ZombieRandomMove.h"


std::string Human::GetTag()
{
	return "Human";
}

void Human::IncrementLapReproduct()
{
	this->m_cpt_lap_reproduct_++;
}

int Human::GetLapReproduct()
{
	return this->m_cpt_lap_reproduct_;
}

void Human::ResetLapReproduct()
{
	this->m_cpt_lap_reproduct_ = 0;
}

void Human::PlayTurn(Vector2 _v2NewPosition)
{
	if (CanTransformToZombie())// todo make const
	{
		TransformToZombie();
		return;
	}
	if (UseEffect(_v2NewPosition))
		return; // to allow one action per lap


	if (CanReproduct(_v2NewPosition))
	{
		Vector2 temp = GetNearestEmptyPosition(_v2NewPosition);
		if (temp != -1)
			Reproduct(temp);
		return;
	}

	if (AmIinfected())
		this->m_cpt_lap_infected_++;
	
	if (CanMove(_v2NewPosition))
		Move(_v2NewPosition);

	IncrementLapReproduct();
}

bool Human::CanReproduct(Vector2 _v2SecondPosition)
{
	Case *h = GetMap().GetCaseByPosition(_v2SecondPosition);
	if (h != nullptr && h->GetTagOccupant() == "Human" && !h->GetHumanOccupant()->AmIinfected() && h->GetHumanOccupant()->GetLapReproduct() > 5) // si humain et pas infect� + collision -> reproduction
		return true;

	return false;
}

void Human::Reproduct(Vector2 _v2BabyPosition)
{
	this->ResetLapReproduct();
}

void Human::GetInfectedByZombie()
{
	this->m_is_infected_ = true;
}

bool Human::AmIinfected()
{
	return this->m_is_infected_;
}

void Human::HealMe()
{
	this->m_cpt_lap_infected_ = 0;
	this->m_is_infected_ = false;
}

Vector2 Human::GetNearestEmptyPosition(Vector2 _v2CurrentPosition)
{
	Vector2 v2Temp;
	Case *ptrCaseTemp = nullptr;

	for (int i = 1; i <= this->GetRange(); i++)
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

void Human::TransformToZombie()
{
	Vector2 temp(this->GetPosition());
	delete(this);
	new ZombieRandomMove(temp);
}

bool Human::CanTransformToZombie()
{
	return this->m_cpt_lap_infected_ > 1; // todo make const
}

bool Human::CanMove(Vector2 _v2NewPosition)
{
	_v2NewPosition != -1 && !GetMap().GetCaseByPosition(_v2NewPosition)->IsOccuped()
}