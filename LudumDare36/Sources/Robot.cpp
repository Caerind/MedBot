#include "../Keengine/Core/World.hpp"
#include "Robot.hpp"
#include "Base.hpp"
#include "GameState.hpp"

#include <iostream>

Robot::Robot(int head, int body, int legs)
{
	auto& s = getWorld().getApplication().script("init.lua");
	mLifeStat = s[std::string("d" + std::to_string(head)).c_str()]["value"];
	mAttackStat = s[std::string("d" + std::to_string(body)).c_str()]["value"];
	mSpeedStat = s[std::string("d" + std::to_string(legs)).c_str()]["value"];
	mLife = mLifeStat;
	mTeam = 1;
	mTarget = "";

	registerComponent(&mHead);
	attachComponent(&mHead);
	mHead.setZ(2.f);
	mHead.setTexture("robot");
	mHead.setTextureRect({ (head - 11) * 24, 96, 24, 26 });
	mHead.move({ -12.f, -76.f });

	registerComponent(&mBody);
	attachComponent(&mBody);
	mBody.setZ(1.f);
	mBody.setTexture("robot");
	mBody.setTextureRect({ (body - 21) * 15, 122, 15, 22 });
	mBody.move({ -7.5f, -50.f });

	registerComponent(&mArms);
	attachComponent(&mArms);
	mArms.setZ(4.f);
	mArms.move({ -2.f, -48.f });
	ke::Animation& aIdle = mArms.getAnimation("idle");
	aIdle.addFrame("robot", { 0, 147, 37, 22 }, sf::seconds(0.25f));
	aIdle.addFrame("robot", { 0, 169, 37, 22 }, sf::seconds(0.25f));
	aIdle.addFrame("robot", { 0, 191, 37, 22 }, sf::seconds(0.25f));
	aIdle.addFrame("robot", { 0, 169, 37, 22 }, sf::seconds(0.25f));
	ke::Animation& aRun = mArms.getAnimation("run");
	aRun.addFrame("robot", { 0, 147, 37, 22 }, sf::seconds(10.f));

	registerComponent(&mLegs);
	attachComponent(&mLegs);
	mLegs.setZ(3.f);
	mLegs.move({ -16.f, -32.f });
	ke::Animation& lRun = mLegs.getAnimation("run");
	lRun.addFrame("robot", { 0, (legs - 31) * 32, 32, 32 }, sf::seconds(0.10f));
	lRun.addFrame("robot", { 32, (legs - 31) * 32, 32, 32 }, sf::seconds(0.10f));
	lRun.addFrame("robot", { 64, (legs - 31) * 32, 32, 32 }, sf::seconds(0.10f));
	ke::Animation& lIdle = mLegs.getAnimation("idle");
	lIdle.addFrame("robot", { 0, (legs - 31) * 32, 32, 32 }, sf::seconds(10.f));

	mArms.playAnimation("run");
	mLegs.playAnimation("run");
}
