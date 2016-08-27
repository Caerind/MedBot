#include "../Keengine/Core/World.hpp"
#include "Soldier.hpp"

#include <iostream>

Soldier::Soldier()
{
	mLifeStat = 100;
	mAttackStat = 15;
	mSpeedStat = 150;
	mLife = mLifeStat;
	mTeam = 2;
	mTarget = "";

	registerComponent(&mComponent);
	attachComponent(&mComponent);
	/*
	ke::Animation& attack = mComponent.getAnimation("attack");
	attack.addFrame("cat", { 0, 0, 64, 64 }, sf::seconds(0.15f));
	attack.addFrame("cat", { 64, 0, 64, 64 }, sf::seconds(0.15f));
	attack.addFrame("cat", { 128, 0, 64, 64 }, sf::seconds(0.15f));
	attack.addFrame("cat", { 192, 0, 64, 64 }, sf::seconds(0.15f));
	*/
	ke::Animation& run = mComponent.getAnimation("run");
	run.addFrame("soldier", { 0, 0, 256, 256 }, sf::seconds(0.15f));
	run.addFrame("soldier", { 256, 0, 256, 256 }, sf::seconds(0.15f));

	mComponent.scale({ 0.25f, 0.25f });
	mComponent.playAnimation("run");
	mComponent.move({ -32.f, -64.f });
}

void Soldier::update(sf::Time dt)
{
	mAttackTimer += dt;
	if (mTarget != "")
	{
		Entity::Ptr entity = getWorld().getTypedActor<Entity>(mTarget);
		if (entity != nullptr)
		{
			if (entity->isAlive())
			{
				float t = static_cast<float>(mSpeedStat) / 100.f;
				if (mAttackTimer > sf::seconds(t))
				{
					entity->inflige(mAttackStat);
					if (entity->isDead())
					{
						grantMoney();
						entity->onDying();
						entity->remove();
						mTarget = "";
					}
					mAttackTimer = sf::Time::Zero;
				}
			}
			else
			{
				mTarget = "";
			}
		}
		else
		{
			mTarget = "";
		}
	}
	else
	{
		move(sf::Vector2f(-1.f, 0.f) * dt.asSeconds() * static_cast<float>(mSpeedStat));
		acquireTarget();
	}
}

void Soldier::onDying()
{
	// TODO : Increase AI aggresivity
}
