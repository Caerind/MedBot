#include "../Keengine/Core/World.hpp"
#include "Robot.hpp"

#include <iostream>

Robot::Robot()
{
	mLifeStat = 100;
	mAttackStat = 100;
	mSpeedStat = 200;
	mLife = mLifeStat;
	mTeam = 1;
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
	run.addFrame("robot", { 0, 0, 128, 256 }, sf::seconds(0.15f));
	run.addFrame("robot", { 128, 0, 128, 256 }, sf::seconds(0.15f));

	mComponent.scale({ 0.25f, 0.25f });
	mComponent.playAnimation("run");
	mComponent.move({ -16.f, -64.f });
}

void Robot::update(sf::Time dt)
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
						std::cout << "test" << std::endl;
						grantMoney();
						entity->onDying();
						entity->remove();
						mTarget = "";
					}
					mAttackTimer = sf::Time::Zero;
				}
			}
		}
	}
	else
	{
		move(sf::Vector2f(1.f, 0.f) * dt.asSeconds() * static_cast<float>(mSpeedStat));
		acquireTarget();
	}
}
