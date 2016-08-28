#include "../Keengine/Core/World.hpp"
#include "Soldier.hpp"
#include "GameState.hpp"

#include <iostream>

Soldier::Soldier(sf::Time gameTime)
{
	mLifeStat = 100 + ke::random(-10, 10) + (int)(gameTime.asSeconds() / 60);
	mAttackStat = 15 + ke::random(-5, 5) + (int)(gameTime.asSeconds() / 60);
	mSpeedStat = 125 + ke::random(-25, 25) + (int)(gameTime.asSeconds() / 60);
	mLife = mLifeStat;
	mTeam = 2;
	mTarget = "";

	registerComponent(&mComponent);
	attachComponent(&mComponent);

	ke::Animation& run = mComponent.getAnimation("run");
	run.addFrame("soldier", { 0, 0, 64, 64 }, sf::seconds(0.15f));
	run.addFrame("soldier", { 64, 0, 64, 64 }, sf::seconds(0.15f));

	mComponent.playAnimation("run");
	mComponent.move({ -32.f, -64.f });
}