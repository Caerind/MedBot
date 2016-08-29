#include "../Keengine/Core/World.hpp"
#include "Entity.hpp"

#include <iostream>
#include "Base.hpp"

Base::Base(int team)
{
	mLifeStat = (mTeam == 1) ? 2000 : 3000;
	mAttackStat = 0;
	mSpeedStat = 0;
	mLife = mLifeStat;
	mTeam = team;
	mTarget = "";

	registerComponent(&mSprite);
	attachComponent(&mSprite);
	mSprite.setZ(-100.f);
	mSprite.setTexture("base");

	registerComponent(&mLifeBack);
	attachComponent(&mLifeBack);
	mLifeBack.setZ(100.f);
	mLifeBack.setTexture("lifebar");
	mLifeBack.setTextureRect({ 0,0,600,45 });

	registerComponent(&mLifeBar);
	attachComponent(&mLifeBar);
	mLifeBar.setZ(200.f);
	mLifeBar.setTexture("lifebar");
	mLifeBar.setTextureRect({ 0,45,600,45 });

	if (mTeam == 1)
	{
		setPosition({ 50, 360 });
		mSprite.setTextureRect({ 36,0,36,50 });

		mLifeBack.setPosition({ -50.f, -360.f });

		mLifeBar.setPosition({ -50.f, -360.f });
	}
	else
	{
		setPosition({ 1550, 360 });
		mSprite.setTextureRect({ 0,0,36,50 });
		
		mLifeBack.setRotation(180);
		mLifeBack.setPosition({ 50.f, -315.f });

		mLifeBar.setRotation(180);
		mLifeBar.setPosition({ 50.f, -315.f });
	}

	mSprite.setScale({ 2.f, 2.f });
	mSprite.move({ -36.f, -100.f });
}

void Base::update(sf::Time dt)
{
	float percent = 600.f * static_cast<float>(mLife) / static_cast<float>(mLifeStat);
	mLifeBar.setTextureRect({ 0,45,(int)percent,45 });
}