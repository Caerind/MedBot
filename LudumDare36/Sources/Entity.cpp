#include "../Keengine/Core/World.hpp"
#include "Entity.hpp"

#include "GameState.hpp"

Entity::Entity()
{
	mLifeStat = 100;
	mAttackStat = 10;
	mSpeedStat = 100;
	mLife = mLifeStat;
	mTeam = 0;
	mTarget = "";
}

int Entity::getLifeStat() const
{
	return mLifeStat;
}

int Entity::getAttackStat() const
{
	return mAttackStat;
}

int Entity::getSpeedStat() const
{
	return mSpeedStat;
}

void Entity::setLifeStat(int life)
{
	mLifeStat = life;
}

void Entity::setAttackStat(int attack)
{
	mAttackStat = attack;
}

void Entity::setSpeedStat(int speed)
{
	mSpeedStat = speed;
}

int Entity::getLife() const
{
	return mLife;
}

void Entity::setLife(int life)
{
	mLife = life;
}

bool Entity::inflige(int damage)
{
	bool ret = false;
	if (mLife < damage && mLife > 0)
	{
		ret = true;
	}
	mLife -= damage;
	return ret;
}

bool Entity::isAlive() const
{
	return (mLife > 0);
}

bool Entity::isDead() const
{
	return (mLife <= 0);
}

void Entity::onDying() const
{
}

int Entity::getTeam() const
{
	return mTeam;
}

void Entity::setTeam(int team)
{
	mTeam = team;
}

void Entity::grantMoney()
{
	Entity::Ptr ent = getWorld().getTypedActor<Entity>(mTarget);
	if (ent != nullptr)
	{
		int amount = (ent->getLifeStat() + ent->getAttackStat() + ent->getSpeedStat()) / 3;
		getWorld().getApplication().getActualState<GameState>()->grantMoney(1, amount);
	}
}

std::string Entity::getTarget() const
{
	return mTarget;
}

void Entity::acquireTarget()
{
	std::size_t size = getWorld().getActorCount();
	float mindist = 30.f;
	for (std::size_t i = 0; i < size; i++)
	{
		Entity::Ptr ent = getWorld().getTypedActor<Entity>(i);
		if (ent != nullptr)
		{
			float d = ke::distance(getPosition(), ent->getPosition());
			if (d < mindist && ent->getTeam() != getTeam() && ent->isAlive())
			{
				mindist = d;
				mTarget = ent->getId();
			}
		}
	}
}
