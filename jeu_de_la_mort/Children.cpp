#include "pch.h"
#include "Sprite.h"
#include "Children.h"
#include "Factory.h"
#include "GameManager.h"

Children::Children(Vector2 _v2Position)
{
	SetSprite(new Sprite('c', WHITE));
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}

void Children::PlayTurn(Vector2 _v2NewPosition)
{
	if (CanGrow())
		Grow();
	
	Human::PlayTurn(_v2NewPosition);
}

bool Children::UseEffect(Vector2 _v2NewPosition)
{
	return false; // no effect fo children
}

bool Children::ImAdult()
{
	return false; // it's a children not an adult
}

bool Children::CanGrow()
{

	return m_nb_lap_grow_ > 5;
}

void Children::Grow()
{
	Vector2 temp(this->GetPosition());
	delete(this);
	Factory::InitiateRandomHuman(temp);
}