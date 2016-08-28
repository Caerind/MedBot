#include "TutoState.hpp"

TutoState::TutoState()
{
	ke::Application::setBackgroundTexture("tuto", { 0,0,1600,900 });

	ke::Theme& theme = getApplication().getResource<ke::Theme>("css");
	tgui::Button::Ptr buttonGame = theme.create("Button");
	buttonGame->setSize({ 400,100 });
	buttonGame->setPosition({ 1600 - 400 - 60, 100 });
	buttonGame->setText(" Skip tutorial ");
	buttonGame->connect("pressed", [&]()
	{
		clearStates();
		pushState("GameState");
	});
	mGui.add(buttonGame);
	tgui::Button::Ptr buttonQuit = theme.create("Button");
	buttonQuit->setSize({ 400,100 });
	buttonQuit->setPosition({ 60, 100 });
	buttonQuit->setText("Return to menu");
	buttonQuit->connect("pressed", [&]()
	{
		clearStates();
		pushState("MenuState");
	});
	mGui.add(buttonQuit);
}

TutoState::~TutoState()
{
	ke::Application::setBackgroundColor(sf::Color::White);
}

bool TutoState::handleEvent(sf::Event const & event)
{
	mGui.handleEvent(event);
	return false;
}

bool TutoState::update(sf::Time dt)
{
	return false;
}

void TutoState::render(sf::RenderTarget & target, sf::RenderStates states)
{
	mGui.draw();
}
