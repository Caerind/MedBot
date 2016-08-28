#include "../Keengine/Core/World.hpp"
#include "Soldier.hpp"
#include "GameState.hpp"

#include <iostream>

Soldier::Soldier(sf::Time gameTime)
{
	mLifeStat = 100 + ke::random(-10, 10) + (int)(gameTime.asSeconds() / 30);
	mAttackStat = 15 + ke::random(-5, 5) + (int)(gameTime.asSeconds() / 30);
	mSpeedStat = 125 + ke::random(-25, 25) + (int)(gameTime.asSeconds() / 30);
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