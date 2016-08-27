#include "GameState.hpp"

GameState::GameState()
	: mWorld(ke::World::createInstance())
{
	mWorld.getTime().setTimeFactor(2.f);

	createActor();
	createGui();
}

GameState::~GameState()
{
	ke::World::destroyInstance();
}

bool GameState::handleEvent(sf::Event const& event)
{
	mWorld.handleEvent(event);
	mGui.handleEvent(event);
	return false;
}

bool GameState::update(sf::Time dt)
{
	mWorld.update(dt);
	return false;
}

void GameState::render(sf::RenderTarget & target, sf::RenderStates states)
{
	mWorld.render(target);
	mGui.draw();
}

void GameState::onActivate()
{
}

void GameState::onDeactivate()
{
}

void GameState::createActor()
{
	mWorld.createActor<MyMap>();

	mBase1 = mWorld.createActor<Base>(1)->getId();
	mBase2 = mWorld.createActor<Base>(2)->getId();

	Robot::Ptr test = mWorld.createActor<Robot>();
	test->setPosition({ 50.f, 365.f });
}

void GameState::createGui()
{
}

void GameState::grantMoney(int team, int amount)
{
	if (team == 1)
	{
		mMoney1 += amount;
	}
	if (team == 2)
	{
		mMoney2 += amount;
	}
}
