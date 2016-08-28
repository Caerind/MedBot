#include "../Keengine/Core/World.hpp"
#include "Entity.hpp"
#include "MyText.hpp"

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

int Entity::getTeam() const
{
	return mTeam;
}

void Entity::setTeam(int team)
{
	mTeam = team;
}

int Entity::getEnemyTeam()
{
	return (mTeam == 1) ? 2 : 1;
}

void Entity::update(sf::Time dt)
{
	mAttackTimer += dt;

	if (mTarget != "")
	{
		Entity::Ptr entity = getWorld().getTypedActor<Entity>(mTarget);
		Base::Ptr base = std::dynamic_pointer_cast<Base>(entity);
		if (entity != nullptr)
		{
			if (entity->isAlive())
			{
				if (mAttackTimer > sf::seconds(200.f / static_cast<float>(mSpeedStat)))
				{
					entity->inflige(mAttackStat);
					getWorld().getApplication().playSound("shit");

					if (base != nullptr)
					{
						getWorld().getApplication().getActualState<GameState>()->grantMoney(getEnemyTeam(), 5);
					}

					if (entity->isDead())
					{
						int amount = (entity->getLifeStat() + entity->getAttackStat() + entity->getSpeedStat()) / 6;
						getWorld().getApplication().getActualState<GameState>()->grantMoney(getTeam(), amount);
						getWorld().getApplication().getActualState<GameState>()->grantMoney(getEnemyTeam(), 10);
						if (mTeam == 1)
						{
							getWorld().createActor<MyText>(amount)->setPosition(entity->getPosition() + sf::Vector2f(0, -60.f));
							getWorld().getApplication().playSound("sdies");
							getWorld().getApplication().playSound("scoin");
						}
						else
						{
							getWorld().getApplication().playSound("sdier");
						}
						entity->remove();
						mTarget = "";
						onRun();

						if (base != nullptr)
						{
							getWorld().getApplication().getActualState<GameState>()->end(mTeam);
						}
					}
					mAttackTimer = sf::Time::Zero;
				}
			}
			else
			{
				mTarget = "";
				onRun();
			}
		}
		else
		{
			mTarget = "";
			onRun();
		}
	}
	else
	{
		float modifier = (mTeam == 1) ? 1.f : -1.f;
		move(sf::Vector2f(modifier, 0.f) * dt.asSeconds() * static_cast<float>(mSpeedStat));

		std::size_t size = getWorld().getActorCount();
		float mindist = 50.f;
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
		if (mTarget != "")
		{
			onAttack(mAttackTimer);
		}
	}
}

void Entity::onRun()
{
}

void Entity::onAttack(sf::Time attackTime)
{
}

std::string Entity::getTarget() const
{
	return mTarget;
}
