#include "pch.h"
#include "Vector2.h"
#include "ZombieExplode.h"
#include "GameManager.h"

ZombieExplode::ZombieExplode(Vector2 _v2Position)
{
	SetSprite(new Sprite('E', YELLOW));
	SetEffectRange(3);
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}


ZombieExplode::~ZombieExplode()
{
	
	Explode();
	GameManager::GetInstance()->RemoveHumanoid(this);
}

void ZombieExplode::Explode()
{
	MyNewList<Human*> humans = GetHumansInMyRange();
	int listSize = humans.Size();

	if (listSize > 0)
	{
		InfectHuman(humans);
	}
}

MyNewList<Human*> ZombieExplode::GetHumansInMyRange()
{

	MyNewList<Human*> returnList = MyNewList<Human*>();
	MyNewList<Human*> humanList = GameManager::GetInstance()->GetCurrentGame()->GetAllHumans();

	Vector2 temp;
	int x = 0, y = 0;

	for (int i = 0; i < humanList.Size(); i++)
	{
		if (temp != Vector2(0, 0)) // exclude yourself 
		{
			Human* z = humanList.At(i).operator*();
			temp = this->GetPosition() - z->GetPosition();

			x = temp.GetX();
			y = temp.GetY();
			if (temp.GetX() < 0)
				x = x * -1;
			if (temp.GetY() < 0)
				y = y * -1;

			temp = Vector2(x, y);
			if ((x > y && x > 0 && x <= GetEffectRange()) || y > x && y > 0 && y <= GetEffectRange())
			{
				returnList.PushBack(z);
			}
		}
	}
	return returnList;
}

void ZombieExplode::InfectHuman(MyNewList<Human*> _lHumans)
{
	for (int i = 0; i < _lHumans.Size(); i++)
	{
		// cast
		_lHumans.At(i).operator*()->GetInfectedByZombie();
	}
}

void ZombieExplode::KillMe()
{
	delete(this);
}