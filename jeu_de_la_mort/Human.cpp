#include "pch.h"
#include "Human.h"
#include "Case.h"
#include "Map.h"
#include "ZombieRandomMove.h"
#include "ZombieExplode.h"
#include "GameManager.h"
#include "Factory.h"


std::string Human::GetTag()
{
	return "Human";
}

void Human::PlayTurn(Vector2 _v2NewPosition)
{
	
	if (CanTransformToZombie())
	{
		TransformToZombie();
		return;
	}
	if (UseEffect(_v2NewPosition))
		return; // to allow one action per lap


	if (CanReproduct(_v2NewPosition))
	{
		Vector2 temp = GetNearestEmptyPosition();
		if (temp != -1)
			Reproduct(temp);
		return;
	}

	if (AmIinfected())
		ProgressiveContamination();

	if (CanMove(_v2NewPosition))
		Move(_v2NewPosition);

	IncrementLapReproduct();
}


void Human::GetInfectedByZombie()
{
	ChangeColorSprite(RED);
	this->m_is_infected_ = true;
}

bool Human::AmIinfected()
{
	return this->m_is_infected_;
}

void Human::HealMe()
{
	ChangeColorSprite(WHITE);
	this->m_cpt_lap_infected_ = 0;
	this->m_is_infected_ = false;
}

Vector2 Human::GetNearestEmptyPosition()
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

void Human::TransformToZombie()
{
	// rand sur type de zombie
	Vector2 temp(this->GetPosition());
	delete(this);
	Factory::InitiateRandomZombie(temp);
}



bool Human::CanTransformToZombie()
{
	return this->m_cpt_lap_infected_ > m_lap_before_transform_;
}

bool Human::CanMove(Vector2 _v2NewPosition)
{
	return _v2NewPosition != -1 && !GetMap().GetCaseByPosition(_v2NewPosition)->IsOccuped();
}

void Human::ProgressiveContamination()
{
	this->m_cpt_lap_infected_++;
}