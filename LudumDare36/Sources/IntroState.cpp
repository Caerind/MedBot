#include "IntroState.hpp"

IntroState::IntroState()
{
	ke::Application::setBackgroundColor(sf::Color::White);
	ke::Application::setBackgroundTexture("ld36", { 0, 0, 1600, 900 });
}

IntroState::~IntroState()
{
}

bool IntroState::handleEvent(sf::Event const & event)
{
	return false;
}

bool IntroState::update(sf::Time dt)
{
	mElapsed += dt;
	if (mElapsed >= sf::seconds(1.f))
	{
		clearStates();
		pushState("MenuState");
	}
	return false;
}

void IntroState::render(sf::RenderTarget & target, sf::RenderStates states)
{
}
