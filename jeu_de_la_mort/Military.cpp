#include "pch.h"
#include "Military.h"
#include "GameManager.h"


bool Military::UseEffect(Vector2 _v2NewPosition)
{
	auto t = GetOneZombieInMyRange();
	if (t == nullptr)
		return false;

	t->KillMe();

	return true;
}

Military::Military(Vector2 _v2Position)
{
	SetSprite(new Sprite('M', WHITE));
	SetEffectRange(2);
	SetPosition(_v2Position);
	GameManager::GetInstance()->RegisterHumanoid(this);
}


Zombie* Military::GetOneZombieInMyRange()
{
	MyNewList<Zombie*> temp = GetZombiesInMyRange();


	int listSize = temp.Size();

	if (listSize > 0)
	{
		int randNum = rand() % (listSize);
		temp.At(randNum).operator*()->KillMe();
	}
	return nullptr;
}


MyNewList<Zombie*> Military::GetZombiesInMyRange()
{
	MyNewList<Zombie*> returnList = MyNewList<Zombie*>();
	MyNewList<Zombie*> zombieList = GameManager::GetInstance()->GetCurrentGame()->GetAllZombies();

	Vector2 temp;
	int x=0, y=0;
	
	for (int i = 0; i < zombieList.Size(); i++)
	{
		if (temp != Vector2(0, 0)) // exclude yourself 
		{
			Zombie* z = zombieList.At(i).operator*();
			temp = this->GetPosition() - z->GetPosition();

			x = temp.GetX();
			y = temp.GetY();
			if (temp.GetX() < 0)
				x = x * -1;
			if (temp.GetY() < 0)
				y = y * -1;

			temp = Vector2(x, y);
			if((x > y && x > 1 && x <= GetEffectRange()) || y > x && y > 1 && y <= GetEffectRange())
			{
				returnList.PushBack(z);
			}
		}
	}
	return returnList;
}